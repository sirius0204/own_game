#include "F_Momotaro.h"



F_Momotaro::F_Momotaro(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)
{
	Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}


F_Momotaro::~F_Momotaro()
{
}

void F_Momotaro::Initialize(int _id, int _hp, int _dir, int _state, const Vector2 & pos, double _h, double _w){
	Character::Initialize(_id, _hp, _dir, _state, pos, _h, _w);
}

void F_Momotaro::Update(const Map & map){
	Character::Update(map);
}

void F_Momotaro::Finalize(){
}