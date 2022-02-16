#pragma once

#ifndef _BULLET_H_
#define _BULLET_H_

#include "main.h"

//弾構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	int nLife;
	bool bUse;
}Bullet;


//プロトタイプ宣言
void lnitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move);

#endif 