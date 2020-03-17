#pragma once
#include "DxLib.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "GameMgr.h"

struct RankInfo;	//�N���X�̑O���錾

class Ranking
{
	std::string convert(int n);
	const int ShownRank = 10;		//��ʂɕ`�悷�郉���L���O�̐�
	const int HadRank = 1<<30;		//�e�L�X�g�t�@�C���ɕۑ����郉���L���O�̐�
	std::string name;				//�v���C���[�l�[��
	int score;						//�v���[���[�̃X�R�A
	int rank;						//�v���[���[�̏���
	std::vector<RankInfo> ranking;	//�����L���O�p�̔z��

	int SoundHundle[3];
	int FontHandle[2];
	int bgH[1];
public:
	Ranking();
	~Ranking();

	void Initialize(const std::string& _name);
	void Draw();

	void Sound();
	void Finalize();

	void nameSwap();

};

//�����L���O�ɕK�v�ȏ��p�̍\����
struct RankInfo {
	int score;			//�X�R�A
	std::string name;	//�l�[��
	int rank;			//����
	RankInfo() {};
	RankInfo(int score, const std::string name, int rank) :score(score), name(name), rank(rank) {};
	//�I�y���[�^�i�\�[�g���ɗp����j
	const bool operator <(const RankInfo& r) {
		return score != r.score ? score > r.score : name < r.name;
	}
};