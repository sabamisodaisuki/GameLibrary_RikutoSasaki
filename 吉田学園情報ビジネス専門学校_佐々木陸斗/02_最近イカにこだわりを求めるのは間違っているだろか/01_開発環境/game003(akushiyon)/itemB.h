#ifndef _ITEMB_H_
#define _ITEMB_H_

#include "main.h"


//�v���C���[�̏��
typedef enum
{
	ITEMB_TYPE_COIN = 0,	//�o����ԁi�_�Łj
	ITEMB_TYPE_MAX
}ITEMB_TYPE;



//�A�C�e���\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	float fWidth;									//��
	float fHeight;									//��sa	
	ITEMB_TYPE type;
	bool bUse;//�g�p���Ă��邩�ǂ���

}ItemB;


//�v���g�^�C�v�錾
void lnitItemb(void);
void UninitItemb(void);
void UpdateItemb(void);
void DrawItemb(void);
void SetItemb(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight);
void CollisionItemB(D3DXVECTOR3*pPos,//���݂̈ʒu
	D3DXVECTOR3*pPosOld,			//�O��̍���
	D3DXVECTOR3*pMove,				//�ړ���
	float fWidth,					//��
	float fHeight);
void DeleteItemB(int nCntItemB);
ItemB*GetItemB(void);


#endif 
