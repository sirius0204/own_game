#include "G_EFcolider.h"

G_EFcolider::G_EFcolider(const std::vector<double>& info){
	Initialize(info);
};
G_EFcolider::~G_EFcolider(){
};

void G_EFcolider::Initialize(const std::vector<double>& info){
	setExist(true);
	state = info[0];
	id = info[1];

};

void G_EFcolider::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score){
	colider(friends, enemys, score);
};

void G_EFcolider::Finalize(){

};

void G_EFcolider::colider(std::vector<Friend*> &friends, std::vector<Enemy*> &enemys,int &score){

	for (Enemy* enemy : enemys){
		for (Friend* fre : friends){
			if (enemy->getState() == 0){
				if (enemy->isHitBox(*fre)){
					//enemy->setExist(false);
					score -= 200;
				}
			}
		}
	}
}