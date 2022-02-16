#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"Enemy.h"
#include"blockB.h"
//�}�N����`
#define MAX_BLOCKB			(128)		//�u���b�N�̍ő吔
#define BLOCKB_SIZE_X			(100.0f)		//�u���b�N�T�C�Y
#define BLOCKB_SIZE_Y			(100.0f)		//�u���b�N�T�C�Y


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureBlockB = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffBlock1 = NULL;
block g_aBlockB[MAX_BLOCKB];


//�u���b�N�̏���������
void lnitblockB(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblockB;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();



	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�T��B.png",
		&g_pTextureBlockB);

	//�u���b�N�̏��̏�����
	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		g_aBlockB[nCntblockB].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlockB[nCntblockB].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlockB[nCntblockB].bUse = false;

	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_BLOCKB,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffBlock1,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^

						//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtexBuffBlock1->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
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
	g_pVtexBuffBlock1->Unlock();


	//�u���b�N�ʒu
	
	SetblockB(D3DXVECTOR3(240.0f, 120.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (70.0f));//���[��


	SetblockB(D3DXVECTOR3(450.0f, 260.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (80.0f));//���[��

	SetblockB(D3DXVECTOR3(650.0f, 130.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (40.0f), (70.0f));//���[��

	SetblockB(D3DXVECTOR3(1100.0f, 180.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (50.0f), (70.0f));//���[��

	
}
//�u���b�I������
void UninitblockB(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureBlockB != NULL)
	{
		g_pTextureBlockB->Release();
		g_pTextureBlockB = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtexBuffBlock1 != NULL)
	{
		g_pVtexBuffBlock1->Release();
		g_pVtexBuffBlock1 = NULL;
	}

}
//�u���b�N�̍X�V����
void UpdateblockB(void)
{





}
//�u���b�N�̕`�揈��
void DrawblockB(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblockB;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtexBuffBlock1, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		if (g_aBlockB[nCntblockB].bUse == true)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBlockB);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntblockB * 4, 2);
		}
	}
}
//�u���b�N�̐ݒ菈��
void SetblockB(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth, float fHeight)
{

	int nCntblockB;
	VERTEX_2D*pVtx;
	g_pVtexBuffBlock1->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		if (g_aBlockB[nCntblockB].bUse == false)
		{//�u���b�N���g�p����ĂȂ��ꍇ
			g_aBlockB[nCntblockB].pos = pos;
			g_aBlockB[nCntblockB].fWidth = fWidth;//��
			g_aBlockB[nCntblockB].fHeight = fHeight;//����
												  //���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2, g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2, 0.0f);

	
			g_aBlockB[nCntblockB].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtexBuffBlock1->Unlock();
}

//�u���b�N�̓����蔻��
bool CollisionBlockB(D3DXVECTOR3*pPos,//���݂̈ʒu
	D3DXVECTOR3*pPosOld,			//�O��̍���
	D3DXVECTOR3*pMove,				//�ړ���
	float fWidth,					//��
	float fHeight)					//����
{


	bool bIsLanding = false;		//���n���Ă��邩�ǂ���

	for (int nCntblockB = 0; nCntblockB < MAX_BLOCKB; nCntblockB++)
	{
		if (g_aBlockB[nCntblockB].bUse == true)//�g�p���Ă���ꍇ
		{
			//��̓����蔻��
			if (g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 > pPos->x - fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 >= pPosOld->y &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 < pPos->y)

				//�u���b�N�ɂ߂荞��
			{
				
				bIsLanding = true;
				pPos->y = g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2;
				pMove->y = 0.0f;
				HitPlayer(10);
			}
			//���̓����蔻��
			else if (g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 > pPos->x - fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 <= pPosOld->y - fHeight &&
				g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 > pPos->y - fHeight)
			{
				pPos->y = g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 + fHeight;
				pMove->y = 0.0f;

				HitPlayer(10);
			}
			//�E�̓����蔻��
			else if (g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 > pPos->y - fHeight &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 < pPos->y + fHeight &&
				g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 <= pPosOld->x - fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 > pPos->x - fWidth / 2)

				//�u���b�N�ɂ߂荞��
			{
				pPos->x = g_aBlockB[nCntblockB].pos.x + g_aBlockB[nCntblockB].fWidth / 2 + fWidth / 2;
				pMove->x = 0.0f;
				
				HitPlayer(10);
			}
			//���̓����蔻��
			else if (g_aBlockB[nCntblockB].pos.y + g_aBlockB[nCntblockB].fHeight / 2 > pPos->y - fHeight / 2 &&
				g_aBlockB[nCntblockB].pos.y - g_aBlockB[nCntblockB].fHeight / 2 < pPos->y + fHeight / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 >= pPosOld->x + fWidth / 2 &&
				g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 < pPos->x + fWidth / 2)

				//�u���b�N�ɂ߂荞��
			{

				pPos->x = g_aBlockB[nCntblockB].pos.x - g_aBlockB[nCntblockB].fWidth / 2 - fWidth / 2;
				pMove->x = 0.0f;
				HitPlayer(10);
			}
		}

	}
	return bIsLanding;
}