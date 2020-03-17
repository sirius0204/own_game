#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	鉱石																							//
//		number = 12, input = 6（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		小人に触れると回収される							//
//	初期値(input)																						//
//		x, y, height, width, id, state		//
//	初期値説明																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//


class G_Stone :
	public Gimic
{
public:
	G_Stone(const std::vector<double>& info);
	~G_Stone();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 6;
};

