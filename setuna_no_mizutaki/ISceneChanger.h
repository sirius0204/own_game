#pragma once

typedef enum {
	//�V�[�����
	eScene_S_Start,
	eScene_S_Game,
	eScene_S_Result,

    eScene_None,
} eScene ;

class ISceneChanger {
public:
    virtual ~ISceneChanger() = 0;
    virtual void ChangeScene(eScene NextScene) = 0;
};
