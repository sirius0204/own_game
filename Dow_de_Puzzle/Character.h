#pragma once
#include "Object.h"
#include "struct.h"
#include "Map.h"
#include "Materials.h"
#include <vector>
#include <cmath>

//�L�����N�^�[�p�N���X
class Character :
	public ObjBox
{
	int id;					//�L�����N�^�[ID
	int hp;					//�L�����N�^�[HP
	Vector2 velocity;		//���x
	Vector2 accelaration;	//�����x
	int dir;				//����			0->���@	1->�E�@	2->��	3-> ��
	int state;

public:
	Character();
	Character(int id, int hp, int dir, int state);
	~Character();

	void Initialize(int _id, int _hp, int _dir, int state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	//�Z�b�^�[
	void setId(int _id);
	void setHp(int _hp);
	void setDir(int _dir);
	void setVelocity(const Vector2& _velocity);
	void setAccelaration(const Vector2& _accelaration);
	void setPoint(const Vector2& pos);
	void setCenterPoint(const Vector2& pos);
	void setMinX(double _x);
	void setMinY(double _y);
	void setMaxX(double _x);
	void setMaxY(double _y);
	void setCenterX(double _x);
	void setCenterY(double _y);
	void setState(int state);

	//�Q�b�^�[
	int getId() const;
	int getHp() const;
	const Vector2& getVelocity() const;
	const Vector2& getAccelaration() const;
	int getDir() const;
	const Vector2 getCenterPoint() const;
	double getMinX() const;
	double getMinY() const;
	double getMaxX() const;
	double getMaxY() const;
	int getState() const;

	void addHp(int add);			//HP�ɑ����Z
	void addVelocity(const Vector2& add);
	//void turnVelocity(double angle);
	void addAccelaration(const Vector2& add);
	void move(const Map& map);		//�L�����N�^�[�̈ړ�
	
	bool isMovableRight(const Map& map, const Vector2& pos) const;		//�����蔻��i�E�j
	bool isMovableLeft(const Map& map, const Vector2& pos) const;		//�����蔻��i���j
	bool isMovableUp(const Map& map, const Vector2& pos) const;			//�����蔻��i��j
	bool isMovableDown(const Map& map, const Vector2& pos) const;		//�����蔻��i���j

	void moveByHittingBox(const ObjBox& box);

	
};

