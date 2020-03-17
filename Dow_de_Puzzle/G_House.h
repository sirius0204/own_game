#pragma once
#include "Gimic.h"
#include "math.h"

//------------------------------------------------------------------------------------------------------//
//	家																										//
//		number = 26, input = 6																			//
//	機能																								//
//		ブタの家。材料の割合によって変化します。															//
//	初期値(input)																						//
//		x, y, height, width, id, state																	//
//	初期値説明																							//
//		特になし																							//	
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

	//initInfoSizeは自分で決める
	static const int initInfoSize = 6;

private:
	void SelectGraph(int collection);
	int setRange(double data);
	void NearPoint(int* range, Vector2& point, int w, int b);
	int getGraph(Vector2 point);
};

