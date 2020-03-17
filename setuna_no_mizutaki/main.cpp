#include "DxLib.h"
#include "SceneMgr.h"

bool checkAll(){
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0 && gpUpdateMouse() == 0 && gpUpdatePad() == 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	SetMainWindowText("");
	SetGraphMode(WinWidth, WinHeight, 16), ChangeWindowMode(TRUE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	ChangeFont("HGPçsèëëÃ"); SetFontSize(20);

	SceneMgr sceneMgr;
	sceneMgr.Initialize();

	while (checkAll()){
		sceneMgr.Update();
		sceneMgr.Draw();
	}

	DxLib_End();
	return 0;
}