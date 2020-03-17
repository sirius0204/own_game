#pragma once

#include "DxLib.h"
#include "Task.h"
#include "ISceneChanger.h"
#include "MyInput.h"
#include "Materials.h"

class BaseScene : public Task {

protected:
    int mImageHandle;
    ISceneChanger* mSceneChanger;

public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}
	virtual void Initialize() override ;
    virtual void Finalize() override ;
	virtual void Update() override {}
	virtual void Draw() override;

};