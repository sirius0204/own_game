#include "S_Result.h"

S_Result::S_Result(ISceneChanger* changer) : BaseScene(changer) {}

void S_Result::Initialize() {
	isNaming = true;
	inputName.Initialize();
	PlaySoundFile("./resource/sound/bgm/名前入力画面.ogg", DX_PLAYTYPE_LOOP);
}

void S_Result::Finalize() {}

void S_Result::Update() {
	if (isNaming) {						//名前入力中なら
		if (!inputName.Upadate()) {		//名前の入力が終了したら
			isNaming = false;
			rank.Initialize(inputName.getName());	//ランキングの初期化
			StopSoundFile();
			rank.Sound();
		}
	}
	else {
		if (Input.getMousePressLeftOnce()) {
			rank.Finalize();
			Finalize();
			mSceneChanger->ChangeScene(eScene_S_Start);
		}
	}
}

void S_Result::Draw() {
	BaseScene::Draw();
	if (isNaming) {
		inputName.Draw();
	}
	else {
		rank.Draw();
	}
}
