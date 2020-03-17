#include "G_Bird.h"



G_Bird::G_Bird(const std::vector<double>& info)
{
	Initialize(info);
}


G_Bird::~G_Bird()
{
}


void G_Bird::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	tree[0] = { info[4],info[5] };
	tree[1] = { info[6],info[7] };
	stopflame = info[8];
	moveflame = info[9];
	state = info[11];
	id = info[10];
	velocity = { 0.0,0.0 };
	accelaration = (tree[1] - tree[0])*(1.0/moveflame);
	setCount(0);

	//soundFile[0] = LoadSoundMem("./resource/sound/SE/はばたき（仮）.ogg");
	//soundFile[1] = LoadSoundMem("./resource/sound/SE/スイッチオン.ogg");
}

void G_Bird::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		if (isHitBox(*fre)) {
			std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
			if (friendstate[Friend::eFriendState_St2::IsMomo]) {
				if (getExist() == true) {
					addAnimal(friendstate);
					fre->setState((int)friendstate.to_ullong());
					setExist(false);
					//StopSoundMem(soundFile[0]);
					score += 900;
					//PlaySoundMem(soundFile[1], DX_PLAYTYPE_BACK, true);
				}
			}
		}
	}

	addCount();
	cnt %= (stopflame + moveflame);
	if (cnt == 0) {
		velocity = { 0.0,0.0 };
		(++state) %= 2;
		accelaration *= -1;
		StopSoundMem(soundFile[0]);
		id++;
		if (state == 0)id = 22;
	}
	else if (cnt < stopflame) return;	//停止
	else {
		velocity += accelaration;
		point += velocity;
		velocity *= 0.0;
		if (id == 22 || id == 24)id++;
	}
}
void G_Bird::Finalize() {
	
}

void G_Bird::addAnimal(std::bitset<Friend::eFriendState_St2::Size> &bs){
	if (bs[Friend::eFriendState_St2::HaveAnimalNum1]){
		if (!bs[Friend::eFriendState_St2::HaveAnimalNum2]){
			bs[Friend::eFriendState_St2::HaveAnimalNum1] = 0;
			bs[Friend::eFriendState_St2::HaveAnimalNum2] = 1;
		}
	}
	else{
		bs[Friend::eFriendState_St2::HaveAnimalNum1] = 1;
	}
}