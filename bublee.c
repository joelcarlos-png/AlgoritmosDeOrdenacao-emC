#include <stdio.h>

void mostrarVet(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void bubble(int *vet, int tam){
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

int main(){
    int vet[] = {5,8,12,3,4,22,68,85,90,100};
    int tam = sizeof(vet) / sizeof(vet[0]);

    mostrarVet(vet, tam);
    bubbleInvertido(vet, tam);
    mostrarVet(vet, tam);
    bubble(vet, tam);
    mostrarVet(vet, tam);

}