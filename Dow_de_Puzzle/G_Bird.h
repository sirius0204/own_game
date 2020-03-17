#pragma once
#include "Gimic.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	�L�W																						//
//		number = 24, input = 12�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j								//
//	�@�\																								//
//									//
//	�����l(input)																						//
//		x, y, height, width, tx1,ty1,tx2,ty2, stopflame, moveflame,  id	,state	//
//	�����l����																							//
//																//	
//		
//------------------------------------------------------------------------------------------------------//


class G_Bird :
	public Gimic
{
	int stopflame, moveflame;
	Vector2 tree[2];
	Vector2 velocity;
	Vector2 accelaration;

	int soundFile[2];
public:
	G_Bird(const std::vector<double>& info);
	~G_Bird();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	void addAnimal(std::bitset<Friend::eFriendState_St2::Size> &bs);
	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 12;
};

