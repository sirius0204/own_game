#include "E_Wolf.h"



E_Wolf::E_Wolf(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


E_Wolf::~E_Wolf()
{
}

void E_Wolf::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void E_Wolf::Update(const Map& map) {
	if(getState()==0) Enemy::Update(map);
	else {
		addCount();
		point.y += 1;
		if (getCount() == 60) {
			setExist(false);
		}
	}
}
void E_Wolf::Finalize() {

}
