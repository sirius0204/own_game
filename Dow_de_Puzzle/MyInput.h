#pragma once

#include "DxLib.h"
//#include "Input.h"
#include "KeyConfig.h"
#include "struct.h"
#include <map>


//���͂��擾����
class MyInput
{
	static const int KeyNum = 256;				//���̓L�[�̍ő吔
	static const int PadMax = 4;				//�ڑ��ł���Q�[���p�b�h�̍ő吔
	static const int PadNum = 32;				//�p�b�h�̃{�^���̍ő吔
	static const int MouseButNum = 8;			//�}�E�X�̃{�^���̍ő吔
	static const int Pads[PadMax];				
	static const int PadMasks[PadNum];
	static const int MouseMasks[MouseButNum];

	KeyConfig keyConf;							//�L�[�R���t�B�O

	int keyPressedCnt[KeyNum];					//�L�[�{�[�h�̉�����J�E���^�[
	int keyReleasedCnt[KeyNum];					//			�@������J�E���^�[
	int padNum;									//�ڑ����Ă���Q�[���p�b�h�̐�
	int padPressedCnt[PadMax][PadNum];			//�p�b�h�̉�����J�E���^�[
	int padReleasedCnt[PadMax][PadNum];			//		�@������J�E���^�[
	int mousePressedCnt[MouseButNum];			//�}�E�X�̉�����J�E���^�[
	int mouseReleasedCnt[MouseButNum];			//		�@������J�E���^�[

	int mouseRot;								//�}�E�X�z�[���̉�]��
	int mouseRotSum;							//�}�E�X�z�C�[���̉�]�ʂ̍��v

	Vector2 mousePoint;							//�}�E�X�̍��W

	bool UpdateKey();							//�L�[�{�[�h�̓��͏�Ԃ��擾
	bool UpdatePad();							//�p�b�h�̓��͏�Ԃ��擾
	bool UpdateMouse();							//�}�E�X�̓��͏�Ԃ��擾


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