#pragma once
#include "Object.h"
#include <vector>
#include "Enemy.h"
#include "Friend.h"
#include "MyInput.h"

class Gimic :
	public ObjBox
{
protected:
	int state;
	int id;
public:
	Gimic();
	~Gimic();
	virtual void Initialize(const std::vector<double>& info) = 0;
	virtual void Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) = 0;
	virtual void Finalize() = 0;

	int getState() const;
	int getId() const;
	void setState(int _state);
	void setId(int _id);
};


