#include "Tutorial.h"



bool Tutorial::checkStep(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{
	if (stage == 0) {
		switch (step)
		{
		case 0://�`���[�g���A���J�n
			if (Input.getMousePressLeftOnce()) {
				step = 1;
			}
			break;
		case 1://�Ԃ�����ړ��J�n
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
		case 2://�Ԃ����񂪂��̂��̑O�ɗ�����
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
		case 3://�L�m�R���N���b�N������
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 336,140 })) {
				fRunFriends = false;
				step = 4;
			}
			break;
		case 4://�Ԃ����񂪃I�I�J�~�̑O�ɗ�����
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
		case 5://�Ԃ�������N���b�N������
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 230,140 })) {
				fRunFriends = false;
				step = 6;
			}
			break;
		case 6://�Ԃ����񂪃L�m�R�̏�ɗ�����
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
		case 7://�L�m�R���N���b�N���ꂽ��
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 130,380 })) {
				fRunFriends = false;
				step = 10;
			}
			break;
		case 8://�Ԃ����񂪃L�m�R����~�肽��
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
		case 9://�Ԃ����񂪕����]��������
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (gimics[7]->getState() == 1) {
				fRunEnemys = true;
				step = 10;
			}
			break;
		case 10://�Ԃ����񂪒g�F�ɓ_�΂�����
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
		case 12://�I�I�J�~�����̏�ɗ�����
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
		case 13://�����N���b�N���ꂽ��
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682
				) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (!enemys[0]->getExist()) {
				step = 14;
			}
			break;
		case 14://�I�I�J�~�Ă��I����
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
		case 0://�`���[�g���A���J�n
			if (Input.getMousePressLeftOnce()) {
				step = 16;
			}
			break;
		case 16://�����Y�ړ��J�n
			fRunFriends = true;
			fRunEnemys = false;
			fRungimics = false;
			if (friends[0]->isHitPoint({ 320, 528 })) {
				fRunFriends = false;
				fRunEnemys = false;
				step = 1;
			}
			break;
		case 1://�����Y����q�̑O�ɗ�����
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
		case 2://��q���N���b�N���ꂽ��
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 570, 340 })) {
				fRunFriends = false;
				step = 3;
			}
			break;
		case 3://�����Y���S�̋߂��ɗ�����
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
		case 4://�����Y��������ς�����
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 390, 340 })) {
				fRunFriends = false;
				step = 5;
			}
			break;
		case 5://��q�̑O�ɗ�����
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
		case 6://��q���N���b�N������
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
		case 7://���𒇊Ԃɂ�����
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
		case 8://�N���b�N����ē����o������
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 146,340 })) {
				fRunFriends = false;
				step = 9;
			}
			break;
		case 9://��Q���ɓ���������
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				fRunFriends = true;
				step = 10;
			}
			break;
		case 10://�N���b�N����ē����o������
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 490,340 })) {
				fRunFriends = false;
				step = 11;
			}
			break;
		case 11://�����Y�����̏�ɗ�����
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
		case 12://�����N���b�N���ꂽ��
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->getId() == 9) {
				fRunFriends = false;
				step = 13;
			}
			break;
		case 13://�����Ƃ�����
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (Input.getMousePressLeftOnce()) {
				fRunFriends = true;
				step = 14;
			}
			break;
		case 14://�N���b�N����ē����o������
			if (gimics[8]->isHitPoint(MousePoint) || gimics[5]->isHitPoint(MousePoint) || friends[0]->isHitPoint(MousePoint)) {
				Input.setMouseIgnoreClick();
			}
			if (friends[0]->isHitPoint({ 750,528 })) {
				fRunFriends = false;
				step = 15;
			}
			break;
		case 15://�D�ɂ�����
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
		case 0://�`���[�g���A���J�n
			if (Input.getMousePressLeftOnce()) {
				step = 8;
			}
			break;
		case 8: //�؈ړ��J�n
			fRunFriends = true;
			fRungimics = true;
			if (MousePoint.x >= 810 && MousePoint.x <= 938 && MousePoint.y >= 650 && MousePoint.y <= 682) {}
			else {
				Input.setMouseIgnoreClick();
			}
			if (!gimics[6]->getExist()) { //�����K���Ƃ�
				fRunFriends = false;
				step = 1;
			}
			break;
		case 1: //�N���b�N���čĊJ
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
			if (!gimics[7]->getExist()) { //���������
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
				if (Input.getMousePressLeftOnce()) { //�N���b�N���čĊJ
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
			if (friends[0]->isHitPoint({ 502,190 })) { //�؂����̏�ɂ���
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
				if (gimics[2]->getId() == 58) { //�����N���b�N���ē؂𗎂Ƃ�
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
			if (friends[0]->isHitPoint({ 230,330 })) {//�؂��I�I�J�~�ɂ����肻���ɂȂ�����
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
				if (friends[0]->isHitPoint(Input.getMousePoint() - screen) && Input.getMousePressLeftOnce()) {//�؂������]��������
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
			if (enemys[0]->isHitPoint({ 288, 330 })) { //�T�������S�̉��ɂ���
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
				if (!gimics[10]->getExist()) {	//�����S���N���b�N���ĘT�ɗ��Ƃ�
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
			if (!gimics[8]->getExist()) {	//�؂����
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
				if (Input.getMousePressLeftOnce()) {	//�N���b�N���čĊJ
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
			if (friends[0]->isHitPoint({ 700,330 })) {//�؂��Ƃɂ�
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