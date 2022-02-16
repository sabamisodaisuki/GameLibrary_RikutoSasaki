//============================================================
//
// 3D制作　Bulletの処理[Bullet.h]
// AUTHOR:Sasaki Rikuto
//
//============================================================
#ifndef _BULLET_H_
#define _BULLET_

#include "main.h"

//============================================================
// 構造体の定義
//============================================================
typedef struct
{
	D3DXVECTOR3 pos;				//視点					
	D3DXVECTOR3 rot;				//注視点
	D3DXVECTOR3 move;				//移動量
	D3DXMATRIX mtxWorld;			//
	int nLife;						//体力
	float fWidth;					//幅
	float fHeight;					//高さ
	bool bUse;						//使用しているかどうか
}Bullet;

//============================================================
// プロトタイプ宣言
//============================================================
void lnitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos ,D3DXVECTOR3 move);

#endif