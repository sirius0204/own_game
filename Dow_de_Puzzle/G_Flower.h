#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	花																							//
//		number = 2, input = 7（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		赤ずきんが触れると、ワインと干し肉が出現																	//
//	初期値(input)																						//
//		x, y, height, width, wineNum, id, atate			//
//	初期値説明																							//
//		wineNum : はなにふれたら、出現するワインのギミック配列での番号														//	
//			//
//------------------------------------------------------------------------------------------------------//




class G_Flower :
	public Gimic
{
	int soundFile[1];
	int wineNum;
public:
	G_Flower(const std::vector<double>& info);
	~G_Flower();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 7;
};

