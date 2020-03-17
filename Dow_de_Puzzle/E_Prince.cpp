#include "E_Prince.h"



E_Prince::E_Prince(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


E_Prince::~E_Prince()
{
}

void E_Prince::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void E_Prince::Update(const Map& map) {
	if (getState() == 0) Enemy::Update(map);

}
void E_Prince::Finalize() {

}
