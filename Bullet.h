#pragma once

class Bullet
{
public:
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	bool isShotFlag_;

	int GetBulletPosX() { return posX_; };
	int GetBulletPosY() { return posY_; };
	void SetBulletPosition(int x, int y);
	int GetBulletSpeed() { return speed_; };
	void SetBulletSpeed(int a);
	int GetBulletRadius() { return radius_; };
	void SetBulletRadius(int a);
	int GetBulletIsShotFlag() { return isShotFlag_; };
	void SetBulletIsShotFlag(bool a);

public:
	Bullet(int posX_,int posY_, int r, int speed, bool isShotFlag);//コンストラクタ
	void Update();
	void Draw();
};