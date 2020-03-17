#include "Collider.h"


Collider::Collider()
{
	Initialize();
}


Collider::~Collider()
{

}

void Collider::Initialize() {
	std::fill(Flags, Flags + 100, 0);
	soundFile[0] = LoadSoundMem("./resource/sound/SE/スイッチオン.ogg");
	soundFile[1] = LoadSoundMem("./resource/sound/SE/ダメージ（桃太郎,子豚向け）feat.鏡音レン「痛っ」.ogg");
	soundFile[2] = LoadSoundMem("./resource/sound/SE/ダメージ（声なし）.ogg");

}

void Collider::Update(std::vector<Friend*> friends, std::vector<Enemy*> enemys, std::vector<Gimic*> gimics, int stage, int& score, int& life) {

	int stageType = getStageType(stage);
	for (Friend* fre : friends) {
		if (stageType == Collider::eStagetype::Aka) {
			int i = 0;
			for (Enemy* ene : enemys) {
				if (ene->getExist() == false || ene == NULL)continue;
				if (fre->isHitBox(*ene)) {
					if (!Flags[i]) {
						life--;
						Flags[i] = 1;
						if (stage / 4 == 0)PlaySoundMem(soundFile[2], DX_PLAYTYPE_BACK, true);
						else if (stage / 4 == 2)PlaySoundMem(soundFile[2], DX_PLAYTYPE_BACK, true);
					}
				}
				else {
					Flags[i] = 0;
				}
				i++;
			}
			for (Gimic* gim : gimics) {
				if (gim->getId() == 14) {
					if (fre->isHitBox(*gim) && fre->getPoint().y < gim->getPoint().y) {
						if (!Flags[i]) {
							life--;
							Flags[i] = 1;
						}
					}
					else {
						Flags[i] = 0;
					}
				}
				i++;
			}
		}
		else if (stageType == Collider::eStagetype::Momotaro) {
			std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
			if (friendstate[Friend::eFriendState_St2::IsMomo]) {
				int i = 0;
				for (Enemy* ene : enemys) {
					if (ene->getExist() == false || ene == NULL)continue;
					if (ene->getId() == 4) {
						if (fre->isHitBox(*ene)) {
							if (!Flags[i]) {
								Flags[i] = 1;
								life--;
								PlaySoundMem(soundFile[2], DX_PLAYTYPE_BACK, true);
							}
						}
						else {
							Flags[i] = 0;
						}
					}
					else {
						if (fre->isHitBox(*ene)) {
							addAnimal(friendstate);
							fre->setState((int)friendstate.to_ullong());
							ene->setExist(false);
							score += 900;
							PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
						}
					}
					i++;
				}

				for (Friend* other : friends) {
					if (other == fre)continue;
					if (other->getExist() == false)continue;
					if (fre->isHitBox(*other)) {
						addAnimal(friendstate);
						other->setExist(false);
						fre->setState((int)friendstate.to_ullong());
						score += 900;
						PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK);
					}
				}
			}

		}
		else if (stageType == Collider::eStagetype::Buta) {
			int i = 0;
			for (Enemy* ene : enemys) {
				if (ene->getExist() == false || ene == NULL)continue; 
				if (fre->isHitBox(*ene)) {
					if (!Flags[i] && ene->getId() == 5) {
						life--;
						Flags[i] = 1;
						if (stage / 4 == 0)PlaySoundMem(soundFile[2], DX_PLAYTYPE_BACK, true);
						else if (stage / 4 == 2)PlaySoundMem(soundFile[2], DX_PLAYTYPE_BACK, true);
					}
				}
				else {
					Flags[i] = 0;
				}
				i++;
			}
		}
	}
}

void Collider::Finalize() {}

int Collider::getStageType(int stage) {
	if (stage / 4 == 0) {
		return Collider::eStagetype::Aka;
	}
	else if (stage / 4 == 1) {
		return Collider::eStagetype::Momotaro;
	}
	else if (stage / 4 == 2) {
		return Collider::eStagetype::Buta;
	}
	//return Collider::eStagetype::Sirayuki;
}

void Collider::addAnimal(std::bitset<Friend::eFriendState_St2::Size> &bs) {
	if (bs[Friend::eFriendState_St2::HaveAnimalNum1]) {
		if (!bs[Friend::eFriendState_St2::HaveAnimalNum2]) {
			bs[Friend::eFriendState_St2::HaveAnimalNum1] = 0;
			bs[Friend::eFriendState_St2::HaveAnimalNum2] = 1;
		}
	}
	else {
		bs[Friend::eFriendState_St2::HaveAnimalNum1] = 1;
	}
}