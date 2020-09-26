#include <stdio.h>

int **matrizRelacoes;
int *listaElementos;
int numeroNos;

int verificaReflexiva(){
    int indReflexiva = 1;

    //TODO: PRINT "1. Reflexiva: "
    for(int i = 0; i < numeroNos; i++){
        if(!matrizRelacoes[i][i]){
            if(indReflexiva){
                //TODO: Print "F \n"
                indReflexiva = 0;
            }
            //TODO: Print: "(" + listaElementos[i] + "," + listaElementos[i] + "); "; 
        }
    }

    if(indReflexiva){
        //TODO: Print "V \n"
    }
    return indReflexiva;
}

int verificaIrreflexiva(){
    int indIrreflexiva = 1;

    //TODO: Print "2. Irreflexiva: "
    for(int i = 0; i < numeroNos; i++){
        if(matrizRelacoes[i][i]){
            if(indIrreflexiva){
                //TODO: Print "F \n"
                indIrreflexiva = 0;
            }
            //TODO: Print: "(" + listaElementos[i] + "," + listaElementos[i] + "); "; 
        }
    }

    if(indIrreflexiva){
        //TODO: Print "V \n"
    }
    return indIrreflexiva;
}

int verificaSimetrica(){
    int indSimetrica = 1;

    //TODO: Print "3. Simetrica: "
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] != matrizRelacoes[j][i]){
                if(indSimetrica){
                    //TODO: Print "F \n"
                    indSimetrica = 0;
                }
                if(matrizRelacoes[i][j]){
                    //TODO: Print: "(" + listaElementos[i] + "," + listaElementos[j] + "); ";
                }else if(matrizRelacoes[j][i]){
                    //TODO: Print: "(" + listaElementos[j] + "," + listaElementos[i] + "); ";
                }
                 
            }
        }
    }

    if(indSimetrica){
        //TODO: Print "V \n";
    }
    return indSimetrica;
}

int verificaAntiSimetrica(){
    int indAntiSimetrica = 1;

    //TODO: Print "4. Anti-simetrica: "
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(i != j){
                if(matrizRelacoes[i][j] == matrizRelacoes[j][i]){
                    if(indAntiSimetrica){
                        //TODO: Print "F \n"
                        indAntiSimetrica = 0;
                    }
                    //TODO: Print: "(" + listaElementos[i] + "," + listaElementos[j] + ") e (" + listaElementos[j] + "," + listaElementos[i] + "); ";
                }
            }
        }
    }

    if(indAntiSimetrica){
        //TODO: Print "V \n";
    }
    return indAntiSimetrica;
}

int verificaAssimetrica(){
    int indAssimetrica = 1;

    //TODO: Print "5. Assimetrica: "
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            if(matrizRelacoes[i][j] == matrizRelacoes[j][i]){
                if(indAssimetrica){
                    //TODO: Print "F \n"
                    indAssimetrica = 0;
                }
            }
        }
    }

    if(indAssimetrica){
        //TODO: Print "V \n";
    }
    return indAssimetrica;
}

int verificaTransitiva(){
    int indTransitiva = 1;

    //TODO: Print "4. Anti-simetrica: "
    for(int i = 0; i < numeroNos; i++){
        for(int j = 0; j < numeroNos; j++){
            for(int z = 0; z < numeroNos; z++){
                if((matrizRelacoes[i][j] == matrizRelacoes[j][z]) && !matrizRelacoes[i][z]){
                    if(indTransitiva){
                        //TODO: Print "F \n"
                        indTransitiva = 0;
                    }
                }
            }
        }
    }

    if(indTransitiva){
        //TODO: Print "V \n";
    }
    return indTransitiva;
}



int main(int argc, char **argv){
    //TODO: Ler primeira linha, preencher numeroNos e listaElementos
    matrizRelacoes = (int **) malloc (sizeof(int *) * numeroNos);
    for(int i = 0; i < numeroNos; i++){
        matrizRelacoes[i] = (int *) malloc (sizeof(int) * numeroNos);
    }

    //TODO: LOOP para ler linha e preencher valor corresponde na matriz


    //Realiza validações de características
    //TODO: PRINT "Propriedades \n"
    int indReflexiva = verificaReflexiva();
    int indIrreflexiva = verificaIrreflexiva();
    int indSimetrica = verificaSimetrica();
    int indAntiSimetrica = verificaAntiSimetrica();
    int indAssimetrica = verificaAssimetrica();
    int indTransitiva = verificaTransitiva();

    //TODO: Print "Relação de equivalência: "
    if(indReflexiva && indSimetrica && indTransitiva){
        //TODO: Print "V \n"
    }else{
        //TODO: Print "F \n"
    }

    //TODO: Print "Relação de ordem parcial: "
    if(indReflexiva && indAntiSimetrica && indTransitiva){
        //TODO: Print "V \n"
    }else{
        //TODO: Print "F \n"
    }

    //TODO: Imprimir fecho transitivo da relação
    return 0;
}