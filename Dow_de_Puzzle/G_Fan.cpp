#include "G_Fan.h"



G_Fan::G_Fan(const std::vector<double>& info)
{
	Initialize(info);
}


G_Fan::~G_Fan()
{
}


void G_Fan::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	clickRange.setPoint({ info[4], info[5] });
	clickRange.setHeight(info[6]);
	clickRange.setWidth(info[7]);
	hitRange.setPoint({ info[8], info[9] });
	hitRange.setHeight(info[10]);
	hitRange.setWidth(info[11]);
	dir = info[12];
	slowRate = info[13];
	fastRate = info[14];
	id = info[15];
	state = info[16];
	
	//soundFile[0] = LoadSoundMem("./resource/sound/SE/êÓïóã@ÇÃâπ.ogg");
}
void G_Fan::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	addCount();
	if (state == 0) {
		if (clickRange.isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
			state = 1;
			return;
		}
	}
	else if (state == 1) {
		if (clickRange.isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
			state = 0;
			StopSoundMem(soundFile[0]);
			return;
		}
		for (Enemy* enemy : enemys) {
			if (hitRange.isHitBox(*enemy)) {
				if (dir == enemy->getDir()) {
					enemy->setVelocity(enemy->getVelocity()*fastRate);
				}
				else {
					enemy->setVelocity(enemy->getVelocity()*slowRate);
				}
			}
		}
		for (Friend* fre : friends) {
			if (hitRange.isHitBox(*fre)) {
				if (dir == fre->getDir()) {
					fre->setVelocity(fre->getVelocity()*fastRate);
				}
				else {
					fre->setVelocity(fre->getVelocity()*slowRate);
				}
			}
		}
		//PlaySoundMem(soundFile[0], DX_PLAYTYPE_LOOP);
	}
}

void G_Fan::Finalize() {
	StopSoundMem(soundFile[0]);
}

