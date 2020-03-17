#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	焼却炉																								//
//		number = 5, input = 6																			//
//	機能																								//
//		赤ずきんの接触で点火＆脱衣、点火時おおかみが乗るとスコア獲得＆狼消滅							//
//	初期値(input)																						//
//		x, y, h, w, id, state																			//
//	初期値説明																							//
//		state			: 0-> 消火状態	1-> 点火状態														//	
//																										//
//------------------------------------------------------------------------------------------------------//

class G_Incinerator :
	public Gimic
{
public:
	G_Incinerator(const std::vector<double>& info);
	~G_Incinerator();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends,std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 6;
};

