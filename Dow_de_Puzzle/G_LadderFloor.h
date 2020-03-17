#pragma once
#include "Gimic.h"
#include "G_Ladder.h"
#include "F_Momotaro.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	��q																								//
//		number = 25, input = 6�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j							//
//	�@�\																								//
//																//
//		��q��ł�friend,enemy�̈ʒu�␳																//
//	�����l(input)																						//
//		x, y, height, width,id,state																	//													
//	�����l����																							//
//		state :1���ځ@0->�ʍs�s�� 1->�ʍs��		
//             2���ځ@��q�ʉߒ����ǂ���
//			�@�@�@�@�@�@																				//
//------------------------------------------------------------------------------------------------------//


class G_LadderFloor :
	public Gimic
{
public:
	G_LadderFloor(const std::vector<double>& info);
	~G_LadderFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	bool isReachUp(Friend *fre);
	bool isProcess(std::vector<Friend*> friends);

	static const int initInfoSize = 6;

};

