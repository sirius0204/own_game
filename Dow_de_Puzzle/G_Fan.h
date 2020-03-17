#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	送風機																							//
//		number = 6, input = 17（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		クリックでオン・オフが切り替わる							//
//	初期値(input)																						//
//		x, y, height, width, clickRangeX, clickRangeY, clickRangeH, clickRangeW, HitRangeX, HitRangeY, HitRangeH, HitRangeW, dir, slowRate, fastRate, id, state		//
//	初期値説明																							//
//		state : 0->OFF  1->ON														//	
//		
//------------------------------------------------------------------------------------------------------//

class G_Fan :
	public Gimic
{
	ObjBox clickRange, hitRange;
	double slowRate, fastRate;
	int dir;

	int soundFile[1];
public:
	G_Fan(const std::vector<double>& info);
	~G_Fan();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 17;
};

