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

void BubbleSort(int *vet, int tam){
    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(vet[j] > vet[j + 1]){
                int aux = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void SelectionSort(int *vet, int tam){
    for(int i = 0; i < tam - 1; i++){
        int indiceTroca = i;
        for(int j = i + 1; j < tam; j++){
            if(vet[j] < vet[indiceTroca]){
                indiceTroca = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[indiceTroca];
        vet[indiceTroca] = aux;
    }
}

void InsertionSort(int *vet, int tam){
    for (int i = 1; i < tam; i++) {
        int atual = vet[i];
        int j;

        for (j = i - 1; j >= 0 && vet[j] > atual; j--) {
            vet[j + 1] = vet[j];
        }

        vet[j + 1] = atual;
    }
}

void bubbleInvertido(int *vet, int tam){
    for(int i = tam - 1; i >= 0; i--){
        for(int j = tam - 1; j > tam - i - 1; j--){
            if(vet[j] > vet[j - 1]){
                int aux = vet[j - 1];
                vet[j - 1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

bool verificarOrdenacao(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        if(i > i + 1) return false;
    }
    return true;
}

int main(){
    int tam = 20;
    int vet[tam];

    srand((unsigned) time(NULL));

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    printf("Vetor para BubbleSort: \nAntes:  ");
    mostrarVet(vet, tam);
    BubbleSort(vet, tam);
    printf("Depois: ");
    mostrarVet(vet, tam);
    if(verificarOrdenacao(vet, tam)) printf("Vetor ESTA ordenado!!\n");
    else printf("Vetor NAO esta ordenado!!\n");

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    printf("\nVetor para SelectionSort: \nAntes:  ");
    mostrarVet(vet, tam);
    SelectionSort(vet, tam);
    printf("Depois: ");
    mostrarVet(vet, tam);
    if(verificarOrdenacao(vet, tam)) printf("Vetor ESTA ordenado!!\n");
    else printf("Vetor NAO esta ordenado!!\n");

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    printf("\nVetor para InsertionSort: \nAntes:  ");
    mostrarVet(vet, tam);
    InsertionSort(vet, tam);
    printf("Depois: ");
    mostrarVet(vet, tam);
    if(verificarOrdenacao(vet, tam)) printf("Vetor ESTA ordenado!!\n");
    else printf("Vetor NAO esta ordenado!!\n");
}