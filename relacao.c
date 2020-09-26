#include <stdio.h>
#include <stdlib.h>

FILE* arquivoEntrada;
FILE* arquivoSaida;
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

    fprintf(arquivoSaida, "Reflexiva: ");
    for(int i = 0; i < numeroNos; i++){
        if(!matrizRelacoes[i][i]){
            if(indReflexiva){
                fprintf(arquivoSaida, "F\n");
                indReflexiva = 0;
            }
            fprintf(arquivoSaida, "(%d,%d); ", listaElementos[i], listaElementos[i]);
        }
    }

    if(indReflexiva){
        fprintf(arquivoSaida, "V");
    }
    return indReflexiva;
}

int verificaIrreflexiva(){
    int indIrreflexiva = 1;

    fprintf(arquivoSaida, "\nIrreflexiva: ");
    for(int i = 0; i < numeroNos; i++){
        if(matrizRelacoes[i][i]){
            if(indIrreflexiva){
                fprintf(arquivoSaida, "F\n");
                indIrreflexiva = 0;
            }
            fprintf(arquivoSaida, "(%d,%d); ", listaElementos[i], listaElementos[i]); 
        }
    }

    if(indIrreflexiva){
        fprintf(arquivoSaida, "V");
    }
    return indIrreflexiva;
}

int verificaSimetrica(){
    int indSimetrica = 1;

    fprintf(arquivoSaida, "\nSimétrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] && !matrizRelacoes[j][i]){
                if(indSimetrica){
                    fprintf(arquivoSaida, "F\n");
                    indSimetrica = 0;
                }
                fprintf(arquivoSaida, "(%d,%d); ", listaElementos[j], listaElementos[i]);
                 
            }
        }
    }

    if(indSimetrica){
        fprintf(arquivoSaida, "V");
    }
    return indSimetrica;
}

int verificaAntiSimetrica(){
    int indAntiSimetrica = 1;

    fprintf(arquivoSaida, "\nAnti-simétrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = i+1; j < numeroNos; j++){
            if(matrizRelacoes[i][j] && matrizRelacoes[j][i]){
                if(indAntiSimetrica){
                    fprintf(arquivoSaida, "F\n");
                    indAntiSimetrica = 0;
                }
                fprintf(arquivoSaida, "(%d,%d); (%d,%d); ",
                    listaElementos[i], listaElementos[j], listaElementos[j], listaElementos[i]);
            }
        }
    }

    if(indAntiSimetrica){
        fprintf(arquivoSaida, "V");
    }
    return indAntiSimetrica;
}

int verificaAssimetrica(){
    int indAssimetrica = 1;

    fprintf(arquivoSaida, "\nAssimétrica: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] == matrizRelacoes[j][i]){
                fprintf(arquivoSaida, "F");
                indAssimetrica = 0;
                return indAssimetrica;
            }
        }
    }

    fprintf(arquivoSaida, "V");
    return indAssimetrica;
}

int verificaTransitiva(){
    int indTransitiva = 1;

    fprintf(arquivoSaida, "\nTransitiva: ");
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            for(int z = 0; z < numeroNos; z++){
                if(matrizRelacoes[i][j] && matrizRelacoes[j][z] && !matrizRelacoes[i][z]){
                    if(indTransitiva){
                        fprintf(arquivoSaida, "F\n");
                        indTransitiva = 0;
                    }
                    fprintf(arquivoSaida, "(%d,%d); ", listaElementos[i], listaElementos[z]);
                    matrizRelacoes[i][z] = -1;
                }
            }
        }
    }
    
    if(indTransitiva){
        fprintf(arquivoSaida, "V");
    }
    return indTransitiva;
}

void imprimeFechoTransitivo(){
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] == 1 || matrizRelacoes[i][j] == -1){
                fprintf(arquivoSaida, " (%d,%d);", listaElementos[i], listaElementos[j]);
            }
        }
    }
}


int main(int argc, char **argv){
    //Começa leitura do arquivo entrada.txt
    arquivoEntrada = fopen("entrada.txt", "r");
    arquivoSaida = fopen("saida.txt", "w");

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

    fprintf(arquivoSaida, "\nRelação de equivalência: ");
    if(indReflexiva && indSimetrica && indTransitiva){
        fprintf(arquivoSaida, "V\n");
    }else{
        fprintf(arquivoSaida, "F\n");
    }

    fprintf(arquivoSaida, "Relação de ordem parcial: ");
    if(indReflexiva && indAntiSimetrica && indTransitiva){
        fprintf(arquivoSaida, "V\n");
    }else{
        fprintf(arquivoSaida, "F\n");
    }

    //Imprime fecho transitivo da relação
    fprintf(arquivoSaida, "Fecho transitivo da relação:");
    imprimeFechoTransitivo();

    //Finaliza escrita no arquivo de saída
    fclose(arquivoSaida);
    return 0;
}