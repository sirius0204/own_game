#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	Enemy,Friend�Ԃ̏Փ�																							//
//		number = 20, input = 2�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//	    Enemy,Friend�ԂŏՓ˂��N��������Enemy����isExist��false�ɂ��AFriend����score���J�E���g�A�b�v���܂�						//
//	�����l(input)																						//
//		state, id		//
//	�����l����																							//
//																							//	
//		//
//------------------------------------------------------------------------------------------------------//


class G_EFcolider :
	public Gimic
{
public:
	G_EFcolider(const std::vector<double>& info);
	~G_EFcolider();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	void colider(std::vector<Friend*> &friends, std::vector<Enemy*> &enemys, int &score);


	static const int initInfoSize = 2;
};