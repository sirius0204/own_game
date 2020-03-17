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
	Drawer drawer;		//描画用
	Map map;			//マップ
	int score;			//スコア
	int cnt = 0;			//カウンター
	int life;			//残機
	Vector2 screen;		//描画するスクリーンの左上の座標
	Vector2 mousePoint;	//マウスの座標
	
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

	bool isIntroScreen; //強制スクロール中かどうか
	int ScreenDir;//スクリーンの移動方向
	int ScreenCnt;
	const int ScrollSpeed = 5;//スクロール速度
	Vector2 screenStart;//スクリーンの初期位置

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
	bool isAbleToBuild(int min, int x, int y); //(三匹の子豚の成功条件) : 家を建てる場所にある個数以上の材料を持ってきたか
	bool isFinishedWork(int x, int y); //(白雪姫の成功条件) : 全ての小人が鉱石を手に入れて戻ってきたか
	bool isReadyToFight(int x, int y); //(桃太郎の成功条件) : お供をすべて連れて指定した場所に来たか
	bool isExit(int x, int y); //(シンデレラの成功条件) : シンデレラが出口までたどり着いたか
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


