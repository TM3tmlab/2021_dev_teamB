/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 LD2��̿��ؿ�                                     */
/*                                                                              */
/*[��ǽ����]      ̿���LD2��¹Ԥ���                                           */
/*                                                                              */
/*[���ҷ���]      int cmd_ld2( T_TRACE *pk_trace, unsigned short *puh_1st_adr ) */
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
#include "cmd_ld2.h"

int cmd_ld2(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
	/***** ���ɽ��� *****/
	pk_trace->auh_gr[pk_trace->uh_g] = *(puh_1st_adr + pk_trace->uh_ea);

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

	/***** �ץ����쥸�������� *****/
	pk_trace->uh_pr += 2;

	/*���ｪλ*/
	return CMD_OK;
}
