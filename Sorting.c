#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

        // Print Array

void printArray(int Array[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\t",Array[i]);
    }
}

        // Bubble sort

void bubbleSort(int Array[],int size){
    for (int i = 1; i < size; i++){
        for (int j = 0; j < size-i; j++){
            if(Array[j] > Array[j+1]){
                int temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }
        }
    }
}

        // Insertion sort

void insertionSort(int Arr[],int n){
    for(int i=1; i<n; i++){
        int j = i-1;
        while(Arr[j+1]<Arr[j] && j>=0){
            int temp = Arr[j];
            Arr[j] = Arr[j+1];
            Arr[j+1] = temp;
            j--;
        }
    }
}


//  Selection Sort

void SelectionSort(int Arr[],int size){
    for(int i=0; i<size-1;i++){
        for (int j = i+1; j< size; j++){
            if(Arr[i]>Arr[j]){
                int temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
}

        // Main function
int main(){
    int Array[10] = {15,12,13,14,15,16,56,42,24,4};
    int size = sizeof(Array)/sizeof(int);
    printArray(Array,size);
    printf("\n");
    SelectionSort(Array,size);
    printArray(Array,size);
    return 0;
}
