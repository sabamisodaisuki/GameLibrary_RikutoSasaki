//============================================================
//
//  �r���{�[�h[billborad.cpp]
// Aothur : Rikuto Sasaki
//
//============================================================
#include "billborad.h"
#include "main.h"

//============================================================
//�}�N����`
//============================================================
#define MAX_Billborad		(256)	//�r���{�[�h�̍ő吔
#define Billborad_SIZE_X		(60)	//�r���{�[�h�̃T�C�Y
#define Billborad_SIZE_Y 	(60)	//�r���{�[�h�̃T�C�Y
//============================================================
//�O���[�o���ϐ�
//============================================================
LPDIRECT3DTEXTURE9 g_pTextureBillborad = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBillborad = NULL;	// ���_�o�b�t�@�ւ̃|�C���^
Billborad g_aEffect[MAX_Billborad];						  //�e

//============================================================
// �r���{�[�h�̏�����
//============================================================
void lnitBillborad(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	int nCntPlayer;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/SETUMEI.jpg",
		&g_pTextureBillborad);

	//�e�̏��̏�����
	for (nCntPlayer = 0; nCntPlayer< MAX_Billborad; nCntPlayer++)
	{
		g_aEffect[nCntPlayer].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEffect[nCntPlayer].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEffect[nCntPlayer].bUse = false;
	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_Billborad,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBillborad,
		NULL);

	//���_���փ|�C���^
	VERTEX_3D *pVtx = NULL;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBillborad->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntPlayer = 0; nCntPlayer < MAX_Billborad; nCntPlayer++)
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
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		//���_�J���[�̕`��
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBillborad->Unlock();

	//�r���{�[�h�ʒu
	SetBillborad(D3DXVECTOR3(30.0f, 400.0f, -700.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (100.0f), (100.0f));
}

//============================================================
// �e�̏I������
//============================================================
void UninitBillborad(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureBillborad != NULL)
	{
		g_pTextureBillborad->Release();
		g_pTextureBillborad = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBillborad != NULL)
	{
		g_pVtxBuffBillborad->Release();
		g_pVtxBuffBillborad = NULL;
	}
}

//============================================================
// �r���{�[�h�̍X�V����
//============================================================
void UpdateBillborad(void)
{

}

//============================================================
// �r���{�[�h�̐ݒ�
//============================================================
void SetBillborad(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	int nCntPlayer;
	VERTEX_3D*pVtx;
	g_pVtxBuffBillborad->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntPlayer = 0; nCntPlayer < MAX_Billborad; nCntPlayer++)
	{
		if (g_aEffect[nCntPlayer].bUse == false)
		{//�r���{�[�h���g�p����ĂȂ��ꍇ
			g_aEffect[nCntPlayer].pos = pos;
			g_aEffect[nCntPlayer].fWidth = fWidth;//��
			g_aEffect[nCntPlayer].fHeight = fHeight;//����
			g_aEffect[nCntPlayer].rot = rot;		//����

			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(-g_aEffect[nCntPlayer].fWidth / 2.0f, g_aEffect[nCntPlayer].fHeight / 2.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEffect[nCntPlayer].fWidth / 2.0f, g_aEffect[nCntPlayer].fHeight / 2.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(-g_aEffect[nCntPlayer].fWidth / 2.0f, -g_aEffect[nCntPlayer].fHeight / 2.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEffect[nCntPlayer].fWidth / 2.0f, -g_aEffect[nCntPlayer].fHeight / 2.0f, 0.0f);

			g_aEffect[nCntPlayer].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtxBuffBillborad->Unlock();
}

//============================================================
// �r���{�[�h�̕`�揈��
//============================================================
void DrawBillborad(void)
{
	//�f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxView;
	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X
	

	pDevice->GetTransform(D3DTS_VIEW, &mtxView);//�r���[�}�g���b�N�X�̎擾

	for (int nCntPlayer = 0; nCntPlayer < MAX_Billborad; nCntPlayer++)
	{
		if (g_aEffect[nCntPlayer].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_aEffect[nCntPlayer].mtxWorld);
			pDevice->SetRenderState(D3DRS_ZENABLE,FALSE);
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

			//�J�����t���ݒ�
			g_aEffect[nCntPlayer].mtxWorld._11 = mtxView._11;
			g_aEffect[nCntPlayer].mtxWorld._12 = mtxView._21;
			g_aEffect[nCntPlayer].mtxWorld._13 = mtxView._31;
			/*g_aEffect[nCntPlayer].mtxWorld._21 = mtxView._12;
			g_aEffect[nCntPlayer].mtxWorld._22 = mtxView._22;
			g_aEffect[nCntPlayer].mtxWorld._23 = mtxView._32;*/
			g_aEffect[nCntPlayer].mtxWorld._31 = mtxView._13;
			g_aEffect[nCntPlayer].mtxWorld._32 = mtxView._23;
			g_aEffect[nCntPlayer].mtxWorld._33 = mtxView._33;

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aEffect[nCntPlayer].rot.y, g_aEffect[nCntPlayer].rot.x, g_aEffect[nCntPlayer].rot.z);
			D3DXMatrixMultiply(&g_aEffect[nCntPlayer].mtxWorld, &g_aEffect[nCntPlayer].mtxWorld, &mtxRot);

			//�ʒu�𔽉f.
			D3DXMatrixTranslation(&mtxTrans, g_aEffect[nCntPlayer].pos.x, g_aEffect[nCntPlayer].pos.y, g_aEffect[nCntPlayer].pos.z);
			D3DXMatrixMultiply(&g_aEffect[nCntPlayer].mtxWorld, &g_aEffect[nCntPlayer].mtxWorld, &mtxTrans);

			//���C�g�̖���
			pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_aEffect[nCntPlayer].mtxWorld);

			//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffBillborad, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBillborad);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntPlayer * 4, 2);

			//���ɖ߂�
			pDevice->SetRenderState(D3DRS_ZENABLE,TRUE);
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
		}
	}

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

	//���C�g�̗L��
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}