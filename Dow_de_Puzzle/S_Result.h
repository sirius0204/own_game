#pragma once

#include "BaseScene.h"
#include <string>
#include "Ranking.h"
#include "InputName.h"

#include <cassert>

class S_Result : public BaseScene {
	bool isNaming;			//名前を入力中かどうか
	Ranking rank;			//ランキング
	InputName inputName;	//名前入力
public:
	S_Result(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};
