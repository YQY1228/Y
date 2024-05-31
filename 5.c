/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 01:33:40 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100
int arr[max+5] = {0};

void s(){
    for (int i = 2;i <= max; i++){
        if (arr[i] == 0){
            //arr[i] = i;
            for (int j = 1,h = max / i;j <=h;j++){
                arr[i*j] = i;
            }
        }
    }
    return;
}

int main(){
    s();
    for (int i = 2;i <= max;i++){
        printf("max(%d)-->%d\n",i,arr[i]);
    }
    return 0;
}
