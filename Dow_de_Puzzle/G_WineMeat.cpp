#include "G_WineMeat.h"



G_WineMeat::G_WineMeat(const std::vector<double>& info)
{
	Initialize(info);
}


G_WineMeat::~G_WineMeat()
{
}

void G_WineMeat::Initialize(const std::vector<double>& info)
{
	setExist(false);	//デバッグ用にかきかえた
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	range.setPoint({ info[4],info[5] });
	range.setHeight(info[6]);
	range.setWidth(info[7]);
	id = info[8];
	state = info[9];
}

void G_WineMeat::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{
	for (Enemy* enemy : enemys) {
		if (isHitBox(*enemy)) {
			setExist(false);
			return;
		}
		if (range.isHitBox(*enemy)) {
			if (enemy->getCenterPoint().x < point.x) {
				enemy->setDir(1);
			}
			else {
				enemy->setDir(0);
			}
		}
		
	}
}

void G_WineMeat::Finalize()
{
}
