#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

int itirateSyntax=0;
int id_or_idArray=0;
int countvir=0;


typedef enum{
	PRINT_TOKEN,TRUE_TOKEN,TRAIT_TOKEN,FILENAME_TOKEN,FILEEXTENSION_TOKEN,MATRIX_TOKEN,MAX_TOKEN,MIN_TOKEN,SUM_TOKEN,MEAN_TOKEN,LIST_TOKEN,FALSE_TOKEN,TABLE_TOKEN,DEUXPT_TOKEN,CROCHETOU_TOKEN,CROCHETFER_TOKEN,ID_TOKEN,STRING_TOKEN,C_ARRAY_TOKEN,ARRAYNAME_TOKEN,INDEXARRAY_TOKEN,FUNCTION_TOKEN,PO_TOKEN,INFOR_TOKEN,RETURN_TOKEN,IF_TOKEN,ACOUV_TOKEN,ACF_TOKEN,WHILE_TOKEN,FOR_TOKEN,DO_TOKEN,READ_TOKEN,
	WRITE_TOKEN,P_TOKEN,PLUS_TOKEN,MOINS_TOKEN,MULT_TOKEN,DIV_TOKEN,VIR_TOKEN,AFF_TOKEN,EGALE_TOKEN,INF_TOKEN,INFEG_TOKEN,SUP_TOKEN,
	SUPEG_TOKEN,DIFF_TOKEN,PT_TOKEN,PF_TOKEN,NUMFLOAT_TOKEN,NUM_TOKEN,ERREUR_TOKEN,FIN_TOKEN,ELSE_TOKEN
}myCodes;


typedef struct { 
	myCodes code; 
	char nom[10]; 
} what_return;

char char_now;
char word[10];
char number[10];
int myIndex;
what_return *return_values;

#include "lexicalHeader.h"
#include "synthaxicHeader.h"


int main(int argc, char const *argv[]){
	FILE *file;
	myIndex=0;
	return_values=(what_return *)malloc((myIndex+1)*sizeof(what_return));
	file=fopen("C:/Users/ibrahim.l/Desktop/code.txt","r");

	do{
		
		if(feof(file))
			break;
		sym_follow(file);

	}while(1);

	for(int i=0;i<myIndex;i++){
		printf("code:%d value:%s\n",return_values[i].code,return_values[i].nom);	
	}

	inst();
	

	fclose(file);
	return 0;
}