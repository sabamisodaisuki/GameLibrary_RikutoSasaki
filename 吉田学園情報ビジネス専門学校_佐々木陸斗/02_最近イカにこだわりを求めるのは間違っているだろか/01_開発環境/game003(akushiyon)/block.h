#pragma once
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "main.h"

//bur�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	float fWidth;									//��
	float fHeight;									//����
	bool bUse;										//�g�p���Ă��邩�ǂ���
}block;


//�v���g�^�C�v�錾
void lnitblock(void);
void Uninitblock(void);
void Updateblock(void);
void Drawblock(void);
void Setblock(D3DXVECTOR3 pos, D3DXVECTOR3 move,float fWidth,float fHeight);

bool CollisionBlock(D3DXVECTOR3*pPos,//���݂̈ʒu
	D3DXVECTOR3*pPosOld,			//�O��̍���
	D3DXVECTOR3*pMove,				//�ړ���
	float fWidth,					//��
	float fHeight);					//����
#endif 