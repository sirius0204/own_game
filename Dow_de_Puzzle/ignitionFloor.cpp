#include "ignitionFloor.h"



ignitionFloor::ignitionFloor(const std::vector<double>& info)
{
	Initialize(info);
}


ignitionFloor::~ignitionFloor()
{
}


void ignitionFloor::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	stoveNum = info[4];
	state = info[5];
	id = info[6];
}
void ignitionFloor::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (fre == NULL || !fre->getExist()) continue;
		if (isHitBox(*fre) && state == fre->getDir() && gimics[stoveNum]->getState()==0) {
			if (fre->getState() == F_Aka::Naked) continue;
			gimics[stoveNum]->setCount(0);
			gimics[stoveNum]->setState(1);
			fre->setDir((state + 1) % 2);
			fre->setState(fre->getState() + 1);
			fre->setId(fre->getId() + 1);
		}
		else if (isHitBox(*fre)) {
			fre->setDir((state + 1) % 2);
		}
	}
	for (Enemy* enemy : enemys) {
		if (enemy == NULL || !enemy->getExist()) continue;
		if (isHitBox(*enemy)) {
			enemy->setDir((state + 1) % 2);
		}
	}
}
void ignitionFloor::Finalize() {

}