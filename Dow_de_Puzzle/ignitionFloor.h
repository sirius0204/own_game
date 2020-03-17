#pragma once
#include "Gimic.h"
#include "F_Aka.h"

//------------------------------------------------------------------------------------------------------//
//	点火用方向転換床																							//
//		number = 6, input = 7（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		ワープ							//
//	初期値(input)																						//
//		x, y, height, width, stoveNum, state, id		//
//	初期値説明																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class ignitionFloor :
	public Gimic
{
	int stoveNum;
public:
	ignitionFloor(const std::vector<double>& info);
	~ignitionFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 7;
};

