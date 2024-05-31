/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 02:05:25 PM CST
 ************************************************************************/


#include<stdio.h>

int main(){
    long long n,s,i = 2;
    scanf("%lld",&n);
    while (i * i <= n){
        if (n % i == 0) s = i;
        while (n % i == 0) n /= i;
        i++;
    }
    if (n != 1)s = n;
    printf("%lld\n",s);
    return 0;
}
