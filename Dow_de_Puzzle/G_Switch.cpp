//#include "G_Switch.h"
//
//
//
//G_Switch::G_Switch(const std::vector<double>& info)
//{
//	Initialize(info);
//}
//
//
//G_Switch::~G_Switch()
//{
//}
//
//
//void G_Switch::Initialize(const std::vector<double>& info) {
//	setExist(true);
//	setPoint({ info[0], info[1] });
//	setHeight(info[2]);
//	setWidth(info[3]);
//	doorNum = info[4];
//	state = info[5];
//	id = info[6];
//}
//void G_Switch::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
//	/*for (Friend*fre : friends) {
//	if (fre == NULL || !fre->getExist()) continue;
//	if (isHitBox(*fre)) {
//	gimics[doorNum]->setState((gimics[doorNum]->getState() + 1) % 2);
//	}
//	}*/
//	for (int i = 0; i < friends.size(); i++) {
//		if (friends[i] == NULL && !friends[i]->getExist()) continue;
//		if (isHitBox(*friends[i])) {
//			if (st.count(i)) continue;
//			gimics[doorNum]->setState((gimics[doorNum]->getState() + 1) % 2);
//			st.insert(i);
//		}
//		else {
//			auto it = st.find(i);
//			if (it == st.end()) continue;
//			st.erase(it);
//		}
//	}
//}
//void G_Switch::Finalize() {
//
//}
