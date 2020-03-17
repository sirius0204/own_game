#pragma once
#include "Gimic.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	桃																									//
//		number = 14, input = 6																			//
//	機能																								//
//		桃太郎が刀所持状態で取るとスコアアップ															//
//	初期値(input)																						//
//		x, y, h, w, id, state																					//
//	初期値説明																							//
//																										//	
//																										//
//------------------------------------------------------------------------------------------------------//

class G_Peach :
	public Gimic
{
	int sounFile[1];
public:
	G_Peach(const std::vector<double>& info);
	~G_Peach();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 6;
};
