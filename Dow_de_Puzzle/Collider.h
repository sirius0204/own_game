#pragma once
#include "Friend.h"
#include "Enemy.h"
#include "Gimic.h"
#include <bitset>

//stageやscoreの情報を必要とするFriend-Enemy-Gimic間の衝突

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

