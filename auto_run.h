/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 オートモード関数用ヘッダーファイル                */
/*                                                                              */
/*[機能概要]      オートモード関数用のヘッダーファイル                          */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.19  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef AUTO_RUN_H
#define AUTO_RUN_H

/***** インクルード宣言 *****/
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

/***** プロトタイプ宣言 *****/
/*オートモード関数*/
int auto_run(T_OPT k_opt_ar, T_OBJ k_obj_ar, unsigned short *puh_1st_adr);

#endif      /*AUTO_RUN_H*/
