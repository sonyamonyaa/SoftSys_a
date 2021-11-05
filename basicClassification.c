#include "NumClass.h"
int isPrime(int num){
    //if divisible by 2, only 2 is prime:
    if (num % 2 == 0)
        return num == 2;
    //otherwise see if divisible by anything odd
    int i = 3;
    while (i * i <= num){
        if (num % i == 0){
            return false;
        }
        i+=2;
    }
    return true;
}
/* returns the factorial of a given number
*/
int factorial(int num){
    int i=1;
    int fact=1;
    while (i<num)
    {
        fact = fact * i;
        i++;
    }
    return fact;
}

int isStrong(int num){
    int temp = num;
    int digit,sum = 0;
    while (temp > 0)
    {
        digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }
    return sum == num;
}