#include "E_Oni.h"



E_Oni::E_Oni(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


E_Oni::~E_Oni()
{
}

void E_Oni::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void E_Oni::Update(const Map& map) {
	if (getState() == 0) Enemy::Update(map);

}
void E_Oni::Finalize() {

}
