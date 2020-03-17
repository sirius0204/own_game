#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	カブ																						//
//		number = 10, input = 6							//
//	機能																								//
//		ブタの速度アップ																	//
//	初期値(input)																						//
//		x, y, height, width, id, state			//
//	初期値説明																							//
//		特になし														//	
//			//
//------------------------------------------------------------------------------------------------------//


class G_Kabu : public Gimic
{
	int kabucnt;
	int kabuflag;
	int soundFile[1];
public:
	G_Kabu(const std::vector<double>& info);
	~G_Kabu();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 6;
};

