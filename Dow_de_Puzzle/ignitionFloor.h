#pragma once
#include "Gimic.h"
#include "F_Aka.h"

//------------------------------------------------------------------------------------------------------//
//	�_�Ηp�����]����																							//
//		number = 6, input = 7�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		���[�v							//
//	�����l(input)																						//
//		x, y, height, width, stoveNum, state, id		//
//	�����l����																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class ignitionFloor :
	public Gimic
{
	int stoveNum;
public:
	ignitionFloor(const std::vector<double>& info);
	~ignitionFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 7;
};

