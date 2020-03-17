#pragma once
#include "Gimic.h"
#include <set>

//------------------------------------------------------------------------------------------------------//
//	�h�A�p�X�C�b�`																						//
//		number = 5, input = 7�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//									//
//	�����l(input)																						//
//		x, y, height, width, doorNum, state, id		//
//	�����l����																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//

class G_DoorSwitch :
	public Gimic
{
	int doorNum;
	std::set<int> st;
public:
	G_DoorSwitch(const std::vector<double>& info);
	~G_DoorSwitch();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 7;
};

