/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 12:47:38 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int arr[max+5] = {0};

void s(){
    for (int i = 2;i <= max; i++){
        if (arr[i] == 0){
            arr[++arr[0]] = i;
            for (int j = 2,h = max / i;j <=h;j++){
                arr[i*j] = 1;
            }
        }
    }
    return;
}

int main(){
    s();
    for (int i = 1;i <= arr[0];i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
