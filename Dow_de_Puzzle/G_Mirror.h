#pragma once
#include "Gimic.h"
#include "Character.h"

//------------------------------------------------------------------------------------------------------//
//	鏡																							//
//		number = 13, input = 7（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		ワープ							//
//	初期値(input)																						//
//		x, y, height, width, pairMirrorNum, id, state		//
//	初期値説明																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class G_Mirror :
	public Gimic
{
	int pairMirrorNum;
public:
	G_Mirror(const std::vector<double>& info);
	~G_Mirror();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 7;
};

