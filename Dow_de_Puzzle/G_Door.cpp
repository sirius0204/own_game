//#include "G_Door.h"
//
//
//
//G_Door::G_Door(const std::vector<double>& info)
//{
//	Initialize(info);
//}
//
//
//G_Door::~G_Door()
//{
//}
//
//void G_Door::Initialize(const std::vector<double>& info) {
//	setExist(true);
//	setPoint({ info[0], info[1] });
//	setHeight(info[2]);
//	setWidth(info[3]);
//	state = info[4];
//	id = info[5];
//}
//void G_Door::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
//	if (state == 0) return;
//	for (Enemy*enemy : enemys) {
//		if (enemy == NULL || !enemy->getExist()) continue;
//		if (isHitBox(*enemy)) {
//			enemy->setDir((enemy->getDir() + 1) % 2);
//		}
//	}
//	for (Friend* fre : friends) {
//		if (fre == NULL || !fre->getExist()) continue;
//		if (isHitBox(*fre)) {
//			fre->setDir((fre->getDir() + 1) % 2);
//		}
//	}
//}
//void G_Door::Finalize() {
//
//}