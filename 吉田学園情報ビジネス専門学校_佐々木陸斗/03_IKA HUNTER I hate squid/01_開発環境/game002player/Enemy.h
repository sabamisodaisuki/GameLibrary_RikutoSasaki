#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "main.h"

//�}�N����`
#define MAX_ENEMY			(128)		//�G�̍ő吔
#define NUM_ENEMY			(10)		//�G�̎��
#define ENEMY_SIZE			(140.0f)	//�G�̃T�C�Y

//�G�̏��
typedef enum
{
	ENEMYSTA_NORMAL = 0,
	ENEMYSTA_DAMAGE,
	ENEMYSTA_MAX
}ENEMYSTATE;


//�e�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	int nType;										//���
	ENEMYSTATE state;								//���
	int nCounterState;								//��ԊǗ��J�E���^�[
	int nLife;										//�̗�
	int nScore;										//�G�l�~�[�̃X�R�A
	bool bUse;										//�g�p���Ă��邩�ǂ���
}Enemy;


//�v���g�^�C�v�錾
void lnitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nType);
void HitEnemy(int nCntEnemy, int nDamage);

Enemy*GetEnemy(void);




#endif 
