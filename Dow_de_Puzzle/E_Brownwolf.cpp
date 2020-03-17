#include "E_Brownwolf.h"



E_Brownwolf::E_Brownwolf(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


E_Brownwolf::~E_Brownwolf()
{
}

void E_Brownwolf::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}
void E_Brownwolf::Update(const Map& map) {
	if (getState() == 0) Enemy::Update(map);
	else {
		addCount();
		if (getCount() == 180) {
			setId(getId() - 1);
			setState(0);
		}
	}
}
void E_Brownwolf::Finalize() {

}
