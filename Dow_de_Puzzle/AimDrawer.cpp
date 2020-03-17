#include "AimDrawer.h"



void AimDrawer::Draw(int stage, int h)
{
	if (stage / 4 != 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 133);
		DrawBox(240, 400, 820, 460, GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 133);
		DrawBox(240, 400, 670, 460, GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	DrawFormatStringToHandle(250, 410, GetColor(80, 50, 20), h, "クリア目標");
	//DrawFormatString(280, 410, GetColor(0, 0, 0), "クリア目標");
	for (int i = 0; i < v[stage].size(); i++) {
		DrawFormatStringToHandle(290, 436 + i * 16, GetColor(80, 50, 20), h, "%s", v[stage][i].c_str());
		//DrawFormatString(320, 426 + i * 16, GetColor(0, 0, 0), "%s", v[stage][i].c_str());
	}
}

std::string AimDrawer::convert(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

AimDrawer::AimDrawer()
{
}


AimDrawer::~AimDrawer()
{
}

void AimDrawer::Initialize()
{
	std::string path = "./resource/dat/aim/";
	for (int i = 0; i < StageNum; i++) {
		std::fstream input(path + convert(i) + ".txt");
		std::string tmp;
		v[i].clear();
		while (input >> tmp) {
			v[i].push_back(tmp);
		}
	}
}

bool AimDrawer::Update(int stage, int h)
{
	Draw(stage, h);
	return true;
}

void AimDrawer::Finalize()
{
}
