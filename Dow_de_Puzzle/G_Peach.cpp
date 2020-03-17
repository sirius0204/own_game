#include "G_Peach.h"



G_Peach::G_Peach(const std::vector<double>& info)
{
	Initialize(info);
}


G_Peach::~G_Peach()
{
}

void G_Peach::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = (int)info[4];
	state = (int)info[5];

	//sounFile[0] = LoadSoundMem("./resource/sound/SE/スコアアップ、スピードアップ音.ogg");
}

void G_Peach::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2 & screen, int & score)
{
	for (Friend* fre : friends) {
		std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
		if (friendstate[Friend::eFriendState_St2::IsMomo]) {
			if (isHitBox(*fre)) {
				setExist(false);
				score += 300;
				//(sounFile[0], DX_PLAYTYPE_BACK);
			}
		}
	}
}

void G_Peach::Finalize() {

}
