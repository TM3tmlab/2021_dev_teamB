/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 オートモード関数                                  */
/*                                                                              */
/*[機能概要]      オートモード時の処理の管理を行う                              */
/*                                                                              */
/*[記述形式]      int auto_run(T_OPT k_opt_ar, T_OBJ k_obj_ar,                  */
/*                             unsigned short *puh_1st_adr)                     */
/*                                                                              */
/*[パラメータ]    T_OPT k_opt_ar (I)オプションの内容が内包された構造体          */
/*                T_OBJ k_obj_ar (I)オブジェクトファイルの情報が内包された構造体*/
/*                unsigned short *puh_1st_adr (I)仮想メモリの先頭アドレス       */
/*                                                                              */
/*[戻り値]       TRACE_END       正常終了                                       */
/*               TRACE_END_HC    異常終了(メモリ未実装/未定義命令)              */
/*               TRACE_END_SO    異常終了(ステップ数異常)                       */
/*               TRACE_END_NE    異常終了(EXITなし)                             */
/*                                                                              */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.19  **********                                */
/*                改訂    2019.08.22  **********                                */
/*                        ADRが更新されないバグを修正                           */
/*                        異常終了時のトレース結果を出力するように変更          */
/*                                                                              */
/********************************************************************************/ 

#include "auto_run.h"

int auto_run(T_OPT k_opt_ar, T_OBJ k_obj_ar, unsigned short *puh_1st_adr)
{
    /***** 変数宣言 *****/
    /*トレースリスト用構造体　初期化*/
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
    /*命令解析用構造体　初期化*/
    T_CMD k_cmd_ar[CMD_NUM] =    {   {OPCD_LD1, "LD", cmd_ld1},
                                    {OPCD_LD2, "LD", cmd_ld2},
                                    {OPCD_ST, "ST", cmd_st},
                                    {OPCD_ADDA, "ADDA", cmd_adda},
                                    {OPCD_SLL, "SLL", cmd_sll},
                                    {OPCD_EXIT, "EXIT", cmd_exit}
                                };
    int i;      //ループカウント用変数1
    int i2;     //ループカウント用変数2
    int i_return_ea_check;  //有効アドレス解析関数復帰値
    int (*pi_do_func)();    //実行関数ポインタ

    /*処理・トレースループ　最大ステップ数を超えるまで*/
    for(i = 0; i < k_opt_ar.i_step; i++) {

    	k_trace_ar.uh_adr = k_trace_ar.uh_pr;
    	i_return_ea_check = ea_check(&k_trace_ar, puh_1st_adr);

        /*関数ポインタで命令関数呼び出し＆二モニック代入*/
        for(i2 = 0; i2 < CMD_NUM; i2++) {
            if(k_cmd_ar[i2].uh_opcd == (k_trace_ar.uh_opcd >> BIT_SHIFT_15_8)) {
                strcpy(k_trace_ar.ac_mne, k_cmd_ar[i2].ac_mne);
                pi_do_func = k_cmd_ar[i2].pi_func_cmd;
                break;
            }
            strcpy(k_trace_ar.ac_mne, "    ");
        }


        /*PRがオブジェクトコード展開していない場所を指していないか*/    
        if(k_trace_ar.uh_pr < k_obj_ar.uh_obj_open || k_trace_ar.uh_pr > (k_obj_ar.uh_obj_open + (unsigned short)(k_obj_ar.i_code_size / (int)sizeof(unsigned short)) - 1)) {
            if(k_opt_ar.h_opt_r == 0) {
                trace_output(k_trace_ar, i);
            }
            return TRACE_END_NE;
        }
   
        /*有効アドレス解析関数エラーチェック*/ 
        if(i_return_ea_check == EA_NG) {
            if(k_opt_ar.h_opt_r == 0) {
                trace_output(k_trace_ar, i);
            }
            return TRACE_END_HC;
        }

        (void)(*pi_do_func)(&k_trace_ar, puh_1st_adr);

        /*-rオプションがなければトレース結果出力関数呼び出し*/
        if(k_opt_ar.h_opt_r == 0) {
            trace_output(k_trace_ar, i);
        }

        /*EXITだったら正常終了*/
        if(strcmp(k_trace_ar.ac_mne, "EXIT") == 0) {
            return TRACE_END;
        }
    }

    return TRACE_END_SO;           

}
