#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	ガラスの靴																						//
//		number = 17, input = 6							//
//	機能																								//
//		シンデレラが忘れていくもの																	//
//	初期値(input)																						//
//		x, y, height, width, id, state			//
//	初期値説明																							//
//		特になし														//	
//			//
//------------------------------------------------------------------------------------------------------//

class G_Shose :
	public Gimic
{

public:
	G_Shose(const std::vector<double>& _infos);
	~G_Shose();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 10;
};