#ifndef _ITEM_H_
#define _ITEM_H_

#include "main.h"

//bur構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	float fWidth;									//幅
	float fHeight;									//高さ
	bool bUse;										//使用しているかどうか
}Item;


//プロトタイプ宣言
void lnitItem(void);
void UninitItem(void);
void UpdateItem(void);
void DrawItem(void);
void SetItem(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight);

//bool CollisionItem(D3DXVECTOR3*pPos,//現在の位置
//	D3DXVECTOR3*pPosOld,			//前回の高さ
//	D3DXVECTOR3*pMove,				//移動量
//	float fWidth,					//幅
//	float fHeight);					//高さ
#endif 