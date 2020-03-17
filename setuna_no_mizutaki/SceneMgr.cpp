#include "DxLib.h"
#include "SceneMgr.h"
#include "S_Start.h"
#include "S_Game.h"
#include "S_Result.h"


SceneMgr::SceneMgr() : mNextScene(eScene_None) {
	mScene = (BaseScene*) new S_Start(this);
}

void SceneMgr::Initialize(){
	mScene->Initialize(PLAYERNUM,score);
}

void SceneMgr::Finalize(){ mScene->Finalize(); }

void SceneMgr::Update(){
	//ƒV[ƒ“ˆ—
	if(mNextScene != eScene_None){
		mScene->Finalize();

		delete mScene;
		switch(mNextScene){
		case eScene_S_Start:
			mScene = (BaseScene*) new S_Start(this);
			break;
		case eScene_S_Game:
			mScene = (BaseScene*) new S_Game(this);
			break;
		case eScene_S_Result:
			mScene = (BaseScene*) new S_Result(this);
			break;
		}
		mNextScene = eScene_None;
		mScene->Initialize(PLAYERNUM,score);
	}
	mScene->Update(score,&PLAYERNUM);
}

void SceneMgr::Draw(){ mScene->Draw(score, PLAYERNUM); }

void SceneMgr::ChangeScene(eScene NextScene){
	mNextScene = NextScene;
}
