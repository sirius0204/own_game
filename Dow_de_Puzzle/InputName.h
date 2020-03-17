#pragma once
#include "DxLib.h"
#include "Materials.h"
#include <string>
#include <vector>
#include "Object.h"
#include <cassert>
#include "MyInput.h"
class InputName
{
	static const int kanaSize = 85;
	static const std::string kana[2][kanaSize];
	static const int mojisu = 10;
	int FontHandle[2]; //ƒtƒHƒ“ƒg
														 
	std::string name;
	std::vector<ObjBox> box;
	ObjBox enter, back, erase, shift;
	bool isUpper;
	bool isNameNG;

	void DrawObjBox(const ObjBox& box, int r, int g, int b, bool f = false);
public:
	InputName();
	~InputName();

	void Initialize();
	bool Upadate();
	void Draw();

	const std::string& getName() const;
};

