#include <stdio.h>
#include <string.h>

int recursiveMinStrDiff(char str1[], char str2[], int m, int n)
{
    if(str1[0] == 0)
        return strlen(str1);        /*resturns len if zero*/
    else if(str2[0] == 0)
        return strlen(str2);        /*resturns len if zero*/
    else if(str1[m - 1] == str2[n - 1] && m>0 && n>0)
        {
            return recursiveMinStrDiff(str1, str2, m - 1, n - 1);   /*skips if both are equal*/
        }
    else
    {
        str1[m - 1] = str2[n - 1];      /*assigning because they only can be different*/
        if(n > m)
        {
            return 1 + recursiveMinStrDiff(str1, str2, m, n - 1);   /*any differences in length are being equalized in every step.*/
        }
        else if(n < m)
        {
            return 1 + recursiveMinStrDiff(str1, str2, m - 1, n);
        }
        else
        {
            return 1 + recursiveMinStrDiff(str1, str2, m - 1, n - 1);
        }
    }
}

int main()
{
    char str1[20] = "tesla";
    char str2[20] = "test";

    printf("%d", recursiveMinStrDiff(str1, str2, strlen(str1), strlen(str2)));
    return 0;
}