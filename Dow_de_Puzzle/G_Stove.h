#pragma once
#include "Gimic.h"
#include "F_Aka.h"

//------------------------------------------------------------------------------------------------------//
//	������																							//
//		number = 5, input = 8�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		�Ԃ�����̐ڐG�œ_�΁��E�߁A�_�Ύ��������݂����ƃX�R�A�l�����T����							//
//	�����l(input)																						//
//		x, y, height, width, movefloorNum0, moveFloorNum1, state, id		//
//	�����l����																							//
//																//	
//		state : 0->���� 1->�_�Β�	2->�_��//
//------------------------------------------------------------------------------------------------------//

class G_Stove :
	public Gimic
{
	int moveFloorNum[2];
	int soundFile[2];
	int graphFile[1];
public:
	G_Stove(const std::vector<double>& info);
	~G_Stove();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 8;
};

