#pragma once

#include "DxLib.h"
#include "enum.h"
#include <cmath>
#include <stack>
#include <vector>


//２次元ベクトル構造体
struct Vector2
{
	double x, y;
	Vector2() :x(0.0), y(0.0) {};
	Vector2(double x, double y) :x(x), y(y) {};


	void setVector2(double x_, double y_) {
		x = x_; y = y_;
	}

	//距離の二乗
	double getDist2(const Vector2 &vec) const {
		return (x - vec.x)*(x - vec.x) + (y - vec.y)*(y - vec.y);
	}
	//距離
	double getDist(const Vector2 &vec) const {
		return sqrt(getDist2(vec));
	}
	//角度（ラジアン）
	double getAngle(const Vector2 &vec) const {
		return atan2(y - vec.y, x - vec.x);
	}
	//オペレーター
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


	//外積
	double det(const Vector2 &vec) const {
		return x*vec.y - y*vec.x;
	}
	//内積
	double dot(const Vector2 &vec) const {
		return x*vec.x + y*vec.y;
	}
};



