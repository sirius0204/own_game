#pragma once
#include "Friend.h"

//------------------------------------------//
//	豚							//
//		number = 1;							//
//------------------------------------------//


//stateは材料の所持数を10bitずつに区切って表す。
//countが負の時はカブモードを表す。

class F_Pig :
	public Friend
{
public:
	F_Pig(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Pig();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

};
