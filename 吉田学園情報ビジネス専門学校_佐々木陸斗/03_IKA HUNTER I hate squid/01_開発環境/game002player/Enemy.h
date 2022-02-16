#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "main.h"

//マクロ定義
#define MAX_ENEMY			(128)		//敵の最大数
#define NUM_ENEMY			(10)		//敵の種類
#define ENEMY_SIZE			(140.0f)	//敵のサイズ

//敵の状態
typedef enum
{
	ENEMYSTA_NORMAL = 0,
	ENEMYSTA_DAMAGE,
	ENEMYSTA_MAX
}ENEMYSTATE;


//弾構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;								//位置
	D3DXVECTOR3 move;								//移動量
	int nType;										//種類
	ENEMYSTATE state;								//状態
	int nCounterState;								//状態管理カウンター
	int nLife;										//体力
	int nScore;										//エネミーのスコア
	bool bUse;										//使用しているかどうか
}Enemy;


//プロトタイプ宣言
void lnitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nType);
void HitEnemy(int nCntEnemy, int nDamage);

Enemy*GetEnemy(void);




#endif 
