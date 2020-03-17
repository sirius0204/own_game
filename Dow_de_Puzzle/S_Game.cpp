#include "S_Game.h"

S_Game::S_Game(ISceneChanger* changer) : BaseScene(changer) {}

void S_Game::Initialize(){
	int playNum;
	std::ifstream input("./resource/dat/playnum.txt");
	input >> playNum;
	input.close();
	playNum++;
	std::ofstream output("./resource/dat/playnum.txt");
	output << playNum;
	gameMgr.Initialize();
}

void S_Game::Finalize(){
	gameMgr.Finalize();
}

void S_Game::Update(){
	if (Input.getInputPress(eInputKnd::eInput_E, eInputPressType::eInputPT_Press)
		&& Input.getInputPress(eInputKnd::eInput_S, eInputPressType::eInputPT_Press)
		&& Input.getInputPress(eInputKnd::eInput_C, eInputPressType::eInputPT_Press)) {
		mSceneChanger->ChangeScene(eScene_S_Start);
	}
	if(!(gameMgr.Update()))mSceneChanger->ChangeScene(eScene_S_Result);
}

void S_Game::Draw(){
	BaseScene::Draw();
}
