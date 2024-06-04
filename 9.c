/*************************************************************************
	> File Name: 9.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 10:32:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector {
    int size, count;
    int *data;
} vector;

vector *getnewvector(int n) {
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int)*n);
    return p;
}

int expand(vector *v){
    if (v == NULL) return 0;
    int *p = v->data = (int *)realloc(v->data,sizeof(int) * 2 * v->size);
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

int insert(vector *v,int pos,int val) {
    if (pos < 0 || pos >= v->size) return 0;
    if (v->size == v->count && !expand(v)) return 0;
    for (int i = v->count - 1; i >= pos; i--) {
        v->data[i+1] = v->data[i];
    }
    v->data[pos] = val;
    v->count += 1;
    return 1;
}

int erase(vector *v, int pos) {
    if (pos < 0 || pos >= v->count) return 0;
    for (int i = pos + 1; i < v->count; i++) {
        v->data[i-1] = v->data[i];
    }
    v->count -= 1;
    return 1;
}
void clear(vector *v){
    if (v == NULL)return;
    free(v->data);
    free(v);
    return;
}

int main() {
    srand(time(0));
    vector *v = getnewvector(12);
    for (int i = 0;i < 10; i++) {
        int n = insert(v, i, i);
        printf("%d\n",n);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", v->data[i]);
    }
    clear(v);
    return 0;
}
