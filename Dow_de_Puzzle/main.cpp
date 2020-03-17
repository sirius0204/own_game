#include "DxLib.h"
#include "SceneMgr.h"
#include "MyInput.h"

MyInput Input;

bool checkAll(){
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Input.Update();
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	SetMainWindowText("童話deパズル");
	SetGraphMode(WinWidth, WinHeight, 16), ChangeWindowMode(FALSE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	//ChangeFont("HGP行書体"); SetFontSize(20);

	SetMouseDispFlag(TRUE);
	SceneMgr sceneMgr;
	sceneMgr.Initialize();

	while (checkAll()){

		sceneMgr.Update();
		sceneMgr.Draw();
	}

	DxLib_End();
	return 0;
}