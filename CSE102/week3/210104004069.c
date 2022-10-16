#include <stdio.h>

void printhashtag(int x, int y, int a, int b, int c)       /*This function takes the cursor back and if the equation satisties, it puts a '#' and then goes back to it's*/
{                                                          /*original position.*/
    if(x == a*(y*y) + b*y + c)
    {
        printf("\033[1D");      /*'D' in the printf means 'left' and the number before it is how many characters you want to go that way.*/
        printf("\33[0;34m#");
    }
    else if(x - 1 == a*(y*y) + b*y + c)
    {
        printf("\033[2D");
        printf("\33[0;34m#");
        printf("\033[1C");      /*'C' means 'right'. It takes cursor x+1 times to the right. x is the number before 'C'.*/
    }
    else if(x - 2 == a*(y*y) + b*y + c)
    {
        printf("\033[3D");
        printf("\33[0;34m#");
        printf("\033[1C");
    }
}

int main()
{
    int menu = 0;
    FILE *ptr;
    int a = 0,b = 0, c = 0;
    int i = 0, j = 0, k = 0;
    int x = 0, y = 0;
    int temp1 = 0, temp2 = 0;
    while(1)
    {
        printf("\33[0;37mSelect an operation...\n1 -> Enter the coefficients.\n2 -> Draw the graph.\n3 -> Print the graph into a .txt file.\n4 -> Exit.\n\nChoice: ");
        scanf(" %d",&menu);
        if(menu == 1)
        {
            printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n\na: ");
            scanf(" %d",&a);
            printf("\nb: ");
            scanf(" %d",&b);
            printf("\nc: ");
            scanf(" %d",&c);
            ptr = fopen("coefficients.txt","w+");
            if (ptr == NULL)
                printf("\n\ncoefficients.txt file couldn't be created.");
            else
            {
                fprintf(ptr,"%d",a);        /*Writing to file line by line.*/
                fprintf(ptr,"%c",'\n');
                fprintf(ptr,"%d",b);
                fprintf(ptr,"%c",'\n');
                fprintf(ptr,"%d",c);
                fprintf(ptr,"%c",'\n');
            }
            fclose(ptr);
        }
        else if(menu == 2)
        {
            ptr = fopen("coefficients.txt","r");
            if(ptr == NULL)
                printf("-ERROR- The file couldn't be read.");
            else
            {
                fscanf(ptr," %d",&a);       /*Reading coefficients*/
                fscanf(ptr," %d",&b);
                fscanf(ptr," %d",&c);
                printf("\nCoefficients has been read from the coefficient.txt file.\nPrinting the graph of x=%d*(y*y) + %d*y + %d\n",a,b,c);
                printf("\33[0;37m                                                        ^\n");
                for(y = 15; y >= -15; y--)
                {
                    if (y == 0) printf("\33[0;37m<");
                    else printf("\33[0;37m ");
                    for(x = -55; x <= 55; x++)
                    {
                        if(x == a*(y*y) + b*y + c)      /*First ifs are in priority. If a '#' is printed, x value is increased immediately.*/
                            {
                                printf("\33[0;34m#");
                            }
                        else{
                        if(x == 0) printf("\33[0;37m|");
                        else if(y == 0) printf("\33[0;37m-");
                        else if(x == -4 && y % 5 == 0 && y != 0) 
                        {
                            printf("\33[0;33m%d",y);
                            if(y<0 && y>-10)
                            {
                                x += 1;                             /*You'll see a few from this. For example when we print 2 digits at once, x value has to*/
                                printhashtag(x,y,a,b,c);            /*be increased by 1 because it is taking +1 more places.*/
                            }
                            else if(y<10 && y>=0);
                            else if(y>0) 
                            {
                                x += 1;
                                printhashtag(x,y,a,b,c);            /*If I don't use this function the program will skip some x values. This function prevents it.*/
                            }
                            else
                            { 
                                x += 2;
                                printhashtag(x,y,a,b,c); 
                            }
                        }
                        else if(y == -1 && x % 10 == 0 && x != 0)
                        {
                            temp1 = x;
                                printf("\33[0;33m%d",temp1);
                            if(x > 0) printhashtag(x,y,a,b,c);
                            else x = x + 2;
                                printhashtag(x,y,a,b,c);
                        }
                        else if(x == -1 && y == -1) printf("\33[0;33m0");
                        else printf("\33[0;37m ");
                        }
                    }
                    if (y == 0) printf("\33[0;37m>");
                    printf("\33[0;37m a\n");
                }
            }
            fclose(ptr);
        }
        else if(menu == 3)                          /*This is basically a copy of the second menu except numbers and colors. In addition, fprintf is used instead of printf.*/
        {
            ptr = fopen("coefficients.txt","r");
            if(ptr == NULL)
                printf("-ERROR- The file couldn't be read.");
            else
            {
                fscanf(ptr," %d",&a);
                fscanf(ptr," %d",&b);
                fscanf(ptr," %d",&c);
                fclose(ptr);
                printf("\nCoefficients has been read from the coefficient.txt file.\nThe graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt file. \n",a,b,c);
                ptr = fopen("graph.txt","w+");
                fprintf(ptr,"%s","                                                        ^\n");
                for(y = 15; y >= -15; y--)
                {
                    if (y == 0) fprintf(ptr,"%c",'<');
                    else fprintf(ptr,"%c",' ');
                    for(x = -55; x <= 55; x++)
                    {
                        if(x == a*(y*y) + b*y + c)
                            {
                                fprintf(ptr,"%c",'#');
                            }
                        else{
                        if(x == 0) fprintf(ptr,"%c",'|');
                        else if(y == 0) fprintf(ptr,"%c",'-');
                        else fprintf(ptr,"%c",' ');
                        }
                    }
                    if (y == 0) fprintf(ptr,"%c",'>');
                    fprintf(ptr,"%c",'\n');
                }
            }
            fclose(ptr);
        }
        else if(menu == 4)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid entry. Please try again.\n");
        }
    }
    return 0;
}