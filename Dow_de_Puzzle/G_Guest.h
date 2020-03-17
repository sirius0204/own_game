#pragma once
#include "Gimic.h"
class G_Guest :
	public Gimic
{

public:
	G_Guest(const std::vector<double>& _infos);
	~G_Guest();

	void Initialize(const std::vector<double>& info);
	void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score);
	void Finalize();


	static const int initInfoSize = 10;
};