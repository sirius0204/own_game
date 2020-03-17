#include "G_Shose.h"



G_Shose::G_Shose(const std::vector<double>& info)
{
	Initialize(info);
}


G_Shose::~G_Shose()
{
}

void G_Shose::Initialize(const std::vector<double>& info)
{
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];
}

void G_Shose::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2 & screen, int & score)
{
	for (Friend* fre : friends) {
		if (isHitBox(*fre)) {
			fre->setState(1);
			id++;
		}
	}
}

void G_Shose::Finalize()
{
}
