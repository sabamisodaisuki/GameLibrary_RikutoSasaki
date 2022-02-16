#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Enemy.h"
#include"bg.h"
#include"Score.h"
#include"block.h"
#define ENEMY_Z			(5.0f)


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_apTextureEnemy[NUM_ENEMY] = {NULL};	//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffEnemy = NULL;			//���_�o�b�t�@�|�C���^
Enemy g_aEnemy[MAX_ENEMY];								//�G�̏��
int g_nEnemyCouter;										//�G�̃J�E���g


//�G�l�~�[�̎擾
Enemy*GetEnemy(void)
{
	return &g_aEnemy[0];
}

//�G�l�~�[�̏���������
void lnitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEnemy;

	g_nEnemyCouter = 0;

	//�J�E���^�[�̏�����
	nCntEnemy = 0;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();


	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ikaa.png",
		&g_apTextureEnemy[0]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika001.png",
		&g_apTextureEnemy[1]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika002.png",
		&g_apTextureEnemy[2]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika003.png",
		&g_apTextureEnemy[3]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika004.png",
		&g_apTextureEnemy[4]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika005.png",
		&g_apTextureEnemy[5]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika06.png",
		&g_apTextureEnemy[6]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika007.png",
		&g_apTextureEnemy[7]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika008.png",
		&g_apTextureEnemy[8]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika09.png",
		&g_apTextureEnemy[9]);


	//�G�l�~�[�̏�����
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		g_aEnemy[nCntEnemy].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].nType = 0;
		g_aEnemy[nCntEnemy].bUse = false;
	}

	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ENEMY * NUM_ENEMY,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffEnemy,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^

//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{

		//���_���W�̐ݒ�
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
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		
		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffEnemy->Unlock();
}
//�|���S���̏I������
void UninitEnemy(void)
{
	int nCntEnemy;


	for (nCntEnemy = 0; nCntEnemy < NUM_ENEMY; nCntEnemy++)
	{ //�e�N�X�`���̔j��
		if (g_apTextureEnemy[nCntEnemy] != NULL)
		{
			g_apTextureEnemy[nCntEnemy]->Release();
			g_apTextureEnemy[nCntEnemy] = NULL;
		}
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffEnemy != NULL)
	{
		g_pVtxBuffEnemy->Release();
		g_pVtxBuffEnemy = NULL;
	}

}
//�G�l�~�[�̍X�V����
void UpdateEnemy(void)
{

	int nCntEnemy;
	VERTEX_2D*pVtx;
	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	g_nEnemyCouter++;			//�G�̊Ԋu
	

	if (g_nEnemyCouter%240 == 0)
	{
		SetEnemy(D3DXVECTOR3(430.0f, 335.0f, 0.0f), D3DXVECTOR3(0.0f, 50.0f, 0.0f), 4);

	}



	if (g_nEnemyCouter%290 == 0)
	{
		SetEnemy(D3DXVECTOR3(650.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 50.0f, 0.0f), 1);
	
		SetEnemy(D3DXVECTOR3(720.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 30.0f, 0.0f), 2);

		SetEnemy(D3DXVECTOR3(800.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 70.0f, 0.0f), 4);

	}
	//if (g_nEnemyCouter%380 == 0)
	//{
	//	SetEnemy(D3DXVECTOR3(110.0f, 40.0f, 0.0f), D3DXVECTOR3(2.0f, 0.0f, 0.0f), 0);
	//}

	if (g_nEnemyCouter%460 == 0)
	{
		SetEnemy(D3DXVECTOR3(1000.0f, 130.0f, 0.0f), D3DXVECTOR3(3.0f, 0.0f, 0.0f), 1);

		SetEnemy(D3DXVECTOR3(1000.0f, 350.0f, 0.0f), D3DXVECTOR3(-8.0f, 0.0f, 0.0f), 2);

		SetEnemy(D3DXVECTOR3(1000.0f, 500.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f), 4);

	}
	////��
	//if (g_nEnemyCouter%310 == 0)
	//{
	//	SetEnemy(D3DXVECTOR3(400.0f, 250.0f, 0.0f), D3DXVECTOR3(8.0f, 0.0f, 0.0f), 3);

	//}

	//if (g_nEnemyCouter%430 == 0)
	//{
	//	SetEnemy(D3DXVECTOR3(50, 50.0f, 0.0f), D3DXVECTOR3(8.0f, 0.0f, 0.0f), 3);

	//}

	//if (g_nEnemyCouter%320 == 0)
	//{
	//	SetEnemy(D3DXVECTOR3(1120.0f, 400.0f, 0.0f), D3DXVECTOR3(-4.0f, 0.0f, 0.0f), 5);
	//
	//	SetEnemy(D3DXVECTOR3(640.0f, 300.0f, 0.0f), D3DXVECTOR3(2.0f, 0.0f, 0.0f), 6);
	//
	//	SetEnemy(D3DXVECTOR3(680.0f, 290.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f), 7);

	//	SetEnemy(D3DXVECTOR3(730.0f, 420.0f, 0.0f), D3DXVECTOR3(5.0f,  0.0f, 0.0f), 8);
	//}
	//if (g_nEnemyCouter%280 == 0)
	//{

	//	SetEnemy(D3DXVECTOR3(620.0f, 330.0f, 0.0f), D3DXVECTOR3(2.0f, 0.0f, 0.0f), 6);

	//	SetEnemy(D3DXVECTOR3(1100.0f, 290.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 7);

	//	SetEnemy(D3DXVECTOR3(630.0f, 420.0f, 0.0f), D3DXVECTOR3(-5.0f, 0.0f, 0.0f), 8);
	//}
	//if (g_nEnemyCouter%240 == 0)
	//{

	//	SetEnemy(D3DXVECTOR3(420.0f, 420.0f, 0.0f), D3DXVECTOR3(15.0f, 0.0f, 0.0f), 8);
	//}
	//
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{
			switch (g_aEnemy[nCntEnemy].state)
			{
			case ENEMYSTA_NORMAL:
				break;

			case ENEMYSTA_DAMAGE:
				g_aEnemy[nCntEnemy].nCounterState--;

				if (g_aEnemy[nCntEnemy].nCounterState <= 0)
				{
					g_aEnemy[nCntEnemy].state = ENEMYSTA_NORMAL;

					VERTEX_2D*pVtx;

					//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
					g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

					pVtx += 4 * nCntEnemy;//�|�C���^���S���i�߂�

					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
					pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
					pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
					pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

					//���_�o�b�t�@�A�����b�N
					g_pVtxBuffEnemy->Unlock();
				}
				break;
			}
		}
	}
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{//�G�l�~�[���o�������
			
		 //�O��̈ʒu��ۑ�
			g_aEnemy[nCntEnemy].OldEnemy = g_aEnemy[nCntEnemy].pos;


			//�ړ��l
			g_aEnemy[nCntEnemy].move.y += ENEMY_Z / 2;
			g_aEnemy[nCntEnemy].pos.x += g_aEnemy[nCntEnemy].move.x/2 ;
			g_aEnemy[nCntEnemy].pos.y+= g_aEnemy[nCntEnemy].move.y / 2;
			

		 //�u���b�N�Ƃ̓����蔻��
			bool blsLanding = CollisionBlock(
				&g_aEnemy[nCntEnemy].pos,
				&g_aEnemy[nCntEnemy].OldEnemy,
				&g_aEnemy[nCntEnemy].move,
				ENEMY_SIZE_X,
				ENEMY_SIZE_Y);


		 //�G�l�~�[�̈ʒu�̍X�V

		/*	g_aEnemy[nCntEnemy].pos += g_aEnemy[nCntEnemy].move;*/

			//���_���W�̍X�V(�G�l�~�[�̑傫���j
			pVtx[0].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE_Y/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE_Y/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y, 0.0f);

			if (g_aEnemy[nCntEnemy].pos.x <= 6)

			{//��ʊO�ɃG�l�~�[���o����
				g_aEnemy[nCntEnemy].bUse = false;
			}
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffEnemy->Unlock();
}

//�G�l�~�[�̕`�揈��
void DrawEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEnemy;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffEnemy, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{//�G���g�p����Ă���

		 //�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_apTextureEnemy[g_aEnemy[nCntEnemy].nType]);

		 //�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEnemy * 4, 2);
		}





	}
}



//�G�l�~�[�̐ݒ菈��
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 move,int nType)
{
	int nCntEnemy;

	VERTEX_2D*pVtx;

	//���_�o�b�t�@���b�N���A���_���փ|�C���^�擾
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == false)
		{//�G���g�p����ĂȂ��ꍇ

			//�G�̏��̐ݒ�
			g_aEnemy[nCntEnemy].pos = pos;

			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - 6.0f, g_aEnemy[nCntEnemy].pos.y - 6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + 6.0f, g_aEnemy[nCntEnemy].pos.y - 6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - 6.0f, g_aEnemy[nCntEnemy].pos.y + 6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + 6.0f, g_aEnemy[nCntEnemy].pos.y + 6.0f, 0.0f);


			//���_�J���[�̕`��
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			g_aEnemy[nCntEnemy].move = move;
			g_aEnemy[nCntEnemy].nLife = 10;
			g_aEnemy[nCntEnemy].bUse = true;	//�g�p���Ă����Ԃɂ���
			g_aEnemy[nCntEnemy].nType = nType;
			/*g_aEnemy[nCntEnemy].nScore = 500;*/

			break;
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtxBuffEnemy->Unlock();
}
//�G�̃q�b�g����
void HitEnemy(int nCntEnemy, int nDamage)
{
	g_aEnemy[nCntEnemy].nLife -= nDamage;

	if (g_aEnemy[nCntEnemy].nLife <= 0)
	{
		////�����̐ݒ�d
		//AddScore(50);

		g_aEnemy[nCntEnemy].bUse = false;
	}
	else
	{
		g_aEnemy[nCntEnemy].state = ENEMYSTA_DAMAGE;
		g_aEnemy[nCntEnemy].nCounterState = 15;

		VERTEX_2D*pVtx;
		
		//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
		g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

		pVtx += 4*nCntEnemy;//�|�C���^���S���i�߂�

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 0, 0, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 0, 0, 255);
	
		//���_�o�b�t�@�A�����b�N
		g_pVtxBuffEnemy->Unlock();
	}
}
