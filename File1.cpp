#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


#define SIZE 154

char TOLOWER(char a){
	 if (a>='A' && a<='Z'){
		a+=32;
	 }
	 return a;
}


int  STRLEN(const char *str){
	int lenght = 0;
    while (*str)
	{
		lenght++;
		str++;
	}
	return lenght;
}


char* STRCPY(char* main_str, const char* copied_str){
	while (*main_str++ = *copied_str++){
	}
	return main_str;
}


char* STRCAT(char* main_str, const char* attached_str){
	main_str += STRLEN(main_str);
	while (*main_str++ = *attached_str++){
	}
	return main_str;
}


int proverka(char *str ,int size,  int start=0){
	if (start>(size-start-1)) {
		return 0;
	}
	if ((str[start]==str[size-start-1])||(str[start]==(str[size-start-1]-32))||((str[start]-32)==str[size-start-1])) {
		start++;
		return proverka(str, size, start);
	}
	if (str[start]!=str[size-start-1]) {
		return 1;
	}
    return -1;
}


int _tmain(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	FILE* file;
	file = fopen("D:\\2semestr\\lab3.txt", "r");
	if (file == NULL) {
		printf ("Ошибка открытия файла\n");
		getch();
		return -1;
	}
	int index=1;
	char **str;
	while(!feof(file)){
		if(index==1){
			if(!(str=(char**)malloc(sizeof (char*)))){
				printf( "Can't allocate memory\n" );
				getch();
				exit(EXIT_FAILURE);
			}


		}
		else if(index>1){
			if(!(str=(char**)realloc(str,sizeof(char*)*index))){
				printf( "Can't allocate memory\n" );
				getch();
				exit(EXIT_FAILURE);
			}
		}
		if(!(str[index-1]=(char*)malloc(SIZE*sizeof(char)))){
            printf( "Can't allocate memory\n" );
			getch();
			exit(EXIT_FAILURE);
		}
		fgets(str[index-1],SIZE, file);
		index++;
	}
	index--;
	char **newstr;
	int newindex=1;
	for(int j=0;j<index;j++){
		for(int fixed_ind=0;str[j][fixed_ind]!=0;fixed_ind++){
			if(str[j][fixed_ind]!=' '&&(fixed_ind==0||str[j][fixed_ind-1]==' ')){
				while(str[j][fixed_ind]==','||str[j][fixed_ind]=='!'||str[j][fixed_ind]=='?'||str[j][fixed_ind]=='.'||str[j][fixed_ind]=='>'
					  ||str[j][fixed_ind]=='<'||str[j][fixed_ind]=='('||str[j][fixed_ind]==')'
					  ||str[j][fixed_ind]==':'||str[j][fixed_ind]==';'||str[j][fixed_ind]=='-'){

					fixed_ind++;
				}
				if(str[j][fixed_ind]==' '){
					continue;
				}
				else if(str[j][fixed_ind]==0){
					break;
				}
				else if(str[j][fixed_ind]=='\n'){
					str[j][fixed_ind]=0;
					break;
				}
				if(newindex==1){
					if(!(newstr=(char**)malloc(sizeof (char*)))){
						printf( "Can't allocate memory\n" );
						getch();
						exit(EXIT_FAILURE);
					}

				}
				else if(newindex>1){
					if(!(newstr=(char**)realloc(newstr,sizeof(char*)*newindex))){
						printf( "Can't allocate memory\n" );
						getch();
						exit(EXIT_FAILURE);
					}
                }
				if(!(newstr[newindex-1]=(char*)malloc(SIZE*sizeof(char)))){
					printf( "Can't allocate memory\n" );
					getch();
					exit(EXIT_FAILURE);
				}
				int variable_size=0;
				while(str[j][fixed_ind]!='\n'&&str[j][fixed_ind]!=' '&&str[j][fixed_ind]!=','&&str[j][fixed_ind]!=0
					  &&str[j][fixed_ind]!='!'&&str[j][fixed_ind]!='?'&&str[j][fixed_ind]!='.'&&str[j][fixed_ind]!='>'&&str[j][fixed_ind]!='<'
					  &&str[j][fixed_ind]!='('&&str[j][fixed_ind]!=')'&&str[j][fixed_ind]!=':'&&str[j][fixed_ind]!=';'
					  &&str[j][fixed_ind]!='-'){

					newstr[newindex-1][variable_size]=str[j][fixed_ind];
					fixed_ind++;
					variable_size++;
				}
				newstr[newindex-1][variable_size]=0;
				newindex++;
			}
        }
    }
	newindex--;
	int bigsize=0;
	for(int j=0;j<newindex;j++){
		bigsize+=STRLEN(newstr[j]);
	}
	char* palindrom;
	if(!(palindrom=(char*)malloc(bigsize*sizeof(char)))){
        printf( "Can't allocate memory\n" );
		getch();
		exit(EXIT_FAILURE);
	}
	for(int j=newindex-1;j>=0;j--){
	for(int fixed_lendgth=0;fixed_lendgth<=j;fixed_lendgth++){
		for(int fixed_kolvo=fixed_lendgth;fixed_kolvo<=j;fixed_kolvo++){
			STRCAT(palindrom,newstr[fixed_kolvo]);

		}
		int opredelitel=proverka(palindrom,STRLEN(palindrom));
		if(opredelitel==0){
			for(int fixed_kolvo=fixed_lendgth;fixed_kolvo<=j;fixed_kolvo++){
				printf("%s ",newstr[fixed_kolvo]);
			}
            printf("\n");
		}
		palindrom[0]=0;
	}
	}
	free(palindrom);
	for(int j=0;j<newindex;j++){
		free(newstr[j]);
	}
	free(newstr);
	for(int j=0;j<index;j++){
        free(str[j]);
	}
	free(str);
	fclose(file);
	getch();
	return 0;
}
