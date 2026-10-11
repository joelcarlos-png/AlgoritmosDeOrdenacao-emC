#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

void mostrarVet(int *vet, int tam){
    printf("[");
    for(int i = 0; i < tam; i++){
        printf("%d", vet[i]);
        if(i != tam - 1){
            printf(", ");
        }
    }
    printf("]");
    printf("\n");
}

void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int *calcularSequencia(int tam, int *count){
    int result = 1;
    int ante = 1;
    int *seq = NULL;
    *count = 0;

    for(int i = 1; result <= tam; i++){
        seq = realloc(seq, (*count + 1) * sizeof(int));
        seq[*count] = result;
        (*count)++;

        result = 3 * ante + 1;
        ante = result;
    }

    return seq;
}

void ShellSort(int *vet, int tam){
    int tamSeq;
    int *seq = calcularSequencia(tam, &tamSeq);
    printf("\nSequencia Utilizada: ");
    mostrarVet(seq, tamSeq);
    
    for(int i = tamSeq - 1; i >= 0; i--){
        int pulo = seq[i];
        for(int k = 0; k < pulo && k + pulo < tam; k++){
            for(int p = 0; k + p * pulo < tam; p++){       
                int atual = p;

                while (atual > 0 && vet[k + (atual - 1) * pulo] > vet[k + atual * pulo]) {
                    trocar(&vet[k + (atual - 1) * pulo], &vet[k + atual * pulo]);
                    atual--;
                }
            }
        }
    }
}

int main(void){
    int tam = 20;
   int *vet = malloc(tam * sizeof(int));

    if (vet == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    printf("Antes:  ");
    mostrarVet(vet, tam);  
    
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    ShellSort(vet, tam);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Depois: ");
    mostrarVet(vet, tam);

    double temp = tempo;
    int casas = 0;
    while(temp < 1.0 && temp > 0.0){
        temp *= 10.0;
        casas++;
    }

    if(tempo > 0.0){
        printf("Tempo de execucao: %.*f",casas + 40,  tempo);
    }else{
        printf("Tempo de execucao: 0 segundos (Rapido demais para medir precisamente)");
    }
}