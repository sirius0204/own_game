#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	������																							//
//		number = 4, input = 11�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		��ɍڂ����L�����N�^�[�̕����������]���i�N���b�N�Ō������ς��j																	//
//	�����l(input)																						//
//		x, y, height, width, rangeX, rangeY, rangeH, rangeW, ����exist, id, state			//
//	�����l����																							//
//																//	
//			//
//------------------------------------------------------------------------------------------------------//

class G_MoveFloor :
	public Gimic
{
	ObjBox range;

	int soundFile[1];
public:
	G_MoveFloor(const std::vector<double>& info);
	~G_MoveFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 11;
};

