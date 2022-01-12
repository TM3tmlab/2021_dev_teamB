/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 COMET共通#defineマクロ                            */
/*                                                                              */
/*[機能概要]      COMETプログラム共通#defineヘッダファイル                      */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.08  **********                                */
/*                改訂    2019.08.09  **********                                */
/*                        命令語解析ビット操作用、フラグレジスタビット操作用追加*/
/*                        空白表示ビット操作用追加                              */
/*                        OPcode参照用追加                                      */
/*                        main内エラーコード追加                                */
/*                        オーバーフロー用追加                                  */
/*                        object_open戻り値SHORT_FILEからFILE_SIZE_ERRORに更新  */
/*                改訂    2019.08.21  **********                                */
/*                        シフト命令オーバーフロー判定用追加                    */
/*                                                                              */
/********************************************************************************/
#ifndef COMET_DEFINE_H
#define COMET_DEFINE_H

/***** 共通定数 *****/
#define VM_MAX_SIZE (0x7FFF)    /*仮想メモリ最大サイズ*/
#define GR_NUM (5)              /*汎用レジスタ個数*/
#define MNE_LEN (5)             /*ニモニック文字数*/
#define CMD_NUM (6)             /*命令語個数*/

/*命令語解析ビット操作用*/
#define BIT_MASK_15_8 (0xFF00)  /*OPcode部抽出用*/
#define BIT_SHIFT_15_8 (8)      /*OPcode部シフト計算用*/
#define BIT_MASK_7_4 (0x00F0)   /*R、R1部抽出用*/
#define BIT_SHIFT_7_4 (4)       /*R、R1部シフト計算用*/
#define BIT_MASK_3 (0x0008)     /*I部抽出用*/
#define BIT_SHIFT_3 (3)         /*I部シフト計算用*/
#define BIT_MASK_2_0 (0x0007)   /*XR、IR、R2部抽出用*/

/*シフト命令オーバーフロー判定用*/
#define BIT_MASK_15 (0x8000)	/*SLL命令用*/

/*フラグレジスタビット操作用*/
#define FR_ZERO_FRAG (0x0001)   /*ゼロフラグ*/
#define FR_SIGN_FRAG (0x0002)   /*サインフラグ*/
#define FR_OVER_FRAG (0x0004)   /*オーバーフローフラグ*/

/*フラグレジスタオーバーフロー範囲用*/
#define SHORT_MIN (-32768)
#define SHORT_MAX (32767)
#define U_SHORT_MIN (0)
#define U_SHORT_MAX (65535)

/*空白表示ビット操作用*/
#define BLANK_ALL (0x07)    /*OPR1,OPR2,EA全て空白表示*/
#define BLANK_OPR2 (0x02)   /*OPR2のみ空白表示*/

/*OPcode参照用*/
#define OPCD_LD1 (0x14)     /*LD(1語)のOPcode*/
#define OPCD_LD2 (0x10)     /*LD(2語)のOPcode*/
#define OPCD_ST (0x11)      /*STのOPcode*/
#define OPCD_ADDA (0x20)    /*ADDAのOPcode*/
#define OPCD_SLL (0x52)     /*SLLのOPcode*/
#define OPCD_EXIT (0xA0)    /*EXITのOPcode*/


/***** 復帰値 *****/
/*main*/
#define OK (0)      /*正常*/
#define NG (1)      /*異常*/
/*main内エラーコード*/
#define NOT_MANUAL (3)      /*マニュアルモード未実装*/
#define MEMORY_ERROR (11)   /*メモリ確保エラー*/

/*check_param*/
#define PRM_OK (0)      /*正常*/
#define PRM_NG_PE (1)   /*異常：パラメータエラー*/
#define PRM_NG_FE (2)   /*異常：ファイルエラー*/

/*object_open*/
#define OPEN_OK (0)             /*正常*/
#define NO_FILE (21)            /*異常：ファイルなし*/
#define FILE_SIZE_ERROR (22)    /*異常：ファイルサイズが小さすぎる*/
#define LARGE_FILE (23)         /*異常：コードサイズが大きすぎる*/

/*auto_run*/
#define TRACE_END (0)       /*正常*/
#define TRACE_END_HC (31)   /*異常：メモリ未実装/未定義命令*/
#define TRACE_END_SO (32)   /*異常：ステップ数オーバー*/
#define TRACE_END_NE (33)   /*異常：EXITなし*/

/*ea_check*/
#define EA_OK (0)   /*正常*/
#define EA_NG (1)   /*異常：メモリ未実装/未定義命令*/

/*adrmode_check*/
#define DIR_AM (0)  /*正常：直接アドレス指定*/
#define IND_AM (1)  /*正常：インデックスアドレス指定*/
#define IDR_AM (2)  /*正常：間接アドレス指定*/

/*cmd*/
#define CMD_OK (0)  /*正常*/

/*trace_output*/
#define TRACE_OK (0)    /*正常*/

/*end_output*/
#define END_OK (0)  /*正常*/
#define END_NG (1)  /*異常*/

#endif  /*COMET_DEFINE_H*/
