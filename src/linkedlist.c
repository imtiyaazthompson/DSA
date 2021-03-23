#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
	int data;
	struct node *next;
};

void insert_first(int data, struct node **head) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *head; // Since head is null
	*head = temp;
}

int insert_end(int data, struct node **head) {
	if (*head == NULL) {
		insert_first(data, head);
		return 0;
	}
	
	struct node *iter = *head;
	
	// Allocate memory for newly added node
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	// Go to the last element in the list
	while (iter->next != NULL) {
		iter = iter->next;
	}
	
	temp->data = data;
	temp->next = iter->next; // Since iter->next point to NULL
	iter->next = temp; // Link the previously last node to the new added node
	
	
	return 0;
}

void insert_between(int start_data, int data, int end_data, struct node **head){
	struct node *iter = *head;
	
	while (iter->next != NULL) {
		if (iter->data == start_data && iter->next->data == end_data){
			break;
		} else {
			iter = iter->next;	
		}
	}
	
	if (iter->next == NULL) {
		printf("Data range is invalid\n");
	} else {
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = iter->next;
		iter->next = temp;
	}
}


void print_list(struct node *head) {
	struct node *iter = head;
	
	while (iter != NULL) {
		printf("%d -> ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}

int main() {
	
	struct node *start = NULL;
	insert_end(1,&start);
	insert_end(2,&start);
	insert_end(3,&start);
	
	print_list(start);
	
	insert_between(1,5,2,&start);
	
	print_list(start);
}
