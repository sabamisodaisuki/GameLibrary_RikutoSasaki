#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"block.h"
#include"Enemy.h"
//�}�N����`
#define MAX_BLOCK			(128)		//�u���b�N�̍ő吔
#define BLOCK_SIZE_X			(100.0f)		//�u���b�N�T�C�Y
#define BLOCK_SIZE_Y			(100.0f)		//�u���b�N�T�C�Y


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureBlock = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtexBuffBlock = NULL;
block g_aBlock[MAX_BLOCK];


//�u���b�N�̏���������
void lnitblock(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblock;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();



	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ki.png",					
		&g_pTextureBlock);

	//�u���b�N�̏��̏�����
	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		g_aBlock[nCntblock].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlock[nCntblock].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlock[nCntblock].bUse = false;

	}
	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_BLOCK,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtexBuffBlock,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^
					
	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtexBuffBlock->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
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

		

		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtexBuffBlock->Unlock();


	//�u���b�N�ʒu
	Setblock(D3DXVECTOR3(15.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f,0.0f),(30.0f),(700.0f));//���[��
					
	Setblock(D3DXVECTOR3(70.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//����1����

	Setblock(D3DXVECTOR3(250.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//�E����
	

	Setblock(D3DXVECTOR3(70.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//����2����

	Setblock(D3DXVECTOR3(70.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//����2����

	Setblock(D3DXVECTOR3(250.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (20.0f));//����2����

	Setblock(D3DXVECTOR3(165.0f, 150.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (80.0f), (100.0f));//���^��

	Setblock(D3DXVECTOR3(250.0f, 150.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (90.0f), (20.0f));//���^�񒆂̉E

	//�^��																					 
	Setblock(D3DXVECTOR3(600.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (600.0f));//�^�񒆕�
	Setblock(D3DXVECTOR3(400.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (230.0f), (80.0f));//����1����
	Setblock(D3DXVECTOR3(500.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (230.0f), (80.0f));//����1����
	Setblock(D3DXVECTOR3(400.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (230.0f), (40.0f));//����1����

	//�E��
	Setblock(D3DXVECTOR3(900.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (700.0f));//���[��

	Setblock(D3DXVECTOR3(670.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(670.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(870.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(750.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(800.0f, 350.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(750.0f, 200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(600.0f, 650.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(800.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (30.0f));//���[��


	Setblock(D3DXVECTOR3(300.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (700.0f));//���[��
																			

	Setblock(D3DXVECTOR3(1050.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(1050.0f, 300.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(1110.0f, 65.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//���[��

	Setblock(D3DXVECTOR3(1110.0f, 450.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (300.0f), (30.0f));//���[��



	Setblock(D3DXVECTOR3(1100.0f, 700.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (400.0f), (30.0f));//���[��
	Setblock(D3DXVECTOR3(1270.0f, 400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (30.0f), (700.0f));//���[��

	





}
//�u���b�I������
void Uninitblock(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureBlock != NULL)
	{
		g_pTextureBlock->Release();
		g_pTextureBlock = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtexBuffBlock != NULL)
	{
		g_pVtexBuffBlock->Release();
		g_pVtexBuffBlock = NULL;
	}

}
//�u���b�N�̍X�V����
void Updateblock(void)
{
	




}
//�u���b�N�̕`�揈��
void Drawblock(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntblock;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtexBuffBlock, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		if (g_aBlock[nCntblock].bUse == true)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBlock);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntblock * 4, 2);
		}
	}
}
//�u���b�N�̐ݒ菈��
void Setblock(D3DXVECTOR3 pos, D3DXVECTOR3 move, float fWidth,float fHeight)
{

	int nCntblock;
	VERTEX_2D*pVtx;
	g_pVtexBuffBlock->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		if (g_aBlock[nCntblock].bUse == false)
		{//�u���b�N���g�p����ĂȂ��ꍇ
			g_aBlock[nCntblock].pos = pos;
			g_aBlock[nCntblock].fWidth=fWidth;//��
			g_aBlock[nCntblock].fHeight=fHeight;//����
			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth/2, g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight/2, 0.0f);

			//�e�N�X�`�����W
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(0.02f*g_aBlock[nCntblock].fWidth, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 0.02f*g_aBlock[nCntblock].fHeight);
			pVtx[3].tex = D3DXVECTOR2(0.02f*g_aBlock[nCntblock].fWidth, 0.02f*g_aBlock[nCntblock].fHeight);

			g_aBlock[nCntblock].bUse = true;	//�g�p���Ă����Ԃɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtexBuffBlock->Unlock();
}

//�u���b�N�̓����蔻��
bool CollisionBlock(D3DXVECTOR3*pPos,//���݂̈ʒu
	D3DXVECTOR3*pPosOld,			//�O��̍���
	D3DXVECTOR3*pMove,				//�ړ���
	float fWidth,					//��
	float fHeight)					//����
{
	

	bool bIsLanding = false;		//���n���Ă��邩�ǂ���

	for (int nCntblock = 0; nCntblock < MAX_BLOCK; nCntblock++)
	{
		if (g_aBlock[nCntblock].bUse == true)//�g�p���Ă���ꍇ
		{
			//��̓����蔻��
			if (g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 > pPos->x - fWidth / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 >= pPosOld->y &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 < pPos->y)

				//�u���b�N�ɂ߂荞��
			{
				bIsLanding = true;
				pPos->y = g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2;
				pMove->y = 0.0f;
				
			}
			//���̓����蔻��
			else if (g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 > pPos->x -fWidth / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 < pPos->x + fWidth / 2 &&
				g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 <= pPosOld->y -fHeight &&
				g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 > pPos->y - fHeight)
			{
				
				pPos->y = g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 + fHeight;
				pMove->y = 0.0f;
				
			}
			//�E�̓����蔻��
			 else if (g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 > pPos->y - fHeight &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 < pPos->y + fHeight &&
				g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 <= pPosOld->x -fWidth / 2 &&
				g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 > pPos->x - fWidth / 2)

				//�u���b�N�ɂ߂荞��
			{
				
				pPos->x = g_aBlock[nCntblock].pos.x + g_aBlock[nCntblock].fWidth / 2 + fWidth / 2;
				pMove->x = 0.0f;
				
			}
			//���̓����蔻��
			else if (g_aBlock[nCntblock].pos.y + g_aBlock[nCntblock].fHeight / 2 > pPos->y - fHeight / 2 &&
				g_aBlock[nCntblock].pos.y - g_aBlock[nCntblock].fHeight / 2 < pPos->y + fHeight / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 >= pPosOld->x + fWidth / 2 &&
				g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 < pPos->x + fWidth / 2)

				//�u���b�N�ɂ߂荞��
			{
				
				pPos->x = g_aBlock[nCntblock].pos.x - g_aBlock[nCntblock].fWidth / 2 - fWidth / 2;
				pMove->x = 0.0f;
				
			}
		}

	}
	return bIsLanding;
}