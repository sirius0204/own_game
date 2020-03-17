#pragma once
#include "DxLib.h"

#define PI			3.14159265359

const int WinWidth = 960;//640 * 1.5;
const int WinHeight = 720;// 480 * 1.5;


const int FieldMinX = 0;
const int FieldMinY = 0;
const int FieldMaxX = WinWidth;
const int FieldMaxY = WinHeight;

const double EPS = 0.01;

const double MapHeight[12] = { 10, 18, 18, 18, 14, 18, 18, 18, 10, 18, 18, 18 };
const double MapWidth[12] = { 17, 18, 27, 40, 18, 18, 28, 40, 17, 18, 28, 40 };

const int YajirushiWidth = 32;
const int YajirushiHeight = 28;

const int BoatWidth = 127;
const int BoatHeight = 90;
const int BoatPosX[3] = { 768,1200,1800 };

const int HouseCount_3 = 4;
const int HouseMinX_3 = 864;
const int HouseMinY_3 = 624;
const int HouseWidth = 144;
const int HouseHeight = 144;

const int HouseCount_8 = 5;
const int HouseMinX_8 = 624;
const int HouseMinY_8 = 624;

const int WindWidth = 460;

const int UIArrowWidth = 64;
const int UIArrowHeight = 64;

const double UIArrowPosX[4] = { WinWidth / 2 - UIArrowWidth / 2, WinWidth / 2 - UIArrowWidth / 2, 0, WinWidth - UIArrowWidth };
const double UIArrowPosY[4] = { 0, WinHeight - UIArrowHeight, WinHeight / 2 - UIArrowHeight / 2, WinHeight / 2 - UIArrowHeight / 2 };

const int StageNum = 12;
