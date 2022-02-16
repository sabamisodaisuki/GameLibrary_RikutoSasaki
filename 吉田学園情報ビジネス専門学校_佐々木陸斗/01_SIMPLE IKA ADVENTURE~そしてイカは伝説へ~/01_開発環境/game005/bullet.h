//============================================================
//
// 3D����@Bullet�̏���[Bullet.h]
// AUTHOR:Sasaki Rikuto
//
//============================================================
#ifndef _BULLET_H_
#define _BULLET_

#include "main.h"

//============================================================
// �\���̂̒�`
//============================================================
typedef struct
{
	D3DXVECTOR3 pos;				//���_					
	D3DXVECTOR3 rot;				//�����_
	D3DXVECTOR3 move;				//�ړ���
	D3DXMATRIX mtxWorld;			//
	int nLife;						//�̗�
	float fWidth;					//��
	float fHeight;					//����
	bool bUse;						//�g�p���Ă��邩�ǂ���
}Bullet;

//============================================================
// �v���g�^�C�v�錾
//============================================================
void lnitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos ,D3DXVECTOR3 move);

#endif