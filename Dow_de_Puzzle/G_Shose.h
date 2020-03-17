#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	�K���X�̌C																						//
//		number = 17, input = 6							//
//	�@�\																								//
//		�V���f�������Y��Ă�������																	//
//	�����l(input)																						//
//		x, y, height, width, id, state			//
//	�����l����																							//
//		���ɂȂ�														//	
//			//
//------------------------------------------------------------------------------------------------------//

class G_Shose :
	public Gimic
{

public:
	G_Shose(const std::vector<double>& _infos);
	~G_Shose();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 10;
};