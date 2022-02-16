#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include "Enemy.h"
#include"title.h"
#include"sound.h"
#include"explosion.h"
#include"fade.h"

//�}�N����`
#define PLAYER_SIZE_X		(100.0f)
#define PLAYER_SIZE_Y		(100.0f)

//�O���[�o���錾
LPDIRECT3DTEXTURE9 g_pTexturePlayer = NULL;				//�e�N�X�`���ւ̃|�C���^			
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPlayer = NULL;		//���_�o�b�t�@�ւ̃|�C���^
int g_nCounterAnimPlayer;								//�A�j���[�V�����J�E���^�[
int g_nPatternAnimPlayer;								//�A�j���[�V�����p�^�[��
D3DXVECTOR3 g_posPlayer;								//�ʒu
D3DXVECTOR3 g_movePlayer;								//�ړ���
D3DXVECTOR3 g_scalePlayer;								//�v���C���[�̑傫��
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




void lnitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/5.png",					//daiba.png
		&g_pTexturePlayer);

	g_nCounterAnimPlayer = 0;							//�J�E���^�[������
	g_nPatternAnimPlayer = 0;							//�p�^�[��No��������
	g_posPlayer = D3DXVECTOR3(250.0f,250.0f,0.0f);		//�ʒu��������
	g_movePlayer = D3DXVECTOR3();						//�ړ��l��������
	g_scalePlayer = D3DXVECTOR3(100.0f,100.0f,0.0f);		//�v���C���[�̏���������
	g_rotPlayer = D3DXVECTOR3(0.0f, 0.0f, 3.14f);
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
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

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

	switch (g_player.state)
	{
	case PLAYERSTATE_NORMAL:
		break;

	case PLAYERSTATE_DAMAGE:
		g_player.nCounterState--;

		if (g_player.nCounterState <= 0)
		{
			g_player.state = PLAYERSTATE_NORMAL;

			VERTEX_2D*pVtx;

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

			//���[�h�ݒ�(�Q�[����ʂɈڍs)
			SetFade(MODE_RESULT);

			return;
		}
		break;
	}
	if (GetKeyboardPress(DIK_A) == true)
	{//A�L�[��������[��]
		if (GetKeyboardPress(DIK_W) == true)
		{
			g_posPlayer.x -= sinf(D3DX_PI*0.25f) * 5.0f;//	4/3�@0.75�p�x5.0f����
			g_posPlayer.y -= cosf(D3DX_PI*0.25f) * 5.0f;
		}
		else if (GetKeyboardPress(DIK_S) == true)
		{
			g_posPlayer.x -= sinf(D3DX_PI*0.25f) * 5.0f;//	4/1
			g_posPlayer.y += cosf(D3DX_PI*0.25f) * 5.0f;//	4/1
		}
		else
		{
			g_posPlayer.x -= 5.0f;//�v���C���[�̈ʒu�Ɉړ��ʂ𑫂�
		}	   
   }
	else if (GetKeyboardPress(DIK_W) == true)
	{//W�L�[��������[��n
		if (GetKeyboardPress(DIK_D) == true)
		{
			g_posPlayer.x += sinf(D3DX_PI*0.25f) * 5.0f;//	4/3
			g_posPlayer.y -= cosf(D3DX_PI*0.25f) * 5.0f;
		}
		else if (GetKeyboardPress(DIK_A) == true)
		{
			g_posPlayer.x -= sinf(D3DX_PI*0.25f) * 5.0f;//	4/3�@0.75�p�x5.0f����
			g_posPlayer.y -= cosf(D3DX_PI*0.25f) * 5.0f;
		}
		else
		{
			g_posPlayer.y -= 5.0f;//�v���C���[�̈ʒu�Ɉړ��ʂ𑫂�
		}
	}
   else  if (GetKeyboardPress(DIK_S) == true)
   {//S�L�[��������[��]
	   if (GetKeyboardPress(DIK_D) == true)
	   {
		   g_posPlayer.x += sinf(D3DX_PI*0.25f) * 5.0f;//	4/3
		   g_posPlayer.y += cosf(D3DX_PI*0.25f) * 5.0f;
	   }
	   else if (GetKeyboardPress(DIK_A) == true)
	   {
		   g_posPlayer.x -= sinf(D3DX_PI*0.25f) * 5.0f;//	4/3�@0.75�p�x5.0f����
		   g_posPlayer.y += cosf(D3DX_PI*0.25f) * 5.0f;
	   }
	   else
	   {
		   g_posPlayer.y += 5.0f;//�v���C���[�̈ʒu�Ɉʒu�ʂ𑫂�
	   }
   }
   else if (GetKeyboardPress(DIK_D) == true)
   {//D�L�[��������[�E]
	   if (GetKeyboardPress(DIK_W) == true)
	   {
		   g_posPlayer.x += sinf(D3DX_PI*0.25f) * 5.0f;//	4/3
		   g_posPlayer.y -= cosf(D3DX_PI*0.25f) * 5.0f;
	   }
	   else if (GetKeyboardPress(DIK_S) == true)
	   {
		   g_posPlayer.x += sinf(D3DX_PI*0.25f) * 5.0f;//	4/3�@0.75�p�x5.0f����
		   g_posPlayer.y += cosf(D3DX_PI*0.25f) * 5.0f;
	   }
	   else
	   {
		   g_posPlayer.x += 5.0f;//�v���C���[�̈ʒu�Ɉړ��ʂ𑫂�
	   }
   }
   if (GetKeyboardTrigger(DIK_SPACE) == true)
   {//SPACE�L�[�������ꂽ
	//�T�E���h�̍Đ�
	   PlaySound(SOUND_LABEL_SE_SHOT);

	   //�e�̐ݒ�
	   SetBullet(g_posPlayer, D3DXVECTOR3(6.0f,0.0f,0.0f));//6.0f,-3.0f,-6.0f
   }
  
   VERTEX_2D*pVtx;		//���_���փ|�C���^

   //���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
   g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);

   pVtx[0].pos = D3DXVECTOR3(g_posPlayer.x - PLAYER_SIZE_X, g_posPlayer.y - PLAYER_SIZE_Y, g_posPlayer.z);
   pVtx[1].pos = D3DXVECTOR3(g_posPlayer.x + PLAYER_SIZE_X, g_posPlayer.y - PLAYER_SIZE_Y, g_posPlayer.z);
   pVtx[2].pos = D3DXVECTOR3(g_posPlayer.x - PLAYER_SIZE_X, g_posPlayer.y + PLAYER_SIZE_Y, g_posPlayer.z);
   pVtx[3].pos = D3DXVECTOR3(g_posPlayer.x + PLAYER_SIZE_X, g_posPlayer.y + PLAYER_SIZE_Y, g_posPlayer.z);
   
   if (g_player.bDisp == true)
   {//�G���g�p�����
	   Enemy*pEnemy;
	   int nCntEnemy;
	   pEnemy = GetEnemy();

	   for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++, pEnemy++)
	   {
		   if (pEnemy->bUse== true)
		   {//�G������Ƃ�
			   if (pEnemy->pos.x + ENEMY_SIZE / 2 > g_posPlayer.x &&
				   pEnemy->pos.x - ENEMY_SIZE / 2 < g_posPlayer.x &&
				   pEnemy->pos.y + ENEMY_SIZE / 2 > g_posPlayer.y &&
				   pEnemy->pos.y - ENEMY_SIZE / 2 < g_posPlayer.y)

			   {//�G�ƃv���C���[����������

				//�T�E���h�̍Đ�
				   PlaySound(SOUND_LABEL_SE_bakuha);

				   HitPlayer(5);
			   }

			   if (g_posPlayer.x + PLAYER_SIZE_X >= SCREEN_WIDTH)
			   {//��ʂ̉E�ɓ�������
				   g_posPlayer.x  = SCREEN_WIDTH- PLAYER_SIZE_X;
				   
			   }

			   if (g_posPlayer.x - PLAYER_SIZE_X <= 0.0f)
			   {//��ʂ̍��ɓ�������

				   g_posPlayer.x =  PLAYER_SIZE_X;
				   
			   }

			   if (g_posPlayer.y + PLAYER_SIZE_Y >= SCREEN_HEIGHT)
			   {//��ʂ����ɓ�������
				   g_posPlayer.y = SCREEN_HEIGHT - PLAYER_SIZE_Y;
				  
			   }

			   if (g_posPlayer.y - PLAYER_SIZE_Y <= 0.0f)
			   {//��ʂ���ɓ�������
				  
				   g_posPlayer.y =  PLAYER_SIZE_Y;
				  
			   }

		   }
	   }
   }
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
	/*g_player.nLife = 10;*/

	g_player.nLife -= nDamage;

	if (g_player.nLife <= 0)
	{

		g_player.bDisp = false;
		g_player.state = PLAYERSTATE_DEATH;
		g_player.nCounterState = 60;

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
