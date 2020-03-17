#include "G_Mushroom.h"



bool G_Mushroom::isUnderCharacter(Character * chr)
{
	return chr->getMinX() >= point.x && chr->getMaxX() <= point.x + width;
}

G_Mushroom::G_Mushroom(const std::vector<double>& info)
{
	Initialize(info);
}


G_Mushroom::~G_Mushroom()
{
}


void G_Mushroom::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	minH = info[2];
	maxH = info[3];
	setWidth(info[4]);
	addH = info[5];
	for (int i = 0; i < 4; i++) moveFloorNum[i] = info[6 + i];
	id = info[10];
	state = info[11];

	mushcnt = 0;
	isClickable = true;

	//soundFile[0] = LoadSoundMem("./resource/sound/SE/ƒLƒmƒRL‚Ñ‚é‘æ‚QˆÄ.ogg");
	//soundFile[1] = LoadSoundMem("./resource/sound/SE/ƒLƒmƒRk‚Þ.ogg");
}

void G_Mushroom::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{
	addCount();
	if (state == 0) {
		gimics[moveFloorNum[0]]->setExist(false);
		gimics[moveFloorNum[1]]->setExist(false);
		gimics[moveFloorNum[2]]->setExist(true);
		gimics[moveFloorNum[3]]->setExist(true);
		if (Input.getMousePressLeftOnce()) {
			if (isHitPoint(Input.getMousePoint() - screen)) {
				state = 1;
				//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
			}
		}
	}
	else if (state == 1) {
		gimics[moveFloorNum[0]]->setExist(true);
		gimics[moveFloorNum[1]]->setExist(true);
		gimics[moveFloorNum[2]]->setExist(true);
		gimics[moveFloorNum[3]]->setExist(true);
		if (height < maxH) {
			height += addH;
			point.y -= addH;
		}
		else {
			state = 2;
		}
	}
	else if (state == 2) {
		gimics[moveFloorNum[0]]->setExist(true);
		gimics[moveFloorNum[1]]->setExist(true);
		gimics[moveFloorNum[2]]->setExist(false);
		gimics[moveFloorNum[3]]->setExist(false);
		/*if (getCount() == 180) {
			gimics[moveFloorNum[2]]->setExist(true);
			gimics[moveFloorNum[3]]->setExist(true);
			state = 3;
		}*/
		if (Input.getMousePressLeftOnce()) {
			if (isHitPoint(Input.getMousePoint() - screen)) {
				state = 3;
				//PlaySoundMem(soundFile[1], DX_PLAYTYPE_BACK);
			}
		}
	}
	else if (state == 3) {
		gimics[moveFloorNum[0]]->setExist(true);
		gimics[moveFloorNum[1]]->setExist(true);
		gimics[moveFloorNum[2]]->setExist(true);
		gimics[moveFloorNum[3]]->setExist(true);
		if (height > minH) {
			height -= addH;
			point.y += addH;
		}
		else {
			state = 0;
		}
	}

	for (Enemy* enemy : enemys) {
		if (enemy == NULL || enemy->getExist() == false) continue;
		if (isHitBox(*enemy)) {
			enemy->setMaxY(point.y+1);
			enemy->setVelocity({ state == 1 || state == 3 ? 0.0 : enemy->getVelocity().x, 0.0 });
		}
	}
	for (Friend* fre : friends) {
		if (fre == NULL || fre->getExist() == false) continue;
		if (isHitBox(*fre)) {
			fre->setMaxY(point.y+1);
			fre->setVelocity({ state == 1 || state == 3 ? 0.0 : fre->getVelocity().x, 0.0 });
		}
	}
}

void G_Mushroom::Finalize()
{
}
