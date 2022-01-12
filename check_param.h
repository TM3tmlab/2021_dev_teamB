/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 パラメータチェック関数マクロ                      */
/*                                                                              */
/*[機能概要]      パラメータチェックヘッダ関数ファイル                          */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.09  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef CHECK_PARAM_H
#define CHECK_PARAM_H

/***** インクルード宣言 *****/
#include<stdlib.h>
#include<string.h>
#include"comet_define.h"
#include"comet_table.h"

/***** マクロ定義 *****/
#define PRM_NUM_MIN (1)         /*PARAMETERの最小個数*/
#define OPT_R "-r"              /*オプション-r*/
#define OPT_S "-s"              /*オプション-s*/
#define OPT_M "-m"              /*オプション-m*/
#define OPT_R_FLAG_UP (1)       /*オプション-rが存在したときのフラグを立てる*/
#define OPT_M_FLAG_UP (1)       /*オプション-mが存在したときのフラグを立てる*/
#define OPT_STEP_FLAG_UP (1)    /*オプション-sのオプション引数であることを示すフラグを立てる*/
#define OPT_STEP_FLAG_DOWN (0)  /*オプション-sのオプション引数であることを示すフラグを無効にする*/
#define MAX_STEP (2147483648)   /*ステップ数の最大*/
#define MIN_STEP (0)            /*ステップ数の最小*/
#define FILE_FLAG_DOWN (0)      /*コマンドライン引数にファイルが存在しなかった*/
#define FILE_FLAG_UP (1)        /*ファイルが存在したときのフラグを立てる*/
#define DECIMAL_NUM (10)        /*１０進数*/
#define TOP_POS (1)             /*引数の先頭の位置*/
#define MATCH (0)               /*一致*/

/***** プロトタイプ宣言 *****/
int check_param(int, char*[], T_OPT*, unsigned short*);

#endif      /*CHECK_PARAM_H*/
