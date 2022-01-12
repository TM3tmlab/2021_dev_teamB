/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 �����ȥ⡼�ɴؿ��ѥإå����ե�����                */
/*                                                                              */
/*[��ǽ����]      �����ȥ⡼�ɴؿ��ѤΥإå����ե�����                          */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2019.08.19  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef AUTO_RUN_H
#define AUTO_RUN_H

/***** ���󥯥롼����� *****/
#include <string.h>
#include "comet_define.h"
#include "comet_table.h"
#include "ea_check.h"
#include "cmd_ld1.h"
#include "cmd_ld2.h"
#include "cmd_st.h"
#include "cmd_adda.h"
#include "cmd_sll.h"
#include "cmd_exit.h"
#include "trace_output.h"

/***** �ץ�ȥ�������� *****/
/*�����ȥ⡼�ɴؿ�*/
int auto_run(T_OPT k_opt_ar, T_OBJ k_obj_ar, unsigned short *puh_1st_adr);

#endif      /*AUTO_RUN_H*/
