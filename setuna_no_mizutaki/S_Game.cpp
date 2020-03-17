#include "S_Game.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

S_Game::S_Game(ISceneChanger* changer) : BaseScene(changer) {}
void S_Game::Initialize(int PlayerNum, int *score) { //������

	time = 0;

	//�D��x
	PriCnt = 0;

	//��ނ̔��a
	dish_r = 75;

	//�J�[�\��
	InitCursor(0, 50, 50, 10, stuffNum, 0, false);
	InitCursor(1, WinWidth - 50, WinHeight - 50, 10, stuffNum, 0, false);
	InitCursor(2, 50, WinHeight - 50, 10, stuffNum, 0, false);
	InitCursor(3, WinWidth - 50, 50, 10, stuffNum, 0, false);

	InitScore(PlayerNum, score);
	InitGoal(PlayerNum);

	InitDraw();
	InitGameSound();

	PlaySoundMem(mainbgm, DX_PLAYTYPE_LOOP);
	PlaySoundMem(SE[0], DX_PLAYTYPE_BACK);
}

void S_Game::Finalize() {
	InitGraph();
	InitSoundMem();
}

void S_Game::Update(int *score, int *PlayerNum) {

	if ((CheckHitKey(KEY_INPUT_ESCAPE) > 0)) {	//ESC�L�[�Ń^�C�g����
		mSceneChanger->ChangeScene(eScene_S_Start);
		StopSoundMem(mainbgm);
	}

	time++;
	if (time == TIMELIMIT)PlaySoundMem(SE[1], DX_PLAYTYPE_BACK);
	if (time > TIMELIMIT) {	//�������Ԃ𒴂����Ƃ�
		for (int i = 0; i < 4; i++) {
			if (CheckPadPressOnce(i, PAD_INPUT_1) || getKeyPressOnce(KEY_INPUT_SPACE) || getKeyPressOnce(KEY_INPUT_RETURN)) {
				mSceneChanger->ChangeScene(eScene_S_Result);
				StopSoundMem(mainbgm);
			}
		}
	}
	else {	//�������ԓ�
		CreateFood();
		VoilFood();
		UpdateCursor(*PlayerNum);
		HitCirsor(*PlayerNum);
		GoalCursor(score, *PlayerNum);
		CatchFood(score, *PlayerNum);
		VoilFood();
	}
}

void S_Game::Draw(int *score, int PlayerNum) {
	BaseScene::Draw(score, PlayerNum);
	//�w�i�̕`��
	DrawGraph(0, 0, potH, TRUE);

	//�M�̕`��
	for (int i = 0; i < PlayerNum; i++) {
		DrawGraph((i % 2)*(WinWidth - DISHSIZE), (i % 3 != 0)*(WinHeight - DISHSIZE), dishH[i], TRUE);
	}

	//��ނ̕`��
	for (int j = 0; j < PriCnt; j++) {
		for (int i = 0; i < stuffNum; i++) {
			if (FoodStuff[i].isAlive == true) {
				if (FoodStuff[i].priority == j) {
					if (FoodStuff[i].isBoil) {
						DrawGraph(FoodStuff[i].x - (FOODWIDTH / 2), FoodStuff[i].y - (FOODHEIGHT / 2), foodH[FoodStuff[i].stuffType + 5], TRUE);
						DrawGraph(FoodStuff[i].x - (BOILWIDTH / 2), FoodStuff[i].y - (BOILHEIGHT / 2), boilH, true);
					}
					else DrawGraph(FoodStuff[i].x - (FOODWIDTH / 2), FoodStuff[i].y - (FOODHEIGHT / 2), foodH[FoodStuff[i].stuffType], TRUE);
				}
			}
		}
	}

	//�p�b�h(��)�̕`��
	for (int i = 0; i < PlayerNum; i++) {
		if (i % 2 == 0)DrawTurnGraph(Pad[i].x - STICKWIDTH + 30, Pad[i].y - (STICKHEIGHT / 2) - 15, stickH[i], true);
		else DrawGraph(Pad[i].x - 30, Pad[i].y - (STICKHEIGHT / 2) - 15, stickH[i], true);
		//DrawCircle(Pad[i].x, Pad[i].y, Pad[i].r, GetColor(255, 0, 0), TRUE);
	}

	//���ԁE�X�R�A�̕`��
	DrawTime();
	DrawScore(score, PlayerNum);
}

void S_Game::UpdateCursor(int PlayerNum) {	//�J�[�\���ړ�
	for (int i = 0; i < PlayerNum; i++) {
		if (!Pad[i].isDead) {
			if (CheckPadPress(i, PAD_INPUT_1));
			if (CheckPadPress(i, PAD_INPUT_RIGHT)) {
				if (Pad[i].x + Pad[i].r < WinWidth)Pad[i].x += CURSORSPEED[!(Pad[i].Catch == stuffNum)];
			}
			if (CheckPadPress(i, PAD_INPUT_LEFT)) {
				if (Pad[i].x - Pad[i].r > 0)Pad[i].x -= CURSORSPEED[!(Pad[i].Catch == stuffNum)];
			}
			if (CheckPadPress(i, PAD_INPUT_DOWN)) {
				if (Pad[i].y + Pad[i].r < WinHeight)Pad[i].y += CURSORSPEED[!(Pad[i].Catch == stuffNum)];
			}
			if (CheckPadPress(i, PAD_INPUT_UP)) {
				if (Pad[i].y - Pad[i].r > 0)Pad[i].y -= CURSORSPEED[!(Pad[i].Catch == stuffNum)];
			}
			Pad[i].StopCnt++;
		}
	}
}

void S_Game::HitCirsor(int PlayerNum) {	//�J�[�\���̏Փ�
	for (int i = 0; i < PlayerNum; i++) {
		for (int j = i + 1; j < PlayerNum; j++) {
			if (CheckHitCircle(Pad[i].x, Pad[i].y, Pad[i].r, Pad[j].x, Pad[j].y, Pad[j].r)) {
				FoodStuff[Pad[i].Catch].isCatch = false;
				FoodStuff[Pad[j].Catch].isCatch = false;
				Pad[i].Catch = stuffNum;
				Pad[j].Catch = stuffNum;
				Pad[i].StopCnt = 0;
				Pad[j].StopCnt = 0;

				PlaySoundMem(SE[2], DX_PLAYTYPE_BACK);
			}
		}
	}
}

void S_Game::GoalCursor(int *score, int PlayerNum) {//�J�[�\���������̃G���A�ɂ���Ƃ�
	for (int i = 0; i < PlayerNum; i++) {
		if (CheckHitCircle(Pad[i].x, Pad[i].y, Pad[i].r, Goal[i].x, Goal[i].y, GOALR)) {	//�����̃G���A�ɓ��������̏���
			if (((!CheckPadPress(i, PAD_INPUT_1))) && Pad[i].Catch != stuffNum) {
				FoodStuff[Pad[i].Catch].isAlive = false;
				if (FoodStuff[Pad[i].Catch].isBoil)score[i] += SCORE[FoodStuff[Pad[i].Catch].stuffType];
				else {
					score[i] -= 20;
					if (FoodStuff[Pad[i].Catch].stuffType == 0)Pad[i].isDead = true;
				}
			}
		}
	}
}

void S_Game::CreateFood() {	//�H�ރ����_������
	if (time % 60 == 0) {
		for (int i = 0; i < stuffNum; i++) {
			CreateF = false;
			if (FoodStuff[i].isAlive == false) {
				for (;;) {//���Ȃ��悤�ɐ���
					double r = sqrt(GetRand(11) / 10.0f) * 250.0f;
					double angle = (GetRand(101) / 100.0f) * 2.0f * PI;
					FoodStuff[i].x = (r * cos(angle)) + 480.0f;
					FoodStuff[i].y = (r * sin(angle)) + 360.0f;
					FoodStuff[i].stuffType = GetRand(4);
					FoodStuff[i].time = 0;
					FoodStuff[i].priority = PriCnt++;
					FoodStuff[i].isAlive = true;
					FoodStuff[i].isBoil = false;
					FoodStuff[i].isCatch = false;
					for (int j = 0; j < stuffNum; j++) {
						if ((j != i) && CheckHitCircle(FoodStuff[i].x, FoodStuff[i].y, dish_r, FoodStuff[j].x, FoodStuff[j].y, dish_r) == true) {
							FoodStuff[i].isAlive = false;
						}
					}
					if (FoodStuff[i].isAlive == true) {
						CreateF = true;
						break;
					}
				}
			}
			if (CreateF)break;
		}
	}
}

void S_Game::VoilFood() {	//�ς������̔���
	for (int i = 0; i < stuffNum; i++) {
		if (FoodStuff[i].isCatch == false)FoodStuff[i].time++;
		if (FoodStuff[i].time == BOILTIME[FoodStuff[i].stuffType]) {
			FoodStuff[i].isBoil = true;
			PlaySoundMem(SE[5], DX_PLAYTYPE_BACK);
		}
	}
}

void S_Game::CatchFood(int *score, int PlayerNum) {
	for (int j = 0; j < PlayerNum; j++) {
		//�H�ނ����񂾎��̏���
		if ((CheckPadPress(j, PAD_INPUT_1)) && (Pad[j].StopCnt > STOPCNT)) {//Pad�̏E��
			if (Pad[j].Catch == stuffNum) {
				int food = stuffNum;
				FoodStuff[food].priority = -1;
				for (int i = 0; i < stuffNum; i++) {
					if (CheckHitCircle(Pad[j].x, Pad[j].y, Pad[j].r, FoodStuff[i].x, FoodStuff[i].y, dish_r) > 0 && FoodStuff[i].isAlive == true) {//�����蔻��
						PlaySoundMem(SE[3], DX_PLAYTYPE_BACK);
						if (FoodStuff[food].priority < FoodStuff[i].priority)food = i;
					}
				}
				Pad[j].Catch = food;
			}
			//�͂܂ꂽ��ނ̈ړ�
			FoodStuff[Pad[j].Catch].priority = PriCnt++;
			FoodStuff[Pad[j].Catch].x = Pad[j].x;
			FoodStuff[Pad[j].Catch].y = Pad[j].y;
			FoodStuff[Pad[j].Catch].isCatch = true;
		}
		//�H�ނ�����łȂ����̏���
		else {
			FoodStuff[Pad[j].Catch].isCatch = false;
			Pad[j].Catch = stuffNum;
			for (int i = 0; i < stuffNum; i++) {
				if (!CheckInCircle(FoodStuff[i].x, FoodStuff[i].y, dish_r, WinWidth / 2, WinHeight / 2, WinHeight / 2) && !FoodStuff[i].isCatch) {
					if ((FoodStuff[i].x == Pad[j].x) && (FoodStuff[i].y == Pad[j].y) && FoodStuff[i].isAlive) {
						score[j] -= 20;
					}
					FoodStuff[i].isAlive = false;
				}
			}
		}
	}
}

bool S_Game::CheckHitCircle(int x1, int y1, int r1, int x2, int y2, int r2) {
	if ((sqrt((x1 - x2)*(x1 - x2) + ((y1 - y2)*(y1 - y2)))) <= r1 + r2) return true;
	else return false;
}

bool S_Game::CheckInCircle(int x1, int y1, int r1, int x2, int y2, int r2) {
	if (r1 > r2) {
		if ((sqrt((x1 - x2)*(x1 - x2) + ((y1 - y2)*(y1 - y2)))) <= r1) return true;
	}
	else {
		if ((sqrt((x1 - x2)*(x1 - x2) + ((y1 - y2)*(y1 - y2)))) <= r2) return true;
	}
	return false;
}

void S_Game::InitCursor(int PadNum, int x, int y, int r, int Catch, int StopCnt, bool isDead) {
	Pad[PadNum].x = x;
	Pad[PadNum].y = y;
	Pad[PadNum].r = r;
	Pad[PadNum].Catch = Catch;
	Pad[PadNum].StopCnt = StopCnt;
	Pad[PadNum].isDead = isDead;
}

void S_Game::InitGoal(int PlayerNum) {
	for (int i = 0; i < PlayerNum; i++) {
		Goal[i].x = GOALX[i];
		Goal[i].y = GOALY[i];
	}
}

void S_Game::InitDraw() {
	foodH[0] = LoadGraph("./resource/img/����.png");
	foodH[1] = LoadGraph("./resource/img/����������.png");
	foodH[2] = LoadGraph("./resource/img/������.png");
	foodH[3] = LoadGraph("./resource/img/�l�M��.png");
	foodH[4] = LoadGraph("./resource/img/���ؐ�.png");
	foodH[5] = LoadGraph("./resource/img/����.png");
	foodH[6] = LoadGraph("./resource/img/����������.png");
	foodH[7] = LoadGraph("./resource/img/������.png");
	foodH[8] = LoadGraph("./resource/img/�l�M��.png");
	foodH[9] = LoadGraph("./resource/img/���ؐ�.png");
	dishH[0] = LoadGraph("./resource/img/�M��.png");
	dishH[1] = LoadGraph("./resource/img/�M��.png");
	dishH[2] = LoadGraph("./resource/img/�M��.png");
	dishH[3] = LoadGraph("./resource/img/�M��.png");
	stickH[0] = LoadGraph("./resource/img/����.png");
	stickH[1] = LoadGraph("./resource/img/����.png");
	stickH[2] = LoadGraph("./resource/img/����.png");
	stickH[3] = LoadGraph("./resource/img/����.png");
	boilH = LoadGraph("./resource/img/�т�����}�[�N.png");
	potH = LoadGraph("./resource/img/��.png");
	//lockH = LoadGraph("./resource/img/���b�N�I����.png");
	numH[0] = LoadGraph("./resource/img/0.png");
	numH[1] = LoadGraph("./resource/img/1.png");
	numH[2] = LoadGraph("./resource/img/2.png");
	numH[3] = LoadGraph("./resource/img/3.png");
	numH[4] = LoadGraph("./resource/img/4.png");
	numH[5] = LoadGraph("./resource/img/5.png");
	numH[6] = LoadGraph("./resource/img/6.png");
	numH[7] = LoadGraph("./resource/img/7.png");
	numH[8] = LoadGraph("./resource/img/8.png");
	numH[9] = LoadGraph("./resource/img/9.png");

	scoreFont = CreateFontToHandle(NULL, 50, -1, DX_FONTTYPE_NORMAL);

}

void S_Game::InitGameSound() {
	mainbgm = LoadSoundMem("./resource/bgm/main.ogg");
	SE[0] = LoadSoundMem("./resource/SE/se-start.ogg");
	SE[1] = LoadSoundMem("./resource/SE/se-finish.ogg");
	SE[2] = LoadSoundMem("./resource/SE/se-stick_hit.ogg");
	SE[3] = LoadSoundMem("./resource/SE/se-stick_in.ogg");
	SE[4] = LoadSoundMem("./resource/SE/se-stick_out.ogg");
	SE[5] = LoadSoundMem("./resource/SE/se-tabegoro.ogg");
	SetLoopPosSoundMem(21000, mainbgm);
}

void S_Game::InitScore(int PlayerNum, int *score) {
	for (int i = 0; i < PlayerNum; i++) {
		score[i] = 0;
	}
}

void S_Game::DrawTime() {
	int cnt = max(0, (TIMELIMIT - time + 30) / 60);
	if (cnt < 10) {
		DrawGraph(WinWidth / 2 - NUMWIDTH / 2, 30, numH[cnt], TRUE);
	}
	else {
		DrawGraph(WinWidth / 2 - NUMWIDTH, 30, numH[cnt / 10], TRUE);
		DrawGraph(WinWidth / 2, 30, numH[cnt % 10], TRUE);
	}
}

void S_Game::DrawScore(int *score, int PlayerNum) {
	DrawFormatStringToHandle(30, 30, GetColor(0, 0, 0), scoreFont, "%d", score[0]);
	DrawFormatStringToHandle(WinWidth - 60, WinHeight - 60, GetColor(0, 0, 0), scoreFont, "%d", score[1]);
	if (PlayerNum > 2)DrawFormatStringToHandle(30, WinHeight - 60, GetColor(0, 0, 0), scoreFont, "%d", score[2]);
	if (PlayerNum > 3)DrawFormatStringToHandle(WinWidth - 60, 30, GetColor(0, 0, 0), scoreFont, "%d", score[3]);

}