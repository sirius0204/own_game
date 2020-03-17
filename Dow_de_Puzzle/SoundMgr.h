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

class SoundMgr
{
	enum eSound{
		//Aka,
		//Momo,
		//Buta,
		apple,
		barrior,
		bird_habataki,
		bird_get,
		bridge,
		collection,
		fan,
		flower,
		kabu,
		ladder,
		movefloor,
		mushroom_nobiru,
		mushroom_tijimu,
		peach,
		spinfloor_open,
		spinfloor_close,
		stove_ignition,
		stove_burn,
		sword,
		turn,
		Size
	};

	int SoundHundle[eSound::Size];
	bool isMove[eSound::Size];//ˆê‚Â‚Å‚à‹N“®’†‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
public:
	SoundMgr();
	~SoundMgr();

	void Initialize();
	void Finalize();
	void Update(std::vector<Gimic*> gimics, std::vector<Friend*> friends, std::vector<Enemy*> enemys, Vector2 screen);
	//void Play(int eSound_Num,int PlayType);
	//void Stop(int eSound_Num);
	bool isProcess(std::vector<Friend*> friends, Gimic* gim);

};

//extern SoundMgr soundmgr;
