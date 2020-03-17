#include "G_Tree.h"

G_Tree::G_Tree(const std::vector<double>& info){
	Initialize(info);
};
G_Tree::~G_Tree(){};

void G_Tree::Initialize(const std::vector<double>& info){
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];
	
};

void G_Tree::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score)
{

};

void G_Tree::Finalize(){

};