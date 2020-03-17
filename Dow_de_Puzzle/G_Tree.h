#pragma once
#include "Gimic.h"

//------------------------------------------------------------------------------------------------------//
//	雉の木																							//
//		number = 19, input = 6（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//								//
//	初期値(input)																						//
//		x, y, height,width,  id,	state	//
//	初期値説明																							//
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
