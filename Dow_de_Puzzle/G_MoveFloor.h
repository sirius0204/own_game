#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	動く床																							//
//		number = 4, input = 11（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		上に載ったキャラクターの方向を強制転換（クリックで向きが変わる）																	//
//	初期値(input)																						//
//		x, y, height, width, rangeX, rangeY, rangeH, rangeW, 初期exist, id, state			//
//	初期値説明																							//
//																//	
//			//
//------------------------------------------------------------------------------------------------------//

class G_MoveFloor :
	public Gimic
{
	ObjBox range;

	int soundFile[1];
public:
	G_MoveFloor(const std::vector<double>& info);
	~G_MoveFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 11;
};

