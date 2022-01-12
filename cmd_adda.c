/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 ADDA関数                                          */
/*                                                                              */
/*[機能概要]      命令語ADDAを実行する                                          */
/*                                                                              */
/*[記述形式]      int cmd_adda( T_TRACE *pk_trace, unsigned short *puh_1st_adr )*/
/*                                                                              */
/*[パラメータ]    T_TRACE  *pk_trace            (I/O)トレースリスト用構造体     */
/*                unsigned short  *puh_1st_adr  (I)仮想メモリの先頭アドレス     */
/*                                                                              */
/*[戻り値]        CMD_OK         正常終了                                       */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.09  **********                                */
/*                                                                              */
/********************************************************************************/
#include "cmd_adda.h"

int cmd_adda(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
	/***** 変数宣言 *****/
	int i_sum; /*オーバーフロー判断用に計算結果を一時保存する*/

	/***** 計算処理 *****/
	i_sum = (int)((short)*(puh_1st_adr + pk_trace->uh_ea) + (short)pk_trace->auh_gr[pk_trace->uh_g]);
	pk_trace->auh_gr[pk_trace->uh_g] = (unsigned short)i_sum;

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
	if((short)(i_sum < SHORT_MIN || i_sum > SHORT_MAX)) {
		pk_trace->uh_fr |= FR_OVER_FRAG;
	}

	/***** プログラムレジスタ更新 *****/
	pk_trace->uh_pr += 2;

	/*正常終了*/
	return CMD_OK;
}
