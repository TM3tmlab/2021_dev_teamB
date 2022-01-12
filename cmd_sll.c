/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 SLL関数                                           */
/*                                                                              */
/*[機能概要]      命令語SLLを実行する                                           */
/*                                                                              */
/*[記述形式]      int cmd_sll( T_TRACE *pk_trace, unsigned short *puh_1st_adr ) */
/*                                                                              */
/*[パラメータ]    T_TRACE  *pk_trace            (I/O)トレースリスト用構造体     */
/*                unsigned short  *puh_1st_adr  仮想メモリの先頭アドレス        */
/*                                              (使用しない)                    */
/*                                                                              */
/*[戻り値]        CMD_OK         正常終了                                       */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.19  **********                                */
/*                                                                              */
/********************************************************************************/
#include "cmd_sll.h"

int cmd_sll(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
    (void)puh_1st_adr;              /*SLL関数では先頭アドレスを使用しない*/

	/***** 変数宣言 *****/
	unsigned short uh_over_flag;    /*オーバーフロー判断用*/

	/***** 計算処理 *****/
	pk_trace->auh_gr[pk_trace->uh_g] <<= (pk_trace->uh_ea - 1);
	uh_over_flag = pk_trace->auh_gr[pk_trace->uh_g] & BIT_MASK_15;
	pk_trace->auh_gr[pk_trace->uh_g] <<= 1;

	/***** フラグレジスタ更新 *****/
	/*初期化*/
	pk_trace->uh_fr = 0x0000;
	/*ゼロフラグ判定*/
	if(pk_trace->auh_gr[pk_trace->uh_g] == 0) {
		pk_trace->uh_fr |= FR_ZERO_FRAG;
	}
	/*サインフラグ判定*/
	if((short)(pk_trace->auh_gr[pk_trace->uh_g]) < 0) {
		pk_trace->uh_fr |= FR_SIGN_FRAG;
	}
	/*オーバーフローフラグ判定*/
	if(uh_over_flag != 0) {
        pk_trace->uh_fr |= FR_OVER_FRAG;
    }

    /***** プログラムレジスタ更新 *****/
    pk_trace->uh_pr += 2;

    /*正常終了*/
    return CMD_OK;
}
