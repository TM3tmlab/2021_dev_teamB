/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 ͭ�����ɥ쥹���ϴؿ�                              */
/*                                                                              */
/*[��ǽ����]      ͭ�����ɥ쥹����Ϥ���                                        */
/*                                                                              */
/*[���ҷ���]      int ea_check(T_TRACE *pk_trace,                               */
/*                                  unsigned short *puh_1st_adr)                */
/*                                                                              */
/*[�ѥ�᡼��]    T_TRACE *pk_trace (I/O)                                       */
/*                    �ȥ졼���κݤ��Ѥ���������񤵤줿��¤��                */
/*                    ̿�ᥳ����/���ڥ��ɥ�����1/���ڥ��ɥ�����2/           */
/*                    ���ѥ쥸�����ֹ桢�ޤ���R1/���ܥ��ɥ쥹����/              */
/*                    ����ǥå����쥸�����ֹ桢���ϴ��ܥ쥸�����ֹ桢����R2/   */
/*                    ͭ�����ɥ쥹/�ȥ졼���ꥹ�ȥե饰����Ϥ���               */
/*                unsigned short *puh_1st_adr (I)                               */
/*                    ���ۥ������Ƭ���ɥ쥹                                  */
/*                                                                              */
/*[�����]        EA_OK    ���ｪλ                                             */
/*                EA_EG    �۾ｪλ                                             */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.09  **********                                */
/*                ����    2019.08.21  **********                                */
/*                        ����ǥå������ɥ쥹����ν���                        */
/*                ����    2019.08.22  **********                                */
/*                        ���ե�̿��ν���                                      */
/*                        ̤����̿��ζ���ɽ�����ѹ�                            */
/*                        �쥸�������۾�ʿ��ͤ��ä����ε�ư����            */
/*                                                                              */
/*                                                                              */
/********************************************************************************/

#include "ea_check.h"

int ea_check(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
    int i_reg_flag = 0;   //�쥸�������ͤ��������ʤ�0���������ʤ��ʤ�1

	/***** ���顼�����å� *****/
	/*OPcode�γ�ǧ�ڤӥ����å�*/
	pk_trace->uh_opcd = *(puh_1st_adr + pk_trace->uh_pr);
	switch(pk_trace->uh_opcd >> BIT_SHIFT_15_8) {
	case OPCD_LD1:
    	/* FALL THROUGH */
	case OPCD_LD2:
    	/* FALL THROUGH */
	case OPCD_ST:
    	/* FALL THROUGH */
	case OPCD_ADDA:
	    /* FALL THROUGH */
	case OPCD_SLL:
	    /* FALL THROUGH */
	case OPCD_EXIT:
		/* DO NOTHING */
		break;
	default:
        pk_trace->c_trace_flag = BLANK_ALL;
        pk_trace->uh_g = 0;
        pk_trace->uh_i = 0;
        pk_trace->uh_x = 0;
		return EA_NG;
	}

	/*���ѥ쥸�����ֹ�������ڤӥ����å�*/
	pk_trace->uh_g = (*(puh_1st_adr + pk_trace->uh_pr) & BIT_MASK_7_4) >> BIT_SHIFT_7_4;
	if(pk_trace->uh_g >= GR_NUM) {
        i_reg_flag = 1;
		pk_trace->uh_ea = 0;
	}

	/*����ǥå����쥸�����ֹ�������ڤӥ����å�*/
	pk_trace->uh_x = (*(puh_1st_adr + pk_trace->uh_pr) & BIT_MASK_2_0);
	if(pk_trace->uh_x >= GR_NUM) {
        i_reg_flag = 1;
		pk_trace->uh_ea = 0;
	}

	/***** ͭ�����ɥ쥹���� *****/
	switch(pk_trace->uh_opcd >> BIT_SHIFT_15_8) {
	case OPCD_LD1:                  /*1��̿��*/
					/* FALL THROUGH */
	case OPCD_EXIT:                 /*1��̿��*/
		pk_trace->uh_ea = 0;
		pk_trace->uh_opr1 = 0;
		pk_trace->uh_opr2 = 0;
		pk_trace->uh_i = 0;
		pk_trace->c_trace_flag = BLANK_ALL;
        /*i,x����������*/
        if(i_reg_flag == 1) {
            return EA_NG;
        }
		break;
	default:                        /*����ʳ�*/
		pk_trace->c_trace_flag = BLANK_OPR2;
		pk_trace->uh_opr1 = *(puh_1st_adr + pk_trace->uh_pr + 1);
		pk_trace->uh_opr2 = 0;

        /*i,x����������*/
        if(i_reg_flag == 1) {
            return EA_NG;
        }

		switch(adrmode_check(pk_trace, puh_1st_adr)) {
		case DIR_AM:                /*ľ�ܥ��ɥ쥹����or¨�ͥ��ɥ쥹����*/
			if((pk_trace->uh_opcd >> BIT_SHIFT_15_8) == OPCD_SLL) {	/*¨�ͥ��ɥ쥹����*/
				pk_trace->uh_ea = *(puh_1st_adr + pk_trace->uh_pr + 1);
			} else {												/*ľ�ܥ��ɥ쥹����*/
				pk_trace->uh_ea = *(puh_1st_adr + pk_trace->uh_pr + 1);
			}
				break;
		case IND_AM:                /*����ǥå������ɥ쥹����*/
			pk_trace->uh_ea = pk_trace->auh_gr[pk_trace->uh_x] + *(puh_1st_adr + pk_trace->uh_pr + 1);
			break;
		case IDR_AM:                /*���ܥ��ɥ쥹����*/
			pk_trace->uh_ea = pk_trace->auh_gr[pk_trace->uh_x];
			break;
		default:
			/* DO NOTHING */
			break;
		}
		break;
	}
	
	/*���ե�̿��ʤ�ͭ�����ɥ쥹�������Ķ���Ƥ⥨�顼�ǤϤʤ�*/
	if((pk_trace->uh_opcd >> BIT_SHIFT_15_8) == OPCD_SLL) {
		return EA_OK;
	}
	
	/*ͭ�����ɥ쥹���ϤΥ����å�*/
	if(pk_trace->uh_ea > VM_MAX_SIZE) {
		return EA_NG;
	}

	return EA_OK;
}
