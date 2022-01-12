#include"comet.h"


int main(int argc,char *argv[]){


    int i_code = 0;                     
    unsigned short *puh_1st_adr = 0;
    unsigned short puh_pos;
    
    T_OPT k_prm_tbl = {0,0,500};
    T_OBJ k_obj_tbl = {0,0,0};



    i_code = check_param(argc,argv,&k_prm_tbl,&puh_pos);


    if(i_code == 0){
	puh_1st_adr = cm_tbad();

	if (*puh_1st_adr == 0) {
	    i_code = MEMORY_ERROR;
	
        }
    }

    if(i_code == 0){
	i_code = object_open(argv[puh_pos],&k_obj_tbl,puh_1st_adr);
	
        if (i_code == 0){
	    i_code = auto_run(&k_prm_tbl,&k_obj_tbl,puh_1st_adr); 
       	}
    }


    (void)end_output(i_code);

    if(i_code != 0){
        return NG;
    }
return OK;
}







