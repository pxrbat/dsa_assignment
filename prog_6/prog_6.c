#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify_min(int arr[],int n, int i){
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && arr[l] < arr[smallest]){
		smallest = l;
	}
	if(r < n && arr[r] < arr[smallest]){
		smallest = r;
	}if(smallest != i){
		swap(&arr[i], &arr[smallest]);
		heapify_min(arr, n, smallest);
	}
}

void heapify_max(int arr[],int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest!= i){
		swap(&arr[i], &arr[largest]);
		heapify_max(arr, n, largest);
	}
}

void build_min_heap(int arr[],int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify_min(arr, n, i);
	}
}

void build_max_heap(int arr[],int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify_max(arr, n, i);
	}
}

void print_array(const char *label,int arr[], int n)
{
	printf("%s",label);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter number of elements: ");
	if(scanf("%d",&n)!= 1||n <= 0){
		printf("Invalid number of elements.\n");
		return 0;
	}

	int *data = (int *)malloc(sizeof(int) * n);
	int *min_heap = (int *)malloc(sizeof(int) * n);
	int *max_heap = (int *)malloc(sizeof(int) * n);

	if(data == NULL || min_heap == NULL || max_heap == NULL){
		printf("Memory allocation failed.\n");
		free(data);
		free(min_heap);
		free(max_heap);
		return 0;
	}

	printf("Enter the elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
		min_heap[i] = data[i];
		max_heap[i] = data[i];
	}

	build_min_heap(min_heap, n);
	build_max_heap(max_heap, n);

	print_array("Min Heap (array form): ",min_heap, n);
	print_array("Max Heap (array form): ", max_heap,n);

	free(data);
	free(min_heap);
	free(max_heap);
	return 0;
}
