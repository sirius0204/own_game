#include"DxLib.h"


//�O���[�o���ϐ�
const int WinWidth = 640*1.5;
const int WinHeight = 480*1.5;

bool checkAll() {
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0;
}

//���C���֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("");
	SetGraphMode(WinWidth, WinHeight, 16), ChangeWindowMode(TRUE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	ChangeFont("HGP�s����"); SetFontSize(20);


	while (checkAll()) {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "");
	}

	DxLib_End();
	return 0;
}


