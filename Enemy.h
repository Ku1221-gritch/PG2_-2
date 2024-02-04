#pragma once
class Enemy
{
public:	// メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X座標</param>
	/// <param name="posY">Y座標</param>
	/// <param name="speedX">移動速度X</param>
	/// <param name="speedY">移動速度Y</param>
	Enemy(int posX, int posY, int speedX, int speedY,bool isAlive);

	int GetEnemyPosX() { return posX_; };
	int GetEnemyPosY() { return posY_; };
	void SetEnemyPosition(int x, int y);
	int GetEnemySpeedX() { return speedX_; };
	int GetEnemySpeedY() { return speedY_; };
	void SetEnemySpeed(int x, int y);
	int GetEnemyRadius() { return radius_; };
	void SetEnemyRadius(int a);
	int GetEnemyIsAlive() { return isAlive_; };
	void SetEnemyIsAlive(int a);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	bool isAlive_;
};
