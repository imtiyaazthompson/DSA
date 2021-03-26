#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void push(int data,int *stack,int *top) {
	*top += 1;
	if (*top <= MAX) {
		stack[*top] = data;
	} else {
		printf("Stack full. Push failed\n");
	}		
}

int pop(int *stack,int *top) {
	if (*top >= 0) {
		int data = stack[*top];
		stack[*top] = NULL;
		*top -= 1;
		return data;
	} else {
		printf("Stack empty. Pop failed\n");
		return -2;
	}
}

void print_stack(int *stack, int top) {
	while (top >= 0) {
		printf("%d\n", stack[top--]);
	}
}

int test_stack() {
	int stack[MAX];
	int top = -1;
	
	push(1,stack,&top);
	push(2,stack,&top);
	push(3,stack,&top);
	
	print_stack(stack,top);
	
	pop(stack,&top);
	pop(stack,&top);
	
	print_stack(stack,top);
	
	pop(stack,&top);
	pop(stack,&top);
}
