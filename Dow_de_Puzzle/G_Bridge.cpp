#include "G_Bridge.h"



G_Bridge::G_Bridge(const std::vector<double>& _infos)
{
	Initialize(_infos);
}


G_Bridge::~G_Bridge()
{
}


void G_Bridge::Initialize(const std::vector<double>& info) {
	setExist(true);
	point.x = info[0];
	point.y = info[1];
	height = info[2];
	width = info[3];
	moveFloorNum[0] = info[4];
	moveFloorNum[1] = info[5];
	id = (int)info[6];
	state = (int)info[7];

//	soundFile[0] = LoadSoundMem("./resource/sound/SE/クリック.ogg");
}
void G_Bridge::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	addCount();

	if (Input.getMousePressLeftOnce()) {
		if (isHitPoint(Input.getMousePoint() - screen)) {
			if (state == 0)id = 61;
			else id = 58;
			(++state) %= 2;	
			//todo id変更するぞ！
			//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
		}
	}
	if (state == 0) {
		gimics[moveFloorNum[0]]->setExist(true);
		gimics[moveFloorNum[1]]->setExist(true);
		
	}
	if (state == 1) {
		for (Enemy* enemy : enemys) {
			if (isHitBox(*enemy)) {
				//SetDrawBright(150, 150, 150);
				enemy->setMaxY(point.y);
			}
			//SetDrawBright(255, 255, 255);
		}
		for (Friend* fre : friends) {
			if (isHitBox(*fre)) {
				//SetDrawBright(150, 150, 150);
				fre->setMaxY(point.y);
			}
			//SetDrawBright(255, 255, 255);
		}
		gimics[moveFloorNum[0]]->setExist(false);
		gimics[moveFloorNum[1]]->setExist(false);
	}
}
void G_Bridge::Finalize() {

}