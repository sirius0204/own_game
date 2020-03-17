#include "G_SpinFloor.h"



G_SpinFloor::G_SpinFloor(const std::vector<double>& _infos)
{
	Initialize(_infos);
}


G_SpinFloor::~G_SpinFloor()
{
}


void G_SpinFloor::Initialize(const std::vector<double>& info) {
	setExist(true);
	point.x = info[0];
	point.y = info[1];
	height = info[2];
	width = info[3];

	moveFloorNum[0] = info[4];
	moveFloorNum[1] = info[5];
	moveFloorNum[2] = info[6];
	moveFloorNum[3] = info[7];
	
	id = (int)info[8];
	state = (int)info[9];

	//soundFile[0] = LoadSoundMem("./resource/sound/SE/ÉhÉAäJÇØÇÈ.ogg");
	//soundFile[1] = LoadSoundMem("./resource/sound/SE/ÉhÉAï¬ÇﬂÇÈÇQ.ogg");

}
void G_SpinFloor::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	addCount();
	if (state > 2) {	//âÒì]íÜÇ»ÇÁ
		if (getCount() >= 10) {
			state %= 2;
		}
		return;
	}
	//âÒì]èàóù
	if (Input.getMousePressLeftOnce()) {
		if (isHitPoint(Input.getMousePoint()-screen)) {
			std::swap(height, width);
			setCount(0);
			for (int i = 0; i < 4; i++) {
				gimics[moveFloorNum[i]]->setExist(!((bool)(state)));
			}
			//PlaySoundMem(soundFile[state],DX_PLAYTYPE_BACK);
			state ? --id : ++id;
			state += 3;
			return;
		}
	}
	if (state == 0) {
		for (Enemy* enemy : enemys) {
			if (isHitBox(*enemy)) {
				enemy->setMaxY(point.y);
			}
		}
		for (Friend* fre : friends) {
			if (isHitBox(*fre)) {
				fre->setMaxY(point.y);
			}
		}
	}
}
void G_SpinFloor::Finalize() {

}
