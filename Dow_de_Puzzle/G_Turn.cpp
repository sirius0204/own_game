#include "G_Turn.h"


G_Turn::G_Turn(const std::vector<double>& info)
{
	Initialize(info);
}


G_Turn::~G_Turn()
{
}

void G_Turn::Initialize(const std::vector<double>& info){
	setExist(true);
	state = info[0];
	id = info[0];

	soundFile[0] = LoadSoundMem("./resource/sound/SE/ƒNƒŠƒbƒN.ogg");
}
void G_Turn::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score){
	//assert(false);
	for (Friend* fre : friends){
		if (fre->getExist() == false || fre == NULL)continue;
		if (fre->getId() == 13 || fre->getId() == 14)continue;
		if (Input.getMousePressLeftOnce()){
			if (fre->isHitPoint(Input.getMousePoint() - screen)){
				if (fre->getDir() < 2){
					fre->setDir((fre->getDir() + 1) % 2);
					//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
				}
			}
		}
	}
}

void G_Turn::Finalize(){

};