#include "G_Apple.h"



G_Apple::G_Apple(const std::vector<double>& info)
{
	Initialize(info);
}


G_Apple::~G_Apple()
{
}

void G_Apple::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];

	soundFile[0] = LoadSoundMem("./resource/sound/SE/ƒŠƒ“ƒS—Ž‰º.ogg");
}
void G_Apple::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	addCount();
	if (Input.getMousePressLeftOnce()) {
		if (isHitPoint(Input.getMousePoint() - screen)) {
			if (state == 0) {
				state = 1;
				//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
			}
		}
	}
	if (state > 0 && state < 45) {
		state += 1;
		point.y += 2.0;
		for (Enemy* ene : enemys) {
			if (isHitBox(*ene)) {
				ene->setState(1);
				ene->setCount(0);
				state = 45;
				if (ene->getId() == 5)ene->setId(ene->getId() + 1);
				score += 200;
			}
		}
	}

	if (state >= 45) {
		setExist(false);
	}


}
void G_Apple::Finalize() {
}