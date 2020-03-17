#pragma once
#include "Friend.h"

//------------------------------------------//
//	ƒVƒ“ƒfƒŒƒ‰							//
//		number = 5;							//
//------------------------------------------//

class F_Cinderella :
	public Friend
{
public:
	F_Cinderella(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Cinderella();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	enum eAkaState {
		Size
	};
};

