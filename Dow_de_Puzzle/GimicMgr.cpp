#include "GimicMgr.h"

std::string GimicMgr::convert(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

GimicMgr::GimicMgr()
{
}


GimicMgr::~GimicMgr()
{
}

void GimicMgr::Initialize(int stage) {
	std::string path = "./resource/dat/gimic/";
	path += convert(stage);
	path += ".txt";
	std::ifstream input(path);
	int gimicNum;
	input >> gimicNum;
	std::vector<double> infos;
	int number;
	for (int i = 0; i < gimicNum; i++) {
		infos.clear();
		input >> number;
		if (number == 0) infos.resize(G_SpinFloor::initInfoSize);
		//else if (number == 1) infos.resize(G_WineMeat::initInfoSize);
		else if (number == 2) infos.resize(G_Flower::initInfoSize);
		else if (number == 3) infos.resize(G_Mushroom::initInfoSize);
		else if (number == 4) infos.resize(G_MoveFloor::initInfoSize);
		else if (number == 5) infos.resize(G_Stove::initInfoSize);
		else if (number == 6) infos.resize(G_Fan::initInfoSize);
		else if (number == 7) infos.resize(G_Bridge::initInfoSize);
		else if (number == 8) infos.resize(G_Ladder::initInfoSize);
		else if (number == 9) infos.resize(G_Apple::initInfoSize);
		else if (number == 10) infos.resize(G_Kabu::initInfoSize);
		else if (number == 11) infos.resize(G_Collection::initInfoSize);
		//else if (number == 12) infos.resize(G_Stone::initInfoSize);
		//else if (number == 13) infos.resize(G_Mirror::initInfoSize);
		else if (number == 14) infos.resize(G_Peach::initInfoSize);
		else if (number == 15) infos.resize(G_Sword::initInfoSize);
		else if (number == 16) infos.resize(G_Barrier::initInfoSize);
		//else if (number == 17) infos.resize(G_Shose::initInfoSize);
		//else if (number == 18) infos.resize(G_Guest::initInfoSize);
		else if (number == 19) infos.resize(G_Tree::initInfoSize);
		else if (number == 20) infos.resize(G_IgnitionFloor::initInfoSize);
		//else if (number == 21) infos.resize(G_EFcolider::initInfoSize);
		//else if (number == 22) infos.resize(G_Switch::initInfoSize);
		//else if (number == 23) infos.resize(G_Door::initInfoSize);
		else if (number == 24) infos.resize(G_Bird::initInfoSize);
		else if (number == 25) infos.resize(G_LadderFloor::initInfoSize);
		else if (number == 26) infos.resize(G_House::initInfoSize);
		else if (number == 27) infos.resize(G_Turn::initInfoSize);
		for (unsigned int j = 0; j < infos.size(); j++) input >> infos[j];

		if (number == 0) gimics.push_back(new G_SpinFloor(infos));
		//else if (number == 1) gimics.push_back(new G_WineMeat(infos));
		else if (number == 2) gimics.push_back(new G_Flower(infos));
		else if (number == 3) gimics.push_back(new G_Mushroom(infos));
		else if (number == 4) gimics.push_back(new G_MoveFloor(infos));
		else if (number == 5) gimics.push_back(new G_Stove(infos));
		else if (number == 6) gimics.push_back(new G_Fan(infos));
		else if (number == 7) gimics.push_back(new G_Bridge(infos));
		else if (number == 8) gimics.push_back(new G_Ladder(infos));
		else if (number == 9) gimics.push_back(new G_Apple(infos));
		else if (number == 10) gimics.push_back(new G_Kabu(infos));
		else if (number == 11) gimics.push_back(new G_Collection(infos));
		//else if (number == 12) gimics.push_back(new G_Stone(infos));
		//else if (number == 13) gimics.push_back(new G_Mirror(infos));
		else if (number == 14) gimics.push_back(new G_Peach(infos));
		else if (number == 15) gimics.push_back(new G_Sword(infos));
		else if (number == 16) gimics.push_back(new G_Barrier(infos));
		//else if (number == 17) gimics.push_back(new G_Shose(infos));
		//else if (number == 18) gimics.push_back(new G_Guest(infos));
		else if (number == 19) gimics.push_back(new G_Tree(infos));
		else if (number == 20) gimics.push_back(new G_IgnitionFloor(infos));
		//else if (number == 21) gimics.push_back(new G_EFcolider(infos));
		//else if (number == 22) gimics.push_back(new G_Switch(infos));
		//else if (number == 23) gimics.push_back(new G_Door(infos));
		else if (number == 24) gimics.push_back(new G_Bird(infos));
		else if (number == 25) gimics.push_back(new G_LadderFloor(infos));
		else if (number == 26) gimics.push_back(new G_House(infos));
		else if (number == 27) gimics.push_back(new G_Turn(infos));
	}
	//const Gimic* gimic = gimics.back();
}
void GimicMgr::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, const Vector2& screen, int& score) {
	for (unsigned i = 0; i < gimics.size(); i++) {
		if (gimics[i] == NULL || gimics[i]->getExist() == false) continue;
		gimics[i]->Update(enemys, friends, gimics, screen, score);
	}
}
void GimicMgr::Finalize() {
	for (unsigned i = 0; i < gimics.size(); i++) {
		gimics[i]->Finalize();
		delete gimics[i];
		gimics[i] = NULL;
	}
	gimics.clear();
}

std::vector<Gimic*>& GimicMgr::getGimics()
{
	return gimics;
}
