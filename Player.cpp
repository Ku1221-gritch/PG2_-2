#include "Player.h"
#include"Bullet.h"
#include "Novice.h"



Player::Player(int posX,int posY, int radius, int speed) {
	//メンバ変数の初期化
	bullet_ = new Bullet( -10,-10, 10, 15, false);
	posX_ = posX;
	posY_ = posY;
	radius_ = radius;
	speed_ = speed;
}

void Player::SetPlayerPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
}

void Player::SetPlayerSpeed(int a)
{
	speed_ = a;
}

void Player::SetPlayerRadius(int a)
{
	radius_ = a;
}

Player::~Player() {
	//ポインタ削除
	delete bullet_;
}

void Player::Update(char* keys) {
	//移動処理
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	if (keys[DIK_SPACE]) {
		if (bullet_->isShotFlag_ == false) {
			//発射処理
			bullet_->posX_ = posX_;
			bullet_->posY_ = posY_;
			bullet_->isShotFlag_ = true;
		}
	}
	bullet_->Update();
}

//弾の更新処理

void Player::Draw()
{
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	bullet_->Draw();
}