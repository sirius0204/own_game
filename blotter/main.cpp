#include "DxLib.h"
#include"Material.h"
#include<assert.h>
#include"Input.h"

//�L�[�������ړ��̖h�~��
/*struct KEY {
	bool isPush = false;
};
KEY up;
KEY down;
KEY space;*/

//�v���C���[
//Player�ƃu���b�N�e���̃O���t�B�b�N�̒�`
struct Player {
	int y;
	int kind; //��� 0->JK 1->������P 2->���^�N
};

Player player;
void PlayerMove();//�v���C���[�̈ړ�
void PlayerShootBlock();//�u���b�N�e�𔭎�
//void PlayerBulletShoot();
void PlayerAction();//�v���C���[�s������

//�G�l�~�[
struct Enemy {
	int hp;
	int kind; //��� 0->JK 1->������P 2->���^�N 3->�]���r 4->�j�q�w�� 5->���A�[ 6->�g�����v 7->�����q 8->ROM
};

Enemy enemy[enemy_num];
bool isEnemyExist(int num); //�G�l�~�[�������邩�ǂ���
void DropEnemy(int dropnum); //�G�l�~�[������ܗ��Ƃ�
void CreatNextEnemy(int player_num, int create_num); //�l�N�X�g�G�l�~�[�����
int PlayerLikeEnemy(int enemy_kind);//fav���鑊�肩block���鑊�肩
void EnemyShoot(); //�G�l�~�[���e����
void EnemyAction(); //�G�l�~�[�̍s������

//�e
//Player���̒e���̏�����
struct PlayerBullet {
	int x;
	int y;
	int dx = 5;
	bool isAlive;
};

struct EnemyBullet
{
	int x, y;
	int dx = 5;
	int kind; // 0->fav������ 1->block������
	int tweetkind; //�ǂ̃c�C�[�g�����邩
	bool isAlive;
};

PlayerBullet playerbullet[PLAYERBULLET_MAX];
EnemyBullet enemybullet[ENEMYBULLET_MAX];
bool CheckHitField(int x1, int x2);
bool CheckHit2(int x1, int y1, int x2, int y2);
void ShotExist();//�e�̏Փ˔���
void BlockMove();//�u���b�N�e�̃��[�u
//void PlayerBullet_Move();
void EnemyBulletMove();//�G�l�~�[�e�̃��[�u
void ShotAction();//�e����

//���̑�
void Score(int _score);//�X�R�A�̏㉺
//void Offset();//�e���̑��E
void Floodgage(int _flood);//����Q�[�W
void modeselect();//���[�h�Z���N�g

struct Tweet {//DrawTweet�p�̍\����
	int cnt;//���ꂼ��̃��[���ɂ���G�l�~�[�e�̌�
	int enemy_kind;//�N�������Ă�����
	int tweet_kind;//�ǂ̎�ނ̃c�C�[�g�����Ă�����
};
Tweet tweet[enemy_num - 1];

//�`��֐�
void DrawBackground();//�w�i��`��
void DrawEnemy();//�G��`��
void DrawNextEnemy();//�l�N�X�g�G�l�~�[��`��
void DrawPlayer();//�v���C���[��`��
//void PlayerDraw();
//void PlayerBulletDraw();
void DrawPlayerBullet();//�v���C���[�e��`��
void DrawEnemyBullet();//�G�l�~�[�e��`��
void DrawFireGauge();//����Q�[�W��`��
void DrawTweet();//���[���̗���tweet��\��
void DrawTime();//�c�莞�ԕ`��
void DrawScore();//�X�R�A�`��

void DrawStartScreen();//�X�^�[�g��ʕ`��
void DrawGameScreen();//�Q�[����ʕ`��
void DrawResultScreen();//���U���g��ʕ`��
void Draw();//�S�̂̕`�搧��

//�T�E���h
void SoundMgr();//�T�E���h�}�l�[�W���[

//�������֐�
void DrawerInitialize();//�`��֘A�̏������A1��̎��s�ň�x�����Ăяo���Ȃ�
void SoundInitialize();//�T�E���h�֘A�̏������A���Q�[���Ăяo��
void Initialize();//�Q�[�����ϐ��������A���Q�[���Ăяo��

//���܂��Ȃ��AgoUpdateKey()��Input.cpp�̊֐����g�����߂ɕK�v
bool checkAll() {
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0;
}

//���C���֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("");
	SetGraphMode(WinWidth, WinHeight, 16), ChangeWindowMode(TRUE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	ChangeFont("HGP�s����"); SetFontSize(36);

	DrawerInitialize();
	SoundInitialize();
	Initialize();

	while (checkAll()) {
		Draw();
		SoundMgr();
		if (scene == 0) {//�^�C�g�����
			if (!isModeselect) {//���[�h�Z���N�g���łȂ��Ȃ�
				if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					isModeselect = true;
				}
			}
			else {//���[�h�Z���N�g���Ȃ�
				modeselect();
			}
		}
		else if (scene == 1) {//�Q�[�����
			if (getKeyPress(KEY_INPUT_ESCAPE, PRESS_ONCE)) {//esc�L�[�������ƃ^�C�g����ʂɖ߂�
				scene = 0;
				StopSoundMem(bgmH[1]);
				Initialize();
				SoundInitialize();
			}
			if (isRule) {//�������
				if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					isRule = false;
				}
			}
			else if (!isgamestart) {//�X�^�[�g���
				if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					isgamestart = true;
					SEflag[0] = true;
				}
			}
			else if (isgameend || isgameover) {//�Q�[�����I�������
				endcnt++;
				if (endcnt >= min_endcnt && getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					scene = 2;
					StopSoundMem(bgmH[1]);
				}
			}
			else {//�Q�[����
				cnt++;
				PlayerAction();
				EnemyAction();
				ShotAction();
				if (cnt == timelimit) {//�^�C���A�b�v�Ȃ�
					isgameend = true;
					SEflag[5] = true;
				}
				if (floodgage >= max_floodgage) {//����Q�[�W��max�ɂȂ�����
					isgameover = true;
					SEflag[8] = true;
				}
			}
		}
		else {//���U���g���
			resultcnt++;
			if (isgameover && !CheckSoundMem(SEH[1]) && !isresultbgmend) {//�Q�[���I�[�o�[�̏ꍇ
				SEflag[1] = true;
				isresultbgmend = true;
			}
			else if (isgameend && !CheckSoundMem(SEH[10]) && !isresultbgmend) {//�^�C���A�b�v�̏ꍇ
				SEflag[10] = true;
				isresultbgmend = true;
			}
			if (resultcnt >= min_result && getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {//space�A�łŃ^�C�g���ɖ߂�̂�h��
				for (int i = 0; i < SE_num; i++) {
					if (CheckSoundMem(SEH[i])) {
						StopSoundMem(SEH[i]);
					}
				}
				scene = 0;
				InitSoundMem();//���Q�[���̍Ō�ɃT�E���h�֘A�Ŏg�������������������
				SoundInitialize();
			}
		}
	}

	DxLib_End();
	return 0;
}

//�v���C���[
void PlayerMove() {//�v���C���[�ړ�

	if (getKeyPress(KEY_INPUT_UP, PRESS_ONCE)) {
		player.y--;
	}
	if (getKeyPress(KEY_INPUT_DOWN, PRESS_ONCE)) {
		player.y++;
	}
	//Player�͈̔͐ݒ�
	player.y = max(min(player.y, 4), 0);
}

void PlayerShootBlock() {//�v���C���[�e����


	if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
		if (cnt - player_shot_time >= player_shot_interval) {//�e�̔��˂ɃC���^�[�o����݂��Ă��
			for (int i = 0; i < PLAYERBULLET_MAX; i++) {
				if (playerbullet[i].isAlive == true)continue;
				playerbullet[i].x = 165;
				playerbullet[i].y = player.y;
				playerbullet[i].isAlive = true;
				player_shot_time = cnt;
				break;
			}
			SEflag[9] = true;
		}
	}
}

void PlayerAction() {//�v���C���[�̍s������
	PlayerMove();
	PlayerShootBlock();
}

//�G�l�~�[
bool isEnemyExist(int num) {//�G�l�~�[�������Ă邩�ǂ���
	if (enemy[num].hp == 0) {
		if (PlayerLikeEnemy(enemy[num].kind) != 2)Score(300);//ROM����Ȃ��Ȃ�
		SEflag[4] = true;
		return false;
	}
	return true;
}

void DropEnemy(int dropnum) {//����ܗ��Ƃ�
	for (int i = dropnum; i > 0; i--) {
		enemy[i] = enemy[i - 1];
	}
	enemy[0] = enemy[enemy_num - 1];
}

int PlayerLikeEnemy(int enemy_kind) {//0->block������ 1->fav������ 2->ROM
	if (player.kind == 0) {//�v���C���[��������P
		switch (enemy_kind) {
		case 1: return 1;
		case 2: return 0;
		case 3: return 0;
		case 4: return 1;
		case 5: return 1;
		case 6: return 1;
		case 7: return 1;
		case 8: return 2;
		}
	}
	else if (player.kind == 1) {//�v���C���[��JK
		switch (enemy_kind) {
		case 0: return 1;
		case 2: return 0;
		case 3: return 0;
		case 4: return 1;
		case 5: return 1;
		case 6: return 0;
		case 7: return 0;
		case 8: return 2;
		}
	}
	else {
		switch (enemy_kind) {//�v���C���[�����^�N
		case 0: return 0;
		case 1: return 0;
		case 3: return 1;
		case 4: return 0;
		case 5: return 0;
		case 6: return 0;
		case 7: return 1;
		case 8: return 2;
		}
	}
}

void CreatNextEnemy(int player_kind, int create_num) {//�l�N�X�g�G�l�~�[�����
	int define_kind;
	enemy[create_num].hp = 3;
	while (1) {
		define_kind = GetRand(enemy_kind_num - 1);
		if (define_kind != player_kind)break;//�v���C���[�Ɠ����L�����ɂȂ�Ȃ��悤��
	}
	enemy[create_num].kind = define_kind;
}

void EnemyShoot() {//�G�l�~�[�e����
	if (cnt % (20 * enemy_shot_interval[mode] + 40) == 0) {//�G�l�~�[�̒e���ˊԊu��ς���
		for (int i = 0; i < ENEMYBULLET_MAX; i++) {
			if (enemybullet[i].isAlive == true)continue;
			enemybullet[i].x = EnemyTeritory_x - shotsize;
			while (1) {
				int tmp = GetRand(enemy_num - 2);//�N�������Ă��邩����
				if (enemy[tmp].kind != 8) {//ROM����Ȃ�������
					enemybullet[i].y = tmp;
					enemybullet[i].kind = !(PlayerLikeEnemy(enemy[tmp].kind));
					int tweetkind = GetRand(2);//tweet�̓��e��3��ނ̂Ȃ����猈��
					enemybullet[i].tweetkind = tweetkind;
					enemybullet[i].isAlive = true;
					tweet[tmp].cnt++;
					tweet[tmp].enemy_kind = enemy[tmp].kind;
					tweet[tmp].tweet_kind = tweetkind;
					break;
				}
			}
			SEflag[6] = true;
			break;
		}
	}
}

void EnemyAction() {//�G�l�~�[�̍s������
	for (int i = 0; i < enemy_num; i++) {
		if (!(isEnemyExist(i))) {
			DropEnemy(i);
			CreatNextEnemy(player.kind, enemy_num - 1);
		}
	}
	EnemyShoot();
}

//�e
bool CheckHitField(int x1, int x2)//player����x
{
	if (x1 >= x2) {
		return true; //�d�Ȃ��Ă����true��Ԃ�
	}
	return false; //�����łȂ�������false��Ԃ�
}

bool CheckHit2(int x1, int y1, int x2, int y2)//player����x
{
	if (x1 >= x2 && y1 == y2)
	{
		return true; //�d�Ȃ��Ă����true��Ԃ�
	}
	else
	{
		return false; //�����łȂ�������false��Ԃ�
	}
}

void ShotExist() {//�e�̏Փ˔���
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		if (!(playerbullet[i].isAlive))continue;
		if (CheckHitField(playerbullet[i].x, EnemyTeritory_x)) {//����ɓ���������
			playerbullet[i].isAlive = false;
			if (PlayerLikeEnemy(enemy[playerbullet[i].y].kind) == 1) {//�����������肪�D���Ȃ�
				Score(-100);
				Floodgage(200);
			}
			else {//�����������肪����orROM�Ȃ�
				enemy[playerbullet[i].y].hp--;
			}
			SEflag[2] = true;
		}
	}
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		if (!(enemybullet[i].isAlive))continue;
		if (CheckHitField(MyTeritory_x - shotsize, enemybullet[i].x)) {
			enemybullet[i].isAlive = false;
			if (enemybullet[i].kind == 0) {//fav���󂯎������
				if (enemybullet[i].y == player.y) {
					enemy[enemybullet[i].y].hp--;
					Score((3 - enemy[enemybullet[i].y].hp) * 100);
					SEflag[7] = true;
				}
			}
			else {//�N�\���v�����w�ɂ͂�������
				Floodgage(100);
				SEflag[3] = true;
			}
			tweet[enemybullet[i].y].cnt--;
		}
	}
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		for (int j = 0; j < ENEMYBULLET_MAX; j++) {
			if (!(playerbullet[i].isAlive) || !(enemybullet[j].isAlive))continue;
			if (CheckHit2(playerbullet[i].x, playerbullet[i].y, enemybullet[j].x, enemybullet[j].y)) {//�e�ǂ����̏Փ�
				playerbullet[i].isAlive = false;
				enemybullet[j].isAlive = false;
				tweet[enemybullet[j].y].cnt--;
				Score(10);
				SEflag[2] = true;
			}
		}
	}
}

void BlockMove() {//�u���b�N�e���̈ړ�
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		if (playerbullet[i].isAlive == false)continue;
		playerbullet[i].x += playerbullet[i].dx;
	}
}

void EnemyBulletMove() {//�G�l�~�[�e�̃��[�u
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		if (enemybullet[i].isAlive == false)continue;
		enemybullet[i].x -= enemybullet[i].dx;
	}
}

void ShotAction() {//�e�̐���
	ShotExist();
	BlockMove();
	EnemyBulletMove();
}

//���̑�
void Score(int _score)//�X�R�A�ǉ�
{
	score += _score * scorebonus[mode];//* (mode + 1) ;
}

void Floodgage(int _flood)//����Q�[�W
{
	floodgage += _flood;
}

void modeselect() {//���[�h�Z���N�g
	if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
		scene = 1;
		mode = selectmode;
		Initialize();
		StopSoundMem(bgmH[0]);
		WaitTimer(1);
	}
	if (getKeyPress(KEY_INPUT_UP, PRESS_ONCE)) {
		selectmode = max(0, selectmode - 1);
		SEflag[11] = true;
	}
	if (getKeyPress(KEY_INPUT_DOWN, PRESS_ONCE)) {
		selectmode = min(2, selectmode + 1);
		SEflag[11] = true;
	}
}

//�`��
void DrawBackground() {//�w�i�`��
	DrawGraph(0, 0, map_gh, true);
}

void DrawEnemy() {//�G�Agood,dangeous�A�C�R���Afavblock�J�E���g�`��
	for (int i = 0; i < enemy_num - 1; i++) {
		DrawGraph(850, 100 + i * 95, CharactorH[enemy[i].kind], true);
		if (PlayerLikeEnemy(enemy[i].kind) != 2) {//ROM����Ȃ�������
			DrawGraph(850, 100 + i * 95, favblockH[!PlayerLikeEnemy(enemy[i].kind)], true);
		}
		DrawGraph(965, 110 + i * 95, fbcntH[!(PlayerLikeEnemy(enemy[i].kind) == 1)], true);
		DrawFormatStringToHandle(975, 160 + i * 95, GetColor(0, 0, 0), FontH[0], "%d", 3 - enemy[i].hp);
	}
}


void DrawNextEnemy() {//�l�N�X�g�G�l�~�[�Agood,dangerous�A�C�R���`��
	DrawGraph(800, 15, CharactorH[enemy[enemy_num - 1].kind], true);
	if (PlayerLikeEnemy(enemy[enemy_num - 1].kind) != 2) {//ROM����Ȃ�������
		DrawGraph(800, 15, favblockH[!(PlayerLikeEnemy(enemy[enemy_num - 1].kind))], true);
	}
}

void DrawPlayer() {//Player�A���A�C�R���̕`��
	DrawGraph(175, 137 + player.y * 95, arrow_gh, true);
	DrawGraph(90, 100 + player.y * 95, CharactorH[player.kind], true);
}


void DrawPlayerBullet() {//PlayerBullet�̕`��
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		if (playerbullet[i].isAlive == false)continue;
		DrawGraph(playerbullet[i].x, 106 + 95 * playerbullet[i].y, playerbullet_gh, true);
	}
}

void DrawEnemyBullet() {//�G�l�~�[�e�̕`��
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		if (enemybullet[i].isAlive == false)continue;
		DrawGraph(enemybullet[i].x, 106 + 95 * enemybullet[i].y, enemybulletH[enemybullet[i].kind], true);
	}
}

void DrawFireGauge() {//����Q�[�W�`��
	DrawGraph(250, 48 - firegauge_y / 2, FireH[0], true);
	DrawRectGraph(251 + (firegauge_x / 10)*(floodgage / 100), 49 - firegauge_y / 2, (firegauge_x / 10)*(floodgage / 100), 0,
		firegauge_x - (firegauge_x / 10)*(floodgage / 100), firegauge_y, FireH[1], true, false);
}

void DrawTweet() {//���[���̗��Ƀc�C�[�g�`��
	for (int i = 0; i < enemy_num - 1; i++) {
		if (tweet[i].cnt == 0)continue;
		DrawGraph(MyTeritory_x, 97 + i * 95, tweetH[tweet[i].enemy_kind][tweet[i].tweet_kind], true);
	}
}

void DrawTime() {//�c�莞�Ԃ̕`��
	int time = timelimit - cnt;
	time = (time + 59) / 60;
	DrawFormatStringToHandle(737, 45, GetColor(255, 255, 255), FontH[0], "%d", time);
}

void DrawScore() {//�X�R�A�̕`��
	DrawFormatStringToHandle(617, 45, GetColor(255, 255, 255), FontH[0], "%d", score);
}

void DrawStartScreen() {//�X�^�[�g��ʕ`��
	if (!isOPend) {//OP���I����ĂȂ��Ȃ�
		PlayMovie("./img/�n�o.avi", 1, DX_MOVIEPLAYTYPE_NORMAL);
		if (GetMovieStateToGraph(openingH) == 0) {
			isOPend = true;
		}
	}
	else {//OP���I�������
		DrawGraph(0, 0, titleH, true);
		if (isModeselect) {//���[�h�Z���N�g���Ȃ�
			for (int i = 0; i < 3; i++) {
				DrawGraph(368, 56 + 170 * i, bottonH[i], true);
				DrawGraph(368 - 2, 56 + 170 * selectmode, modeflameH, true);
			}
		}
	}
}

void DrawGameScreen() {//�Q�[����ʕ`��
	DrawBackground();
	DrawPlayer();
	DrawEnemy();
	DrawNextEnemy();
	DrawTweet();
	DrawPlayerBullet();
	DrawEnemyBullet();
	DrawFireGauge();
	DrawTime();
	DrawScore();
	if (!isgamestart)DrawGraph(0, 250, startH, true);//�X�^�[�g�O�Ȃ�
	if (isgameend || isgameover)DrawGraph(0, 250, finishH, true);//�Q�[�������������
	if (isRule)DrawGraph(0, 0, ruleH, true);//���[���������Ȃ�
}

void DrawResultScreen() {//���U���g��ʕ`��
	DrawGraph(0, 0, resultH[isgameover], true);
	if (!isgameover) {//�^�C���A�b�v�Ȃ�ŏI�X�R�A�\��
		DrawGraph(WinWidth / 2 - 162, 25, resultscoreH, true);
		DrawFormatStringToHandle(WinWidth / 2 - GetDrawFormatStringWidthToHandle(FontH[1], "%d", score) / 2 - 5, 95, GetColor(0, 0, 0), FontH[1], "%d", score);
	}
}

void Draw() {
	if (scene == 0) {
		DrawStartScreen();
	}
	else if (scene == 1) {
		DrawGameScreen();
	}
	else {
		DrawResultScreen();
	}
}

//�T�E���h
void SoundMgr() {
	if (scene == 0) {
		ChangeVolumeSoundMem(122, bgmH[0]);
		if (istitlebgm == false) {
			PlaySoundMem(bgmH[0], DX_PLAYTYPE_LOOP, false);//���[�v�Đ�
			istitlebgm = true;
		}
	}
	else if (scene == 1) {
		ChangeVolumeSoundMem(122, bgmH[1]);
		if (isgamebgm == false) {
			PlaySoundMem(bgmH[1], DX_PLAYTYPE_LOOP, false);
			isgamebgm = true;
		}
	}

	for (int i = 0; i < SE_num; i++) {//SEflag�������Ă��炻��SE�𗬂�
		if (SEflag[i]) {
			PlaySoundMem(SEH[i], DX_PLAYTYPE_BACK, true);//�o�b�N�O���E���h�Đ�
			SEflag[i] = false;//flag��؂�
		}
	}
}

//�������֐�
void DrawerInitialize() {//�`��֘A�̏�����
	//�O���t�B�b�N�̓ǂݍ���
	openingH = LoadGraph("./img/�n�o.avi");
	titleH = LoadGraph("./img/OP.png");
	bottonH[0] = LoadGraph("./img/easy.png");
	bottonH[1] = LoadGraph("./img/normal.png");
	bottonH[2] = LoadGraph("./img/hard.png");
	modeflameH = LoadGraph("./img/mode_frame.png");
	map_gh = LoadGraph("./img/map 2.png");
	ruleH = LoadGraph("./img/rulerule.png");
	startH = LoadGraph("./img/start.png");
	finishH = LoadGraph("./img/finish.png");
	CharactorH[0] = LoadGraph("./img/kaguya.png");
	CharactorH[1] = LoadGraph("./img/jk.png");
	CharactorH[2] = LoadGraph("./img/wotaku.png");
	CharactorH[3] = LoadGraph("./img/zombie.png");
	CharactorH[4] = LoadGraph("./img/dk.png");
	CharactorH[5] = LoadGraph("./img/riaju.png");
	CharactorH[6] = LoadGraph("./img/trump.png");
	CharactorH[7] = LoadGraph("./img/fujoshi.png");
	CharactorH[8] = LoadGraph("./img/ROM.png");
	playerbullet_gh = LoadGraph("./img/block.png");
	enemybulletH[0] = LoadGraph("./img/fav.png");
	enemybulletH[1] = LoadGraph("./img/kusorep.png");
	arrow_gh = LoadGraph("./img/arrow.png");
	favblockH[0] = LoadGraph("./img/icon_good.png");
	favblockH[1] = LoadGraph("./img/icon_dangerous.png");
	fbcntH[0] = LoadGraph("./img/fav_mark.png");
	fbcntH[1] = LoadGraph("./img/block_mark.png");
	tweetH[0][0] = LoadGraph("./img/tweet/kaguya_t1.png");
	tweetH[0][1] = LoadGraph("./img/tweet/kaguya_t2.png");
	tweetH[0][2] = LoadGraph("./img/tweet/kaguya_t3.png");
	tweetH[1][0] = LoadGraph("./img/tweet/jk_t1.png");
	tweetH[1][1] = LoadGraph("./img/tweet/jk_t2.png");
	tweetH[1][2] = LoadGraph("./img/tweet/jk_t3.png");
	tweetH[2][0] = LoadGraph("./img/tweet/wotaku_t1.png");
	tweetH[2][1] = LoadGraph("./img/tweet/wotaku_t2.png");
	tweetH[2][2] = LoadGraph("./img/tweet/wotaku_t3.png");
	tweetH[3][0] = LoadGraph("./img/tweet/zombie_t1.png");
	tweetH[3][1] = LoadGraph("./img/tweet/zombie_t2.png");
	tweetH[3][2] = LoadGraph("./img/tweet/zombie_t3.png");
	tweetH[4][0] = LoadGraph("./img/tweet/dk_t1.png");
	tweetH[4][1] = LoadGraph("./img/tweet/dk_t2.png");
	tweetH[4][2] = LoadGraph("./img/tweet/dk_t3.png");
	tweetH[5][0] = LoadGraph("./img/tweet/riaju_t1.png");
	tweetH[5][1] = LoadGraph("./img/tweet/riaju_t2.png");
	tweetH[5][2] = LoadGraph("./img/tweet/riaju_t3.png");
	tweetH[6][0] = LoadGraph("./img/tweet/trump_t1.png");
	tweetH[6][1] = LoadGraph("./img/tweet/trump_t2.png");
	tweetH[6][2] = LoadGraph("./img/tweet/trump_t3.png");
	tweetH[7][0] = LoadGraph("./img/tweet/fujoshi_t1.png");
	tweetH[7][1] = LoadGraph("./img/tweet/fujoshi_t2.png");
	tweetH[7][2] = LoadGraph("./img/tweet/fujoshi_t3.png");
	FireH[0] = LoadGraph("./img/gauge_max.png");
	FireH[1] = LoadGraph("./img/gauge_frame 2.png");
	resultH[0] = LoadGraph("./img/result.png");
	resultH[1] = LoadGraph("./img/gameover.png");
	resultscoreH = LoadGraph("./img/result_score.png");
	//riaju_gh = LoadGraph("./img/riaju.png");
	//kusorip_gh = LoadGraph("./img/kusorep.png");

	LPCSTR font_path = "./Font/���̑��̃t�@�C��/TrueType�t�H���g/03SmartFontUI.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {//�t�H���g�ǂݍ��ݐ���
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}

	FontH[0] = CreateFontToHandle(font_path, 30, 9);
	FontH[1] = CreateFontToHandle(font_path, 60, 9);
}

void SoundInitialize() {//�T�E���h�֘A�̏�����
	bgmH[0] = LoadSoundMem("./sound/title.ogg");
	bgmH[1] = LoadSoundMem("./sound/main.ogg");
	SEH[0] = LoadSoundMem("./sound/SE/start.wav");
	SEH[1] = LoadSoundMem("./sound/SE/badresult.wav");
	SEH[2] = LoadSoundMem("./sound/SE/block.wav");
	SEH[3] = LoadSoundMem("./sound/SE/damage.wav");
	SEH[4] = LoadSoundMem("./sound/SE/delete.wav");
	SEH[5] = LoadSoundMem("./sound/SE/end.wav");
	SEH[6] = LoadSoundMem("./sound/SE/enemytweet.wav");
	SEH[7] = LoadSoundMem("./sound/SE/fav.wav");
	SEH[8] = LoadSoundMem("./sound/SE/gameover.wav");
	SEH[9] = LoadSoundMem("./sound/SE/playershot.wav");
	SEH[10] = LoadSoundMem("./sound/SE/result.wav");
	SEH[11] = LoadSoundMem("./sound/SE/select.wav");
}

void Initialize() {//�Q�[���ϐ�������
	player.y = 0;
	player.kind = mode;
	for (int i = 0; i < enemy_num; i++) {
		CreatNextEnemy(player.kind, i);
	}
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		playerbullet[i].isAlive = false;
	}
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		enemybullet[i].isAlive = false;
	}
	for (int i = 0; i < enemy_num - 1; i++) {
		tweet[i].cnt = 0;
	}
	for (int i = 0; i < SE_num; i++) {
		SEflag[i] = false;
	}

	cnt = 0;
	score = 0;
	floodgage = 0;
	selectmode = 0;
	endcnt = 0;
	resultcnt = 0;
	player_shot_time = -player_shot_interval;
	//-------------------
	//���̕ӂ�������ƃf�o�b�O���y�ɂȂ�
	isModeselect = false;
	isgamestart = false;
	isgameend = false;
	isOPend = false;
	isRule = true;
	isgameover = false;
	istitlebgm = false;
	isgamebgm = false;
	isresultbgmend = false;
	//-------------------
}
