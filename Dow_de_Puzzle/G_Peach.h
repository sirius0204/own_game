#pragma once
#include "Gimic.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	��																									//
//		number = 14, input = 6																			//
//	�@�\																								//
//		�����Y����������ԂŎ��ƃX�R�A�A�b�v															//
//	�����l(input)																						//
//		x, y, h, w, id, state																					//
//	�����l����																							//
//																										//	
//																										//
//------------------------------------------------------------------------------------------------------//

class G_Peach :
	public Gimic
{
	int sounFile[1];
public:
	G_Peach(const std::vector<double>& info);
	~G_Peach();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 6;
};
