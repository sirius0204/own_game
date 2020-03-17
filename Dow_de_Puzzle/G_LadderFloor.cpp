#include "G_LadderFloor.h"


G_LadderFloor::G_LadderFloor(const std::vector<double>& info)
{
	Initialize(info);
}


G_LadderFloor::~G_LadderFloor()
{
}

void G_LadderFloor::Initialize(const std::vector<double>& info) {
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];
	setExist(true);
}

void G_LadderFloor::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	std::bitset<G_Ladder::eLadderState::Size * 10> ladderstate(getState());


	if (Input.getMousePressLeftOnce()) {
		if (isHitPoint(Input.getMousePoint() - screen)) {
			if (!isProcess(friends)) {//íÚéqí âﬂíÜÇ≈Ç»ÇØÇÍÇŒ
				ladderstate[G_Ladder::eLadderState::isAccess] = !ladderstate[G_Ladder::eLadderState::isAccess];
			}
		}
	}

	//ladderstate[G_Ladder::eLadderState::isProcess] = 0;


	//if (ladderstate[G_Ladder::eLadderState::isAccess]){
	//	DrawFormatString(0, 0, GetColor(255, 0, 0), "!!!");
	//}


	int num = 0;
	for (Friend* fre : friends) {
		num++;
		if (fre->getExist() == false || fre == NULL)continue;
		if (ladderstate[G_Ladder::eLadderState::isAccess]) {//í çsâ¬
			std::bitset<Friend::eFriendState_St2::Size> bs(fre->getState());

			if (isHitBox(*fre)) {
				//ladderstate[G_Ladder::eLadderState::isProcess] = 1;
				if (fre->getDir() == 2) {
					ladderstate[G_Ladder::eLadderState::isLadderUp*num] = 1;
				}
				if (ladderstate[G_Ladder::eLadderState::isLadderUp*num]) {
					if (!bs[Friend::eFriendState_St2::Down_Up]) {
						if (fre->getDir() != 2) {
							fre->setPoint({ fre->getPoint().x, getPoint().y - fre->getHeight() });
						}
					}
				}
			}
			else {
				if (!(fre->getPoint().x >= getPoint().x - fre->getWidth() && fre->getPoint().x <= getPoint().x + fre->getWidth())) {
					ladderstate[G_Ladder::eLadderState::isLadderUp*num] = 0;
				}
			}
			fre->setState((int)bs.to_ullong());
		}
		else {
			if (isHitBox(*fre)) {
				if (fre->getPoint().x >= getPoint().x - fre->getWidth() && fre->getPoint().x <= getPoint().x + fre->getWidth() && fre->getPoint().y < getPoint().y) {
					fre->setPoint({ fre->getPoint().x, getPoint().y - fre->getHeight() });
				}
			}
		}
	}

	for (Enemy* ene : enemys) {
		if (isHitBox(*ene) && ene->getPoint().y < getPoint().y) {
			ene->setPoint({ ene->getPoint().x, getPoint().y - ene->getHeight() });
		}
	}

	setState((int)ladderstate.to_ullong());
}
void G_LadderFloor::Finalize() {

}

bool G_LadderFloor::isReachUp(Friend *fre) {
	return fabs(fre->getPoint().y - (getPoint().y - fre->getHeight())) < 10;
}

bool G_LadderFloor::isProcess(std::vector<Friend*> friends) {
	for (Friend* fre : friends) {
		if (fre->getExist() == false || fre == NULL)continue;
		if (isHitBox(*fre))return true;
	}
	return false;
}
