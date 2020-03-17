#include "MyInput.h"

const int MyInput::Pads[] = { DX_INPUT_PAD1, DX_INPUT_PAD2, DX_INPUT_PAD3, DX_INPUT_PAD4 };
const int MyInput::PadMasks[] = {	PAD_INPUT_DOWN, PAD_INPUT_LEFT, PAD_INPUT_RIGHT, PAD_INPUT_UP,
									PAD_INPUT_1, PAD_INPUT_2, PAD_INPUT_3, PAD_INPUT_4, PAD_INPUT_5, PAD_INPUT_6, PAD_INPUT_7, PAD_INPUT_8, PAD_INPUT_9, PAD_INPUT_10,
									PAD_INPUT_11, PAD_INPUT_12, PAD_INPUT_13, PAD_INPUT_14, PAD_INPUT_15, PAD_INPUT_16, PAD_INPUT_17, PAD_INPUT_18, PAD_INPUT_19, PAD_INPUT_20,
									PAD_INPUT_21, PAD_INPUT_22, PAD_INPUT_23, PAD_INPUT_24, PAD_INPUT_25, PAD_INPUT_26, PAD_INPUT_27, PAD_INPUT_28 };
const int MyInput::MouseMasks[] = { MOUSE_INPUT_1, MOUSE_INPUT_2, MOUSE_INPUT_3, MOUSE_INPUT_4, MOUSE_INPUT_5, MOUSE_INPUT_6, MOUSE_INPUT_7, MOUSE_INPUT_8 };



MyInput::MyInput()
{
	Initialize();
	
}


MyInput::~MyInput()
{
}




void MyInput::Initialize(){
	for (int i = 0; i < KeyNum; i++){
		keyPressedCnt[i] = 0;
		keyReleasedCnt[i] = 0;
	}

	padNum = GetJoypadNum();
	for (int i = 0; i < PadMax; i++){
		for (int j = 0; j < PadNum; j++){
			padPressedCnt[i][j] = 0;
			padReleasedCnt[i][j] = 0;
		}
	}

	for (int i = 0; i < MouseButNum; i++){
		mousePressedCnt[i] = 0;
		mouseReleasedCnt[i] = 0;
	}
	mouseRot = 0;
	mouseRotSum = 0;
}

bool MyInput::Update(){

	//キーボード,　パッド,　マウスの入力状態を更新
	return UpdateKey() && UpdatePad() && UpdateMouse();
}



bool MyInput::UpdateKey(){
	char tmpKey[KeyNum];
	GetHitKeyStateAll(tmpKey);				//すべてのキーの入力状態を取得
	for (int i = 0; i < KeyNum; i++){
		if (tmpKey[i] == 0){				//今見ているキーが押されてなかったら
			if (keyPressedCnt[i] != 0){
				keyPressedCnt[i] = 0;
			}
			++keyReleasedCnt[i];
		}
		else{								//今見ているキーが押されていたら
			if (keyReleasedCnt[i] != 0){
				keyReleasedCnt[i] = 0;
			}
			++keyPressedCnt[i];
		}
	}
	
	return true;
}

bool MyInput::UpdatePad(){
	for (int i = 0; i < padNum; i++){
		for (int j = 0; j < PadNum; j++){
			if ((GetJoypadInputState(Pads[i]) & PadMasks[j]) == 0){	//ボタンが押されているなら
				if (padPressedCnt[i][j] != 0){
					padPressedCnt[i][j] = 0;
				}
				++padReleasedCnt[i][j];
			}	
			else{													//ボタンが押されていないなら
				if (padReleasedCnt[i][j] != 0){
					padReleasedCnt[i][j] = 0;
				}
				++padPressedCnt[i][j] = 0;
			}
		}
	}

	return true;
}

bool MyInput::UpdateMouse(){
	int tmpMouse = GetMouseInput();					//マウスの入力状態
	int tmpMouseX, tmpMouseY;						//マウスの座標
	GetMousePoint(&tmpMouseX, &tmpMouseY);			//マウスの座標を取得
	mousePoint.setVector2(tmpMouseX, tmpMouseY);
	for (int i = 0; i < MouseButNum; i++){
		if (tmpMouse & MouseMasks[i]){				//ボタンが押されていれば
			if (mouseReleasedCnt[i] != 0){
				mouseReleasedCnt[i] = 0;
			}
			++mousePressedCnt[i];
		}
		else{										//ボタンが押されていなければ
			if (mousePressedCnt[i] != 0){
				mousePressedCnt[i] = 0;
			}
			++mouseReleasedCnt[i];
		}
	}
	mouseRot = GetMouseWheelRotVol();				//マウスホイールの回転量を取得
	mouseRotSum += mouseRot;
	return true;
}

void MyInput::setMouseIgnoreClick() {
	for (int i = 0; i < MouseButNum; i++) {
		if (mousePressedCnt[i]>0)mousePressedCnt[i] -= (1 << 30);
	}
}

//以下ゲッター

int  MyInput::getKeyPress(const eInputKnd KeyCode, eInputPressType par){
	if (par == eInputPT_PressNot){
		return keyReleasedCnt[keyConf.getKey(eInputT_Key, KeyCode)];
	}
	else if (par == eInputPT_PressOnce){
		return keyPressedCnt[keyConf.getKey(eInputT_Key, KeyCode)] == 1;
	}
	return keyPressedCnt[keyConf.getKey(eInputT_Key, KeyCode)];
}
bool  MyInput::getKeyInterval(const eInputKnd KeyCode, int interval, eInputPressType par){
	if (par == eInputPT_PressNot){
		return keyReleasedCnt[keyConf.getKey(eInputT_Key, KeyCode)] % interval == 1;
	}
	return keyPressedCnt[keyConf.getKey(eInputT_Key, KeyCode)] % interval == 1;
}

int MyInput::getPadPress(const eInputKnd KeyCode, int padNum_, eInputPressType par){
	if (padNum_ >= padNum){
		return -1;
	}
	if (par == eInputPT_PressNot){
		return padReleasedCnt[padNum_][keyConf.getKey(eInputT_Pad, KeyCode)];
	}
	else if (par == eInputPT_PressOnce){
		return padPressedCnt[padNum_][keyConf.getKey(eInputT_Pad, KeyCode)] == 1;
	}
	return padPressedCnt[padNum_][keyConf.getKey(eInputT_Pad, KeyCode)];
}
bool MyInput::getPadInterval(const eInputKnd KeyCode, int interval, int padNum_, eInputPressType par){
	if (padNum_ >= padNum){
		return false;
	}
	if (par == eInputPT_PressNot){
		return padReleasedCnt[padNum_][keyConf.getKey(eInputT_Pad, KeyCode)] % interval == 1;
	}
	return padPressedCnt[padNum_][keyConf.getKey(eInputT_Pad, KeyCode)] % interval == 1;
}

int MyInput::getInputPress(const eInputKnd KeyCode, eInputPressType par, int padNum_){
	if (par == eInputPT_PressNot){
		return  min(getKeyPress(KeyCode, par), getPadPress(KeyCode, padNum_, par));
	}
	return max(getKeyPress(KeyCode, par), getPadPress(KeyCode, padNum_, par));
}
bool MyInput::getInputInterval(const eInputKnd KeyCode, int interval, int padNum_, eInputPressType par){
	return getKeyInterval(KeyCode, interval, par) || getPadInterval(KeyCode, padNum_, par);
}


int	MyInput::getMousePress(const eInputMouse KeyCode, eInputPressType par){
	if (par == eInputPT_PressNot){
		return mouseReleasedCnt[KeyCode];
	}
	else if (par == eInputPT_PressOnce){
		return mousePressedCnt[KeyCode] == 1;
	}
	return mousePressedCnt[KeyCode];
}
bool MyInput::getMouseInterval(const eInputMouse KeyCode, int interval, eInputPressType par){
	if (par == eInputPT_PressNot){
		return mouseReleasedCnt[KeyCode] % interval == 1;
	}
	return mousePressedCnt[KeyCode] % interval == 1;
}
Vector2	MyInput::getMousePoint(){
	return mousePoint;
}
int	MyInput::getMouseWheelRot(){
	return mouseRot;
}
int	MyInput::getMouseWheelRotSum(){
	return mouseRotSum;
}
int	MyInput::getMousePressLeft(eInputPressType par){
	return getMousePress(eInputM_1, par);
}
bool MyInput::getMousePressLeftOnce(){
	return getMousePress(eInputM_1, eInputPT_PressOnce)==1;
}
int	MyInput::getMousePressRight(eInputPressType par){
	return getMousePress(eInputM_2, par);
}
bool MyInput::getMousePressRightOnce(){
	return getMousePress(eInputM_2, eInputPT_PressOnce)==1;
}