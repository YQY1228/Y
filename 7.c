/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 02:06:59 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int arr[max+5] = {0};

void s(){
    for (int i = 2;i <= max; i++){
        if (arr[i] == 0){
            arr[i] = i;
            for (int j = 2,h = max / i;j <=h;j++){
                if (arr[i*j])continue;
                arr[i*j] = i;
            }
        }
    }
    return;
}

int main(){
    s();
    for (int i = 2;i <= max;i++){
        printf("min(%d)-->%d\n",i,arr[i]);
    }
    return 0;
}
