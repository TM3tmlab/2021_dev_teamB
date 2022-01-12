/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 COMET共通構造体テーブル                           */
/*                                                                              */
/*[機能概要]      COMETプログラム共通構造体ヘッダファイル                       */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.08  **********                                */
/*                                                                              */
/********************************************************************************/ 
#ifndef COMET_TABLE_H
#define COMET_TABLE_H

#include "comet_define.h"

/*オプション用テーブル*/
typedef struct{
    short h_opt_r;  /*-rの有無*/
    short h_opt_m;  /*-mの有無*/
    int i_step;     /*ステップ数*/
}T_OPT;

/*オブジェクト用テーブル*/
typedef struct{
    unsigned short uh_obj_open;     /*オブジェクト展開先アドレス*/
    unsigned short uh_init_pr;      /*実行開始アドレス(PR初期値)*/
    int i_code_size;                /*オブジェクトコードサイズ*/
}T_OBJ;


/*トレースリスト用テーブル*/
typedef struct{
    unsigned short uh_adr;          /*命令アドレス*/
    unsigned short uh_opcd;         /*命令コード*/
    unsigned short uh_opr1;         /*オペランドコード1*/
    unsigned short uh_opr2;         /*オペランドコード2*/
    char ac_mne[MNE_LEN];           /*命令コードのニモニック*/
    unsigned short uh_g;            /*汎用レジスタ番号又はR1*/
    unsigned short uh_i;            /*間接アドレス指定*/
    unsigned short uh_x;            /*インデックスレジスタ番号、又は間接レジスタ番号、又はR2*/
    unsigned short uh_ea;           /*有効アドレス*/
    unsigned short uh_pr;           /*プログラムレジスタ*/
    unsigned short auh_gr[GR_NUM];  /*汎用レジスタの内容*/
    unsigned short uh_mr;           /*マスクレジスタの内容*/
    unsigned short uh_fr;           /*フラグレジスタの内容*/
    char c_trace_flag;              /*トレースリスト表示空白判定用フラグ*/
}T_TRACE;

/*命令解析用テーブル*/
typedef struct{
    unsigned short uh_opcd;     /*オペレーションコード*/
    char ac_mne[MNE_LEN];       /*ニモニック*/
    int (*pi_func_cmd)();       /*各命令実行関数ポインタ*/
}T_CMD;

#endif
