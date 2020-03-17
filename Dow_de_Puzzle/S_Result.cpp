#include "S_Result.h"

S_Result::S_Result(ISceneChanger* changer) : BaseScene(changer) {}

void S_Result::Initialize() {
	isNaming = true;
	inputName.Initialize();
	PlaySoundFile("./resource/sound/bgm/���O���͉��.ogg", DX_PLAYTYPE_LOOP);
}

void S_Result::Finalize() {}

void S_Result::Update() {
	if (isNaming) {						//���O���͒��Ȃ�
		if (!inputName.Upadate()) {		//���O�̓��͂��I��������
			isNaming = false;
			rank.Initialize(inputName.getName());	//�����L���O�̏�����
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
