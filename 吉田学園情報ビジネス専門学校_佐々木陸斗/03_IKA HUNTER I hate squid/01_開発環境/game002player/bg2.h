#pragma once

#ifndef _BG2_H_
#define _BG2_H_

//弾構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	int nType;
	bool bUse;										//使用しているかどうか
}BG2;

//プロトタイプ宣言
void lnitBG2(void);
void UninitBG2(void);
void UpdateBG2(void);
void DrawBG2(void);
void SetBG2(D3DXVECTOR3 pos, D3DXVECTOR3 move);
#endif