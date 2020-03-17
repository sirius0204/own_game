#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	リンゴ																						//
//		number = 9, input = 6							//
//	機能																								//
//		狼(ブタ)の頭上に落として気絶																//
//	初期値(input)																						//
//		x, y, height, width, id, state			//
//	初期値説明																							//
//		state : 0=実ってる 1=落ちてる 2=落ちた														//	
//			//
//------------------------------------------------------------------------------------------------------//


class G_Apple : public Gimic
{
	int soundFile[1];
public:
	G_Apple(const std::vector<double>& info);
	~G_Apple();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 6;
};

