#include "S_Result.h"

S_Result::S_Result(ISceneChanger* changer) : BaseScene(changer) {}

void S_Result::Initialize(int PlayerNum, int *score) {
	resultH[0] = LoadGraph("./resource/img/1Pwin.png");
	resultH[1] = LoadGraph("./resource/img/2Pwin.png");
	resultH[2] = LoadGraph("./resource/img/3Pwin.png");
	resultH[3] = LoadGraph("./resource/img/4Pwin.png");
	resultbgm = LoadSoundMem("./resource/bgm/result.ogg");
	SetLoopPosSoundMem(8308, resultbgm);
	PlaySoundMem(resultbgm, DX_PLAYTYPE_LOOP);
}

void S_Result::Finalize() {
	InitGraph();
	InitSoundMem();
}

void S_Result::Update(int *score, int *PlayerNum) {
	for (int i = 0; i < 4; i++) {
		if (CheckPadPressOnce(i, PAD_INPUT_1)) {
			mSceneChanger->ChangeScene(eScene_S_Start);
			StopSoundMem(resultbgm);
		}
	}
}

void S_Result::Draw(int *score, int PlayerNum) {
	BaseScene::Draw(score, PlayerNum);
	int winer = 0;
	for (int i = 0; i < PlayerNum; i++) {
		for (int j = i + 1; j < PlayerNum; j++) {
			if (score[i] < score[j]) {
				winer = j;
				break;
			}
		}
	}
	DrawGraph(0, 0, resultH[winer], TRUE);
}
