//====================
//プレイヤーの処理
//AUTHOR:佐々木陸斗
//
//===================

#include "main.h"
#include "player.h"
#include"input.h"
#include"bg.h"
#include"block.h"
#include"time.h"
#include"bullet.h"
#include"itemB.h"
#include"fade.h"
#include"sound.h"
#include"Enemy.h"
#include"HighScore.h"
#include"blockB.h"

#define PLAYER_Z			(4.0f)

//グローバル宣言
LPDIRECT3DTEXTURE9 g_pTexturePlayer = NULL;				//テクスチャへのポインタ			
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPlayer = NULL;		//頂点バッファへのポインタ
int g_nCounterAnimPlayer;								//アニメーションカウンター
int g_nPatternAnimPlayer;								//アニメーションパターン
int nDirectionMove;
D3DXVECTOR3 g_posPlayer;								//位置
D3DXVECTOR3 g_movePlayer;								//移動量
D3DXVECTOR3 g_scalePlayer;								//プレイヤーの大きさ
D3DXVECTOR3 g_posOldPlayer;								//前回の位置
Player g_player;										//プレイヤー情報


//プレイヤーの初期化処理
D3DXVECTOR3 g_rotPlayer;								//向き
float g_fLengthPlayer;									//対角線の長さ
float g_fAnglePlayer;									//対角線の角度


//プレイヤーの取得
Player*GetPlayer(void)
{
	return &g_player;
}

int sum(int a, int b)
{
//	return a + b;
	int c = a + b;
	return c;
}


void lnitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int C;
	C = sum(4,5);

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/kabo.png",					//daiba.png sura2.png
		&g_pTexturePlayer);
	
	g_nCounterAnimPlayer = 0;							//カウンター初期化
	g_nPatternAnimPlayer = 0;							//パターンNoを初期化
	g_posPlayer = D3DXVECTOR3(70.0f,480.0f,0.0f);		//位置を初期化
	g_movePlayer = D3DXVECTOR3(0.0f,0.0f,0.0f);		//移動値を初期化
	g_scalePlayer = D3DXVECTOR3(100.0f,100.0f,0.0f);	//プレイヤーの初期化処理
	g_player.bDisp = true;
	g_player.nLife = 20;
	g_player.nCounterState = 60;
	g_player.state = PLAYERSTATE_NORMAL;
	


	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D)*4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPlayer,
		NULL);

		VERTEX_2D*pVtx;		//頂点情報へポインタ

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffPlayer->Lock(0, 0,(void**)&pVtx, 0);

	

	//頂点座標
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの描画
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//プレイヤー座標
	pVtx[0].tex = D3DXVECTOR2(0.0f+(0.33f*g_player.nPatternAnim), 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.33f+(0.33f*g_player.nPatternAnim), 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + (0.33f*g_player.nPatternAnim),0.25f);
	pVtx[3].tex = D3DXVECTOR2(0.33f + (0.33f*g_player.nPatternAnim), 0.25f);

	//頂点バッファアンロック
	g_pVtxBuffPlayer->Unlock();

}
//ポリゴンの終了処理
void UninitPlayer(void)
{
	//サウンドの停止
	StopSound();

	//テクスチャの破棄
	if (g_pTexturePlayer != NULL)
	{
		g_pTexturePlayer->Release();
		g_pTexturePlayer= NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffPlayer != NULL)
	{
		g_pVtxBuffPlayer->Release();
		g_pVtxBuffPlayer = NULL;
	}
	
}

//プレイヤーの更新処理
void UpdatePlayer(void)
{
	// フェード情報の取得
	FADE fade = GetFade();

	VERTEX_2D*pVtx;



	if (GetKeyboardPress(DIK_A) == true)
	{//Aキーを押した[左]

		g_player.nDirectionMove = 1;

		
			g_movePlayer.x -= 5.0f;//プレイヤーの位置に移動量を足す
								  
	}
	
		if (GetKeyboardTrigger(DIK_W) == true)
		{//Wキーを押した[上］
			if (g_player.bIsJumping == false)
			{
				g_player.bIsJumping = true;

			g_movePlayer.y = -40.0f;//プレイヤーのジャンプ
									
		}
	}

	else if (GetKeyboardPress(DIK_D) == true)
	{//Dキーを押した[右]
		g_player.nDirectionMove = 2;
			g_movePlayer.x += 5.0f;//プレイヤーの位置に移動量を足す
	}
	 if (GetKeyboardTrigger(DIK_SPACE) == true)
	{//SPACEキーが押された
	
		//弾の設定
		 if (g_player.nDirectionMove == 2)
		 {
			 SetBullet( D3DXVECTOR3(g_posPlayer.x, g_posPlayer.y-PLAYER_SIZE_Y/2.0f, g_posPlayer.z), D3DXVECTOR3(6.0f, 0.0f, 0.0f));//6.0f,-3.0f,-6.0f
																																	//サウンドの再生
			 PlaySound(SOUND_LABEL_SE_SHOT);
		 }
		 else if (g_player.nDirectionMove == 1)
		 {
			 SetBullet(D3DXVECTOR3(g_posPlayer.x, g_posPlayer.y-PLAYER_SIZE_Y/2.0f, g_posPlayer.z), D3DXVECTOR3(-6.0f, 0.0f, 0.0f));
			 //サウンドの再生
			 PlaySound(SOUND_LABEL_SE_SHOT);
		 }
		
	}
	if (g_movePlayer.x >= 1.0f||g_movePlayer.x<=-1.0f)
	{
		//パターン更新
		g_player.nCounterAnim++; //カウンター加算

		if ((g_player.nCounterAnim % 5) == 0)
		{
		
			g_player.nPatternAnim++; //カウンター加算

			if (g_player.nPatternAnim >= 4)//総パターンを超えた
			{
				g_player.nPatternAnim = 0;//カウントを0に戻す
			}

			//頂点バッファをロックし、頂点情報へポインタ取得
			g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

			//テクスチャ座標
			pVtx[0].tex = D3DXVECTOR2(0.0f + (0.33f*(g_player.nPatternAnim)), 0.25f*g_player.nDirectionMove);
			pVtx[1].tex = D3DXVECTOR2(0.33f + (0.33f*(g_player.nPatternAnim)), 0.25f*g_player.nDirectionMove);
			pVtx[2].tex = D3DXVECTOR2(0.0f + (0.33f*(g_player.nPatternAnim)), 0.25f*(g_player.nDirectionMove+1));
			pVtx[3].tex = D3DXVECTOR2(0.33f + (0.33f*(g_player.nPatternAnim)), 0.25f*(g_player.nDirectionMove+1));
			//頂点バッファアンロック
			g_pVtxBuffPlayer->Unlock();
		}
		else
		{//停止中
			if (g_player.nCounterAnim)
			{

			}



		}
		
	}

	


	switch (g_player.state)
	{
	case PLAYERSTATE_NORMAL:
		break;

	case PLAYERSTATE_DAMAGE:
		g_player.nCounterState--;

		if (g_player.nCounterState <= 0)
		{
			g_player.state = PLAYERSTATE_NORMAL;

			/*VERTEX_2D*pVtx;*/

			//頂点バッファをロックし、頂点情報へポインタ取得
			g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

			//pVtx += 4 * nDamage;//ポインタを４つ分進める

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//頂点バッファアンロック
			g_pVtxBuffPlayer->Unlock();
		}
		break;

		case PLAYERSTATE_DEATH:
			g_player.nCounterState--;

			if (g_player.nCounterState <= 0 && fade == FADE_NONE)
			{
				SaveHigeScore();
				//モード設定(ゲーム画面に移行)
				SetFade(MODE_RESULT);

				return;
			}
			break;
		}
		
		////位置を更新
		//g_posPlayer += g_movePlayer;

		//前回の位置を保存
		g_posOldPlayer = g_posPlayer;

	
		//移動値
		g_movePlayer.y += PLAYER_Z/2;
		g_posPlayer.x += g_movePlayer.x/2;
		g_posPlayer.y += g_movePlayer.y/2;
		g_movePlayer.x = (-g_movePlayer.x)*0.1f/2;
		
		//画面外処理
		if (g_posPlayer.x - PLAYER_SIZE_X / 2 >= SCREEN_WIDTH)
		{//画面の右に当たった
			g_posPlayer.x = 0.0f - PLAYER_SIZE_X / 2;
			g_posOldPlayer.x = 0.0f - PLAYER_SIZE_X / 2;
		}
		else if (g_posPlayer.x + PLAYER_SIZE_X / 2 < 0.0f)
		{//画面の左に当たった
			g_posPlayer.x = SCREEN_WIDTH + PLAYER_SIZE_X / 2;
			g_posOldPlayer.x = SCREEN_WIDTH+PLAYER_SIZE_X / 2;
		}
		
		if (g_posPlayer.y + PLAYER_SIZE_Y / 2 >= SCREEN_HEIGHT == true && fade == FADE_NONE)
		{//プレイヤーが下に当たった
			SaveHigeScore();
			SetFade(MODE_RESULT);
			return;
		}
		
		//ブロックとの当たり判定
		bool blsLanding = CollisionBlock(
			&g_posPlayer,
			&g_posOldPlayer,
			&g_movePlayer,
			PLAYER_SIZE_X,
			PLAYER_SIZE_Y);

		//ブロックとの当たり判定
		 CollisionBlockB(
			&g_posPlayer,
			&g_posOldPlayer,
			&g_movePlayer,
			PLAYER_SIZE_X,
			PLAYER_SIZE_Y);


		//アイテムとの当たり判定
		 CollisionItemB
		 (&g_posPlayer,
			&g_posOldPlayer,
			&g_movePlayer,
			 PLAYER_SIZE_X,
			 PLAYER_SIZE_Y);



		//頂点バッファをロックし、頂点情報へポインタ取得
		g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

		pVtx[0].pos = D3DXVECTOR3(g_posPlayer.x - PLAYER_SIZE_X / 2, g_posPlayer.y - PLAYER_SIZE_Y, g_posPlayer.z);
		pVtx[1].pos = D3DXVECTOR3(g_posPlayer.x + PLAYER_SIZE_X / 2, g_posPlayer.y - PLAYER_SIZE_Y, g_posPlayer.z);
		pVtx[2].pos = D3DXVECTOR3(g_posPlayer.x - PLAYER_SIZE_X / 2, g_posPlayer.y, g_posPlayer.z);
		pVtx[3].pos = D3DXVECTOR3(g_posPlayer.x + PLAYER_SIZE_X / 2, g_posPlayer.y, g_posPlayer.z);

		if (g_player.bDisp == true)
		{//敵が使用される
		    Enemy*pEnemy;
		    int nCntEnemy;
		    pEnemy = GetEnemy();

		    for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++, pEnemy++)
		    {
			    if (pEnemy->bUse== true)
			    {//敵がいるとき
				    if (pEnemy->pos.x + ENEMY_SIZE_X / 2 > g_posPlayer.x &&
				 	   pEnemy->pos.x - ENEMY_SIZE_X / 2 < g_posPlayer.x &&
				 	   pEnemy->pos.y + ENEMY_SIZE_Y / 2 > g_posPlayer.y &&
				 	   pEnemy->pos.y - ENEMY_SIZE_Y / 2 < g_posPlayer.y)

				    {//敵とプレイヤーが当たった

				 	//サウンドの再生
				 	   PlaySound(SOUND_LABEL_SE_bakuha);

				 	   HitPlayer(5);
				    }


			    }
			    
		    }
		}
		
		//ブロックの上でジャンプ
		if (blsLanding == true)
		{
			g_player.bIsJumping = false;
		}
		/*else
		{
			if (g_player.bIsJumping == false)
			{
				g_player.bIsJumping = true;
			}
		}*/


		//頂点バッファアンロック
		g_pVtxBuffPlayer->Unlock();
	}



//ポリゴンの描画処理
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	/*if (g_player.bDisp == true)
	{*/
		//頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffPlayer, 0, sizeof(VERTEX_2D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_2D);

		//テクスチャの設定
		pDevice->SetTexture(0, g_pTexturePlayer);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	/*}*/
}

//プレイヤーのヒット処理
void HitPlayer(int nDamage)
{
	// フェード情報の取得
	FADE fade = GetFade();

	/*g_player.nLife = 10;*/

	g_player.nLife -= nDamage;

	if (g_player.nLife <= 0 && fade == FADE_NONE)
	{

		g_player.bDisp = false;
		g_player.state = PLAYERSTATE_DEATH;
		g_player.nCounterState = 60;
		SaveHigeScore();
		//モード設定(ゲーム画面に移行)
		SetFade(MODE_RESULT);

		return;
	}
	else
	{
		g_player.state = PLAYERSTATE_DAMAGE;
		g_player.nCounterState = 4;

		VERTEX_2D*pVtx;

		//頂点バッファをロックし、頂点情報へポインタ取得
		g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

		 //頂点カラーの設定
		pVtx[0].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 0, 0, 255);

		//頂点バッファアンロック
		g_pVtxBuffPlayer->Unlock();
		
	}


}
