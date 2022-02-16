#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"Enemy.h"
#include"blockB.h"
//マクロ定義
#define MAX_BLOCKB			(128)		//ブロックの最大数
#define BLOCKB_SIZE_X			(100.0f)		//ブロックサイズ
#define BLOCKB_SIZE_Y			(100.0f)		//ブロックサイズ


//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureBlockB = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffBlock1 = NULL;
block g_aBlockB[MAX_BLOCKB];


//ブロックの初期化処理
void lnitblockB(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblockB;

	//デバイスの取得
	pDevice = GetDevice();



	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/サメB.png",
		&g_pTextureBlockB);

	//ブロックの情報の初期化
	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		g_aBlockB[nCntblockB].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlockB[nCntblockB].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlockB[nCntblockB].bUse = false;

	}
	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_BLOCKB,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffBlock1,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ

						//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtexBuffBlock1->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
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
	g_pVtexBuffBlock1->Unlock();


	//ブロック位置
	
	SetblockB(D3DXVECTOR3(240.0f, 120.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (70.0f));//左端壁


	SetblockB(D3DXVECTOR3(450.0f, 260.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (80.0f));//左端壁

	SetblockB(D3DXVECTOR3(650.0f, 130.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (40.0f), (70.0f));//左端壁

	SetblockB(D3DXVECTOR3(1100.0f, 180.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (70.0f));//左端壁

	
}
//ブロッ終了処理
void UninitblockB(void)
{
	//テクスチャの破棄
	if (g_pTextureBlockB != NULL)
	{
		g_pTextureBlockB->Release();
		g_pTextureBlockB = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtexBuffBlock1 != NULL)
	{
		g_pVtexBuffBlock1->Release();
		g_pVtexBuffBlock1 = NULL;
	}

}
//ブロックの更新処理
void UpdateblockB(void)
{





}
//ブロックの描画処理
void DrawblockB(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblockB;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtexBuffBlock1, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		if (g_aBlockB[nCntblockB].bUse == true)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureBlockB);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntblockB * 4, 2);
		}
	}
}
//ブロックの設定処理
void SetblockB(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight)
{

	int nCntblockB;
	VERTEX_2D*pVtx;
	g_pVtexBuffBlock1->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		if (g_aBlockB[nCntblockB].bUse == false)
		{//ブロックが使用されてない場合
			g_aBlockB[nCntblockB].pos = pos;
			g_aBlockB[nCntblockB].fWidth = fWidth;//幅
			g_aBlockB[nCntblockB].fHeight = fHeight;//高さ
												  //頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2, 0.0f);

	
			g_aBlockB[nCntblockB].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtexBuffBlock1->Unlock();
}

//ブロックの当たり判定
bool CollisionBlockB(D3DXVECTOR3*pPos,//現在の位置
	D3DXVECTOR3*pPosOld,			//前回の高さ
	D3DXVECTOR3*pMove,				//移動量
	float fWidth,					//幅
	float fHeight)					//高さ
{


	bool bIsLanding = false;		//着地しているかどうか

	for (int nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		if (g_aBlockB[nCntblockB].bUse == true)//使用している場合
		{
			//上の当たり判定
			if (g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 > pPos->x - fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 >= pPosOld->y &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 < pPos->y)

				//ブロックにめり込んだ
			{
				
				bIsLanding = true;
				pPos->y = g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2;
				pMove->y = 0.0f;
				HitPlayer(10);
			}
			//下の当たり判定
			else if (g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 > pPos->x - fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 <= pPosOld->y - fHeight &&
				g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 > pPos->y - fHeight)
			{
				pPos->y = g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 + fHeight;
				pMove->y = 0.0f;

				HitPlayer(10);
			}
			//右の当たり判定
			else if (g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 > pPos->y - fHeight &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 < pPos->y + fHeight &&
				g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 <= pPosOld->x - fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 > pPos->x - fWidth / 2)

				//ブロックにめり込んだ
			{
				pPos->x = g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 + fWidth / 2;
				pMove->x = 0.0f;
				
				HitPlayer(10);
			}
			//左の当たり判定
			else if (g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 > pPos->y - fHeight / 2 &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 < pPos->y + fHeight / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 >= pPosOld->x + fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 < pPos->x + fWidth / 2)

				//ブロックにめり込んだ
			{

				pPos->x = g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 - fWidth / 2;
				pMove->x = 0.0f;
				HitPlayer(10);
			}
		}

	}
	return bIsLanding;
}