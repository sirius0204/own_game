#pragma once
#include "Gimic.h"


//------------------------------------------------------------------------------------------------------//
//	回転する床																							//
//		number = 0, input = 10																			//
//	機能																								//
//		クリックで回転（９０度倒れる）																	//
//	初期値(input)																						//
//		x, y, h, w,  moveFloorNum0, moveFloorNum1, moveFloorNum2, moveFloorNum3, id, 初期state				//
//	初期値説明																							//
//		ボタンの位置	: true-> 左　false-> 右															//	
//		state			: 0-> 平行　	1-> 垂直	3->移動中(0->1)（４５度）4->移動中（1->0）(４５度)	//
//------------------------------------------------------------------------------------------------------//

class G_SpinFloor :
	public Gimic
{
	
	int moveFloorNum[4];
	int soundFile[2];
public:
	G_SpinFloor(const std::vector<double>& _infos);
	~G_SpinFloor();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();
	
	
	static const int initInfoSize = 10;
};

