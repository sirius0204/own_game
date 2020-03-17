#include "FriendMgr.h"

std::string FriendMgr::convert(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

FriendMgr::FriendMgr()
{
}


FriendMgr::~FriendMgr()
{
}

void FriendMgr::Initialize(int stage)
{
	std::string path = "./resource/dat/friend/";
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
			friends.push_back(new F_Monkey(id, hp, dir, state, { x,y }, h, w));
		}
		else if (number == 1) friends.push_back(new F_Pig(id, hp, dir, state, { x,y }, h, w));
		//else if (number == 2) friends.push_back(new F_Dwarf(id, hp, dir, state, { x,y }, h, w));
		else if (number == 3) friends.push_back(new F_Momotaro(id, hp, dir, state, { x,y }, h, w));
		else if (number == 4) friends.push_back(new F_Monkey(id, hp, dir, state, { x,y }, h, w));
		//else if (number == 5) friends.push_back(new F_Cinderella(id, hp, dir, state, { x,y }, h, w));
	}
}

void FriendMgr::Update(const Map & map)
{
	for (unsigned i = 0; i < friends.size(); i++) {
		if (friends[i] == NULL || friends[i]->getExist() == false) continue;
		friends[i]->Update(map);
	}
}

void FriendMgr::Finalize()
{
	for (unsigned i = 0; i < friends.size(); i++) {
		delete friends[i];
		friends[i] = NULL;
	}
	friends.clear();
}

std::vector<Friend*>& FriendMgr::getFriends()
{
	return friends;
}
