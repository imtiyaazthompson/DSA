#include <stdio.h>
#include <stdlib.h>

void swap_2(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_list_2(int *list,int n) {
	int i;
	for(i = 0;i < n;i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

int main() {
	int i,j;
	int numbers[11] = {10,4,11,6,1,0,2,23,14,17,9};
	
	print_list_2(numbers,11);
	
	for(i = 0;i < 11;i++) {
		// Outer loop iterates through unsorted part
		for(j=i-1;j >= 0;j--) {
			// Inner loop iterates through sorted part to insert element in correct place
			if (numbers[j+1] < numbers[j]) {
				swap_2(&numbers[i],&numbers[j]);
			}
		}
	}
	
	print_list_2(numbers,11);
}
