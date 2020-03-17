#pragma once
#include "DxLib.h"
#include "struct.h"
#include <string>
#include "Materials.h"
#include <vector>

#include "Character.h"
#include "Map.h"
#include "Enemy.h"
#include "Friend.h"
#include "Gimic.h"
#include "EnemyMgr.h"
#include "GimicMgr.h"
#include "FriendMgr.h"
#include "Tutorial.h"


class Drawer
{
	static const int MaxID = 15;
	int mapchips[Map::Chip::Size];		//マップチップ
	int backgroundH[5];
	int friendH[FriendMgr::eFriend::Size][4];				//フレンド用の画像配列
	int enemyH[EnemyMgr::eEnemy::Size][4];					//エネミー用の画像配列
	int gimicH[GimicMgr::eGimic::Size][4];//ギミック用の画像配列
	int ButtonH[3];
	int UIH[17];
	int NumberH[10][12];
	int UiHundle[3];
	int helpgimicH[GimicMgr::eGimic::Size];
	int soundFile[1];

	int FontHandle[3];
	int timelimit;
	int timeLimitMinute = 3; //制限時間
	int timeLimitSecond = 30;

	const Vector2* screen;	//スクリーンへのポインタ
	std::vector<std::string> aim[StageNum];
	std::vector<int> manualGimics[StageNum];
	std::vector<std::string> gManual[GimicMgr::eGimic::Size];

	std::vector<std::string> tutorialS[StageNum][Tutorial::MaxStep];

	void DrawMap(const std::vector<std::vector<int>>& map, int stage);	//マップを描画
	void DrawFriend(const std::vector<Friend*>& enemys);
	void DrawEnemy(const std::vector<Enemy*>& enemys);
	void DrawGimic(const std::vector<Gimic*>& gimics);
	void DrawMinimap(const std::vector<std::vector<int>>& map, const std::vector<Friend*>& friends, const std::vector<Enemy*>& enemys, const std::vector<Gimic*>& gimics); 
	void getNotAnimGraph(int idx, const std::string& path);
	int GetMiniColor(int id, int type); //ミニマップで描画する色の取得
										//type: 0=map 1=freinds 2=enemys 3=gimics
	void DrawUI(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int score, int cnt, int life, int stage);
	//void DrawMiniMap(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics);
	void DrawAim(int stage);
	void DrawHelp(const Vector2& point);
	void DrawBack(const Vector2& point);
	void DrawSkip(const Vector2& point);
	void DrawUIArrow();
	void DrawScore(int score);
	void DrawLife(int life);
	void DrawTime(int cnt);
	void DrawWatch(int cnt);
	void DrawGimicManual(int stage);
	void DrawFillBox_dbg(int x, int y, int h, int w, unsigned int color);
	bool isDrawableInMinimap(int id, int type);
	void DrawAddition(const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int stage, int cnt);
	Vector2 GimPosYajirushi(const Gimic* gim);
	Vector2 EnePosYajirushi(const Enemy* ene);
	Vector2 FrePosYajirushi(const Friend* fre);

	void DrawGetAnimal(const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics);
	bool isGetDog(const std::vector<Enemy*>& enemys);
	bool isGetBird(const std::vector<Gimic*>& gimics);
	bool isGetMonkey(const std::vector<Friend*>& friends);

	std::string convert(int i);

	static const double ExtendRate[MaxID];
	int stage;

	int watchH[3];

public:
	Drawer();
	~Drawer();

	static int getStage();
	void Initialize(const Vector2* _screen);
	void Draw(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int score, int cnt, int stage,int life);
	void Finalize();

	void DrawMenue(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int score, int cnt, int stage,int life);

	void DrawTutorial(int stage, int step) const;	
	void DrawStart(const ObjBox& start, int& cnt, int stage, bool isIntroScreen) const;
	void DrawGo(const ObjBox & start, int& cnt) const;
	void DrawClear(const ObjBox & start, int& cnt) const;
	void DrawDead(const ObjBox & start, int& cnt) const;
	void DrawTimeUp(const ObjBox & start, int& cnt) const;
	int GetHundle();

	enum ePict_cntType {
		StageStart = 0,
		GO,
		TimeUp,
		Clear,
		Dead,
		Size
	};
};

