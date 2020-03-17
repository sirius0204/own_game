#pragma once
#include "Object.h"
#include "struct.h"
#include "Map.h"
#include "Materials.h"
#include <vector>
#include <cmath>

//キャラクター用クラス
class Character :
	public ObjBox
{
	int id;					//キャラクターID
	int hp;					//キャラクターHP
	Vector2 velocity;		//速度
	Vector2 accelaration;	//加速度
	int dir;				//向き			0->左　	1->右　	2->上	3-> 下
	int state;

public:
	Character();
	Character(int id, int hp, int dir, int state);
	~Character();

	void Initialize(int _id, int _hp, int _dir, int state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	//セッター
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

	//ゲッター
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

	void addHp(int add);			//HPに足し算
	void addVelocity(const Vector2& add);
	//void turnVelocity(double angle);
	void addAccelaration(const Vector2& add);
	void move(const Map& map);		//キャラクターの移動
	
	bool isMovableRight(const Map& map, const Vector2& pos) const;		//あたり判定（右）
	bool isMovableLeft(const Map& map, const Vector2& pos) const;		//あたり判定（左）
	bool isMovableUp(const Map& map, const Vector2& pos) const;			//あたり判定（上）
	bool isMovableDown(const Map& map, const Vector2& pos) const;		//あたり判定（下）

	void moveByHittingBox(const ObjBox& box);

	
};

