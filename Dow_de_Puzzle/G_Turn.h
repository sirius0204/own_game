#pragma once
#include "Gimic.h"
#include "MyInput.h"

//------------------------------------------------------------------------------------------------------//
//	���]																							//
//		number = 19, input = 2�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//		�E�N���b�N�Ŕ��]�i��l���̂݁j						//
//	�����l(input)																						//
//		id,	state	//
//	�����l����																							//
//																//	
//		//
//------------------------------------------------------------------------------------------------------//

class G_Turn :
	public Gimic
{
	int soundFile[1];
public:
	G_Turn(const std::vector<double>& info);
	~G_Turn();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	static const int initInfoSize = 2;
};

