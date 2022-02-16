#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"explosion.h"
#include "Enemy.h"


//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureExplosion = NULL;			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffExplosion = NULL;		//頂点バッファへのポインタ
Explosion g_aExplosion[MAX_EXPLOSION];					//爆破の情報


//弾の初期化処理
void lnitExplosion(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntExplosion;

	//デバイスの取得
	pDevice = GetDevice();


	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ex.png",					//akira000.png,koda.jpg,su.jpg,runningman100.png,bullet000.png,人参.png,金人参.png,ぺこら.jpg
		&g_pTextureExplosion);


	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_EXPLOSION,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffExplosion,
		NULL);


	VERTEX_2D*pVtx;		//頂点情報へポインタ
	

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
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
		pVtx[0].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 0.0f);
		pVtx[1].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 0.0f);
		pVtx[2].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 1.0f);
		pVtx[3].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 1.0f);


		pVtx += 4;
	}
	//頂点バッファアンロック
	g_pVtxBuffExplosion->Unlock();
}
//ポリゴンの終了処理
void UninitExplosion(void)
{
	//テクスチャの破棄
	if (g_pTextureExplosion != NULL)
	{
		g_pTextureExplosion->Release();
		g_pTextureExplosion = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffExplosion != NULL)
	{
		g_pVtxBuffExplosion->Release();
		g_pVtxBuffExplosion = NULL;
	}

}
//弾の更新処理
void UpdateExplosion(void)
{
	int nCntExplosion;
	VERTEX_2D*pVtx;

	
	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if(g_aExplosion[nCntExplosion].bUse==true)
		{//爆発が使用される
			//パターン更新
			g_aExplosion[nCntExplosion].nCounterAnim++; //カウンター加算

			if ((g_aExplosion[nCntExplosion].nCounterAnim % 5 ) == 0)
			{
			
					g_aExplosion[nCntExplosion].nPatternAnim++; //カウンター加算

					if (g_aExplosion[nCntExplosion].nPatternAnim >= 8)//総パターンを超えた
					{
						g_aExplosion[nCntExplosion].bUse = false;//使用してない状態
					}
					//テクスチャ座標
					pVtx[0].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 0.0f);
					pVtx[1].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 0.0f);
					pVtx[2].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 1.0f);
					pVtx[3].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 1.0f);
			}

		}
		pVtx += 4;//ポインタを４つ分進める
	}
	//頂点バッファアンロック
	g_pVtxBuffExplosion->Unlock();
}
//爆破の描画処理
void DrawExplosion(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntExplosion;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffExplosion, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureExplosion);


	//ポリゴンの描画
	for ( nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if (g_aExplosion[nCntExplosion].bUse == true)
		{
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntExplosion * 4, 2);
		}
	}
}
//弾の設定処理
void SetExplosion(D3DXVECTOR3 pos)
{
	int nCntExplosion;
	VERTEX_2D*pVtx;
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for ( nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if (g_aExplosion[nCntExplosion].bUse == false)
		{//弾が使用されてない場合
			g_aExplosion[nCntExplosion].pos = pos;

			//頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x - MAX_SIZE, g_aExplosion[nCntExplosion].pos.y - MAX_SIZE, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x + MAX_SIZE, g_aExplosion[nCntExplosion].pos.y - MAX_SIZE, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x - MAX_SIZE, g_aExplosion[nCntExplosion].pos.y + MAX_SIZE, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x + MAX_SIZE, g_aExplosion[nCntExplosion].pos.y + MAX_SIZE, 0.0f);

			//使用している状態にする
			g_aExplosion[nCntExplosion].bUse = true;

			g_aExplosion[nCntExplosion].nCounterAnim = 0; //アニメをゼロにする

			g_aExplosion[nCntExplosion].nPatternAnim = 0;//パターンをゼロにする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtxBuffExplosion->Unlock();
}

