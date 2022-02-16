#include "main.h"
#include "player.h"
#include "input.h"
#include"bullet.h"
#include"Enemy.h"
#include"title.h"
#include"game.h"
#include"bg.h"
#include"sound.h"
#include"fade.h"
#include"titleb.h"

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureTitleb = NULL;//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitleb = NULL;//���_�o�b�t�@�ւ̂ۂ����


											   //�^�C�g����ʂ̏���������
void lnitTitleb(void)
{
	LPDIRECT3DDEVICE9 pDevice;


	//�T�E���h�̍Đ�
	PlaySound(SOUND_LABEL_BGMTITLE);



	//�f�o�C�X�̎擾
	pDevice = GetDevice();


	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/DA.png",//TITOL.png"
		&g_pTextureTitleb);



	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitleb,
		NULL);


	VERTEX_2D*pVtx;		//���_���փ|�C���^

						//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffTitleb->Lock(0, 0, (void**)&pVtx, 0);

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
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffTitleb->Unlock();
}

//�^�C�g����ʂ̏I������
void UninitTitleb(void)
{
	//�T�E���h�̒�~
	StopSound();


	//�e�N�X�`���̔j��
	if (g_pTextureTitleb != NULL)
	{
		g_pTextureTitleb->Release();
		g_pTextureTitleb = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTitleb != NULL)
	{
		g_pVtxBuffTitleb->Release();
		g_pVtxBuffTitleb = NULL;
	}
}

//�^�C�g����ʂ̍X�V����
void UpdateTitleb(void)
{
	// �t�F�[�h���̎擾
	FADE fade = GetFade();

	//����L�[(ENTER�L�[�������ꂽ���ǂ���)
	if (GetKeyboardTrigger(DIK_RETURN) == true && fade == FADE_NONE)
	{
		//�T�E���h�̍Đ�
		PlaySound(SOUND_LABEL_SE_ketei);

		//���[�h�ݒ�
		SetFade(MODE_TITLE);
	}

}

//�^�C�g����ʂ̕`�揈��
void DrawTitleb(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffTitleb, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureTitleb);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

