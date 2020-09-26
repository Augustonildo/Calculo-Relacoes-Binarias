#include <stdio.h>
#include <stdlib.h>

int **matrizRelacoes;
int *listaElementos;
int numeroNos;

void limpaValoresMatrizRelacoes(){
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            matrizRelacoes[i][j] = 0;
        }
    }
}

int verificaReflexiva(){
    int indReflexiva = 1;

    printf("1. Reflexiva: ");
    for(int i = 0; i < numeroNos; i++){
        if(!matrizRelacoes[i][i]){
            if(indReflexiva){
                printf("F \n   ");
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

    printf("\n2. Irreflexiva: ");
    for(int i = 0; i < numeroNos; i++){
        if(matrizRelacoes[i][i]){
            if(indIrreflexiva){
                printf("F \n   ");
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

    printf("\n3. Simetrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] != matrizRelacoes[j][i]){
                if(indSimetrica){
                    printf("F \n   ");
                    indSimetrica = 0;
                }
                if(matrizRelacoes[i][j]){
                    printf("(%d,%d); ", listaElementos[i], listaElementos[j]);
                }else if(matrizRelacoes[j][i]){
                    printf("(%d,%d); ", listaElementos[j], listaElementos[i]);
                }
                 
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

    printf("\n4. Anti-simetrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = i+1; j < numeroNos; j++){
            if(matrizRelacoes[i][j] && matrizRelacoes[j][i]){
                if(indAntiSimetrica){
                    printf("F \n   ");
                    indAntiSimetrica = 0;
                }
                printf("(%d,%d) e (%d,%d); ",
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

    printf("\n5. Assimetrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] == matrizRelacoes[j][i]){
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

    printf("\n6. Transitiva: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            for(int z = 0; z < numeroNos; z++){
                if((matrizRelacoes[i][j] == matrizRelacoes[j][z]) && !matrizRelacoes[i][z]){
                    printf("F \n");
                    indTransitiva = 0;
                    return indTransitiva;
                }
            }
        }
    }

    printf("V \n");
    return indTransitiva;
}



int main(int argc, char **argv){
    //Começa leitura do arquivo entrada.txt
    FILE* arquivo = fopen("entrada.txt", "r");

    //Aloca espaço para matriz e vetor, preenchendo os elementos
    fscanf(arquivo,"%d", &numeroNos);
    listaElementos = (int *) malloc (sizeof(int) * numeroNos);
    matrizRelacoes = (int **) malloc (sizeof(int *) * numeroNos);
    for(int i = 0; i < numeroNos; i++){
        fscanf(arquivo, " %d", &listaElementos[i]);
        matrizRelacoes[i] = (int *) malloc (sizeof(int) * numeroNos);
    }
    limpaValoresMatrizRelacoes();

    //Lê relações e preenche matriz
    int relacaoPontoA = 0;
    int relacaoPontoB = 0;
    while (!feof(arquivo))
    {
      fscanf(arquivo, "%d", &relacaoPontoA);
      fscanf(arquivo, "%d", &relacaoPontoB);
      matrizRelacoes[relacaoPontoA-listaElementos[0]][relacaoPontoB-listaElementos[0]] = 1;
    }

    //Finaliza leitura do arquivo de entrada
    fclose(arquivo);

    //Realiza validações de características
    printf("Propriedades \n");
    int indReflexiva = verificaReflexiva();
    int indIrreflexiva = verificaIrreflexiva();
    int indSimetrica = verificaSimetrica();
    int indAntiSimetrica = verificaAntiSimetrica();
    int indAssimetrica = verificaAssimetrica();
    int indTransitiva = verificaTransitiva();

    printf("\nRelacao de equivalencia: ");
    if(indReflexiva && indSimetrica && indTransitiva){
        printf("V \n");
    }else{
        printf("F \n");
    }

    printf("Relacao de ordem parcial: ");
    if(indReflexiva && indAntiSimetrica && indTransitiva){
        printf("V \n");
    }else{
        printf("F \n");
    }

    //TODO: Imprimir fecho transitivo da relação

    
    return 0;
}