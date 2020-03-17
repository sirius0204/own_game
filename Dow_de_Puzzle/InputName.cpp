#include "InputName.h"

const std::string InputName::kana[2][InputName::kanaSize] = {
	{
		"あ" , "い" , "う" , "え" , "お" , "か" , "き" , "く" , "け" , "こ" , "さ" , "し" , "す" , "せ" , "そ" , "た" , "ち" , "つ" , "て" , "と" , "な" , "に" , "ぬ" , "ね" , "の" , "は" , "ひ" , "ふ" , "へ" , "ほ" , "ま" , "み" , "む" , "め" , "も" , "や" , "" , "ゆ" , "" , "よ" , "ら" , "り" , "る" , "れ" , "ろ" , "わ" ,"" ,"を" ,"" , "ん" , "ー" ,"っ" ,"ゃ" ,"ゅ" ,"ょ" , "が" , "ぎ" , "ぐ" , "げ" , "ご" , "ざ" , "じ" , "ず" , "ぜ" , "ぞ" , "だ" , "ぢ" , "づ" , "で" , "ど" , "ば" , "び" , "ぶ" , "べ" , "ぼ" , "ぱ" , "ぴ" , "ぷ" , "ぺ" , "ぽ" , "ぁ" , "ぃ" , "ぅ" , "ぇ" , "ぉ" },
		{
			"ア" , "イ" , "ウ" , "エ" , "オ" , "カ" , "キ" , "ク" , "ケ" , "コ" , "サ" , "シ" , "ス" , "セ" , "ソ" , "タ" , "チ" , "ツ" , "テ" , "ト" , "ナ" , "ニ" , "ヌ" , "ネ" , "ノ" , "ハ" , "ヒ" , "フ" , "ヘ" , "ホ" , "マ" , "ミ" , "ム" , "メ" , "モ" , "ヤ" , "" , "ユ" ,"" , "ヨ" , "ラ" , "リ" , "ル" , "レ" , "ロ" , "ワ" ,"" ,"ヲ" ,"" , "ン" , "ー" ,"ッ" ,"ャ" ,"ュ" ,"ョ" , "ガ" , "ギ" , "グ" , "ゲ" , "ゴ" , "ザ" , "ジ" , "ズ" , "ゼ" , "ゾ" , "ダ" , "ヂ" , "ヅ" , "デ" , "ド" , "バ" , "ビ" , "ブ" , "ベ" , "ボ" , "パ" , "ピ" , "プ" , "ペ" , "ポ" , "ァ" , "ィ" , "ゥ" , "ェ" , "ォ" }
};

InputName::InputName()
{
}


InputName::~InputName()
{
}

void InputName::Initialize() {
	name.clear();
	isUpper = false;
	isNameNG = false;

	
	double x = 900, y = 250, w = 50, h = 50, ax = 5, ay = 5;
	for (int i = 0; i < kanaSize; i++) {
		box.push_back(ObjBox({ x, y }, h, w));
		y += h + ay;
		if ((i + 1) % 5 == 0) {
			y -= 5 * (h + ay);
			x -= w + ax;
		}
	}

	x = 900, y = 250, w = 50, h = 50, ax = 5, ay = 5;
	shift = ObjBox(Vector2(x - w * 2, y + 5 * (h + ay) + ay * 3), h, w * 3);
	back = ObjBox(Vector2(x - w * 5 - ax, y + 5 * (h + ay) + ay * 3), h, w * 3);
	erase = ObjBox(Vector2(x - w * 8 - ax * 2, y + 5 * (h + ay) + ay * 3), h, w * 3);

	x = 650, w = 150, y = 100, h = 75, ax = 10, ay = 10;
	enter = ObjBox(Vector2(x, y), h, w);

	LPCSTR font_path = "./resource/Font/uzurafont100/uzurafont100/uzura.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}

	FontHandle[1] = CreateFontToHandle(font_path, 20, 9);
}
bool InputName::Upadate() {
	if (Input.getMousePressLeftOnce()) {
		Vector2 mousePoint = Input.getMousePoint();
		if (enter.isHitPoint(mousePoint) && name.size() != 0) {
			return false;
		}
		if (back.isHitPoint(mousePoint) && name.size() != 0) {
			name = name.substr(0, name.size() - 2);
		}
		else if (erase.isHitPoint(mousePoint)) {
			name.clear();
		}
		else if (shift.isHitPoint(mousePoint)) {
			isUpper = !isUpper;
		}
		else {
			for (int i = 0; i < kanaSize; i++) {
				if (box[i].isHitPoint(Input.getMousePoint())) {
					if (name.size() <= mojisu * 2) name += kana[isUpper][i];
				}
			}
		}
	}
	return true;
}
void InputName::Draw() {
	DrawBox(0, 0, WinWidth, WinHeight, GetColor(232, 225, 173),true);
	DrawFormatStringToHandle(50, 50, GetColor(204, 143, 81), FontHandle[1], "名前を入力してね！！(空文字列はNGだよ！！)");
	for (int i = 0; i < kanaSize; i++) {
		DrawObjBox(box[i], 0, 0, 0);
		DrawFormatStringToHandle(box[i].getPoint().x + 12, box[i].getPoint().y + 12, GetColor(204, 143, 81), FontHandle[1], "%s", kana[isUpper][i].c_str());
	}
	DrawObjBox(enter, 0, 0, 0);
	DrawFormatStringToHandle(enter.getPoint().x + 25, enter.getPoint().y + 25, GetColor(204, 143 ,81), FontHandle[1], "%s", "けってい");
	DrawObjBox(back, 0,0,0);
	DrawFormatStringToHandle(back.getPoint().x + 12, back.getPoint().y + 12, GetColor(204, 143, 81), FontHandle[1], "%s", "もどる");
	DrawObjBox(erase, 0,0,0);
	DrawFormatStringToHandle(erase.getPoint().x + 12, erase.getPoint().y + 12, GetColor(204, 143, 81), FontHandle[1], "%s", "けす");
	DrawObjBox(shift, 0,0,0);
	if(!isUpper) DrawFormatStringToHandle(shift.getPoint().x + 12, shift.getPoint().y + 12, GetColor(204, 143, 81), FontHandle[1], "%s", "カナ");
	else if (isUpper) DrawFormatStringToHandle(shift.getPoint().x + 12, shift.getPoint().y + 12, GetColor(204, 143, 81), FontHandle[1], "%s", "カナ");



	DrawFormatStringToHandle(100, 200, GetColor(204, 143, 81), FontHandle[1], name.c_str());
}

const std::string & InputName::getName() const
{
	return name;
}

void InputName::DrawObjBox(const ObjBox & box, int r, int g, int b, bool f)
{
	DrawBox(box.getPoint().x, box.getPoint().y, box.getPoint().x + box.getWidth(), box.getPoint().y + box.getHeight(), GetColor(r, g, b), f);
}
