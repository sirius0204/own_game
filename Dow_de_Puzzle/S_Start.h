#pragma once
#include "BaseScene.h"
#include "GameMgr.h"
#include "Object.h"


class S_Start : public BaseScene {
	int Mouse_x;
	int Mouse_y;
	int Button1[5];  //[0]->x, [1]->y, [2]->height, [3]->width
	int Button2[5];
	int Button3[5];
	int SS[3];

	
	int Button1_over;
	int Button2_over;
	int Button3_over;

	bool isMouseOver(int Button[4]);

	bool isPushButton(int Button[4]);
	void ButtonInit();
	int TitleHundle[2];
	enum {x,y,height,width};

public:
	S_Start(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};
