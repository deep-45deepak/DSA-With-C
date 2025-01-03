#include<stdio.h>
#include<stdlib.h>

// Print Array
void printArray(int Array[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", Array[i]);
    }
}

// Merge two arrays
void merge(int Arr[], int l, int mid, int r){
    // Size of the divided arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Allocate memory for the divided arrays
    int A[n1];
    int B[n2];

    // Merging the first half of the array
    for(int i = 0; i < n1; i++){
        A[i] = Arr[l + i];
    }

    // Merging the second half of the array
    for(int i = 0; i < n2; i++){
        B[i] = Arr[mid + 1 + i];
    }

    // Combining the two sorted arrays.
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(A[i] < B[j]){
            Arr[k] = A[i];
            k++; i++;
        }
        else{
            Arr[k] = B[j];
            k++; j++;
        }
    }

    // Merging the remaining elements of A[] if any
    while(i < n1){
        Arr[k] = A[i];
        k++; i++;
    }

    // Merging the remaining elements of B[] if any
    while(j < n2){
        Arr[k] = B[j];
        k++; j++;
    }
}

// MergeSort
void mergeSort(int Arr[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(Arr, l, mid);
        mergeSort(Arr, mid + 1, r);
        merge(Arr, l, mid, r);
    }
}

int main(){
    int Array[10] = {15, 12, 13, 14, 15, 16, 56, 42, 24, 4};
    int size = sizeof(Array) / sizeof(int);
    printf("Size of the array is %d", size);
    printf("\nArray before sorting\n");
    printArray(Array, size);

    mergeSort(Array, 0, size - 1);  // Corrected the 'size' index in mergeSort call

    printf("\nArray after sorting: \n");
    printArray(Array, size);

    return 0;
}
