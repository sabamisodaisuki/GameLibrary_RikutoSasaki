#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include "Enemy.h"
#include"bg2.h"
#include"game.h"

////�}�N����]
#define MAX_AWA		(5)					//�A�̐�
#define AWA_SIZE			(140.0f)	//�G�̃T�C�Y
#define NUM_AWA		(5)
//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_apTextureBG2=NULL;	//�e�N�X�`���O����
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBG2 = NULL;	//���_�o�b�t�@
BG2 g_aBG2[MAX_AWA];
int g_nBG2Couter;								//float g_aPosTexV[NUM_BG];						//�e�N�X�`�����W�J�n�ʒu�iV�l�j

//�w�i�̏���������
void lnitBG2(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^
								
	//�w�i�̏�����
	for (int nCntBG2 = 0; nCntBG2 < MAX_AWA; nCntBG2++)
	{
		g_aBG2[nCntBG2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBG2[nCntBG2].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBG2[nCntBG2].bUse = false;
	}

	g_nBG2Couter = 0;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/awa2.png",		//	NEW2		
		&g_apTextureBG2);

	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D)* 4 *MAX_AWA*NUM_AWA,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBG2,
		NULL);

	VERTEX_2D*pVtx;		//���_���փ|�C���^

						
	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBG2->Lock(0, 0, (void**)&pVtx, 0);


	for (int nCntAWA = 0; nCntAWA < MAX_AWA; nCntAWA++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(200.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 200.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(200.0f, 200.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̕`��
		pVtx[0].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
		pVtx[1].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
		pVtx[2].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);
		pVtx[3].col = D3DXCOLOR(255.0f, 255.0f, 255.0f, 255.0f);

		//�e�N�X�`�����W
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBG2->Unlock();
}
//}

void UninitBG2(void)
{
	int nCntAWA;

	for (nCntAWA = 0; nCntAWA < NUM_AWA; nCntAWA++)
	{
		{ //�e�N�X�`���̔j��
			if (g_apTextureBG2 != NULL)
			{
				g_apTextureBG2->Release();
				g_apTextureBG2 = NULL;
			}
		}
	}
	//�o�b�t�@�̔j��
	if (g_pVtxBuffBG2 != NULL)
	{
		g_pVtxBuffBG2->Release();
		g_pVtxBuffBG2= NULL;
	}
}

void UpdateBG2(void)
{
	VERTEX_2D*pVtx;		//���_���փ|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBG2->Lock(0, 0, (void**)&pVtx, 0);

	g_nBG2Couter++;
	
	if (g_nBG2Couter == 350)
	{
		SetBG2(D3DXVECTOR3(400.0f, 900.0f, 0.0f), D3DXVECTOR3(0.0f, -5.0f, 0.0f));
		g_nBG2Couter = 0;
	}
	
	for (int nCntAWA = 0; nCntAWA < MAX_AWA; nCntAWA++)
	{
		if (g_aBG2[nCntAWA].bUse == true)
		{
			//�G�l�~�[�̈ʒu�̍X�V

			g_aBG2[nCntAWA].pos += g_aBG2[nCntAWA].move;

			//���_���W�̍X�V(�G�l�~�[�̑傫���j
			pVtx[0].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x - AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y - AWA_SIZE / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x + AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y - AWA_SIZE / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x - AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y + AWA_SIZE / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBG2[nCntAWA].pos.x + AWA_SIZE / 2, g_aBG2[nCntAWA].pos.y + AWA_SIZE / 2, 0.0f);

			if (g_aBG2[nCntAWA].pos.y <= 6)

			{//��ʊO�ɃG�l�~�[���o����
				g_aBG2[nCntAWA].bUse = false;
			}

		}
		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBG2->Unlock();
}

void DrawBG2(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffBG2, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	////�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, g_apTextureBG2[nCntAWA]);

	for (int nCntBG2 = 0; nCntBG2 < MAX_AWA; nCntBG2++)
	{
		if (g_aBG2[nCntBG2].bUse == true)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_apTextureBG2);
			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBG2*4, 2);
		}
	}
}

void SetBG2(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	
		int nCntBG2;

		VERTEX_2D*pVtx;

		//���_�o�b�t�@���b�N���A���_���փ|�C���^�擾
		g_pVtxBuffBG2->Lock(0, 0, (void**)&pVtx, 0);

		for (nCntBG2 = 0; nCntBG2 < MAX_AWA; nCntBG2++)
		{
			if (g_aBG2[nCntBG2].bUse == false)
			{//�G���g�p����ĂȂ��ꍇ

			 //�G�̏��̐ݒ�
				g_aBG2[nCntBG2].pos = pos;

				//���_���W�̍X�V
				pVtx[0].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x - 6.0f, g_aBG2[nCntBG2].pos.y - 6.0f, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x + 6.0f, g_aBG2[nCntBG2].pos.y - 6.0f, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x - 6.0f, g_aBG2[nCntBG2].pos.y + 6.0f, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(g_aBG2[nCntBG2].pos.x + 6.0f, g_aBG2[nCntBG2].pos.y + 6.0f, 0.0f);


				//���_�J���[�̕`��
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

				g_aBG2[nCntBG2].move = move;
				g_aBG2[nCntBG2].bUse = true;	//�g�p���Ă����Ԃɂ���

				break;
			}
			pVtx += 4;//�|�C���^���S���i�߂�
		}
		g_pVtxBuffBG2->Unlock();
	}
