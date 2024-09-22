#include <stdio.h>


void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void selectionSort(int arr[], int size) {
    int min;
    for(int i = 0; i < size; i++) {
        min = i;
        for(int j = i + 1; j < size; j++) { 
            if(arr[j] < arr[min]) min = j;
        }
        
        swap(arr, i, min);
    }
}

void test() {
	int n, X, res = 1;
	scanf("%d %d", &n, &X);
	
	int h[2*n];
	
	for(int i = 0; i < 2*n; i++) {
		scanf("%d", &(h[i]));
	}
	
	selectionSort(h, 2*n);
	for (int i = 0; i < n && res == 1; i++) {
		if (h[i] > h[i+n]-X) res = 0;
	}
	
	printf((res)? "SIM\n" : "NAO\n");
}

int main() {
	int tests;
	
	scanf("%d", &tests);

	for (int i = 0; i < tests; i++) test();
}
