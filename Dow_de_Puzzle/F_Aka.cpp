#include "F_Aka.h"



F_Aka::F_Aka(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


F_Aka::~F_Aka()
{
}


void F_Aka::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void F_Aka::Update(const Map& map) {
	Character::Update(map);
}
void F_Aka::Finalize() {

}
