#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

//CONST DE CORES
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m" /*reset*/
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */

//CONST DE BUFFER
#define MAX_STR_LEN 256
#define MAX_EXIB 3700 // ALTERAR DE ACORDO COM O QUE IRÁ PRECISAR PARA NÃO ESTRAPOLAR A MEMORIA


struct structList{
    char *codigo_ocorrencia;
    char *fator_nome;
    char *fator_aspecto;
    char *fator_condicionante;
    char *fator_area;
};

/* FUNÇÕES AUX */
	char readAdamFile();
	char readOriginalFile();

int main()
{   
    system("mode con:cols=200");
    setlocale(LC_ALL, "Portuguese");    
    system("color 05");
    printf("\n");
    printf(GREEN);
    printf(" Sistema desenvolvido por: ADAM ALMEIDA DE OLIVEIRA\n");
    printf(" Disciplina: Estrutura de dados II\n");
    printf(" Ano: 2020\n");
    printf(" Objetivo: Leitura e ordenação em Shellsort\n");
    
    //inicio menu
    char opcao;
    
    int countResult = count();
    printf(BOLDWHITE " Total: %i resultados obtidos \n",countResult );
    
    printf(YELLOW "\n Escolha o que deseja fazer \n\n [1] Exibir dados Originais \n [2] Ordenar pela primeira coluna \n [3] Sair do programa \n\n");
	 
	opcao = getch();
	
    switch (opcao) {
	    case '1':
	    	
	    //exibe arquivo original
	    printf(BOLDWHITE "\n\n %-7s  | %-40s | %-30s | %-25s | %s\n","Cod" ,  "Fator Nome", "Fator Aspecto", "Fator Condicionante", "Fator Area");
	    readOriginalFile();
	    
	        break;
	    case '2':
	    
	    //exibe ordenação
		printf(BOLDWHITE "\n\n %-7s  | %-40s | %-30s | %-25s | %s\n","Cod" ,  "Fator Nome", "Fator Aspecto", "Fator Condicionante", "Fator Area");
	    readAdamFile();
		
	        break;
		case '3':
	    	
	        system("cls");
	        printf("\n Voce optou por sair, encerrando programa...\n");
	        Sleep(3000); // 3 seg antes de encerrar o programa
			exit(0);
			
	    default:
	    	
	        printf("\n Você deve escolher uma opção válida\n");
	        printf("\n Precione qualquer tecla para voltar ao menu\n");
	        system("pause");
    }


    system("pause");
    return 0;
}

char readOriginalFile()
{
    /* FileStream no arquivo */
    FILE *adamFile;

    /* Alocação de Buffer por linha do arquivo */
    char c, base = '\n';
    int  x;
    char *linha = malloc(MAX_STR_LEN);

    char nome[MAX_EXIB][255];
    
    /* caso não tenha espaço alocado retorna um erro */
    if (linha == NULL) {
        printf ( BOLDRED "\n Sem memoria suficiente para alocar\n" RESET);
        return 1;
    }
    
    if ( ( adamFile = fopen( "fator_contribuinte.csv", "r" ) ) == NULL ) //Leitura do arquivo
    {
        printf( BOLDRED "\n Não foi possivel abrir o arquivo.\n" RESET );
        return 0;
    }
    
    while(fread (&c, sizeof(char), 1, adamFile))//Lendo o linhas 1 por 1
	{
        if(c == base) {
            while (fgets(linha, sizeof(nome[x]), adamFile) != NULL)
   			{
   				char *codigo_ocorrencia;
   				char *fator_nome; 
   				char *fator_aspecto;
   				char *fator_condicionante;
   				char *fator_area;
   				char *tmp;
   				
   				tmp = strtok(linha, ";");
   				codigo_ocorrencia = tmp;

   				tmp = strtok(NULL, ";");
   				fator_nome = tmp;
   				
   				tmp = strtok(NULL, ";");
				fator_aspecto = tmp;
				
				tmp = strtok(NULL, ";");
				fator_condicionante = tmp;
				
				tmp = strtok(NULL, ";");
				fator_area = tmp;
				
				printf( CYAN " %-7s  | %-40s | %-30s | %-25s | %s",codigo_ocorrencia,fator_nome,fator_aspecto,
				fator_condicionante,fator_area);

            } 	
        }
    	
	}// fechmaneto do primeiro while

    //liberando o buffer;
    fclose(adamFile);
    return 0;
	
}

char readAdamFile()
{
    /* FileStream no arquivo */
    FILE *adamFile;

    /* Alocação de Buffer por linha do arquivo */
    char c, base = '\n';
    int  x;
    char *linha = malloc(MAX_STR_LEN);
    char *tmp;
    char nome[MAX_EXIB][255];
    
    /* caso não tenha espaço alocado retorna um erro */
    if (linha == NULL) {
        printf ( BOLDRED "\n Sem memoria suficiente para alocar\n" RESET);
        return 1;
    }
    
    if ( ( adamFile = fopen( "fator_contribuinte.csv", "r" ) ) == NULL ) //Leitura do arquivo
    {
        printf( BOLDRED "\n Não foi possivel abrir o arquivo.\n" RESET );
        return 0;
    }
    
    while(fread (&c, sizeof(char), 1, adamFile))//Lendo o linhas 1 por 1
	{
        if(c == base) {
            while (fgets(linha, sizeof(nome[x]), adamFile) != NULL)
   			{
	            strcpy(nome[x], linha);
	            x++;			
            } 
        }
	}// fechmaneto do primeiro while
	
    //inicio shellsort

	int total = x-1;
	struct structList lista_adam[total];
	int pri, y, r;
	char aux[80];

    for (pri = 0; pri <= total; pri++)
		{	
			for(y = pri+1; y <= total; y++){
		    
				r = strcmp(nome[pri], nome[y]);
				if (r > 0){		
					strcpy(aux, nome[pri]);
					strcpy(nome[pri], nome[y]);
					strcpy(nome[y], aux);
				
				}
			}
				
   				char *tmp;
   				tmp = strtok(nome[pri], ";");
   				lista_adam[pri].codigo_ocorrencia = tmp;

   				tmp = strtok(NULL, ";");
   				lista_adam[pri].fator_nome = tmp;
   				
   				tmp = strtok(NULL, ";");
				lista_adam[pri].fator_aspecto = tmp;
				
				tmp = strtok(NULL, ";");
				lista_adam[pri].fator_condicionante = tmp;
				
				tmp = strtok(NULL, ";");
				lista_adam[pri].fator_area = tmp;
				
				printf( CYAN " %-7s  | %-40s | %-30s | %-25s | %s",lista_adam[pri].codigo_ocorrencia,lista_adam[pri].fator_nome,lista_adam[pri].fator_aspecto,
				lista_adam[pri].fator_condicionante,lista_adam[pri].fator_area);
			
		}//fim shellsort

    //liberando o buffer;
    fclose(adamFile);
    return 0;
	
}

int count()
{	
	FILE *arq;
    char c, letra = '\n';
    int vezes;
    arq = fopen("fator_contribuinte.csv","r");

        //Lendo o arquivo 1 por 1
        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == letra) {
                vezes++;
            }
        } 

    return vezes + 1;

    fclose(arq);
}
