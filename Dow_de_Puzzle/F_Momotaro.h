#pragma once
#include "Friend.h"

//----------------------------------------------------------------------------------//
//	桃太郎																			//
//		number = 3;																    //
//	初期値説明																	    //
//		state	: 0桁目 0->	off梯子 1-> on梯子																			//
//				　1桁目 0-> release梯子 1-> catch梯子										//
//				  2桁目 0-> 梯子を上っている 1-> 梯子を下りている　　　　　　		//
//				  3桁目 0-> 梯子に右から接近 1-> 梯子に左から接近
//				  4桁目 桃太郎かどうか									//
//				  5桁目 0-> 刀なし 1-> 刀所持											//
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

