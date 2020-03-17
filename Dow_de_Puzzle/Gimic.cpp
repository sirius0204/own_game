#include "Gimic.h"



Gimic::Gimic()
{
}


Gimic::~Gimic()
{
}

int Gimic::getId() const
{
	return id;
}

int Gimic::getState() const
{
	return state;
}

void Gimic::setState(int _state) {
	state = _state;
}
void Gimic::setId(int _id) {
	id = _id;
}
