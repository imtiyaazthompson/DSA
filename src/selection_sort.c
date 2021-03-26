#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int test_ssort() {
	int i,j,k;
	int min_index = 0;
	int numbers[11] = {10,4,11,6,1,0,2,23,14,17,9};
	printf("Unsorted\n");
	for (i=0;i<11;i++) {
		printf("%d ", numbers[i]);
	}
	
	for (i = 0;i < 10;i++) {
		// Reset min_index to current value of i for correctness
		min_index = i;
		for (j = i + 1;j < 11;j++) {
			if (numbers[j] < numbers[min_index]) {
				min_index = j;
			}
		}
		
		if (i != min_index) {
			// Smallest number within the range has been found
			swap(&numbers[i], &numbers[min_index]);
		}
		
	}
	
	printf("Sorted\n");
	for (i=0;i<11;i++) {
		printf("%d ", numbers[i]);
	}
}
