#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

/*
    Function: alphabeticSort
    --------------------------
    It does: sort n number of strings

    n:  number of strings
    MAX_LEN:maximum number of string length
    arr:holds the strings



    returns:nothing since it is void

*/void alphabeticSort(char a[MAX_LEN][MAX_LEN], int n);

/*
    Function: alphabeticSort
    --------------------------
    It does: put signs at the beginning

    temp:holds the temporary values while we manipulate array values
    arr:contains given string



    returns:nothing since it is void but the changes done to array are being carried to main since we modify the original values. 

*/void generateTagParser(char temp[], char arr[]);




int main()
{
    int n = 0, i = 0;
    char a[MAX_LEN][MAX_LEN];
    char arr[MAX_LEN];
    char temp[MAX_LEN];
    int menu = 0;
    do
    {
    printf("\n1- Part 1 (Sort Strings)\n2- Part 2 (Generate Tag Parser)\n0- EXIT\nChoice: ");
    scanf("%d", &menu);
    switch(menu)
    {
        default: printf("\nERROR ! Invalid operation.\n");

        case 1:
        printf("\nEnter count: ");            //nothing to explain here since all the computation is in functions.
        scanf("%d",&n);

        for(i = 0; i < n; i++)
        {
            printf("\nEnter %dth word: ",i+1);
            scanf("%s",a[i]);
        }
        printf("\n");
        for(i = 0; i < n; i++)
        {
            printf("\n%dth word: %s\n",i+1,a[i]);
        }
        printf("\n------------------------------------\n");
        alphabeticSort(a,n);
        printf("\n");
        
    for(i = 0; i < n; i++)
        {
            printf("\n%dth word: %s\n",i+1,a[i]);
        }
        break;

        case 2:
        
        printf("\nEnter string: ");
        scanf("%s", arr);
        generateTagParser(temp, arr);
        printf("\n%s", arr);
        break;

        case 0: break;
    }
    }while(menu != 0);
    return 0;
}


void alphabeticSort(char a[MAX_LEN][MAX_LEN], int n)
{
    int i = 0, j = 0;
    char temp[MAX_LEN];
    int compare = 0;
    
    for(i = 0; i < n-1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            compare = strcmp(a[i],a[j]);        //if the one on the left side is greater in terms of alphabetical order, function returns 1.
            if(compare > 0)                     //this only works if a[i] is greater than a[j].
            {
                // temp = a[i];
                // a[i] = a[j];         //same logic
                // a[j] = temp;
                strcpy(temp,a[i]);      //swaps them
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
                
            }
        }
    }
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

void generateTagParser(char temp[], char arr[])
{
    int i = 0, j = 0, wordcount = 0;
    char *place = NULL;
    wordcount = strlen(arr);                //to know the where to put signs, program takes the length of string with strlen(). This can also be made with a simple while loop.
    if(wordcount < 5)
    {
        temp[0] = '<';                      /*Every if statement logic: in the beginning tag is being placed, string in 'arr' is being copied               */ 
        temp[1] = '<';                      /*and at the end; first, the tags have been put on top of null and secondly, string has been null terminated.   */
        place = &temp[2];
        strcpy(place, arr);
        temp[wordcount + 2] = '>';
        temp[wordcount + 3] = '>';
        temp[wordcount + 4] = '\0';
    }
    else if(wordcount > 10)
    {
        temp[0] = '/';
        temp[1] = '+';
        place = &temp[2];
        strcpy(place, arr);
        temp[wordcount + 2] = '+';
        temp[wordcount + 3] = '/';
        temp[wordcount + 4] = '\0';
    }
    else if(wordcount >= 5)              //this only applies when the upper if's aren't true so this only works when 5 <= wordcount <= 10
    {
        temp[0] = '*';
        place = &temp[1];
        strcpy(place, arr);
        temp[wordcount + 1] = '*';
        temp[wordcount + 2] = '\0';
    }
    strcpy(arr, temp);      //lastly for convenience, the string in "temp" is copied to "arr" array
}