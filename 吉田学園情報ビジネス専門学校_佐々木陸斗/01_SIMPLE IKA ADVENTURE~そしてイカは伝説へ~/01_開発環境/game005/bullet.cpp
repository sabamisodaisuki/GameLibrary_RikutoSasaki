//============================================================
//
// 3D�e�̏��� [Bullet.cpp]
// Aothur : Rikuto Sasaki
//
//============================================================
#include "Bullet.h"
#include "main.h"
#include"effect.h"
//============================================================
//�}�N����`
//============================================================
#define MAX_Bullet		(256)	//�ǂ̍ő吔
#define BULLET_SIZE_XE_X		(6.0f)	//�ǂ̃T�C�Y
#define BULLET_SIZE_XE_Y 	(6.0f)	//�ǂ̃T�C�Y
//============================================================
//�O���[�o���ϐ�
//============================================================
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;	// ���_�o�b�t�@�ւ̃|�C���^
Bullet g_aBullet[MAX_Bullet];						  //�e

 //============================================================
 // �ǂ̏�����
 //============================================================
void lnitBullet(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	int nCntBullet;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ika008.png",
		&g_pTextureBullet);

	//�e�̏��̏�����
	for (nCntBullet = 0; nCntBullet< MAX_Bullet; nCntBullet++)
	{
		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].bUse = false;
	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_Bullet,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBullet,
		NULL);

	//���_���փ|�C���^
	VERTEX_3D *pVtx = NULL;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		//���_���W
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�e�N�X�`�����W
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		//�e���_�̖@���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//���_�J���[�̕`��
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBullet->Unlock();
}


//============================================================
// �ǂ̏I������
//============================================================
void UninitBullet(void)
{
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

//============================================================
// �e�̍X�V����
//============================================================
void UpdateBullet(void)
{
	int nCntBullet;
	VERTEX_3D*pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//�e���g�p�����
			g_aBullet[nCntBullet].pos.x -= sinf(g_aBullet[nCntBullet].rot.y)*1.5f;
			g_aBullet[nCntBullet].pos.z -= cosf(g_aBullet[nCntBullet].rot.y)*1.5f;


			//�e�̈ʒu�̍X�V
			/*g_aBullet[nCntBullet].pos += g_aBullet[nCntBullet].move;*/

		
			//if (g_aBullet[nCntBullet].pos.y <= 6)

 			SetEffect(g_aBullet[nCntBullet].pos,g_aBullet[nCntBullet].rot, D3DXVECTOR3(10.0f, 10.0f, 0.5f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 20);
			//�����̃J�E���g�_�E��

			g_aBullet[nCntBullet].nLife -- ;

			if (g_aBullet[nCntBullet].nLife <= 0)
			{
				g_aBullet[nCntBullet].bUse = false;
			}
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// �ǂ̐ݒ�
//============================================================
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntBullet;
	VERTEX_3D*pVtx;
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == false)
		{//�ǂ��g�p����ĂȂ��ꍇ
			g_aBullet[nCntBullet].pos = pos;
			g_aBullet[nCntBullet].move = move;
			g_aBullet[nCntBullet].nLife = 100;
			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3( - 6.0f,  6.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3( + 6.0f,  6.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3( - 6.0f, -6.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3( + 6.0f, - 6.0f, 0.0f);

			g_aBullet[nCntBullet].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// �e�̕`�揈��
//============================================================
void DrawBullet(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCntBullet = 0; nCntBullet < MAX_Bullet; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{

			D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X
			//���[���h�}�g���b�N�X�̏�����
			D3DXMATRIX mtxView;
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);//�r���[�}�g���b�N�X�̎擾
			D3DXMatrixIdentity(&g_aBullet[nCntBullet].mtxWorld);

			//Z�o�b�t�@
			pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

			//�J�����t���ݒ�
			g_aBullet[nCntBullet].mtxWorld._11 = mtxView._11;
			g_aBullet[nCntBullet].mtxWorld._12 = mtxView._21;
			g_aBullet[nCntBullet].mtxWorld._13 = mtxView._31;
			g_aBullet[nCntBullet].mtxWorld._21 = mtxView._12;
			g_aBullet[nCntBullet].mtxWorld._22 = mtxView._22;
			g_aBullet[nCntBullet].mtxWorld._23 = mtxView._32;
			g_aBullet[nCntBullet].mtxWorld._31 = mtxView._13;
			g_aBullet[nCntBullet].mtxWorld._32 = mtxView._23;
			g_aBullet[nCntBullet].mtxWorld._33 = mtxView._33;


			//�ʒu�𔽉f.
			D3DXMatrixTranslation(&mtxTrans, g_aBullet[nCntBullet].pos.x, g_aBullet[nCntBullet].pos.y, g_aBullet[nCntBullet].pos.z);
			D3DXMatrixMultiply(&g_aBullet[nCntBullet].mtxWorld, &g_aBullet[nCntBullet].mtxWorld, &mtxTrans);

			//���C�g�̖���
			pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_aBullet[nCntBullet].mtxWorld);

			//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBullet);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBullet * 4, 2);

			//���ɖ߂�
			pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

		}
	}

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

	//���C�g�̗L��
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}
	