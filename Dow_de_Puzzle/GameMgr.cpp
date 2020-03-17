#include "GameMgr.h"
#include "Tutorial.h"


int GameMgr::stage = 0;

std::string convert(int n) {
	std::stringstream ss;
	ss << n;
	return ss.str();
}

GameMgr::GameMgr()
{
}


GameMgr::~GameMgr()
{
}

void GameMgr::ChangeStage(int _stage)
{
	stage = _stage;
}

int GameMgr::getStage()
{
	return stage;
}

void GameMgr::Initialize() {
	score =0;
	cnt = 0;
	life = 10;
	drawer.Initialize(&screen);
	map.Initialize(stage);

	enemyMgr.Initialize(stage);
	friendMgr.Initialize(stage);
	gimicMgr.Initialize(stage);

	tutorial.Initialize(stage);

	ad.Initialize();

	isMenuScreen = false;
	isTutorial = true;
	isGamestart = false;
	for (int i = 0; i < Drawer::ePict_cntType::Size; i++)Pict_cnt[i] = 0;
	ClearFlag = false;
	isDead = false;
	isTimeUp = false;
	isIntroScreen = true;
	ScreenDir = 0;
	ScreenCnt = 0;
	help = ObjBox({ 700, 150 }, 32, 128);
	start = { { 480-100,360-25 },50,200 };
	skip = ObjBox{ {810,650},32,128 };

	if (stage / 4 == 0)	PlaySoundFile("./resource/sound/bgm/赤ずきんステージ（修正版2）.ogg", DX_PLAYTYPE_LOOP);
	else if (stage / 4 == 1) PlaySoundFile("./resource/sound/bgm/桃太郎ステージ.ogg", DX_PLAYTYPE_LOOP);
	else if (stage / 4 == 2) PlaySoundFile("./resource/sound/bgm/３匹の子豚ステージ.ogg", DX_PLAYTYPE_LOOP);

	std::ifstream input("./resource/dat/screen/stage/" + convert(stage) + ".txt");
	input >> screen.x >> screen.y >> screenMin.x >> screenMin.y >> screenMax.x >> screenMax.y;

	screenStart = screen;

	soundFile[0] = LoadSoundMem("./resource/sound/SE/スタート.ogg");
	soundFile[1] = LoadSoundMem("./resource/sound/SE/ゲームクリア.ogg");
	soundFile[2] = LoadSoundMem("./resource/sound/SE/ゲームオーバー.ogg");
	soundFile[3] = LoadSoundMem("./resource/sound/SE/タイムアップ.ogg");
}

bool GameMgr::Update() {
	/*for (Friend* fre : friends) {
		printfDx("%lf,%lf", )
	}*/
	soundMgr.Update(gimicMgr.getGimics(), friendMgr.getFriends(), enemyMgr.getEnemys(), screen);
	if (isTutorial) {
		if (!tutorial.Update(enemyMgr.getEnemys(), friendMgr.getFriends(), gimicMgr.getGimics(), screen, score)) {
			isTutorial = false;
			map.Finalize();
			enemyMgr.Finalize();
			friendMgr.Finalize();
			gimicMgr.Finalize();
			score = 0;
			stage++;
			map.Initialize(stage);
			enemyMgr.Initialize(stage);
			friendMgr.Initialize(stage);
			gimicMgr.Initialize(stage);

			std::ifstream input("./resource/dat/screen/stage/" + convert(stage) + ".txt");
			input >> screen.x >> screen.y >> screenMin.x >> screenMin.y >> screenMax.x >> screenMax.y;

			return true;
		}

		collider.Update(friendMgr.getFriends(), enemyMgr.getEnemys(), gimicMgr.getGimics(), stage, score, life);

		if (tutorial.isRungimic()) gimicMgr.Update(enemyMgr.getEnemys(), friendMgr.getFriends(), screen, score);
		if (tutorial.isRunEnemy()) enemyMgr.Update(map);
		if (tutorial.isRunFriend()) friendMgr.Update(map);
		//if (tutorial.isRunSoundmgr()) soundMgr.Update(gimicMgr.getGimics(), friendMgr.getFriends(), enemyMgr.getEnemys(), screen);
		drawer.Draw(map.getMap(), enemyMgr.getEnemys(), friendMgr.getFriends(), gimicMgr.getGimics(), score, cnt, stage, life);
		drawer.DrawTutorial(stage, tutorial.getStep());

		if (Input.getMousePressLeftOnce() && skip.isHitPoint(Input.getMousePoint())) {
			isTutorial = false;
			map.Finalize();
			enemyMgr.Finalize();
			friendMgr.Finalize();
			gimicMgr.Finalize();
			score = 0;
			stage++;
			map.Initialize(stage);
			enemyMgr.Initialize(stage);
			friendMgr.Initialize(stage);
			gimicMgr.Initialize(stage);

			std::ifstream input("./resource/dat/screen/stage/" + convert(stage) + ".txt");
			input >> screen.x >> screen.y >> screenMin.x >> screenMin.y >> screenMax.x >> screenMax.y;
		}
		
		if (stage % 4 == 0)isTutorial = true;
		else if (stage % 4 != 0)isTutorial = false;
	}
	else {
		if (!isGamestart) {
			if (isIntroScreen) {
				IntroScreen();
			}
			else {
				moveScreen();
				if (Input.getMousePressLeftOnce() && start.isHitPoint(Input.getMousePoint())) {
					isGamestart = true;
					PlaySoundMem(soundFile[0], DX_PLAYTYPE_BACK, true);
				}
			}
			drawer.Draw(map.getMap(), enemyMgr.getEnemys(), friendMgr.getFriends(), gimicMgr.getGimics(), score, cnt, stage, life);
			drawer.DrawStart(start, Pict_cnt[Drawer::ePict_cntType::StageStart], stage, isIntroScreen);
			ad.Update(stage,drawer.GetHundle());
		}
		else if (!isMenuScreen) {
			if (life == 0) isDead = true;
			if (cnt >= TimeLimit) isTimeUp = true;
			cnt++;
			collider.Update(friendMgr.getFriends(), enemyMgr.getEnemys(), gimicMgr.getGimics(), stage, score, life);
			gimicMgr.Update(enemyMgr.getEnemys(), friendMgr.getFriends(), screen, score);
			enemyMgr.Update(map);
			friendMgr.Update(map);
			moveScreen();
			drawer.Draw(map.getMap(), enemyMgr.getEnemys(), friendMgr.getFriends(), gimicMgr.getGimics(), score, cnt, stage, life);
			drawer.DrawGo(start, Pict_cnt[Drawer::ePict_cntType::GO]);
			if (ClearFlag) {
				drawer.DrawClear(start, Pict_cnt[Drawer::ePict_cntType::Clear]);
			}
			if (isDead) {
				if(CheckSoundMem(soundFile[2])==0)PlaySoundMem(soundFile[2], DX_PLAYTYPE_BACK, true);
				if (255 - (Pict_cnt[Drawer::ePict_cntType::Dead] - 60) * 2 <= 0) {
					StopSoundFile();
					InitSoundMem();

					pd.time[stage] = cnt;
					pd.stage = stage;
					pd.life = life;
					pd.score = score;

					outputScore();
					
					return false;
				}
				else {
					drawer.DrawDead(start, Pict_cnt[Drawer::ePict_cntType::Dead]);
					for (Friend *fre : friendMgr.getFriends())fre->setDir(3);
					for (Enemy *ene : enemyMgr.getEnemys())ene->setDir(3);
				}
			}
			if (isTimeUp) {
				if (CheckSoundMem(soundFile[3]) == 0)PlaySoundMem(soundFile[3], DX_PLAYTYPE_BACK, true);
				if (255 - (Pict_cnt[Drawer::ePict_cntType::TimeUp] - 60) * 2 <= 0) {
					StopSoundFile();
					InitSoundMem();
					PlaySoundMem(soundFile[3], DX_PLAYTYPE_BACK, true);
					
					pd.time[stage] = cnt;
					pd.stage = -stage;
					pd.life = life;
					pd.score = score;

					outputScore();
					return false;
				}
				else {
					drawer.DrawTimeUp(start, Pict_cnt[Drawer::ePict_cntType::TimeUp]);
				}
			}
			if (isClear()) {
				ClearFlag = true;
				if (CheckSoundMem(soundFile[1]) == 0)PlaySoundMem(soundFile[1], DX_PLAYTYPE_BACK, true);
				if (255 - (Pict_cnt[Drawer::ePict_cntType::Clear] - 60) * 2 <= 0 && Pict_cnt[Drawer::ePict_cntType::Clear] != 0) {
					TimeBonus();
					LifeBonus();
					getFinalScore(stage);
					StopSoundFile();
					InitSoundMem();

					pd.time[stage] = cnt;
					pd.stage = stage;
					pd.life = life;
					pd.score = score;

					outputScore();


					return false;
				}
			}
			else if (isClearStage()) {
				ClearFlag = true;
			}
			if (ClearFlag) {
				if (CheckSoundMem(soundFile[1]) == 0)PlaySoundMem(soundFile[1], DX_PLAYTYPE_BACK, true);
				if (255 - (Pict_cnt[Drawer::ePict_cntType::Clear] - 60) * 2 <= 0 && Pict_cnt[Drawer::ePict_cntType::Clear] != 0) {
					TimeBonus();
					getFinalScore(stage);
					map.Finalize();
					enemyMgr.Finalize();
					friendMgr.Finalize();
					gimicMgr.Finalize();
					StopSoundFile();

					pd.time[stage] = cnt;

					stage++;
					if (stage / 4 == 0) PlaySoundFile("./resource/sound/bgm/赤ずきんステージ（修正版2）.ogg", DX_PLAYTYPE_LOOP);
					else if (stage / 4 == 1) PlaySoundFile("./resource/sound/bgm/桃太郎ステージ.ogg", DX_PLAYTYPE_LOOP);
					else if (stage / 4 == 2) PlaySoundFile("./resource/sound/bgm/３匹の子豚ステージ.ogg", DX_PLAYTYPE_LOOP);
					map.Initialize(stage);
					enemyMgr.Initialize(stage);
					friendMgr.Initialize(stage);
					gimicMgr.Initialize(stage);
					std::ifstream input("./resource/dat/screen/stage/" + convert(stage) + ".txt");
					input >> screen.x >> screen.y >> screenMin.x >> screenMin.y >> screenMax.x >> screenMax.y;
					isGamestart = false;
					for (int i = 0; i < Drawer::ePict_cntType::Size; i++)Pict_cnt[i] = 0;
					ClearFlag = false;
					isIntroScreen = true;
					ScreenDir = 0;
					ScreenCnt = 0;
					screenStart = screen;
					cnt = 0;
				}
				else {
					for (Friend *fre : friendMgr.getFriends())fre->setDir(3);
					for (Enemy *ene : enemyMgr.getEnemys())ene->setDir(3);
				}
			}
			if (cnt > 10) {
				moveScreen();
			}
		}
		else {
			drawer.DrawMenue(map.getMap(), enemyMgr.getEnemys(), friendMgr.getFriends(), gimicMgr.getGimics(), score, cnt, stage, life);
		}

		if (Input.getMousePressLeftOnce() && help.isHitPoint(Input.getMousePoint())) {
			isMenuScreen = !isMenuScreen;
		}
	}
	return true;
}

void GameMgr::Finalize() {
	enemyMgr.Finalize();
	friendMgr.Finalize();
}

void GameMgr::moveScreen()
{
	if (Input.getMousePressLeft()) {
		screen += Input.getMousePoint() - mousePoint;
		screen += Input.getMousePoint() - mousePoint;
		screen.x = min(screen.x, screenMax.x);
		screen.y = min(screen.y, screenMax.y);
		screen.x = max(screen.x, screenMin.x);
		screen.y = max(screen.y, screenMin.y);
	}
	mousePoint = Input.getMousePoint();
	for (int i = 0; i < 4; i++) {
		if (mousePoint.x >= UIArrowPosX[i] && mousePoint.x <= UIArrowPosX[i] + UIArrowWidth&&mousePoint.y >= UIArrowPosY[i] && mousePoint.y <= UIArrowPosY[i] + UIArrowHeight) {
			if (Input.getMousePressLeft()) {
				switch (i)
				{
				case 0://上
					screen.y += 5;
					break;
				case 1://下
					screen.y -= 5;
					break;
				case 2://左
					screen.x += 5;
					break;
				case 3://右
					screen.x -= 5;
					break;
				default:
					break;
				}
			}
		}
	}
}


void GameMgr::outputScore()
{
	std::ofstream output("./resource/dat/score/score.txt", std::ios::trunc);
	output << score << std::endl;

	pd.outPut();
}

bool GameMgr::isClear()
{
	return ((stage == 3 || stage == 7 || stage == 11) && isClearStage());
}

bool GameMgr::isClearStage()
{
	if (stage != 0 && stage / 4 == 0)  return isKOallWolf();
	else if (stage == 5) return isReadyToFight(670, 704);
	else if (stage == 6) return isReadyToFight(1160, 704); 
	else if (stage == 7) return isReadyToFight(1730, 704);
	else if (stage == 9) return isAbleToBuild(2, 400, 704);
	else if (stage == 10) return isAbleToBuild(4, 644, 704);
	else if (stage == 11) return isAbleToBuild(5, 884, 704);
	return false;
}

bool GameMgr::isKOallWolf()//赤ずきんクリア条件
{
	for (Enemy* enemy : enemyMgr.getEnemys()) {
		if (enemy != NULL && enemy->getExist()) return false;
	}
	return true;
}


bool GameMgr::isReadyToFight(int x, int y) {
	for (Friend* fre : friendMgr.getFriends()) {
		std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
		if (friendstate[Friend::eFriendState_St2::IsMomo]) {
			//printfDx("%lf,%lf\n", fre->getPoint().x, fre->getPoint().y);
		}
		return friendstate[Friend::eFriendState_St2::HaveAnimalNum1]
			&& friendstate[Friend::eFriendState_St2::HaveAnimalNum2]
			&& fabs(x - fre->getPoint().x) < 10 && fabs(y - fre->getPoint().y) < 10;
	}
}

bool GameMgr::isAbleToBuild(int min, int x, int y) {//豚クリア条件
	for (Friend* fre : friendMgr.getFriends()) {
		int straw = fre->getHp() & 1023;
		int wood = (fre->getHp() & 1047552)>>10;
		int brick = (fre->getHp() & 1072693248)>>20;
		if (straw + wood + brick < min) return false;
		return isHitArea(x, y, fre);
	}
	return true;
}

bool GameMgr::isFinishedWork(int x, int y) {//白雪姫クリア
	for (Friend* fre : friendMgr.getFriends()) {
		if (!isHitArea(x, y, fre))return false;
		if (fre->getState() != 1) return false;
	}
	return true;
}

bool GameMgr::isExit(int x, int y) {//シンデレラクリア条件
	for (Friend* fre : friendMgr.getFriends()) {
		return isHitArea(x, y, fre);
	}
	return true;
}

bool GameMgr::isHitArea(int x, int y, Friend* fre) {
	static const int DIST = 5;
	return ((x - fre->getPoint().x)*(x - fre->getPoint().x) <= DIST*DIST) && ((y - fre->getPoint().y)*(y - fre->getPoint().y) <= DIST*DIST);
}

void GameMgr::IntroScreen() {
	if (stage % 4 != 1) {
		if (ScreenDir == 0) {
			if (screen.x < screenMax.x || screen.y < screenMax.y) {
				if (screen.x < screenMax.x)screen.x += 5;
				if (screen.y < screenMax.y)screen.y += 5;
			}
			else {
				ScreenDir = 1;
			}
		}
		else if (ScreenDir == 1) {//画面右移動
			screen.x -= ScrollSpeed;
			screen.x = max(screen.x, screenMin.x);
			if (fabs(screen.x - screenMin.x) < 10) {
				ScreenDir = 2;
			}
		}
		else if (ScreenDir == 2) {//画面下移動
			screen.y -= ScrollSpeed;
			screen.y = max(screen.y, screenMin.y);
			if (fabs(screen.y - screenMin.y) < 10) {
				ScreenDir = 3;
			}
		}
		else if (ScreenDir == 3) {//画面左移動
			screen.x += ScrollSpeed;
			screen.x = min(screen.x, screenMax.x);
			if (fabs(screen.x - screenMax.x) < 10) {
				ScreenDir = 4;
			}
		}
		else if (ScreenDir == 4) {//画面上移動
			screen.y += ScrollSpeed;
			screen.y = min(screen.y, screenMax.y);
			if (fabs(screen.y - screenMax.y) < 10) {
				ScreenDir = 5;
			}
		}
		else {
			if (fabs(screen.y - screenStart.y) > 10 || fabs(screen.x - screenStart.x) > 10) {
				if (fabs(screen.y - screenStart.y) > 10) {
					if (screen.y > screenStart.y)screen.y -= 5;
					else screen.y += 5;
				}
				if (fabs(screen.x - screenStart.x) > 10) {
					if (screen.x > screenStart.x)screen.x -= 5;
					else screen.x += 5;
				}
				screen.x = min(screen.x, screenMax.x);
				screen.y = min(screen.y, screenMax.y);
				screen.x = max(screen.x, screenMin.x);
				screen.y = max(screen.y, screenMin.y);
			}
			else {
				isIntroScreen = false;
			}
		}
	}
	else {
		if (stage == 1) {
			if (ScreenDir == 0) {
				if (fabs(screen.y - screenMin.y) > 10)screen.y -= ScrollSpeed;
				else ScreenDir = 1;
			}
			else if (ScreenDir == 1) {
				if (fabs(screen.y - screenMax.y) > 10)screen.y += ScrollSpeed;
				else isIntroScreen = false;
			}
		}
		else {
			if (ScreenDir == 0) {
				if (fabs(screen.y - screenMax.y) > 10)screen.y += ScrollSpeed;
				else ScreenDir = 1;
			}
			else if (ScreenDir == 1) {
				if (fabs(screen.y - screenMin.y) > 10)screen.y -= ScrollSpeed;
				else isIntroScreen = false;
			}
		}
	}
}

void GameMgr::getFinalScore(int _stage) {

	if (_stage / 4 == 2) { // 三匹の子豚ステージの場合
		static const int HOUSE_SCORE[] = { 2000, 1800, 1600, 1600, 1500,
			1400, 1400, 1300, 1200, 1100,
			1200, 1100, 1000,  900,  800 }; //各家パターンに対するスコア
		for (Gimic* gim : gimicMgr.getGimics()) {
			if (gim->getId() < 47 || gim->getId() > 50) continue; // 家以外のギミックは無視
			int h_num = (gim->getId() - 47) * 4 + (gim->getCount() / 30); // 家のパターン番号所得
			assert(h_num > 0 && "家が建ってない状態でクリア判定");
			score += HOUSE_SCORE[h_num - 1]; //家の出来映えによってスコアを加算。
		}
		return;
	}

}

void GameMgr::TimeBonus() {
	if (stage == 1) {
		if (cnt <= 30 * 60)score += 1000;
		else score += (1000 / (3 * 60)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 2) {
		if (cnt <= 30 * 60)score += 2000;
		else score += (2000 / (3 * 60)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 3) {
		if (cnt <= 50 * 60)score += 3000;
		else score += (3000 / (2 * 60 + 40)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 5) {
		if (cnt <= 20 * 60)score += 1000;
		else score += (1000 / (3 * 60 + 10)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 6) {
		if (cnt <= 30 * 60)score += 2000;
		else score += (2000 / (3 * 60)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 7) {
		if (cnt <= 60 * 60)score += 3000;
		else score += (3000 / (2 * 60 + 30)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 9) {
		if (cnt <= 20 * 60)score += 1000;
		else score += (1000 / (3 * 60 + 10)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 10) {
		if (cnt <= 40 * 60)score += 2000;
		else score += (2000 / (2 * 60 + 50)) * ((TimeLimit - cnt) / 60);
	}
	else if (stage == 11) {
		if (cnt <= 40 * 60)score += 3000;
		else score += (3000 / (2 * 60 + 30) + 50) * ((TimeLimit - cnt) / 60);
	}
}

void GameMgr::LifeBonus() {
	score += life * 400;
}