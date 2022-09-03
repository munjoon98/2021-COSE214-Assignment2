#include<iostream>
using namespace std;

int num;

void max_heapify(int arr[],int numb) {
	int largest;
	int l = (numb+1) * 2;
	int r = (numb+1) * 2 + 1;
	if (l <= num && arr[l-1] > arr[numb]) largest = l;
	else largest = numb+1;
	if (r <= num && arr[r-1] > arr[largest-1]) largest = r;
	if (largest != numb+1) {
		int temp = arr[numb];
		arr[numb] = arr[largest-1];
		arr[largest-1] = temp;
		max_heapify(arr, largest-1);
	}
}

void build_max_heap(int arr[]) {
	for (int i = num / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i);
	}

}

void heapsort(int arr[]) {
	build_max_heap(arr);
	for (int i = num-1; i >= 1; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		num--;
		max_heapify(arr, 0);
	}
}

int main() {
	

	scanf("%d", &num);
	int fin_num = num;

	int* arr = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	
	heapsort(arr);

	for (int i = 0; i < fin_num; i++) {
		printf("%d\n", arr[i]);
	}
}
