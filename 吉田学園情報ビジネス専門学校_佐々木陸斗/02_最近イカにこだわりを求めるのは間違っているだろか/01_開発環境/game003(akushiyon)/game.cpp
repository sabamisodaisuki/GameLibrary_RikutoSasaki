#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Enemy.h"
#include"title.h"
#include"game.h"
#include"bg.h"
#include"sound.h"
#include"Score.h"
#include"Time.h"
#include"block.h"
#include"item.h"
#include"itemB.h"
#include"HighScore.h"
#include"blockB.h"
//�Q�[����ʂ̏���������
void lnitGAME(void)
{
	//�T�E���h�̍Đ�
	PlaySound(SOUND_LABEL_BGMGame);
	
	//�w�i�̏���������
	lnitBG();

	//�X�R�A�̏���������
	lnitScore();


	//�^�C���̏�����
	lnitTime();


	//�v���C���[�̏���������

	lnitPlayer();

	//�e�̏���������
	lnitBullet();

	//�G�l�~�[�̏���������
	lnitEnemy();

	//�u���b�N
	lnitblock();
	//�u���b�N
	lnitblockB();
	//�A�C�e��
	lnitItem();

	//�A�C�e��
	lnitItemb();
	//�n�C�X�R�A�̏�����
	lnitHigeScore();


}



//�Q�[���̏I������
void UninitGAME(void)
{
	//�T�E���h�̒�~
	StopSound();


	//�v���C���[��̏I������
	UninitPlayer();

	//�X�R�A�̏I������
	UninitScore();

	//�^�C���̏I������
	UninitTime();

	//�e�̏I������
	UninitBullet();

	//�G�l�~�[�̏I������
	UninitEnemy();

	//�w�i�̏I������
	UninitBG();

	//�u���b�N
	Uninitblock();

	//�u���b�N
	UninitblockB();

	//�A�C�e��
	UninitItem();

	//�A�C�e��
	UninitItemb();

	UninitHigeScore();
}

//�Q�[���̕`�揈��
void DrawGAME(void)
{
	//�w�i�̍X�V����
	DrawBG();

	//�X�R�A�̍X�V����
	DrawScore();

	//�^�C���̍X�V����
	DrawTime();

	//�v���C���[�̍X�V����
	DrawPlayer();

	//�e�̍X�V����
	DrawBullet();

	//�G�l�~�[�̍X�V����
	DrawEnemy();

	//�u���b�N
	Drawblock();

	//�u���b�N
	DrawblockB();
	//�A�C�e��
	DrawItem();

	//�A�C�e��
	DrawItemb();

	DrawHigeScore();
}

//�Q�[����ʂ̍X�V����
void UpdateGAME(void)
{
	//�w�i�̍X�V����
	UpdateBG();

	//�X�R�A�̍X�V����
	UpdateScore();

	//�^�C���̍X�V
	UpdateTime();

	//�e�̍X�V����
	UpdateBullet();

	//�G�l�~�[�̍X�V����
	UpdateEnemy();
	
	//�u���b�N
	Updateblock();

	//�u���b�N
	UpdateblockB();
	//�A�C�e��
	UpdateItem();

	//�A�C�e��
	UpdateItemb();

	//�v���C���[�̍X�V����
	UpdatePlayer();

	UpdateHigeScore();


	//����L�[(ENTER�L�[�������ꂽ���ǂ���)
	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		//���[�h�ݒ�
		SetMode(MODE_RESULT);
	}
	//K�L�[(�Q�[���ŏ�����)
	if (GetKeyboardTrigger(DIK_K) == true)
	{
		//���[�h�ݒ�
		SetMode(MODE_GAME);
	}
}