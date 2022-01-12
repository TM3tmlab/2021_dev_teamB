/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 オブジェクトファイル展開関数用                    */
/*                                                                              */
/*[機能概要]      オブジェクトファイル展開関数用ヘッダファイル                  */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.09  **********                                */
/*                修正    2019.08.19  **********                                */
/*                        整形コマンド使用                                      */
/*                修正    2019.08.20  **********                                */
/*                        プロトタイプ宣言後のセミコロン追加                    */
/*                修正    2019.08.21  **********                                */
/*                        インクルードファイルを追加、定数を追加                */
/*                                                                              */
/********************************************************************************/
#ifndef OBJECT_OPEN_H
#define OBJECT_OPEN_H

/*ヘッダファイル*/
#include <sys/stat.h>
#include <stdio.h>
#include "comet_define.h"
#include "comet_table.h"

/*マクロ定数*/
#define FILE_HEAD_SIZE (32)				   /*オブジェクトファイルヘッド情報サイズ*/
#define FILE_HEAD_NUM (FILE_HEAD_SIZE / 2) /*ヘッド情報要素数*/
#define RESERVE_SIZE (28)				   /*不要箇所*/
#define UH_OBJ_OPEN (0)					   /*オブジェクト展開先アドレス部*/
#define UH_INIT_PR (1)					   /*実行開始アドレス部*/

/*プロトタイプ宣言*/
int object_open(char *pc_argv, unsigned short *puh_1st_adr, T_OBJ *pk_obj);

#endif /*OBJECT_OPEN_H*/
