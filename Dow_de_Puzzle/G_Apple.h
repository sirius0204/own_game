#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	�����S																						//
//		number = 9, input = 6							//
//	�@�\																								//
//		�T(�u�^)�̓���ɗ��Ƃ��ċC��																//
//	�����l(input)																						//
//		x, y, height, width, id, state			//
//	�����l����																							//
//		state : 0=�����Ă� 1=�����Ă� 2=������														//	
//			//
//------------------------------------------------------------------------------------------------------//


class G_Apple : public Gimic
{
	int soundFile[1];
public:
	G_Apple(const std::vector<double>& info);
	~G_Apple();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 6;
};

