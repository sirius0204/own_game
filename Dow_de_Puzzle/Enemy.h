#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy();
	~Enemy();

	virtual void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	virtual void Update(const Map& map);
	virtual void Finalize();

	
};

