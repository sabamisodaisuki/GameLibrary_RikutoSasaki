#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"Enemy.h"
//マクロ定義
#define MAX_BLOCK			(128)		//ブロックの最大数
#define BLOCK_SIZE_X			(100.0f)		//ブロックサイズ
#define BLOCK_SIZE_Y			(100.0f)		//ブロックサイズ


//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureBlock = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffBlock = NULL;
block g_aBlock[MAX_BLOCK];


//ブロックの初期化処理
void lnitblock(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblock;

	//デバイスの取得
	pDevice = GetDevice();



	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ki.png",					
		&g_pTextureBlock);

	//ブロックの情報の初期化
	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		g_aBlock[nCntblock].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlock[nCntblock].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlock[nCntblock].bUse = false;

	}
	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_BLOCK,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffBlock,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ
					
	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtexBuffBlock->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
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

		

		pVtx += 4;
	}
	//頂点バッファアンロック
	g_pVtexBuffBlock->Unlock();


	//ブロック位置
	Setblock(D3DXVECTOR3(15.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f,0.0f),(30.0f),(700.0f));//左端壁
					
	Setblock(D3DXVECTOR3(70.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//左下1↑床

	Setblock(D3DXVECTOR3(250.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//右↑床
	

	Setblock(D3DXVECTOR3(70.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//左下2↑床

	Setblock(D3DXVECTOR3(70.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//左下2↑床

	Setblock(D3DXVECTOR3(250.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//左下2↑床

	Setblock(D3DXVECTOR3(165.0f, 150.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (100.0f));//左真ん中

	Setblock(D3DXVECTOR3(250.0f, 150.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (90.0f), (20.0f));//左真ん中の右

	//真ん中																					 
	Setblock(D3DXVECTOR3(600.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (600.0f));//真ん中壁
	Setblock(D3DXVECTOR3(400.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (230.0f), (80.0f));//左下1↑床
	Setblock(D3DXVECTOR3(500.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (230.0f), (80.0f));//左下1↑床
	Setblock(D3DXVECTOR3(400.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (230.0f), (40.0f));//左下1↑床

	//右壁
	Setblock(D3DXVECTOR3(900.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (700.0f));//左端壁

	Setblock(D3DXVECTOR3(670.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(670.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(870.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(750.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(800.0f, 350.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(750.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(600.0f, 650.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(800.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//左端壁


	Setblock(D3DXVECTOR3(300.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (700.0f));//左端壁
																			

	Setblock(D3DXVECTOR3(1050.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(1050.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(1110.0f, 65.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//左端壁

	Setblock(D3DXVECTOR3(1110.0f, 450.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//左端壁



	Setblock(D3DXVECTOR3(1100.0f, 700.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (400.0f), (30.0f));//左端壁
	Setblock(D3DXVECTOR3(1270.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (700.0f));//左端壁

	





}
//ブロッ終了処理
void Uninitblock(void)
{
	//テクスチャの破棄
	if (g_pTextureBlock != NULL)
	{
		g_pTextureBlock->Release();
		g_pTextureBlock = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtexBuffBlock != NULL)
	{
		g_pVtexBuffBlock->Release();
		g_pVtexBuffBlock = NULL;
	}

}
//ブロックの更新処理
void Updateblock(void)
{
	




}
//ブロックの描画処理
void Drawblock(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblock;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtexBuffBlock, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		if (g_aBlock[nCntblock].bUse == true)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureBlock);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntblock * 4, 2);
		}
	}
}
//ブロックの設定処理
void Setblock(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth,float fHeight)
{

	int nCntblock;
	VERTEX_2D*pVtx;
	g_pVtexBuffBlock->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		if (g_aBlock[nCntblock].bUse == false)
		{//ブロックが使用されてない場合
			g_aBlock[nCntblock].pos = pos;
			g_aBlock[nCntblock].fWidth=fWidth;//幅
			g_aBlock[nCntblock].fHeight=fHeight;//高さ
			//頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight/2, 0.0f);

			//テクスチャ座標
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(0.02f*g_aBlock[nCntblock].fWidth, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 0.02f*g_aBlock[nCntblock].fHeight);
			pVtx[3].tex = D3DXVECTOR2(0.02f*g_aBlock[nCntblock].fWidth, 0.02f*g_aBlock[nCntblock].fHeight);

			g_aBlock[nCntblock].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtexBuffBlock->Unlock();
}

//ブロックの当たり判定
bool CollisionBlock(D3DXVECTOR3*pPos,//現在の位置
	D3DXVECTOR3*pPosOld,			//前回の高さ
	D3DXVECTOR3*pMove,				//移動量
	float fWidth,					//幅
	float fHeight)					//高さ
{
	

	bool bIsLanding = false;		//着地しているかどうか

	for (int nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		if (g_aBlock[nCntblock].bUse == true)//使用している場合
		{
			//上の当たり判定
			if (g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 > pPos->x - fWidth / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 >= pPosOld->y &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 < pPos->y)

				//ブロックにめり込んだ
			{
				bIsLanding = true;
				pPos->y = g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2;
				pMove->y = 0.0f;
				
			}
			//下の当たり判定
			else if (g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 > pPos->x -fWidth / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 <= pPosOld->y -fHeight &&
				g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 > pPos->y - fHeight)
			{
				
				pPos->y = g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 + fHeight;
				pMove->y = 0.0f;
				
			}
			//右の当たり判定
			 else if (g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 > pPos->y - fHeight &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 < pPos->y + fHeight &&
				g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 <= pPosOld->x -fWidth / 2 &&
				g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 > pPos->x - fWidth / 2)

				//ブロックにめり込んだ
			{
				
				pPos->x = g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 + fWidth / 2;
				pMove->x = 0.0f;
				
			}
			//左の当たり判定
			else if (g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 > pPos->y - fHeight / 2 &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 < pPos->y + fHeight / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 >= pPosOld->x + fWidth / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 < pPos->x + fWidth / 2)

				//ブロックにめり込んだ
			{
				
				pPos->x = g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 - fWidth / 2;
				pMove->x = 0.0f;
				
			}
		}

	}
	return bIsLanding;
}