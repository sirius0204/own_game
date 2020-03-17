#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	���C���Ɠ�																							//
//		number = 1, input = 10�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		�T�������t����i�����������]���j																	//
//	�����l(input)																						//
//		x, y, height, width, rangeX, rangeY, rangeH, rangeW	, id, state		//
//	�����l����																							//
//		Range : �����蔻��p�̃{�b�N�X														//	
//			//
//------------------------------------------------------------------------------------------------------//


class G_WineMeat :
	public Gimic
{
	ObjBox range;
public:
	G_WineMeat(const std::vector<double>& info);
	~G_WineMeat();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 10;
};

