#pragma once

#ifndef _BG2_H_
#define _BG2_H_

//�e�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	int nType;
	bool bUse;										//�g�p���Ă��邩�ǂ���
}BG2;

//�v���g�^�C�v�錾
void lnitBG2(void);
void UninitBG2(void);
void UpdateBG2(void);
void DrawBG2(void);
void SetBG2(D3DXVECTOR3 pos, D3DXVECTOR3 move);
#endif