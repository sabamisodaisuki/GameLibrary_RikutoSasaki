#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include "Enemy.h"
#include"bg2.h"
#include"game.h"

////マクロ定犠
#define MAX_AWA		(5)					//泡の数
#define AWA_SIZE			(140.0f)	//敵のサイズ
#define NUM_AWA		(5)
//グローバル変数
LPDIRECT3DTEXTURE9 g_apTextureBG2=NULL;	//テクスチャ三枚分
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBG2 = NULL;	//頂点バッファ
BG2 g_aBG2[MAX_AWA];
int g_nBG2Couter;								//float g_aPosTexV[NUM_BG];						//テクスチャ座標開始位置（V値）

//背景の初期化処理
void lnitBG2(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ
								
	//背景の初期化
	for (int nCntBG2 = 0; nCntBG2 < MAX_AWA; nCntBG2++)
	{
		g_aBG2[nCntBG2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBG2[nCntBG2].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBG2[nCntBG2].bUse = false;
	}

	g_nBG2Couter = 0;

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/awa2.png",		//	NEW2		
		&g_apTextureBG2);

	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D)* 4 *MAX_AWA*NUM_AWA,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBG2,
		NULL);

	VERTEX_2D*pVtx;		//頂点情報へポインタ

						
	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBG2->Lock(0, 0, (void**)&pVtx, 0);


	for (int nCntAWA = 0; nCntAWA < MAX_AWA; nCntAWA++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(200.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 200.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(200.0f, 200.0f, 0.0f);

		//rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの描画
		pVtx[0].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
		pVtx[1].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
		pVtx[2].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
		pVtx[3].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);

		//テクスチャ座標
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}
	//頂点バッファアンロック
	g_pVtxBuffBG2->Unlock();
}
//}

void UninitBG2(void)
{
	int nCntAWA;

	for (nCntAWA = 0; nCntAWA < NUM_AWA; nCntAWA++)
	{
		{ //テクスチャの破棄
			if (g_apTextureBG2 != NULL)
			{
				g_apTextureBG2->Release();
				g_apTextureBG2 = NULL;
			}
		}
	}
	//バッファの破棄
	if (g_pVtxBuffBG2 != NULL)
	{
		g_pVtxBuffBG2->Release();
		g_pVtxBuffBG2= NULL;
	}
}

void UpdateBG2(void)
{
	VERTEX_2D*pVtx;		//頂点情報へポインタ

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBG2->Lock(0, 0, (void**)&pVtx, 0);

	g_nBG2Couter++;
	
	if (g_nBG2Couter == 350)
	{
		SetBG2(D3DXVECTOR3(400.0f, 900.0f, 0.0f), D3DXVECTOR3(0.0f, -5.0f, 0.0f));
		g_nBG2Couter = 0;
	}
	
	for (int nCntAWA = 0; nCntAWA < MAX_AWA; nCntAWA++)
	{
		if (g_aBG2[nCntAWA].bUse == true)
		{
			//エネミーの位置の更新

			g_aBG2[nCntAWA].pos += g_aBG2[nCntAWA].move;

			//頂点座標の更新(エネミーの大きさ）
			pVtx[0].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x - AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y - AWA_SIZE / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x + AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y - AWA_SIZE / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x - AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y + AWA_SIZE / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x + AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y + AWA_SIZE / 2, 0.0f);

			if (g_aBG2[nCntAWA].pos.y <= 6)

			{//画面外にエネミーが出た時
				g_aBG2[nCntAWA].bUse = false;
			}

		}
		pVtx += 4;
	}
	//頂点バッファアンロック
	g_pVtxBuffBG2->Unlock();
}

void DrawBG2(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffBG2, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	////テクスチャの設定
	//pDevice->SetTexture(0, g_apTextureBG2[nCntAWA]);

	for (int nCntBG2 = 0; nCntBG2 < MAX_AWA; nCntBG2++)
	{
		if (g_aBG2[nCntBG2].bUse == true)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, g_apTextureBG2);
			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBG2*4, 2);
		}
	}
}

void SetBG2(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	
		int nCntBG2;

		VERTEX_2D*pVtx;

		//頂点バッファロックし、頂点情報へポインタ取得
		g_pVtxBuffBG2->Lock(0, 0, (void**)&pVtx, 0);

		for (nCntBG2 = 0; nCntBG2 < MAX_AWA; nCntBG2++)
		{
			if (g_aBG2[nCntBG2].bUse == false)
			{//敵が使用されてない場合

			 //敵の情報の設定
				g_aBG2[nCntBG2].pos = pos;

				//頂点座標の更新
				pVtx[0].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x - 6.0f, g_aBG2[nCntBG2].pos.y - 6.0f, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x + 6.0f, g_aBG2[nCntBG2].pos.y - 6.0f, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x - 6.0f, g_aBG2[nCntBG2].pos.y + 6.0f, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x + 6.0f, g_aBG2[nCntBG2].pos.y + 6.0f, 0.0f);


				//頂点カラーの描画
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

				g_aBG2[nCntBG2].move = move;
				g_aBG2[nCntBG2].bUse = true;	//使用している状態にする

				break;
			}
			pVtx += 4;//ポインタを４つ分進める
		}
		g_pVtxBuffBG2->Unlock();
	}
