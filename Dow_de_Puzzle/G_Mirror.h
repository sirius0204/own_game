#pragma once
#include "Gimic.h"
#include "Character.h"

//------------------------------------------------------------------------------------------------------//
//	��																							//
//		number = 13, input = 7�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		���[�v							//
//	�����l(input)																						//
//		x, y, height, width, pairMirrorNum, id, state		//
//	�����l����																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class G_Mirror :
	public Gimic
{
	int pairMirrorNum;
public:
	G_Mirror(const std::vector<double>& info);
	~G_Mirror();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 7;
};

