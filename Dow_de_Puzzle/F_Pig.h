#pragma once
#include "Friend.h"

//------------------------------------------//
//	��							//
//		number = 1;							//
//------------------------------------------//


//state�͍ޗ��̏�������10bit���ɋ�؂��ĕ\���B
//count�����̎��̓J�u���[�h��\���B

class F_Pig :
	public Friend
{
public:
	F_Pig(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Pig();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

};
