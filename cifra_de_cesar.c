#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char * limD = &(alfabeto[25]);
char * limE = alfabeto;

void codificar(char *, int);
void decodificar(char *, int);

int main()
{
    char * string;
    int chave;
    int operacao;

    string = (char *) malloc(10000 * sizeof(char));

    if(string == NULL) {
        printf("Erro inesperado, encerrando o programa.\n");
        exit(1);
    }

    printf("CIFRA DE CESAR\n");
    printf("==============\n\n");

    printf("Dica: A conversao em cifra de cesar fica melhor executada quando:\nNao sao utlizados caracteres alem de letras;\nAs letras estao todas maiusculas ou minusculas.\n\n");
    printf("Instrucoes:\n");
    printf("A frase nao pode conter mais que 10000 caracteres;\nA chave deve ser um numero natural.\n");
    printf("Desobedecer as intrucoes implicara num mal funcionamento do programa.\n");
    printf("Se precisar forcar parada do programa, pressione Ctrl + C.\n\n");

    do {
        printf("O que deseja fazer?\n");
        printf("(1) Codificar uma frase    (2) Decodificar uma frase    (0) Encerrar o programa\n");
        printf("-> ");
        scanf("%d", &operacao);

        if(operacao) {
            printf("\nDigite a frase:\n");
            printf("-> ");
            scanf("%*c%[^\n]", string);
            printf("Digite a chave:\n");
            printf("-> ");
            scanf("%d", &chave);
            printf("\n");

            switch(operacao) {
                case 1: codificar(string, chave); break;
                case 2: decodificar(string, chave); break;
            }

            printf("Resultado: %s\n\n", string);

            printf("================================\n\n");
        }
    } while(operacao);

    free(string);

    return 0;
}

void codificar(char * string, int chave) {
    char * pointerS = string;
    char * pointerA = alfabeto;

    
    for(int i = 0; i < strlen(string); i++) {
        if(isupper(*pointerS)) {
            for(int j = 0; j < 26; j++) {
                if(*pointerS == toupper(*pointerA)) {
                    for(int k = 0; k < chave; k++) {
                        if(pointerA == limD) pointerA = limE;
                        else pointerA++;
                    }
                    *pointerS = toupper(*pointerA);
                    break;
                } else {
                    if(pointerA == limD) pointerA = limE;
                    else pointerA++;
                }
            }
        } else if(islower(*pointerS)) {
            for(int j = 0; j < 26; j++) {
                if(*pointerS == tolower(*pointerA)) {
                    for(int k = 0; k < chave; k++) {
                        if(pointerA == limD) pointerA = limE;
                        else pointerA++;
                    }
                    *pointerS = tolower(*pointerA);
                    break;
                } else {
                   if(pointerA == limD) pointerA = limE; 
                   else pointerA++;
                }
            }
        }
        pointerS++;
    }
}

void decodificar(char * string, int chave) {
    char * pointerS = string;
    char * pointerA = alfabeto;

    
    for(int i = 0; i < strlen(string); i++) {
        if(isupper(*pointerS)) {
            for(int j = 0; j < 26; j++) {
                if(*pointerS == toupper(*pointerA)) {
                    for(int k = 0; k < chave; k++) {
                        if(pointerA == limE) pointerA = limD;
                        else pointerA--;
                    }
                    *pointerS = toupper(*pointerA);
                    break;
                } else {
                    if(pointerA == limE) pointerA = limD;
                    else pointerA--;
                }
            }
        } else if(islower(*pointerS)) {
            for(int j = 0; j < 26; j++) {
                if(*pointerS == tolower(*pointerA)) {
                    for(int k = 0; k < chave; k++) {
                        if(pointerA == limE) pointerA = limD;
                        else pointerA--;
                    }
                    *pointerS = tolower(*pointerA);
                    break;
                } else {
                   if(pointerA == limE) pointerA = limD; 
                   else pointerA--;
                }
            }
        }
        pointerS++;
    }
}
