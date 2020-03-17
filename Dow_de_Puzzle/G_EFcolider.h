#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	Enemy,Friend間の衝突																							//
//		number = 20, input = 2（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//	    Enemy,Friend間で衝突が起こった際Enemy側のisExistをfalseにし、Friend側のscoreをカウントアップします						//
//	初期値(input)																						//
//		state, id		//
//	初期値説明																							//
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