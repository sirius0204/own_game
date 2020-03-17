#include "G_Flower.h"



G_Flower::G_Flower(const std::vector<double>& info)
{
	Initialize(info);
}


G_Flower::~G_Flower()
{
}

void G_Flower::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	wineNum = (int)info[4];
	id = info[5];
	state = info[6];
//	soundFile[0] = LoadSoundMem("./resource/sound/SE/スコアアップ、スピードアップ音.ogg");
}

void G_Flower::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics,const Vector2 & screen, int & score)
{
	addCount();
	for (Friend* fre : friends) {
		if (isHitBox(*fre)) {
			gimics[wineNum]->setExist(true);
			setExist(false);
	//		PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
			score += 200;
		}
	}
}

void G_Flower::Finalize()
{
}
