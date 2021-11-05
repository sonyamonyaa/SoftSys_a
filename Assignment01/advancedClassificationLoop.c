#include <NumClass.h>
#include <math.h>
//self note: loop implmentation
int isArmstrong(int num)
{
    int n = (num == 0) ? 1 : log10(num) + 1;
    int temp = num;
    int digit, sum = 0;
    while (temp > 0)
    {
        digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }
    return sum == num;
}

int isPalindrome(int num)
{
    if (num < 0)
        return false;
    int div = 1;
    while (num / div >= 10)
    {
        div *= 10;
    }
    while (num != 0)
    {
        int ld = num / div;
        int rd = num % 10;
        if (rd != ld)
            return false;
        num = (num % div) /10;
        div /= 100;
    }
    return true;
}