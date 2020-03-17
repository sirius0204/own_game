#include "G_Collection.h"



G_Collection::G_Collection(const std::vector<double>& info)
{
	Initialize(info);
}


G_Collection::~G_Collection()
{
}

void G_Collection::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];

	soundFile[0] = LoadSoundMem("./resource/sound/SE/ï®ÇéùÇ¬âπ.ogg");
}
void G_Collection::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (isHitBox(*fre)) {
			fre->setHp(fre->getHp() + (1 << (state * 10)));
			setExist(false);
			score += 200;
			//PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
		}
	}
}
void G_Collection::Finalize() {
}