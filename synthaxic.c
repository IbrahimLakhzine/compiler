#include "synthaxicHeader.h"


void variable(){
	if (return_values[itirateSyntax].code==ID_TOKEN){
		itirateSyntax++;
		
	}

	else if(return_values[itirateSyntax].code==ERREUR_TOKEN){
		printf("Error: unexpected symbol");
		//exit(0);
	}
}
 
void comp(){
	if ( return_values[itirateSyntax].code==DIFF_TOKEN || return_values[itirateSyntax].code==EGALE_TOKEN || return_values[itirateSyntax].code==SUPEG_TOKEN || return_values[itirateSyntax].code==SUP_TOKEN || return_values[itirateSyntax].code==INFEG_TOKEN || return_values[itirateSyntax].code==INF_TOKEN)
	{
		itirateSyntax++;
	}
	else{
		printf("[-]Error synthaxe comparaison");
	}

}

void condition(){
	if((return_values[itirateSyntax].code==TRUE_TOKEN) || (return_values[itirateSyntax].code==FALSE_TOKEN))
		itirateSyntax++;
	else {
		variable();
		comp();
		if(return_values[itirateSyntax].code==ID_TOKEN ){
			variable();
		}
		else if(return_values[itirateSyntax].code==NUM_TOKEN || return_values[itirateSyntax].code==NUMFLOAT_TOKEN )
		{
			chiffre();
		}

		else if(return_values[itirateSyntax].code==TRUE_TOKEN || return_values[itirateSyntax].code==FALSE_TOKEN )
		{
			itirateSyntax++;
		}
		else
		{
			printf("unexpected symbol Error condition");
			//exit(0);
		}
		

		
		
	}

}

void forcondition(){
	variable();
	if(return_values[itirateSyntax].code==INFOR_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==NUM_TOKEN){
			itirateSyntax++;
			if(return_values[itirateSyntax].code==DEUXPT_TOKEN){
				itirateSyntax++;
				if(return_values[itirateSyntax].code==NUM_TOKEN){
					itirateSyntax++;
				}
				else{
					printf("error");
					exit(0);
				}
			}
			else{
				printf("error");
				exit(0);
			}
		}
		else{
			printf("error");
			exit(0);
		}
	}
	else{
		printf("error");
		exit(0);
	}
}


void affec(){
	variable();
	if(return_values[itirateSyntax].code==AFF_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==FUNCTION_TOKEN){
			decfunction();
		}

		else if(return_values[itirateSyntax].code==C_ARRAY_TOKEN){
			carray();
		}

		else if(return_values[itirateSyntax].code==TRAIT_TOKEN){
			string();
		}

		else if(return_values[itirateSyntax].code==ID_TOKEN || return_values[itirateSyntax].code==ID_TOKEN) {

			my_exp();
		}
		else{
			printf("funtion eroor");
		}
	}
	else{
		printf("error");
		exit(0);
	}
}


void args(){
	while(return_values[itirateSyntax].code!=PF_TOKEN && countvir==0){

		if(return_values[itirateSyntax].code==ID_TOKEN){
			itirateSyntax++;
			countvir++;
			if(return_values[itirateSyntax].code==VIR_TOKEN){
				itirateSyntax++;
				countvir--;
			}

			else if(return_values[itirateSyntax].code==PF_TOKEN){
				break;
			}

			else{
				printf("error");
			}
		}

		else if(return_values[itirateSyntax].code==NUM_TOKEN){
			itirateSyntax++;
			countvir++;
			if(return_values[itirateSyntax].code==VIR_TOKEN){
				itirateSyntax++;
				countvir--;
			}

			else if(return_values[itirateSyntax].code==PF_TOKEN){
				break;
			}

			else{
				printf("error");
			}
		}

		else{
			break;
		}

		
	}

	if(countvir!=1){
		printf("virPrblm");
	}

	countvir=0;
}

void string(){
	if(return_values[itirateSyntax].code==TRAIT_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==STRING_TOKEN){
			itirateSyntax++;
			if(return_values[itirateSyntax].code==TRAIT_TOKEN){
				itirateSyntax++;
			}
			else{
				printf("error");
				exit(0);
			}
		}
		else{
			printf("error");
			exit(0);
		}

	}

	else{
		printf("error");
		exit(0);
	}
}

void selecting_vector_elements(){
	if(return_values[itirateSyntax].code==ARRAYNAME_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==CROCHETOU_TOKEN){
			itirateSyntax++;
			if(return_values[itirateSyntax].code==NUM_TOKEN){
				itirateSyntax++;
				if(return_values[itirateSyntax].code==DEUXPT_TOKEN){
					itirateSyntax++;
					if(return_values[itirateSyntax].code==NUM_TOKEN){
						itirateSyntax++;
						if(return_values[itirateSyntax].code==CROCHETFER_TOKEN){
							itirateSyntax++;
						}
						else{
							printf("error selecting ");
							//exit(0);
						}
					}
					else{
						printf("error selecting ");
						//exit(0);
					}
				}
				else if(return_values[itirateSyntax].code==CROCHETFER_TOKEN){
					itirateSyntax++;
				}
				else{
					printf("error selecting");
					//exit(0);
				}
			}

			else if(return_values[itirateSyntax].code==C_ARRAY_TOKEN){
				carray();
				if(return_values[itirateSyntax].code==CROCHETFER_TOKEN){
					itirateSyntax++;
				}
				else{
					printf("error selecting");
					//exit(0);
				}
			}

			else if(return_values[itirateSyntax].code==TRAIT_TOKEN){
				string();
				if(return_values[itirateSyntax].code==CROCHETFER_TOKEN){
					itirateSyntax++;
				}
				else{
					printf("error selecting");
					//exit(0);
				}
			}

			else{
				printf("error selecting");
				//exit(0);
			}
		}
		else{
			printf("error selecting");
			//exit(0);
		}
		
	}
	else{
		printf("error selecting");
		//exit(0);
	}
}


void carray(){
	if(return_values[itirateSyntax].code==C_ARRAY_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==PO_TOKEN){
			itirateSyntax++;
			args();	
			if (return_values[itirateSyntax].code==PF_TOKEN){
				itirateSyntax++;
			}
			else{
				printf("error");
				exit(0);
			}
		}
		else{
			printf("error");
			exit(0);
		}
		
	}
	else{
		printf("error");
		exit(0);
	}
}



void decfunction(){
	if(return_values[itirateSyntax].code==FUNCTION_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==PO_TOKEN){
			itirateSyntax++;
			args();
			if(return_values[itirateSyntax].code==PF_TOKEN){
				itirateSyntax++;
				if(return_values[itirateSyntax].code==ACOUV_TOKEN){
					itirateSyntax++;
					inst();
					if(return_values[itirateSyntax].code==RETURN_TOKEN){
						itirateSyntax++;
						if(return_values[itirateSyntax].code==ID_TOKEN){
							itirateSyntax++;
							if(return_values[itirateSyntax].code==ACF_TOKEN){
								itirateSyntax++;
							}
							else{
								printf("error");
								exit(0);
							}
						}
						else{
							printf("error");
							exit(0);
						}
					}
					else{
						printf("error");
						exit(0);
					}
				}
				else{
					printf("error");
					exit(0);
				}
			}	
			else{
				printf("error");
				exit(0);
			}
		}
		else{
			printf("error");
			exit(0);
		}
	}

	else{
		printf("erooooor function");
		//exit(0);
	}	
}

void arg_print(){
	if (return_values[itirateSyntax].code==TRAIT_TOKEN){
		itirateSyntax++;
		if (return_values[itirateSyntax].code==ID_TOKEN){
			itirateSyntax++;
			if (return_values[itirateSyntax].code==TRAIT_TOKEN){
				itirateSyntax++;
			}else{
				printf("error");
				exit(0);
			}
		}else{
			printf("error");
			exit(0);
		}

	}else{
		if(return_values[itirateSyntax].code==ID_TOKEN || return_values[itirateSyntax].code==NUM_TOKEN){
			my_exp();	
		}else{
			printf("error");
			exit(0);
		}
		
	}


}


void print_fun(){
	if (return_values[itirateSyntax].code==PRINT_TOKEN){

		if (return_values[itirateSyntax].code==PO_TOKEN){
			itirateSyntax++;
			arg_print();
			itirateSyntax++;
			if (return_values[itirateSyntax].code==PF_TOKEN){
				itirateSyntax++;

			}
			else{
				//exit(0);
				printf("Error print1");
			}
		}
		else{
			//exit(0);
			printf("Error print2");
		}
	}
	else{
		printf("Error print3");
	}
}

void inst(){
	if(return_values[itirateSyntax].code==ID_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==AFF_TOKEN){
			itirateSyntax--;
			affec();
			inst();

		}
		else{
			itirateSyntax--;
				my_exp();
				inst();
			}
	}
	else if (return_values[itirateSyntax].code==NUM_TOKEN){
		my_exp();
		inst();		
	}
	else if (return_values[itirateSyntax].code==FOR_TOKEN)
	{
		forfunction();
	}
	else if (return_values[itirateSyntax].code==WHILE_TOKEN)
	{
		whilefunction();
	}
	else if (return_values[itirateSyntax].code==IF_TOKEN)
	{
		iffunction();
	}
	else if (return_values[itirateSyntax].code==PRINT_TOKEN)
	{
		print_fun();
	}
	else if(return_values[itirateSyntax].code==ARRAYNAME_TOKEN){
		selecting_vector_elements();
	}
}
		
void IF_while_cond(){
	if (return_values[itirateSyntax].code==PO_TOKEN){
		itirateSyntax++;
		condition();
		//itirateSyntax++;
		if (return_values[itirateSyntax].code==PF_TOKEN){
			itirateSyntax++;
		}
		else{
			//exit(0);
			printf("Error if while cond PF_T1");
		}
		

	}else{
		//exit(0);
		printf("Error if while conf PO_TOKEN");
	}
}

void W3F_inst(){
	if (return_values[itirateSyntax].code==ACOUV_TOKEN){
		itirateSyntax++;
		inst();
		if (return_values[itirateSyntax].code==ACF_TOKEN){
			itirateSyntax++;
		}else{
			//exit(0);
			printf("Error W3F ACF");
		}

	}else{
		//exit(0);
		printf("Error W3F ACO");
	}
}


void my_A_exp(){
	if(return_values[itirateSyntax].code==MULT_TOKEN || return_values[itirateSyntax].code==MOINS_TOKEN || return_values[itirateSyntax].code==PLUS_TOKEN ||return_values[itirateSyntax].code==DIV_TOKEN){
		itirateSyntax++;
		//op();

		my_exp();

	}
	else{
		if(!(return_values[itirateSyntax].code==MULT_TOKEN && return_values[itirateSyntax].code==MOINS_TOKEN && return_values[itirateSyntax].code==PLUS_TOKEN && return_values[itirateSyntax].code==DIV_TOKEN)){
			//printf("smaaatt\n");
			itirateSyntax--;
			if(return_values[itirateSyntax].code==NUM_TOKEN || return_values[itirateSyntax].code==NUMFLOAT_TOKEN){
				chiffre();
			}		
			else if(return_values[itirateSyntax].code==ID_TOKEN){
				variable();
			}
			else{
				printf("error");
				//exit(0);
			}
		}
	}
}


void my_exp(){		 
	
	if(return_values[itirateSyntax].code==ID_TOKEN || return_values[itirateSyntax].code==NUM_TOKEN){
		itirateSyntax++;
		my_A_exp();

	}
	
		
	else{
		printf("error");
		exit(0);
	}
}	

	

void Else_t2(){
	if(return_values[itirateSyntax].code==ACOUV_TOKEN){
		W3F_inst();
	}else if(return_values[itirateSyntax].code==IF_TOKEN){
		iffunction();
	}else{
		printf("else A Error");
	}
}


void Else_t(){
	if(return_values[itirateSyntax].code==ELSE_TOKEN){//ajouter à l'exicale
		itirateSyntax++;
		Else_t2();
	}else{
		itirateSyntax++;
	}


}

void iffunction(){
	if(return_values[itirateSyntax].code==IF_TOKEN){
		itirateSyntax++;
		IF_while_cond();
		W3F_inst();
		Else_t();

	}
	else{
	 		//exit(0);
			printf("iffunction");
						
		}
}




void whilefunction(){
	if(return_values[itirateSyntax].code==WHILE_TOKEN){
		itirateSyntax++;
		IF_while_cond();
		W3F_inst();

	}
	else{
			//exit(0);
			printf("whilefunction");
		}
}

void forfunction(){
	if(return_values[itirateSyntax].code==FOR_TOKEN){
		itirateSyntax++;
		if(return_values[itirateSyntax].code==PO_TOKEN){
			itirateSyntax++;
			forcondition();
			if(return_values[itirateSyntax].code==PF_TOKEN){
				itirateSyntax++;
				W3F_inst();
			}
			else
			{
				printf("error");
				exit(0);
						
			}
		}
		else
		{
			printf("error");
			exit(0);
		}
	}
	else
	{
		printf("error");
		exit(0);
	}
}

void chiffre(){
	if (return_values[itirateSyntax].code==NUM_TOKEN){
		itirateSyntax++;
		
	}
	else if (return_values[itirateSyntax].code==NUMFLOAT_TOKEN){
		itirateSyntax++;
			

	}
	else{
		printf("error");
		//exit(0);
	}
}



void op(){
	if (return_values[itirateSyntax].code==MULT_TOKEN || return_values[itirateSyntax].code==MOINS_TOKEN || return_values[itirateSyntax].code==PLUS_TOKEN ||return_values[itirateSyntax].code==DIV_TOKEN ){
		itirateSyntax++;
	}

	else{
		
		//exit(0);
		printf("error");

	}
}