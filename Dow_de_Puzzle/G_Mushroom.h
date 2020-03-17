#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	�L�m�R																							//
//		number = 3, input = 12�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		�N���b�N�ŏ㏸���鑫��																	//
//	�����l(input)																						//
//		x, y, minHeight, maxHeight, width, addH, movefloor0, movefloor1, movefloor2, movefloor3, id, state			//
//	�����l����																							//
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

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 12;
};

