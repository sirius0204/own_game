#pragma once

#include "BaseScene.h"
#include <algorithm>

class S_Result : public BaseScene {

	int resultH[4];
	int resultbgm;

public:
	S_Result(ISceneChanger* changer);
	void Initialize(int PlayerNum, int *score) override;
	void Finalize() override;
	void Update(int *score, int *PlayerNum) override;
	void Draw(int *score, int PlayerNum) override;
};
