#include "F_Pig.h"



F_Pig::F_Pig(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


F_Pig::~F_Pig()
{
}


void F_Pig::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void F_Pig::Update(const Map& map) {
	Character::move(map);
	int cnt = getCount();
	if (cnt >= 120) {
		setAccelaration(getAccelaration()*2.0);
		setCount((getCount() + 1) % 360);
	}
	else {
		setCount((getCount() + 1) % 120);
	}
	if (cnt == 358) {
		if (getId() == 15 || getId() == 16)setId(getId() - 4);
	}
}
void F_Pig::Finalize() {

}

