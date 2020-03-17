#pragma once

#include "DxLib.h"
#include "enum.h"
#include <cmath>
#include <stack>
#include <vector>


//�Q�����x�N�g���\����
struct Vector2
{
	double x, y;
	Vector2() :x(0.0), y(0.0) {};
	Vector2(double x, double y) :x(x), y(y) {};


	void setVector2(double x_, double y_) {
		x = x_; y = y_;
	}

	//�����̓��
	double getDist2(const Vector2 &vec) const {
		return (x - vec.x)*(x - vec.x) + (y - vec.y)*(y - vec.y);
	}
	//����
	double getDist(const Vector2 &vec) const {
		return sqrt(getDist2(vec));
	}
	//�p�x�i���W�A���j
	double getAngle(const Vector2 &vec) const {
		return atan2(y - vec.y, x - vec.x);
	}
	//�I�y���[�^�[
	bool operator <(const Vector2 &vec) const {
		return x < vec.x&&y < vec.y;
	}
	bool operator >(const Vector2 &vec) const {
		return x > vec.x &&y > vec.y;
	}
	bool operator <=(const Vector2 &vec) const {
		return x <= vec.x&&y <= vec.y;
	}
	bool operator ==(const Vector2 &vec) const {
		return x == vec.x &&y == vec.y;
	}
	Vector2& operator +=(const Vector2 &vec) {
		x += vec.x;
		y += vec.y;
		return *this;
	}
	Vector2& operator *=(const Vector2 &vec) {
		x *= vec.x;
		y *= vec.y;
		return *this;
	}
	Vector2& operator *=(const double d) {
		x *= d;
		y *= d;
		return *this;
	}
	Vector2& operator /=(const Vector2 &vec) {
		x /= vec.x;
		y /= vec.y;
		return *this;
	}
	Vector2& operator /=(const double d) {
		x /= d;
		y /= d;
		return *this;
	}
	const Vector2 operator +(const Vector2 &vec) const {
		return Vector2(x + vec.x, y + vec.y);
	}
	const Vector2 operator -(const Vector2 &vec) const {
		return Vector2(x - vec.x, y - vec.y);
	}
	const Vector2 operator *(const Vector2 &vec) const {
		return Vector2(x * vec.x, y * vec.y);
	}
	const Vector2 operator *(const double d) const {
		return Vector2(x * d, y * d);
	}
	const Vector2 operator /(const Vector2 &vec) const {
		return Vector2(x / vec.x, y / vec.y);
	}


	//�O��
	double det(const Vector2 &vec) const {
		return x*vec.y - y*vec.x;
	}
	//����
	double dot(const Vector2 &vec) const {
		return x*vec.x + y*vec.y;
	}
};



