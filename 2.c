/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 09:23:24 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int arr[max+5] = {0};

void s(){
    for (int i = 2;i <= max; i++){
        if (arr[i] == 0){
            for (int j = 2,h = max / i;j <=h;j++){
                arr[i*j] = 1;
            }
        }
    }
    return;
}

int main(){
    s();
    for (int i = 2;i <= max;i++){
        if (arr[i] == 0)printf("%d\n",i);
    }
    return 0;
}
