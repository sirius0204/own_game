#include "G_Incinerator.h"



G_Incinerator::G_Incinerator(const std::vector<double>& info)
{
	Initialize(info);
}


G_Incinerator::~G_Incinerator()
{
}

void G_Incinerator::Initialize(const std::vector<double>& info)
{
	setExist(true);
	point.x = info[0];
	point.y = info[1];
	height = info[2];
	width = info[3];
	id = (int)info[4];
	state = (int)info[5];
}

void G_Incinerator::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2 & screen, int & score)
{
	for (Friend* fre : friends) {
		if (isHitBox(*fre)) {
			state = 1;				//“_‰Î
		}
	}
	for (Enemy* enemy : enemys) {
		if (state == 1 && isHitBox(*enemy)) {
			enemy->setExist(false);
			score += 10;
		}
	}
}

void G_Incinerator::Finalize()
{
}
