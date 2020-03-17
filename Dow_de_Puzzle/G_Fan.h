#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	�����@																							//
//		number = 6, input = 17�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		�N���b�N�ŃI���E�I�t���؂�ւ��							//
//	�����l(input)																						//
//		x, y, height, width, clickRangeX, clickRangeY, clickRangeH, clickRangeW, HitRangeX, HitRangeY, HitRangeH, HitRangeW, dir, slowRate, fastRate, id, state		//
//	�����l����																							//
//		state : 0->OFF  1->ON														//	
//		
//------------------------------------------------------------------------------------------------------//

class G_Fan :
	public Gimic
{
	ObjBox clickRange, hitRange;
	double slowRate, fastRate;
	int dir;

	int soundFile[1];
public:
	G_Fan(const std::vector<double>& info);
	~G_Fan();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 17;
};

