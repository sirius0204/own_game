#include "G_Stone.h"



G_Stone::G_Stone(const std::vector<double>& info)
{
	Initialize(info);
}


G_Stone::~G_Stone()
{
}


void G_Stone::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];

}
void G_Stone::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (fre == NULL || !fre->getExist()) continue;
		if (isHitBox(*fre) && fre->getState()==0) {
			setExist(false);
			fre->setState(1);
		}
	}
}
void G_Stone::Finalize() {

}
