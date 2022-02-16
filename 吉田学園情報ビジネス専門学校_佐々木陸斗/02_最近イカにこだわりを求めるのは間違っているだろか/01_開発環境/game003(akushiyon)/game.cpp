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
#include"Time.h"
#include"block.h"
#include"item.h"
#include"itemB.h"
#include"HighScore.h"
#include"blockB.h"
//ゲーム画面の初期化処理
void lnitGAME(void)
{
	//サウンドの再生
	PlaySound(SOUND_LABEL_BGMGame);
	
	//背景の初期化処理
	lnitBG();

	//スコアの初期化処理
	lnitScore();


	//タイムの初期化
	lnitTime();


	//プレイヤーの初期化処理

	lnitPlayer();

	//弾の初期化処理
	lnitBullet();

	//エネミーの初期化処理
	lnitEnemy();

	//ブロック
	lnitblock();
	//ブロック
	lnitblockB();
	//アイテム
	lnitItem();

	//アイテム
	lnitItemb();
	//ハイスコアの初期化
	lnitHigeScore();


}



//ゲームの終了処理
void UninitGAME(void)
{
	//サウンドの停止
	StopSound();


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

	//ブロック
	Uninitblock();

	//ブロック
	UninitblockB();

	//アイテム
	UninitItem();

	//アイテム
	UninitItemb();

	UninitHigeScore();
}

//ゲームの描画処理
void DrawGAME(void)
{
	//背景の更新処理
	DrawBG();

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

	//ブロック
	Drawblock();

	//ブロック
	DrawblockB();
	//アイテム
	DrawItem();

	//アイテム
	DrawItemb();

	DrawHigeScore();
}

//ゲーム画面の更新処理
void UpdateGAME(void)
{
	//背景の更新処理
	UpdateBG();

	//スコアの更新処理
	UpdateScore();

	//タイムの更新
	UpdateTime();

	//弾の更新処理
	UpdateBullet();

	//エネミーの更新処理
	UpdateEnemy();
	
	//ブロック
	Updateblock();

	//ブロック
	UpdateblockB();
	//アイテム
	UpdateItem();

	//アイテム
	UpdateItemb();

	//プレイヤーの更新処理
	UpdatePlayer();

	UpdateHigeScore();


	//決定キー(ENTERキーが押されたかどうか)
	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		//モード設定
		SetMode(MODE_RESULT);
	}
	//Kキー(ゲーム最初から)
	if (GetKeyboardTrigger(DIK_K) == true)
	{
		//モード設定
		SetMode(MODE_GAME);
	}
}