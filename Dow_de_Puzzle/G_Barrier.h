#pragma once
#include "Gimic.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	障害物																								//
//		number = 16, input = 8（自分で書く（下のinitInfoSizeと同じ数にする））							//
//	機能																								//
//		桃太郎が刀所持状態で触れると破壊																//
//	初期値(input)																						//
//		x, y, height, width,movefloorNum0, moveFloorNum1, id, state											//
//	初期値説明																							//																									//	
//		state :																							//
//------------------------------------------------------------------------------------------------------//
class G_Barrier :
	public Gimic
{
	int moveFloorNum[2];

	int sounFile[1];
public:
	G_Barrier(const std::vector<double>& info);
	~G_Barrier();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 8;
};

