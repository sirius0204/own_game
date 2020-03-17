#include "KeyConfig.h"


KeyConfig::KeyConfig()
{
	getKeyConf("./resource/KeyConfig.txt");
}


KeyConfig::~KeyConfig()
{
}


void KeyConfig::getKeyConf(const std::string& path) {
	std::ifstream in(path);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < eInputSize; j++) {
			in >> input[i][j];
		}
	}
}

void KeyConfig::setKeyConf(const std::string& path) {
	std::ofstream out(path);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < eInputSize; j++) {
			out << input[i][j] << " ";
		}
		out << std::endl;
	}
}

int KeyConfig::getKey(eInputType type, eInputKnd knd) {
	return input[type][knd];
}

void KeyConfig::setKey(eInputType type, eInputKnd knd, int KeyCode) {
	input[type][knd] = KeyCode;
}

