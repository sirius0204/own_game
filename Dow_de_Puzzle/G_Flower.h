#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	��																							//
//		number = 2, input = 7�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		�Ԃ����񂪐G���ƁA���C���Ɗ��������o��																	//
//	�����l(input)																						//
//		x, y, height, width, wineNum, id, atate			//
//	�����l����																							//
//		wineNum : �͂Ȃɂӂꂽ��A�o�����郏�C���̃M�~�b�N�z��ł̔ԍ�														//	
//			//
//------------------------------------------------------------------------------------------------------//




class G_Flower :
	public Gimic
{
	int soundFile[1];
	int wineNum;
public:
	G_Flower(const std::vector<double>& info);
	~G_Flower();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 7;
};

