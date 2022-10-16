#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    printf("\033[1;7;37m");
    int *loop;
    int looplen = 0;
    int seqlen, xs;
    printf("Please enter the sequence length: ");
    scanf("%d", &seqlen);
    printf("Please enter the first element: ");
    scanf("%d", &xs);
    loop = (int *)calloc(seqlen + 10, sizeof(int));      /*opening space in memory as suggested in the pdf, opening more than needed for safety and some usefulness.*/
    check_loop_iterative(&generate_sequence, xs, seqlen, loop, &looplen);
    if(looplen != 0)                        /*if the function does not return an unsuccesful value, print loop.*/
    {
        printf("Loop: \033[1;7;31m{");
        for(int i = 0; i < looplen; i++)
            printf("%d, ", loop[i]);
        printf("\b\b}\033[0m\n\n");
    }
    /*-----------------------------------------------------------------------------------------*/
    int *h;
    h = (int*)calloc(11, sizeof(int));  /*opening more than needed, just for safety and I couldn't be bothered to optimize the program and make it as efficient as possible and etc. since it isn't requested.*/
    hist_of_firstdigits(&generate_sequence, xs, seqlen, h, 0);
    printf("\nHistogram of the sequence: \033[1;7;31m{");
    for(int i = 0; i < 9; i++)
        printf("%d, ", h[i]);
    printf("\b\b}\033[0m\n");

    free(h);
    free(loop);
    return 0;
}