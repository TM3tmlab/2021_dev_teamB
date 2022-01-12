/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 �����ȥ⡼�ɴؿ�                                  */
/*                                                                              */
/*[��ǽ����]      �����ȥ⡼�ɻ��ν����δ�����Ԥ�                              */
/*                                                                              */
/*[���ҷ���]      int auto_run(T_OPT k_opt_ar, T_OBJ k_obj_ar,                  */
/*                             unsigned short *puh_1st_adr)                     */
/*                                                                              */
/*[�ѥ�᡼��]    T_OPT k_opt_ar (I)���ץ��������Ƥ����񤵤줿��¤��          */
/*                T_OBJ k_obj_ar (I)���֥������ȥե�����ξ������񤵤줿��¤��*/
/*                unsigned short *puh_1st_adr (I)���ۥ������Ƭ���ɥ쥹       */
/*                                                                              */
/*[�����]       TRACE_END       ���ｪλ                                       */
/*               TRACE_END_HC    �۾ｪλ(����̤����/̤���̿��)              */
/*               TRACE_END_SO    �۾ｪλ(���ƥå׿��۾�)                       */
/*               TRACE_END_NE    �۾ｪλ(EXIT�ʤ�)                             */
/*                                                                              */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.19  **********                                */
/*                ����    2019.08.22  **********                                */
/*                        ADR����������ʤ��Х�����                           */
/*                        �۾ｪλ���Υȥ졼����̤���Ϥ���褦���ѹ�          */
/*                                                                              */
/********************************************************************************/ 

#include "auto_run.h"

int auto_run(T_OPT k_opt_ar, T_OBJ k_obj_ar, unsigned short *puh_1st_adr)
{
    /***** �ѿ���� *****/
    /*�ȥ졼���ꥹ���ѹ�¤�Ρ������*/
    T_TRACE k_trace_ar = {  0, 
                            0, 
                            0, 
                            0, 
                            "", 
                            0, 
                            0, 
                            0, 
                            0,
                            k_obj_ar.uh_init_pr,
                            {0, 0, 0, 0, VM_MAX_SIZE}, 
                            0, 
                            0,
                            0
                        };
    /*̿������ѹ�¤�Ρ������*/
    T_CMD k_cmd_ar[CMD_NUM] =    {   {OPCD_LD1, "LD", cmd_ld1},
                                    {OPCD_LD2, "LD", cmd_ld2},
                                    {OPCD_ST, "ST", cmd_st},
                                    {OPCD_ADDA, "ADDA", cmd_adda},
                                    {OPCD_SLL, "SLL", cmd_sll},
                                    {OPCD_EXIT, "EXIT", cmd_exit}
                                };
    int i;      //�롼�ץ���������ѿ�1
    int i2;     //�롼�ץ���������ѿ�2
    int i_return_ea_check;  //ͭ�����ɥ쥹���ϴؿ�������
    int (*pi_do_func)();    //�¹Դؿ��ݥ���

    /*�������ȥ졼���롼�ס����祹�ƥå׿���Ķ����ޤ�*/
    for(i = 0; i < k_opt_ar.i_step; i++) {

    	k_trace_ar.uh_adr = k_trace_ar.uh_pr;
    	i_return_ea_check = ea_check(&k_trace_ar, puh_1st_adr);

        /*�ؿ��ݥ��󥿤�̿��ؿ��ƤӽФ������˥å�����*/
        for(i2 = 0; i2 < CMD_NUM; i2++) {
            if(k_cmd_ar[i2].uh_opcd == (k_trace_ar.uh_opcd >> BIT_SHIFT_15_8)) {
                strcpy(k_trace_ar.ac_mne, k_cmd_ar[i2].ac_mne);
                pi_do_func = k_cmd_ar[i2].pi_func_cmd;
                break;
            }
            strcpy(k_trace_ar.ac_mne, "    ");
        }


        /*PR�����֥������ȥ�����Ÿ�����Ƥ��ʤ�����ؤ��Ƥ��ʤ���*/    
        if(k_trace_ar.uh_pr < k_obj_ar.uh_obj_open || k_trace_ar.uh_pr > (k_obj_ar.uh_obj_open + (unsigned short)(k_obj_ar.i_code_size / (int)sizeof(unsigned short)) - 1)) {
            if(k_opt_ar.h_opt_r == 0) {
                trace_output(k_trace_ar, i);
            }
            return TRACE_END_NE;
        }
   
        /*ͭ�����ɥ쥹���ϴؿ����顼�����å�*/ 
        if(i_return_ea_check == EA_NG) {
            if(k_opt_ar.h_opt_r == 0) {
                trace_output(k_trace_ar, i);
            }
            return TRACE_END_HC;
        }

        (void)(*pi_do_func)(&k_trace_ar, puh_1st_adr);

        /*-r���ץ���󤬤ʤ���Хȥ졼����̽��ϴؿ��ƤӽФ�*/
        if(k_opt_ar.h_opt_r == 0) {
            trace_output(k_trace_ar, i);
        }

        /*EXIT���ä������ｪλ*/
        if(strcmp(k_trace_ar.ac_mne, "EXIT") == 0) {
            return TRACE_END;
        }
    }

    return TRACE_END_SO;           

}
