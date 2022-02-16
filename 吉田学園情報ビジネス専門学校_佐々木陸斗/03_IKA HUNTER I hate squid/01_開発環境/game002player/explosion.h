#pragma once
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "main.h"

//�}�N����`
#define MAX_EXPLOSION			(128)		//���j�̍ő吔
#define MAX_SIZE				(50)		//���j�̃T�C�Y
//���j�̍\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;			//�ʒu
	D3DXVECTOR3 col;			//�F
	int nCounterAnim;			//�A�j���[�V�����J�E���^�[
	int nPatternAnim;			//�A�j���[�V�����p�^�[��No.
	bool bUse;					//�g�p���Ă��邩�ǂ���
}Explosion;


//�v���g�^�C�v�錾
void lnitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);
void SetExplosion(D3DXVECTOR3 pos);
#endif
