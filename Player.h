#pragma once
#include "Bullet.h"
//class + クラスの型の名前
class Player
{
public://ここから
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	//ここまでがメンバ変数

	int GetPlayerPosX() { return posX_; };
	int GetPlayerPosY() { return posY_; };
	void SetPlayerPosition(int x, int y);
	int GetPlayerSpeed() { return speed_; };
	void SetPlayerSpeed(int a);
	int GetPlayerRadius() { return radius_; };
	void SetPlayerRadius(int a);

public://ここから
	Bullet* bullet_;
	Player(int posX_,int posY_, int r, int speed);//コンストラクタ
	~Player();
	void Update(char* keys);
	void Draw();
	//ここまでメンバ関数
};

//struct + 構造体の型の名前