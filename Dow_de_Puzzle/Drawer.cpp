#include "Drawer.h"


Drawer::Drawer()
{
}


Drawer::~Drawer()
{
}

void Drawer::getNotAnimGraph(int idx, const std::string& path) {
	gimicH[idx][0] = LoadGraph(path.c_str());
	for (int i = 1; i < 4; i++) gimicH[idx][i] = gimicH[idx][0];
}

void Drawer::Initialize(const Vector2* _screen) {
	screen = _screen;
	
	mapchips[0] = -1;
	mapchips[1] = -1;
	mapchips[2] = LoadGraph("./resource/img/Map/grass_floor.png");
	mapchips[3] = LoadGraph("./resource/img/Map/house.png");
	mapchips[4] = LoadGraph("./resource/img/Map/kabochanobasha.png");
	mapchips[5] = LoadGraph("./resource/img/Map/snow_floor.png");
	mapchips[6] = LoadGraph("./resource/img/Map/tree2.png");
	mapchips[7] = LoadGraph("./resource/img/Map/toxicplant.png");
	mapchips[8] = LoadGraph("./resource/img/Map/boat.png");
	mapchips[9] = LoadGraph("./resource/img/Map/grass_floor2.png");
	mapchips[10] = LoadGraph("./resource/img/Map/grass_floor3.png");
	mapchips[11] = LoadGraph("./resource/img/Map/water.png");
	//使いまわし
	getNotAnimGraph(0, "");
	LoadDivGraph("./resource/img/Gimic/moveable_floor_left.png", 4, 4, 1, 48, 48, gimicH[1]);
	LoadDivGraph("./resource/img/Gimic/moveable_floor_right.png", 4, 4, 1, 48, 48, gimicH[2]);
	LoadDivGraph("./resource/img/Gimic/wooden_floor_3mas.png", 4, 1, 4, 144, 48, gimicH[3]);
	LoadDivGraph("./resource/img/Gimic/wooden_floor_vertical_3mas.png", 4, 4, 1, 48, 144, gimicH[4]);
	LoadDivGraph("./resource/img/Gimic/ladder_clear.png", 4, 4, 1, 46, 192, gimicH[7]);
	LoadDivGraph("./resource/img/Gimic/ladder_brownyellow.png", 4, 4, 1, 46, 192, gimicH[8]);
	getNotAnimGraph(44, "./resource/img/Map/tree2.png");
	LoadDivGraph("./resource/img/Gimic/bridge_off.png", 4, 1, 4, 144, 48, gimicH[58]);
	LoadDivGraph("./resource/img/Gimic/yajirushi4.png", 4, 4, 1, 32, 28, gimicH[59]);
	LoadDivGraph("./resource/img/Gimic/bridge.png", 4, 1, 4, 144, 48, gimicH[61]);
	LoadDivGraph("./resource/img/Gimic/fan_left.png", 4, 4, 1, 45, 50, gimicH[62]);
	getNotAnimGraph(63, "./resource/img/Gimic/barrier.png");
	LoadDivGraph("./resource/img/Gimic/fan_right.png", 4, 4, 1, 45, 50, gimicH[66]);
	LoadDivGraph("./resource/img/Gimic/wind.png", 4, 1, 4, 460, 46, gimicH[67]);
	//赤ずきん
	LoadDivGraph("./resource/img/Gimic/flower.png", 4, 4, 1, 48, 48, gimicH[10]);
	LoadDivGraph("./resource/img/Gimic/mushroom.png", 4, 4, 1, 96, 288, gimicH[11]);
	getNotAnimGraph(13, "./resource/img/Gimic/fire_off.png");
	LoadDivGraph("./resource/img/Gimic/fire_on.png", 4, 4, 1, 96, 144, gimicH[14]); 
	//桃太郎
	getNotAnimGraph(9, "./resource/img/Gimic/katana.png");
	getNotAnimGraph(21, "./resource/img/Gimic/peach.png");
	LoadDivGraph("./resource/img/Gimic/kiji_stop_left.png", 4, 4, 1, 64, 64, gimicH[22]);
	LoadDivGraph("./resource/img/Gimic/kiji_fly_left.png", 4, 4, 1, 64, 64, gimicH[23]);
	LoadDivGraph("./resource/img/Gimic/kiji_stop_right.png", 4, 4, 1, 64, 64, gimicH[24]);
	LoadDivGraph("./resource/img/Gimic/kiji_fly_right.png", 4, 4, 1, 64, 64, gimicH[25]);
	//豚
	getNotAnimGraph(45, "./resource/img/Gimic/wara.png");
	getNotAnimGraph(46, "./resource/img/Gimic/wood.png");
	LoadDivGraph("./resource/img/Gimic/house_01.png", 4, 4, 1, 144, 144, gimicH[47]);
	LoadDivGraph("./resource/img/Gimic/house_02.png", 4, 4, 1, 144, 144, gimicH[48]);
	LoadDivGraph("./resource/img/Gimic/house_03.png", 4, 4, 1, 144, 144, gimicH[49]);
	LoadDivGraph("./resource/img/Gimic/house_04.png", 4, 4, 1, 144, 144, gimicH[50]);
	LoadDivGraph("./resource/img/Gimic/apple2.png", 4, 4, 1, 30, 30, gimicH[51]);
	getNotAnimGraph(64, "./resource/img/Gimic/turnip.png");
	getNotAnimGraph(65, "./resource/img/Gimic/brick.png");
	
	//エネミー
	LoadDivGraph("./resource/img/Character/wolf.png", 4, 4, 1, 64, 64, enemyH[0]);
	LoadDivGraph("./resource/img/Character/wolf_burning.png", 4, 4, 1, 64, 64, enemyH[1]);
	LoadDivGraph("./resource/img/Character/inu.png", 4, 4, 1, 64, 64, enemyH[2]);
	LoadDivGraph("./resource/img/Character/oni.png", 4, 4, 1, 64, 64, enemyH[4]);
	LoadDivGraph("./resource/img/Character/brownwolf.png", 4, 4, 1, 64, 64, enemyH[5]);
	LoadDivGraph("./resource/img/Character/brownwolf_piyopiyo.png", 4, 4, 1, 64, 64, enemyH[6]);

	//フレンド
	LoadDivGraph("./resource/img/Character/akasan_2.png", 4, 4, 1, 64, 64, friendH[0]);
	LoadDivGraph("./resource/img/Character/akasan_put_off_1_left.png", 4, 4, 1, 64, 64, friendH[1]);
	LoadDivGraph("./resource/img/Character/akasan_put_off_1_right.png", 4, 4, 1, 64, 64, friendH[2]);
	LoadDivGraph("./resource/img/Character/akasan_1.png", 4, 4, 1, 64, 64, friendH[3]);
	LoadDivGraph("./resource/img/Character/akasan_put_off_0_left.png", 4, 4, 1, 64, 64, friendH[4]);
	LoadDivGraph("./resource/img/Character/akasan_put_off_0_right.png", 4, 4, 1, 64, 64, friendH[5]);
	LoadDivGraph("./resource/img/Character/akasan_0.png", 4, 4, 1, 64, 64, friendH[6]);
	LoadDivGraph("./resource/img/Character/momotaro.png", 4, 4, 1, 64, 64, friendH[7]);
	LoadDivGraph("./resource/img/Character/momotaro_ladder.png", 4, 4, 1, 64, 64, friendH[8]);
	LoadDivGraph("./resource/img/Character/momotaro_havingKatana.png", 4, 4, 1, 64, 64, friendH[9]);
	LoadDivGraph("./resource/img/Character/momotaro_havingKatana_ladder.png", 4, 4, 1, 64, 64, friendH[10]);
	LoadDivGraph("./resource/img/Character/buta.png", 4, 4, 1, 64, 64, friendH[11]);
	LoadDivGraph("./resource/img/Character/buta_ladder.png", 4, 4, 1, 64, 64, friendH[12]);
	LoadDivGraph("./resource/img/Character/saru.png", 4, 4, 1, 64, 64, friendH[13]);
	LoadDivGraph("./resource/img/Character/saru_ladder.png", 4, 4, 1, 64, 64, friendH[14]);
	LoadDivGraph("./resource/img/Character/buta_aura.png", 4, 4, 1, 64, 64, friendH[15]);
	LoadDivGraph("./resource/img/Character/buta_ascending_aura.png", 4, 4, 1, 64, 64, friendH[16]);

	//背景
	backgroundH[0] = LoadGraph("./resource/img/Background/forest.png");
	backgroundH[1] = LoadGraph("./resource/img/Background/bg_momotaro.png");
	backgroundH[2] = LoadGraph("./resource/img/Background/bg_buta.png");

	ButtonH[0] = LoadGraph("./resource/img/UI/help.png");
	ButtonH[1] = LoadGraph("./resource/img/UI/back.png");

	watchH[0] = LoadGraph("./resource/img/UI/watch_case.png");
	watchH[1] = LoadGraph("./resource/img/UI/watch_sandU.png");
	watchH[2] = LoadGraph("./resource/img/UI/watch_sandD.png");

	UIH[0] = LoadGraph("./resource/img/UI/start.png");
	UIH[1] = LoadGraph("./resource/img/UI/icon_animal.png");
	UIH[2] = LoadGraph("./resource/img/UI/circle.png");
	UIH[3] = LoadGraph("./resource/img/UI/life.png");
	UIH[4] = LoadGraph("./resource/img/UI/go.png");
	UIH[5] = LoadGraph("./resource/img/UI/clear.png");
	UIH[6] = LoadGraph("./resource/img/UI/stage1.png");
	UIH[7] = LoadGraph("./resource/img/UI/stage2.png");
	UIH[8] = LoadGraph("./resource/img/UI/stage3.png");
	UIH[9] = LoadGraph("./resource/img/UI/dead.png");
	UIH[10] = LoadGraph("./resource/img/UI/timeup.png");
	UIH[11] = LoadGraph("./resource/img/UI/arrow_1.png");
	UIH[12] = LoadGraph("./resource/img/UI/arrow_2.png");
	UIH[13] = LoadGraph("./resource/img/UI/arrow_3.png");
	UIH[14] = LoadGraph("./resource/img/UI/arrow_4.png");
	UIH[15] = LoadGraph("./resource/img/UI/skip.png");
	UIH[16] = LoadGraph("./resource/img/UI/messagebox.png");

	LPCSTR font_path = "./resource/Font/uzurafont100/uzurafont100/uzura.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	
	FontHandle[0] = CreateFontToHandle("Stencil", 25, 9);
	FontHandle[1] = CreateFontToHandle(font_path, 20, 9);
	FontHandle[2] = CreateFontToHandle(font_path, 15, 9);

	for (int i = 0; i < 10; i++) {
		std::string path = "./resource/img/UI/" + convert(i + 1) + ".png";
		LoadDivGraph(path.c_str(), 12, 4, 3, 100, 100, NumberH[i]);
	}
	std::string path = "./resource/dat/aim/";
	for (int i = 0; i < StageNum; i++) {
		std::ifstream input(path + convert(i) + ".txt");
		std::string tmp;
		while (input >> tmp) {
			aim[i].push_back(tmp);
		}
	}
	path = "./resource/dat/gimic/manual/";
	for (int i = 0; i <GimicMgr::eGimic::Size; i++) {
		std::ifstream input(path + convert(i) + ".txt");
		std::string tmp;
		while (input >> tmp) {
			gManual[i].push_back(tmp);
		}
	}

	path = "./resource/dat/gimic/manual/stage/";
	for (int i = 0; i < StageNum; i++) {
		std::ifstream input(path + convert(i) + ".txt");
		int tmp;
		while (input >> tmp) {
			manualGimics[i].push_back(tmp);
		}
	}

	path = "./resource/dat/tutorial/stage/";
	for (int i = 0; i < StageNum; i++) {
		path = "./resource/dat/tutorial/stage/" + convert(i) + "/";
		for (int j = 0; j < Tutorial::MaxStep; j++) {
			std::ifstream input(path + convert(j) + ".txt");
			if (!input) break;
			std::string tmp;
			while (input >> tmp) {
				tutorialS[i][j].push_back(tmp);
			}
		}

	}

	path = "./resource/img/Help/Gimic/";
	for (int i = 0; i < GimicMgr::eGimic::Size; i++) {
		helpgimicH[i] = LoadGraph((path + convert(i) + ".png").c_str());
	}

	soundFile[0] = LoadSoundMem("./resource/sound/SE/カウントダウン.ogg");
}

void Drawer::Draw(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int score, int cnt, int stage, int life) {
	if (stage / 4 == 0) DrawRotaGraph(672, 432, 1.4, 0.0, backgroundH[0], true);
	else if (stage / 4 == 1) DrawRotaGraph(672, 432, 1.4, 0.0, backgroundH[1], true);
	else if (stage / 4 == 2) DrawRotaGraph(672, 432, 1.4, 0.0, backgroundH[2], true);
	DrawMap(map, stage);
	DrawGimic(gimics);
	DrawAddition(enemys, friends, gimics, stage, cnt);
	DrawFriend(friends);
	DrawEnemy(enemys);
	DrawMinimap(map, friends, enemys, gimics);
	DrawUI(map, enemys, friends, gimics, score, cnt, life, stage);
	DrawHelp({ 700,150 });
	if (stage % 4 == 0)DrawSkip({ 810,650 });
}

void Drawer::Finalize() {
}

void Drawer::DrawMenue(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int score, int cnt, int stage, int life)
{
	DrawGraph(0, 0, backgroundH[stage / 4], true);
	DrawTime(cnt);
	DrawAim(stage);
	DrawUI(map, enemys, friends, gimics, score, cnt, life, stage);
	DrawBack({ 700,150 });

	DrawGimicManual(stage);
}

void Drawer::DrawTutorial(int stage, int step) const
{
	if (stage == 0 || stage == 8) {
		DrawGraph(46, 580, UIH[16], TRUE);
		for (int i = 0; i < tutorialS[stage][step].size(); i++) {
			DrawFormatStringToHandle(100, 600, GetColor(0, 0, 0), FontHandle[2], tutorialS[stage][step][i].c_str());
			//DrawFormatString(100, 600, GetColor(0, 0, 0), tutorialS[stage][step][i].c_str());
		}
	}
	if (stage == 4) {
		DrawGraph(46, 630, UIH[16], TRUE);
		for (int i = 0; i < tutorialS[stage][step].size(); i++) {
			DrawFormatStringToHandle(100, 650, GetColor(0, 0, 0), FontHandle[2], tutorialS[stage][step][i].c_str());
			//DrawFormatString(100, 650, GetColor(0, 0, 0), tutorialS[stage][step][i].c_str());
		}
	}
}

void Drawer::DrawStart(const ObjBox & start, int& cnt, int stage, bool isIntroScreen) const
{
	if (cnt < 60 || isIntroScreen)DrawGraph(start.getPoint().x - 100, start.getPoint().y - 50, UIH[5 + stage % 4], TRUE);
	else DrawGraph(start.getPoint().x, start.getPoint().y, UIH[0], TRUE);
	cnt++;
}

void Drawer::DrawGo(const ObjBox & start, int& cnt) const
{
	if (cnt < 60) {
		if (cnt < 30) {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(cnt * 2 + 60) / 60.0, 0, UIH[4], true);
		}
		else {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(120 - (cnt * 2 - 60)) / 60.0, 0, UIH[4], true);
		}
	}
	else {
		if (255 - (cnt - 60) * 2 > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (cnt - 60) * 2);
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, 1.0, 0, UIH[4], true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	cnt++;
}

void Drawer::DrawClear(const ObjBox & start, int& cnt) const
{
	if (cnt < 60) {
		if (cnt < 30) {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(cnt * 2 + 60) / 60.0, 0, UIH[5], true);
		}
		else {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(120 - (cnt * 2 - 60)) / 60.0, 0, UIH[5], true);
		}
	}
	else {
		if (255 - (cnt - 60) * 2 > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (cnt - 60) * 2);
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, 1.0, 0, UIH[5], true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	cnt++;
}

void Drawer::DrawDead(const ObjBox & start, int& cnt) const {
	if (cnt < 60) {
		if (cnt < 30) {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(cnt * 2 + 60) / 60.0, 0, UIH[9], true);
		}
		else {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(120 - (cnt * 2 - 60)) / 60.0, 0, UIH[9], true);
		}
	}
	else {
		if (255 - (cnt - 60) * 2 > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (cnt - 60) * 2);
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, 1.0, 0, UIH[9], true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	cnt++;
}

void Drawer::DrawTimeUp(const ObjBox & start, int& cnt) const {
	if (cnt < 60) {
		if (cnt < 30) {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(cnt * 2 + 60) / 60.0, 0, UIH[10], true);
		}
		else {
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, double(120 - (cnt * 2 - 60)) / 60.0, 0, UIH[10], true);
		}
	}
	else {
		if (255 - (cnt - 60) * 2 > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (cnt - 60) * 2);
			DrawRotaGraph(WinWidth / 2, WinHeight / 2, 1, 0, UIH[10], true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	cnt++;
};

void Drawer::DrawMap(const std::vector<std::vector<int>>& map,int stage)
{
	int sx = (-screen->x-Map::ChipEdge+1) / Map::ChipEdge, sy = (-screen->y-Map::ChipEdge+1) / Map::ChipEdge;	//画面左上のマップチップの番号
	int h = (FieldMaxY - FieldMinY) / Map::ChipEdge + 2;	//１画面に表示するマップチップの縦の個数
	int w = (FieldMaxX - FieldMinX) / Map::ChipEdge + 2;	//１画面に表示するマップチップの横の個数
	double dx = sx * Map::ChipEdge+screen->x, dy = sy * Map::ChipEdge+screen->y;	//左上のマップチップと描画画面のずれ
	for (signed i = 0; i < h; i++) {
		for (signed j = 0; j < w; j++) {
			if (sy + i < 0 || sx + j < 0 || sy + i >= map.size() || sx + j >= map[sy + i].size()) continue;
			DrawGraph(FieldMinX + dx + j*Map::ChipEdge, FieldMinY + dy + i*Map::ChipEdge, mapchips[map[sy + i][sx + j]], TRUE);
		}
	}
	if (stage == 1) {}
	else if (stage == 4) {
		DrawRotaGraph(FieldMinX + screen->x + 760, FieldMinY + screen->y + 540, 1.0, 0.0, mapchips[8], true);
		DrawRotaGraph(FieldMinX + screen->x + 48 + 70.4, FieldMinY + screen->y + 480 + 48.4, 2.2, 0.0, mapchips[3], true);
		DrawRotaGraph(FieldMinX + screen->x + 266, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 360, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[9], true);
	}
	else if (stage == 5) {
		DrawRotaGraph(FieldMinX + screen->x + 768, FieldMinY + screen->y + 730, 1.0, 0.0, mapchips[8], true);
		DrawRotaGraph(FieldMinX + screen->x + 48 + 70.4, FieldMinY + screen->y + 672 + 48.4, 2.2, 0.0, mapchips[3], true);
		DrawRotaGraph(FieldMinX + screen->x + 552, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 312, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 600, FieldMinY + screen->y + 601, 1.0, 0.0, mapchips[9], true);
	}
	else if (stage == 6) {
		DrawRotaGraph(FieldMinX + screen->x + 1230, FieldMinY + screen->y + 730, 1.0, 0.0, mapchips[8], true);
		DrawRotaGraph(FieldMinX + screen->x + 48 + 70.4, FieldMinY + screen->y + 672 + 48.4, 2.2, 0.0, mapchips[3], true);
		DrawRotaGraph(FieldMinX + screen->x + 792, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 168, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 552, FieldMinY + screen->y + 601, 1.0, 0.0, mapchips[9], true);
	}
	else if (stage == 7) {
		DrawRotaGraph(FieldMinX + screen->x + 1800, FieldMinY + screen->y + 730, 1.0, 0.0, mapchips[8], true);
		DrawRotaGraph(FieldMinX + screen->x + 48 + 70.4, FieldMinY + screen->y + 672 + 48.4, 2.2, 0.0, mapchips[3], true);
		DrawRotaGraph(FieldMinX + screen->x + 792, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 312, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[9], true);
		DrawRotaGraph(FieldMinX + screen->x + 1080, FieldMinY + screen->y + 601, 1.0, 0.0, mapchips[9], true);
	}
	else if (stage == 9) {
		DrawRotaGraph(FieldMinX + screen->x + 216, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[10], true);
		DrawRotaGraph(FieldMinX + screen->x + 552, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[10], true);
		DrawRotaGraph(FieldMinX + screen->x + 312, FieldMinY + screen->y + 601, 1.0, 0.0, mapchips[10], true);
	}
	else if (stage == 10) {
		DrawRotaGraph(FieldMinX + screen->x + 168, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[10], true);
		DrawRotaGraph(FieldMinX + screen->x + 888, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[10], true);
		DrawRotaGraph(FieldMinX + screen->x + 312, FieldMinY + screen->y + 601, 1.0, 0.0, mapchips[10], true);
	}
	else if (stage == 11) {
		DrawRotaGraph(FieldMinX + screen->x + 888, FieldMinY + screen->y + 217, 1.0, 0.0, mapchips[10], true);
		DrawRotaGraph(FieldMinX + screen->x + 744, FieldMinY + screen->y + 409, 1.0, 0.0, mapchips[10], true);
		DrawRotaGraph(FieldMinX + screen->x + 504, FieldMinY + screen->y + 601, 1.0, 0.0, mapchips[10], true);
	}
}

void Drawer::DrawEnemy(const std::vector<Enemy*>& enemys)
{
	for (Enemy* enemy : enemys) {
		if (enemy == NULL || enemy->getExist() == false) continue;
		
		DrawRotaGraph(FieldMinX + screen->x + enemy->getPoint().x+enemy->getWidth()/2.0, FieldMinY + screen->y + enemy->getPoint().y+enemy->getHeight()/2.0, 1.0, 0.0, enemyH[enemy->getId()][(enemy->getCount() / 30) % 4], TRUE, enemy->getDir());
	}
}

void Drawer::DrawFriend(const std::vector<Friend*>& friends)
{
	for (Friend* fre : friends) {
		if (fre == NULL || fre->getExist() == false) continue;

		DrawRotaGraph(FieldMinX + screen->x + fre->getPoint().x + fre->getWidth() / 2.0, FieldMinY + screen->y + fre->getPoint().y + fre->getHeight() / 2.0, 1.0, 0.0, friendH[fre->getId()][(fre->getCount() / 30) % 4], TRUE, fre->getDir() % 2);
	}
}

void Drawer::DrawUI(const std::vector<std::vector<int>>& map, const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int score, int cnt, int life, int stage)
{
	if (stage / 4 == 1) DrawGetAnimal(enemys, friends, gimics);
	DrawWatch(cnt);
	DrawScore(score);
	DrawLife(life);
	DrawMinimap(map, friends, enemys, gimics);
	DrawUIArrow();
}

void Drawer::DrawGimic(const std::vector<Gimic*>& gimics)
{
	for (Gimic* gimic : gimics) {
		if (gimic == NULL || gimic->getExist() == false) continue;
		/*DrawBox(FieldMinX + screen->x + gimic->getPoint().x, FieldMinY + screen->y + gimic->getPoint().y,
			FieldMinX + screen->x + gimic->getPoint().x + gimic->getWidth(), FieldMinY + screen->y + gimic->getPoint().y + gimic->getHeight(), GetColor(255, 0, 0), true);*/
		if (gimic->getId() == 11) {
			DrawRectGraph(FieldMinX + screen->x + gimic->getPoint().x , FieldMinY + screen->y + gimic->getPoint().y, 0, 0, gimic->getWidth(), gimic->getHeight() + 5, gimicH[11][(gimic->getCount() / 30) % 4], true,true);
		}
		else{
			DrawRotaGraph(FieldMinX + screen->x + gimic->getPoint().x + gimic->getWidth() / 2.0, FieldMinY + screen->y + gimic->getPoint().y + gimic->getHeight() / 2.0, 1.0 , 0.0, gimicH[gimic->getId()][(gimic->getCount() / 30) % 4], TRUE, 0);
		}
	}
}

void Drawer::DrawMinimap(const std::vector<std::vector<int>>& map, const std::vector<Friend*>& friends, const std::vector<Enemy*>& enemys, const std::vector<Gimic*>& gimics) {
	static const double per = (double)1 / 8; //縮尺

	static const int mx = 400, my = 40; //ミニマップの左上隅の位置
	static const int m_size = Map::ChipEdge * per; //マップチップ（正方形）の一辺の長さ

	unsigned int color;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 160);
	for (int i = 0; i < map.size(); i++) {			//マップの描画
		for (int j = 0; j < map[i].size(); j++) {
			color = GetMiniColor(map[i][j], 0);
			DrawFillBox(mx + j*m_size, my + i*m_size, mx + (j + 1)*m_size, my + (i + 1)*m_size, color);
		}
	}

	double cx, cy; //動くキャラ or ギミックの位置
	int cw, ch; //サイズ
	for (Friend* fre : friends) {
		if (!fre->getExist())continue;
		cx = fre->getPoint().x * per;
		cy = fre->getPoint().y * per;
		cw = fre->getWidth() * per;
		ch = fre->getHeight() * per;
		color = GetMiniColor(fre->getId(), 1);
		DrawFillBox(mx + cx, my + cy, mx + cx + cw, my + cy + ch, color);

	}

	for (Enemy* ene : enemys) {
		if (!ene->getExist())continue;
		cx = ene->getPoint().x * per;
		cy = ene->getPoint().y * per;
		cw = ene->getWidth() * per;
		ch = ene->getHeight() * per;
		color = GetMiniColor(ene->getId(), 2);
		DrawFillBox(mx + cx, my + cy, mx + cx + cw, my + cy + ch, color);

	}

	for (Gimic* gimic : gimics) {
		if (!gimic->getExist()) continue;
		if (gimic->getId() == 0 || gimic->getId() == 7) continue; //透明ギミックは除外
		cx = gimic->getPoint().x * per;
		cy = gimic->getPoint().y * per;
		cw = gimic->getWidth() * per;
		ch = gimic->getHeight() * per;
		color = GetMiniColor(gimic->getId(), 3);
		DrawFillBox(mx + cx, my + cy, mx + cx + cw, my + cy + ch, color);

	}
	for (int i = 0; i < 4; i++) {
		DrawBox(mx - i * 2 - 2, my - i * 2 - 2, mx + map[0].size()*m_size + i * 2 + 2, my + map.size()*m_size + i * 2 + 2, GetColor(133 + i * 20, 46 + i * 20, 25 + i * 20), FALSE);
	}

	DrawBox(mx + -screen->x * per, my + -screen->y * per, mx + (-screen->x + WinWidth) * per, my + (-screen->y + WinHeight) * per, GetColor(255, 0, 0), FALSE);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

int Drawer::GetMiniColor(int id, int type) {
	if (type == 0) { //マップ
		switch (id) {
		case 0: return GetColor(255, 255, 255);
		case 1: return GetColor(205, 133, 63);
		case 2: return GetColor(60, 179, 113);
		case 9: return GetColor(60, 179, 113);
		case 10: return GetColor(60, 179, 113);
		case 11: return GetColor(133, 133, 255);
		default: assert(!"不正なID");
		}
	}
	if (type == 1) { //フレンド
		switch (id) {
		case 0: return GetColor(201, 23, 30);
		case 1: return GetColor(201, 23, 30);
		case 2: return GetColor(201, 23, 30);
		case 3: return GetColor(250, 128, 114);
		case 4: return GetColor(250, 128, 114);
		case 5: return GetColor(139, 0, 0);
		case 6: return GetColor(139, 0, 0);
		case 7: return GetColor(238, 131, 111);
		case 8: return GetColor(238, 131, 111);
		case 9: return GetColor(72, 209, 204);
		case 10: return GetColor(72, 209, 204);
		case 11: return GetColor(77, 90, 175);
		case 12: return GetColor(77, 90, 175);
		case 13: return GetColor(113, 92, 31);
		case 14: return GetColor(113, 92, 31);
		case 15: return GetColor(77, 90, 175);
		case 16: return GetColor(77, 90, 175);
		/*case 17: return GetColor(113, 92, 31);
		case 18: return GetColor(113, 92, 31);
		case 19: return GetColor(113, 92, 31);
		case 20: return GetColor(113, 92, 31);
		case 21: return GetColor(113, 92, 31);
		case 22: return GetColor(113, 92, 31);
		case 23: return GetColor(113, 92, 31);
		case 24: return GetColor(113, 92, 31);
		case 25: return GetColor(113, 92, 31);
		case 26: return GetColor(113, 92, 31);
		case 27: return GetColor(139, 0, 0);
		case 28: return GetColor(139, 0, 0);*/
		default: assert(!"不正なID");
		}
	}

	if (type == 2) { //エネミー
		switch (id) {
		case 0: return GetColor(112, 128, 144);
		case 1: return GetColor(112, 128, 144);
		case 2: return GetColor(218, 165, 32);
		case 3: return GetColor(226, 4, 27);
		case 4: return GetColor(46, 41, 48);
		case 5: return GetColor(128, 128, 0);
		case 6: return GetColor(128, 128, 0);
		default: assert(!"不正なID");
		}
	}

	if (type == 3) { //ギミック
		switch (id) {
		case 1: return GetColor(107, 123, 110);
		case 2: return GetColor(107, 123, 110);
		case 3: return GetColor(149, 111, 41);
		case 4: return GetColor(149, 111, 41);
		case 5: return GetColor(149, 111, 41);
		case 6: return GetColor(149, 111, 41);
		case 7: return GetColor(200, 131, 127);
		case 8: return GetColor(150, 81, 77);
		case 9: return GetColor(136, 142, 126);
		case 10: return GetColor(230, 180, 34);
		case 11: return GetColor(208, 87, 107);
		case 12: return GetColor(150, 81, 77);
		case 13: return GetColor(111, 75, 62);
		case 14: return GetColor(234, 85, 6);
		case 15: return GetColor(183, 40, 46);
		case 16: return GetColor(25, 68, 142);
		case 17: return GetColor(0, 123, 67);
		case 18: return GetColor(183, 40, 46);
		case 19: return GetColor(25, 68, 142);
		case 20: return GetColor(0, 123, 67);
		case 21: return GetColor(244, 179, 194);
		case 22: return GetColor(131, 155, 92);
		case 23: return GetColor(131, 155, 92);
		case 24: return GetColor(184, 210, 0);
		case 25: return GetColor(181, 82, 51);
		case 26: return GetColor(188, 226, 232);
		case 27: return GetColor(235, 225, 169);
		case 28: return GetColor(226, 4, 27);
		case 29: return GetColor(136, 127, 122);
		case 30: return GetColor(136, 127, 122);
		case 31: return GetColor(136, 127, 122);
		case 32: return GetColor(136, 127, 122);
		case 33: return GetColor(136, 127, 122);
		case 34: return GetColor(136, 127, 122);
		case 35: return GetColor(136, 127, 122);
		case 36: return GetColor(44, 169, 225);
		case 37: return GetColor(44, 169, 225);
		case 38: return GetColor(62, 179, 112);
		case 39: return GetColor(62, 179, 112);
		case 40: return GetColor(233, 84, 107);
		case 41: return GetColor(233, 84, 107);
		case 42: return GetColor(136, 72, 152);
		case 43: return GetColor(136, 72, 152);
		case 44: return GetColor(105, 176, 118);
		case 45: return GetColor(189, 151, 35);
		case 46: return GetColor(136, 121, 75);
		case 47: return GetColor(77, 81, 57);
		case 48: return GetColor(77, 81, 57);
		case 49: return GetColor(77, 81, 57);
		case 50: return GetColor(77, 81, 57);
		case 51: return GetColor(139, 0, 0);
		case 52: return GetColor(74, 47, 182);
		case 53: return GetColor(74, 47, 182);
		case 54: return GetColor(198, 0, 28);
		case 55: return GetColor(198, 0, 28);
		case 56: return GetColor(0, 154, 87);
		case 57: return GetColor(0, 154, 87);
		case 58: return GetColor(255, 255, 255);
			//case 59: 
			//case 60: 
		case 61: return GetColor(223, 119, 4);
		case 62: return GetColor(97, 86, 66);
		case 63: return GetColor(104, 55, 34);
		case 64: return GetColor(186, 205, 49);
		case 65: return GetColor(112, 53, 50);
		case 66: return GetColor(97, 86, 66);
		case 67: return GetColor(204, 204, 255);
		default: assert(!"不正なID");
		}
	}
}

bool Drawer::isDrawableInMinimap(int id, int type) {
	if (type == 3 && id == 0) return false;
	if (type == 3 && id == 58) return false;
	if (type == 3 && id == 59) return false;
	if (type == 3 && id == 60) return false;
	return true;
}

void Drawer::DrawAim(int stage)
{
	for (int i = 0; i < aim[stage].size(); i++) {
		DrawFormatStringToHandle(128, 256 + i * 20, GetColor(0, 0, 0), FontHandle[1], "目的 : %s", aim[stage][i].c_str());
		//DrawFormatString(128, 256 + i * 20, GetColor(0, 0, 0), "目的 : %s", aim[stage][i].c_str());
	}
}

void Drawer::DrawHelp(const Vector2 & point)
{
	if (!(Input.getMousePoint().x >= point.x && Input.getMousePoint().x <= point.x + 200
		&& Input.getMousePoint().y >= point.y && Input.getMousePoint().y <= point.y + 50)) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 / 2);
	}
	DrawGraph(point.x, point.y, ButtonH[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Drawer::DrawBack(const Vector2 & point)
{
	DrawGraph(point.x, point.y, ButtonH[1], TRUE);
}

void Drawer::DrawSkip(const Vector2 & point) {
	DrawGraph(point.x, point.y, UIH[15], TRUE);
}

void Drawer::DrawUIArrow() {
	Vector2 mousePoint = Input.getMousePoint();
	for (int i = 0; i < 4; i++) {
		if (!(mousePoint.x >= UIArrowPosX[i] && mousePoint.x <= UIArrowPosX[i] + UIArrowWidth&&mousePoint.y >= UIArrowPosY[i] && mousePoint.y <= UIArrowPosY[i] + UIArrowHeight)) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 / 2);
		}
		DrawGraph(UIArrowPosX[i], UIArrowPosY[i], UIH[11 + i], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

void Drawer::DrawScore(int score)
{
	SetFontSize(100);
	DrawFormatStringToHandle(700, 64, GetColor(255, 0, 0), FontHandle[1], "Score : %6d", score);
	//DrawFormatString(700, 64, GetColor(255, 0, 0), "Score : %6d", score);
}

void Drawer::DrawLife(int life)
{
	for (int i = 0; i < life; i++) {
		//DrawBox(WinWidth - 48 * (i + 1) - 80, 90, WinWidth - 48 * i - 80, 138, GetColor(255, 255, 255), false);
		if (life <= 5)DrawGraph(680 + 48 * (i + 1) - 80, 90, UIH[3], true);
		else DrawGraph(680 + 24 * (i + 1) - 80, 90, UIH[3], true);
	}
	//DrawGraph(0, 0, gimicH[58][0], true);
}

void Drawer::DrawTime(int cnt)
{
	{
		int secondCnt = cnt - timeLimitSecond * 60;
		if (cnt == 0) return;
		//DrawFormatString(32, 160, GetColor(0, 255, 0), "time : %d 分 %d 秒", cnt / 3600, (cnt / 60) % 60);
		/*if (cnt < 60) DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d分 %d秒", timeLimitMinute, timeLimitSecond);
		else if (cnt < timeLimitSecond * 60) DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d分 %d秒", timeLimitMinute - cnt / 3600, timeLimitSecond - cnt / 60);
		else if ((secondCnt / 60) % 60 == 0) DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d分 %d秒", timeLimitMinute - secondCnt / 3600, 0);
		else DrawFormatStringToHandle(20, 176, GetColor(0, 0, 0), FontHandle[0], "%d分 %d秒", (timeLimitMinute - 1) - secondCnt / 3600, 60 - (secondCnt / 60) % 60);*/
	}
}

void Drawer::DrawWatch(int cnt)
{
	int secondCnt = cnt - timeLimitSecond * 60;

	DrawGraph(10, 10, watchH[0], TRUE);
	DrawRectGraph(10, 10 + 31 + cnt / (60 * 7), 0, cnt / (60 * 7), 68, 190 - cnt / (60 * 7), watchH[1], TRUE, FALSE);
	DrawRectGraph(10, 10 + 120 - cnt / (60 * 7), 0, 31 - cnt / (60 * 7), 68, cnt / (60 * 7), watchH[2], TRUE, FALSE);

	if (cnt >= (timeLimitMinute * 60 + timeLimitSecond) * 60)return;
	if (cnt >= (timeLimitMinute * 60 + timeLimitSecond - 10) * 60) {
		DrawGraph(0, 0, NumberH[9 - ((cnt - (timeLimitMinute * 60 + timeLimitSecond - 10) * 60) / 60)][(cnt / 5) % 12], true);
		if (cnt == (timeLimitMinute * 60 + timeLimitSecond - 10) * 60) PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK, true);
		return;
	}

	if (cnt < 60) DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d : %d", timeLimitMinute, timeLimitSecond);
	else if (cnt < timeLimitSecond * 60) DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d : %d", timeLimitMinute - cnt / 3600, timeLimitSecond - cnt / 60);
	else if ((secondCnt / 60) % 60 == 0) DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d : %d", timeLimitMinute - secondCnt / 3600, 00);
	else DrawFormatStringToHandle(20, 70, GetColor(0, 0, 0), FontHandle[0], "%d : %d", (timeLimitMinute - 1) - secondCnt / 3600, 60 - (secondCnt / 60) % 60);
}

void Drawer::DrawGimicManual(int stage)
{
	int k = -1;
	for (int i = 0; i < manualGimics[stage].size(); i++) {
		int ty = i / 8, tx = i % 8;
		//DrawFillBox_dbg(100 + tx * 64, 350 + ty * 64, 60, 60, GetColor(128, 128, 128));
		DrawBox(100 + tx * 64, 350 + ty * 64, 100 + tx * 64 + 60, 350 + ty * 64 + 60, GetColor(0,255,0),true);
		DrawGraph(100 + tx * 64, 350 + ty * 64, helpgimicH[manualGimics[stage][i]], TRUE);
		if (ObjBox({ 100.0 + tx * 64,350.0 + ty * 64 }, 60.0, 60.0).isHitPoint(Input.getMousePoint())) {
			k = i;
		}
	}
	if (k == -1) return;
	int tcnt = 0;
	for (std::string& str : gManual[manualGimics[stage][k]]) {
		DrawFormatStringToHandle(100, 500 + 20 * tcnt, GetColor(0, 0, 0), FontHandle[1], str.c_str());
		//DrawFormatString(100, 500 + 20 * tcnt, GetColor(0, 0, 0), str.c_str());
		tcnt++;
	}
}

void Drawer::DrawFillBox_dbg(int x, int y, int h, int w, unsigned int color)
{
	DrawBox(x, y, x + w, y + h, color, TRUE);
}

std::string Drawer::convert(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void Drawer::DrawAddition(const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics, int stage, int cnt) {
	if (stage == 4 || stage == 5 || stage == 6) {
		DrawGetAnimal(enemys, friends, gimics);
	}

	for (Gimic* gim : gimics) {
		if (gim->getExist() == false || gim == NULL)continue;
		//矢印
		if (gim->getId() == 22 || gim->getId() == 23 || gim->getId() == 24 || gim->getId() == 25
			|| gim->getId() == 45 || gim->getId() == 46 || gim->getId() == 65) {//きじ、わら、木、レンガ
			DrawGraph(GimPosYajirushi(gim).x, GimPosYajirushi(gim).y, gimicH[59][(cnt / 30) % 4], true);
		}
		else if(gim->getId() == 13)	DrawGraph(GimPosYajirushi(gim).x, GimPosYajirushi(gim).y + 30, gimicH[59][(cnt / 30) % 4], true);
		else if (gim->getId() == 14) {//薪が燃えているとき
			DrawGraph(GimPosYajirushi(gim).x, GimPosYajirushi(gim).y+30, gimicH[59][(cnt / 30) % 4], true);
			for (Enemy* ene : enemys) {
				if (ene->getExist() == false || ene == NULL)continue;
				DrawGraph(EnePosYajirushi(ene).x, EnePosYajirushi(ene).y, gimicH[59][(cnt / 30) % 4], true);
			}
		}
		//風
		if (gim->getId() == 62) {
			if (gim->getState() == 1) {
				SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
				DrawGraph(screen->x + gim->getPoint().x - WindWidth, screen->y + gim->getPoint().y, gimicH[67][(gim->getCount() / 30) % 4], true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
		}
		else if (gim->getId() == 66) {
			if (gim->getState() == 1) {
				SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
				DrawGraph(screen->x + gim->getPoint().x + gim->getWidth(), screen->y + gim->getPoint().y, gimicH[67][(gim->getCount() / 30) % 4], true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
		}
	}

	for (Friend* fre : friends) {
		if (fre->getExist() == false || fre == NULL)continue;
		//矢印
		if (fre->getId() == 0 || fre->getId() == 1 || fre->getId() == 2 || fre->getId() == 13 || fre->getId() == 14) {//サル、赤ずきん
			DrawGraph(FrePosYajirushi(fre).x, FrePosYajirushi(fre).y, gimicH[59][(cnt / 30) % 4], true);
		}
		//ふねのうえ
		std::bitset < Friend::eFriendState_St2::Size> bs = fre->getState();
		if (bs[Friend::eFriendState_St2::IsMomo]) {
			if (bs[Friend::eFriendState_St2::HaveAnimalNum1] && bs[Friend::eFriendState_St2::HaveAnimalNum2]) {
				DrawGraph(screen->x + 1800 - YajirushiWidth / 2, screen->y + 730 - BoatHeight / 2 - YajirushiHeight, gimicH[59][(cnt / 30) % 4], true);
			}
		}
		//いえのうえ
		if (fre->getId() == 7 || fre->getId() == 8) {
			int straw = fre->getHp() & 1023;
			int wood = (fre->getHp() & 1047552) >> 10;
			int brick = (fre->getHp() & 1072693248) >> 20;
			if (stage == 3) {
				if (straw + wood + brick >= HouseCount_3) {
					DrawGraph(screen->x + HouseMinX_3 + HouseWidth / 2 - YajirushiWidth / 2, screen->y + HouseMinY_3 - YajirushiHeight, gimicH[59][(cnt / 30) % 4], true);
				}
			}
			else if (stage == 8) {
				if (straw + wood + brick >= HouseCount_8) {
					DrawGraph(screen->x + HouseMinX_8 + HouseWidth / 2 - YajirushiWidth / 2, screen->y + HouseMinY_8 - YajirushiHeight, gimicH[59][(cnt / 30) % 4], true);
				}
			}
		}
	}
	for (Enemy* ene : enemys) {
		if (ene->getExist() == false || ene == NULL)continue;
		//矢印
		if (ene->getId() == 2) {//犬
			DrawGraph(EnePosYajirushi(ene).x, EnePosYajirushi(ene).y, gimicH[59][(cnt / 30) % 4], true);
		}
	}
	if (stage / 4 == 1)DrawGraph(192, 0, UiHundle[0], true);
}

Vector2 Drawer::GimPosYajirushi(const Gimic* gim) {
	return Vector2(gim->getPoint().x + gim->getWidth() / 2 - YajirushiWidth / 2 + screen->x, gim->getPoint().y - YajirushiHeight + screen->y);
}

Vector2 Drawer::EnePosYajirushi(const Enemy* ene) {
	return Vector2(ene->getPoint().x + ene->getWidth() / 2 - YajirushiWidth / 2 + screen->x, ene->getPoint().y - YajirushiHeight + screen->y);
}

Vector2 Drawer::FrePosYajirushi(const Friend* fre) {
	return Vector2(fre->getPoint().x + fre->getWidth() / 2 - YajirushiWidth / 2 + screen->x, fre->getPoint().y - YajirushiHeight + screen->y);
}

void Drawer::DrawGetAnimal(const std::vector<Enemy*>& enemys, const std::vector<Friend*>& friends, const std::vector<Gimic*>& gimics) {
	DrawGraph(192, 0, UIH[1], true);
	if (isGetDog(enemys)) {
		//DrawBox(192, 0, 192 + 48, 48, GetColor(255, 0, 0), false);
		DrawGraph(192, 0, UIH[2], true);
	}
	if (isGetMonkey(friends)) {
		//DrawBox(192 + 48, 0, 192 + 96, 48, GetColor(0, 255, 0), false);
		DrawGraph(192 + 48, 0, UIH[2], true);
	}
	if (isGetBird(gimics)) {
		//DrawBox(192 + 96, 0, 192 + 144, 48, GetColor(0, 0, 255), false);
		DrawGraph(192 + 96, 0, UIH[2], true);
	}
}

bool Drawer::isGetDog(const std::vector<Enemy*>& enemys) {
	for (Enemy* ene : enemys) {
		if (ene->getId() == 2) {
			if (ene->getExist() == false)return true;
			else return false;
		}
	}
	return true;
}

bool Drawer::isGetBird(const std::vector<Gimic*>& gimics) {
	for (Gimic* gim : gimics) {
		if (gim->getId() == 22 || gim->getId() == 23 || gim->getId() == 24 || gim->getId() == 25) {
			if (gim->getExist() == false)return true;
			else return false;
		}
	}
	return true;
}

bool Drawer::isGetMonkey(const std::vector<Friend*>& friends) {
	for (Friend* fre : friends) {
		if (fre->getId() == 13 || fre->getId() == 14) {
			if (fre->getExist() == false)return true;
			else return false;
		}
	}
	return true;
}
int Drawer::GetHundle() {
	return FontHandle[1];
}
