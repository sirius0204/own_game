#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	ワインと肉																							//
//		number = 1, input = 10（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		狼を引き付ける（向きを強制転換）																	//
//	初期値(input)																						//
//		x, y, height, width, rangeX, rangeY, rangeH, rangeW	, id, state		//
//	初期値説明																							//
//		Range : あたり判定用のボックス														//	
//			//
//------------------------------------------------------------------------------------------------------//


class G_WineMeat :
	public Gimic
{
	ObjBox range;
public:
	G_WineMeat(const std::vector<double>& info);
	~G_WineMeat();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 10;
};

