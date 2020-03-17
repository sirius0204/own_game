#include "EnemyMgr.h"

std::string EnemyMgr::convert(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

EnemyMgr::EnemyMgr()
{
}


EnemyMgr::~EnemyMgr()
{
}


void EnemyMgr::Initialize(int stage) {
	std::string path = "./resource/dat/enemy/";
	path += convert(stage);
	path += ".txt";
	std::ifstream input(path);
	int inputSize;
	input >> inputSize;
	int number, id, hp, dir, state;
	double x, y, h, w;
	for (int i = 0; i < inputSize; i++) {
		input >> number;
		input >> id >> hp >> dir >> state >> x >> y >> h >> w;
		if (number == 0) {
			enemys.push_back(new E_Wolf(id, hp, dir, state, { x,y }, h, w));
		}
		/*else if (number == 1) {
			double tree1x, tree1y, tree2x, tree2y, treew, treeh;
			input >> tree1x >> tree1y >> tree2x >> tree2y >> treew >> treeh;
			enemys.push_back(new E_Bird(id, hp, dir, state, { x,y }, h, w, { tree1x + 0.5*w, tree1y + 0.5*h }, { tree2x + w*0.5, tree2y + h*0.5 }));
		}*/
		else if (number == 2)enemys.push_back(new E_Dog(id, hp, dir, state, { x,y }, h, w));
		else if (number == 3)enemys.push_back(new E_Oni(id, hp, dir, state, { x,y }, h, w));
		else if (number == 4)enemys.push_back(new E_Brownwolf(id, hp, dir, state, { x,y }, h, w));
	}
}

void EnemyMgr::Update(const Map& map) {
	for (unsigned i = 0; i < enemys.size(); i++) {
		if (enemys[i] == NULL || enemys[i]->getExist() == false) continue;
		enemys[i]->Update(map);
	}
}

void EnemyMgr::Finalize() {
	for (unsigned i = 0; i < enemys.size(); i++) {
		delete enemys[i];
		enemys[i] = NULL;
	}
	enemys.clear();
}


std::vector<Enemy*>& EnemyMgr::getEnemys()
{
	return enemys;
}
