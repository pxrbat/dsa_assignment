#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpCnt = 0, swapCnt = 0;

void printArray(int *arr,int n)
{   
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n)
{
    cmpCnt = swapCnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++){
            cmpCnt++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; swapCnt++;
            }
        }
    }
}

void selectionSort(int *arr,int n)
{
    cmpCnt = swapCnt = 0;
    for (int i = 0; i < n - 1; i++){
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            cmpCnt++;
            if (arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        if (minPos != i){
            int temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;
            swapCnt++;
        }
    }
}

void insertionSort(int *arr,int n)
{
    cmpCnt = swapCnt = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            cmpCnt++;
            if (arr[j] > key){
                arr[j + 1] = arr[j];
                swapCnt++;
                j--;
            } 
            else { 
                break; 
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = malloc(n1*sizeof(int));
    int *R = malloc(n2*sizeof(int));
    
    for (int i = 0;i < n1; i++){
        L[i] = arr[left + i];
    } 
    for (int i = 0; i< n2;i++) {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        cmpCnt++;
        if (L[i] <= R[j]){
            arr[k++]= L[i++];
        } else {
            arr[k++]= R[j++];
        } swapCnt++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    srand(time(NULL));
    int n;
    
    printf("Enter the number of random integers (N): ");
    scanf("%d", &n);
    
    int *arr = malloc(n *sizeof(int));
    int *arr2 = malloc(n* sizeof(int));
    
    printf("\nGenerating %d random integers in range [1, 1000]...\n", n);
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 1000 + 1;
    }
    
    printf("\nBefore Sorting:\n");
    printArray(arr, n);
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter choice (1-4): ");
    
    int choice;
    scanf("%d", &choice);
    
    for (int i = 0; i < n; i++) arr2[i] = arr[i];
    
    switch (choice){
        case 1:
            bubbleSort(arr2, n);
            printf("\nUsing Bubble Sort\n");
            break;
        case 2:
            selectionSort(arr2, n);
            printf("\nUsing Selection Sort\n");
            break;
        case 3:
            insertionSort(arr2, n);
            printf("\nUsing Insertion Sort\n");
            break;
        case 4:
            cmpCnt = 0; swapCnt = 0;
            mergeSort(arr2, 0, n - 1);
            printf("\nUsing Merge Sort\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    printf("\nAfter Sorting:\n");
    printArray(arr2, n);
    
    printf("\nNumber of comparisons: %d\n", cmpCnt);
    printf("Swaps: %d\n", swapCnt);
    
    free(arr);
    free(arr2);
    
    return 0;
}