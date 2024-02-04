#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY,bool isAlive)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 32;
	isAlive_ = isAlive;
}

void Enemy::SetEnemyPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
}

void Enemy::SetEnemySpeed(int x, int y)
{
	speedX_ = x;
	speedY_ = y;
}

void Enemy::SetEnemyRadius(int a)
{
	radius_ = a;
}

void Enemy::SetEnemyIsAlive(int a)
{
	isAlive_ = a;
}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
		isAlive_ = true;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}