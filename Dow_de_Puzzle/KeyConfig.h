#pragma once

#include "DxLib.h"
#include "enum.h"

#include <string>
#include <fstream>


//�L�[�R�[�h���t�@�C������擾�E�ݒ肷��
class KeyConfig
{
	static const int eInputSize = eInput_End;
	int input[2][eInputSize];
public:
	KeyConfig();
	~KeyConfig();

	void getKeyConf(const std::string& path);
	void setKeyConf(const std::string& path);

	int getKey(eInputType type, eInputKnd knd);
	void setKey(eInputType type, eInputKnd knd, int KeyCode);
};

