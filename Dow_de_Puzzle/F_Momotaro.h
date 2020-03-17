#pragma once
#include "Friend.h"

//----------------------------------------------------------------------------------//
//	�����Y																			//
//		number = 3;																    //
//	�����l����																	    //
//		state	: 0���� 0->	off��q 1-> on��q																			//
//				�@1���� 0-> release��q 1-> catch��q										//
//				  2���� 0-> ��q������Ă��� 1-> ��q������Ă���@�@�@�@�@�@		//
//				  3���� 0-> ��q�ɉE����ڋ� 1-> ��q�ɍ�����ڋ�
//				  4���� �����Y���ǂ���									//
//				  5���� 0-> ���Ȃ� 1-> ������											//
//																					//
//----------------------------------------------------------------------------------//

class F_Momotaro :
	public Friend
{
public:
	F_Momotaro(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Momotaro();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	//enum eFriendState{
	//	one=0,
	//	two,
	//	three
	//};
};

