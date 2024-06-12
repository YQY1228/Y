/*************************************************************************
	> File Name: 16.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 08:31:51 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
}Node;

Node *getnewnode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = rtag = 0;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getnewnode(key);
    if (rand() % 2) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    return root;
}

void prenode(Node *root) {
    if (root == NULL)return;
    printf("%d ", root->key);
    if (ltag == 0)prenode(root->lchild);
    if (rtag == 0)prenode(root->rchild);
    return;
}

void innode(Node *root) {
    if (root == NULL)return;
    if (ltag == 0)innode(root->lchild);
    printf("%d ", root->key);
    if (rtag == 0)innode(root->rchild);
    return;
}

void postnode(Node *root) {
    if (root == NULL)return;
    if (ltag == 0)postnode(root->lchild);
    if (rtag == 0)postnode(root->rchild);
    printf("%d ",root->key);
    return;
}

Node *pre = NULL, *inorder = NULL;
void __build_inorder(Node *root) {
    if (root ==NULL) return;
    if (root->ltag == 0) __build_inorder(root->lchild);
    if (inorder == NULL) inorder = root;
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = 1;
    }
    if (pre && pre->rchild == NULL) {
        pre->rchild = root;
        root->rtag = 1;
    }
    pre = root;
    if (root->rtag == 0) __build_inorder(root->rchild);
    return;
}

void build_inorder(Node *root) {
    __build_inorder(root);
    pre->rchild = NULL;
    pre->rtag = 1;
    return;
}

Node *getnext(Node *root) {
    if (root->rtag == 1) return root->rchild;
    root = root->rchild;
    while (root->ltag == 0 && root->lchild) root = root->lchild;
    return root;
}

void clear(Node *root){
    if(root == NULL) return;
    if (ltag == 0)clear(root->lchild);
    if(rtag == 0)clear(root->rchild);
    free(root);
    return;
}
