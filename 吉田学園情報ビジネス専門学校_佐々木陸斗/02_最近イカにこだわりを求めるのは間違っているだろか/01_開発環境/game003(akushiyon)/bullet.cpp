#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Score.h"
#include"Enemy.h"
#include"sound.h"
//�}�N����`
#define MAX_BULLET			(5)		//�e�̍ő吔
#define BULLET_SIZ			(25)		//�e�T�C�Y

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;
Bullet g_aBullet[MAX_BULLET];

//�e�̏���������
void lnitBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntBullet;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();


	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/kabo1.png",					//akira000.png,koda.jpg,su.jpg,runningman100.png,bullet000.png,�l�Q.png,���l�Q.png,�؂���.jpg
		&g_pTextureBullet);

	//�e�̏��̏�����
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].nLife = 10;
		g_aBullet[nCntBullet].bUse = false;
	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_BULLET,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBullet,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^
	/*int nCntBullet;*/

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
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
	g_pVtxBuffBullet->Unlock();

}
//�|���S���̏I������
void UninitBullet(void)
{
	//�T�E���h�̒�~
	StopSound();

	//�e�N�X�`���̔j��
	if (g_pTextureBullet != NULL)
	{
		g_pTextureBullet->Release();
		g_pTextureBullet = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}

}
//�e�̍X�V����
void UpdateBullet(void)
{
	int nCntBullet;
	VERTEX_2D*pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
	
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//�e���g�p�����
			Enemy*pEnemy;
			int nCntEnemy;
			pEnemy = GetEnemy();

			//�e�̈ʒu�̍X�V
			g_aBullet[nCntBullet].pos += g_aBullet[nCntBullet].move;

			//�e�̈ʒu�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y - BULLET_SIZ/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y - BULLET_SIZ/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y + BULLET_SIZ/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + BULLET_SIZ/2, g_aBullet[nCntBullet].pos.y + BULLET_SIZ/2, 0.0f);

			if (g_aBullet[nCntBullet].pos.y <= 6)

			{//��ʊO�ɒe���o����
				g_aBullet[nCntBullet].bUse = false;
			}

			//�����̃J�E���g�_�E��

			g_aBullet[nCntBullet].nLife -= 1;

			if (g_aBullet[nCntBullet].nLife == 0)
			{
				g_aBullet[nCntBullet].bUse = false;
			}

			for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++,pEnemy++)
			{
				if (pEnemy->bUse == true)
				{//�G������Ƃ�
					if (pEnemy->pos.x + ENEMY_SIZE_X/ 2 > g_aBullet[nCntBullet].pos.x &&
						pEnemy->pos.x - ENEMY_SIZE_X / 2 < g_aBullet[nCntBullet].pos.x &&
              			pEnemy->pos.y + ENEMY_SIZE_Y / 2 > g_aBullet[nCntBullet].pos.y &&
						pEnemy->pos.y - ENEMY_SIZE_Y / 2 < g_aBullet[nCntBullet].pos.y)
					{//�G�ƒe����������

					
						//�X�R�A�ݒ�
						AddScore(50);
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_EXPLOSION);

						////�����̐ݒ�
						//SetExplosion(g_aBullet[nCntBullet].pos);

             			//pEnemy->bUse = false;//�g�p���Ă��Ȃ����

						//�G�̃q�b�g����
            			HitEnemy(nCntEnemy,5);
						
						//�g�p���Ă��Ȃ���Ԃ�
						g_aBullet[nCntBullet].bUse = false;

					}

				}
			}
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBullet->Unlock();
}
//�e�̕`�揈��
void DrawBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntBullet;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//�e���g�p����Ă���
		//	Enemy*pEnemy = GetEnemy();
		//	int nCntEnemy;

		////	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
		////	{
		//		if (pEnemy->bUse == true)
		//		{

		//		}
		//	}
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBullet);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,nCntBullet*4, 2);
		}
	}
}
//�e�̐ݒ菈��
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntBullet;
	VERTEX_2D*pVtx;
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == false)
		{//�e���g�p����ĂȂ��ꍇ
			g_aBullet[nCntBullet].pos = pos;

			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 6.0f, g_aBullet[nCntBullet].pos.y - 6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 6.0f, g_aBullet[nCntBullet].pos.y - 6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 6.0f, g_aBullet[nCntBullet].pos.y + 6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 6.0f, g_aBullet[nCntBullet].pos.y + 6.0f, 0.0f);

			g_aBullet[nCntBullet].move = move;
			g_aBullet[nCntBullet].nLife = 100;
			g_aBullet[nCntBullet].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtxBuffBullet->Unlock();
}

