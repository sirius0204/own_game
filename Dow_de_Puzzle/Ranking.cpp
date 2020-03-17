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
	std::ifstream input(inputPath + convert(GameMgr::getStage() / 4) + ".txt");		//�����L���O�̓���
	std::ifstream inputScore(inputScorePath  + ".txt");		//����̃v���C�̃X�R�A��ǂݎ��
	inputScore >> score;
	int rankNum;		//�ۑ�����Ă��郉���L���O�̌�
	input >> rankNum;
	for (int i = 0; i < rankNum; i++) {
		RankInfo tmp;
		input >> tmp.score >> tmp.name;
		tmp.rank = 0;
		ranking.push_back(tmp);
	}
	ranking.push_back(RankInfo( score,name,-1 ));	//����̃v���C��ǉ�
	std::sort(ranking.begin(), ranking.end());		//�����L���O���X�R�A���Ƀ\�[�g
	nameSwap();

	rank = 1;
	ranking[0].rank = 1;
	//���ʂ�����
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
	std::ofstream output(outputPath + convert(GameMgr::getStage() / 4) + ".txt", std::ios::trunc);	//���ʂ��e�L�X�g�t�@�C���ɏo��
	output << min(HadRank, (int)ranking.size()) << std::endl;
	for (int i = 0; i < min(HadRank, (int)ranking.size()); i++) {
		output << ranking[i].score << " " << ranking[i].name << std::endl;
	}
	output.close();

	SoundHundle[0] = LoadSoundMem("./resource/sound/bgm/���U���g��ʁ`�p�[�t�F�N�g�`.ogg");
	SoundHundle[1] = LoadSoundMem("./resource/sound/bgm/���U���g��ʁ`�m���}�N���A�`.ogg");
	SoundHundle[2] = LoadSoundMem("./resource/sound/bgm/���U���g��ʁ`�m���}���s�`.ogg");

	LPCSTR font_path = "./resource/Font/uzurafont100/uzurafont100/uzura.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}

	FontHandle[1] = CreateFontToHandle(font_path, 15, 9);

	bgH[0] = LoadGraph("./resource/img/Background/result.png");

}

void Ranking::Draw()
{
	DrawGraph(0, 0, bgH[0],TRUE);
	DrawFormatStringToHandle(100, 100, GetColor(204, 143, 81), FontHandle[1], "%15s�̃X�R�A�� %d", name.c_str(),score);
	DrawFormatStringToHandle(120, 130, GetColor(204, 143, 81), FontHandle[1], "%15s�̏��ʂ́A",name.c_str());
	if (rank > HadRank) {
		DrawFormatStringToHandle(300, 160, GetColor(204, 143, 81), FontHandle[1], "���O�ł�");
	}
	else {
		DrawFormatStringToHandle(300, 160, GetColor(204, 143, 81), FontHandle[1], "%d�ʂł��I�I", rank);
	}
	DrawFormatStringToHandle(100, 200, GetColor(204, 143, 81), FontHandle[1], "�����L���O");
	for (int i = 0; i < min(ShownRank, (int)ranking.size()); i++) {
		DrawFormatStringToHandle(96, 250 + i * 30, GetColor(204,143 ,81), FontHandle[1], "%2d��    %-20s : %d", ranking[i].rank, ranking[i].name.c_str(), ranking[i].score);
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
