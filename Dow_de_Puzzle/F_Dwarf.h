#pragma once
#include "Friend.h"

//------------------------------------------//
//	���l							//
//		number = 2;							//
//  �������								//
//		state	:	0->�z�Ζ�����	1->�z�Ώ��� //
//------------------------------------------//

class F_Dwarf :
	public Friend
{
public:
	F_Dwarf(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Dwarf();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	enum eDwarfState {
		Dwarf=0,
		Size
	};
};

