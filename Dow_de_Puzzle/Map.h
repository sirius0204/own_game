#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "struct.h"
#include "Materials.h"

#include <cassert>
class Map
{	
	std::vector<std::vector<int>> map;	//マップ用２次元配列
	int height, width;	//マップの縦、横の個数
	std::string convert(int num);
public:
	Map();
	~Map();

	void Initialize(int stage);
	void Update();
	void Finalize();

	bool isMovable(const Vector2& pos) const;		//その座標が移動可能なマスかどうか
	const std::vector<std::vector<int>>& getMap();

	int getHeight() const;
	int getWidth() const;

	static const int ChipEdge = 48;		//マップチップの辺の長さ
	enum Chip {							//チップの種類の列挙体
		None = 0,
		Wall,
		grass_floor,
		grass_floor1,
		grass_floor2,
		house,
		kabochanobasha,
		snow_floor,
		tree,
		toxicplant,
		boat,
		water,
		Size
	};
};

