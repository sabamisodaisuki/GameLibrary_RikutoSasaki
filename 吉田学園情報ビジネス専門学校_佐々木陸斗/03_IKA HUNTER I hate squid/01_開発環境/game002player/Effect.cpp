#include "main.h"
#include "player.h"
#include "input.h"
#include"Effect.h"
#include "Effect.h"
#include"title.h"
//�}�N����`
#define MAX_EFFECT			(4096)		//�G�t�F�N�g�̍ő吔

//�G�t�F�N�g�̍\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;		//�ʒu
	D3DXCOLOR col;			//�F
	D3DXVECTOR3 move;		//�ړ�
	float fRadius;			//���a�i�傫���j
	int nLife;				//�����i�\�����ԁj
	bool bUse;				//�g�p���Ă��邩�ǂ���

}Effect;

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureEffect = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffEffect = NULL;
Effect g_aEffect[MAX_EFFECT];


//�e�̏���������
void lnitEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEffect;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();


	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/effect000.jpg",					//akira000.png,koda.jpg,su.jpg,runningman100.png,Effect000.png,�l�Q.png,���l�Q.png,�؂���.jpg
		&g_pTextureEffect);

	//�e�̏��̏�����
	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		g_aEffect[nCntEffect].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEffect[nCntEffect].nLife = 10;
		g_aEffect[nCntEffect].bUse = false;
	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_EFFECT,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffEffect,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^
						/*int nCntEffect;*/

						//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
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
	g_pVtxBuffEffect->Unlock();
}
//�|���S���̏I������
void UninitEffect(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureEffect != NULL)
	{
		g_pTextureEffect->Release();
		g_pTextureEffect = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffEffect != NULL)
	{
		g_pVtxBuffEffect->Release();
		g_pVtxBuffEffect = NULL;
	}

}
//�e�̍X�V����
void UpdateEffect(void)
{
	int nCntEffect;

	VERTEX_2D*pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == true)
		{//�G�t�F�N�g���g�p�����
		/*	Effect*pEffect;*/
			/*int nCntEffect;*/
			
			////�e�̈ʒu�̍X�V
			//g_aEffect[nCntEffect].pos += g_aEffect[nCntEffect].move;


			//���_�J���[�̕`��
			pVtx[0].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(6.0f, 1.0f, 1.0f, 1.0f);

			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);




			/*if (g_aEffect[nCntEffect].pos.y <= 6)*/

			//{//��ʊO�ɒe���o����
			//	g_aEffect[nCntEffect].bUse = false;
			//}

			////�����̃J�E���g�_�E��

			//g_aEffect[nCntEffect].nLife -= 1;

			//if (g_aEffect[nCntEffect].nLife == 0)
			//{
			//	g_aEffect[nCntEffect].bUse = false;
			//}

			
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffEffect->Unlock();
}
//�e�̕`�揈��
void DrawEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEffect;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffEffect, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	////a�v���f�B���O�����Z�����ɐݒ�
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	//{
	//	if (g_aEffect[nCntEffect].bUse == true)
	//	{
	//		//�|���S���̕`��
	//		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);
	//	}
	//}

	////a�v���f�B���O�����Z�����ɐݒ�
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);


	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == true)
		{//�e���g�p����Ă���
		 //	Effect*pEffect = GetEffect();
		
		 //�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureEffect);
			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_2D);

			//a�v���f�B���O�����Z�����ɐݒ�
			pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

			for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
			{
				if (g_aEffect[nCntEffect].bUse == true)
				{
					//�|���S���̕`��
					pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);
				}
			}
			////�|���S���̕`��
			//pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);
		}
	}
}
//�e�̐ݒ菈��
void SetEffect(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntEffect;
	VERTEX_2D*pVtx;
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == false)
		{//�e���g�p����ĂȂ��ꍇ
			g_aEffect[nCntEffect].pos = pos;

			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x - 6.0f, g_aEffect[nCntEffect].pos.y - 6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x + 6.0f, g_aEffect[nCntEffect].pos.y - 6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x - 6.0f, g_aEffect[nCntEffect].pos.y + 6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEffect[nCntEffect].pos.x + 6.0f, g_aEffect[nCntEffect].pos.y + 6.0f, 0.0f);

			g_aEffect[nCntEffect].move = move;
			g_aEffect[nCntEffect].nLife = 100;
			g_aEffect[nCntEffect].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtxBuffEffect->Unlock();
}


//�G�t�F�N�g�̐ݒ菈��
void SetEffect(D3DXVECTOR3 pos, D3DXCOLOR col, float fRadius, int nLife)
{
	int nCntEffect;
	
	for(nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_aEffect[nCntEffect].bUse == false)
		{
			g_aEffect[nCntEffect].pos = pos;
			g_aEffect[nCntEffect].col = col;
			g_aEffect[nCntEffect].fRadius = fRadius;
			g_aEffect[nCntEffect].nLife = nLife;
			g_aEffect[nCntEffect].bUse = true;

			break;
		}
	}
}
