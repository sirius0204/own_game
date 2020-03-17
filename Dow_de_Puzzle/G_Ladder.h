#pragma once
#include "Gimic.h"
#include "F_Momotaro.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	梯子																								//
//		number = 2, input = 6（自分で書く（下のinitInfoSizeと同じ数にする））							//
//	機能																								//
//		クリックすると梯子が登れるor登れなくなる														//
//		friendが通過すると上り下りする																	//
//	初期値(input)																						//
//		x, y, height, width,id,state																	//													
//	初期値説明																							//
//		state :1桁目　0->通行不可 1->通行可															    //
//			   2桁目　梯子通過中かどうか																//
//			　　　　　　																				//
//------------------------------------------------------------------------------------------------------//

class G_Ladder :
	public Gimic
{
protected:

public:
	G_Ladder(const std::vector<double>& info);
	~G_Ladder();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	double getLadderCenter_x();
	//Vector2 makeVelocity();
	bool isReachDown(Friend *fre);
	bool isReachUp(Friend *fre);
	bool isProcess(std::vector<Friend*> friends);

	enum eLadderState{
		isAccess = 0,
		isLadderUp,
		Size
	};

	static const int initInfoSize = 6;
};

