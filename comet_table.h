/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 COMET���̹�¤�Υơ��֥�                           */
/*                                                                              */
/*[��ǽ����]      COMET�ץ���ඦ�̹�¤�Υإå��ե�����                       */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.08  **********                                */
/*                                                                              */
/********************************************************************************/ 
#ifndef COMET_TABLE_H
#define COMET_TABLE_H

#include "comet_define.h"

/*���ץ�����ѥơ��֥�*/
typedef struct{
    short h_opt_r;  /*-r��̵ͭ*/
    short h_opt_m;  /*-m��̵ͭ*/
    int i_step;     /*���ƥå׿�*/
}T_OPT;

/*���֥��������ѥơ��֥�*/
typedef struct{
    unsigned short uh_obj_open;     /*���֥�������Ÿ���襢�ɥ쥹*/
    unsigned short uh_init_pr;      /*�¹Գ��ϥ��ɥ쥹(PR�����)*/
    int i_code_size;                /*���֥������ȥ����ɥ�����*/
}T_OBJ;


/*�ȥ졼���ꥹ���ѥơ��֥�*/
typedef struct{
    unsigned short uh_adr;          /*̿�ᥢ�ɥ쥹*/
    unsigned short uh_opcd;         /*̿�ᥳ����*/
    unsigned short uh_opr1;         /*���ڥ��ɥ�����1*/
    unsigned short uh_opr2;         /*���ڥ��ɥ�����2*/
    char ac_mne[MNE_LEN];           /*̿�ᥳ���ɤΥ˥�˥å�*/
    unsigned short uh_g;            /*���ѥ쥸�����ֹ�����R1*/
    unsigned short uh_i;            /*���ܥ��ɥ쥹����*/
    unsigned short uh_x;            /*����ǥå����쥸�����ֹ桢���ϴ��ܥ쥸�����ֹ桢����R2*/
    unsigned short uh_ea;           /*ͭ�����ɥ쥹*/
    unsigned short uh_pr;           /*�ץ����쥸����*/
    unsigned short auh_gr[GR_NUM];  /*���ѥ쥸����������*/
    unsigned short uh_mr;           /*�ޥ����쥸����������*/
    unsigned short uh_fr;           /*�ե饰�쥸����������*/
    char c_trace_flag;              /*�ȥ졼���ꥹ��ɽ������Ƚ���ѥե饰*/
}T_TRACE;

/*̿������ѥơ��֥�*/
typedef struct{
    unsigned short uh_opcd;     /*���ڥ졼����󥳡���*/
    char ac_mne[MNE_LEN];       /*�˥�˥å�*/
    int (*pi_func_cmd)();       /*��̿��¹Դؿ��ݥ���*/
}T_CMD;

#endif
