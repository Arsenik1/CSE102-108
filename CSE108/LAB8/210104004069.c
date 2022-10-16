#include <stdio.h>
#include <string.h>

void reverse(char str[], char reversed[], int i)
{
        reversed[0] = str[i - 1];
    if(str[i - 1] && i != 0)
        reverse(str, reversed + 1, i - 1);  /*decreases str index by 1 and increases reversed array by 1.*/
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1, n2 = r - q;
    int L[n1], M[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for(int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j]; 

        int i = 0, j = 0, k;
        k = p;

        while(i < n1 && j < n2)
        {
            if(L[i] <= M[j])
            {
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = M[j];
                j++;
            }
            k++;
        }
        while(i < n1)
        {
            arr[k] = L[i];
            k++;
            i++;
        }
        while(j < n2)
        {
            arr[k] = M[j];
            k++;
            j++;
        }
}

void mergeSort(int arr[], int l, int r)
{
    int m = (r + l) / 2;
    if(m - l != 2)
        mergeSort(arr, l, m);
    if(r - m + 1 != 2)
        mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
//5 3 3
//6 3 4


int main()
{
    int menu;
    char src[100] = "aMerreMa";
    char dest[100];
    int arr[100] = {6, 5, 12, 10, 9, 1};
    int n;
    while(1)
    {
        printf("Select operation: ");
        scanf("%d", &menu);
        if(menu == 1)
        {
            n = 0;
            reverse(src, dest, strlen(src));
            if(strcmp(src,dest) == 0)
                printf("\nPalindrome\n");
        }
        else if (menu == 2)
        {
            mergeSort(arr, 0, 5);
            for(n = 0; n < 6; n++)
                printf("%d ", arr[n]);
        }
        else
            return 0;
    }
}