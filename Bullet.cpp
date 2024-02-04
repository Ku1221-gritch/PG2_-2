#include "Novice.h"
#include"Bullet.h"

Bullet::Bullet(int posX, int posY, int r, int speed, bool isShotFlag) {
	//メンバ変数の初期化
	posX_ = posX;
	posY_ = posY;
	radius_ = r;
	speed_ = speed;
	isShotFlag_ = isShotFlag;
}

void Bullet::SetBulletPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
}

void Bullet::SetBulletSpeed(int a)
{
	speed_ = a;
}

void Bullet::SetBulletRadius(int a)
{
	radius_ = a;
}

void Bullet::SetBulletIsShotFlag(bool a)
{
	isShotFlag_ = a;
}

void Bullet::Update() {
	//移動処理
	if (isShotFlag_ == true) {
		posY_ -= speed_;
		if (posY_ <= 0) {
			//画面外に出たら
			isShotFlag_ = false;
		}
	}
	
}

void Bullet::Draw() {
	//描画処理
	if (isShotFlag_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}
