/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 LD1語命令関数                                     */
/*                                                                              */
/*[機能概要]      命令語LD1を実行する                                           */
/*                                                                              */
/*[記述形式]      int cmd_ld1( T_TRACE *pk_trace, unsigned short *puh_1st_adr ) */
/*                                                                              */
/*[パラメータ]    T_TRACE  *pk_trace            (I/O)トレースリスト用構造体     */
/*                unsigned short  *puh_1st_adr  (I)仮想メモリの先頭アドレス     */
/*                                                                              */
/*[戻り値]        CMD_OK         正常終了                                       */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.08  **********                                */
/*                                                                              */
/********************************************************************************/
#include "cmd_ld1.h"

int cmd_ld1(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
	/***** ロード処理 *****/
	pk_trace->auh_gr[pk_trace->uh_g] = pk_trace->auh_gr[pk_trace->uh_x];

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

	/***** プログラムレジスタ更新 *****/
	pk_trace->uh_pr += 1;

	/*正常終了*/
	return CMD_OK;
}
