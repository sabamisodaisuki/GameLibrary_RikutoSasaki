#ifndef _ITEMB_H_
#define _ITEMB_H_

#include "main.h"


//プレイヤーの状態
typedef enum
{
	ITEMB_TYPE_COIN = 0,	//出現状態（点滅）
	ITEMB_TYPE_MAX
}ITEMB_TYPE;



//アイテム構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	float fWidth;									//幅
	float fHeight;									//高sa	
	ITEMB_TYPE type;
	bool bUse;//使用しているかどうか

}ItemB;


//プロトタイプ宣言
void lnitItemb(void);
void UninitItemb(void);
void UpdateItemb(void);
void DrawItemb(void);
void SetItemb(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight);
void CollisionItemB(D3DXVECTOR3*pPos,//現在の位置
	D3DXVECTOR3*pPosOld,			//前回の高さ
	D3DXVECTOR3*pMove,				//移動量
	float fWidth,					//幅
	float fHeight);
void DeleteItemB(int nCntItemB);
ItemB*GetItemB(void);


#endif 
