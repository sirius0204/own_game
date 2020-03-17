#pragma once
#include "Enemy.h"

//------------------------------------------//
//	�T�i�u�^�j								//
//		number = 4;							//
//------------------------------------------//

class E_Brownwolf :
	public Enemy
{
public:
	E_Brownwolf(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~E_Brownwolf();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();
};
