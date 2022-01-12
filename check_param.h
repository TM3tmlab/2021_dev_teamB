/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 �ѥ�᡼�������å��ؿ��ޥ���                      */
/*                                                                              */
/*[��ǽ����]      �ѥ�᡼�������å��إå��ؿ��ե�����                          */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.09  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef CHECK_PARAM_H
#define CHECK_PARAM_H

/***** ���󥯥롼����� *****/
#include<stdlib.h>
#include<string.h>
#include"comet_define.h"
#include"comet_table.h"

/***** �ޥ������ *****/
#define PRM_NUM_MIN (1)         /*PARAMETER�κǾ��Ŀ�*/
#define OPT_R "-r"              /*���ץ����-r*/
#define OPT_S "-s"              /*���ץ����-s*/
#define OPT_M "-m"              /*���ץ����-m*/
#define OPT_R_FLAG_UP (1)       /*���ץ����-r��¸�ߤ����Ȥ��Υե饰��Ω�Ƥ�*/
#define OPT_M_FLAG_UP (1)       /*���ץ����-m��¸�ߤ����Ȥ��Υե饰��Ω�Ƥ�*/
#define OPT_STEP_FLAG_UP (1)    /*���ץ����-s�Υ��ץ��������Ǥ��뤳�Ȥ򼨤��ե饰��Ω�Ƥ�*/
#define OPT_STEP_FLAG_DOWN (0)  /*���ץ����-s�Υ��ץ��������Ǥ��뤳�Ȥ򼨤��ե饰��̵���ˤ���*/
#define MAX_STEP (2147483648)   /*���ƥå׿��κ���*/
#define MIN_STEP (0)            /*���ƥå׿��κǾ�*/
#define FILE_FLAG_DOWN (0)      /*���ޥ�ɥ饤������˥ե����뤬¸�ߤ��ʤ��ä�*/
#define FILE_FLAG_UP (1)        /*�ե����뤬¸�ߤ����Ȥ��Υե饰��Ω�Ƥ�*/
#define DECIMAL_NUM (10)        /*�����ʿ�*/
#define TOP_POS (1)             /*��������Ƭ�ΰ���*/
#define MATCH (0)               /*����*/

/***** �ץ�ȥ�������� *****/
int check_param(int, char*[], T_OPT*, unsigned short*);

#endif      /*CHECK_PARAM_H*/
