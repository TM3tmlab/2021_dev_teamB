/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習  トレース結果出力関数                             */
/*                                                                              */
/*[機能概要]      トレース結果を表示する。                                      */
/*                                                                              */
/*[記述形式]      int trace_output ( T_TRACE k_trace, int i_step)               */
/*                                                                              */
/*[パラメータ]                                                                  */
/*      T_TRACE     k_trace     (I)トレースリスト用構造体                       */
/*      int         i_step      (I)現在ステップ数                               */
/*                                                                              */
/*[戻り値]                                                                      */
/*    TRACE_OK       正常終了                                                   */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.19  ****                                      */
/*                改番    2019.08.22  ****                                      */
/*                        タイトルの命令コードのニモニックの表示を修正          */
/*                                                                              */
/********************************************************************************/

#include "trace_output.h"

int trace_output(T_TRACE k_trace, int i_step)
{

	/*タイトル表示判定*/
	if ( (i_step % NUM_TITLE_DISPLAY) == 0) {
		printf("ADR  OPCD OPR1 OPR2 MNE  G I X EA   PR   GR0  GR1  GR2  GR3  GR4  MR FR\n");
	}

	/*ADRを表示*/
	printf("%04X", k_trace.uh_adr);

	/*OPCDを表示*/
	printf(" %04X", k_trace.uh_opcd);

	/**OPR1を表示**/
	if ( (k_trace.c_trace_flag & NONE_OPR1) == 0) {
		printf(" %04X", k_trace.uh_opr1);
	} else {
		printf("     ");
	}

	/**OPR2を表示**/
	if ( (k_trace.c_trace_flag & NONE_OPR2) == 0) {
		printf(" %04X", k_trace.uh_opr2);
	} else {
		printf("     ");
	}

	/*MNEを表示*/
	printf(" %-4s", k_trace.ac_mne);

	/*Gを表示*/
	printf(" %01X", k_trace.uh_g);

	/*Iを表示*/
	printf(" %01X", k_trace.uh_i);

	/*Xを表示*/
	printf(" %01X", k_trace.uh_x);

	/**EAを表示**/
	if ( (k_trace.c_trace_flag & NONE_OPR_EA) == 0) {
		printf(" %04X", k_trace.uh_ea);
	} else {
		printf("     ");
	}

	/*PRを表示*/
	printf(" %04X", k_trace.uh_pr);

	/*GR0を表示*/
	printf(" %04X", k_trace.auh_gr[0]);

	/*GR1を表示*/
	printf(" %04X", k_trace.auh_gr[1]);

	/*GR2を表示*/
	printf(" %04X", k_trace.auh_gr[2]);

	/*GR3を表示*/
	printf(" %04X", k_trace.auh_gr[3]);

	/*GR4を表示*/
	printf(" %04X", k_trace.auh_gr[4]);

	/*MRを表示*/
	printf(" %02X", k_trace.uh_mr);

	/*FRを表示*/
	printf(" %02X\n", k_trace.uh_fr);

	return TRACE_OK;
}
