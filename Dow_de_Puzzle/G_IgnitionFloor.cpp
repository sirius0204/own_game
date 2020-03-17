#include "G_IgnitionFloor.h"



G_IgnitionFloor::G_IgnitionFloor(const std::vector<double>& info)
{
	Initialize(info);
}


G_IgnitionFloor::~G_IgnitionFloor()
{
}


void G_IgnitionFloor::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	stoveNum = info[4];
	id = info[5]; 
	state = info[6];

	akaflag = 2;

	soundFile[0] = LoadSoundMem("./resource/sound/SE/“_‰Î.ogg");
}
void G_IgnitionFloor::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (fre == NULL || !fre->getExist()) continue;
		if (isHitBox(*fre) && state == fre->getDir() && gimics[stoveNum]->getState() == 0) {
			if (fre->getState() == F_Aka::Naked) continue;
			gimics[stoveNum]->setCount(0);
			gimics[stoveNum]->setState(1);
			fre->setDir((state + 1) % 2);
			fre->setState(fre->getState() + 1);
			akaflag = fre->getDir();
			akacnt = 0;
			if (fre->getDir() == 0)fre->setId(fre->getId() + 1);
			else if (fre->getDir() == 1)fre->setId(fre->getId() + 2);
			score += 500;
		}
		else if (isHitBox(*fre)) {
			fre->setDir((state + 1) % 2);
		}
		if (akaflag == 1 || akaflag == 0) {
			if (akacnt < 60) {
				fre->setDir(3);
			}
			if (akacnt == 60) {
				fre->setDir(akaflag);
				if(akaflag==0)fre->setId(fre->getId() + 2);
				else if (akaflag == 1)fre->setId(fre->getId() + 1);
			}
			akacnt++;
		}
	}
	for (Enemy* enemy : enemys) {
		if (enemy == NULL || !enemy->getExist()) continue;
		if (isHitBox(*enemy)) {
			enemy->setDir((state + 1) % 2);
		}
	}
}
void G_IgnitionFloor::Finalize() {

}