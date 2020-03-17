#pragma once
#include "Friend.h"

//------------------------------------------//
//	ƒTƒ‹							//
//		number = 4;							//
//------------------------------------------//

class F_Monkey :
	public Friend
{
public:
	F_Monkey(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Monkey();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	enum eAkaState {
		Size
	};
};

