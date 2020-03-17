#include "F_Dwarf.h"



F_Dwarf::F_Dwarf(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


F_Dwarf::~F_Dwarf()
{
}


void F_Dwarf::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void F_Dwarf::Update(const Map& map) {
	Character::Update(map);
}
void F_Dwarf::Finalize() {

}
