#include "E_Dog.h"



E_Dog::E_Dog(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


E_Dog::~E_Dog()
{
}

void E_Dog::Initialize(int _id, int _hp, int _dir, int _state, const Vector2 & pos, double _h, double _w)
{
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}

void E_Dog::Update(const Map & map)
{
	Character::Update(map);
	setVelocity(getVelocity()*1.1);
}

void E_Dog::Finalize()
{
}
