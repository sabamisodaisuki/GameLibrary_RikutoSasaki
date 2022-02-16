#pragma once

#ifndef _SCORE_H_
#define _SCORE_H_
#define MAX_Score				(9)		//�ǂݍ��ރT�C�Y
#include "main.h"

typedef struct
{
	D3DXVECTOR3 pos;								//�ʒu
	D3DXVECTOR3 move;								//�ړ���
	float fWidth;									//��
	float fHeight;									//����
	bool bUse;										//�g�p���Ă��邩�ǂ���
}Score;
//�v���g�^�C�v�錾
void lnitScore(void);
void UninitScore(void);
void UpdateScore(void);
void DrawScore(void);
void SetScore(int nScore, D3DXVECTOR3 pos, float fWidth, float fHeight);
void AddScore(int nValue);
int GetScore(void);





#endif 