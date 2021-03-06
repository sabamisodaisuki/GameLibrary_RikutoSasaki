#ifndef _PLAYER_H_
#define _PLAYER_H_

//プレイヤーの状態
typedef enum
{
	PLAYERSTATE_APPEAR=0,	//出現状態（点滅）
	PLAYERSTATE_NORMAL,		//通常状態
	PLAYERSTATE_DAMAGE,		//ダメージ状態
	PLAYERSTATE_DEATH,		//死亡状態
	PLAYERSTATE_MAX
}PLAYERSTATE;


//プレイヤーの構造体の定義
typedef struct
{
	D3DXVECTOR3 g_posPlayer;				//位置					
	D3DXVECTOR3 g_movePlayer;				//移動量
	D3DXVECTOR3 g_scalePlayer;																	
	D3DXVECTOR3 g_rotPlayer;
	D3DXVECTOR3 g_posOldPlayer;				//前回の位置
	PLAYERSTATE state;						//プレイヤーの状態
	int nCounterState;						//状態管理カウンター
	int nLife;								//体力
	int nCounterAnim;						//カウンター
	int nPatternAnim;						//パターン番号
	int nDirectionMove;						//向き
	float fWidth;									//幅
	float fHeight;									//高さ
	bool bDisp;								//表示するかしないか
	bool bIsJumping;						//ジャンプ中
	bool bUse;

}Player;

//マクロ定義
#define PLAYER_SIZE_X		(40.0f)
#define PLAYER_SIZE_Y		(40.0f)



//プロトタイプ宣言
Player *GetPlayer(void);
void lnitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void HitPlayer(int nDamage);




#endif 

