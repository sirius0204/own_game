#include "G_House.h"



G_House::G_House(const std::vector<double>& info)
{
	Initialize(info);
}


G_House::~G_House()
{
}

void G_House::Initialize(const std::vector<double>& info) {
	setExist(true);
	setPoint({ info[0], info[1] });
	setHeight(info[2]);
	setWidth(info[3]);
	id = info[4];
	state = info[5];
}
void G_House::Update(std::vector<Enemy*> &enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2& screen, int& score) {
	for (Friend* fre : friends) {
		SelectGraph(fre->getHp());
	}
}

void G_House::Finalize() {
}

void G_House::SelectGraph(int collection) {
	//個数を所得
	double straw = collection & 1023;
	double wood = (collection & 1047552) >> 10;
	double brick = (collection & 1072693248) >> 20;
	int sum = straw + wood + brick;
	if (sum == 0) {
		id = 47;
		setCount(0);
		return;
	}
	
	//個数->割合に変換
	straw = straw / sum * 100;
	wood = wood / sum * 100;
	brick = brick / sum * 100;
	//下端を設定
	int range[3];
	range[0] = setRange(straw);
	range[1] = setRange(wood);
	range[2] = setRange(brick);
	//一番近い点を選ぶ
	Vector2 point;
	NearPoint(range, point, wood, brick);
	//描画画像選択
	int newId = getGraph(point);
	id = 47 + (newId / 4);
	setCount(30 * (newId % 4));
}

int G_House::setRange(double data) { //各割合を0~25,25~50,50~75,75~100のいずれかに当てはめる
	if (data >= 0 && data < 25) return 0;
	if (data >= 25 && data < 50) return 25;
	if (data >= 50 && data < 75) return 50;
	if (data >= 75 && data <= 100) return 75;
	assert(!"範囲外の数値");
}

void G_House::NearPoint(int* range, Vector2& point, int w, int b) {
	const Vector2 vectorW(1, 0), vectorB(cos(PI / 3), sin(PI / 3));
	Vector2 candi[3]; //候補を3つ作る

	int low_sum = range[0] + range[1] + range[2];
	if (low_sum == 50) { //上端上端下端
		candi[0] = vectorW*(range[1] + 25) + vectorB*(range[2] + 25);
		candi[1] = vectorW*(range[1] + 25) + vectorB*range[2];
		candi[2] = vectorW*range[1] + vectorB*(range[2] + 25);
	}
	else if (low_sum == 75) { //下端下端上端
		candi[0] = vectorW*range[1] + vectorB*range[2];
		candi[1] = vectorW*(range[1] + 25) + vectorB*range[2];
		candi[2] = vectorW*range[1] + vectorB*(range[2] + 25);
	}
	else if (low_sum == 100) { //特別な場合は即決定
		point = vectorW*range[1] + vectorB*range[2];
		return;
	}
	else {
		assert(!"合計値が不正");
	}

	//3つの候補の中から一番近いものを選ぶ
	int n=0;
	double d, nd = 1;
	Vector2 p = vectorW*w + vectorB*b;
	for (int i = 0; i < 3; i++) {
		d = candi[i].getDist(p);
		if (d < nd) n = i;
	}
	point = candi[n];
	return;
}

int G_House::getGraph(Vector2 point) {
	const Vector2 vectorW(1, 0), vectorB(cos(PI / 3), sin(PI / 3));
	if (point == vectorW * 0 + vectorB * 100) return 1;
	if (point == vectorW * 25 + vectorB * 75) return 2;
	if (point == vectorW * 0 + vectorB * 75)  return 3;
	if (point == vectorW * 50 + vectorB * 50) return 4;
	if (point == vectorW * 25 + vectorB * 50) return 5;
	if (point == vectorW * 0 + vectorB * 50)  return 6;
	if (point == vectorW * 75 + vectorB * 25) return 7;
	if (point == vectorW * 50 + vectorB * 25) return 8;
	if (point == vectorW * 25 + vectorB * 25) return 9;
	if (point == vectorW * 0 + vectorB * 25)  return 10;
	if (point == vectorW * 100 + vectorB * 0) return 11;
	if (point == vectorW * 75 + vectorB * 0)  return 12;
	if (point == vectorW * 50 + vectorB * 0)  return 13;
	if (point == vectorW * 25 + vectorB * 0)  return 14;
	if (point == vectorW * 0 + vectorB * 0)   return 15;
	assert(!"不正なベクトル値");
}


