#include "DxLib.h"
#include"Material.h"
#include<assert.h>
#include"Input.h"

//キー長押し移動の防止策
/*struct KEY {
	bool isPush = false;
};
KEY up;
KEY down;
KEY space;*/

//プレイヤー
//Playerとブロック弾幕のグラフィックの定義
struct Player {
	int y;
	int kind; //種類 0->JK 1->かぐや姫 2->ヲタク
};

Player player;
void PlayerMove();//プレイヤーの移動
void PlayerShootBlock();//ブロック弾を発射
//void PlayerBulletShoot();
void PlayerAction();//プレイヤー行動制御

//エネミー
struct Enemy {
	int hp;
	int kind; //種類 0->JK 1->かぐや姫 2->ヲタク 3->ゾンビ 4->男子学生 5->リア充 6->トランプ 7->腐女子 8->ROM
};

Enemy enemy[enemy_num];
bool isEnemyExist(int num); //エネミーが消えるかどうか
void DropEnemy(int dropnum); //エネミーをだるま落とし
void CreatNextEnemy(int player_num, int create_num); //ネクストエネミーを作る
int PlayerLikeEnemy(int enemy_kind);//favする相手かblockする相手か
void EnemyShoot(); //エネミーが弾発射
void EnemyAction(); //エネミーの行動制御

//弾
//Player側の弾幕の初期化
struct PlayerBullet {
	int x;
	int y;
	int dx = 5;
	bool isAlive;
};

struct EnemyBullet
{
	int x, y;
	int dx = 5;
	int kind; // 0->favしたい 1->blockしたい
	int tweetkind; //どのツイートをするか
	bool isAlive;
};

PlayerBullet playerbullet[PLAYERBULLET_MAX];
EnemyBullet enemybullet[ENEMYBULLET_MAX];
bool CheckHitField(int x1, int x2);
bool CheckHit2(int x1, int y1, int x2, int y2);
void ShotExist();//弾の衝突判定
void BlockMove();//ブロック弾のムーブ
//void PlayerBullet_Move();
void EnemyBulletMove();//エネミー弾のムーブ
void ShotAction();//弾制御

//その他
void Score(int _score);//スコアの上下
//void Offset();//弾幕の相殺
void Floodgage(int _flood);//炎上ゲージ
void modeselect();//モードセレクト

struct Tweet {//DrawTweet用の構造体
	int cnt;//それぞれのレーンにあるエネミー弾の個数
	int enemy_kind;//誰が撃ってきたか
	int tweet_kind;//どの種類のツイートをしてきたか
};
Tweet tweet[enemy_num - 1];

//描画関数
void DrawBackground();//背景を描く
void DrawEnemy();//敵を描く
void DrawNextEnemy();//ネクストエネミーを描く
void DrawPlayer();//プレイヤーを描く
//void PlayerDraw();
//void PlayerBulletDraw();
void DrawPlayerBullet();//プレイヤー弾を描く
void DrawEnemyBullet();//エネミー弾を描く
void DrawFireGauge();//炎上ゲージを描く
void DrawTweet();//レーンの裏にtweetを表示
void DrawTime();//残り時間描画
void DrawScore();//スコア描画

void DrawStartScreen();//スタート画面描画
void DrawGameScreen();//ゲーム画面描画
void DrawResultScreen();//リザルト画面描画
void Draw();//全体の描画制御

//サウンド
void SoundMgr();//サウンドマネージャー

//初期化関数
void DrawerInitialize();//描画関連の初期化、1回の実行で一度しか呼び出さない
void SoundInitialize();//サウンド関連の初期化、毎ゲーム呼び出す
void Initialize();//ゲーム内変数初期化、毎ゲーム呼び出す

//おまじない、goUpdateKey()はInput.cppの関数を使うために必要
bool checkAll() {
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0;
}

//メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("");
	SetGraphMode(WinWidth, WinHeight, 16), ChangeWindowMode(TRUE);
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	ChangeFont("HGP行書体"); SetFontSize(36);

	DrawerInitialize();
	SoundInitialize();
	Initialize();

	while (checkAll()) {
		Draw();
		SoundMgr();
		if (scene == 0) {//タイトル画面
			if (!isModeselect) {//モードセレクト中でないなら
				if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					isModeselect = true;
				}
			}
			else {//モードセレクト中なら
				modeselect();
			}
		}
		else if (scene == 1) {//ゲーム画面
			if (getKeyPress(KEY_INPUT_ESCAPE, PRESS_ONCE)) {//escキーを押すとタイトル画面に戻る
				scene = 0;
				StopSoundMem(bgmH[1]);
				Initialize();
				SoundInitialize();
			}
			if (isRule) {//説明画面
				if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					isRule = false;
				}
			}
			else if (!isgamestart) {//スタート画面
				if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					isgamestart = true;
					SEflag[0] = true;
				}
			}
			else if (isgameend || isgameover) {//ゲームが終わったら
				endcnt++;
				if (endcnt >= min_endcnt && getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
					scene = 2;
					StopSoundMem(bgmH[1]);
				}
			}
			else {//ゲーム中
				cnt++;
				PlayerAction();
				EnemyAction();
				ShotAction();
				if (cnt == timelimit) {//タイムアップなら
					isgameend = true;
					SEflag[5] = true;
				}
				if (floodgage >= max_floodgage) {//炎上ゲージがmaxになったら
					isgameover = true;
					SEflag[8] = true;
				}
			}
		}
		else {//リザルト画面
			resultcnt++;
			if (isgameover && !CheckSoundMem(SEH[1]) && !isresultbgmend) {//ゲームオーバーの場合
				SEflag[1] = true;
				isresultbgmend = true;
			}
			else if (isgameend && !CheckSoundMem(SEH[10]) && !isresultbgmend) {//タイムアップの場合
				SEflag[10] = true;
				isresultbgmend = true;
			}
			if (resultcnt >= min_result && getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {//space連打でタイトルに戻るのを防ぐ
				for (int i = 0; i < SE_num; i++) {
					if (CheckSoundMem(SEH[i])) {
						StopSoundMem(SEH[i]);
					}
				}
				scene = 0;
				InitSoundMem();//毎ゲームの最後にサウンド関連で使ったメモリを解放する
				SoundInitialize();
			}
		}
	}

	DxLib_End();
	return 0;
}

//プレイヤー
void PlayerMove() {//プレイヤー移動

	if (getKeyPress(KEY_INPUT_UP, PRESS_ONCE)) {
		player.y--;
	}
	if (getKeyPress(KEY_INPUT_DOWN, PRESS_ONCE)) {
		player.y++;
	}
	//Playerの範囲設定
	player.y = max(min(player.y, 4), 0);
}

void PlayerShootBlock() {//プレイヤー弾発射


	if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
		if (cnt - player_shot_time >= player_shot_interval) {//弾の発射にインターバルを設けてるよ
			for (int i = 0; i < PLAYERBULLET_MAX; i++) {
				if (playerbullet[i].isAlive == true)continue;
				playerbullet[i].x = 165;
				playerbullet[i].y = player.y;
				playerbullet[i].isAlive = true;
				player_shot_time = cnt;
				break;
			}
			SEflag[9] = true;
		}
	}
}

void PlayerAction() {//プレイヤーの行動制御
	PlayerMove();
	PlayerShootBlock();
}

//エネミー
bool isEnemyExist(int num) {//エネミーが生きてるかどうか
	if (enemy[num].hp == 0) {
		if (PlayerLikeEnemy(enemy[num].kind) != 2)Score(300);//ROMじゃないなら
		SEflag[4] = true;
		return false;
	}
	return true;
}

void DropEnemy(int dropnum) {//だるま落とし
	for (int i = dropnum; i > 0; i--) {
		enemy[i] = enemy[i - 1];
	}
	enemy[0] = enemy[enemy_num - 1];
}

int PlayerLikeEnemy(int enemy_kind) {//0->blockしたい 1->favしたい 2->ROM
	if (player.kind == 0) {//プレイヤーがかぐや姫
		switch (enemy_kind) {
		case 1: return 1;
		case 2: return 0;
		case 3: return 0;
		case 4: return 1;
		case 5: return 1;
		case 6: return 1;
		case 7: return 1;
		case 8: return 2;
		}
	}
	else if (player.kind == 1) {//プレイヤーがJK
		switch (enemy_kind) {
		case 0: return 1;
		case 2: return 0;
		case 3: return 0;
		case 4: return 1;
		case 5: return 1;
		case 6: return 0;
		case 7: return 0;
		case 8: return 2;
		}
	}
	else {
		switch (enemy_kind) {//プレイヤーがヲタク
		case 0: return 0;
		case 1: return 0;
		case 3: return 1;
		case 4: return 0;
		case 5: return 0;
		case 6: return 0;
		case 7: return 1;
		case 8: return 2;
		}
	}
}

void CreatNextEnemy(int player_kind, int create_num) {//ネクストエネミーを作る
	int define_kind;
	enemy[create_num].hp = 3;
	while (1) {
		define_kind = GetRand(enemy_kind_num - 1);
		if (define_kind != player_kind)break;//プレイヤーと同じキャラにならないように
	}
	enemy[create_num].kind = define_kind;
}

void EnemyShoot() {//エネミー弾発射
	if (cnt % (20 * enemy_shot_interval[mode] + 40) == 0) {//エネミーの弾発射間隔を変える
		for (int i = 0; i < ENEMYBULLET_MAX; i++) {
			if (enemybullet[i].isAlive == true)continue;
			enemybullet[i].x = EnemyTeritory_x - shotsize;
			while (1) {
				int tmp = GetRand(enemy_num - 2);//誰が撃ってくるか決定
				if (enemy[tmp].kind != 8) {//ROMじゃなかったら
					enemybullet[i].y = tmp;
					enemybullet[i].kind = !(PlayerLikeEnemy(enemy[tmp].kind));
					int tweetkind = GetRand(2);//tweetの内容を3種類のなかから決定
					enemybullet[i].tweetkind = tweetkind;
					enemybullet[i].isAlive = true;
					tweet[tmp].cnt++;
					tweet[tmp].enemy_kind = enemy[tmp].kind;
					tweet[tmp].tweet_kind = tweetkind;
					break;
				}
			}
			SEflag[6] = true;
			break;
		}
	}
}

void EnemyAction() {//エネミーの行動制御
	for (int i = 0; i < enemy_num; i++) {
		if (!(isEnemyExist(i))) {
			DropEnemy(i);
			CreatNextEnemy(player.kind, enemy_num - 1);
		}
	}
	EnemyShoot();
}

//弾
bool CheckHitField(int x1, int x2)//player側がx
{
	if (x1 >= x2) {
		return true; //重なっていればtrueを返す
	}
	return false; //そうでなかったらfalseを返す
}

bool CheckHit2(int x1, int y1, int x2, int y2)//player側がx
{
	if (x1 >= x2 && y1 == y2)
	{
		return true; //重なっていればtrueを返す
	}
	else
	{
		return false; //そうでなかったらfalseを返す
	}
}

void ShotExist() {//弾の衝突判定
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		if (!(playerbullet[i].isAlive))continue;
		if (CheckHitField(playerbullet[i].x, EnemyTeritory_x)) {//相手に当たったら
			playerbullet[i].isAlive = false;
			if (PlayerLikeEnemy(enemy[playerbullet[i].y].kind) == 1) {//当たった相手が好きなら
				Score(-100);
				Floodgage(200);
			}
			else {//当たった相手が嫌いorROMなら
				enemy[playerbullet[i].y].hp--;
			}
			SEflag[2] = true;
		}
	}
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		if (!(enemybullet[i].isAlive))continue;
		if (CheckHitField(MyTeritory_x - shotsize, enemybullet[i].x)) {
			enemybullet[i].isAlive = false;
			if (enemybullet[i].kind == 0) {//favを受け取ったら
				if (enemybullet[i].y == player.y) {
					enemy[enemybullet[i].y].hp--;
					Score((3 - enemy[enemybullet[i].y].hp) * 100);
					SEflag[7] = true;
				}
			}
			else {//クソリプが自陣にはいったら
				Floodgage(100);
				SEflag[3] = true;
			}
			tweet[enemybullet[i].y].cnt--;
		}
	}
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		for (int j = 0; j < ENEMYBULLET_MAX; j++) {
			if (!(playerbullet[i].isAlive) || !(enemybullet[j].isAlive))continue;
			if (CheckHit2(playerbullet[i].x, playerbullet[i].y, enemybullet[j].x, enemybullet[j].y)) {//弾どうしの衝突
				playerbullet[i].isAlive = false;
				enemybullet[j].isAlive = false;
				tweet[enemybullet[j].y].cnt--;
				Score(10);
				SEflag[2] = true;
			}
		}
	}
}

void BlockMove() {//ブロック弾幕の移動
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		if (playerbullet[i].isAlive == false)continue;
		playerbullet[i].x += playerbullet[i].dx;
	}
}

void EnemyBulletMove() {//エネミー弾のムーブ
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		if (enemybullet[i].isAlive == false)continue;
		enemybullet[i].x -= enemybullet[i].dx;
	}
}

void ShotAction() {//弾の制御
	ShotExist();
	BlockMove();
	EnemyBulletMove();
}

//その他
void Score(int _score)//スコア追加
{
	score += _score * scorebonus[mode];//* (mode + 1) ;
}

void Floodgage(int _flood)//炎上ゲージ
{
	floodgage += _flood;
}

void modeselect() {//モードセレクト
	if (getKeyPress(KEY_INPUT_SPACE, PRESS_ONCE)) {
		scene = 1;
		mode = selectmode;
		Initialize();
		StopSoundMem(bgmH[0]);
		WaitTimer(1);
	}
	if (getKeyPress(KEY_INPUT_UP, PRESS_ONCE)) {
		selectmode = max(0, selectmode - 1);
		SEflag[11] = true;
	}
	if (getKeyPress(KEY_INPUT_DOWN, PRESS_ONCE)) {
		selectmode = min(2, selectmode + 1);
		SEflag[11] = true;
	}
}

//描画
void DrawBackground() {//背景描画
	DrawGraph(0, 0, map_gh, true);
}

void DrawEnemy() {//敵、good,dangeousアイコン、favblockカウント描画
	for (int i = 0; i < enemy_num - 1; i++) {
		DrawGraph(850, 100 + i * 95, CharactorH[enemy[i].kind], true);
		if (PlayerLikeEnemy(enemy[i].kind) != 2) {//ROMじゃなかったら
			DrawGraph(850, 100 + i * 95, favblockH[!PlayerLikeEnemy(enemy[i].kind)], true);
		}
		DrawGraph(965, 110 + i * 95, fbcntH[!(PlayerLikeEnemy(enemy[i].kind) == 1)], true);
		DrawFormatStringToHandle(975, 160 + i * 95, GetColor(0, 0, 0), FontH[0], "%d", 3 - enemy[i].hp);
	}
}


void DrawNextEnemy() {//ネクストエネミー、good,dangerousアイコン描画
	DrawGraph(800, 15, CharactorH[enemy[enemy_num - 1].kind], true);
	if (PlayerLikeEnemy(enemy[enemy_num - 1].kind) != 2) {//ROMじゃなかったら
		DrawGraph(800, 15, favblockH[!(PlayerLikeEnemy(enemy[enemy_num - 1].kind))], true);
	}
}

void DrawPlayer() {//Player、矢印アイコンの描画
	DrawGraph(175, 137 + player.y * 95, arrow_gh, true);
	DrawGraph(90, 100 + player.y * 95, CharactorH[player.kind], true);
}


void DrawPlayerBullet() {//PlayerBulletの描画
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		if (playerbullet[i].isAlive == false)continue;
		DrawGraph(playerbullet[i].x, 106 + 95 * playerbullet[i].y, playerbullet_gh, true);
	}
}

void DrawEnemyBullet() {//エネミー弾の描画
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		if (enemybullet[i].isAlive == false)continue;
		DrawGraph(enemybullet[i].x, 106 + 95 * enemybullet[i].y, enemybulletH[enemybullet[i].kind], true);
	}
}

void DrawFireGauge() {//炎上ゲージ描画
	DrawGraph(250, 48 - firegauge_y / 2, FireH[0], true);
	DrawRectGraph(251 + (firegauge_x / 10)*(floodgage / 100), 49 - firegauge_y / 2, (firegauge_x / 10)*(floodgage / 100), 0,
		firegauge_x - (firegauge_x / 10)*(floodgage / 100), firegauge_y, FireH[1], true, false);
}

void DrawTweet() {//レーンの裏にツイート描画
	for (int i = 0; i < enemy_num - 1; i++) {
		if (tweet[i].cnt == 0)continue;
		DrawGraph(MyTeritory_x, 97 + i * 95, tweetH[tweet[i].enemy_kind][tweet[i].tweet_kind], true);
	}
}

void DrawTime() {//残り時間の描画
	int time = timelimit - cnt;
	time = (time + 59) / 60;
	DrawFormatStringToHandle(737, 45, GetColor(255, 255, 255), FontH[0], "%d", time);
}

void DrawScore() {//スコアの描画
	DrawFormatStringToHandle(617, 45, GetColor(255, 255, 255), FontH[0], "%d", score);
}

void DrawStartScreen() {//スタート画面描画
	if (!isOPend) {//OPが終わってないなら
		PlayMovie("./img/ＯＰ.avi", 1, DX_MOVIEPLAYTYPE_NORMAL);
		if (GetMovieStateToGraph(openingH) == 0) {
			isOPend = true;
		}
	}
	else {//OPが終わったら
		DrawGraph(0, 0, titleH, true);
		if (isModeselect) {//モードセレクト中なら
			for (int i = 0; i < 3; i++) {
				DrawGraph(368, 56 + 170 * i, bottonH[i], true);
				DrawGraph(368 - 2, 56 + 170 * selectmode, modeflameH, true);
			}
		}
	}
}

void DrawGameScreen() {//ゲーム画面描画
	DrawBackground();
	DrawPlayer();
	DrawEnemy();
	DrawNextEnemy();
	DrawTweet();
	DrawPlayerBullet();
	DrawEnemyBullet();
	DrawFireGauge();
	DrawTime();
	DrawScore();
	if (!isgamestart)DrawGraph(0, 250, startH, true);//スタート前なら
	if (isgameend || isgameover)DrawGraph(0, 250, finishH, true);//ゲームがおわったら
	if (isRule)DrawGraph(0, 0, ruleH, true);//ルール説明中なら
}

void DrawResultScreen() {//リザルト画面描画
	DrawGraph(0, 0, resultH[isgameover], true);
	if (!isgameover) {//タイムアップなら最終スコア表示
		DrawGraph(WinWidth / 2 - 162, 25, resultscoreH, true);
		DrawFormatStringToHandle(WinWidth / 2 - GetDrawFormatStringWidthToHandle(FontH[1], "%d", score) / 2 - 5, 95, GetColor(0, 0, 0), FontH[1], "%d", score);
	}
}

void Draw() {
	if (scene == 0) {
		DrawStartScreen();
	}
	else if (scene == 1) {
		DrawGameScreen();
	}
	else {
		DrawResultScreen();
	}
}

//サウンド
void SoundMgr() {
	if (scene == 0) {
		ChangeVolumeSoundMem(122, bgmH[0]);
		if (istitlebgm == false) {
			PlaySoundMem(bgmH[0], DX_PLAYTYPE_LOOP, false);//ループ再生
			istitlebgm = true;
		}
	}
	else if (scene == 1) {
		ChangeVolumeSoundMem(122, bgmH[1]);
		if (isgamebgm == false) {
			PlaySoundMem(bgmH[1], DX_PLAYTYPE_LOOP, false);
			isgamebgm = true;
		}
	}

	for (int i = 0; i < SE_num; i++) {//SEflagが立ってたらそのSEを流す
		if (SEflag[i]) {
			PlaySoundMem(SEH[i], DX_PLAYTYPE_BACK, true);//バックグラウンド再生
			SEflag[i] = false;//flagを切る
		}
	}
}

//初期化関数
void DrawerInitialize() {//描画関連の初期化
	//グラフィックの読み込み
	openingH = LoadGraph("./img/ＯＰ.avi");
	titleH = LoadGraph("./img/OP.png");
	bottonH[0] = LoadGraph("./img/easy.png");
	bottonH[1] = LoadGraph("./img/normal.png");
	bottonH[2] = LoadGraph("./img/hard.png");
	modeflameH = LoadGraph("./img/mode_frame.png");
	map_gh = LoadGraph("./img/map 2.png");
	ruleH = LoadGraph("./img/rulerule.png");
	startH = LoadGraph("./img/start.png");
	finishH = LoadGraph("./img/finish.png");
	CharactorH[0] = LoadGraph("./img/kaguya.png");
	CharactorH[1] = LoadGraph("./img/jk.png");
	CharactorH[2] = LoadGraph("./img/wotaku.png");
	CharactorH[3] = LoadGraph("./img/zombie.png");
	CharactorH[4] = LoadGraph("./img/dk.png");
	CharactorH[5] = LoadGraph("./img/riaju.png");
	CharactorH[6] = LoadGraph("./img/trump.png");
	CharactorH[7] = LoadGraph("./img/fujoshi.png");
	CharactorH[8] = LoadGraph("./img/ROM.png");
	playerbullet_gh = LoadGraph("./img/block.png");
	enemybulletH[0] = LoadGraph("./img/fav.png");
	enemybulletH[1] = LoadGraph("./img/kusorep.png");
	arrow_gh = LoadGraph("./img/arrow.png");
	favblockH[0] = LoadGraph("./img/icon_good.png");
	favblockH[1] = LoadGraph("./img/icon_dangerous.png");
	fbcntH[0] = LoadGraph("./img/fav_mark.png");
	fbcntH[1] = LoadGraph("./img/block_mark.png");
	tweetH[0][0] = LoadGraph("./img/tweet/kaguya_t1.png");
	tweetH[0][1] = LoadGraph("./img/tweet/kaguya_t2.png");
	tweetH[0][2] = LoadGraph("./img/tweet/kaguya_t3.png");
	tweetH[1][0] = LoadGraph("./img/tweet/jk_t1.png");
	tweetH[1][1] = LoadGraph("./img/tweet/jk_t2.png");
	tweetH[1][2] = LoadGraph("./img/tweet/jk_t3.png");
	tweetH[2][0] = LoadGraph("./img/tweet/wotaku_t1.png");
	tweetH[2][1] = LoadGraph("./img/tweet/wotaku_t2.png");
	tweetH[2][2] = LoadGraph("./img/tweet/wotaku_t3.png");
	tweetH[3][0] = LoadGraph("./img/tweet/zombie_t1.png");
	tweetH[3][1] = LoadGraph("./img/tweet/zombie_t2.png");
	tweetH[3][2] = LoadGraph("./img/tweet/zombie_t3.png");
	tweetH[4][0] = LoadGraph("./img/tweet/dk_t1.png");
	tweetH[4][1] = LoadGraph("./img/tweet/dk_t2.png");
	tweetH[4][2] = LoadGraph("./img/tweet/dk_t3.png");
	tweetH[5][0] = LoadGraph("./img/tweet/riaju_t1.png");
	tweetH[5][1] = LoadGraph("./img/tweet/riaju_t2.png");
	tweetH[5][2] = LoadGraph("./img/tweet/riaju_t3.png");
	tweetH[6][0] = LoadGraph("./img/tweet/trump_t1.png");
	tweetH[6][1] = LoadGraph("./img/tweet/trump_t2.png");
	tweetH[6][2] = LoadGraph("./img/tweet/trump_t3.png");
	tweetH[7][0] = LoadGraph("./img/tweet/fujoshi_t1.png");
	tweetH[7][1] = LoadGraph("./img/tweet/fujoshi_t2.png");
	tweetH[7][2] = LoadGraph("./img/tweet/fujoshi_t3.png");
	FireH[0] = LoadGraph("./img/gauge_max.png");
	FireH[1] = LoadGraph("./img/gauge_frame 2.png");
	resultH[0] = LoadGraph("./img/result.png");
	resultH[1] = LoadGraph("./img/gameover.png");
	resultscoreH = LoadGraph("./img/result_score.png");
	//riaju_gh = LoadGraph("./img/riaju.png");
	//kusorip_gh = LoadGraph("./img/kusorep.png");

	LPCSTR font_path = "./Font/その他のファイル/TrueTypeフォント/03SmartFontUI.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {//フォント読み込み成功
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}

	FontH[0] = CreateFontToHandle(font_path, 30, 9);
	FontH[1] = CreateFontToHandle(font_path, 60, 9);
}

void SoundInitialize() {//サウンド関連の初期化
	bgmH[0] = LoadSoundMem("./sound/title.ogg");
	bgmH[1] = LoadSoundMem("./sound/main.ogg");
	SEH[0] = LoadSoundMem("./sound/SE/start.wav");
	SEH[1] = LoadSoundMem("./sound/SE/badresult.wav");
	SEH[2] = LoadSoundMem("./sound/SE/block.wav");
	SEH[3] = LoadSoundMem("./sound/SE/damage.wav");
	SEH[4] = LoadSoundMem("./sound/SE/delete.wav");
	SEH[5] = LoadSoundMem("./sound/SE/end.wav");
	SEH[6] = LoadSoundMem("./sound/SE/enemytweet.wav");
	SEH[7] = LoadSoundMem("./sound/SE/fav.wav");
	SEH[8] = LoadSoundMem("./sound/SE/gameover.wav");
	SEH[9] = LoadSoundMem("./sound/SE/playershot.wav");
	SEH[10] = LoadSoundMem("./sound/SE/result.wav");
	SEH[11] = LoadSoundMem("./sound/SE/select.wav");
}

void Initialize() {//ゲーム変数初期化
	player.y = 0;
	player.kind = mode;
	for (int i = 0; i < enemy_num; i++) {
		CreatNextEnemy(player.kind, i);
	}
	for (int i = 0; i < PLAYERBULLET_MAX; i++) {
		playerbullet[i].isAlive = false;
	}
	for (int i = 0; i < ENEMYBULLET_MAX; i++) {
		enemybullet[i].isAlive = false;
	}
	for (int i = 0; i < enemy_num - 1; i++) {
		tweet[i].cnt = 0;
	}
	for (int i = 0; i < SE_num; i++) {
		SEflag[i] = false;
	}

	cnt = 0;
	score = 0;
	floodgage = 0;
	selectmode = 0;
	endcnt = 0;
	resultcnt = 0;
	player_shot_time = -player_shot_interval;
	//-------------------
	//この辺をいじるとデバッグが楽になる
	isModeselect = false;
	isgamestart = false;
	isgameend = false;
	isOPend = false;
	isRule = true;
	isgameover = false;
	istitlebgm = false;
	isgamebgm = false;
	isresultbgmend = false;
	//-------------------
}
