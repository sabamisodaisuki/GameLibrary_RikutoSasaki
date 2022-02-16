#include "main.h"
#include "player.h"
#include "input.h"
#include"bg.h"


////�}�N����`
//#define NUM_BG	(2)		//�w�i�̐�

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_apTextureBG = NULL;/*[NUM_BG] = {};*/	//�e�N�X�`���O����
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBG = NULL;	//���_�o�b�t�@
//float g_aPosTexV[NUM_BG];						//�e�N�X�`�����W�J�n�ʒu�iV�l�j

//�w�i�̏���������
void lnitBG(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^
	/*int nCntBG;			
*/
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BGG.png",		//	NEW2	haik.png",	
		&g_apTextureBG);

	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice,
	//	"data/TEXTURE/awa2.png",		//	NEW2		
	//	&g_apTextureBG[1]);



	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBG,
		NULL);

	VERTEX_2D*pVtx;		//���_���փ|�C���^

	//for (nCntBG = 0; nCntBG < NUM_BG; nCntBG++)
	//{
		//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
		g_pVtxBuffBG->Lock(0, 0, (void**)&pVtx, 0);

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

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

		//���_�o�b�t�@�A�����b�N
		g_pVtxBuffBG->Unlock();
	}
//}

void UninitBG(void)
{
	/*int nCntBG;


	for (nCntBG = 0; nCntBG < NUM_BG; nCntBG++)*/
	{ //�e�N�X�`���̔j��
		if (g_apTextureBG != NULL)
		{
			g_apTextureBG->Release();
			g_apTextureBG = NULL;
		}
	}
	
	//�o�b�t�@�̔j��
	if (g_pVtxBuffBG != NULL)
	{
		g_pVtxBuffBG->Release();
		g_pVtxBuffBG = NULL;
	}
}

void UpdateBG(void)
{
	VERTEX_2D*pVtx;		//���_���փ|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffBG->Lock(0, 0, (void**)&pVtx, 0);
	{

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);


	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffBG->Unlock();
}

void DrawBG(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffBG, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	
	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_apTextureBG);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0, 6);
}





