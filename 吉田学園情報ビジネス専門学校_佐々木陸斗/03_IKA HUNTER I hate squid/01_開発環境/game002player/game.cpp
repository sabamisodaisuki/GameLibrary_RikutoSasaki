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
#include"explosion.h"
#include"Time.h"
#include"bg2.h"
#include"HighScore.h"

//�Q�[����ʂ̏���������
void lnitGAME(void)
{
	//�T�E���h�̍Đ�
	PlaySound(SOUND_LABEL_BGMMAOU);


	//�w�i�̏���������
	lnitBG();

	//�w�i�̏���������
	lnitBG2();

	//�X�R�A�̏���������
	lnitScore();

	//���j�̏���������
	lnitExplosion();


	//�^�C���̏�����
	lnitTime();


	//�v���C���[�̏���������

	lnitPlayer();

	//�e�̏���������
	lnitBullet();

	//�G�l�~�[�̏���������
	lnitEnemy();

	//�n�C�X�R�A�̏���������
	lnitHigeScore();
}

//�Q�[���̏I������
void UninitGAME(void)
{
	//�T�E���h�̒�~
	StopSound();

	//���j�̏I������
	UninitExplosion();

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

	//�w�i�̏I������
	UninitBG2();

	//�n�C�X�R�A�I������
	UninitHigeScore();
}

//�Q�[���̕`�揈��
void DrawGAME(void)
{
	//�w�i�̍X�V����
	DrawBG();

	//�w�i�̍X�V����
	DrawBG2();

	//���j�̍X�V����
	DrawExplosion();

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

	//�n�C�X�R�A�̍X�V����
	DrawHigeScore();
}

//�Q�[����ʂ̍X�V����
void UpdateGAME(void)
{
	//�w�i�̍X�V����
	UpdateBG();

	//�w�i�̍X�V����
	UpdateBG2();

	//���j�̍X�V����
	UpdateExplosion();

	//�X�R�A�̍X�V����
	UpdateScore();

	//�v���C���[�̍X�V����
	UpdatePlayer();

	//�^�C���̍X�V
	UpdateTime();

	//�e�̍X�V����
	UpdateBullet();

	//�G�l�~�[�̍X�V����
	UpdateEnemy();
	
	//�n�C�X�R�A�̍X�V������
	UpdateHigeScore();
	////����L�[(ENTER�L�[�������ꂽ���ǂ���)
	//if (GetKeyboardTrigger(DIK_RETURN) == true)
	//{
	//	//���[�h�ݒ�
	//	SetMode(MODE_RESULT);
	//}

}