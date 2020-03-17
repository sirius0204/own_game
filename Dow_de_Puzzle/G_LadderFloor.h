#pragma once
#include "Gimic.h"
#include "G_Ladder.h"
#include "F_Momotaro.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	梯子																								//
//		number = 25, input = 6（自分で書く（下のinitInfoSizeと同じ数にする））							//
//	機能																								//
//																//
//		梯子上でのfriend,enemyの位置補正																//
//	初期値(input)																						//
//		x, y, height, width,id,state																	//													
//	初期値説明																							//
//		state :1桁目　0->通行不可 1->通行可		
//             2桁目　梯子通過中かどうか
//			　　　　　　																				//
//------------------------------------------------------------------------------------------------------//


class G_LadderFloor :
	public Gimic
{
public:
	G_LadderFloor(const std::vector<double>& info);
	~G_LadderFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	bool isReachUp(Friend *fre);
	bool isProcess(std::vector<Friend*> friends);

	static const int initInfoSize = 6;

};

