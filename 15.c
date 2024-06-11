/*************************************************************************
	> File Name: 15.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jun 2024 02:14:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
}Node;

Node *getnewnode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL:
    return p;
}

Node *insert(Node *root,int key){
    if (root == NULL)return getnewnode(key);
    if (rand() % 2) root-lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    return root;
}

Node *queue[25];
int head, tail;

//广度遍历
void bfs(Node *root) {
    head = tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        Node *node = queue[head];
        if (node->lchild) queue[tail++] = node->lchild;
        if (node->rchild) queue[tail++] = node->rchild;
        head++;
    }
}

//深度遍历
int tot = 0;
void dfs(Node *root) {
    if (root == NULL)return;
    int start, end;
    tot += 1;
    start = tot;
    if (root->lchild) dfs(root->lchild);
    if (root->rchild) dfs(root->rchild);
    tot += 1;
    end = tot;
    return;
}

void clear(Node *root) {
    if (root == NULL)return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
