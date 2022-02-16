//====================
//�v���C���[�̏���
//AUTHOR:���X�ؗ��l
//
//===================

#include "main.h"
#include "player.h"
#include"input.h"
#include"bg.h"
#include"block.h"
#include"time.h"
#include"bullet.h"
#include"itemB.h"
#include"fade.h"
#include"sound.h"
#include"Enemy.h"
#include"HighScore.h"
#include"blockB.h"

#define PLAYER_Z			(4.0f)

//�O���[�o���錾
LPDIRECT3DTEXTURE9 g_pTexturePlayer = NULL;				//�e�N�X�`���ւ̃|�C���^			
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPlayer = NULL;		//���_�o�b�t�@�ւ̃|�C���^
int g_nCounterAnimPlayer;								//�A�j���[�V�����J�E���^�[
int g_nPatternAnimPlayer;								//�A�j���[�V�����p�^�[��
int nDirectionMove;
D3DXVECTOR3 g_posPlayer;								//�ʒu
D3DXVECTOR3 g_movePlayer;								//�ړ���
D3DXVECTOR3 g_scalePlayer;								//�v���C���[�̑傫��
D3DXVECTOR3 g_posOldPlayer;								//�O��̈ʒu
Player g_player;										//�v���C���[���


//�v���C���[�̏���������
D3DXVECTOR3 g_rotPlayer;								//����
float g_fLengthPlayer;									//�Ίp���̒���
float g_fAnglePlayer;									//�Ίp���̊p�x


//�v���C���[�̎擾
Player*GetPlayer(void)
{
	return &g_player;
}

int sum(int a, int b)
{
//	return a + b;
	int c = a + b;
	return c;
}


void lnitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int C;
	C = sum(4,5);

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/kabo.png",					//daiba.png sura2.png
		&g_pTexturePlayer);
	
	g_nCounterAnimPlayer = 0;							//�J�E���^�[������
	g_nPatternAnimPlayer = 0;							//�p�^�[��No��������
	g_posPlayer = D3DXVECTOR3(70.0f,480.0f,0.0f);		//�ʒu��������
	g_movePlayer = D3DXVECTOR3(0.0f,0.0f,0.0f);		//�ړ��l��������
	g_scalePlayer = D3DXVECTOR3(100.0f,100.0f,0.0f);	//�v���C���[�̏���������
	g_player.bDisp = true;
	g_player.nLife = 20;
	g_player.nCounterState = 60;
	g_player.state = PLAYERSTATE_NORMAL;
	


	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D)*4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPlayer,
		NULL);

		VERTEX_2D*pVtx;		//���_���փ|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffPlayer->Lock(0, 0,(void**)&pVtx, 0);

	

	//���_���W
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̕`��
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�v���C���[���W
	pVtx[0].tex = D3DXVECTOR2(0.0f+(0.33f*g_player.nPatternAnim), 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.33f+(0.33f*g_player.nPatternAnim), 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + (0.33f*g_player.nPatternAnim),0.25f);
	pVtx[3].tex = D3DXVECTOR2(0.33f + (0.33f*g_player.nPatternAnim), 0.25f);

	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffPlayer->Unlock();

}
//�|���S���̏I������
void UninitPlayer(void)
{
	//�T�E���h�̒�~
	StopSound();

	//�e�N�X�`���̔j��
	if (g_pTexturePlayer != NULL)
	{
		g_pTexturePlayer->Release();
		g_pTexturePlayer= NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffPlayer != NULL)
	{
		g_pVtxBuffPlayer->Release();
		g_pVtxBuffPlayer = NULL;
	}
	
}

//�v���C���[�̍X�V����
void UpdatePlayer(void)
{
	// �t�F�[�h���̎擾
	FADE fade = GetFade();

	VERTEX_2D*pVtx;



	if (GetKeyboardPress(DIK_A) == true)
	{//A�L�[��������[��]

		g_player.nDirectionMove = 1;

		
			g_movePlayer.x -= 5.0f;//�v���C���[�̈ʒu�Ɉړ��ʂ𑫂�
								  
	}
	
		if (GetKeyboardTrigger(DIK_W) == true)
		{//W�L�[��������[��n
			if (g_player.bIsJumping == false)
			{
				g_player.bIsJumping = true;

			g_movePlayer.y = -40.0f;//�v���C���[�̃W�����v
									
		}
	}

	else if (GetKeyboardPress(DIK_D) == true)
	{//D�L�[��������[�E]
		g_player.nDirectionMove = 2;
			g_movePlayer.x += 5.0f;//�v���C���[�̈ʒu�Ɉړ��ʂ𑫂�
	}
	 if (GetKeyboardTrigger(DIK_SPACE) == true)
	{//SPACE�L�[�������ꂽ
	
		//�e�̐ݒ�
		 if (g_player.nDirectionMove == 2)
		 {
			 SetBullet( D3DXVECTOR3(g_posPlayer.x, g_posPlayer.y-PLAYER_SIZE_Y/2.0f, g_posPlayer.z), D3DXVECTOR3(6.0f, 0.0f, 0.0f));//6.0f,-3.0f,-6.0f
																																	//�T�E���h�̍Đ�
			 PlaySound(SOUND_LABEL_SE_SHOT);
		 }
		 else if (g_player.nDirectionMove == 1)
		 {
			 SetBullet(D3DXVECTOR3(g_posPlayer.x, g_posPlayer.y-PLAYER_SIZE_Y/2.0f, g_posPlayer.z), D3DXVECTOR3(-6.0f, 0.0f, 0.0f));
			 //�T�E���h�̍Đ�
			 PlaySound(SOUND_LABEL_SE_SHOT);
		 }
		
	}
	if (g_movePlayer.x >= 1.0f||g_movePlayer.x<=-1.0f)
	{
		//�p�^�[���X�V
		g_player.nCounterAnim++; //�J�E���^�[���Z

		if ((g_player.nCounterAnim % 5) == 0)
		{
		
			g_player.nPatternAnim++; //�J�E���^�[���Z

			if (g_player.nPatternAnim >= 4)//���p�^�[���𒴂���
			{
				g_player.nPatternAnim = 0;//�J�E���g��0�ɖ߂�
			}

			//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
			g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

			//�e�N�X�`�����W
			pVtx[0].tex = D3DXVECTOR2(0.0f + (0.33f*(g_player.nPatternAnim)), 0.25f*g_player.nDirectionMove);
			pVtx[1].tex = D3DXVECTOR2(0.33f + (0.33f*(g_player.nPatternAnim)), 0.25f*g_player.nDirectionMove);
			pVtx[2].tex = D3DXVECTOR2(0.0f + (0.33f*(g_player.nPatternAnim)), 0.25f*(g_player.nDirectionMove+1));
			pVtx[3].tex = D3DXVECTOR2(0.33f + (0.33f*(g_player.nPatternAnim)), 0.25f*(g_player.nDirectionMove+1));
			//���_�o�b�t�@�A�����b�N
			g_pVtxBuffPlayer->Unlock();
		}
		else
		{//��~��
			if (g_player.nCounterAnim)
			{

			}



		}
		
	}

	


	switch (g_player.state)
	{
	case PLAYERSTATE_NORMAL:
		break;

	case PLAYERSTATE_DAMAGE:
		g_player.nCounterState--;

		if (g_player.nCounterState <= 0)
		{
			g_player.state = PLAYERSTATE_NORMAL;

			/*VERTEX_2D*pVtx;*/

			//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
			g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

			//pVtx += 4 * nDamage;//�|�C���^���S���i�߂�

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//���_�o�b�t�@�A�����b�N
			g_pVtxBuffPlayer->Unlock();
		}
		break;

		case PLAYERSTATE_DEATH:
			g_player.nCounterState--;

			if (g_player.nCounterState <= 0 && fade == FADE_NONE)
			{
				SaveHigeScore();
				//���[�h�ݒ�(�Q�[����ʂɈڍs)
				SetFade(MODE_RESULT);

				return;
			}
			break;
		}
		
		////�ʒu���X�V
		//g_posPlayer += g_movePlayer;

		//�O��̈ʒu��ۑ�
		g_posOldPlayer = g_posPlayer;

	
		//�ړ��l
		g_movePlayer.y += PLAYER_Z/2;
		g_posPlayer.x += g_movePlayer.x/2;
		g_posPlayer.y += g_movePlayer.y/2;
		g_movePlayer.x = (-g_movePlayer.x)*0.1f/2;
		
		//��ʊO����
		if (g_posPlayer.x - PLAYER_SIZE_X / 2 >= SCREEN_WIDTH)
		{//��ʂ̉E�ɓ�������
			g_posPlayer.x = 0.0f - PLAYER_SIZE_X / 2;
			g_posOldPlayer.x = 0.0f - PLAYER_SIZE_X / 2;
		}
		else if (g_posPlayer.x + PLAYER_SIZE_X / 2 < 0.0f)
		{//��ʂ̍��ɓ�������
			g_posPlayer.x = SCREEN_WIDTH + PLAYER_SIZE_X / 2;
			g_posOldPlayer.x = SCREEN_WIDTH+PLAYER_SIZE_X / 2;
		}
		
		if (g_posPlayer.y + PLAYER_SIZE_Y / 2 >= SCREEN_HEIGHT == true && fade == FADE_NONE)
		{//�v���C���[�����ɓ�������
			SaveHigeScore();
			SetFade(MODE_RESULT);
			return;
		}
		
		//�u���b�N�Ƃ̓����蔻��
		bool blsLanding = CollisionBlock(
			&g_posPlayer,
			&g_posOldPlayer,
			&g_movePlayer,
			PLAYER_SIZE_X,
			PLAYER_SIZE_Y);

		//�u���b�N�Ƃ̓����蔻��
		 CollisionBlockB(
			&g_posPlayer,
			&g_posOldPlayer,
			&g_movePlayer,
			PLAYER_SIZE_X,
			PLAYER_SIZE_Y);


		//�A�C�e���Ƃ̓����蔻��
		 CollisionItemB
		 (&g_posPlayer,
			&g_posOldPlayer,
			&g_movePlayer,
			 PLAYER_SIZE_X,
			 PLAYER_SIZE_Y);



		//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
		g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

		pVtx[0].pos = D3DXVECTOR3(g_posPlayer.x - PLAYER_SIZE_X / 2, g_posPlayer.y - PLAYER_SIZE_Y, g_posPlayer.z);
		pVtx[1].pos = D3DXVECTOR3(g_posPlayer.x + PLAYER_SIZE_X / 2, g_posPlayer.y - PLAYER_SIZE_Y, g_posPlayer.z);
		pVtx[2].pos = D3DXVECTOR3(g_posPlayer.x - PLAYER_SIZE_X / 2, g_posPlayer.y, g_posPlayer.z);
		pVtx[3].pos = D3DXVECTOR3(g_posPlayer.x + PLAYER_SIZE_X / 2, g_posPlayer.y, g_posPlayer.z);

		if (g_player.bDisp == true)
		{//�G���g�p�����
		    Enemy*pEnemy;
		    int nCntEnemy;
		    pEnemy = GetEnemy();

		    for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++, pEnemy++)
		    {
			    if (pEnemy->bUse== true)
			    {//�G������Ƃ�
				    if (pEnemy->pos.x + ENEMY_SIZE_X / 2 > g_posPlayer.x &&
				 	   pEnemy->pos.x - ENEMY_SIZE_X / 2 < g_posPlayer.x &&
				 	   pEnemy->pos.y + ENEMY_SIZE_Y / 2 > g_posPlayer.y &&
				 	   pEnemy->pos.y - ENEMY_SIZE_Y / 2 < g_posPlayer.y)

				    {//�G�ƃv���C���[����������

				 	//�T�E���h�̍Đ�
				 	   PlaySound(SOUND_LABEL_SE_bakuha);

				 	   HitPlayer(5);
				    }


			    }
			    
		    }
		}
		
		//�u���b�N�̏�ŃW�����v
		if (blsLanding == true)
		{
			g_player.bIsJumping = false;
		}
		/*else
		{
			if (g_player.bIsJumping == false)
			{
				g_player.bIsJumping = true;
			}
		}*/


		//���_�o�b�t�@�A�����b�N
		g_pVtxBuffPlayer->Unlock();
	}



//�|���S���̕`�揈��
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	/*if (g_player.bDisp == true)
	{*/
		//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffPlayer, 0, sizeof(VERTEX_2D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_2D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTexturePlayer);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	/*}*/
}

//�v���C���[�̃q�b�g����
void HitPlayer(int nDamage)
{
	// �t�F�[�h���̎擾
	FADE fade = GetFade();

	/*g_player.nLife = 10;*/

	g_player.nLife -= nDamage;

	if (g_player.nLife <= 0 && fade == FADE_NONE)
	{

		g_player.bDisp = false;
		g_player.state = PLAYERSTATE_DEATH;
		g_player.nCounterState = 60;
		SaveHigeScore();
		//���[�h�ݒ�(�Q�[����ʂɈڍs)
		SetFade(MODE_RESULT);

		return;
	}
	else
	{
		g_player.state = PLAYERSTATE_DAMAGE;
		g_player.nCounterState = 4;

		VERTEX_2D*pVtx;

		//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
		g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

		 //���_�J���[�̐ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 0, 0, 255);

		//���_�o�b�t�@�A�����b�N
		g_pVtxBuffPlayer->Unlock();
		
	}


}
