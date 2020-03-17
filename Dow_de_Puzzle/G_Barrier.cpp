#include "G_Barrier.h"



G_Barrier::G_Barrier(const std::vector<double>& info)
{
	Initialize(info);
}


G_Barrier::~G_Barrier()
{
}

void G_Barrier::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	moveFloorNum[0] = info[4];
	moveFloorNum[1] = info[5];
	id = (int)info[6];
	state = (int)info[7];

	//sounFile[0] = LoadSoundMem("./resource/sound/SE/è·äQï®îjâÛâπÅiìÅÇ¡Ç€Ç≠Ç»Ç¢ãCÇ™ÇµÇ‹Ç∑Åj.ogg");
}

void G_Barrier::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2 & screen, int & score)
{
	for (Friend* fre : friends) {
		std::bitset<Friend::eFriendState_St2::Size> bs(fre->getState());
		if (bs[Friend::eFriendState_St2::IsSword] && isHitBox(*fre)) {
			setExist(false);
			score += 100;
			//PlaySoundMem(sounFile[0], DX_PLAYTYPE_BACK);
			if (getExist() == false) {
				gimics[moveFloorNum[0]]->setExist(false);
				gimics[moveFloorNum[1]]->setExist(false);
			}
		}
		fre->setState((int)bs.to_ullong());
	}
}

void G_Barrier::Finalize()
{
}
