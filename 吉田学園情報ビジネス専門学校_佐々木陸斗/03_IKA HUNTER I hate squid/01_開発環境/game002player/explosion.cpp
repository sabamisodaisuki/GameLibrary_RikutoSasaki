#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"explosion.h"
#include "Enemy.h"


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureExplosion = NULL;			//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffExplosion = NULL;		//���_�o�b�t�@�ւ̃|�C���^
Explosion g_aExplosion[MAX_EXPLOSION];					//���j�̏��


//�e�̏���������
void lnitExplosion(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntExplosion;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();


	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ex.png",					//akira000.png,koda.jpg,su.jpg,runningman100.png,bullet000.png,�l�Q.png,���l�Q.png,�؂���.jpg
		&g_pTextureExplosion);


	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_EXPLOSION,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffExplosion,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^
	

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
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
		pVtx[0].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 0.0f);
		pVtx[1].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 0.0f);
		pVtx[2].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 1.0f);
		pVtx[3].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 1.0f);


		pVtx += 4;
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffExplosion->Unlock();
}
//�|���S���̏I������
void UninitExplosion(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureExplosion != NULL)
	{
		g_pTextureExplosion->Release();
		g_pTextureExplosion = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffExplosion != NULL)
	{
		g_pVtxBuffExplosion->Release();
		g_pVtxBuffExplosion = NULL;
	}

}
//�e�̍X�V����
void UpdateExplosion(void)
{
	int nCntExplosion;
	VERTEX_2D*pVtx;

	
	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if(g_aExplosion[nCntExplosion].bUse==true)
		{//�������g�p�����
			//�p�^�[���X�V
			g_aExplosion[nCntExplosion].nCounterAnim++; //�J�E���^�[���Z

			if ((g_aExplosion[nCntExplosion].nCounterAnim % 5 ) == 0)
			{
			
					g_aExplosion[nCntExplosion].nPatternAnim++; //�J�E���^�[���Z

					if (g_aExplosion[nCntExplosion].nPatternAnim >= 8)//���p�^�[���𒴂���
					{
						g_aExplosion[nCntExplosion].bUse = false;//�g�p���ĂȂ����
					}
					//�e�N�X�`�����W
					pVtx[0].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 0.0f);
					pVtx[1].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 0.0f);
					pVtx[2].tex = D3DXVECTOR2((0.0f + 0.125f*g_aExplosion[nCntExplosion].nPatternAnim), 1.0f);
					pVtx[3].tex = D3DXVECTOR2((0.125f + 0.125f*(g_aExplosion[nCntExplosion].nPatternAnim)), 1.0f);
			}

		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffExplosion->Unlock();
}
//���j�̕`�揈��
void DrawExplosion(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntExplosion;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffExplosion, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureExplosion);


	//�|���S���̕`��
	for ( nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if (g_aExplosion[nCntExplosion].bUse == true)
		{
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntExplosion * 4, 2);
		}
	}
}
//�e�̐ݒ菈��
void SetExplosion(D3DXVECTOR3 pos)
{
	int nCntExplosion;
	VERTEX_2D*pVtx;
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for ( nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if (g_aExplosion[nCntExplosion].bUse == false)
		{//�e���g�p����ĂȂ��ꍇ
			g_aExplosion[nCntExplosion].pos = pos;

			//���_���W�̍X�V
			pVtx[0].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x - MAX_SIZE, g_aExplosion[nCntExplosion].pos.y - MAX_SIZE, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x + MAX_SIZE, g_aExplosion[nCntExplosion].pos.y - MAX_SIZE, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x - MAX_SIZE, g_aExplosion[nCntExplosion].pos.y + MAX_SIZE, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aExplosion[nCntExplosion].pos.x + MAX_SIZE, g_aExplosion[nCntExplosion].pos.y + MAX_SIZE, 0.0f);

			//�g�p���Ă����Ԃɂ���
			g_aExplosion[nCntExplosion].bUse = true;

			g_aExplosion[nCntExplosion].nCounterAnim = 0; //�A�j�����[���ɂ���

			g_aExplosion[nCntExplosion].nPatternAnim = 0;//�p�^�[�����[���ɂ���

			break;		//(for���𔲂���)
		}
		pVtx += 4;//�|�C���^���S���i�߂�
	}
	g_pVtxBuffExplosion->Unlock();
}

