/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jun 2024 04:17:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
	int* data;
	int size, top;
}strck;
stack* initstack(int n) {
	stack* s = (stack*)malloc(sizeof(stack));
	s->data = (int*)malloc(sizeof(int)*n);
	s->size = n;
	s->top = -1;
	return s;
}
int empty(stack* s) {
	return s->top == -1;
}
int top(stack* s) {
	if (empty(s))return 0;
	return s->data[s->top];
}
int push(stack* s, int val) {
	if (s->top + 1 == s->size)return 0;
	s->top += 1;
	s->data[s->top] = val;
	return 1;
}
int pop(stack* s) {
	if (empty(s))return 0;
	s->top -= 1;
	return 1;
}
void clearstack(stack* s) {
	if (s == NULL)return;
	free(s->data);
	free(s);
	return;
}

int main() {
	return 0;
}
