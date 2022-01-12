/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 IoT開発演習 EXIT関数                              */
/*                                                                              */
/*[機能概要]      命令EXITを実行する                                            */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.19  **********                                */
/*                                                                              */
/********************************************************************************/
#ifndef CMD_EXIT_H
#define CMD_EXIT_H

#include "comet_table.h"
#include "comet_define.h"

/*プロトタイプ宣言*/
int cmd_exit(T_TRACE *pk_trace, unsigned short * puh_1st_adr);

#endif /*CMD_EXIT_H*/

