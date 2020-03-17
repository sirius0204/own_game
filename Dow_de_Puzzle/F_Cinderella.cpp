#include "F_Cinderella.h"



F_Cinderella::F_Cinderella(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


F_Cinderella::~F_Cinderella()
{
}


void F_Cinderella::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void F_Cinderella::Update(const Map& map) {
	Character::Update(map);
}
void F_Cinderella::Finalize() {

}
