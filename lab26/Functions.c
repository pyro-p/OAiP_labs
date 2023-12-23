#include "Functions.h"

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;



void preset() {
	first = NULL;
	printList();

	addToHead(10);
	printList();
	addToHead(20);
	printList();
	addToHead(30);
	printList();
	addToHead(40);
	printList();
	addToHead(50);
	printList();
}



void printList() {
	struct Node* ptr = first;
	while (ptr) {
		printf("(%d)->", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr);
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	if (first) {
		int value = first->data;
		struct Node* delNode = first;
		first = first->next;

		free(delNode);

		return value;
	}
	return 0;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* ptr = first;
	int s = 0;

	while (ptr) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int countEven() {
	struct Node* ptr = first;
	int cnt = 0;

	while (ptr) {
		if (ptr->data % 2 == 0)	cnt++;
		ptr = ptr->next;
	}
	return cnt;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr) {
		if (ptr->data % 2 == 1) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
	}
}

void elIx100(int i) {
	struct Node* ptr = first;
	int index = 0;

	while (ptr) {
		if (index == i) {
			ptr->data *= 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elLeftIx10(int i) {
	if (i < 1) return;
	struct Node* ptr = first;
	int index = 0;
	
	while (ptr && (index < i)) {
		ptr->data *= 10;
		ptr = ptr->next;
		index++;
	}
}

void elRightIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	
	while (ptr && (index != i)) {
		ptr = ptr->next;
		index++;
	}

	if (!ptr) return;
	
	while (ptr->next) {
		ptr = ptr->next;
		ptr->data *= 10;
	}
}

void deleteElI(int i) {
	if (first == NULL) return;

	if (i == 0) {
		deleteFromHead();
		return;
	}

	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int index = 1;

	while (ptr) {
		if (index == i) {
			struct Node* delNode = ptr;
			prev_ptr->next = ptr->next;
			ptr = prev_ptr->next;

			free(delNode);
			if (!ptr) return;
		}
		
		prev_ptr = ptr;
		ptr = ptr->next;
		index++;
	}
}

void task9() {
	struct Node* ptr = first;
	reverseList(ptr);
}

void reverseList(struct Node* ptr) {
	if (ptr) {
		reverseList(ptr->next);
	}
	if (ptr == NULL) {
		printf("%d", ptr);
		return;
	}
	printf("<-(%d)", ptr->data);
}

int checkDuplicate() {
	struct Node* ptr = first;
	while (ptr) {
		struct Node* temp_ptr = ptr->next;
		while (temp_ptr) {
			if (ptr->data == temp_ptr->data) return 1;
			temp_ptr = temp_ptr->next;
		}
		ptr = ptr->next;
	}
	return 0;
}

void swapAdjacent(int i) {
	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	struct Node* next_ptr = ptr->next;

	if (i == 0) {
		prev_ptr->next = ptr->next;
		ptr->next = prev_ptr;
		first = ptr;
	}

	int index = 1;
	while (next_ptr) {
		if (index == i) {
			ptr->next = next_ptr->next;
			next_ptr->next = ptr;
			prev_ptr->next = next_ptr;
			break;
		}
		prev_ptr = prev_ptr->next;
		ptr = ptr->next;
		next_ptr = next_ptr->next;
		index++;
	}
}

void swap(int i, int j) {
	if (i + 1 == j) {
		swapAdjacent(i);
		return;
	}
	if (j + 1 == i) {
		swapAdjacent(j);
		return;
	}

	struct Node* ptr = first;

	struct Node* prev_ptr_i = NULL;
	struct Node* ptr_i = NULL;
	struct Node* prev_ptr_j = NULL;
	struct Node* ptr_j = NULL;

	int index_i = 0;
	int index_j = 0;

	while (ptr) {
		if (ptr->next && i == 0) {
			ptr_i = ptr;
			break;
		}

		if (index_i == i - 1) {
			prev_ptr_i = ptr;
			ptr_i = ptr->next;
			break;
		}
		ptr = ptr->next;
		index_i++;
	}

	ptr = first;

	while (ptr) {
		if (ptr->next && j == 0) {
			ptr_j = ptr;
			break;
		}

		if (index_j == j - 1) {
			prev_ptr_j = ptr;
			ptr_j = ptr->next;
			break;
		}
		ptr = ptr->next;
		index_j++;
	}

	struct Node* next_ptr_i = ptr_i->next;

	if (i == 0) first = ptr_j;
	if (j == 0) first = ptr_i;

	ptr_i->next = ptr_j->next;
	ptr_j->next = next_ptr_i;
	if (i) prev_ptr_i->next = ptr_j;
	if (j) prev_ptr_j->next = ptr_i;
}

