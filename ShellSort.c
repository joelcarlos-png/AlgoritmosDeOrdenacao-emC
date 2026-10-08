#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
}

int main(void){
    int tam = 20;
    int vet[tam];
    
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    int count;
    int *seq = calcularSequencia(tam, &count);
    printf("Sequencia utilizada: ");
    mostrarVet(seq, count);
}