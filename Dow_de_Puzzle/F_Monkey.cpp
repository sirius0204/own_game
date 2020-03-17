#include "F_Monkey.h"



F_Monkey::F_Monkey(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


F_Monkey::~F_Monkey()
{
}


void F_Monkey::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void F_Monkey::Update(const Map& map) {
	Character::Update(map);
}
void F_Monkey::Finalize() {

}
