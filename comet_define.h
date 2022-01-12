/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 COMET����#define�ޥ���                            */
/*                                                                              */
/*[��ǽ����]      COMET�ץ���ඦ��#define�إå��ե�����                      */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.08  **********                                */
/*                ����    2019.08.09  **********                                */
/*                        ̿�����ϥӥå�����ѡ��ե饰�쥸�����ӥå�������ɲ�*/
/*                        ����ɽ���ӥå�������ɲ�                              */
/*                        OPcode�������ɲ�                                      */
/*                        main�⥨�顼�������ɲ�                                */
/*                        �����С��ե����ɲ�                                  */
/*                        object_open�����SHORT_FILE����FILE_SIZE_ERROR�˹���  */
/*                ����    2019.08.21  **********                                */
/*                        ���ե�̿�ᥪ���С��ե�Ƚ�����ɲ�                    */
/*                                                                              */
/********************************************************************************/
#ifndef COMET_DEFINE_H
#define COMET_DEFINE_H

/***** ������� *****/
#define VM_MAX_SIZE (0x7FFF)    /*���ۥ�����祵����*/
#define GR_NUM (5)              /*���ѥ쥸�����Ŀ�*/
#define MNE_LEN (5)             /*�˥�˥å�ʸ����*/
#define CMD_NUM (6)             /*̿���Ŀ�*/

/*̿�����ϥӥå������*/
#define BIT_MASK_15_8 (0xFF00)  /*OPcode�������*/
#define BIT_SHIFT_15_8 (8)      /*OPcode�����եȷ׻���*/
#define BIT_MASK_7_4 (0x00F0)   /*R��R1�������*/
#define BIT_SHIFT_7_4 (4)       /*R��R1�����եȷ׻���*/
#define BIT_MASK_3 (0x0008)     /*I�������*/
#define BIT_SHIFT_3 (3)         /*I�����եȷ׻���*/
#define BIT_MASK_2_0 (0x0007)   /*XR��IR��R2�������*/

/*���ե�̿�ᥪ���С��ե�Ƚ����*/
#define BIT_MASK_15 (0x8000)	/*SLL̿����*/

/*�ե饰�쥸�����ӥå������*/
#define FR_ZERO_FRAG (0x0001)   /*����ե饰*/
#define FR_SIGN_FRAG (0x0002)   /*������ե饰*/
#define FR_OVER_FRAG (0x0004)   /*�����С��ե��ե饰*/

/*�ե饰�쥸���������С��ե��ϰ���*/
#define SHORT_MIN (-32768)
#define SHORT_MAX (32767)
#define U_SHORT_MIN (0)
#define U_SHORT_MAX (65535)

/*����ɽ���ӥå������*/
#define BLANK_ALL (0x07)    /*OPR1,OPR2,EA���ƶ���ɽ��*/
#define BLANK_OPR2 (0x02)   /*OPR2�Τ߶���ɽ��*/

/*OPcode������*/
#define OPCD_LD1 (0x14)     /*LD(1��)��OPcode*/
#define OPCD_LD2 (0x10)     /*LD(2��)��OPcode*/
#define OPCD_ST (0x11)      /*ST��OPcode*/
#define OPCD_ADDA (0x20)    /*ADDA��OPcode*/
#define OPCD_SLL (0x52)     /*SLL��OPcode*/
#define OPCD_EXIT (0xA0)    /*EXIT��OPcode*/


/***** ������ *****/
/*main*/
#define OK (0)      /*����*/
#define NG (1)      /*�۾�*/
/*main�⥨�顼������*/
#define NOT_MANUAL (3)      /*�ޥ˥奢��⡼��̤����*/
#define MEMORY_ERROR (11)   /*������ݥ��顼*/

/*check_param*/
#define PRM_OK (0)      /*����*/
#define PRM_NG_PE (1)   /*�۾�ѥ�᡼�����顼*/
#define PRM_NG_FE (2)   /*�۾�ե����륨�顼*/

/*object_open*/
#define OPEN_OK (0)             /*����*/
#define NO_FILE (21)            /*�۾�ե�����ʤ�*/
#define FILE_SIZE_ERROR (22)    /*�۾�ե����륵����������������*/
#define LARGE_FILE (23)         /*�۾�����ɥ��������礭������*/

/*auto_run*/
#define TRACE_END (0)       /*����*/
#define TRACE_END_HC (31)   /*�۾����̤����/̤���̿��*/
#define TRACE_END_SO (32)   /*�۾���ƥå׿������С�*/
#define TRACE_END_NE (33)   /*�۾EXIT�ʤ�*/

/*ea_check*/
#define EA_OK (0)   /*����*/
#define EA_NG (1)   /*�۾����̤����/̤���̿��*/

/*adrmode_check*/
#define DIR_AM (0)  /*���ľ�ܥ��ɥ쥹����*/
#define IND_AM (1)  /*�������ǥå������ɥ쥹����*/
#define IDR_AM (2)  /*������ܥ��ɥ쥹����*/

/*cmd*/
#define CMD_OK (0)  /*����*/

/*trace_output*/
#define TRACE_OK (0)    /*����*/

/*end_output*/
#define END_OK (0)  /*����*/
#define END_NG (1)  /*�۾�*/

#endif  /*COMET_DEFINE_H*/
