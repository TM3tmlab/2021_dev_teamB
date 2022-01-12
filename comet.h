/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 main関数用ヘッダーファイル                        */
/*                                                                              */
/*[機能概要]      main関数用のヘッダーファイル                                  */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.09  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef MAIN_H
#define MAIN_RUN_H

/***** インクルード宣言 *****/
#include "comet_define.h"
#include "comet_table.h"
#include "check_param.h"
#include "object_open.h"
#include "auto_run.h"
#include "end_output.h"

/***** 定数              *****/
#define NO_FLAG (0)    /*フラグが立っていない*/
#define NO_MEMORY (0)  /*仮想メモリの確保失敗*/

/***** プロトタイプ宣言 *****/
unsigned short  *cm_tbad();

#endif      /*MAIN_H*/

