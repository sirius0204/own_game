#pragma once

#include "BaseScene.h"
#include "Input.h"
#include "Materials.h"


class S_Game : public BaseScene {

	const int CURSORSPEED[2] = { 15,10 };

	struct GOAL {
		int x;
		int y;
	};
	GOAL Goal[4];

	struct PAD {
		int x;
		int y;
		int r;
		int Catch;	//����ł�H�ނ̃i���o�[
		int StopCnt; //�����Ԃ����Ă���̎���
		bool isDead;
	};
	PAD Pad[4];

	int dishType;
	const int STOPCNT = 30;	//�����Ԃ�������̂��߂Ȃ�����

	struct dish {//�H��
	public:
		//�ʒu
		double x;
		double y;
		//�ς�����
		int time;
		//�D��x
		int priority;
		//�H�ނ̎��
		int stuffType; //0->�� 1->�������� 2->���� 3->�˂� 4->����
		bool isAlive;//��������
		bool isBoil;//�ς�����
		bool isCatch;//���܂�Ă��邩
	};
	int dish_r;
	int stuffColor;
	int PriCnt;//�D��x�ݒ�p
	const int stuffNum = 8;
	const int BOILTIME[5] = { 10 * 60,5 * 60, 3 * 60, 2 * 60, 11 * 60 };//�ς鎞��
	const int SCORE[5] = { 200,50,30,20,10 };//�X�R�A

	class dish FoodStuff[256];
	bool push;

	const int GOALX[4] = { 0,960,0,960 };
	const int GOALY[4] = { 0,720,720,0 };
	const int GOALR = 200;

	bool CreateF;

	//�摜�֘A
	int foodH[10];
	int dishH[4];
	int	stickH[4];
	int boilH;
	int potH;
	//int lockH;
	int numH[10];
	int scoreFont;
	const int FOODWIDTH = 200;
	const int FOODHEIGHT = 200;
	const int STICKWIDTH = 300;
	const int STICKHEIGHT = 100;
	const int BOILWIDTH = 200;
	const int BOILHEIGHT = 200;
	const int NUMWIDTH = 40;
	const int DISHSIZE = 210;

	//���y�֘A
	int mainbgm;
	int SE[6];

	void UpdateCursor(int PlayerNum);
	void HitCirsor(int PlayerNum);
	void GoalCursor(int *score, int PlayerNum);
	void CreateFood();
	void CatchFood(int *score, int PlayerNum);
	void VoilFood();

	bool CheckHitCircle(int x1, int y1, int r1, int x2, int y2, int r2);
	bool CheckInCircle(int x1, int y1, int r1, int x2, int y2, int r2);
	void InitCursor(int PadNum, int x, int y, int r, int Catch, int StopCnt, bool isDead);
	void InitGoal(int PlayerNum);
	void InitDraw();
	void InitGameSound();
	void InitScore(int PlayerNum, int *score);

	void DrawTime();
	void DrawScore(int *score, int PlayerNum);


public:

	int time;
	const int TIMELIMIT = 1 * 60 * 60;

	S_Game(ISceneChanger* changer);
	void Initialize(int PlayerNum, int *score) override;
	void Finalize() override;
	void Update(int *score, int *PlayerNum) override;
	void Draw(int *score, int PlayerNum) override;

};

