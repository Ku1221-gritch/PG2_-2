#include <Novice.h>
#include <Player.h>
#include <Bullet.h>
#include "Enemy.h"

const char kWindowTitle[] = "GC1A_06_サトウ_クウ_ClassiFication";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player( 640,500 , 30, 10);

	Enemy* enemy = new Enemy(100, 150, 6, 0,true);

	//シーン切り替え
	enum SceneNo {
		Title,
		Game,
		Gameover,
		Gameclear,
	};

	int SceneNo = Title;

	int TitleTexture = Novice::LoadTexture("./images/Title.png");
	int GameclearTexture = Novice::LoadTexture("./images/GAMECLEAR1.png");
	int GameoverTexture = Novice::LoadTexture("./images/GAMEOVER.png");

	int deathCount = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (SceneNo) {
		case Title:
			deathCount = 0;
			player->SetPlayerPosition(640, 500);
			player->bullet_->SetBulletIsShotFlag(false);
			enemy->SetEnemyIsAlive(true);
			
			if ((keys[DIK_RETURN]) && (preKeys[DIK_RETURN]) == 0) {
				SceneNo = Game;
			}

			break;

		case Game:

			player->Update(keys);

			enemy->Update();

			// エネミーとプレイヤーの当たり判定処理
			{
				int distX1 = enemy->GetEnemyPosX() - player->GetPlayerPosX();
				int distY1 = enemy->GetEnemyPosY() - player->GetPlayerPosY();
				int dist1 = (distX1 * distX1) + (distY1 * distY1);
				int radius1 = enemy->GetEnemyRadius() + player->GetPlayerRadius();
				if (dist1 <= radius1 * radius1) {
					SceneNo = Gameover;
				}
			}

			// エネミーと弾の当たり判定処理
			{
				int distX2 = enemy->GetEnemyPosX() - player->bullet_->GetBulletPosX();
				int distY2 = enemy->GetEnemyPosY() - player->bullet_->GetBulletPosY();
				int dist2 = (distX2 * distX2) + (distY2 * distY2);
				int radius2 = enemy->GetEnemyRadius() + player->bullet_->GetBulletRadius();
				if (dist2 <= radius2 * radius2) {
					enemy->SetEnemyIsAlive(false);
					deathCount += 1;
				}
			}

			if (deathCount == 15) {
				SceneNo = Gameclear;
			}

			break;

		case Gameover:

			if ((keys[DIK_SPACE]) && (preKeys[DIK_SPACE]) == 0) {
				SceneNo = Title;
			}

			break;

		case Gameclear:

			if ((keys[DIK_SPACE]) && (preKeys[DIK_SPACE]) == 0) {
				SceneNo = Title;
			}

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (SceneNo) {
		case Title:
			Novice::DrawSprite(0, 0, TitleTexture, 1, 1, 0.0f, WHITE);
			break;

		case Game:
			Novice::ScreenPrintf(0, 0, "%d", deathCount);
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);

			player->Draw();
			
	
			enemy->Draw();

			break;

		case Gameover:
			Novice::DrawSprite(0, 0, GameoverTexture, 1, 1, 0.0f, WHITE);
			break;

		case Gameclear:
			Novice::DrawSprite(0, 0, GameclearTexture, 1, 1, 0.0f, WHITE);
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
