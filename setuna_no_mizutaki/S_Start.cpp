#include "S_Start.h"

S_Start::S_Start(ISceneChanger* changer) : BaseScene(changer) {}

void S_Start::Initialize(int PlayerNum, int *score) {
	SelectNum = 0;

	titleH = LoadGraph("./resource/img/タイトル.png");
	startH[0] = LoadGraph("./resource/img/二人対戦.png");
	startH[1] = LoadGraph("./resource/img/三人対戦.png");
	startH[2] = LoadGraph("./resource/img/四人対戦.png");
	startH[3] = LoadGraph("./resource/img/二人対戦大.png");
	startH[4] = LoadGraph("./resource/img/三人対戦大.png");
	startH[5] = LoadGraph("./resource/img/四人対戦大.png");


	titlebgm = LoadSoundMem("./resource/bgm/title.ogg");
	SetLoopPosSoundMem(6750, titlebgm);
	PlaySoundMem(titlebgm, DX_PLAYTYPE_LOOP);
}

void S_Start::Finalize() {
	InitGraph();
	InitSoundMem();
}

void S_Start::Update(int *score, int *PlayerNum) {
	for (int i = 0; i < 4; i++) {
		if (CheckPadPressOnce(i, PAD_INPUT_1)) {
			*PlayerNum = SelectNum + 2;
			mSceneChanger->ChangeScene(eScene_S_Game);
			StopSoundMem(titlebgm);
		}
		else if (CheckPadPressOnce(i, PAD_INPUT_UP)) {
			SelectNum--;
			SelectNum = max(0, SelectNum);
		}
		else if (CheckPadPressOnce(i, PAD_INPUT_DOWN)) {
			SelectNum++;
			SelectNum = min(2, SelectNum);
		}
	}
}

void S_Start::Draw(int *score, int PlayerNum) {
	BaseScene::Draw(score, PlayerNum);
	DrawGraph(0, 0, titleH, TRUE);
	switch (SelectNum)
	{
	case 0:
		DrawGraph(WinWidth / 2 - STARTLWIDTH / 2, 380, startH[3], TRUE);
		DrawGraph(WinWidth / 2 - STARTWIDTH / 2, 490, startH[1], TRUE);
		DrawGraph(WinWidth / 2 - STARTWIDTH / 2, 600, startH[2], TRUE);
		break;
	case 1:
		DrawGraph(WinWidth / 2 - STARTWIDTH / 2, 380, startH[0], TRUE);
		DrawGraph(WinWidth / 2 - STARTLWIDTH / 2, 490, startH[4], TRUE);
		DrawGraph(WinWidth / 2 - STARTWIDTH / 2, 600, startH[2], TRUE);
		break;
	case 2:
		DrawGraph(WinWidth / 2 - STARTWIDTH / 2, 380, startH[0], TRUE);
		DrawGraph(WinWidth / 2 - STARTWIDTH / 2, 490, startH[1], TRUE);
		DrawGraph(WinWidth / 2 - STARTLWIDTH / 2, 600, startH[5], TRUE);
		break;
	default:
		break;
	}
}
