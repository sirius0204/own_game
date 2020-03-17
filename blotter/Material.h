#pragma once
#include<iostream>
#include<DxLib.h>

//�O���[�o���ϐ�
const int WinWidth = 1024;
const int WinHeight = 576;

int scene;//0->�X�^�[�g��� 1->�Q�[����� 2->���U���g���
int cnt;//����
const int timelimit = 1 * 60 * 60;//���Ԑ���
int mode;//��Փx�@0->easy 1->normal 2->hard
int selectmode;//�^�C�g����ʂł̃��[�h�I��
int score;//�X�R�A
const double scorebonus[3] = { 0.6,1,1.5 };
int floodgage = 0;//����Q�[�W
const int max_floodgage = 1000;//�Q�[���I�[�o�[�ɂȂ鉊��Q�[�W�̒l
int endcnt;//space�A�Ŗh�~�p�ϐ�
const int min_endcnt = 1 * 60;//space�A�Ŗh�~�p�ϐ�
int resultcnt;//space�A�Ŗh�~�p�ϐ�
const int min_result = 1 * 60;//space�A�Ŗh�~�p�ϐ�
//int blockcount = 0;//�u���b�N�𐔂���
//int favcount = 0;//�t�@�{�𐔂���
bool isOPend;//OP������������ǂ���
bool isModeselect;//���[�h�Z���N�g�����ǂ���
bool isRule;//������ʂ��ǂ���
bool isgamestart;//�Q�[�����n�܂������ǂ���
bool isgameend;//�Q�[�����I��������ǂ���
bool isgameover;//�Q�[���I�[�o�[���ǂ���

//�G�l�~�[�̕ϐ�
const int enemy_num = 6;//�E�ɏo�Ă���G�l�~�[��+�l�N�X�g�G�l�~�[
const int enemy_kind_num = 9;//�G�̎�ސ�

//�e�̕ϐ�
const int PLAYERBULLET_MAX = 10; //�v���C���[�̒e�̍ő吔
const int ENEMYBULLET_MAX = 5; //�G�l�~�[�̒e�̍ő吔
const int player_shot_interval = 30;//�v���C���[�̒e���ˊԊu
int player_shot_time;//�v���C���[���e���˂�������
const int enemy_shot_interval[3] = {3,2,1};//�G�l�~�[�̒e���ˊԊu,easy,normal,hard�̏�
const int shotsize = 40;//�e�̑傫��

//UI
const int firegauge_x = 330;//����Q�[�W�̕�
const int firegauge_y = 35;//����Q�[�W�̍���
const int MyTeritory_x = 200; //���w�̉E�[
const int EnemyTeritory_x = 860;//�G�w�̍��[


//�`��Ɋւ���ϐ�
int openingH;//OP
int titleH;//�^�C�g�����
int bottonH[3];//���[�h�Z���N�g�{�^��
int modeflameH;//���[�h�Z���N�g�̃t���[��
int map_gh;//�w�i
int ruleH;//������
int startH;//�X�^�[�g
int finishH;//�t�B�j�b�V��
int CharactorH[enemy_kind_num];//�L�����N�^�[�̉摜�n���h��
int playerbullet_gh;//�v���C���[�e
int enemybulletH[2];//�G�l�~�[�e�̉摜�n���h��
int arrow_gh;//���
int favblockH[2];//�����good,dangerous�A�C�R��
int fbcntH[2];//�����fav,block�񐔂̃A�C�R��
int tweetH[8][3];//tweet
int FireH[2];//����Q�[�W�̉摜�n���h��
int resultH[2];//���U���g���
int resultscoreH;//���U���g�̃X�R�A�̘g

int FontH[2];//�ǂݍ��񂾃t�H���g�̃n���h��

//�T�E���h�Ɋւ���ϐ�
int bgmH[2];//bgm�Aresult��bgm��SE�Ƃ��Ă�(1�񂵂������Ȃ�����)
const int SE_num = 12;//SE�̌�
int SEH[SE_num];//SE
bool SEflag[SE_num];//SE�𗬂��^�C�~���O�̃t���O
bool istitlebgm;//�^�C�g��bgm�����ꂽ���ǂ���
bool isgamebgm;//�Q�[��bgm�����ꂽ���ǂ���
bool isresultbgmend;//result��ʂ�bgm���I��������ǂ���