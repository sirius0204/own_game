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
	std::vector<std::vector<int>> map;	//�}�b�v�p�Q�����z��
	int height, width;	//�}�b�v�̏c�A���̌�
	std::string convert(int num);
public:
	Map();
	~Map();

	void Initialize(int stage);
	void Update();
	void Finalize();

	bool isMovable(const Vector2& pos) const;		//���̍��W���ړ��\�ȃ}�X���ǂ���
	const std::vector<std::vector<int>>& getMap();

	int getHeight() const;
	int getWidth() const;

	static const int ChipEdge = 48;		//�}�b�v�`�b�v�̕ӂ̒���
	enum Chip {							//�`�b�v�̎�ނ̗񋓑�
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

