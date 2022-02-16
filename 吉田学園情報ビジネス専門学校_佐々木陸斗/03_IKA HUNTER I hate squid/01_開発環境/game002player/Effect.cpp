#include "main.h"
#include "player.h"
#include "input.h"
#include"Effect.h"
#include "Effect.h"
#include"title.h"
//マクロ定義
#define MAX_EFFECT			(4096)		//エフェクトの最大数

//エフェクトの構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;		//位置
	D3DXCOLOR col;			//色
	D3DXVECTOR3 move;		//移動
	float fRadius;			//半径（大きさ）
	int nLife;				//寿命（表示時間）
	bool bUse;				//使用しているかどうか

}Effect;

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureEffect = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffEffect = NULL;
Effect g_aEffect[MAX_EFFECT];


//弾の初期化処理
void lnitEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEffect;

	//デバイスの取得
	pDevice = GetDevice();


	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/effect000.jpg",					//akira000.png,koda.jpg,su.jpg,runningman100.png,Effect000.png,人参.png,金人参.png,ぺこら.jpg
		&g_pTextureEffect);

	//弾の情報の初期化
	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		g_aEffect[nCntEffect].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEffect[nCntEffect].nLife = 10;
		g_aEffect[nCntEffect].bUse = false;
	}
	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_EFFECT,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffEffect,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ
						/*int nCntEffect;*/

						//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
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
	g_pVtxBuffEffect->Unlock();
}
//ポリゴンの終了処理
void UninitEffect(void)
{
	//テクスチャの破棄
	if (g_pTextureEffect != NULL)
	{
		g_pTextureEffect->Release();
		g_pTextureEffect = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffEffect != NULL)
	{
		g_pVtxBuffEffect->Release();
		g_pVtxBuffEffect = NULL;
	}

}
//弾の更新処理
void UpdateEffect(void)
{
	int nCntEffect;

	VERTEX_2D*pVtx;

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == true)
		{//エフェクトが使用される
		/*	Effect*pEffect;*/
			/*int nCntEffect;*/
			
			////弾の位置の更新
			//g_aEffect[nCntEffect].pos += g_aEffect[nCntEffect].move;


			//頂点カラーの描画
			pVtx[0].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);

			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);




			/*if (g_aEffect[nCntEffect].pos.y <= 6)*/

			//{//画面外に弾が出た時
			//	g_aEffect[nCntEffect].bUse = false;
			//}

			////寿命のカウントダウン

			//g_aEffect[nCntEffect].nLife -= 1;

			//if (g_aEffect[nCntEffect].nLife == 0)
			//{
			//	g_aEffect[nCntEffect].bUse = false;
			//}

			
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	//頂点バッファアンロック
	g_pVtxBuffEffect->Unlock();
}
//弾の描画処理
void DrawEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEffect;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffEffect, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	////aプレディングを加算合成に設定
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	//{
	//	if (g_aEffect[nCntEffect].bUse == true)
	//	{
	//		//ポリゴンの描画
	//		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);
	//	}
	//}

	////aプレディングを加算合成に設定
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);


	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == true)
		{//弾が使用されている
		 //	Effect*pEffect = GetEffect();
		
		 //テクスチャの設定
			pDevice->SetTexture(0, g_pTextureEffect);
			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_2D);

			//aプレディングを加算合成に設定
			pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

			for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
			{
				if (g_aEffect[nCntEffect].bUse == true)
				{
					//ポリゴンの描画
					pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);
				}
			}
			////ポリゴンの描画
			//pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);
		}
	}
}
//弾の設定処理
void SetEffect(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntEffect;
	VERTEX_2D*pVtx;
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == false)
		{//弾が使用されてない場合
			g_aEffect[nCntEffect].pos = pos;

			//頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x - 6.0f, g_aEffect[nCntEffect].pos.y - 6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x + 6.0f, g_aEffect[nCntEffect].pos.y - 6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x - 6.0f, g_aEffect[nCntEffect].pos.y + 6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x + 6.0f, g_aEffect[nCntEffect].pos.y + 6.0f, 0.0f);

			g_aEffect[nCntEffect].move = move;
			g_aEffect[nCntEffect].nLife = 100;
			g_aEffect[nCntEffect].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtxBuffEffect->Unlock();
}


//エフェクトの設定処理
void SetEffect(D3DXVECTOR3 pos, D3DXCOLOR col, float fRadius, int nLife)
{
	int nCntEffect;
	
	for(nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == false)
		{
			g_aEffect[nCntEffect].pos = pos;
			g_aEffect[nCntEffect].col = col;
			g_aEffect[nCntEffect].fRadius = fRadius;
			g_aEffect[nCntEffect].nLife = nLife;
			g_aEffect[nCntEffect].bUse = true;

			break;
		}
	}
}
