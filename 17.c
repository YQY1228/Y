/*************************************************************************
	> File Name: 17.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 06:07:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define KEY(node) (node ? node->key : -1)
typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getnewnode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getnewnode(key);
    if (rand() % 2)root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *gettree(int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root,rand() % 100);
    }
    return root;
}

void clear(Node *p) {
    if (p == NULL)return;
    clear(p->lchild);
    clear(p->rchild);
    free(p);
    return;
}

char buff[1000];
int len = 0;
void __serialize(Node *root) {
    if (root == NULL) return;
    len += snprintf(buff +len, 100, "%d", root->key);
    if (root->lchild == NULL && root->rchild == NULL) return;
    len += snprintf(buff + len, 100, "(");
    __serialize(root->lchild);
    if (root->rchild) {
        len += snprintf(buff + len,100, ",");
        __serialize(root->rchild);
    }
    len += snprintf(buff + len,100,")");
    return;
}

void serialize(Node *root) {
    memset(buff,0,sizeof(buff));
    len = 0;
    __serialize(root);
    return;
}

void print(Node *root) {
    printf("%d(%d, %d)\n",KEY(root),KEY(root->lchild),KEY(root->rchild));
    return;
}

void output(Node *root) {
    if (root == NULL)return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}

int main() {
    srand(time(0));
    #define max 10
    Node *root = gettree(max);
    serialize(root);
    output(root);
    printf("buff[] : %s\n",buff);
    return 0;
}
