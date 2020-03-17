#pragma once

#include "DxLib.h"



//���͂̎�ނ�񋓁i�����Ɏg�����͂̎�ނ�񋓂���j
enum eInputKnd {						//TODO : Marge
	eInput_E, eInput_S, eInput_C,
	eInput_End
};

//���̓f�o�C�X�̎�ނ��
enum eInputType {
	eInputT_Key = 0, eInputT_Pad, eInputT_Mouse,
	eInputT_End
};

//���͂̏�Ԃ��
enum eInputPressType {
	eInputPT_Press = 0, eInputPT_PressNot, eInputPT_PressOnce,
	eInputPT_End
};

//�Q�[���p�b�h�̓��͂��
enum eInputPad {
	eInputP_Down = 0, eInputP_Left, eInputP_Right, eInputP_Up,
	eInputP_1, eInputP_2, eInputP_3, eInputP_4, eInputP_5, eInputP_6, eInputP_7, eInputP_8, eInputP_9, eInputP_10,
	eInputP_11, eInputP_12, eInputP_13, eInputP_14, eInputP_15, eInputP_16, eInputP_17, eInputP_18, eInputP_19, eInputP_20,
	eInputP_21, eInputP_22, eInputP_23, eInputP_24, eInputP_25, eInputP_26, eInputP_27, eInputP_28,
	eInputP_End
};

//�}�E�X�̓��͂��
enum eInputMouse {
	eInputM_1 = 0, eInputM_2, eInputM_3, eInputM_4, eInputM_5, eInputM_6, eInputM_7, eInputM_8,
	eInputM_End
};