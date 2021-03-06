/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 SLL語命令関数用ヘッダファイル                     */
/*                                                                              */
/*[機能概要]      SLL語命令関数用ヘッダファイル                                 */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.19  **********                                */
/*                                                                              */
/********************************************************************************/
#ifndef CMD_SLL_H
#define CMD_SLL_H

#include "comet_table.h"
#include "comet_define.h"

/*プロトタイプ宣言*/
int cmd_sll(T_TRACE *pk_trace, unsigned short *puh_1st_adr);

#endif /*CMD_SLL_H*/
