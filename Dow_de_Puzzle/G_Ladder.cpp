#include "G_Ladder.h"


G_Ladder::G_Ladder(const std::vector<double>& info)
{
	Initialize(info);
}


G_Ladder::~G_Ladder()
{
}


void G_Ladder::Initialize(const std::vector<double>& info) {
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];
	setExist(true);


}

void G_Ladder::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	addCount();
	std::bitset<G_Ladder::eLadderState::Size * 10> ladderstate(getState());

	if (Input.getMousePressLeftOnce()) {
		if (isHitPoint(Input.getMousePoint() - screen)) {
			if (!isProcess(friends)) {//梯子通過中でなければ
				ladderstate[G_Ladder::eLadderState::isAccess] = !ladderstate[G_Ladder::eLadderState::isAccess];
				ladderstate[G_Ladder::eLadderState::isAccess] ? ++id : --id;
			}
		}
	}

	for (Friend* fre : friends) {
		if (ladderstate[G_Ladder::eLadderState::isAccess] == 1) {
			if (fre->getExist() == false || fre == NULL)continue;

			if (isHitBox(*fre)) {

				std::bitset<Friend::eFriendState_St2::Size> bs(fre->getState());
				if (fabs(fre->getCenterPoint().x - getLadderCenter_x()) < 10) {
					if (bs[Friend::eFriendState_St2::On_Off]) {//on梯子なら
						if (bs[Friend::eFriendState_St2::Down_Up]) {//梯子をおりているなら
							if (isReachDown(fre)) {
								bs[Friend::eFriendState_St2::On_Off] = 0;
								fre->setId(fre->getId() - 1);
							}
						}
						else {
							if (isReachUp(fre)) {
								bs[Friend::eFriendState_St2::On_Off] = 0;
								fre->setId(fre->getId() - 1);
							}
						}
						if (!bs[Friend::eFriendState_St2::On_Off]) {
							fre->setDir(bs[Friend::eFriendState_St2::Right_Left]);
							fre->setVelocity({ 0, 0 });
							bs[Friend::eFriendState_St2::Rel_Cat] = 0;
						}
					}
					else if (bs[Friend::eFriendState_St2::Rel_Cat]) {//梯子catchなら
						bs[Friend::eFriendState_St2::Right_Left] = fre->getDir();
						bs[Friend::eFriendState_St2::On_Off] = 1;
						bs[Friend::eFriendState_St2::Down_Up] = fre->getPoint().y < getPoint().y;
						fre->setDir(bs[Friend::eFriendState_St2::Down_Up] + 2);
						fre->setVelocity({ 0, 0 });
						fre->setId(fre->getId() + 1);
					}
				}
				else {
					bs[Friend::eFriendState_St2::Rel_Cat] = 1;
				}
				fre->setState((int)bs.to_ullong());
			}
		}
	}

	setState((int)ladderstate.to_ullong());
}

void G_Ladder::Finalize() {

}

double G_Ladder::getLadderCenter_x() {
	return getPoint().x + getWidth() / 2;
}

//Vector2 G_Ladder::makeVelocity(){
//	return Vector2({ getLadderCenter_x(), getPoint().y + getHeight() }) - Vector2({ getLadderCenter_x(), getPoint().y })*0.1;
//}

bool G_Ladder::isReachDown(Friend *fre) {
	return fabs(fre->getPoint().y - (getPoint().y + getHeight() - fre->getHeight())) < 10;
}

bool G_Ladder::isReachUp(Friend *fre) {
	return fabs(fre->getPoint().y - (getPoint().y - fre->getHeight())) < 10;
}

bool G_Ladder::isProcess(std::vector<Friend*> friends) {
	for (Friend* fre : friends) {
		if (fre->getExist() == false)continue;
		if (isHitBox(*fre))return true;
	}
	return false;
}
