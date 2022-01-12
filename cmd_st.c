/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 ST関数                                            */
/*                                                                              */
/*[機能概要]      命令語STを実行する                                            */
/*                                                                              */
/*[記述形式]      int cmd_st( T_TRACE *pk_trace, unsigned short *puh_1st_adr )  */
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
#include "cmd_st.h"

int cmd_st(T_TRACE *pk_trace, unsigned short *puh_1st_adr)
{
	/***** セット処理 *****/
	*(puh_1st_adr + pk_trace->uh_ea) = pk_trace->auh_gr[pk_trace->uh_g];

	/***** プログラムレジスタ更新 *****/
	pk_trace->uh_pr += 2;

	/*正常終了*/
	return CMD_OK;
}
