#include "Input.h"

static int Key[256];
static int Mouse[7];
static int Pad[4][32];

//キーボード
int gpUpdateKey(){
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i<256; i++){
		if (tmpKey[i] != 0){
			Key[i]++;
		}
		else {
			Key[i] = 0;
		}
	}
	return 0;
}

int getKey(const int KeyCode){
	return Key[KeyCode];
}

bool getKeyInterval(const int KeyCode, int interval){
	return (Key[KeyCode] % interval == 1);
}

bool getKeyPress(const int KeyCode){
	return (Key[KeyCode] > 0);
}

bool getKeyPressOnce(const int KeyCode){
	return (Key[KeyCode] == 1);
}

bool getKeyPress2(const int KeyCode[], int num){
	for (int i = 0; i < num; i++){
		if (getKeyPress(KeyCode[i])){
			return true;
		}
	}
	return false;
}

bool getKeyPressOnce2(const int KeyCode[], int num){
	for (int i = 0; i < num; i++){
		if (getKeyPressOnce(KeyCode[i])){
			return true;
		}
	}
	return false;
}

bool getKeyPressDoubleOnce(const int KeyCode1, const int KeyCode2){
	return (getKeyPress(KeyCode1) && getKeyPressOnce(KeyCode2)) || getKeyPress(KeyCode2) && getKeyPressOnce(KeyCode1);
}

bool getKeyPressDoubleOnce1_2(const int KeyCode1, const int KeyCode2[], int num){
	for (int i = 0; i < num; i++){
		if (getKeyPressDoubleOnce(KeyCode1, KeyCode2[i])){
			return true;
		}
	}
	return false;
}

bool getKeyPressDoubleOnce2_2(const int KeyCode1[], const int KeyCode2[], int num1, int num2){
	for (int i = 0; i < num1; i++){
		for (int j = 0; j < num2; j++){
			if (getKeyPressDoubleOnce(KeyCode1[i], KeyCode2[j])){
				return true;
			}
		}
	}
	return false;
}

//マウス
int gpUpdateMouse(){
	GetMousePoint(&Mouse[0], &Mouse[1]);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
		Mouse[2]++;
	}
	else{
		Mouse[2] = 0;
	}
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0){
		Mouse[3]++;
	}
	else{
		Mouse[3] = 0;
	}
	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0){
		Mouse[4]++;
	}
	else{
		Mouse[4] = 0;
	}
	Mouse[6] = GetMouseWheelRotVol();
	Mouse[5] += Mouse[6];
	return 0;
}

int getMouseX(){
	return Mouse[0];
}

int getMouseY(){
	return Mouse[1];
}

int getMouseLeftPressTime(){
	return Mouse[2];
}

int getMouseRightPressTime(){
	return Mouse[3];
}

int getMouseMiddlePressTime(){
	return Mouse[4];
}

int getMouseWheelVol(){
	return Mouse[5];
}

int getMouseWheelVolPM(){
	return Mouse[6];
}

bool getMouseLeftPress(){
	return (Mouse[2] > 0);
}

bool getMouseLeftPressOnce(){
	return (Mouse[2] == 1);
}

bool getMouseRightPress(){
	return (Mouse[3] > 0);
}

bool getMouseRightPressOnce(){
	return (Mouse[3] == 1);
}

bool getMouseMiddlePress(){
	return (Mouse[4] > 0);
}

bool getMouseMiddlePressOnce(){
	return (Mouse[4] == 1);
}

bool checkMouseSquare(double x1, double y1, double x2, double y2){
	return ((getMouseX() >= x1) && (getMouseX() < x2) && (getMouseY() >= y1) && (getMouseY() < y2));
}

bool checkMouseSquare2(double x, double y, double w, double h){
	return ((getMouseX() >= x) && (getMouseX() < x + w) && (getMouseY() >= y) && (getMouseY() < y + h));
}

bool checkMouseCircle(double x, double y, double r){
	return ((getMouseX() - x) * (getMouseX() - x) + (getMouseY() - y) * (getMouseY() - y)) <= r * r;
}

//ゲームパッド
int gpUpdatePad(){
	for (int i = 0; i < 32; i++){
		if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & masks[i]) == 0){
			Pad[0][i] = 0;
		}
		else{
			Pad[0][i]++;
		}
	}
	for (int i = 1; i < GetJoypadNum(); i++){
		for (int j = 0; j < 32; j++){
			if ((GetJoypadInputState(joypads[i]) & masks[j]) == 0){
				Pad[i][j] = 0;
			}
			else{
				Pad[i][j]++;
			}
		}
	}
	return 0;
}

int getPadPressTime(int PadNum, int Mask){
	for (int i = 0; i < 32; i++){
		if (masks[i] == Mask){
			return Pad[PadNum - 1][i];
		}
	}
	return 0;
}

bool getPadPress(int PadNum, int Mask){
	for (int i = 0; i < 32; i++){
		if (masks[i] == Mask){
			return (Pad[PadNum - 1][i] > 0);
		}
	}
	return false;
}

bool getPadPressOnce(int PadNum, int Mask){
	for (int i = 0; i < 32; i++){
		if (masks[i] == Mask){
			return (Pad[PadNum - 1][i] == 1);
		}
	}
	return false;
}

bool CheckPadPress(int PadNum, int Key) {
	if (getPadPress(joypads[PadNum], Key)) {
		return true;
	}
	else return false;
}

bool CheckPadPressOnce(int PadNum, int Key) {
	if (getPadPressOnce(joypads[PadNum], Key)) {
		return true;
	}
	else return false;
}