#include "main.h"
#include "player.h"
#include "input.h"
#include"bg.h"


////マクロ定義
//#define NUM_BG	(2)		//背景の数

//グローバル変数
LPDIRECT3DTEXTURE9 g_apTextureBG = NULL;/*[NUM_BG] = {};*/	//テクスチャ三枚分
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBG = NULL;	//頂点バッファ
//float g_aPosTexV[NUM_BG];						//テクスチャ座標開始位置（V値）

//背景の初期化処理
void lnitBG(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ
	/*int nCntBG;			
*/
	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BGG.png",		//	NEW2	haik.png",	
		&g_apTextureBG);

	////テクスチャの読み込み
	//D3DXCreateTextureFromFile(pDevice,
	//	"data/TEXTURE/awa2.png",		//	NEW2		
	//	&g_apTextureBG[1]);



	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBG,
		NULL);

	VERTEX_2D*pVtx;		//頂点情報へポインタ

	//for (nCntBG = 0; nCntBG < NUM_BG; nCntBG++)
	//{
		//頂点バッファをロックし、頂点情報へポインタ取得
		g_pVtxBuffBG->Lock(0, 0, (void**)&pVtx, 0);

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

		//頂点バッファアンロック
		g_pVtxBuffBG->Unlock();
	}
//}

void UninitBG(void)
{
	/*int nCntBG;


	for (nCntBG = 0; nCntBG < NUM_BG; nCntBG++)*/
	{ //テクスチャの破棄
		if (g_apTextureBG != NULL)
		{
			g_apTextureBG->Release();
			g_apTextureBG = NULL;
		}
	}
	
	//バッファの破棄
	if (g_pVtxBuffBG != NULL)
	{
		g_pVtxBuffBG->Release();
		g_pVtxBuffBG = NULL;
	}
}

void UpdateBG(void)
{
	VERTEX_2D*pVtx;		//頂点情報へポインタ

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBG->Lock(0, 0, (void**)&pVtx, 0);
	{

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);


	}
	//頂点バッファアンロック
	g_pVtxBuffBG->Unlock();
}

void DrawBG(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffBG, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	
	//テクスチャの設定
	pDevice->SetTexture(0, g_apTextureBG);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0, 6);
}





