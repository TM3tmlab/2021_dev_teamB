/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 ADDA�ؿ�                                          */
/*                                                                              */
/*[��ǽ����]      ̿���ADDA��¹Ԥ���                                          */
/*                                                                              */
/*[���ҷ���]      int cmd_adda( T_TRACE *pk_trace, unsigned short *puh_1st_adr )*/
/*                                                                              */
/*[�ѥ�᡼��]    T_TRACE  *pk_trace            (I/O)�ȥ졼���ꥹ���ѹ�¤��     */
/*                unsigned short  *puh_1st_adr  (I)���ۥ������Ƭ���ɥ쥹     */
/*                                                                              */
/*[�����]        CMD_OK         ���ｪλ                                       */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.09  **********                                */
/*                                                                              */
/********************************************************************************/
#include "cmd_adda.h"

int cmd_adda(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
	/***** �ѿ���� *****/
	int i_sum; /*�����С��ե�Ƚ���Ѥ˷׻���̤�����¸����*/

	/***** �׻����� *****/
	i_sum = (int)((short)*(puh_1st_adr + pk_trace->uh_ea) + (short)pk_trace->auh_gr[pk_trace->uh_g]);
	pk_trace->auh_gr[pk_trace->uh_g] = (unsigned short)i_sum;

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
	if((short)(i_sum < SHORT_MIN || i_sum > SHORT_MAX)) {
		pk_trace->uh_fr |= FR_OVER_FRAG;
	}

	/***** �ץ����쥸�������� *****/
	pk_trace->uh_pr += 2;

	/*���ｪλ*/
	return CMD_OK;
}
