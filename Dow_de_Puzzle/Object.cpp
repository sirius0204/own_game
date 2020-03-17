#include "Object.h"


Object::Object()
{
	isExist = false;
	cnt = 0;
}

Object::Object(const Vector2 &point) :point(point)
{
	isExist = false;
	cnt = 0;
}

Object::~Object()
{
}


bool Object::getExist() const{
	return isExist;
}
void Object::setExist(bool existFlag){
	isExist = existFlag;
}

const Vector2& Object::getPoint() const{
	return point;
}

void Object::setPoint(const Vector2& _point){
	point = _point;
}


void Object::addCount(){
	++cnt;
}
void Object::addCount(int add) {
	cnt += add;
}
void Object::setCount(int cnt_){
	cnt = cnt_;
}
int Object::getCount() const{
	return cnt;
}


ObjBox::ObjBox()
{
}


ObjBox::ObjBox(const Vector2 &point, double height, double width) : Object(point), height(height), width(width)
{
}


ObjBox::~ObjBox()
{
}


bool ObjBox::isHitPoint(const Vector2 &vec) const{
	if (point.x <= vec.x &&vec.x < point.x + width && point.y <= vec.y && vec.y < point.y + height) {
		return true;
	}
	return false;
}
bool ObjBox::isHitBox(const ObjBox& box) const {
	return isHitPoint(box.getPoint()) || isHitPoint(box.getPoint() + Vector2(box.getWidth(), 0))
		|| isHitPoint(box.getPoint() + Vector2(0, box.getHeight())) || isHitPoint(box.getPoint() + Vector2(box.getWidth(), box.getHeight()))
		|| (box.getPoint().x <= point.x && point.x + width <= box.getPoint().x + box.getWidth() && box.getPoint().y <= point.y + height && point.y <= box.getPoint().y + box.getHeight())
		|| (box.getPoint().y <= point.y && point.y + height <= box.getPoint().y + box.getHeight() && box.getPoint().x <= point.x + width && point.x <= box.getPoint().x + box.getWidth());
}


double ObjBox::getHeight() const{
	return height;
}
double ObjBox::getWidth() const{
	return width;
}

void ObjBox::setHeight(double _height) {
	height = _height;
}
void ObjBox::setWidth(double _width) {
	width = _width;
}

ObjCircle::ObjCircle()
{
	
}


ObjCircle::ObjCircle(const Vector2 &point, double r) :Object(point), r(r)
{
}


ObjCircle::~ObjCircle()
{
}


bool ObjCircle::isHitPoint(const Vector2 &vec) const {
	return point.getDist2(vec) <= r*r;
}

bool ObjCircle::isHitCirle(const ObjCircle & circle) const {
	return point.getDist2(circle.getPoint()) <= (r + circle.getR())*(r + circle.getR());
}


double ObjCircle::getR() const {
	return r;
}

void ObjCircle::setR(double _r)
{
	r = _r;
}

ObjTriangle::ObjTriangle()
{
}


ObjTriangle::ObjTriangle(const std::array<Vector2, 3> &points)
	:points(points), Object((points[0] + points[1] + points[2]) / Vector2(3, 3))
{
}


ObjTriangle::~ObjTriangle()
{
}


bool ObjTriangle::isHitPoint(const Vector2 &vec) {
	for (int i = 0; i < 2; i++) {
		if (points[i].det(vec) * points[i + 1].det(vec) < 0) {
			return false;
		}
	}
	return true;
}
std::array<Vector2, 3> ObjTriangle::getPoints() {
	return points;
}