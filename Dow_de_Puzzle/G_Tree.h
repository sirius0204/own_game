#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	賂̖�																							//
//		number = 19, input = 6�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//								//
//	�����l(input)																						//
//		x, y, height,width,  id,	state	//
//	�����l����																							//
//																//	
//		//
//------------------------------------------------------------------------------------------------------//

class G_Tree :
	public Gimic
{

public:
	G_Tree(const std::vector<double>& info);
	~G_Tree();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	static const int initInfoSize = 6;
};
