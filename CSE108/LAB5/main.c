#include <stdio.h>

void display(int a)
{
    printf("%d     ",a);   //prints the array when used in a loop
}


int main()
{
    int menu,i,j,k,l;
    int kernel[] = {-1,1,-1};
    int ten_arr[11];
    int mult[11];
    int tbt1[3][3];
    int tbt2[3][3];
    int res[3][3];
    do
    {
        printf("Choose the matrix operation,\n------------------------------------\n1. Convolutional Filter for 1D array\n2. Multiplication\n3. Traace\n4. Transpose\n5. Exit\n-----------------------------------\nEnter your choice:");
        scanf("%d",&menu);
        if(menu == 1)
        {
            printf("Enter a 1D array: ");
            for(i = 0; i < 10; i++)
                scanf(" %d",&ten_arr[i]);
            for(i = 0; i < 8; i++)
            {
                j = i;
                mult[i] = (kernel[0]*ten_arr[j])+(kernel[1]*ten_arr[j + 1])+(kernel[2]*ten_arr[j + 2]);     //performs the multiplication operation
            }
            printf("1D Array\n");
            for(i = 0; i < 10; i++)
            {
                display(ten_arr[i]);           //prints ten array
            }
            printf("\n");
            printf("Convolutional Filter Result:\n");
            for(i = 0; i < 8; i++)
            {
                display(mult[i]);           //prints filter array
            }
            printf("\n");
        }
        else if(menu == 2)
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    scanf(" %d",&tbt1[i][j]);
                }
            }
            printf("First Matrix:\n");
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    display(tbt1[i][j]);
                    printf("    ");
                }
                printf("\n");
            }
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    scanf(" %d",&tbt2[i][j]);
                }
            }
            printf("Second Matrix:\n");
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    display(tbt2[i][j]);
                    printf("    ");
                }
                printf("\n");
            }
            printf("Multiplication of matrix:\n");
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    res[i][j] = tbt1[i][j]*tbt2[i][j];
                    
                }
                display(res[i][j]);
                    printf("    ");
                printf("\n");
            }
        }
        else if(menu == 2)
        {}
        else if(menu == 2)
        {}
    }while(menu!=5);
    return 0;
}