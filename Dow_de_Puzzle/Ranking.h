#pragma once
#include "DxLib.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "GameMgr.h"

struct RankInfo;	//クラスの前方宣言

class Ranking
{
	std::string convert(int n);
	const int ShownRank = 10;		//画面に描画するランキングの数
	const int HadRank = 1<<30;		//テキストファイルに保存するランキングの数
	std::string name;				//プレイヤーネーム
	int score;						//プレーヤーのスコア
	int rank;						//プレーヤーの順位
	std::vector<RankInfo> ranking;	//ランキング用の配列

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

//ランキングに必要な情報用の構造体
struct RankInfo {
	int score;			//スコア
	std::string name;	//ネーム
	int rank;			//順位
	RankInfo() {};
	RankInfo(int score, const std::string name, int rank) :score(score), name(name), rank(rank) {};
	//オペレータ（ソート時に用いる）
	const bool operator <(const RankInfo& r) {
		return score != r.score ? score > r.score : name < r.name;
	}
};