#include "G_Sword.h"


G_Sword::G_Sword(const std::vector<double>& info)
{
	Initialize(info);
}


G_Sword::~G_Sword()
{
}

void G_Sword::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = (int)info[4];
	state = (int)info[5];

	//sounFile[0] = LoadSoundMem("./resource/sound/SE/ï®ÇéùÇ¬âπ.ogg");
}

void G_Sword::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2 & screen, int & score)
{
	for (Friend * fre : friends) {
		std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
		if (friendstate[Friend::eFriendState_St2::IsMomo]){
			if (isHitBox(*fre)) {
				setExist(false);
				friendstate[Friend::eFriendState_St2::IsSword] = 1;
				fre->setState((int)friendstate.to_ullong());
				fre->setId(fre->getId() + 2);
				score += 100;
				//PlaySoundMem(sounFile[0], DX_PLAYTYPE_BACK);
			}
		}
	}
}

void G_Sword::Finalize()
{
}
