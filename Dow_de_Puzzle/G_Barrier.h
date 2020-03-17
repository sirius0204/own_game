#pragma once
#include "Gimic.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	��Q��																								//
//		number = 16, input = 8�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j							//
//	�@�\																								//
//		�����Y����������ԂŐG���Ɣj��																//
//	�����l(input)																						//
//		x, y, height, width,movefloorNum0, moveFloorNum1, id, state											//
//	�����l����																							//																									//	
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

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 8;
};

