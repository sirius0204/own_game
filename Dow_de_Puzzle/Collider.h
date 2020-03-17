#pragma once
#include "Friend.h"
#include "Enemy.h"
#include "Gimic.h"
#include <bitset>

//stage‚âscore‚Ìî•ñ‚ğ•K—v‚Æ‚·‚éFriend-Enemy-GimicŠÔ‚ÌÕ“Ë

class Collider
{
	//int cnt;
	bool Flags[100];
	int soundFile[3];
public:
	Collider();
	~Collider();

	void Initialize();
	void Finalize();
	void Update(std::vector<Friend*> friends, std::vector<Enemy*> enemys, std::vector<Gimic*> gimics, int stage, int& score, int& life);

	int getStageType(int stage);
	void addAnimal(std::bitset<Friend::eFriendState_St2::Size> &bs);

	enum eStagetype {
		Aka = 0,
		Momotaro,
		Buta,
		Size
	};

};

