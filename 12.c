/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jun 2024 12:05:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct vector {
    int *data;
    int size;
}vector;

vector *initvector(int n){
    vector *v = (vector *)malloc(sizeof(vector));
    v->size = n;
    v->data = (int *)malloc(sizeof(int)*n);
    return v;
}

int vectorfind(vector *v,int pos) {
    if (pos < 0 || pos >= v->size)return -1;
    return v->data[pos];
}

int insert(vector *v,int pos,int val) {
    if (pos < 0 || pos >= v->size)return 0;
    v->data[pos] = val;
    return 1;
}

void clearvector(vector *v) {
    if (v == NULL)return;
    free(v->data);
    free(v);
    return;
}

typedef struct Queue {
    vector *data;
    int size,count,tail,head;
}Queue;

Queue *initQueue(int n) {
    Queue *p = (Queue *)malloc(sizeof(Queue));
    p->data = initvector(n);
    p->size = n;
    p->tail = p->head = p->count = 0;
    return p;
}

int empty(Queue *q){
    return q->count == 0;
}

int front(Queue *q) {
    return vectorfind(q->data,q->head);
}

int push(Queue *q,int val){
    if (q->count == q->size)return 0;
    insert(q->data,q->tail,val);
    q->tail += 1;
    if (q->tail == q->size)q->tail = 0;
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    if (empty(q))return 0;
    q->head += 1;
    q->count -= 1;
    return 1;
}

void clearQueue(Queue *q) {
    if (q == NULL)return;
    clearvector(q->data);
    free(q);
    return;
}
