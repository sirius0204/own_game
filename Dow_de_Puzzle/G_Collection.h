#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	材料(藁、木材、レンガ)																						//
//		number = 11, input = 6							//
//	機能																								//
//		家を作る材料　拾える																//
//	初期値(input)																						//
//		x, y, height, width, id, state					//
//	初期値説明																							//
//		state : 0=藁　1=木材　2=レンガ														//	
//														//
//------------------------------------------------------------------------------------------------------//


class G_Collection : public Gimic
{

	int soundFile[1];
public:
	G_Collection(const std::vector<double>& info);
	~G_Collection();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 6;
};

