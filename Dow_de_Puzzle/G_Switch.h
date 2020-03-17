#pragma once
#include "Gimic.h"
#include <set>

//------------------------------------------------------------------------------------------------------//
//	ドア用スイッチ																						//
//		number = 5, input = 7（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//									//
//	初期値(input)																						//
//		x, y, height, width, doorNum, state, id		//
//	初期値説明																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class G_DoorSwitch :
	public Gimic
{
	int doorNum;
	std::set<int> st;
public:
	G_DoorSwitch(const std::vector<double>& info);
	~G_DoorSwitch();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 7;
};

