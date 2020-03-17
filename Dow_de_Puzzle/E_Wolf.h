#pragma once
#include "Enemy.h"

//------------------------------------------//
//	˜TiÔ‚¸‚«‚ñj							//
//		number = 0;							//
//------------------------------------------//

class E_Wolf :
	public Enemy
{
public:
	E_Wolf(int _id, int _hp, int _dir, int _state, const Vector2& pos,double _h, double _w);
	~E_Wolf();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos,double _h, double _w);
	void Update(const Map& map);
	void Finalize();
};

