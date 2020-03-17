#include "Character.h"



Character::Character()
{
}

Character::Character(int id, int hp, int dir, int state): id(id), hp(hp), dir(dir), state(state)
{
}


Character::~Character()
{
}


void Character::Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w) {
	id = _id;
	hp = _hp;
	dir = _dir;
	this->setExist(true);
	this->setPoint(pos);
	height = _h;
	width = _w;
	state = _state;
	setAccelaration(Vector2());
}
void Character::Update(const Map& map) {
	addCount();
	move(map);
}
void Character::Finalize() {

}


void Character::setId(int _id) { id = _id; }
void Character::setHp(int _hp) { hp = _hp; }
void Character::setDir(int _dir)
{
	dir = _dir;
}
void Character::setVelocity(const Vector2& _velocity) { velocity = _velocity; }
void Character::setAccelaration(const Vector2& _accelaration) { accelaration = _accelaration; }

void Character::setPoint(const Vector2 & pos)
{
	point = pos;
}

void Character::setMinX(double _x) { point.x = _x; }
void Character::setMinY(double _y) { point.y = _y; }
void Character::setMaxX(double _x) { point.x = _x - width; }
void Character::setMaxY(double _y) { point.y = _y - height; }
void Character::setCenterX(double _x) { point.x = _x - width / 2.0; }
void Character::setCenterY(double _y) { point.y = _y - height / 2.0; }

void Character::setState(int _state)
{
	state = _state;
}

void Character::setCenterPoint(const Vector2 & pos)
{
	point.x = pos.x - width / 2;
	point.y = pos.y - height / 2;
}


int Character::getId() const { return id; }
int Character::getHp() const { return hp; }
const Vector2& Character::getVelocity() const { return velocity; }
const Vector2& Character::getAccelaration() const { return accelaration; }
int Character::getDir() const { return dir; }

const Vector2 Character::getCenterPoint() const
{
	return point + Vector2(width / 2.0, height / 2.0);
}

double Character::getMinX() const { return point.x; }
double Character::getMinY() const { return point.y; }
double Character::getMaxX() const { return point.x + width; }
double Character::getMaxY() const { return point.y + height; }

int Character::getState() const
{
	return state;
}



void Character::addHp(int add) { hp += add; }	//�L�����N�^�[��HP�����Z����

void Character::addVelocity(const Vector2 & add)
{
	velocity += add;
}

//void Character::turnVelocity(double angle){
//	Vector2 v = getVelocity();
//	setVelocity({ v.x*cos(angle) - v.y*sin(angle), v.x*sin(angle) + v.y*cos(angle) });
//}

void Character::addAccelaration(const Vector2 & add)
{
	accelaration += add;
}

void  Character::move(const Map& map) {
	Vector2 newPos = point + velocity;		//�ړ���̈ʒu
	
	if (velocity.y < 0.0) {									//������ւ̈ړ�
		if (newPos.y < 0) newPos.y = 0;		//��[���t�B�[���h�O�Ȃ�␳
		if (!isMovableUp(map, newPos)) {
			newPos.y = (int)(newPos.y / Map::ChipEdge + 1)*Map::ChipEdge;
		}
	}
	else if(velocity.y > 0.0){							//�������ւ̈ړ�
		if (newPos.y > Map::ChipEdge*map.getHeight()-height) newPos.y = Map::ChipEdge*map.getHeight()-height;		//�������t�B�[���h�O�Ȃ�␳
		if (!isMovableDown(map, newPos)) {
			newPos.y = (int)((newPos.y + height) / Map::ChipEdge)*Map::ChipEdge - height;
		}
	}
	if (velocity.x < 0.0) {					//���Ɉړ�����Ȃ�
		if (newPos.x < 0) newPos.x = 0;		//���[���t�B�[���h�O�ɏo�Ă���Ε␳
		if (!isMovableLeft(map, newPos)) {
			newPos.x = (int)(newPos.x / Map::ChipEdge + 1)*Map::ChipEdge;
		}
	}
	else if(velocity.x > 0.0){									//�E���ւ̈ړ�
		if (newPos.x > Map::ChipEdge*map.getWidth()-width) newPos.x = Map::ChipEdge*map.getWidth()-width;		//�E�[���t�B�[���h�O�ɏo�Ă���Ε␳
		if (!isMovableRight(map, newPos)) {
			newPos.x = (int)((newPos.x + width) / Map::ChipEdge)*Map::ChipEdge - width;
		}
	}


	point = newPos;						//�ړ���̍��W����
	velocity *= 0.8;					//��������
	velocity += accelaration;			//�����x�𑫂�
	accelaration *= 0.0;				//�����x������


	if (isMovableDown(map, newPos) && dir < 2) {
		addAccelaration({ 0, 0.5 });
	}
	accelaration.x += 0.30*(dir == 0 ? -1 : (dir == 1 ? 1 : 0));
	accelaration.y += 0.30*(dir == 2 ? -1 : (dir == 3 ? 1 : 0));
}

//�e�����̂����蔻��
bool Character::isMovableRight(const Map& map, const Vector2& pos) const {
	return map.isMovable(pos + Vector2(width, height / 2.0));
}
bool Character::isMovableLeft(const Map& map, const Vector2& pos) const {
	return map.isMovable(pos + Vector2(0.0, height / 2.0));
}
bool Character::isMovableUp(const Map& map, const Vector2& pos) const {
	return map.isMovable(pos + Vector2(width/2.0, 0.0));
}
bool Character::isMovableDown(const Map& map, const Vector2& pos) const {
	return map.isMovable(pos + Vector2(width/2.0, height));
}

void Character::moveByHittingBox(const ObjBox & box)
{
	// TODO : �l�p�̃I�u�W�F�N�g�ɂ������Ă���Ƃ��̏���
}


