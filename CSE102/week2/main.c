#include <stdio.h>
#include <math.h>
#include <stdlib.h> /*To use abs function in part 1. I could've done it without this library but this way it is easier to understand and it's use is only for error code.*/

void write_file(int number) /*Writes numbers to temp file.*/
{
    FILE *ptr2;
    ptr2 = fopen("temp.txt", "a+");
    fprintf(ptr2, "%d", number);
    fprintf(ptr2, "%c", ' ');
    fclose(ptr2);
}

void print_file() /*Prints the whole results.txt file.*/
{
    FILE *ptr1;
    ptr1 = fopen("results.txt", "a+");
    int a;
    rewind(ptr1);
    while (!feof(ptr1))
    {
        fscanf(ptr1, "%d ", &a);
        printf("%d ", a);
    }
    fclose(ptr1);
}

int checkdouble(FILE *ptr, int a) /*Checks if the number is repeating or not.*/
{
    rewind(ptr);
    int b = 0;
    int count = 0;
    while (!feof(ptr))
    {
        fscanf(ptr, " %d", &b);
        if (b == a)
            count++;
    }
    return count;
}

void sort_file()
{
    FILE *ptr1;
    ptr1 = fopen("results.txt", "a+");

    int i = 0, j = 0, k = 0;
    int duble = 1;
    int minstate = 1, min1 = 0, min2 = 0, min3 = 0;
    int temp = 0;
    int pos = 0;
    int count1 = 0, count2 = 0;
    while (!feof(ptr1)) /*Calculating the number count*/
    {
        fscanf(ptr1, " %d", &temp);
        count1++;
    }
    rewind(ptr1);
    while (count1)               /*This part finds the 3 smallest numbers and puts them in order in min1,min2 and min3.*/
    {                            /*The main logic here is if we have x numbers, the smallest number will be smaller than x-1 numbers and the biggest one will be smaller than zero.*/
        fscanf(ptr1, " %d", &i); /*If we sort them by comparison amounts 3 by 3 and write the in the temp file, at the end, we would be sorting all of them.*/
        pos = ftell(ptr1);
        count2 = 0;
        rewind(ptr1);
        while (!feof(ptr1))
        {
            fscanf(ptr1, " %d", &j);
            if (i <= j)
                count2++;
        }

        if (count1 == count2)
        {
            if (minstate == 1) /*minstate holds where to put the number.*/
            {
                min1 = i;
                duble = checkdouble(ptr1, min1); /*Comparison amount is subtracted by the repetition amount and the number is printed by the repetition amount.*/
                for (k = 0; k < duble; k++)
                    if (k != 0)
                        count1--;
                minstate = 2;
            }
            else if (minstate == 2)
            {
                min2 = i;
                duble = checkdouble(ptr1, min2);
                for (k = 0; k < duble; k++)
                    if (k != 0)
                        count1--;

                minstate = 3;
            }
            else if (minstate == 3) /*Every minstate which equals to 3, the numbers are printed 3 by 3.*/
            {
                min3 = i;
                duble = checkdouble(ptr1, min1);
                for (k = 0; k < duble; k++)
                {
                    write_file(min1);
                }
                duble = checkdouble(ptr1, min2);
                for (k = 0; k < duble; k++)
                {
                    write_file(min2);
                }
                duble = checkdouble(ptr1, min3);
                for (k = 0; k < duble; k++)
                {
                    if (k != 0)
                        count1--;
                    write_file(min3);
                }

                minstate = 1;
            }
            count1--;
            rewind(ptr1);
        }
        else
        {
            fseek(ptr1, pos, SEEK_SET);
        }
    }
    rename("temp.txt", "results.txt"); /*The temp file becomes our results file since it has all the same values but sorted.*/
    fclose(ptr1);
}

int sum(int n1, int n2, int flag)
{
    int summ = 0;
    n1 += 1;        /*Not to include the boundary.*/
    while (n1 < n2) /*If flag == 0, it will work on even, else, it will work on odd.*/
    {
        if (flag == 0 && n1 % 2 == 0)
        {
            summ += n1;
        }
        else if (flag == 1 && n1 % 2 == 1)
        {
            summ += n1;
        }
        n1++;
    }

    return summ;
}
int multi(int n1, int n2, int flag)
{
    int mult = 1;
    n1 += 1;        /*Not to include the boundary.*/
    while (n1 < n2) /*If flag == 0, it will work on even, else, it will work on odd.*/
    {
        if (flag == 0 && n1 % 2 == 0)
        {
            mult *= n1;
        }
        else if (flag == 1 && n1 % 2 == 1)
        {
            mult *= n1;
        }
        n1++;
    }
    return mult;
}

int isprime(int a)
{
    int result = 0;
    int i = 0;
    for (i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return i;
        }
    }
    return 0;
}

int main() /***DISCLAIMER: I HAVEN'T PUT FUNCTIONS IF THE PROTOTYPE HAS NOT BEEN GIVEN.THE CALCULATIONS WHICH THE PROTOTYPES NOT GIVEN, THEY'VE BEEN HANDLED IN main.***/
{
    int enter = 0;
    int n1 = 0, n2 = 0, flag1 = 0, flag2 = 0, flag;
    int summ = 0, mult = 0;
    int temp = 0;
    FILE *ptr1;
    FILE *ptr2;

    printf("Select operation\n1. Calculate sum/multiplication between two numbers\n2. Calculate prime numbers\n3. Show number sequence in file\n4. Sort number sequence in file\n-------------------------\n");
    scanf(" %d", &enter);
    if (enter == 1)
    {
        printf("\nPlease enter '0' for sum, '1' for multiplication.\n");
        scanf(" %d", &flag1);
        printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
        scanf(" %d", &flag2);
        if((flag1 > 1 || flag1 < 0) || (flag2 > 1 || flag2 < 0))
        {
            printf("-ERROR-Invalid input.\n");
            return 0;
        }
        printf("Number 1: ");
        scanf(" %d", &n1);
        printf("Number 2: ");
        scanf(" %d", &n2);

        

        if (n1 > n2) /*tidying up the boundaries*/
        {
            temp = n1;
            n1 = n2;
            n2 = temp;
        }

        temp = 0;

        flag = flag1 + flag2;
        if (flag == 1 && flag1 == 1) /*Basically I compiled flag1 and flag2 values into one single flag value.                              */
            flag = -1;               /*-1 (1,0) = Even Multiplication , 0 (0,0) = Even sum, 1 (0,1) = Odd Sum, 2 (1,1) = Odd Multiplication */

        switch (flag)
        {
        default:
            printf("Invalid input.");
            break;
        case -1:
            printf("Result\n");
            temp = n1 + 1;
            if ((temp++ % 2 == 0 || temp++ % 2 == 0) && abs(n1 - n2) > 1) /*Here, I made an exception for the while loop below. The first number shouldn't have a sign in front of it.*/
                printf("%d", temp - 1);                                   /*If the first condition meets, the first number after boundary is printed and the temp is increased by one */
            while (temp < n2)                                             /*because if it does not increase, the same number will go inside the while loop and print twice. And also  */
            {                                                             /*if the first condition is met, the compiler won't look at the second one so temp is only incremented by 1.*/
                if (temp % 2 == 0)                                        /*Se)cond condtion is only looked when the first one is not true and since the program increments temp after */
                {                                                         /*looking, second condition checks the second number's even-odd state.                                      */
                    printf(" * %d", temp);
                }
                temp++;
            }
            if (abs(n1 - n2) > 1)
            {
                mult = multi(n1, n2, flag2);
                printf(" = %d", mult);
                ptr1 = fopen("results.txt", "a");
                fprintf(ptr1, "%d", mult);
                fprintf(ptr1, "%c", ' ');
                fclose(ptr1);
                printf("\nThe result is written to result.txt file.");
            }
            else
            {
                printf("Error code: -999 (Out of boundary)");
            }
            break;
        case 0:

            printf("Result\n");
            temp = n1 + 1;
            if ((temp++ % 2 == 0 || temp++ % 2 == 0) && abs(n1 - n2) > 1)
                printf("%d", temp - 1);
            while (temp < n2)
            {
                if (temp % 2 == 0)
                {
                    printf(" + %d", temp);
                }
                temp++;
            }
            if (abs(n1 - n2) > 1)
            {
                summ = sum(n1, n2, flag2);
                printf(" = %d", summ);
                ptr1 = fopen("results.txt", "a");
                fprintf(ptr1, "%d", summ);
                fprintf(ptr1, "%c", ' ');
                fclose(ptr1);
                printf("\nThe result is written to result.txt file.");
            }
            else
            {
                printf("Error code: -999 (Out of boundary)");
            }
            break;
        case 1:
            printf("Result\n");
            temp = n1 + 1;
            if ((temp++ % 2 == 0 || temp++ % 2 == 0) && abs(n1 - n2) > 1)
                printf("%d", temp - 1);
            while (temp < n2)
            {
                if (temp % 2 == 1)
                {
                    printf(" + %d", temp);
                }
                temp++;
            }
            if (abs(n1 - n2) > 1)
            {
                summ = sum(n1, n2, flag2);
                printf(" = %d", summ);
                ptr1 = fopen("results.txt", "a");
                fprintf(ptr1, "%d", summ);
                fprintf(ptr1, "%c", ' ');
                fclose(ptr1);
                printf("\nThe result is written to result.txt file.");
            }
            else
            {
                printf("Error code: -999 (Out of boundary)");
            }
            break;
        case 2:
            printf("Result\n");
            temp = n1 + 1;
            if ((temp++ % 2 == 0 || temp++ % 2 == 0) && abs(n1 - n2) > 1)
                printf("%d", temp - 1);
            while (temp < n2)
            {
                if (temp % 2 == 1)
                {
                    printf(" * %d", temp);
                }
                temp++;
            }
            if (abs(n1 - n2) > 1)
            {
                mult = multi(n1, n2, flag2);
                printf(" = %d", mult);
                ptr1 = fopen("results.txt", "a");
                fprintf(ptr1, "%d", mult);
                fprintf(ptr1, "%c", ' ');
                fclose(ptr1);
                printf("\nThe result is written to result.txt file.");
            }
            else
            {
                printf("Error code: -999 (Out of boundary)");
            }
            break;
        }
    }
    else if (enter == 2)
    {
        int num = 0;
        int res = 0;
        int i = 0;
        printf("Please enter an integer: ");
        scanf(" %d", &num);
        for (i = 2; i < num; i++)
        {
            res = isprime(i);
            if (res == 0)
            {
                printf("\n%d is a prime number.", i);
            }
            else
            {
                printf("\n%d is a prime number, it is dividible by %d.", i, res);
            }
        }
    }
    else if (enter == 3)
    {

        printf("Result :\n");
        print_file();
    }
    else if (enter == 4)
    {

        sort_file();

        printf("Result :\n");
        print_file();
    }
    printf("\n");
    return 0;
}