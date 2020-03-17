#pragma once
#include "Gimic.h"
#include "F_Aka.h"

//------------------------------------------------------------------------------------------------------//
//	動く床																							//
//		number = 5, input = 8（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		赤ずきんの接触で点火＆脱衣、点火時おおかみが乗るとスコア獲得＆狼消滅							//
//	初期値(input)																						//
//		x, y, height, width, movefloorNum0, moveFloorNum1, state, id		//
//	初期値説明																							//
//																//	
//		state : 0->消化 1->点火中	2->点火//
//------------------------------------------------------------------------------------------------------//

class G_Stove :
	public Gimic
{
	int moveFloorNum[2];
	int soundFile[2];
	int graphFile[1];
public:
	G_Stove(const std::vector<double>& info);
	~G_Stove();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 8;
};

