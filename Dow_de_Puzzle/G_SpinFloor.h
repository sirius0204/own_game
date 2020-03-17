#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	��]���鏰																							//
//		number = 0, input = 10																			//
//	�@�\																								//
//		�N���b�N�ŉ�]�i�X�O�x�|���j																	//
//	�����l(input)																						//
//		x, y, h, w,  moveFloorNum0, moveFloorNum1, moveFloorNum2, moveFloorNum3, id, ����state				//
//	�����l����																							//
//		�{�^���̈ʒu	: true-> ���@false-> �E															//	
//		state			: 0-> ���s�@	1-> ����	3->�ړ���(0->1)�i�S�T�x�j4->�ړ����i1->0�j(�S�T�x)	//
//------------------------------------------------------------------------------------------------------//

class G_SpinFloor :
	public Gimic
{
	
	int moveFloorNum[4];
	int soundFile[2];
public:
	G_SpinFloor(const std::vector<double>& _infos);
	~G_SpinFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();
	
	
	static const int initInfoSize = 10;
};

