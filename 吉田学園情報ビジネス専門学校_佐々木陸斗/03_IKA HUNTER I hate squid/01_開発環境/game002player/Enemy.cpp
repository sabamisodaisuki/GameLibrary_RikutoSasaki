#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Enemy.h"
#include"title.h"
#include"bg.h"
#include"explosion.h"
#include"game.h"
#include"result.h"
#include"Score.h"
#include"sound.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_apTextureEnemy[NUM_ENEMY] = {NULL};	//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffEnemy = NULL;			//頂点バッファポインタ
Enemy g_aEnemy[MAX_ENEMY];								//敵の情報
int g_nEnemyCouter;										//敵のカウント


//エネミーの取得
Enemy*GetEnemy(void)
{
	return &g_aEnemy[0];
}

//エネミーの初期化処理
void lnitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEnemy;


	//カウンターの初期化
	nCntEnemy = 0;

	//デバイスの取得
	pDevice = GetDevice();


	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ikaa.png",
		&g_apTextureEnemy[0]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika001.png",
		&g_apTextureEnemy[1]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika002.png",
		&g_apTextureEnemy[2]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika03.png",
		&g_apTextureEnemy[3]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika004.png",
		&g_apTextureEnemy[4]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika005.png",
		&g_apTextureEnemy[5]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika06.png",
		&g_apTextureEnemy[6]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika007.png",
		&g_apTextureEnemy[7]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika008.png",
		&g_apTextureEnemy[8]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika09.png",
		&g_apTextureEnemy[9]);


	//エネミーの初期化
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		g_aEnemy[nCntEnemy].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].nType = 0;
		g_aEnemy[nCntEnemy].bUse = false;
	}

	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ENEMY * NUM_ENEMY,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffEnemy,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ

//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
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
	g_pVtxBuffEnemy->Unlock();
}
//ポリゴンの終了処理
void UninitEnemy(void)
{
	int nCntEnemy;


	for (nCntEnemy = 0; nCntEnemy < NUM_ENEMY; nCntEnemy++)
	{ //テクスチャの破棄
		if (g_apTextureEnemy[nCntEnemy] != NULL)
		{
			g_apTextureEnemy[nCntEnemy]->Release();
			g_apTextureEnemy[nCntEnemy] = NULL;
		}
	}

	//頂点バッファの破棄
	if (g_pVtxBuffEnemy != NULL)
	{
		g_pVtxBuffEnemy->Release();
		g_pVtxBuffEnemy = NULL;
	}

}
//エネミーの更新処理
void UpdateEnemy(void)
{

	int nCntEnemy;
	VERTEX_2D*pVtx;
	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	g_nEnemyCouter++;			//敵の間隔
	
	if (g_nEnemyCouter == 60)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 240.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 0);
	}

	if (g_nEnemyCouter == 70)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 330.0f, 0.0f), D3DXVECTOR3(-3.0f, 0.0f, 0.0f), 1);
	
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 450.0f, 0.0f), D3DXVECTOR3(-8.0f, 0.0f, 0.0f), 2);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 120.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 4);

	}
	if (g_nEnemyCouter == 80)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 240.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 0);
	}

	if (g_nEnemyCouter == 95)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 330.0f, 0.0f), D3DXVECTOR3(-3.0f, 0.0f, 0.0f), 1);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 450.0f, 0.0f), D3DXVECTOR3(-8.0f, 0.0f, 0.0f), 2);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 120.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 4);

	}
	//左
	if (g_nEnemyCouter == 70)
	{
		SetEnemy(D3DXVECTOR3(0, 250.0f, 0.0f), D3DXVECTOR3(8.0f, 0.0f, 0.0f), 3);

	}

	if (g_nEnemyCouter == 90)
	{
		SetEnemy(D3DXVECTOR3(0, 350.0f, 0.0f), D3DXVECTOR3(8.0f, 0.0f, 0.0f), 3);

	}

	if (g_nEnemyCouter == 80)
	{
		/*SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 330.0f, 0.0f), D3DXVECTOR3(-3.0f, 0.0f, 0.0f), 5);*/
	
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 330.0f, 0.0f), D3DXVECTOR3(-2.0f, 0.0f, 0.0f), 6);
	
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 290.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 7);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 420.0f, 0.0f), D3DXVECTOR3(-5.0f,  0.0f, 0.0f), 8);
	}
	if (g_nEnemyCouter == 140)
	{
		/*SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 330.0f, 0.0f), D3DXVECTOR3(-3.0f, 0.0f, 0.0f), 5);*/

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 330.0f, 0.0f), D3DXVECTOR3(-2.0f, 0.0f, 0.0f), 6);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 290.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 7);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 420.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 8);
	}
	if (g_nEnemyCouter == 100)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 290.0f, 0.0f), D3DXVECTOR3(-15.0f, 0.0f, 0.0f), 5);

		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 420.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 8);
	}
	if (g_nEnemyCouter == 270)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 240.0f, 0.0f), D3DXVECTOR3(-50.0f, 0.0f, 0.0f), 9);

		/*g_nEnemyCouter = 0;*/
	}

	if (g_nEnemyCouter == 270)
	{
		SetEnemy(D3DXVECTOR3(0, 240.0f, 0.0f), D3DXVECTOR3(50.0f, 0.0f, 0.0f), 9);

		/*g_nEnemyCouter = 0;*/
	}

	if (g_nEnemyCouter == 270)
	{
		SetEnemy(D3DXVECTOR3(SCREEN_WIDTH, 420.0f, 0.0f), D3DXVECTOR3(-50.0f, 0.0f, 0.0f), 9);

		g_nEnemyCouter = 0;
	}


	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{
			switch (g_aEnemy[nCntEnemy].state)
			{
			case ENEMYSTA_NORMAL:
				break;

			case ENEMYSTA_DAMAGE:
				g_aEnemy[nCntEnemy].nCounterState--;

				if (g_aEnemy[nCntEnemy].nCounterState <= 0)
				{
					g_aEnemy[nCntEnemy].state = ENEMYSTA_NORMAL;

					VERTEX_2D*pVtx;

					//頂点バッファをロックし、頂点情報へポインタ取得
					g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

					//pVtx += 4 * nDamage;//ポインタを４つ分進める

					//頂点カラーの設定
					pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
					pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
					pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
					pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

					//頂点バッファアンロック
					g_pVtxBuffEnemy->Unlock();
				}
				break;
			}
		}
	}
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{//エネミーが出現される
			
		 //エネミーの位置の更新

			g_aEnemy[nCntEnemy].pos += g_aEnemy[nCntEnemy].move;

			//頂点座標の更新(エネミーの大きさ）
			pVtx[0].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE/2, g_aEnemy[nCntEnemy].pos.y + ENEMY_SIZE/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE/2, g_aEnemy[nCntEnemy].pos.y + ENEMY_SIZE/2, 0.0f);

			if (g_aEnemy[nCntEnemy].pos.x <= 6)

			{//画面外にエネミーが出た時
				g_aEnemy[nCntEnemy].bUse = false;
			}
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	//頂点バッファアンロック
	g_pVtxBuffEnemy->Unlock();
}

//エネミーの描画処理
void DrawEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEnemy;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffEnemy, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{//敵が使用されている

		 //テクスチャの設定
			pDevice->SetTexture(0, g_apTextureEnemy[g_aEnemy[nCntEnemy].nType]);

		 //ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEnemy * 4, 2);
		}
	}
}



//エネミーの設定処理
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 move,int nType)
{
	int nCntEnemy;

	VERTEX_2D*pVtx;

	//頂点バッファロックし、頂点情報へポインタ取得
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == false)
		{//敵が使用されてない場合

			//敵の情報の設定
			g_aEnemy[nCntEnemy].pos = pos;

			//頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - 6.0f, g_aEnemy[nCntEnemy].pos.y - 6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + 6.0f, g_aEnemy[nCntEnemy].pos.y - 6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - 6.0f, g_aEnemy[nCntEnemy].pos.y + 6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + 6.0f, g_aEnemy[nCntEnemy].pos.y + 6.0f, 0.0f);


			//頂点カラーの描画
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			g_aEnemy[nCntEnemy].move = move;
			g_aEnemy[nCntEnemy].nLife = 10;
			g_aEnemy[nCntEnemy].bUse = true;	//使用している状態にする
			g_aEnemy[nCntEnemy].nType = nType;
			/*g_aEnemy[nCntEnemy].nScore = 500;*/

			break;
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtxBuffEnemy->Unlock();
}
//敵のヒット処理
void HitEnemy(int nCntEnemy, int nDamage)
{
	g_aEnemy[nCntEnemy].nLife -= nDamage;

	if (g_aEnemy[nCntEnemy].nLife <= 0)
	{
		//爆発の設定
		AddScore(500);

		g_aEnemy[nCntEnemy].bUse = false;
	}
	else
	{
		g_aEnemy[nCntEnemy].state = ENEMYSTA_DAMAGE;
		g_aEnemy[nCntEnemy].nCounterState = 15;

		VERTEX_2D*pVtx;
		
		//頂点バッファをロックし、頂点情報へポインタ取得
		g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

		pVtx += 4*nCntEnemy;//ポインタを４つ分進める

		//頂点カラーの設定
		pVtx[0].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 0, 0, 255);
	
		//頂点バッファアンロック
		g_pVtxBuffEnemy->Unlock();
	}
}
