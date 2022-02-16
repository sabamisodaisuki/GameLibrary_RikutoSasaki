#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Enemy.h"
#include"title.h"
#include"game.h"
#include"bg.h"
#include"sound.h"
#include"Score.h"
#include"explosion.h"
#include"Time.h"
#include"bg2.h"
#include"HighScore.h"

//ゲーム画面の初期化処理
void lnitGAME(void)
{
	//サウンドの再生
	PlaySound(SOUND_LABEL_BGMMAOU);


	//背景の初期化処理
	lnitBG();

	//背景の初期化処理
	lnitBG2();

	//スコアの初期化処理
	lnitScore();

	//爆破の初期化処理
	lnitExplosion();


	//タイムの初期化
	lnitTime();


	//プレイヤーの初期化処理

	lnitPlayer();

	//弾の初期化処理
	lnitBullet();

	//エネミーの初期化処理
	lnitEnemy();

	//ハイスコアの初期化処理
	lnitHigeScore();
}

//ゲームの終了処理
void UninitGAME(void)
{
	//サウンドの停止
	StopSound();

	//爆破の終了処理
	UninitExplosion();

	//プレイヤーんの終了処理
	UninitPlayer();

	//スコアの終了処理
	UninitScore();

	//タイムの終了処理
	UninitTime();

	//弾の終了処理
	UninitBullet();

	//エネミーの終了処理
	UninitEnemy();

	//背景の終了処理
	UninitBG();

	//背景の終了処理
	UninitBG2();

	//ハイスコア終了処理
	UninitHigeScore();
}

//ゲームの描画処理
void DrawGAME(void)
{
	//背景の更新処理
	DrawBG();

	//背景の更新処理
	DrawBG2();

	//爆破の更新処理
	DrawExplosion();

	//スコアの更新処理
	DrawScore();

	//タイムの更新処理
	DrawTime();

	//プレイヤーの更新処理
	DrawPlayer();

	//弾の更新処理
	DrawBullet();

	//エネミーの更新処理
	DrawEnemy();

	//ハイスコアの更新処理
	DrawHigeScore();
}

//ゲーム画面の更新処理
void UpdateGAME(void)
{
	//背景の更新処理
	UpdateBG();

	//背景の更新処理
	UpdateBG2();

	//爆破の更新処理
	UpdateExplosion();

	//スコアの更新処理
	UpdateScore();

	//プレイヤーの更新処理
	UpdatePlayer();

	//タイムの更新
	UpdateTime();

	//弾の更新処理
	UpdateBullet();

	//エネミーの更新処理
	UpdateEnemy();
	
	//ハイスコアの更新化処理
	UpdateHigeScore();
	////決定キー(ENTERキーが押されたかどうか)
	//if (GetKeyboardTrigger(DIK_RETURN) == true)
	//{
	//	//モード設定
	//	SetMode(MODE_RESULT);
	//}

}