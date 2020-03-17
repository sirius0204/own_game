#include "G_Kabu.h"



G_Kabu::G_Kabu(const std::vector<double>& info)
{
	Initialize(info);
}


G_Kabu::~G_Kabu()
{
}

void G_Kabu::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];

	//soundFile[0] = LoadSoundMem("./resource/sound/SE/スコアアップ、スピードアップ.ogg");
}
void G_Kabu::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (isHitBox(*fre)) {
			fre->setCount(120);
			setExist(false);
			if (fre->getId() == 11 || fre->getId() == 12) {
				fre->setId(fre->getId() + 4);
			}
			else if (fre->getId() == 15 || fre->getId() == 16) {
				fre->setCount(120);
			}
		//	PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
			score += 200;
		}
	}
}
void G_Kabu::Finalize() {
}