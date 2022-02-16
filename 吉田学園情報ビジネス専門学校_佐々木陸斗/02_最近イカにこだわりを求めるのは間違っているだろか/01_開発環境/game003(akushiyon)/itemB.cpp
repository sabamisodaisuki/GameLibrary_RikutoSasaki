#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"item.h"
#include"itemB.h"
#include"Score.h"
#include"sound.h"
#include"fade.h"
#include"HighScore.h"
//�}�N����`
#define MAX_ITEMB			(128)		//�u���b�N�̍ő吔
#define ITEMB_SIZE_X			(100.0f)		//�u���b�N�T�C�Y
#define ITEMB_SIZE_Y			(100.0f)		//�u���b�N�T�C�Y


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureITEMB = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffITEMB = NULL;
ItemB g_aItemB[MAX_ITEMB];
int g_CounterItem;



//�u���b�N�̏���������
void lnitItemb(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitemB;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();



	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/kabo1.png",
		&g_pTextureITEMB);

	//�u���b�N�̏��̏�����
	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
	{
		g_aItemB[nCntitemB].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItemB[nCntitemB].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aItemB[nCntitemB].bUse = false;


	}

	  g_CounterItem = 0;

	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEMB,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffITEMB,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^

						//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtexBuffITEMB->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
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
	g_pVtexBuffITEMB->Unlock();


	//�u���b�N�ʒu
	SetItemb(D3DXVECTOR3(250.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (50.0f));

	//�u���b�N�ʒu
	SetItemb(D3DXVECTOR3(640.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0), (50.0f));

	//�u���b�N�ʒu
	SetItemb(D3DXVECTOR3(950.0f,640.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0), (50.0f));

	//�u���b�N�ʒu
	SetItemb(D3DXVECTOR3(350.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0), (50.0f));

	

}
//�u���b�I������
void UninitItemb(void)
{
	//�T�E���h�̒�~
	StopSound();

		//�e�N�X�`���̔j��
		if (g_pTextureITEMB != NULL)
		{
			g_pTextureITEMB->Release();
			g_pTextureITEMB = NULL;
		}
		//���_�o�b�t�@�̔j��
		if (g_pVtexBuffITEMB != NULL)
		{
			g_pVtexBuffITEMB->Release();
			g_pVtexBuffITEMB = NULL;
		}
}
//�u���b�N�̍X�V����
void UpdateItemb(void)
{
	


}
//�u���b�N�̕`�揈��
void DrawItemb(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntitemB;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtexBuffITEMB, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
	{
		if (g_aItemB[nCntitemB].bUse == true)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureITEMB);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntitemB * 4, 2);
		}
	}
}
//�u���b�N�̐ݒ菈��
void SetItemb(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight)
{

	int nCntitemB;
	VERTEX_2D*pVtx;
	g_pVtexBuffITEMB->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntitemB = 0; nCntitemB < MAX_ITEMB; nCntitemB++)
	{
		if (g_aItemB[nCntitemB].bUse == false)
		{//�u���b�N���g�p����ĂȂ��ꍇ
			g_aItemB[nCntitemB].pos = pos;
			g_aItemB[nCntitemB].fWidth = fWidth;//��
			g_aItemB[nCntitemB].fHeight = fHeight;//����
			//���_���W�̍X�Vw
			pVtx[0].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x - g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y - g_aItemB[nCntitemB].fHeight / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x + g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y - g_aItemB[nCntitemB].fHeight / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x - g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y + g_aItemB[nCntitemB].fHeight / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aItemB[nCntitemB].pos.x + g_aItemB[nCntitemB].fWidth / 2, g_aItemB[nCntitemB].pos.y + g_aItemB[nCntitemB].fHeight / 2, 0.0f);

			g_aItemB[nCntitemB].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtexBuffITEMB->Unlock();
}

void CollisionItemB(D3DXVECTOR3*pPos,//���݂̈ʒu
	D3DXVECTOR3*pPosOld,			//�O��̍���
	D3DXVECTOR3*pMove,				//�ړ���
	float fWidth,					//��
	float fHeight)
{
	ItemB*pItemB;
	int nCntItemB;
	pItemB = GetItemB();

	for (nCntItemB = 0; nCntItemB < MAX_ITEMB; nCntItemB++)
	{
		if (g_aItemB[nCntItemB].bUse == true)
		{

			if (g_aItemB[nCntItemB].pos.x - g_aItemB[nCntItemB].fWidth/2  < pPos->x + fWidth/2  &&
				g_aItemB[nCntItemB].pos.x + g_aItemB[nCntItemB].fWidth/2  > pPos->x - fWidth/2  &&
				g_aItemB[nCntItemB].pos.y + g_aItemB[nCntItemB].fHeight/2  > pPos->y-fHeight &&
				g_aItemB[nCntItemB].pos.y - g_aItemB[nCntItemB].fHeight/2 < pPos->y)
			{
				DeleteItemB(nCntItemB);
			}
		}
		pItemB++;
	}
}
void DeleteItemB(int nCntItemB)
{
	
	//�T�E���h�̍Đ�
	PlaySound(SOUND_LABEL_SE_bakuha);
	// �t�F�[�h���̎擾
	FADE fade = GetFade();

	g_CounterItem++;
		//�g�p���Ă��Ȃ���Ԃ�
		g_aItemB[nCntItemB].bUse = false;

		//�X�R�A�ݒ�
		AddScore(15000);
		
		for (nCntItemB = 0; nCntItemB < MAX_ITEMB; nCntItemB++)
		{

			if (g_CounterItem == 4)//�A�C�e�������ׂĎ�胊�U���g��ʂ�
			{
				SaveHigeScore();
				SetFade(MODE_WIN);
				return;
			}
		}
	
}
//�A�C�e���̎擾
ItemB*GetItemB(void)
{
	return &g_aItemB[0];
}