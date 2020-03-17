#pragma once
#include "Enemy.h"

//------------------------------------------//
//	��(�����Y)								//
//		number = 2;							//
//	�@�\									//
//		����								//
//	�����l����								//
//		state	:							//
//------------------------------------------//

class E_Dog :
	public Enemy
{
public:
	E_Dog(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~E_Dog();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();
};

