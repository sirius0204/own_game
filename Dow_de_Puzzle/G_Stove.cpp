#include "G_Stove.h"



G_Stove::G_Stove(const std::vector<double>& info)
{
	Initialize(info);
}


G_Stove::~G_Stove()
{
}

void G_Stove::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	moveFloorNum[0] = info[4];
	moveFloorNum[1] = info[5];
	state = info[7];
	id = info[6];

	/*soundFile[0] = LoadSoundMem("./resource/sound/SE/焼ける音（短）.ogg");
	soundFile[1] = LoadSoundMem("./resource/sound/SE/点火.ogg");*/
	//graphFile[0] = LoadGraph("./resource/img/Gimic/yajirushi4.png");
}

void G_Stove::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{
	addCount();
	if (state == 0) {
		//点火処理　ストーブからは行わない
		/*for (Friend* fre : friends) {
			if (fre == NULL || !fre->getExist()) continue;
			if (isHitBox(*fre)) {
				if (fre->getState() == F_Aka::Naked) continue;
				fre->setState(fre->getState() + 1);
				fre->setId(fre->getId() + 1);
				setCount(0);
				gimics[moveFloorNum[0]]->setExist(true);
				gimics[moveFloorNum[1]]->setExist(true);
				state = 1;
			}
		}*/
		//DrawRotaGraph(point.x + width / 2, point.y + height / 2, 1.0, 180, graphFile[0], true);
	}
	else if (state == 1) {
		if (getCount() == 60) {
			state = 2;
			id++;
			//PlaySoundMem(soundFile[1], DX_PLAYTYPE_BACK);
		}
	}
	else {
		for (Enemy* enemy : enemys) {
			if (enemy == NULL || !enemy->getExist()) continue;
			if (isHitBox(*enemy) && enemy->getState() == 0) {
				enemy->setState(1);
				enemy->setCount(0);
				enemy->setId(1);
				score += 750;
				//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
			}
		}
		for (Friend* fre : friends) {
			if (isHitBox(*fre)) {
				//score -= 500;
			}
		}
	}


}

void G_Stove::Finalize()
{
}

