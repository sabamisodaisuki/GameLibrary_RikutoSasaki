#ifndef _PLAYER_H_
#define _PLAYER_H_

//�v���C���[�̏��
typedef enum
{
	PLAYERSTATE_APPEAR=0,	//�o����ԁi�_�Łj
	PLAYERSTATE_NORMAL,		//�ʏ���
	PLAYERSTATE_DAMAGE,		//�_���[�W���
	PLAYERSTATE_DEATH,		//���S���
	PLAYERSTATE_MAX
}PLAYERSTATE;


//�v���C���[�̍\���̂̒�`
typedef struct
{
	D3DXVECTOR3 g_posPlayer;				//�ʒu					
	D3DXVECTOR3 g_movePlayer;				//�ړ���
	D3DXVECTOR3 g_scalePlayer;																	
	D3DXVECTOR3 g_rotPlayer;
	D3DXVECTOR3 g_posOldPlayer;				//�O��̈ʒu
	PLAYERSTATE state;						//�v���C���[�̏��
	int nCounterState;						//��ԊǗ��J�E���^�[
	int nLife;								//�̗�
	int nCounterAnim;						//�J�E���^�[
	int nPatternAnim;						//�p�^�[���ԍ�
	int nDirectionMove;						//����
	float fWidth;									//��
	float fHeight;									//����
	bool bDisp;								//�\�����邩���Ȃ���
	bool bIsJumping;						//�W�����v��
	bool bUse;

}Player;

//�}�N����`
#define PLAYER_SIZE_X		(40.0f)
#define PLAYER_SIZE_Y		(40.0f)



//�v���g�^�C�v�錾
Player *GetPlayer(void);
void lnitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void HitPlayer(int nDamage);




#endif 

