#pragma once
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "main.h"

//マクロ定義
#define MAX_EXPLOSION			(128)		//爆破の最大数
#define MAX_SIZE				(50)		//爆破のサイズ
//爆破の構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;			//位置
	D3DXVECTOR3 col;			//色
	int nCounterAnim;			//アニメーションカウンター
	int nPatternAnim;			//アニメーションパターンNo.
	bool bUse;					//使用しているかどうか
}Explosion;


//プロトタイプ宣言
void lnitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);
void SetExplosion(D3DXVECTOR3 pos);
#endif
