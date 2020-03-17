#pragma once
#include "Gimic.h"
#include "math.h"

//------------------------------------------------------------------------------------------------------//
//	��																										//
//		number = 26, input = 6																			//
//	�@�\																								//
//		�u�^�̉ƁB�ޗ��̊����ɂ���ĕω����܂��B															//
//	�����l(input)																						//
//		x, y, height, width, id, state																	//
//	�����l����																							//
//		���ɂȂ�																							//	
//																											//
//------------------------------------------------------------------------------------------------------//

class G_House :
	public Gimic
{
public:
	G_House(const std::vector<double>& info);
	~G_House();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();

	//initInfoSize�͎����Ō��߂�
	static const int initInfoSize = 6;

private:
	void SelectGraph(int collection);
	int setRange(double data);
	void NearPoint(int* range, Vector2& point, int w, int b);
	int getGraph(Vector2 point);
};

