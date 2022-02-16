#pragma once

#ifndef _BULLET_H_
#define _BULLET_H_

#include "main.h"

//�e�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	int nLife;
	bool bUse;
}Bullet;


//�v���g�^�C�v�錾
void lnitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move);

#endif 