#ifndef _ITEM_H_
#define _ITEM_H_

#include "main.h"

//bur�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	float fWidth;									//��
	float fHeight;									//����
	bool bUse;										//�g�p���Ă��邩�ǂ���
}Item;


//�v���g�^�C�v�錾
void lnitItem(void);
void UninitItem(void);
void UpdateItem(void);
void DrawItem(void);
void SetItem(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight);

//bool CollisionItem(D3DXVECTOR3*pPos,//���݂̈ʒu
//	D3DXVECTOR3*pPosOld,			//�O��̍���
//	D3DXVECTOR3*pMove,				//�ړ���
//	float fWidth,					//��
//	float fHeight);					//����
#endif 