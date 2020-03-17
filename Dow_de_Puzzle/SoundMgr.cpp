#include "SoundMgr.h"


SoundMgr::SoundMgr()
{
	Initialize();
}


SoundMgr::~SoundMgr()
{
	Finalize();
}

void SoundMgr::Initialize(){
	//bgm
	//SoundHundle[eSound::Aka] = LoadSoundMem("./resource/sound/bgm/赤ずきんステージ（修正版）.ogg");
	//SoundHundle[eSound::Momo] = LoadSoundMem("./resource/sound/bgm/桃太郎ステージ.ogg");
	//SoundHundle[eSound::Buta] = LoadSoundMem("./resource/sound/bgm/３匹の子豚ステージ.ogg");

	//gimic
	SoundHundle[eSound::apple] = LoadSoundMem("./resource/sound/SE/リンゴ落下.ogg");
	SoundHundle[eSound::barrior] = LoadSoundMem("./resource/sound/SE/障害物破壊音（刀っぽくない気がします）.ogg");
	SoundHundle[eSound::bird_habataki] = LoadSoundMem("./resource/sound/SE/はばたき（仮）.ogg");
	SoundHundle[eSound::bird_get] = LoadSoundMem("./resource/sound/SE/スイッチオン.ogg");
	SoundHundle[eSound::bridge] = LoadSoundMem("./resource/sound/SE/クリック.ogg");
	SoundHundle[eSound::collection] = LoadSoundMem("./resource/sound/SE/物を持つ音.ogg");
	SoundHundle[eSound::fan] = LoadSoundMem("./resource/sound/SE/扇風機の音.ogg");
	SoundHundle[eSound::flower] = LoadSoundMem("./resource/sound/SE/スコアアップ、スピードアップ音.ogg");
	SoundHundle[eSound::kabu] = LoadSoundMem("./resource/sound/SE/スコアアップ、スピードアップ音.ogg");
	SoundHundle[eSound::ladder] = LoadSoundMem("./resource/sound/SE/クリック.ogg"); 
	SoundHundle[eSound::movefloor] = LoadSoundMem("./resource/sound/SE/クリック.ogg");
	SoundHundle[eSound::mushroom_nobiru] = LoadSoundMem("./resource/sound/SE/キノコ伸びる第２案.ogg");
	SoundHundle[eSound::mushroom_tijimu] = LoadSoundMem("./resource/sound/SE/キノコ縮む.ogg");
	SoundHundle[eSound::peach] = LoadSoundMem("./resource/sound/SE/スコアアップ、スピードアップ音.ogg");
	SoundHundle[eSound::spinfloor_open] = LoadSoundMem("./resource/sound/SE/ドア開ける.ogg");
	SoundHundle[eSound::spinfloor_close] = LoadSoundMem("./resource/sound/SE/ドア閉める２.ogg");
	SoundHundle[eSound::stove_ignition] = LoadSoundMem("./resource/sound/SE/点火.ogg");
	SoundHundle[eSound::stove_burn] = LoadSoundMem("./resource/sound/SE/焼ける音（短）.ogg");
	SoundHundle[eSound::sword] = LoadSoundMem("./resource/sound/SE/物を持つ音.ogg");
	SoundHundle[eSound::turn] = LoadSoundMem("./resource/sound/SE/クリック.ogg");

	std::fill(isMove, isMove + eSound::Size, false);
}

void SoundMgr::Finalize(){
	InitSoundMem();
}

void SoundMgr::Update(std::vector<Gimic*> gimics, std::vector<Friend*> friends, std::vector<Enemy*> enemys, Vector2 screen){
	std::fill(isMove, isMove + eSound::Size, false);
	for (Gimic* gim : gimics){
		if (gim->getExist() == false || gim == NULL) continue;
		if (gim->getId() == 51){//apple
			if (Input.getMousePressLeftOnce()) {
				if (gim->isHitPoint(Input.getMousePoint() - screen)) {
					if (gim->getState() == 0) {
						PlaySoundMem(SoundHundle[eSound::apple], DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (gim->getId() == 63){//barrior
			for (Friend* fre : friends) {
				std::bitset<Friend::eFriendState_St2::Size> bs(fre->getState());
				if (bs[Friend::eFriendState_St2::IsSword] && gim->isHitBox(*fre)) {
					PlaySoundMem(SoundHundle[eSound::barrior], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 22 || gim->getId() == 23 || gim->getId() == 24 || gim->getId() == 25){//bird
			if (gim->getId() == 23 || gim->getId() == 25){
				if (CheckSoundMem(SoundHundle[eSound::bird_habataki]) == 0){
					PlaySoundMem(SoundHundle[eSound::bird_habataki], DX_PLAYTYPE_BACK);
				}
			}
			else{
				StopSoundMem(SoundHundle[eSound::bird_habataki]);
			}
			for (Friend* fre : friends) {
				if (fre->isHitBox(*gim)) {
					std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
					if (friendstate[Friend::eFriendState_St2::IsMomo]) {
						StopSoundMem(SoundHundle[eSound::bird_habataki]);
						PlaySoundMem(SoundHundle[eSound::bird_get], DX_PLAYTYPE_BACK, true);
					}
				}
			}
		}
		else if (gim->getId() == 58 || gim->getId() == 61){//bridge
			if (Input.getMousePressLeftOnce()) {
				if (gim->isHitPoint(Input.getMousePoint() - screen)) {
					PlaySoundMem(SoundHundle[eSound::bridge], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 45 || gim->getId() == 46 || gim->getId() == 65){//collection(brick,wara,wood)
			for (Friend* fre : friends) {
				if (gim->isHitBox(*fre)) {
					PlaySoundMem(SoundHundle[eSound::collection], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 62 || gim->getId() == 66){//fan
			if (gim->getState() == 1){
				isMove[eSound::fan] = true;
			}
		}
		else if (gim->getId() == 10){//flower
			for (Friend* fre : friends) {
				if (gim->isHitBox(*fre)) {
					PlaySoundMem(SoundHundle[eSound::flower], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 64){//kabu
			for (Friend* fre : friends) {
				if (gim->isHitBox(*fre)) {
					PlaySoundMem(SoundHundle[eSound::kabu], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 7 || gim->getId() == 8) {//ladder
			if (Input.getMousePressLeftOnce()) {
				if (gim->isHitPoint(Input.getMousePoint() - screen)) {
					if (!isProcess(friends, gim)) {//梯子通過中でなければ
						PlaySoundMem(SoundHundle[eSound::ladder], DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (gim->getId() == 1 || gim->getId() == 2) {//movefloor
			if (Input.getMousePressLeftOnce()) {
				if (gim->isHitPoint(Input.getMousePoint() - screen)) {
					PlaySoundMem(SoundHundle[eSound::movefloor], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 11){//mushroom
			if (gim->getState() == 0) {
				if (Input.getMousePressLeftOnce()) {
					if (gim->isHitPoint(Input.getMousePoint() - screen)) {
						PlaySoundMem(SoundHundle[eSound::mushroom_nobiru], DX_PLAYTYPE_BACK);
					}
				}
			}
			else if (gim->getState() == 2) {
				if (Input.getMousePressLeftOnce()) {
					if (gim->isHitPoint(Input.getMousePoint() - screen)) {
						PlaySoundMem(SoundHundle[eSound::mushroom_tijimu], DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (gim->getId() == 21){//peach
			for (Friend* fre : friends) {
				std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
				if (friendstate[Friend::eFriendState_St2::IsMomo]) {
					if (gim->isHitBox(*fre)) {
						PlaySoundMem(SoundHundle[eSound::peach], DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (gim->getId() == 3 || gim->getId() == 4){//spinfloor
			if (Input.getMousePressLeftOnce()) {
				if (gim->isHitPoint(Input.getMousePoint() - screen)) {
					PlaySoundMem(SoundHundle[eSound::spinfloor_open + gim->getState()], DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (gim->getId() == 13 || gim->getId() == 14){//stove
			if (gim->getState() == 1) {
				//printfDx("%d\n", gim->getCount());
				if (gim->getCount() == 59) {
					PlaySoundMem(SoundHundle[eSound::stove_ignition], DX_PLAYTYPE_BACK);
				}
			}
			else if (gim->getState() == 2) {
				for (Enemy* enemy : enemys) {
					if (gim->isHitBox(*enemy) && enemy->getState() == 0) {
						if (!CheckSoundMem(SoundHundle[eSound::stove_burn])) {
							PlaySoundMem(SoundHundle[eSound::stove_burn], DX_PLAYTYPE_BACK);
						}
					}
				}
			}
		}
		else if (gim->getId() == 9){//sword
			for (Friend * fre : friends) {
				std::bitset<Friend::eFriendState_St2::Size> friendstate(fre->getState());
				if (friendstate[Friend::eFriendState_St2::IsMomo]){
					if (gim->isHitBox(*fre)) {
						PlaySoundMem(SoundHundle[eSound::sword], DX_PLAYTYPE_BACK);
					}
				}
			}
		}
	}
	for (Friend* fre : friends) {
		if (fre->isHitPoint(Input.getMousePoint() - screen)) {
			if (Input.getMousePressLeftOnce()) {
				PlaySoundMem(SoundHundle[eSound::turn], DX_PLAYTYPE_BACK);
			}
		}
	}
	if (isMove[eSound::fan]){
		if (!CheckSoundMem(SoundHundle[eSound::fan])){
			PlaySoundMem(SoundHundle[eSound::fan], DX_PLAYTYPE_LOOP);
		}
	}
	else{
		StopSoundMem(SoundHundle[eSound::fan]);
	}
}

bool SoundMgr::isProcess(std::vector<Friend*> friends, Gimic* gim) {
	for (Friend* fre : friends) {
		if (fre->getExist() == false)continue;
		if (gim->isHitBox(*fre))return true;
	}
	return false;
}

//void SoundMgr::Play(int eSound_Num,int PlayType){
//	switch (eSound_Num){
//	case eSound::apple:
//		PlaySoundMem(SoundHundle[eSound::apple], PlayType);
//		break;
//	case eSound::barrior:
//		PlaySoundMem(SoundHundle[eSound::barrior], PlayType);
//		break;
//	case eSound::bird_get:
//		PlaySoundMem(SoundHundle[eSound::bird_get], PlayType);
//		break;
//	case eSound::bird_habataki:
//		PlaySoundMem(SoundHundle[eSound::bird_habataki], PlayType);
//		break;
//	case eSound::bridge:
//		PlaySoundMem(SoundHundle[eSound::bridge], PlayType);
//		break;
//	case eSound::collection:
//		PlaySoundMem(SoundHundle[eSound::collection], PlayType);
//		break;
//	case eSound::fan:
//		PlaySoundMem(SoundHundle[eSound::fan], PlayType);
//		break;
//	case eSound::flower:
//		PlaySoundMem(SoundHundle[eSound::flower], PlayType);
//		break;
//	case eSound::kabu:
//		PlaySoundMem(SoundHundle[eSound::kabu], PlayType);
//		break;
//	case eSound::mushroom_nobiru:
//		PlaySoundMem(SoundHundle[eSound::mushroom_nobiru], PlayType);
//		break;
//	case eSound::mushroom_tijimu:
//		PlaySoundMem(SoundHundle[eSound::mushroom_tijimu], PlayType);
//		break;
//	case eSound::peach:
//		PlaySoundMem(SoundHundle[eSound::peach], PlayType);
//		break;
//	case eSound::spinfloor_close:
//		PlaySoundMem(SoundHundle[eSound::spinfloor_close], PlayType);
//		break;
//	case eSound::spinfloor_open:
//		PlaySoundMem(SoundHundle[eSound::spinfloor_open], PlayType);
//		break;
//	case eSound::stove_burn:
//		PlaySoundMem(SoundHundle[eSound::stove_burn], PlayType);
//		break;
//	case eSound::stove_ignition:
//		PlaySoundMem(SoundHundle[eSound::stove_ignition], PlayType);
//		break;
//	case eSound::sword:
//		PlaySoundMem(SoundHundle[eSound::sword], PlayType);
//		break;
//	defalut:
//		break;
//	}
//}
//
//void SoundMgr::Stop(int eSound_Num){
//	switch (eSound_Num){
//	case eSound::apple:
//		StopSoundMem(SoundHundle[eSound::apple]);
//		break;
//	case eSound::barrior:
//		StopSoundMem(SoundHundle[eSound::barrior]);
//		break;
//	case eSound::bird_get:
//		StopSoundMem(SoundHundle[eSound::bird_get]);
//		break;
//	case eSound::bird_habataki:
//		StopSoundMem(SoundHundle[eSound::bird_habataki]);
//		break;
//	case eSound::bridge:
//		StopSoundMem(SoundHundle[eSound::bridge]);
//		break;
//	case eSound::collection:
//		StopSoundMem(SoundHundle[eSound::collection]);
//		break;
//	case eSound::fan:
//		StopSoundMem(SoundHundle[eSound::fan]);
//		break;
//	case eSound::flower:
//		StopSoundMem(SoundHundle[eSound::flower]);
//		break;
//	case eSound::kabu:
//		StopSoundMem(SoundHundle[eSound::kabu]);
//		break;
//	case eSound::mushroom_nobiru:
//		StopSoundMem(SoundHundle[eSound::mushroom_nobiru]);
//		break;
//	case eSound::mushroom_tijimu:
//		StopSoundMem(SoundHundle[eSound::mushroom_tijimu]);
//		break;
//	case eSound::peach:
//		StopSoundMem(SoundHundle[eSound::peach]);
//		break;
//	case eSound::spinfloor_close:
//		StopSoundMem(SoundHundle[eSound::spinfloor_close]);
//		break;
//	case eSound::spinfloor_open:
//		StopSoundMem(SoundHundle[eSound::spinfloor_open]);
//		break;
//	case eSound::stove_burn:
//		StopSoundMem(SoundHundle[eSound::stove_burn]);
//		break;
//	case eSound::stove_ignition:
//		StopSoundMem(SoundHundle[eSound::stove_ignition]);
//		break;
//	case eSound::sword:
//		StopSoundMem(SoundHundle[eSound::sword]);
//		break;
//	defalut:
//		break;
//	}
//}