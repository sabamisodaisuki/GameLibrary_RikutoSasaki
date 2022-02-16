#pragma once
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "main.h"

//bur構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	float fWidth;									//幅
	float fHeight;									//高さ
	bool bUse;										//使用しているかどうか
}block;


//プロトタイプ宣言
void lnitblock(void);
void Uninitblock(void);
void Updateblock(void);
void Drawblock(void);
void Setblock(D3DXVECTOR3 pos, D3DXVECTOR3 move,float fWidth,float fHeight);

bool CollisionBlock(D3DXVECTOR3*pPos,//現在の位置
	D3DXVECTOR3*pPosOld,			//前回の高さ
	D3DXVECTOR3*pMove,				//移動量
	float fWidth,					//幅
	float fHeight);					//高さ
#endif 