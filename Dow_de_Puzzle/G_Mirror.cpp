#include "G_Mirror.h"





G_Mirror::G_Mirror(const std::vector<double>& info)
{
	Initialize(info);
}


G_Mirror::~G_Mirror()
{
}

void G_Mirror::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	pairMirrorNum = info[4];
	id = info[5];
	state = info[6];

}

void G_Mirror::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (fre == NULL || !fre->getExist()) continue;
		if (fre->isHitBox(*fre)) {
			fre->setPoint(this->point-Vector2(fre->getWidth()-width, fre->getHeight()-height));
		}
	}
}

void G_Mirror::Finalize() {

}
