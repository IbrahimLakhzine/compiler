#include"lexicalHeader.h"


void myRealloc(){
	return_values=(what_return *)realloc(return_values,(myIndex+1)*sizeof(what_return));
}

void read_else(char* str,myCodes code){
	what_return val;
	val.code=code;
	strcpy(val.nom,str);
	return_values[myIndex]=val;
	myIndex++;
	myRealloc();
}

void read_number(FILE *file){
	what_return val;
	int i=0;
	int flag=0;
	do{
		if(char_now==EOF || char_now=='{' || char_now=='}' || char_now=='[' || char_now==']' || char_now=='\t' || char_now=='\n' || char_now==' ' || char_now=='+' || char_now=='-' || char_now=='/' || char_now=='*' || char_now==',' || char_now=='<' || char_now=='>' || char_now==':' || char_now=='=' || char_now=='(' || char_now==')' || char_now=='!')
			break;

		else if(isalpha(char_now) && flag==0){
			read_else("ERREUR",ERREUR_TOKEN);

			for(int i=0;i<10;i++){
				number[i]='\0';
			}

			flag=1;
		} 


		number[i]=char_now;
		char_now=fgetc(file);
		i++;	
	}while(1);

	if(flag==0){
		val.code=NUM_TOKEN;
		strcpy(val.nom,number);

		for(int i=0;i<10;i++){
			number[i]='\0';
		}


		return_values[myIndex]=val;
		myIndex++;
		myRealloc();	
	}
	
}

void read_word_else(char* str,myCodes code){
	what_return val;
	val.code=code;
	strcpy(val.nom,str);
	return_values[myIndex]=val;
	myIndex++;

	for(int j=0;j<10;j++){
		word[j]='\0';
	}

	myRealloc();

}

void read_word(FILE *file){
	int i=0;
	do{
		if(char_now==EOF || char_now=='{' || char_now=='}' || char_now==']' || char_now=='\t' || char_now=='\n' || char_now=='!' || char_now==' ' || char_now=='+' || char_now=='-' || char_now=='/' || char_now=='*' || char_now==',' || char_now=='<' || char_now=='>' || char_now==':' || char_now=='=' || char_now==')'|| char_now=='{'|| char_now=='}'){
			id_or_idArray=0;
			break;
		}

		else if(char_now=='('){
			id_or_idArray=1;
			break;
		}

		else if(char_now=='['){
			id_or_idArray=2;
			break;
		}

		else if(char_now=='\''){
			id_or_idArray=3;
			break;
		}

		else if(char_now=='.'){
			id_or_idArray=4;
			break;
		}

		word[i]=char_now;
		char_now=fgetc(file);
		i++;	
	}while(1);



	if(strcmp(word,"print")==0){
		read_word_else(word,PRINT_TOKEN);
	}

	else if(strcmp(word,"function")==0){
		read_word_else(word,FUNCTION_TOKEN);
	}

	else if(strcmp(word,"TRUE")==0){
		read_word_else(word,TRUE_TOKEN);
	}

	else if(strcmp(word,"FALSE")==0){
		read_word_else(word,FALSE_TOKEN);
	}

	
	else if(strcmp(word,"return")==0){
		read_word_else(word,RETURN_TOKEN);
	}

	else if(strcmp(word,"table")==0){
		read_word_else(word,TABLE_TOKEN);
	}

	else if(strcmp(word,"if")==0){
		read_word_else(word,IF_TOKEN);
	}
	else if(strcmp(word,"else")==0){
		read_word_else(word,ELSE_TOKEN);
	}

	else if(strcmp(word,"while")==0){
		read_word_else(word,WHILE_TOKEN);
	}

	else if(strcmp(word,"do")==0){
		read_word_else(word,DO_TOKEN);
	}
	else if(strcmp(word,"for")==0){
		read_word_else(word,FOR_TOKEN);
	}

	else if(strcmp(word,"in")==0){
		read_word_else(word,INFOR_TOKEN);
	}

	else if(strcmp(word,"matrix")==0){
		read_word_else(word,MATRIX_TOKEN);
	}

	else if(strcmp(word,"list")==0){
		read_word_else(word,LIST_TOKEN);
	}

	else if(strcmp(word,"read")==0){
		read_word_else(word,READ_TOKEN);
	}

	else if(strcmp(word,"write")==0){
		read_word_else(word,WRITE_TOKEN);
	}

	else if(strcmp(word,"max")==0){
		read_word_else(word,MAX_TOKEN);
	}
	else if(strcmp(word,"min")==0){
		read_word_else(word,MIN_TOKEN);
	}
	else if(strcmp(word,"mean")==0){
		read_word_else(word,MEAN_TOKEN);
	}
	else if(strcmp(word,"sum")==0){
		read_word_else(word,SUM_TOKEN);
	}

	else if(strcmp(word,"txt")==0){
		read_word_else(word,FILEEXTENSION_TOKEN);
	}

	else{
		if(id_or_idArray==0){
			read_word_else(word,ID_TOKEN);	
		}	
		else if(id_or_idArray==1 && strcmp(word,"c")==0){
			read_word_else(word,C_ARRAY_TOKEN);
		}
		else if(id_or_idArray==1){
			read_word_else(word,ERREUR_TOKEN);
		}
		else if(id_or_idArray==2){
			read_word_else(word,ARRAYNAME_TOKEN);
		}

		else if(id_or_idArray==3){
			read_word_else(word,STRING_TOKEN);
		}

		else if(id_or_idArray==4){
			read_word_else(word,FILENAME_TOKEN);
		}
	}
	
	
}




void sym_follow(FILE *file){
	
	char_now=fgetc(file);

	if (isalpha(char_now)){
		read_word(file);		
	}

	if (isdigit(char_now)){
		read_number(file);

	}


	if(!isalpha(char_now) && !isdigit(char_now)){
		if(char_now=='+'){
			read_else("+",PLUS_TOKEN);		
		}

		else if(char_now=='-'){
			read_else("-",MOINS_TOKEN);	
		}

		else if(char_now=='\''){
			read_else("'",TRAIT_TOKEN);
		}

		else if(char_now==':'){
			read_else(":",DEUXPT_TOKEN);	
		}

		else if(char_now=='='){
			char_now=fgetc(file);

			if(char_now=='='){
				read_else("==",EGALE_TOKEN);	
			}
		}

		else if(char_now=='!'){
			char_now=fgetc(file);

			if(char_now=='='){
				read_else("!=",DIFF_TOKEN);	
			}
		}

		else if(char_now=='.'){
			read_else(".",PT_TOKEN);
		}

		else if(char_now=='*'){
			read_else("*",MULT_TOKEN);
		}

		else if(char_now=='/'){
			read_else("/",DIV_TOKEN);
		}

		else if(char_now==','){
			read_else(",",VIR_TOKEN);
		}

		else if(char_now=='['){
			read_else("[",CROCHETOU_TOKEN);
		}

		else if(char_now==']'){
			read_else("]",CROCHETFER_TOKEN);
		}

		else if(char_now=='<'){
			char_now=fgetc(file);

			if(char_now=='-'){
				read_else("<-",AFF_TOKEN);
			}

			else if(char_now=='='){
				read_else("<=",INFEG_TOKEN);	
			}

			

			else{
				read_else("<",INF_TOKEN);
				if(isdigit(char_now)){
					read_number(file);
				}
				else if(isalpha(char_now)){
					read_word(file);
				}	
					
			}
				
			
		}

		else if(char_now=='>'){
			char_now=fgetc(file);
			if(char_now=='='){
				read_else(">=",SUPEG_TOKEN);	
			}
			else{
				read_else(">",SUP_TOKEN);
			}
		}

		else if(char_now=='('){
			read_else("(",PO_TOKEN);
		}

		else if(char_now==')'){
			read_else(")",PF_TOKEN);
		}

		else if(char_now=='{'){
			read_else("{",ACOUV_TOKEN);
		}

		else if(char_now=='}'){
			read_else("}",ACF_TOKEN);
		}
	
		else if(char_now==EOF){
			read_else("EOF",FIN_TOKEN);	
		}


	}

}