#pragma once
#include "Gimic.h"
#include "F_Aka.h"

//------------------------------------------------------------------------------------------------------//
//	�_�Ηp�����]����																							//
//		number = 20, input = 7�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		���[�v							//
//	�����l(input)																						//
//		x, y, height, width, stoveNum, id, state//
//	�����l����																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class G_IgnitionFloor :
	public Gimic
{
	int stoveNum, akaflag, akacnt;

	int soundFile[1];
public:
	G_IgnitionFloor(const std::vector<double>& info);
	~G_IgnitionFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 7;
};

