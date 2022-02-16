#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Enemy.h"
#include"title.h"
#include"game.h"
#include"bg.h"
#include"sound.h"
#include"fade.h"
#include"titleb.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureTitleb = NULL;//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitleb = NULL;//頂点バッファへのぽんった


											   //タイトル画面の初期化処理
void lnitTitleb(void)
{
	LPDIRECT3DDEVICE9 pDevice;


	//サウンドの再生
	PlaySound(SOUND_LABEL_BGMTITLE);



	//デバイスの取得
	pDevice = GetDevice();


	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/DA.png",//TITOL.png"
		&g_pTextureTitleb);



	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitleb,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ

						//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffTitleb->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

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

	//頂点バッファアンロック
	g_pVtxBuffTitleb->Unlock();
}

//タイトル画面の終了処理
void UninitTitleb(void)
{
	//サウンドの停止
	StopSound();


	//テクスチャの破棄
	if (g_pTextureTitleb != NULL)
	{
		g_pTextureTitleb->Release();
		g_pTextureTitleb = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffTitleb != NULL)
	{
		g_pVtxBuffTitleb->Release();
		g_pVtxBuffTitleb = NULL;
	}
}

//タイトル画面の更新処理
void UpdateTitleb(void)
{
	// フェード情報の取得
	FADE fade = GetFade();

	//決定キー(ENTERキーが押されたかどうか)
	if (GetKeyboardTrigger(DIK_RETURN) == true && fade == FADE_NONE)
	{
		//サウンドの再生
		PlaySound(SOUND_LABEL_SE_ketei);

		//モード設定
		SetFade(MODE_TITLE);
	}

}

//タイトル画面の描画処理
void DrawTitleb(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffTitleb, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureTitleb);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

