/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 アドレッシングモード解析関数                      */
/*                                                                              */
/*[機能概要]      アドレッシングモードを解析する                                */
/*                                                                              */
/*[記述形式]      int adrmode_check(T_TRACE *pk_trace,                          */
/*                                  unsigned short *puh_1st_adr)                */
/*                                                                              */
/*[パラメータ]    T_TRACE *pk_trace (I/O)                                       */
/*                    トレースの際に用いる情報が内包された構造体                */
/*                    間接アドレス指定を出力する                                */
/*                unsigned short *puh_1st_adr (I)                               */
/*                    仮想メモリの先頭アドレス                                  */
/*                                                                              */
/*[戻り値]        DIR_AM    直接アドレス指定                                    */
/*                IND_AM    インデックスアドレス指定                            */
/*                IDR_AM    間接アドレス指定                                    */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.08  **********                                */
/*                改版    2019.08.09  **********                                */
/*                        定数名の変更                                          */
/*                                                                              */
/********************************************************************************/ 

#include "adrmode_check.h"

int adrmode_check(T_TRACE  *pk_trace, unsigned short *puh_1st_adr)
{
    /*命令第1語のbit3が１か*/ 
    if((*(puh_1st_adr + pk_trace->uh_pr) & BIT_MASK_3) != 0) {
        pk_trace->uh_i = 1;
        return IDR_AM;                                      //間接アドレス指定
    }else{
    /*命令第1語のbit0-2が0か*/
        if((*(puh_1st_adr + pk_trace->uh_pr) & BIT_MASK_2_0) == 0) {
            pk_trace->uh_i = 0;
            return DIR_AM;                                  //直接アドレス指定
        }else{
            pk_trace->uh_i = 0;
            return IND_AM;                                  //インデックスアドレス指定
        }
    }
}
