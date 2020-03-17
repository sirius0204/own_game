#pragma once
#include "Gimic.h"
#include "MyInput.h"

//------------------------------------------------------------------------------------------------------//
//	反転																							//
//		number = 19, input = 2（自分で書く（下のinitInfoSizeと同じ数にする））								//
//	機能																								//
//		右クリックで反転（主人公のみ）						//
//	初期値(input)																						//
//		id,	state	//
//	初期値説明																							//
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

