#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"item.h"
//マクロ定義
#define MAX_ITEM			(128)		//ブロックの最大数
#define ITEM_SIZE_X			(100.0f)		//ブロックサイズ
#define ITEM_SIZE_Y			(100.0f)		//ブロックサイズ


//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureITEM = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffITEM = NULL;
block g_aItem[MAX_ITEM];


//ブロックの初期化処理
void lnitItem(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitem;

	//デバイスの取得
	pDevice = GetDevice();



	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/矢印.png",
		&g_pTextureITEM);

	//ブロックの情報の初期化
	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
	{
		g_aItem[nCntitem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItem[nCntitem].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItem[nCntitem].bUse = false;

	}
	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEM,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffITEM,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ

						//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtexBuffITEM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
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
	g_pVtexBuffITEM->Unlock();


	//ブロック位置
	SetItem(D3DXVECTOR3(350.0f, 130.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));

	//ブロック位置
	SetItem(D3DXVECTOR3(980.0f, 260.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));

	//ブロック位置
	SetItem(D3DXVECTOR3(60.0f, 260.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));



}
//ブロッ終了処理
void UninitItem(void)
{
	//テクスチャの破棄
	if (g_pTextureITEM != NULL)
	{
		g_pTextureITEM->Release();
		g_pTextureITEM = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtexBuffITEM != NULL)
	{
		g_pVtexBuffITEM->Release();
		g_pVtexBuffITEM = NULL;
	}

}
//ブロックの更新処理
void UpdateItem(void)
{





}
//ブロックの描画処理
void DrawItem(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitem;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtexBuffITEM, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureITEM);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntitem * 4, 2);

	}
}
//ブロックの設定処理
void SetItem(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight)
{

	int nCntitem;
	VERTEX_2D*pVtx;
	g_pVtexBuffITEM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
	{
		if (g_aItem[nCntitem].bUse == false)
		{//ブロックが使用されてない場合
			g_aItem[nCntitem].pos = pos;
			g_aItem[nCntitem].fWidth = fWidth;//幅
			g_aItem[nCntitem].fHeight = fHeight;//高さ
			 //頂点座標の更新w
			pVtx[0].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x - g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y - g_aItem[nCntitem].fHeight / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x + g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y - g_aItem[nCntitem].fHeight / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x - g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y + g_aItem[nCntitem].fHeight / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x + g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y + g_aItem[nCntitem].fHeight / 2, 0.0f);

			g_aItem[nCntitem].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtexBuffITEM->Unlock();
}

