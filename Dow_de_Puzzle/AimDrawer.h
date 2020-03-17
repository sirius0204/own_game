#pragma once
#include "Materials.h"
#include <vector>
#include <string>

#include <fstream> 
#include <sstream>

class AimDrawer
{
	int stage;
	std::vector<std::string> v[StageNum];

	void Draw(int stage, int h);

	std::string convert(int n);

public:
	AimDrawer();
	~AimDrawer();

	void Initialize();
	bool Update(int stage, int h);
	void Finalize();
};

