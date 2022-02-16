//============================================================
//
// 3D弾の処理 [Bullet.cpp]
// Aothur : Rikuto Sasaki
//
//============================================================
#include "Bullet.h"
#include "main.h"
#include"effect.h"
//============================================================
//マクロ定義
//============================================================
#define MAX_Bullet		(256)	//壁の最大数
#define BULLET_SIZE_XE_X		(6.0f)	//壁のサイズ
#define BULLET_SIZE_XE_Y 	(6.0f)	//壁のサイズ
//============================================================
//グローバル変数
//============================================================
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;	// 頂点バッファへのポインタ
Bullet g_aBullet[MAX_Bullet];						  //影

 //============================================================
 // 壁の初期化
 //============================================================
void lnitBullet(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	int nCntBullet;

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika008.png",
		&g_pTextureBullet);

	//弾の情報の初期化
	for (nCntBullet = 0; nCntBullet< MAX_Bullet; nCntBullet++)
	{
		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].bUse = false;
	}
	//頂点バッファの作成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_Bullet,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBullet,
		NULL);

	//頂点情報へポインタ
	VERTEX_3D *pVtx = NULL;

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		//頂点座標
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//テクスチャ座標
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		//各頂点の法線の設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//頂点カラーの描画
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}
	//頂点バッファアンロック
	g_pVtxBuffBullet->Unlock();
}


//============================================================
// 壁の終了処理
//============================================================
void UninitBullet(void)
{
	//テクスチャの破棄
	if (g_pTextureBullet != NULL)
	{
		g_pTextureBullet->Release();
		g_pTextureBullet = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}
}

//============================================================
// 弾の更新処理
//============================================================
void UpdateBullet(void)
{
	int nCntBullet;
	VERTEX_3D*pVtx;

	//頂点バッファをロックし、頂点情報へポインタ取得
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//弾が使用される
			g_aBullet[nCntBullet].pos.x -= sinf(g_aBullet[nCntBullet].rot.y)*1.5f;
			g_aBullet[nCntBullet].pos.z -= cosf(g_aBullet[nCntBullet].rot.y)*1.5f;


			//弾の位置の更新
			/*g_aBullet[nCntBullet].pos += g_aBullet[nCntBullet].move;*/

		
			//if (g_aBullet[nCntBullet].pos.y <= 6)

 			SetEffect(g_aBullet[nCntBullet].pos,g_aBullet[nCntBullet].rot, D3DXVECTOR3(10.0f, 10.0f, 0.5f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 20);
			//寿命のカウントダウン

			g_aBullet[nCntBullet].nLife -- ;

			if (g_aBullet[nCntBullet].nLife <= 0)
			{
				g_aBullet[nCntBullet].bUse = false;
			}
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	//頂点バッファアンロック
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// 壁の設定
//============================================================
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntBullet;
	VERTEX_3D*pVtx;
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == false)
		{//壁が使用されてない場合
			g_aBullet[nCntBullet].pos = pos;
			g_aBullet[nCntBullet].move = move;
			g_aBullet[nCntBullet].nLife = 100;
			//頂点座標の更新
			pVtx[0].pos = D3DXVECTOR3( - 6.0f,  6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3( + 6.0f,  6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3( - 6.0f, -6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3( + 6.0f, - 6.0f, 0.0f);

			g_aBullet[nCntBullet].bUse = true;	//使用している状態にする

			break;		//(for文を抜ける)
		}
		pVtx += 4;//ポインタを４つ分進める
	}
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// 影の描画処理
//============================================================
void DrawBullet(void)
{
	//デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{

			D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス
			//ワールドマトリックスの初期化
			D3DXMATRIX mtxView;
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);//ビューマトリックスの取得
			D3DXMatrixIdentity(&g_aBullet[nCntBullet].mtxWorld);

			//Zバッファ
			pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

			//カメラ逆例を設定
			g_aBullet[nCntBullet].mtxWorld._11 = mtxView._11;
			g_aBullet[nCntBullet].mtxWorld._12 = mtxView._21;
			g_aBullet[nCntBullet].mtxWorld._13 = mtxView._31;
			g_aBullet[nCntBullet].mtxWorld._21 = mtxView._12;
			g_aBullet[nCntBullet].mtxWorld._22 = mtxView._22;
			g_aBullet[nCntBullet].mtxWorld._23 = mtxView._32;
			g_aBullet[nCntBullet].mtxWorld._31 = mtxView._13;
			g_aBullet[nCntBullet].mtxWorld._32 = mtxView._23;
			g_aBullet[nCntBullet].mtxWorld._33 = mtxView._33;


			//位置を反映.
			D3DXMatrixTranslation(&mtxTrans, g_aBullet[nCntBullet].pos.x, g_aBullet[nCntBullet].pos.y, g_aBullet[nCntBullet].pos.z);
			D3DXMatrixMultiply(&g_aBullet[nCntBullet].mtxWorld, &g_aBullet[nCntBullet].mtxWorld, &mtxTrans);

			//ライトの無効
			pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_aBullet[nCntBullet].mtxWorld);

			//頂点バッファをデバイスのデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_3D));

			//頂点フォーマット設定
			pDevice->SetFVF(FVF_VERTEX_3D);

			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureBullet);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBullet * 4, 2);

			//元に戻す
			pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

		}
	}

	//テクスチャの設定
	pDevice->SetTexture(0, NULL);

	//ライトの有効
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}
	