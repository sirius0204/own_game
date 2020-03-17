#pragma once
#include <vector>

#include "Gimic.h"
#include "Friend.h"
#include "Enemy.h"
#include "MyInput.h"


class Tutorial
{
	int step;
	int stage;

	bool fRunFriends;
	bool fRunEnemys;
	bool fRungimics;
	Vector2 MousePoint;

	bool checkStep(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);

public:
	Tutorial();
	~Tutorial();

	void Initialize(int _stage);
	bool Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	int getStep() const;
	bool isRunEnemy() const;
	bool isRunFriend() const;
	bool isRungimic() const;

	static const int MaxStep = 20;	//ìKãXèëÇ´ä∑Ç¶ÇÈ
};

