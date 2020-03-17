#pragma once
#include "Gimic.h"
#include "F_Aka.h"

//------------------------------------------------------------------------------------------------------//
//	点火用方向転換床																							//
//		number = 20, input = 7（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		ワープ							//
//	初期値(input)																						//
//		x, y, height, width, stoveNum, id, state//
//	初期値説明																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class G_IgnitionFloor :
	public Gimic
{
	int stoveNum, akaflag, akacnt;

	int soundFile[1];
public:
	G_IgnitionFloor(const std::vector<double>& info);
	~G_IgnitionFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 7;
};

