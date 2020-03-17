#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	キノコ																							//
//		number = 3, input = 12（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		クリックで上昇する足場																	//
//	初期値(input)																						//
//		x, y, minHeight, maxHeight, width, addH, movefloor0, movefloor1, movefloor2, movefloor3, id, state			//
//	初期値説明																							//
//																//	
//			//
//------------------------------------------------------------------------------------------------------//

class G_Mushroom :
	public Gimic
{
	double minH, maxH, addH;
	int moveFloorNum[4];
	int mushcnt;
	bool isClickable;

	int soundFile[2];

	bool isUnderCharacter(Character* chr);
public:
	G_Mushroom(const std::vector<double>& info);
	~G_Mushroom();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSizeは自分で決める
	static const int initInfoSize = 12;
};

