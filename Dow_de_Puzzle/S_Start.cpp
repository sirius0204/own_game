#include "S_Start.h"


bool S_Start::isPushButton(int Button[4])
{
	if (Mouse_x > Button[x] && Mouse_x < Button[x] + Button[width] && Mouse_y > Button[y] && Mouse_y < Button[y] + Button[height]) {
		if (Input.getMousePressLeftOnce()) {
			return true;
		}
	}
	return false;
}

bool S_Start::isMouseOver(int Button[4])
{
	if (Mouse_x > Button[x] && Mouse_x < Button[x] + Button[width] && Mouse_y > Button[y] && Mouse_y < Button[y] + Button[height]) {
		return true;
	}
	return false;
}

void S_Start::ButtonInit()
{
	Button1[x] = 102;
	Button1[y] = 329;
	Button1[height] = 87;
	Button1[width] = 347;

	Button2[x] = 102;
	Button2[y] = 449;
	Button2[height] = 87;
	Button2[width] = 347;

	Button3[x] = 102;
	Button3[y] = 569;
	Button3[height] = 87;
	Button3[width] = 347;
}

S_Start::S_Start(ISceneChanger* changer) : BaseScene(changer) {}

void S_Start::Initialize(){
	//mSceneChanger->ChangeScene(eScene_S_Game);
	StopSoundFile();
	PlaySoundFile("./resource/sound/bgm/タイトル_テーマソング.ogg", DX_PLAYTYPE_LOOP);
	TitleHundle[0] = LoadGraph("./resource/img/Background/title_default.png");
	TitleHundle[1] = LoadGraph("./resource/img/Background/title_default_txt.png");
	ButtonInit();
	Button1[4] = LoadGraph("./resource/img/UI/bottun_akazukin.png");
	Button2[4] = LoadGraph("./resource/img/UI/bottun_momotaro.png");
	Button3[4] = LoadGraph("./resource/img/UI/bottun_buta.png");

	Button1_over = LoadGraph("./resource/img/Background/title_akazukin.png");
	Button2_over = LoadGraph("./resource/img/Background/title_momotaro.png");
	Button3_over = LoadGraph("./resource/img/Background/title_kobuta.png");

	SS[0] = LoadGraph("./resource/img/Background/Aka_SS.png");
	SS[1] = LoadGraph("./resource/img/Background/Momo_SS.png");
	SS[2] = LoadGraph("./resource/img/Background/Buta_SS.png");

}

void S_Start::Finalize(){}

void S_Start::Update(){
	if (isPushButton(Button1)) {
		GameMgr::ChangeStage(0);
		mSceneChanger->ChangeScene(eScene_S_Game);
		StopSoundFile();
	}

	else if (isPushButton(Button2)) {
		GameMgr::ChangeStage(4);
		mSceneChanger->ChangeScene(eScene_S_Game);
		StopSoundFile();
	}

	else if (isPushButton(Button3)) {
		GameMgr::ChangeStage(8);
		mSceneChanger->ChangeScene(eScene_S_Game);
		StopSoundFile();
	}
}

void S_Start::Draw(){
	BaseScene::Draw();
	GetMousePoint(&Mouse_x, &Mouse_y);
	DrawGraph(0, 0, TitleHundle[0], false);

	if (isMouseOver(Button1)) {
		DrawGraph(0, 0, Button1_over, TRUE);
		DrawGraph(540, 396, SS[0], TRUE);
	}
	else if (isMouseOver(Button2)) {
		DrawGraph(0, 0, Button2_over, TRUE);
		DrawGraph(540, 396, SS[1], TRUE);
	}
	else if (isMouseOver(Button3)) {
		DrawGraph(0, 0, Button3_over, TRUE);
		DrawGraph(540, 396, SS[2], TRUE);
	}
	else {
		DrawGraph(0, 0, TitleHundle[1], TRUE);
	}
}
