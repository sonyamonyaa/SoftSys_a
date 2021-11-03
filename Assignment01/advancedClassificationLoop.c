#include <NumClass.h>
#include <math.h>
//self note: loop implmentation
int isArmstrong(int num) {
    int n = (num==0)?1:log10(num)+1; 
    int temp = num;
    int digit,sum = 0;
    while (temp > 0)
    {
        digit = temp % 10;
        sum += pow(digit,n);
        temp /= 10;
    }
    return sum == num;
}

int isPalindrome(int num){
    
}