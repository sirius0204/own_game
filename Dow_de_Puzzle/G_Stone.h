#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	�z��																							//
//		number = 12, input = 6�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		���l�ɐG���Ɖ�������							//
//	�����l(input)																						//
//		x, y, height, width, id, state		//
//	�����l����																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//


class G_Stone :
	public Gimic
{
public:
	G_Stone(const std::vector<double>& info);
	~G_Stone();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 6;
};

