#pragma once
#include "Character.h"

class Friend :
	public Character
{
public:
	Friend();
	~Friend();

	virtual void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w)=0;
	virtual void Update(const Map& map)=0;
	virtual void Finalize()=0;
	static const int Friendnum_St2 = 2;

	enum eFriendState_St2 {
		On_Off = 0,
		Rel_Cat,
		Down_Up,
		Right_Left,
		IsMomo,
		IsSword,
		HaveAnimalNum1,
		HaveAnimalNum2,
		Size
	};

};

