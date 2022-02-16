#pragma once
#ifndef _BLOCKB_H_
#define _BLOCKB_H_

#include "main.h"

//bur構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	float fWidth;									//幅
	float fHeight;									//高さ
	bool bUse;										//使用しているかどうか
}blockB;


//プロトタイプ宣言
void lnitblockB(void);
void UninitblockB(void);
void UpdateblockB(void);
void DrawblockB(void);
void SetblockB(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight);

bool CollisionBlockB(D3DXVECTOR3*pPos,//現在の位置
	D3DXVECTOR3*pPosOld,			//前回の高さ
	D3DXVECTOR3*pMove,				//移動量
	float fWidth,					//幅
	float fHeight);					//高さ
#endif 