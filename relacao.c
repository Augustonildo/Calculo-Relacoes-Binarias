#include <stdio.h>
#include <stdlib.h>

FILE* arquivoEntrada;
int **matrizRelacoes;
int *listaElementos;
int numeroNos;

void inicializaMatrizRelacoes(){
    fscanf(arquivoEntrada,"%d", &numeroNos);
    listaElementos = (int *) malloc (sizeof(int) * numeroNos);
    matrizRelacoes = (int **) malloc (sizeof(int *) * numeroNos);
    for(int i = 0; i < numeroNos; i++){
        fscanf(arquivoEntrada, " %d", &listaElementos[i]);
        matrizRelacoes[i] = (int *) malloc (sizeof(int) * numeroNos);
    }

    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            matrizRelacoes[i][j] = 0;
        }
    }
}

void preencheMatrizRelacoes(){
    int relacaoPontoA = 0;
    int relacaoPontoB = 0;
    while (!feof(arquivoEntrada))
    {
      fscanf(arquivoEntrada, "%d", &relacaoPontoA);
      fscanf(arquivoEntrada, "%d", &relacaoPontoB);
      matrizRelacoes[relacaoPontoA-listaElementos[0]][relacaoPontoB-listaElementos[0]] = 1;
    }
}

int verificaReflexiva(){
    int indReflexiva = 1;

    printf("Reflexiva: ");
    for(int i = 0; i < numeroNos; i++){
        if(!matrizRelacoes[i][i]){
            if(indReflexiva){
                printf("F\n");
                indReflexiva = 0;
            }
            printf("(%d,%d); ", listaElementos[i], listaElementos[i]);
        }
    }

    if(indReflexiva){
        printf("V");
    }
    return indReflexiva;
}

int verificaIrreflexiva(){
    int indIrreflexiva = 1;

    printf("\nIrreflexiva: ");
    for(int i = 0; i < numeroNos; i++){
        if(matrizRelacoes[i][i]){
            if(indIrreflexiva){
                printf("F\n");
                indIrreflexiva = 0;
            }
            printf("(%d,%d); ", listaElementos[i], listaElementos[i]); 
        }
    }

    if(indIrreflexiva){
        printf("V");
    }
    return indIrreflexiva;
}

int verificaSimetrica(){
    int indSimetrica = 1;

    printf("\nSimetrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] && !matrizRelacoes[j][i]){
                if(indSimetrica){
                    printf("F\n");
                    indSimetrica = 0;
                }
                printf("(%d,%d); ", listaElementos[j], listaElementos[i]);
                 
            }
        }
    }

    if(indSimetrica){
        printf("V");
    }
    return indSimetrica;
}

int verificaAntiSimetrica(){
    int indAntiSimetrica = 1;

    printf("\nAnti-simetrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = i+1; j < numeroNos; j++){
            if(matrizRelacoes[i][j] && matrizRelacoes[j][i]){
                if(indAntiSimetrica){
                    printf("F\n");
                    indAntiSimetrica = 0;
                }
                printf("(%d,%d); (%d,%d); ",
                    listaElementos[i], listaElementos[j], listaElementos[j], listaElementos[i]);
            }
        }
    }

    if(indAntiSimetrica){
        printf("V");
    }
    return indAntiSimetrica;
}

int verificaAssimetrica(){
    int indAssimetrica = 1;

    printf("\nAssimetrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] && matrizRelacoes[j][i]){
                printf("F");
                indAssimetrica = 0;
                return indAssimetrica;
            }
        }
    }

    printf("V");
    return indAssimetrica;
}

int verificaTransitiva(){
    int indTransitiva = 1;

    printf("\nTransitiva: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            for(int z = 0; z < numeroNos; z++){
                if(matrizRelacoes[i][j] && matrizRelacoes[j][z] && !matrizRelacoes[i][z]){
                    if(indTransitiva){
                        printf("F\n");
                        indTransitiva = 0;
                    }
                    printf("(%d,%d); ", listaElementos[i], listaElementos[z]);
                    matrizRelacoes[i][z] = -1;
                }
            }
        }
    }
    
    if(indTransitiva){
        printf("V");
    }
    return indTransitiva;
}

void imprimeFechoTransitivo(){
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] == 1 || matrizRelacoes[i][j] == -1){
                printf(" (%d,%d);", listaElementos[i], listaElementos[j]);
            }
        }
    }
}


int main(int argc, char **argv){
    //Começa leitura do arquivo entrada.txt
    arquivoEntrada = fopen("entrada.txt", "r");

    //Aloca espaço para matriz e vetor, preenchendo os elementos
    inicializaMatrizRelacoes();

    //Lê relações e preenche matriz
    preencheMatrizRelacoes();

    //Finaliza leitura do arquivo de entrada
    fclose(arquivoEntrada);

    //Realiza validações de características
    int indReflexiva = verificaReflexiva();
    int indIrreflexiva = verificaIrreflexiva();
    int indSimetrica = verificaSimetrica();
    int indAntiSimetrica = verificaAntiSimetrica();
    int indAssimetrica = verificaAssimetrica();
    int indTransitiva = verificaTransitiva();

    printf("\nRelacao de equivalencia: ");
    if(indReflexiva && indSimetrica && indTransitiva){
        printf("V\n");
    }else{
        printf("F\n");
    }

    printf("Relacao de ordem parcial: ");
    if(indReflexiva && indAntiSimetrica && indTransitiva){
        printf("V\n");
    }else{
        printf("F\n");
    }

    //Imprime fecho transitivo da relação
    printf("Fecho transitivo da relacao:");
    imprimeFechoTransitivo();
    
    return 0;
}