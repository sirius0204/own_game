#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	橋																							//
//		number = 7, input = 8																			//
//	機能																								//
//		クリックで、消滅⇔出現																	//
//	初期値(input)																						//
//		x, y, h, w, movefloorNum0, movefloorNum1, id, 初期state								//
//	初期値説明																							//														//	
//		state			: 0->無　1->有							//
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

