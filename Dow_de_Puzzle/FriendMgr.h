#pragma once
#include "Friend.h"
#include <vector>
#include "F_Aka.h"
#include "F_Pig.h"
#include "F_Momotaro.h"
#include "F_Monkey.h"

class FriendMgr
{
	std::vector<Friend*> friends;
	std::string convert(int num);
public:
	FriendMgr();
	~FriendMgr();

	void Initialize(int stage);
	void Update(const Map& map);
	void Finalize();


	std::vector<Friend*>& getFriends();

	enum eFriend {
		Aka_0 = 0,
		Aka_1,
		Aka_2,
		momotarou,
		saru,
		pig,
		cinderella,
		shirayuki,
		momotarou_ladder,
		saru_ladder,
		pig_ladder,
		cinderella_ladder,
		shirayuki_ladder,
		momotaro_havingKatana,
		momotaro_havingKatana2,
		pig_aura,
		pig_aura2,
		Size
	};
};

