#include "Tutorial.h"



bool Tutorial::checkStep(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{
	if (stage == 0) {
		switch (step)
		{
		case 0://チュートリアル開始
			if (Input.getMousePressLeftOnce()) {
				step = 1;
			}
			break;
		case 1://赤ずきん移動開始
			fRunFriends = true;
			fRungimics = true;
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 160,140 })) {
				fRunFriends = false;
				step = 2;
			}
			
			break;
		case 2://赤ずきんがきのこの前に来たら
			if (gimics[4]->isHitPoint(Input.getMousePoint() - screen)) {
				if (gimics[4]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 3;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 3://キノコをクリックしたら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 336,140 })) {
				fRunFriends = false;
				step = 4;
			}
			break;
		case 4://赤ずきんがオオカミの前に来たら
			if (friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				if (friends[0]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 5;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 5://赤ずきんをクリックしたら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 230,140 })) {
				fRunFriends = false;
				step = 6;
			}
			break;
		case 6://赤ずきんがキノコの上に来たら
			if (gimics[4]->isHitPoint(Input.getMousePoint() - screen)) {
				if (gimics[4]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 9;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 7://キノコがクリックされたら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 130,380 })) {
				fRunFriends = false;
				step = 10;
			}
			break;
		case 8://赤ずきんがキノコから降りたら
			if (friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				if (friends[0]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 9;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 9://赤ずきんが方向転換したら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (gimics[7]->getState() == 1) {
				fRunEnemys = true;
				step = 10;
			}
			break;
		case 10://赤ずきんが暖炉に点火したら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (enemys[0]->isHitPoint({ 520,140 })) {
				fRunEnemys = false;
				fRunFriends = false;
				step = 12;
			}
			break;
		case 11://

			break;
		case 12://オオカミが橋の上に来たら
			if (gimics[10]->isHitPoint(Input.getMousePoint() - screen)) {
				if (gimics[10]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunEnemys = true;
					step = 13;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 13://橋がクリックされたら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682
				) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (!enemys[0]->getExist()) {
				step = 14;
			}
			break;
		case 14://オオカミ焼き終わると
			if (Input.getMousePressLeftOnce()) {
				step = 15;
			}
			break;
		default:
			return false;
		}
	}

	else if (stage == 4) {
		switch (step)
		{
		case 0://チュートリアル開始
			if (Input.getMousePressLeftOnce()) {
				step = 16;
			}
			break;
		case 16://桃太郎移動開始
			fRunFriends = true;
			fRunEnemys = false;
			fRungimics = false;
			if (friends[0]->isHitPoint({ 320, 528 })) {
				fRunFriends = false;
				fRunEnemys = false;
				step = 1;
			}
			break;
		case 1://桃太郎が梯子の前に来たら
			fRungimics = true;
			if (gimics[8]->isHitPoint(MousePoint)) {
				if (gimics[8]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 2;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 2://梯子がクリックされたら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 570, 340 })) {
				fRunFriends = false;
				step = 3;
			}
			break;
		case 3://桃太郎が鬼の近くに来たら
			if (friends[0]->isHitPoint(MousePoint)) {
				if (friends[0]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 4;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 4://桃太郎が向きを変えたら
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 390, 340 })) {
				fRunFriends = false;
				step = 5;
			}
			break;
		case 5://梯子の前に来たら
			if (gimics[8]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
				step = 17;
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 17:
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			else {
				if (Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 6;
				}
			}
			break;
		case 6://梯子をクリックしたら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (enemys[0]->getExist() == 0) {
				fRunFriends = false;
				step = 18;
			}
			break;
		case 18:
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				step = 7;
			}
			break;
		case 7://犬を仲間にしたら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				fRunFriends = true;
				friends[1]->setExist(0);
				gimics[10]->setExist(0);
				step = 8;
			}
			break;
		case 8://クリックされて動き出したら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 146,340 })) {
				fRunFriends = false;
				step = 9;
			}
			break;
		case 9://障害物に当たったら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				fRunFriends = true;
				step = 10;
			}
			break;
		case 10://クリックされて動き出したら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 490,340 })) {
				fRunFriends = false;
				step = 11;
			}
			break;
		case 11://桃太郎が橋の上に来たら
			if (gimics[5]->isHitPoint(MousePoint)) {
				if (gimics[5]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 12;
				}
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			break;
		case 12://橋がクリックされたら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->getId() == 9) {
				fRunFriends = false;
				step = 13;
			}
			break;
		case 13://刀をとったら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				fRunFriends = true;
				step = 14;
			}
			break;
		case 14://クリックされて動き出したら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 750,528 })) {
				fRunFriends = false;
				step = 15;
			}
			break;
		case 15://船についたら
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				step = 20;
			}
			break;
		default:
			return false;
		}
	}

	else if (stage == 8) {
		switch (step)
		{
		case 0://チュートリアル開始
			if (Input.getMousePressLeftOnce()) {
				step = 8;
			}
			break;
		case 8: //豚移動開始
			fRunFriends = true;
			fRungimics = true;
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (!gimics[6]->getExist()) { //レンガをとる
				fRunFriends = false;
				step = 1;
			}
			break;
		case 1: //クリックして再開
			if (gimics[2]->isHitPoint(Input.getMousePoint()-screen) || gimics[10]->isHitPoint(Input.getMousePoint() - screen) || friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				Input.setMouseIgnoreClick();
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				if (Input.getMousePressLeftOnce()) {
					fRunFriends = true;
					step = 9;
				}
			}
			break;
		case 9:
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (!gimics[7]->getExist()) { //ワラを取る
				fRunFriends = false;
				step = 2;
			}
			break;
		case 2:
			if (gimics[2]->isHitPoint(Input.getMousePoint() - screen) || gimics[10]->isHitPoint(Input.getMousePoint() - screen) || friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				Input.setMouseIgnoreClick();
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				if (Input.getMousePressLeftOnce()) { //クリックして再開
					fRunFriends = true;
					step = 10;
				}
			}
			break;
		case 10:
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 502,190 })) { //豚が橋の上にくる
				fRunFriends = false;
				step = 3;
			}
			break;
		case 3:
			if (gimics[10]->isHitPoint(Input.getMousePoint() - screen) || friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				Input.setMouseIgnoreClick();
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				if (gimics[2]->getId() == 58) { //橋をクリックして豚を落とす
					fRunFriends = true;
					fRunEnemys = true;
					step = 11;
				}
			}
			break;
		case 11:
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 230,330 })) {//豚がオオカミにあたりそうになったら
				fRunFriends = false;
				fRunEnemys = false;
				step = 4;
			}
			break;
		case 4:
			if (gimics[2]->isHitPoint(Input.getMousePoint() - screen) || gimics[10]->isHitPoint(Input.getMousePoint() - screen)) {
				Input.setMouseIgnoreClick();
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				if (friends[0]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {//豚が方向転換したら
					fRunFriends = true;
					fRunEnemys = true;
					step = 12;
				}
			}
			break;
		case 12:
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (enemys[0]->isHitPoint({ 288, 330 })) { //狼がリンゴの下にくる
				fRunFriends = false;
				fRunEnemys = false;
				step = 5;
			}
			break;
		case 5:
			if (gimics[2]->isHitPoint(Input.getMousePoint() - screen) || friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				Input.setMouseIgnoreClick();
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				if (!gimics[10]->getExist()) {	//リンゴをクリックして狼に落とす
					fRunFriends = true;
					fRunEnemys = true;
					step = 13;
				}
			}
			break;
		case 13:
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (!gimics[8]->getExist()) {	//木を取る
				fRunFriends = false;
				fRunEnemys = false;
				step = 6;
			}
			break;
		case 6:
			if (gimics[2]->isHitPoint(Input.getMousePoint() - screen) || friends[0]->isHitPoint(Input.getMousePoint() - screen)) {
				Input.setMouseIgnoreClick();
			}
			else if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				if (Input.getMousePressLeftOnce()) {	//クリックして再開
					fRunFriends = true;
					fRunEnemys = true;
					step = 14;
				}
			}
			break;
		case 14:
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 700,330 })) {//豚が家につく
				fRunFriends = false;
				fRunEnemys = false;
				step = 7;
			}
			break;
		case 7:
			if (Input.getMousePressLeftOnce()) {
				step = 20;
			}
			break;
		default:
			return false;
		}
	}

	return true;
}

Tutorial::Tutorial()
{
}


Tutorial::~Tutorial()
{
}


void Tutorial::Initialize(int _stage) {
	stage = _stage;
	step = 0;
	fRunFriends = false;
	fRunEnemys = false;
	fRungimics = false;
	MousePoint = Input.getMousePoint();
}
bool Tutorial::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	MousePoint = Input.getMousePoint();
	if (!checkStep(enemys, friends, gimics, screen, score)) return false;
	
	return true;
}
void Tutorial::Finalize() {

}

int Tutorial::getStep() const
{
	return step;
}


bool Tutorial::isRunEnemy() const { return fRunEnemys; }
bool Tutorial::isRunFriend() const { return fRunFriends; }
bool Tutorial::isRungimic() const { return fRungimics; }