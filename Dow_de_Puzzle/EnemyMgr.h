#pragma once
#include "Enemy.h"
#include <vector>
#include <string>
#include <fstream>

#include "E_Wolf.h"
#include "E_Dog.h"
#include "E_Oni.h"
#include "E_Brownwolf.h"



class EnemyMgr
{
	std::vector<Enemy*> enemys;
	std::string convert(int num);
public:
	EnemyMgr();
	~EnemyMgr();

	void Initialize(int stage);
	void Update(const Map& map);
	void Finalize();

	std::vector<Enemy*>& getEnemys();

	enum eEnemy {
		Wolf = 0,
		Wolf_burnig,
		dog,
		prince,
		majo,
		brownwolf,
		brownwolf2,
		Size
	};
};

