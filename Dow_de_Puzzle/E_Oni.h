#pragma once
#include "Enemy.h"

//------------------------------------------//
//	‰¤Žq									//
//		number = 3;							//
//------------------------------------------//

class E_Oni :
	public Enemy
{
public:
	E_Oni(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~E_Oni();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();
};

