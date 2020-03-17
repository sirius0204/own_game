#pragma once
#include "Gimic.h"
#include "F_Momotaro.h"
#include <bitset>

//------------------------------------------------------------------------------------------------------//
//	��q																								//
//		number = 2, input = 6�i�����ŏ����i����initInfoSize�Ɠ������ɂ���j�j							//
//	�@�\																								//
//		�N���b�N����ƒ�q���o���or�o��Ȃ��Ȃ�														//
//		friend���ʉ߂���Ə�艺�肷��																	//
//	�����l(input)																						//
//		x, y, height, width,id,state																	//													
//	�����l����																							//
//		state :1���ځ@0->�ʍs�s�� 1->�ʍs��															    //
//			   2���ځ@��q�ʉߒ����ǂ���																//
//			�@�@�@�@�@�@																				//
//------------------------------------------------------------------------------------------------------//

class G_Ladder :
	public Gimic
{
protected:

public:
	G_Ladder(const std::vector<double>& info);
	~G_Ladder();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	double getLadderCenter_x();
	//Vector2 makeVelocity();
	bool isReachDown(Friend *fre);
	bool isReachUp(Friend *fre);
	bool isProcess(std::vector<Friend*> friends);

	enum eLadderState{
		isAccess = 0,
		isLadderUp,
		Size
	};

	static const int initInfoSize = 6;
};

