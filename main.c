#include "NumClass.h"
#include <stdio.h>
int main(){
    int fst, lst;
    scanf("%d %d",&fst,&lst);
    printf("The Armstrong numbers are:");
    for (int i = fst; i < lst; i++)
    {
        if (isArmstrong(i))
        {
            printf(" %d",i);
        }
    }
    printf("\nThe Palindromes are:");
    for (int i = fst; i < lst; i++)
    {
        if (isPalindrome(i))
        {
            printf(" %d",i);
        }
    }
    printf("\nThe Prime numbers are:");
    for (int i = fst; i < lst; i++)
    {
        if (isPrime(i))
        {
            printf(" %d",i);
        }
    }
    printf("\nThe Strong numbers are:");
    for (int i = fst; i < lst; i++)
    {
        if (isStrong(i))
        {
            printf(" %d",i);
        }
    }
    printf("\n");
    return 0;
}
