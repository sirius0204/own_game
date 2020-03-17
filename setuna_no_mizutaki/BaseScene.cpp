#include "BaseScene.h"

BaseScene::BaseScene(ISceneChanger* changer) : 
    mImageHandle(0) {
    mSceneChanger = changer;
}

void BaseScene::Initialize(int PlayerNum, int *score){
}

void BaseScene::Update(int *score, int *PlayerNum) {
}

void BaseScene::Finalize(){
    DeleteGraph(mImageHandle);
}

void BaseScene::Draw(int *score, int PlayerNum){
    DrawGraph(0,0,mImageHandle,FALSE);
}