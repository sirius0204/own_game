#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}

void Enemy::Update(const Map & map)
{

	Character::Update(map);
}

void Enemy::Finalize()
{
}
