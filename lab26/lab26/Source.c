#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d)->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = first;
	newNode->data = value; 
	first = newNode;
}
int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}
int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) return 1;
		ptr = ptr->next;
	}           
	return 0;
}
void clearList() {
	struct Node* ptr;
	while (first != NULL) {
		ptr = first;
		first = first->next;
		free(ptr);
	}
}
int sum() {
	int s = 0;
	struct Node* ptr = first;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}
int odds() {
	int x = 0;
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) x++;
		ptr = ptr->next;
	}
	return x;
}
void x10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if(ptr->data % 2)ptr->data *= 10;
		ptr = ptr->next;
	}
}
void iX100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data *= 100;
			return;
		}
		index++;
		ptr = ptr->next;
	}
}
void leftX10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL && index != i) {
			ptr->data *= 10;
			index++;
			ptr = ptr->next;
	}
}
void rightX10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index > i) ptr->data *= 10;
		index++;
		ptr = ptr->next;
	}
}
void delI(int i) {
	if (i == NULL) return;
	if (i == 0) {
		deleteFromHead();
		return;
	}
	
	struct Node* ptr = first->next;
	struct Node* prev = first;


	int index = 1;

	while (ptr != NULL) {
		if (index == i) {
			prev->next = ptr->next;
			free(ptr);
			return;
		}
		prev = ptr;
		ptr = ptr->next;
		index++;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// #1
	addToHead(10);
	addToHead(21);
	addToHead(30);
	addToHead(40);
	addToHead(111);
	printList();
	// #2
	printf("sum = %d\n", sum());
	// #3
	printf("odds = %d\n", odds());
	// #4
	x10();
	printList();
	// #5
	{int i;
	printf("¬ведите индекс элемента, который нужно x100: ");
	scanf_s("%d", &i);
	iX100(i);
	printList();}
	// #6
	{int i;
	printf("¬ведите индекс элемента, левее которого x10: ");
	scanf_s("%d", &i);
	leftX10(i);
	printList();}
	// #7
	{int i;
	printf("¬ведите индекс элемента, правее которого x10: ");
	scanf_s("%d", &i);
	rightX10(i);
	printList();}
	// #8
	{
		int i;
		printf("¬ведите индекс элемента, который нужно удалить: ");
		scanf_s("%d", &i);
		delI(i);
		printList();
	}

	clearList();
}