#include "NumClass.h"
#include <math.h>
//self note: recursion implementation

/*returns the sum of digits of a num to the power of n,
using recursion.
*/
int recPowSum(int num, int n)
{
    int sum =0;
    if (num == 0)
        return 0;
    if (num < 10)
        return pow(num, n);
    else
    {
        int digit = num % 10;
        sum += pow(digit, n);
        sum +=recPowSum(num/10,n);
    }
    return sum;
}
int isArmstrong(int num)
{
    int n = (num == 0) ? 1 : log10(num) + 1;
    int sum = recPowSum(num,n);
    return sum == num;
}

/* checks if a number is palindrome using it's size by div
*/
int recPalindrome(int num, int div){
    if (num >= 0 && num <= 9) return true;
    int ld = num / div;
    int rd = num % 10;
    if (rd != ld)
        return false;
    return recPalindrome((num%div)/10,div/100);
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
    return recPalindrome(num,div);
}