#pragma once
#include "Friend.h"

//------------------------------------------//
//	ê‘Ç∏Ç´ÇÒ							//
//		number = 0;							//
//------------------------------------------//

class F_Aka :
	public Friend
{
public:
	F_Aka(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	~F_Aka();

	void Initialize(int _id, int _hp, int _dir, int _state, const Vector2& pos, double _h, double _w);
	void Update(const Map& map);
	void Finalize();

	enum eAkaState {
		Coat=0,
		Shirt,
		Naked,
		Size
	};
};

