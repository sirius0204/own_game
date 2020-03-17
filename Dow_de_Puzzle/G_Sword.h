#pragma once
#include "Gimic.h"
#include "F_Momotaro.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	刀																									//
//		number = 15, input = 6（自分で書く（下のinitInfoSizeと同じ数にする））							//
//	機能																								//
//		桃太郎が触れると刀所持状態に　刀所持状態で障害物に触れると破壊									//
//	初期値(input)																						//
//		x, y, height, width, id	,state										//
//	初期値説明																							//																									//	
//		state :																							//
//------------------------------------------------------------------------------------------------------//

class G_Sword :
	public Gimic
{
	int sounFile[1];

public:
	G_Sword(const std::vector<double>& info);
	~G_Sword();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 6;
};

