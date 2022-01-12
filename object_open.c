#include "object_open.h"
#include<stdio.h>
#define OBJ_HDR_SIZE 32
#define VMEM_SIZE 0x7FFF
    typedef struct objhdr
    {
        unsigned short tenkai_adr;     /*コード展開先アドレス*/
	unsigned short kaishi_adr;     /*実行開始アドレス*/
	unsigned short reserve1[8];    /*リザーブ*/
	int            next_link;      /*次オブジェクトリンク*/
	unsigned short reserve2[4];    /*リザーブ*/
    }OBJHDR;
int object_open(char *pc_argv,unsigned short *puh_1st_adr, T_OBJ *pkobj){
 
    FILE *fp;
    struct stat k_stat;
    int read_num;
    int obj_size;
    OBJHDR data1; 

    if(puh_1st_adr == NULL){
	return NO_FILE;
	}

    fp = fopen(pc_argv,"r");
    if(fp == NULL){
        return NO_FILE;
    }
    if(stat(pc_argv,&k_stat) == -1){
	return NO_FILE;
    }
    if(k_stat.st_size>VMEM_SIZE){
	return FILE_SIZE_ERROR;
    }

    read_num =fread(&data1,sizeof(char),OBJ_HDR_SIZE,fp);
    if(read_num != OBJ_HDR_SIZE){
        return NO_FILE;
    }
    obj_size = data1.next_link;
    if(obj_size == 0){
        obj_size = k_stat.st_size - OBJ_HDR_SIZE;
    }
	
    if((obj_size + data1.tenkai_adr) > VMEM_SIZE){
        return LARGE_FILE;
    }
	
    read_num = fread((puh_1st_adr + data1.tenkai_adr),sizeof(char),obj_size,fp);
    if(read_num != obj_size){
        return NO_FILE;
    }
    fclose(fp);

    pkobj->uh_obj_open = data1.tenkai_adr;
    pkobj->uh_init_pr  = data1.kaishi_adr;
    pkobj->i_code_size = obj_size;

    return OPEN_OK;
}

	
