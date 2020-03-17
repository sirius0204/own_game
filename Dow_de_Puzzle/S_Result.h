#pragma once

#include "BaseScene.h"
#include <string>
#include "Ranking.h"
#include "InputName.h"

#include <cassert>

class S_Result : public BaseScene {
	bool isNaming;			//���O����͒����ǂ���
	Ranking rank;			//�����L���O
	InputName inputName;	//���O����
public:
	S_Result(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};
