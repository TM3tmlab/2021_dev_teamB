/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 SLL�ؿ�                                           */
/*                                                                              */
/*[��ǽ����]      ̿���SLL��¹Ԥ���                                           */
/*                                                                              */
/*[���ҷ���]      int cmd_sll( T_TRACE *pk_trace, unsigned short *puh_1st_adr ) */
/*                                                                              */
/*[�ѥ�᡼��]    T_TRACE  *pk_trace            (I/O)�ȥ졼���ꥹ���ѹ�¤��     */
/*                unsigned short  *puh_1st_adr  ���ۥ������Ƭ���ɥ쥹        */
/*                                              (���Ѥ��ʤ�)                    */
/*                                                                              */
/*[�����]        CMD_OK         ���ｪλ                                       */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.19  **********                                */
/*                                                                              */
/********************************************************************************/
#include "cmd_sll.h"

int cmd_sll(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
    (void)puh_1st_adr;              /*SLL�ؿ��Ǥ���Ƭ���ɥ쥹����Ѥ��ʤ�*/

	/***** �ѿ���� *****/
	unsigned short uh_over_flag;    /*�����С��ե�Ƚ����*/

	/***** �׻����� *****/
	pk_trace->auh_gr[pk_trace->uh_g] <<= (pk_trace->uh_ea - 1);
	uh_over_flag = pk_trace->auh_gr[pk_trace->uh_g] & BIT_MASK_15;
	pk_trace->auh_gr[pk_trace->uh_g] <<= 1;

	/***** �ե饰�쥸�������� *****/
	/*�����*/
	pk_trace->uh_fr = 0x0000;
	/*����ե饰Ƚ��*/
	if(pk_trace->auh_gr[pk_trace->uh_g] == 0) {
		pk_trace->uh_fr |= FR_ZERO_FRAG;
	}
	/*������ե饰Ƚ��*/
	if((short)(pk_trace->auh_gr[pk_trace->uh_g]) < 0) {
		pk_trace->uh_fr |= FR_SIGN_FRAG;
	}
	/*�����С��ե��ե饰Ƚ��*/
	if(uh_over_flag != 0) {
        pk_trace->uh_fr |= FR_OVER_FRAG;
    }

    /***** �ץ����쥸�������� *****/
    pk_trace->uh_pr += 2;

    /*���ｪλ*/
    return CMD_OK;
}
