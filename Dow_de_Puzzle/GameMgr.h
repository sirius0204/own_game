#pragma once
#include "Character.h"
#include "Map.h"
#include "Drawer.h"
#include "MyInput.h"

#include <string>
#include <fstream>
#include "GimicMgr.h"
#include "EnemyMgr.h"
#include "FriendMgr.h"
#include "Collider.h"
#include "Tutorial.h"
#include "SoundMgr.h"

#include "AimDrawer.h"

struct PlayDate {
	int stage, time[StageNum], life, score;
	PlayDate() {
		for (int i = 0; i < StageNum; i++) {
			time[i] = -1;
		}
	}
	void outPut() {
		std::ofstream playdate("resource/dat/playdate.txt", std::ios::app);
		playdate << stage << " " << life << " " << score;
		for (int i = 0; i < StageNum; i++) {
			playdate << " " << time[i];
		}
		playdate << std::endl;
	}
};


class GameMgr
{
	static int stage;
	Drawer drawer;		//�`��p
	Map map;			//�}�b�v
	int score;			//�X�R�A
	int cnt = 0;			//�J�E���^�[
	int life;			//�c�@
	Vector2 screen;		//�`�悷��X�N���[���̍���̍��W
	Vector2 mousePoint;	//�}�E�X�̍��W
	
	ObjBox help;
	ObjBox start;
	ObjBox skip;
	bool isMenuScreen;
	bool isTutorial;	
	bool isGamestart;
	bool ClearFlag;
	int Pict_cnt[100];
	bool isDead;
	bool isTimeUp;

	bool isIntroScreen; //�����X�N���[�������ǂ���
	int ScreenDir;//�X�N���[���̈ړ�����
	int ScreenCnt;
	const int ScrollSpeed = 5;//�X�N���[�����x
	Vector2 screenStart;//�X�N���[���̏����ʒu

	GimicMgr gimicMgr;
	EnemyMgr enemyMgr;
	FriendMgr friendMgr;
	Collider collider;
	SoundMgr soundMgr;


	AimDrawer ad;

	Tutorial tutorial;

	Vector2 screenMin, screenMax;
	
	void outputScore();
	bool isClear();
	bool isClearStage();
	bool isKOallWolf();
	bool isAbleToBuild(int min, int x, int y); //(�O�C�̎q�؂̐�������) : �Ƃ����Ă�ꏊ�ɂ�����ȏ�̍ޗ��������Ă�����
	bool isFinishedWork(int x, int y); //(����P�̐�������) : �S�Ă̏��l���z�΂���ɓ���Ė߂��Ă�����
	bool isReadyToFight(int x, int y); //(�����Y�̐�������) : ���������ׂĘA��Ďw�肵���ꏊ�ɗ�����
	bool isExit(int x, int y); //(�V���f�����̐�������) : �V���f�������o���܂ł��ǂ蒅������
	bool isHitArea(int x, int y, Friend* fre);

	void IntroScreen();
	
	PlayDate pd;

	int soundFile[4];
public:
	GameMgr();
	~GameMgr();

	static void ChangeStage(int _stage);
	static int getStage();
	void Initialize();
	bool Update();
	void Finalize();

	void moveScreen();

	void TimeBonus();
	void LifeBonus();
	
	const int TimeLimit = 3 * 60 * 60 + 30 * 60;

private:
	void getFinalScore(int _stage);
};


