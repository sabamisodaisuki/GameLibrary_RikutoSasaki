#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"item.h"
//�}�N����`
#define MAX_ITEM			(128)		//�u���b�N�̍ő吔
#define ITEM_SIZE_X			(100.0f)		//�u���b�N�T�C�Y
#define ITEM_SIZE_Y			(100.0f)		//�u���b�N�T�C�Y


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureITEM = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffITEM = NULL;
block g_aItem[MAX_ITEM];


//�u���b�N�̏���������
void lnitItem(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitem;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();



	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/���.png",
		&g_pTextureITEM);

	//�u���b�N�̏��̏�����
	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
	{
		g_aItem[nCntitem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItem[nCntitem].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItem[nCntitem].bUse = false;

	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEM,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffITEM,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^

						//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtexBuffITEM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
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
	g_pVtexBuffITEM->Unlock();


	//�u���b�N�ʒu
	SetItem(D3DXVECTOR3(350.0f, 130.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));

	//�u���b�N�ʒu
	SetItem(D3DXVECTOR3(980.0f, 260.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));

	//�u���b�N�ʒu
	SetItem(D3DXVECTOR3(60.0f, 260.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));



}
//�u���b�I������
void UninitItem(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureITEM != NULL)
	{
		g_pTextureITEM->Release();
		g_pTextureITEM = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtexBuffITEM != NULL)
	{
		g_pVtexBuffITEM->Release();
		g_pVtexBuffITEM = NULL;
	}

}
//�u���b�N�̍X�V����
void UpdateItem(void)
{





}
//�u���b�N�̕`�揈��
void DrawItem(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitem;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtexBuffITEM, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureITEM);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntitem * 4, 2);

	}
}
//�u���b�N�̐ݒ菈��
void SetItem(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight)
{

	int nCntitem;
	VERTEX_2D*pVtx;
	g_pVtexBuffITEM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitem = 0; nCntitem < MAX_ITEM; nCntitem++)
	{
		if (g_aItem[nCntitem].bUse == false)
		{//�u���b�N���g�p����ĂȂ��ꍇ
			g_aItem[nCntitem].pos = pos;
			g_aItem[nCntitem].fWidth = fWidth;//��
			g_aItem[nCntitem].fHeight = fHeight;//����
			 //���_���W�̍X�Vw
			pVtx[0].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x - g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y - g_aItem[nCntitem].fHeight / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x + g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y - g_aItem[nCntitem].fHeight / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x - g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y + g_aItem[nCntitem].fHeight / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aItem[nCntitem].pos.x + g_aItem[nCntitem].fWidth / 2, g_aItem[nCntitem].pos.y + g_aItem[nCntitem].fHeight / 2, 0.0f);

			g_aItem[nCntitem].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtexBuffITEM->Unlock();
}

