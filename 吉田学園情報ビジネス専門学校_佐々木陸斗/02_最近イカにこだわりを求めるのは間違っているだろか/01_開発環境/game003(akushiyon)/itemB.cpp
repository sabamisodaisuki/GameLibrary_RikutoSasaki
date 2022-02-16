#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"item.h"
#include"itemB.h"
#include"Score.h"
#include"sound.h"
#include"fade.h"
#include"HighScore.h"
//マクロ定義
#define MAX_ITEMB			(128)		//ブロックの最大数
#define ITEMB_SIZE_X			(100.0f)		//ブロックサイズ
#define ITEMB_SIZE_Y			(100.0f)		//ブロックサイズ


//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureITEMB = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffITEMB = NULL;
ItemB g_aItemB[MAX_ITEMB];
int g_CounterItem;



//ブロックの初期化処理
void lnitItemb(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitemB;

	//デバイスの取得
	pDevice = GetDevice();



	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/kabo1.png",
		&g_pTextureITEMB);

	//ブロックの情報の初期化
	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
	{
		g_aItemB[nCntitemB].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItemB[nCntitemB].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItemB[nCntitemB].bUse = false;


	}

	  g_CounterItem = 0;

	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEMB,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffITEMB,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ

						//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtexBuffITEMB->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
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
	g_pVtexBuffITEMB->Unlock();


	//ブロック位置
	SetItemb(D3DXVECTOR3(250.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));

	//ブロック位置
	SetItemb(D3DXVECTOR3(640.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0), (50.0f));

	//ブロック位置
	SetItemb(D3DXVECTOR3(950.0f,640.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0), (50.0f));

	//ブロック位置
	SetItemb(D3DXVECTOR3(350.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0), (50.0f));

	

}
//ブロッ終了処理
void UninitItemb(void)
{
	//サウンドの停止
	StopSound();

		//テクスチャの破棄
		if (g_pTextureITEMB != NULL)
		{
			g_pTextureITEMB->Release();
			g_pTextureITEMB = NULL;
		}
		//頂点バッファの破棄
		if (g_pVtexBuffITEMB != NULL)
		{
			g_pVtexBuffITEMB->Release();
			g_pVtexBuffITEMB = NULL;
		}
}
//ブロックの更新処理
void UpdateItemb(void)
{
	


}
//ブロックの描画処理
void DrawItemb(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitemB;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtexBuffITEMB, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
	{
		if (g_aItemB[nCntitemB].bUse == true)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureITEMB);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntitemB * 4, 2);
		}
	}
}
//ブロックの設定処理
void SetItemb(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight)
{

	int nCntitemB;
	VERTEX_2D*pVtx;
	g_pVtexBuffITEMB->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
	{
		if (g_aItemB[nCntitemB].bUse == false)
		{//ブロックが使用されてない場合
			g_aItemB[nCntitemB].pos = pos;
			g_aItemB[nCntitemB].fWidth = fWidth;//幅
			g_aItemB[nCntitemB].fHeight = fHeight;//高さ
			//頂点座標の更新w
			pVtx[0].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x - g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y - g_aItemB[nCntitemB].fHeight / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x + g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y - g_aItemB[nCntitemB].fHeight / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x - g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y + g_aItemB[nCntitemB].fHeight / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x + g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y + g_aItemB[nCntitemB].fHeight / 2, 0.0f);

			g_aItemB[nCntitemB].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtexBuffITEMB->Unlock();
}

void CollisionItemB(D3DXVECTOR3*pPos,//現在の位置
	D3DXVECTOR3*pPosOld,			//前回の高さ
	D3DXVECTOR3*pMove,				//移動量
	float fWidth,					//幅
	float fHeight)
{
	ItemB*pItemB;
	int nCntItemB;
	pItemB = GetItemB();

	for (nCntItemB = 0; nCntItemB < MAX_ITEMB; nCntItemB++)
	{
		if (g_aItemB[nCntItemB].bUse == true)
		{

			if (g_aItemB[nCntItemB].pos.x - g_aItemB[nCntItemB].fWidth/2  < pPos->x + fWidth/2  &&
				g_aItemB[nCntItemB].pos.x + g_aItemB[nCntItemB].fWidth/2  > pPos->x - fWidth/2  &&
				g_aItemB[nCntItemB].pos.y + g_aItemB[nCntItemB].fHeight/2  > pPos->y-fHeight &&
				g_aItemB[nCntItemB].pos.y - g_aItemB[nCntItemB].fHeight/2 < pPos->y)
			{
				DeleteItemB(nCntItemB);
			}
		}
		pItemB++;
	}
}
void DeleteItemB(int nCntItemB)
{
	
	//サウンドの再生
	PlaySound(SOUND_LABEL_SE_bakuha);
	// フェード情報の取得
	FADE fade = GetFade();

	g_CounterItem++;
		//使用していない状態へ
		g_aItemB[nCntItemB].bUse = false;

		//スコア設定
		AddScore(15000);
		
		for (nCntItemB = 0; nCntItemB < MAX_ITEMB; nCntItemB++)
		{

			if (g_CounterItem == 4)//アイテムをすべて取りリザルト画面へ
			{
				SaveHigeScore();
				SetFade(MODE_WIN);
				return;
			}
		}
	
}
//アイテムの取得
ItemB*GetItemB(void)
{
	return &g_aItemB[0];
}