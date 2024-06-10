/*************************************************************************
	> File Name: 13.c
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Jun 2024 02:11:20 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct Node {
    int data;
    Node *next;
}Node;

typedef struct Linklist {
    Node head, *tail;
}Linklist;

Node *getnewnode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

int insert(Linklist *l, int val) {
    Node *node = getnewnode(val);
    l->tail->next = node;
    l->tail = node;
    return 1;
}

int erase(Linklist *l) {
    if (empty(l))return 0;
    Node *p = l->head.next;
    l->head.next = l->head.next->next;
    if (p == l->tail) l->tail = &(l->head);
    free(p);
    return 1;
}

Linklist *initlinklist() {
    Linklist *l = (Linklist *)malloc(sizeof(Linklist));
    l->head.next = NULL;
    l->tail = &(l->head);
    return l;
}

int findLinklist (Linklist *l) {
    if (l == NULL)return 0;
    return l->head.next->data;
}

void clearLinklist(Linklist *l){
    Node *p = l->head.next,*q;
    if(l == NULL)return;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return;
}

typedef struct Queue {
    Linklist *l;
    int count;
}Queue;

Queue *initQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->l = initLinklist();
    q->count = 0;
    return q;
}

int empty(Queue *q){
    return q->count == 0;
}

int front(Queue *q){
    if (empty(q))return 0;
    return frontlinklist(q->l);
}

int push(Queue *q,int val){
    insert(q->l,val);
    return 1;
}

int pop(Queue *q){
    erase(q->l);
    return 1;
}

void clear(Queue *q){
    if (q == NULL)return;
    clearLinklist(q->l);
    free(q);
    return;
}
