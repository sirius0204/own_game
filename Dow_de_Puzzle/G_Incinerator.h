#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	�ċp�F																								//
//		number = 5, input = 6																			//
//	�@�\																								//
//		�Ԃ�����̐ڐG�œ_�΁��E�߁A�_�Ύ��������݂����ƃX�R�A�l�����T����							//
//	�����l(input)																						//
//		x, y, h, w, id, state																			//
//	�����l����																							//
//		state			: 0-> ���Ώ��	1-> �_�Ώ��														//	
//																										//
//------------------------------------------------------------------------------------------------------//

class G_Incinerator :
	public Gimic
{
public:
	G_Incinerator(const std::vector<double>& info);
	~G_Incinerator();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends,std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 6;
};

