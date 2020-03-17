#pragma once

#include "BaseScene.h"
#include <algorithm>

class S_Start : public BaseScene {

	int SelectNum;

	int titleH;
	int startH[6];
	const int STARTWIDTH = 400;
	const int STARTLWIDTH = 450;

	int titlebgm;

public:
	S_Start(ISceneChanger* changer);
	void Initialize(int PlayerNum, int *score) override;
	void Finalize() override;
	void Update(int *score, int *PlayerNum) override;
	void Draw(int *score, int PlayerNum) override;

};
