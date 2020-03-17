#include "G_MoveFloor.h"



G_MoveFloor::G_MoveFloor(const std::vector<double>& info)
{
	Initialize(info);
}


G_MoveFloor::~G_MoveFloor()
{
}

void G_MoveFloor::Initialize(const std::vector<double>& info)
{
	setPoint({ info[0],info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	range.setPoint({ info[4],info[5] });
	range.setHeight(info[6]);
	range.setWidth(info[7]);
	setExist((bool)((int)info[8]));
	id = info[9];
	state = info[10];

	//soundFile[0] = LoadSoundMem("./resource/sound/SE/ƒNƒŠƒbƒN.ogg");
}

void G_MoveFloor::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{
	addCount();
	if (Input.getMousePressLeftOnce()) {
		if (isHitPoint(Input.getMousePoint() - screen)) {
			state ? --id : ++id;
			(++state) %= 2;
			//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
			return;
		}
	}
	for (Enemy* enemy : enemys) {
		if (enemy == NULL || enemy->getExist() == false) continue;
		if (range.isHitBox(*enemy)) {
			if (enemy->getVelocity().x > 0 && state==0) {
				//enemy->setMaxX(this->getPoint().x-1);
			}
			else if(enemy->getVelocity().x < 0 && state == 1){
				//enemy->setMinX(this->getPoint().x + width+1);
			}
			enemy->setDir(state);
		}
	}
	for (Friend* fre : friends) {
		if (fre == NULL || fre->getExist() == false) continue;
		if (range.isHitBox(*fre)) {
			if (fre->getVelocity().x > 0 && state == 0) {
				//fre->setMaxX(this->getPoint().x-1);
			}
			else if(fre->getVelocity().x < 0 && state == 1){
				//fre->setMinX(this->getPoint().x + width+1);
			}
			fre->setDir(state);
		}
	}
}

void G_MoveFloor::Finalize()
{
}

