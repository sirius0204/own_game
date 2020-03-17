#pragma once
#include "Gimic.h"
#include "F_Momotaro.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	��																									//
//		number = 15, input = 6�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j							//
//	�@�\																								//
//		�����Y���G���Ɠ�������ԂɁ@��������Ԃŏ�Q���ɐG���Ɣj��									//
//	�����l(input)																						//
//		x, y, height, width, id	,state										//
//	�����l����																							//																									//	
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

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 6;
};

