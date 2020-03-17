#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	�J�u																						//
//		number = 10, input = 6							//
//	�@�\																								//
//		�u�^�̑��x�A�b�v																	//
//	�����l(input)																						//
//		x, y, height, width, id, state			//
//	�����l����																							//
//		���ɂȂ�														//	
//			//
//------------------------------------------------------------------------------------------------------//


class G_Kabu : public Gimic
{
	int kabucnt;
	int kabuflag;
	int soundFile[1];
public:
	G_Kabu(const std::vector<double>& info);
	~G_Kabu();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 6;
};

