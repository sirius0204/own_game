#pragma once
#include<iostream>
#include<DxLib.h>

//グローバル変数
const int WinWidth = 1024;
const int WinHeight = 576;

int scene;//0->スタート画面 1->ゲーム画面 2->リザルト画面
int cnt;//時間
const int timelimit = 1 * 60 * 60;//時間制限
int mode;//難易度　0->easy 1->normal 2->hard
int selectmode;//タイトル画面でのモード選択
int score;//スコア
const double scorebonus[3] = { 0.6,1,1.5 };
int floodgage = 0;//炎上ゲージ
const int max_floodgage = 1000;//ゲームオーバーになる炎上ゲージの値
int endcnt;//space連打防止用変数
const int min_endcnt = 1 * 60;//space連打防止用変数
int resultcnt;//space連打防止用変数
const int min_result = 1 * 60;//space連打防止用変数
//int blockcount = 0;//ブロックを数える
//int favcount = 0;//ファボを数える
bool isOPend;//OPがおわったかどうか
bool isModeselect;//モードセレクト中かどうか
bool isRule;//説明画面かどうか
bool isgamestart;//ゲームが始まったかどうか
bool isgameend;//ゲームが終わったかどうか
bool isgameover;//ゲームオーバーかどうか

//エネミーの変数
const int enemy_num = 6;//右に出てくるエネミー数+ネクストエネミー
const int enemy_kind_num = 9;//敵の種類数

//弾の変数
const int PLAYERBULLET_MAX = 10; //プレイヤーの弾の最大数
const int ENEMYBULLET_MAX = 5; //エネミーの弾の最大数
const int player_shot_interval = 30;//プレイヤーの弾発射間隔
int player_shot_time;//プレイヤーが弾発射した時間
const int enemy_shot_interval[3] = {3,2,1};//エネミーの弾発射間隔,easy,normal,hardの順
const int shotsize = 40;//弾の大きさ

//UI
const int firegauge_x = 330;//炎上ゲージの幅
const int firegauge_y = 35;//炎上ゲージの高さ
const int MyTeritory_x = 200; //自陣の右端
const int EnemyTeritory_x = 860;//敵陣の左端


//描画に関する変数
int openingH;//OP
int titleH;//タイトル画面
int bottonH[3];//モードセレクトボタン
int modeflameH;//モードセレクトのフレーム
int map_gh;//背景
int ruleH;//説明書
int startH;//スタート
int finishH;//フィニッシュ
int CharactorH[enemy_kind_num];//キャラクターの画像ハンドル
int playerbullet_gh;//プレイヤー弾
int enemybulletH[2];//エネミー弾の画像ハンドル
int arrow_gh;//矢印
int favblockH[2];//相手のgood,dangerousアイコン
int fbcntH[2];//相手のfav,block回数のアイコン
int tweetH[8][3];//tweet
int FireH[2];//炎上ゲージの画像ハンドル
int resultH[2];//リザルト画面
int resultscoreH;//リザルトのスコアの枠

int FontH[2];//読み込んだフォントのハンドル

//サウンドに関する変数
int bgmH[2];//bgm、resultのbgmはSEとしてる(1回しか流さないから)
const int SE_num = 12;//SEの個数
int SEH[SE_num];//SE
bool SEflag[SE_num];//SEを流すタイミングのフラグ
bool istitlebgm;//タイトルbgmが流れたかどうか
bool isgamebgm;//ゲームbgmが流れたかどうか
bool isresultbgmend;//result画面でbgmが終わったかどうか