#include "Ranking.h"



Ranking::Ranking()
{
}


Ranking::~Ranking()
{
}

std::string Ranking::convert(int n) {
	std::stringstream ss;
	ss << n;
	return ss.str();
}

void Ranking::Initialize(const std::string & _name)
{
	name = _name;
	ranking.resize(0);
	std::string inputPath = "./resource/dat/score/ranking";
	std::string inputScorePath = "./resource/dat/score/score";
	std::ifstream input(inputPath + convert(GameMgr::getStage() / 4) + ".txt");		//ランキングの入力
	std::ifstream inputScore(inputScorePath  + ".txt");		//今回のプレイのスコアを読み取る
	inputScore >> score;
	int rankNum;		//保存されているランキングの個数
	input >> rankNum;
	for (int i = 0; i < rankNum; i++) {
		RankInfo tmp;
		input >> tmp.score >> tmp.name;
		tmp.rank = 0;
		ranking.push_back(tmp);
	}
	ranking.push_back(RankInfo( score,name,-1 ));	//今回のプレイを追加
	std::sort(ranking.begin(), ranking.end());		//ランキングをスコア順にソート
	nameSwap();

	rank = 1;
	ranking[0].rank = 1;
	//順位を決定
	for (unsigned i = 1; i < ranking.size(); i++) {
		if (ranking[i].score == ranking[i - 1].score) {
			ranking[i].rank = ranking[i - 1].rank;
		}
		else {
			ranking[i].rank = i + 1;
		}
		if (ranking[i].score == score) rank = ranking[i].rank;
	}
	input.close();
	std::string outputPath = "./resource/dat/score/ranking";
	std::ofstream output(outputPath + convert(GameMgr::getStage() / 4) + ".txt", std::ios::trunc);	//順位をテキストファイルに出力
	output << min(HadRank, (int)ranking.size()) << std::endl;
	for (int i = 0; i < min(HadRank, (int)ranking.size()); i++) {
		output << ranking[i].score << " " << ranking[i].name << std::endl;
	}
	output.close();

	SoundHundle[0] = LoadSoundMem("./resource/sound/bgm/リザルト画面～パーフェクト～.ogg");
	SoundHundle[1] = LoadSoundMem("./resource/sound/bgm/リザルト画面～ノルマクリア～.ogg");
	SoundHundle[2] = LoadSoundMem("./resource/sound/bgm/リザルト画面～ノルマ失敗～.ogg");

	LPCSTR font_path = "./resource/Font/uzurafont100/uzurafont100/uzura.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}

	FontHandle[1] = CreateFontToHandle(font_path, 15, 9);

	bgH[0] = LoadGraph("./resource/img/Background/result.png");

}

void Ranking::Draw()
{
	DrawGraph(0, 0, bgH[0],TRUE);
	DrawFormatStringToHandle(100, 100, GetColor(204, 143, 81), FontHandle[1], "%15sのスコアは %d", name.c_str(),score);
	DrawFormatStringToHandle(120, 130, GetColor(204, 143, 81), FontHandle[1], "%15sの順位は、",name.c_str());
	if (rank > HadRank) {
		DrawFormatStringToHandle(300, 160, GetColor(204, 143, 81), FontHandle[1], "圏外です");
	}
	else {
		DrawFormatStringToHandle(300, 160, GetColor(204, 143, 81), FontHandle[1], "%d位です！！", rank);
	}
	DrawFormatStringToHandle(100, 200, GetColor(204, 143, 81), FontHandle[1], "ランキング");
	for (int i = 0; i < min(ShownRank, (int)ranking.size()); i++) {
		DrawFormatStringToHandle(96, 250 + i * 30, GetColor(204,143 ,81), FontHandle[1], "%2d位    %-20s : %d", ranking[i].rank, ranking[i].name.c_str(), ranking[i].score);
	}	
	for (int i = 0; i < min(ShownRank, (int)ranking.size()); i++) {
		if (name == ranking[i].name && score == ranking[i].score) {
			DrawBox(96, 250 + i * 30, 470, 270 + i * 30, GetColor(150, 113, 61), FALSE);
			break;
		}
	}

}

void Ranking::Sound()
{
	if (rank > ShownRank) {
		PlaySoundMem(SoundHundle[2], DX_PLAYTYPE_BACK);
	}
	else {
		if (rank == 1) PlaySoundMem(SoundHundle[0], DX_PLAYTYPE_BACK);
		else PlaySoundMem(SoundHundle[1], DX_PLAYTYPE_BACK);
	}
}



void Ranking::Finalize() {
	for (int i = 0; i < 3; i++)StopSoundMem(SoundHundle[i]);
	InitSoundMem();
	DeleteFontToHandle(FontHandle[1]);
}

void Ranking::nameSwap() {
	std::vector<RankInfo>::iterator buf1;
	for (auto it = ranking.begin(); it != ranking.end(); it++) {
		if (it->score == score) {
			buf1 = it;
			break;
		}
	}
	for (auto it = ranking.begin(); it != ranking.end(); it++) {
		if (it->score == score) {
			if (it->name == name) {
				swap(buf1->name, it->name);
				break;
			}
		}
	}
}
