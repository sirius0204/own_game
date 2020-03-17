#pragma once

#include "DxLib.h"
#include "Task.h"
#include "ISceneChanger.h"
#include "Input.h"
#include "Materials.h"

class BaseScene/* : public Task */{

protected:
    int mImageHandle;
    ISceneChanger* mSceneChanger;

public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}
	virtual void Initialize(int PlayerNum,int *score) = 0;
	virtual void Finalize() = 0;
	virtual void Update(int *score,int *PlayerNum) = 0;
	virtual void Draw(int *score, int PlayerNum) = 0;
};