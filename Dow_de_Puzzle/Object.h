#pragma once

#include "struct.h"
#include "DxLib.h"

#include <array>

class Object
{
protected:
	Vector2 point;
	bool isExist;
	int cnt;
public:
	Object();
	Object(const Vector2 &point);
	~Object();

	bool getExist() const;
	void setExist(bool existFlag);

	const Vector2& getPoint() const;
	void setPoint(const Vector2& _point);

	void addCount();
	void addCount(int add);
	void setCount(int cnt_);
	int getCount() const;
};

class ObjBox :
	public Object
{
protected:
	double height, width;
public:
	ObjBox();
	ObjBox(const Vector2 &point, double height, double width);
	~ObjBox();

	bool isHitPoint(const Vector2 &vec) const;
	bool isHitBox(const ObjBox& box) const;
	double getHeight() const;
	double getWidth() const;

	void setHeight(double _height);
	void setWidth(double _width);
};


class ObjCircle :
	public Object
{
protected:
	double r;
public:
	ObjCircle();
	ObjCircle(const Vector2 &point, double r);
	~ObjCircle();

	bool isHitPoint(const Vector2 &vec) const;
	bool isHitCirle(const ObjCircle& circle) const;
	double getR() const;
	void setR(double _r);
};


class ObjTriangle :
	public Object
{
protected:
	std::array<Vector2, 3> points;
public:
	ObjTriangle();
	ObjTriangle(const std::array<Vector2, 3> &points);
	~ObjTriangle();

	bool isHitPoint(const Vector2 &vec);
	std::array<Vector2, 3> getPoints();
};