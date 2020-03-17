#pragma once
#include "Gimic.h"
#include <vector>
#include <string>
#include <fstream>
#include <cassert>

#include "G_SpinFloor.h"
#include "G_Flower.h"
#include "G_MoveFloor.h"
#include "G_Mushroom.h"
#include "G_Stove.h"
#include "G_Fan.h"
#include "G_Bridge.h"
#include "G_Ladder.h"
#include "G_Apple.h"
#include "G_Kabu.h"
#include "G_Collection.h"
#include "G_Peach.h"
#include "G_Sword.h"
#include "G_Barrier.h"
#include "G_Tree.h"
#include "G_IgnitionFloor.h"
#include "G_Bird.h"
#include "G_LadderFloor.h"
#include "G_House.h"
#include "G_Turn.h"
class GimicMgr
{
	std::string convert(int num);
	std::vector<Gimic*> gimics;
public:
	GimicMgr();
	~GimicMgr();

	void Initialize(int stage);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, const Vector2& screen, int& score);
	void Finalize();

	std::vector<Gimic*>& getGimics();

	enum eGimic
	{
		none= 0,
		moveable_floor_left,
		moveable_floor_right,
		wooden_floor_horizontal,
		wooden_floor_vertical,
		wooden_floor_horizontal_2mas,
		wooden_floor_vertical_2mas,
		ladder_clear,
		ladder_brownyellow,	
		switch_off_red,
		switch_off_bule,
		switch_off_green,
		switch_on_red,
		switch_on_blue,
		switch_on_green,
		bridge, 
		wind,
		door,
		flower,
		mushroom,
		wine_und_driedmeat,
		fire_off,
		fire_on,
		katana,
		peach,
		kiji_stop_left,
		kiji_fly_left,
		kiji_stop_right,
		kiji_fly_right,
		glass_shoe_superclear,
		guest_right,
		guest_left,
		apple,
		ore_blue,
		ore_cyan,
		ore_green,
		ore_orange,
		ore_purple,
		ore_red,
		ore_yellow,
		mirror_blue,
		mirror_blue_rev,
		mirror_green,
		mirror_green_rev,
		mirror_pink,
		mirror_pink_rev,
		mirror_purple,
		mirror_purple_rev,
		tree,
		house1,
		house2,
		something,
		something2,
		door_close_blue,
		door_open_blue,
		door_close_red,
		door_open_red,
		door_close_green,
		door_open_green,
		waku,
		yajirushi1,
		yajirushi2,
		fan,
		barrier,
		turnip,
		brick,
		fan_right,
		wind2,
		Size
	};
};

