#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void generate_sequence (int xs, int currentlen, int seqlen, int *seq)
{
    if(currentlen < seqlen)
    {
    seq[currentlen] = xs;                                                   /*always assigns current value to the arrey, the initial enter is not an exception here.*/
    if(xs % 2 == 1)
            generate_sequence(3 * xs + 1, currentlen + 1, seqlen, seq);     /*if it is odd we take 3x+1 of it.*/
    else
            generate_sequence(xs / 2, currentlen + 1, seqlen, seq);         /*if it is even we just divide it by 2.*/
    }
}

void recPrint(int *arr, int depth)  /*well, the name speaks for itself. by the way, i finished this homework pretty early and            */
{                                                                                   /*it turns out that some loops aren't prohibited and I suppose printing the sequance was one of them */
    if(depth == 0)                                                                  /*so ever since this printing function has become a flex.                                            */
        printf("\n\033[1;7;31m{");
    if(*arr != 0)
    {
        printf("%d, ", *arr);
        recPrint(arr + 1, depth + 1);
    }
    else if(*arr == 0)
        printf("\b\b}\033[0m\n");
}

void check_loop_iterative(void (*f)(int, int, int, int *), int xs, int seqlen, int *loop, int *looplen)
{
    int ls = 0, le = 0;
    if(loop[0] == 0)               /*initially (*loop) comes with zero-filled so we can only generate the array at the beginning this way. it will be filled with a*/
    {                               /*positive integer after that.*/
        f(xs, 0, seqlen, loop);
        *looplen = seqlen / 2;
        loop[seqlen] = 0;           /*NULL terminating for safety and it offers easier loop building as NULL means the end.*/
        recPrint(loop, 0);  /*just printing recursively, nothing special*/
        check_loop_iterative(f, xs, seqlen, loop, looplen);         /*recalls itself again but this time array has filled itself so the program won't get in here again.*/
    }
    else if(*looplen > 1)        
    {
        printf("\nChecking if there is a loop of length %d...", *looplen);
        if(has_loop(loop, seqlen, *looplen, &ls, &le) == 1)                 /*if the array has a loop in it, recursion stops. else, it goes on by decreasing *looplen at every step.*/
            printf("\n\n\033[1;30;42mLoop detected with a length of %d. \nThe indexes of the loop's first occurance: %d(first digit), %d(last digit)\033[0m\n", *looplen, ls, le);
        else
        {
            *looplen -= 1;
            check_loop_iterative(f, xs, seqlen, loop, looplen);
        }
    }
    else
    {
        for(int i = 0; i < 100; i++)
            loop[i] = 0;
        printf("\n\033[1;7;31mNo loop found.\033[0m\n");                                   /*when *looplen = 0, main() handles it as a unsuccesful operation code.*/
        *looplen = 0;
    }
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    arr[n] = 0;
    int i = 0, j = 0, count = 0;    /*i and j are indexes, count however, holds how many consecutive indexes that are in "looplen" distance.*/
    int inLoop = 0;                 /*lets the program know if it is in loop or not.*/
    int loopCount = 0;              /*amount of whole loops*/
    int *holdIfSuccess;                             /*if a loop is found, this works as a temp array. this way the loop is transferred to the beginning of (*arr) which means*/
    holdIfSuccess = (int *)calloc(50, sizeof(int)); /*if i want to print the loop in main, i just print the first "looplen" elements of the array.*/

    while(i + looplen <= n)
    {
        if(arr[i] == arr[i + looplen])                  /*if there are "looplen" consecutive indexes that are in "looplen" distance, we can say that it is a loop.*/
        {                                            
            if(count == 0 && inLoop == 0)               /*at the start of the loop, it assigns the start index to (*ls).*/
                *ls = i;
            count++;
        }
        else if(inLoop == 1)                            /*function terminates if loop has broken or the while loop has ended.*/
            break;
        if(count == looplen && inLoop == 0)             /*if "looplen" amount of consecutive indexes match at some indexes at "looplen" distance, it means that*/
        {                                               /*it repeats at least once which means this is a loop. this part controls the entrance to the loop.*/
            inLoop = 1;
            count = 0;
            loopCount++;
            *le = i + 1;                                /*if the loop happens only twice, the if condition below will not be entered so i put this line here so that it matches the minimum requirements.*/
            *le = *ls + looplen - 1;
        }
        else if(count == looplen && inLoop == 1)        /*resets the counter as loops iterate*/
        {
            loopCount++;
            count = 0;
            *le = i + 1;
            *le = *ls + looplen - 1;
        }
        i++;
    }
    /*NOTE: DUE TO THE CONTRADICTION IN THE PDF FILE'S FIRST DIGIT AND LAST DIGIT USAGES, THIS PROGRAM IS COMPATIBLE WITH BOTH SCREENSHOTS AND
    THE WRITINGS IN THE SECOND PAGE. IF YOU RUN THIS PROGRAM WITHOUT ANY CHANGES, IT WILL FIND FIRST LOOP'S FIRST INDEX AS 'ls' AND FIRST LOOP'S
    LAST INDEX AS 'le'. IF YOU REMOVE THE 93'RD AND 86'TH LINES, IT WILL FIND FIRST LOOP'S FIRST INDEX AS 'ls' AND LAST LOOP'S FIRST INDEX AS 'le'.*/
    if(loopCount > 0)
    {
        while(j < looplen)                      /*On success, assigns the first elements of the array with the loop for easy printing in main().*/
        {
            holdIfSuccess[j] = arr[*ls + j];
            j++;
        }
        j = 0;
        while(j < looplen)  /*index is -2. This is the only place that the first index can have -2 value.*/
        {
            arr[j] = holdIfSuccess[j];
            j++;
        }
        return 1;
    }
    else return 0;          /*i am not placing anything to the first index as not placing -2 will mean that the operation was unsuccesful.*/
}

void hist_of_firstdigits(void (*f)(int, int, int, int *), int xs, int seqlen, int *h, int digit)
{
    int *arr;
    arr = (int *) calloc(seqlen + 2, sizeof(int));
    f(xs, 0, seqlen, arr);
    char findDigit[10] = {};    /*this will be a string so there will be an additional NULL character so I opened place for 9 digits and 1 NULL character.*/
    if(digit < seqlen)
    {
        sprintf(findDigit, "%d", arr[digit]);   /*leftmost digit goes to the 0'th index so i can easily find the digit.*/
        h[findDigit[0] - 48 - 1]++;             /*incrementing the digit array's (Current leftmost digit - 1)'th index by one.*/
        hist_of_firstdigits(f, xs, seqlen, h, digit + 1);   /*proceeding through the next index. "int digit" holds the current index value.*/
    }
    free(arr);
}