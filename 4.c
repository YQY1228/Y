/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 12:50:01 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int arr[max+5] = {0};

void z(){
    for (int i = 2;i <= max;i++){
        if (arr[i] == 0){
            arr[++arr[0]] = i;
        }
        for (int j = 1;j <= arr[0];j++){
            if (arr[j]*i >max)break;
            arr[arr[j]*i] = 1;
            if (i % arr[j] == 0)break;
        }

    }
    return;
}

int main(){
    z();
    for (int i = 1; i <= arr[0];i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
