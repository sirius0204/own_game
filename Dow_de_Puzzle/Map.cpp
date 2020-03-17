#include "Map.h"



std::string Map::convert(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

Map::Map()
{
}


Map::~Map()
{
}


void Map::Initialize(int stage) {
	std::string dir = "./resource/dat/stage/";
	//dir += (char)(stage + '0');
	dir += convert(stage);
	dir += ".prn";
	std::ifstream input(dir);
	assert(input);

	input >> height >> width;
	map.resize(height, std::vector<int>(width));

	for (signed i = 0; i < height; i++) {
		for (signed j = 0; j < width; j++) {
			input >> map[i][j];
		}
	}

}
void Map::Update() {

}
void Map::Finalize() {
	for (unsigned i = 0; i < map.size(); i++) {
		map[i].clear();
	}
	map.clear();
}

bool Map::isMovable(const Vector2 & pos) const
{
	return map[pos.y / ChipEdge][pos.x / ChipEdge] == Chip::None;
}


const std::vector<std::vector<int>>& Map::getMap() { return map; }

int Map::getHeight() const
{
	return height;
}

int Map::getWidth() const
{
	return width;
}
