/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬  �ȥ졼����̽��ϴؿ�                             */
/*                                                                              */
/*[��ǽ����]      �ȥ졼����̤�ɽ�����롣                                      */
/*                                                                              */
/*[���ҷ���]      int trace_output ( T_TRACE k_trace, int i_step)               */
/*                                                                              */
/*[�ѥ�᡼��]                                                                  */
/*      T_TRACE     k_trace     (I)�ȥ졼���ꥹ���ѹ�¤��                       */
/*      int         i_step      (I)���ߥ��ƥå׿�                               */
/*                                                                              */
/*[�����]                                                                      */
/*    TRACE_OK       ���ｪλ                                                   */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.19  ****                                      */
/*                ����    2019.08.22  ****                                      */
/*                        �����ȥ��̿�ᥳ���ɤΥ˥�˥å���ɽ������          */
/*                                                                              */
/********************************************************************************/

#include "trace_output.h"

int trace_output(T_TRACE k_trace, int i_step)
{

	/*�����ȥ�ɽ��Ƚ��*/
	if ( (i_step % NUM_TITLE_DISPLAY) == 0) {
		printf("ADR  OPCD OPR1 OPR2 MNE  G I X EA   PR   GR0  GR1  GR2  GR3  GR4  MR FR\n");
	}

	/*ADR��ɽ��*/
	printf("%04X", k_trace.uh_adr);

	/*OPCD��ɽ��*/
	printf(" %04X", k_trace.uh_opcd);

	/**OPR1��ɽ��**/
	if ( (k_trace.c_trace_flag & NONE_OPR1) == 0) {
		printf(" %04X", k_trace.uh_opr1);
	} else {
		printf("     ");
	}

	/**OPR2��ɽ��**/
	if ( (k_trace.c_trace_flag & NONE_OPR2) == 0) {
		printf(" %04X", k_trace.uh_opr2);
	} else {
		printf("     ");
	}

	/*MNE��ɽ��*/
	printf(" %-4s", k_trace.ac_mne);

	/*G��ɽ��*/
	printf(" %01X", k_trace.uh_g);

	/*I��ɽ��*/
	printf(" %01X", k_trace.uh_i);

	/*X��ɽ��*/
	printf(" %01X", k_trace.uh_x);

	/**EA��ɽ��**/
	if ( (k_trace.c_trace_flag & NONE_OPR_EA) == 0) {
		printf(" %04X", k_trace.uh_ea);
	} else {
		printf("     ");
	}

	/*PR��ɽ��*/
	printf(" %04X", k_trace.uh_pr);

	/*GR0��ɽ��*/
	printf(" %04X", k_trace.auh_gr[0]);

	/*GR1��ɽ��*/
	printf(" %04X", k_trace.auh_gr[1]);

	/*GR2��ɽ��*/
	printf(" %04X", k_trace.auh_gr[2]);

	/*GR3��ɽ��*/
	printf(" %04X", k_trace.auh_gr[3]);

	/*GR4��ɽ��*/
	printf(" %04X", k_trace.auh_gr[4]);

	/*MR��ɽ��*/
	printf(" %02X", k_trace.uh_mr);

	/*FR��ɽ��*/
	printf(" %02X\n", k_trace.uh_fr);

	return TRACE_OK;
}
