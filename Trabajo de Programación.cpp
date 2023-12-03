#include<iostream>
#include<ctime>
#include<cstdlib>
#include<chrono>

void quicksort(int arrayqs[],int princ,int fin);

void print(int valors[],int num){
    for(int i=0;i<num;i++){
        printf("%d  ",valors[i]);
    }
}
void bubbleSort(int arrayb[],int num);

int main(){
    int num;
    srand(time(NULL));
    printf("introduzca la cantidad de valores a ordenar: ");
    scanf("%d",&num);
    int def;
    printf("desea escribir los numeros o desea generarlos aleatoriamente?\n1-Definirlos\n2-Aleatorios\n");
    scanf("%d",&def);
    
    int arrayb[num],arrayqs[num]; 

    switch(def){
        case 1:
        printf("Introduzca los valores:\n");
        for(int o=0;o<num;o++){
            printf("Valor %d del arreglo\n",o);
            scanf("%d",&arrayb[o]);

        }
        break;
        case 2:
         for(int i=0;i<num;i++){
        arrayb[i]=rand();
    
    }

        break;
        default:
        printf("Era 1 o 2\n");
        break;
    }




    
    for(int i=0;i<num;i++){
      
        arrayqs[i]=arrayb[i];
    }








    printf("Valores desordenados:\n");
    print(arrayb,num);
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arrayb,num);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    printf("\nValores ordenados por el metodo burbuja:\n");
    print(arrayb,num);
    int princ=0;
    start = std::chrono::high_resolution_clock::now();
    quicksort(arrayqs,princ,num-1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end - start;
    printf("\nValores ordenados por quick sort:\n");
    print(arrayqs,num);
    printf("\nEl tiempo del metodo burbuja fue de %f y el de quick sort fue de %f \n ",elapsed.count(),elapsed2.count());
    
    system ("pause");
    return 0;
}

void bubbleSort(int arrayb[],int num){
    int aux,i,j;
    for(i=0;i<num-1;i++){
        for(j=0;j<num-i-1;j++){
            if(arrayb[j]>arrayb[j+1]){
                aux=arrayb[j];
                arrayb[j]=arrayb[j+1];
                arrayb[j+1]=aux;
            }
        }
    }
}

void quicksort(int arrayqs[],int princ, int fin) {
    int izq,der,pivote,aux;
    izq=princ;
    der=fin;
    pivote=arrayqs[(izq+der)/2];
    do{
        while(arrayqs[izq]<pivote && izq<fin) izq++;
        while(pivote<arrayqs[der] && der > princ) der--;
        if(izq <= der){
            aux= arrayqs[izq];
            arrayqs[izq]=arrayqs[der];
            arrayqs[der]=aux;
            izq++;
            der--;
        }
    }while(izq<=der);
    if(princ < der) quicksort(arrayqs, princ, der);
    if(fin > izq) quicksort(arrayqs,izq,fin);
}