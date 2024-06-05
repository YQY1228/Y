/*************************************************************************
	> File Name: 10.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jun 2024 08:34:24 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *getnewnode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Node *insert(Node *head,int pos, int val){
    if (pos == 0){
        Node *p = getnewnode(val);
        p->next = head;
        return p;
    }
    Node *node = getnewnode(val);
    for (int i = 1; i < pos ; i++)p = p->next;
    node->next = p->next;
    p->next = node;
    return head;
}

int find(Node *head,int val){
    Node *p = head;
    while (p){
        if (p->data == val) return 1;
        p = p->next;
    }
    return 0;
}

void clear(Node *head){
    if (head == NULL)return;
    for (Node *p = head,*q; p ;p = q){
        q = p->next;
        free(p);
    }
    return;
}

