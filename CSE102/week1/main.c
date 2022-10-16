#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{

    /* Ask for the problem selection (1,2,3) .....  */
    int enter;
    int PL, PW, SL, SW;
    int a = 0;
    int b = 0;

    double x1, x2, x3, x4, x5;
    double i = 0;
    double j = 0;

    printf("Select problem:");
    scanf(" %d", &enter);

    if (enter == 1)
    {
        printf("PL:");
        scanf(" %d", &PL);
        printf("PW:");
        scanf(" %d", &PW);
        printf("SL:");
        scanf(" %d", &SL);
        printf("SW:");
        scanf(" %d", &SW);

        a = dt1a(PL, PW, SL, SW);
        b = dt1b(PL, PW, SL, SW);

        if (a == b)
        {
            if (a == '1')
            {
                printf("Setosa");
            }
            else if (a == '2')
            {
                printf("Versicolor");
            }
            else if (a == '3')
            {
                printf("Virginica");
            }
        }
        else
        {
            if (a == '1')
            {
                printf("Setosa");
            }
            else if (a == '2')
            {
                printf("Versicolor");
            }
            else if (a == '3')
            {
                printf("Virginica");
            }
            printf("\n");
            if (b == '1')
            {
                printf("Setosa");
            }
            else if (b == '2')
            {
                printf("Versicolor");
            }
            else if (b == '3')
            {
                printf("Virginica");
            }
        }
    }
    else if (enter == 2)
    {
        printf("x1:");
        scanf(" %lf", &x1);
        printf("x2:");
        scanf(" %lf", &x2);
        printf("x3:");
        scanf(" %lf", &x3);
        printf("x4:");
        scanf(" %lf", &x4);
        printf("x5:");
        scanf(" %lf", &x5);

        i = dt2a(x1, x2, x3, x4, x5);
        j = dt2b(x1, x2, x3, x4, x5);

        if (((i - j) <= CLOSE_ENOUGH && (i - j) >= 0) || (((j - i) <= CLOSE_ENOUGH) && (j - i) >= 0))
        {
            printf("%.1f", (i + j) / 2);
        }
        else
        {
            printf("%.1f", i);
            printf("\n");
            printf("%.1f", j);
        }
    }
    else if (enter == 3)
    {

        int debt, year;
        char brand, creditScore = '0', status;
        int k = 0;
        int l = 0;

        printf("Since you registered to our bank, how many years have passed? :");
        scanf(" %d", &year);

        printf("What is the current status of your credit score according to our credit score system?");
        printf("\nA- Great\nB- Very Good\nC- Good\nD- Bad\nE- Very Bad\n (Uppercase)  :");
        scanf(" %c", &creditScore);
        printf("\nWhat brand is your car? (Only write the first letter of the brand with uppercase.) :");
        scanf(" %c", &brand);
        printf("Are you checking for a company?\nY-Yes\nN-No\n (Enter upparcase) :");
        scanf(" %c", &status);
        printf("How much debt do you have? :");
        scanf(" %d",&debt);

        k = dt3a(debt, year, brand, creditScore, status);
        l = dt3b(debt, year, brand, creditScore, status);

        if (((k - l) <= CLOSE_ENOUGH && (k - l) >= 0) || (((l - k) <= CLOSE_ENOUGH) && (l - k) >= 0))
        {
            k = (k - l) / 2;
            if (k == 0)
            {
                printf("Your financial health is: Great!");
            }
            else if (k == 1)
            {
                printf("Your financial health is: Very Good!");
            }
            else if (k == 2)
            {
                printf("Your financial health is: Good!");
            }
            else if (k == 3)
            {
                printf("Your financial health is: Normal");
            }
            else if (k == 4)
            {
                printf("Your financial health is: Bad");
            }
            else if (k == 5)
            {
                printf("Your financial health is: Very Bad :(");
            }
        }
        else
        {
            printf("Your financial health is: ");
            if (k == 0)
            {
                printf("Great!");
            }
        }
        if (k == 1)
        {
            printf("Very Good!");
        }
        else if (k == 2)
        {
            printf("Good!");
        }
        else if (k == 3)
        {
            printf("Normal");
        }
        else if (k == 4)
        {
            printf("Bad");
        }
        else if (k == 5)
        {
            printf("Very Bad :(");
        }
        printf(" or ");
        if (l == 0)
        {
            printf("Great!");
        }
        else if (l == 1)
        {
            printf("Very Good!");
        }
        else if (l == 2)
        {
            printf("Good!");
        }
        else if (l == 3)
        {
            printf("Normal");
        }
        else if (l == 4)
        {
            printf("Bad");
        }
        else if (l == 5)
        {
            printf("Very Bad :(");
        }
    }



/* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
/* Compare performances and print results */

/* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
/* Compare performances and print results */

/* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
/* Compare performances and print results */
printf("\n");
return 0;
}
