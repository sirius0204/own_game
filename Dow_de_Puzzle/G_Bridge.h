#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	��																							//
//		number = 7, input = 8																			//
//	�@�\																								//
//		�N���b�N�ŁA���Ł̏o��																	//
//	�����l(input)																						//
//		x, y, h, w, movefloorNum0, movefloorNum1, id, ����state								//
//	�����l����																							//														//	
//		state			: 0->���@1->�L							//
//------------------------------------------------------------------------------------------------------//

class G_Bridge :
	public Gimic
{
	int moveFloorNum[2];

	int soundFile[1];
public:
	G_Bridge(const std::vector<double>& _infos);
	~G_Bridge();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 8;
};

