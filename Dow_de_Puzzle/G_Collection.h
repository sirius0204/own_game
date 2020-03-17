#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	�ޗ�(�m�A�؍ށA�����K)																						//
//		number = 11, input = 6							//
//	�@�\																								//
//		�Ƃ����ޗ��@�E����																//
//	�����l(input)																						//
//		x, y, height, width, id, state					//
//	�����l����																							//
//		state : 0=�m�@1=�؍ށ@2=�����K														//	
//														//
//------------------------------------------------------------------------------------------------------//


class G_Collection : public Gimic
{

	int soundFile[1];
public:
	G_Collection(const std::vector<double>& info);
	~G_Collection();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 6;
};

