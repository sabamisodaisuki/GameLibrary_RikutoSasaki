#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Score.h"
#include"Enemy.h"
#include"sound.h"
//マクロ定義
#define MAX_BULLET			(5)		//弾の最大数
#define BULLET_SIZ			(25)		//弾サイズ

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;
Bullet g_aBullet[MAX_BULLET];

//弾の初期化処理
void lnitBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntBullet;

	//デバイスの取得
	pDevice = GetDevice();


	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/kabo1.png",					//akira000.png,koda.jpg,su.jpg,runningman100.png,bullet000.png,人参.png,金人参.png,ぺこら.jpg
		&g_pTextureBullet);

	//弾の情報の初期化
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].nLife = 10;
		g_aBullet[nCntBullet].bUse = false;
	}
	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_BULLET,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBullet,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ
	/*int nCntBullet;*/

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{

		//頂点座標の設定
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
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//テクスチャ座標
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}
	//頂点バッファアンロック
	g_pVtxBuffBullet->Unlock();

}
//ポリゴンの終了処理
void UninitBullet(void)
{
	//サウンドの停止
	StopSound();

	//テクスチャの破棄
	if (g_pTextureBullet != NULL)
	{
		g_pTextureBullet->Release();
		g_pTextureBullet = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}

}
//弾の更新処理
void UpdateBullet(void)
{
	int nCntBullet;
	VERTEX_2D*pVtx;

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
	
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//弾が使用される
			Enemy*pEnemy;
			int nCntEnemy;
			pEnemy = GetEnemy();

			//弾の位置の更新
			g_aBullet[nCntBullet].pos += g_aBullet[nCntBullet].move;

			//弾の位置の更新
			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y - BULLET_SIZ/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y - BULLET_SIZ/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y + BULLET_SIZ/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y + BULLET_SIZ/2, 0.0f);

			if (g_aBullet[nCntBullet].pos.y <= 6)

			{//画面外に弾が出た時
				g_aBullet[nCntBullet].bUse = false;
			}

			//寿命のカウントダウン

			g_aBullet[nCntBullet].nLife -= 1;

			if (g_aBullet[nCntBullet].nLife == 0)
			{
				g_aBullet[nCntBullet].bUse = false;
			}

			for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++,pEnemy++)
			{
				if (pEnemy->bUse == true)
				{//敵がいるとき
					if (pEnemy->pos.x + ENEMY_SIZE_X/ 2 > g_aBullet[nCntBullet].pos.x &&
						pEnemy->pos.x - ENEMY_SIZE_X / 2 < g_aBullet[nCntBullet].pos.x &&
              			pEnemy->pos.y + ENEMY_SIZE_Y / 2 > g_aBullet[nCntBullet].pos.y &&
						pEnemy->pos.y - ENEMY_SIZE_Y / 2 < g_aBullet[nCntBullet].pos.y)
					{//敵と弾が当たった

					
						//スコア設定
						AddScore(50);
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_EXPLOSION);

						////爆発の設定
						//SetExplosion(g_aBullet[nCntBullet].pos);

             			//pEnemy->bUse = false;//使用していない状態

						//敵のヒット処理
            			HitEnemy(nCntEnemy,5);
						
						//使用していない状態へ
						g_aBullet[nCntBullet].bUse = false;

					}

				}
			}
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	//頂点バッファアンロック
	g_pVtxBuffBullet->Unlock();
}
//弾の描画処理
void DrawBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntBullet;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//弾が使用されている
		//	Enemy*pEnemy = GetEnemy();
		//	int nCntEnemy;

		////	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
		////	{
		//		if (pEnemy->bUse == true)
		//		{

		//		}
		//	}
			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureBullet);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,nCntBullet*4, 2);
		}
	}
}
//弾の設定処理
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntBullet;
	VERTEX_2D*pVtx;
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == false)
		{//弾が使用されてない場合
			g_aBullet[nCntBullet].pos = pos;

			//頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 6.0f, g_aBullet[nCntBullet].pos.y - 6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 6.0f, g_aBullet[nCntBullet].pos.y - 6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 6.0f, g_aBullet[nCntBullet].pos.y + 6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 6.0f, g_aBullet[nCntBullet].pos.y + 6.0f, 0.0f);

			g_aBullet[nCntBullet].move = move;
			g_aBullet[nCntBullet].nLife = 100;
			g_aBullet[nCntBullet].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtxBuffBullet->Unlock();
}

