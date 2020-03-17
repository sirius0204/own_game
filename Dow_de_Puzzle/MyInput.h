#pragma once

#include "DxLib.h"
//#include "Input.h"
#include "KeyConfig.h"
#include "struct.h"
#include <map>


//入力を取得する
class MyInput
{
	static const int KeyNum = 256;				//入力キーの最大数
	static const int PadMax = 4;				//接続できるゲームパッドの最大数
	static const int PadNum = 32;				//パッドのボタンの最大数
	static const int MouseButNum = 8;			//マウスのボタンの最大数
	static const int Pads[PadMax];				
	static const int PadMasks[PadNum];
	static const int MouseMasks[MouseButNum];

	KeyConfig keyConf;							//キーコンフィグ

	int keyPressedCnt[KeyNum];					//キーボードの押されカウンター
	int keyReleasedCnt[KeyNum];					//			　離されカウンター
	int padNum;									//接続しているゲームパッドの数
	int padPressedCnt[PadMax][PadNum];			//パッドの押されカウンター
	int padReleasedCnt[PadMax][PadNum];			//		　離されカウンター
	int mousePressedCnt[MouseButNum];			//マウスの押されカウンター
	int mouseReleasedCnt[MouseButNum];			//		　離されカウンター

	int mouseRot;								//マウスホールの回転量
	int mouseRotSum;							//マウスホイールの回転量の合計

	Vector2 mousePoint;							//マウスの座標

	bool UpdateKey();							//キーボードの入力状態を取得
	bool UpdatePad();							//パッドの入力状態を取得
	bool UpdateMouse();							//マウスの入力状態を取得


	int getKeyPress(const eInputKnd KeyCode, eInputPressType par = eInputPT_Press);
	bool getKeyInterval(const eInputKnd KeyCode, int interval, eInputPressType par = eInputPT_Press);

	int getPadPress(const eInputKnd KeyCode, int padNum_ = 0, eInputPressType par = eInputPT_Press);
	bool getPadInterval(const eInputKnd KeyCode, int interval, int padNum_ = 0, eInputPressType par = eInputPT_Press);
public:
	MyInput();
	~MyInput();


	void	Initialize();
	bool	Update();

	int		getInputPress(const eInputKnd KeyCode, eInputPressType par, int padNum_ = 0);
	bool	getInputInterval(const eInputKnd KeyCode, int interval, int padNum_ = 0, eInputPressType par = eInputPT_Press);

	int		getMousePress(const eInputMouse KeyCode, eInputPressType par);
	bool	getMouseInterval(const eInputMouse KeyCode, int interval, eInputPressType par);
	Vector2	getMousePoint();
	int		getMouseWheelRot();
	int		getMouseWheelRotSum();
	int		getMousePressLeft(eInputPressType par = eInputPT_Press);
	bool	getMousePressLeftOnce();
	int		getMousePressRight(eInputPressType par = eInputPT_Press);
	bool	getMousePressRightOnce();
	void    setMouseIgnoreClick();
};


extern MyInput Input;