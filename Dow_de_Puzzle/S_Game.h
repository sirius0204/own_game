#pragma once

#include "BaseScene.h"
#include "GameMgr.h"

class S_Game : public BaseScene {
	GameMgr gameMgr;
public:
	S_Game(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};
