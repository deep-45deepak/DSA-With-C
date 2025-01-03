#include<stdio.h>
#include<stdlib.h>

// print Array

void printArray(int Array[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\t",Array[i]);
    }
}


//  swap

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partition
// it is the partition from last method there are also other
//  methods like front and random or median element methods

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    // iterator along left to right side of the array.
    int i = l-1;
    // iterator over the partition array to count the number of small element in left side and swap them.
    // and then it finally return the index of the pivot element.
    for(int j=l; j<r; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    i++;
    swap(arr,i,r);
    return i;
}



// QuickSort

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}


int main(){
    int Array[10] = {12,2,44,32,14,4,57,78,98,57};
    printf("Unsorted Array is : \n");
    printArray(Array,10);
    quickSort(Array,0,10);
    printf("\nSorted Array is : \n");
    printArray(Array,10);

    return 0;
}