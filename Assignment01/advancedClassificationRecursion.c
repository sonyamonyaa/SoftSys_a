#include <NumClass.h>
#include <math.h>
//self note: recursion implementation

/*returns the sum of digits of a num to the power of n,
using recursion.
*/
int recPowSum(int num, int n)
{
    int sum;
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
    int digit;
    int sum = recPowSum(num,n);
    return sum == num;
}

int isPalindrome(int num)
{
}