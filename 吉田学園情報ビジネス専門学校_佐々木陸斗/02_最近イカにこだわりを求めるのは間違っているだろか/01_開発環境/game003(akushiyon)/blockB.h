#pragma once
#ifndef _BLOCKB_H_
#define _BLOCKB_H_

#include "main.h"

//bur�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	float fWidth;									//��
	float fHeight;									//����
	bool bUse;										//�g�p���Ă��邩�ǂ���
}blockB;


//�v���g�^�C�v�錾
void lnitblockB(void);
void UninitblockB(void);
void UpdateblockB(void);
void DrawblockB(void);
void SetblockB(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight);

bool CollisionBlockB(D3DXVECTOR3*pPos,//���݂̈ʒu
	D3DXVECTOR3*pPosOld,			//�O��̍���
	D3DXVECTOR3*pMove,				//�ړ���
	float fWidth,					//��
	float fHeight);					//����
#endif 