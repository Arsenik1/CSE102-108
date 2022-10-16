#include <stdio.h>

typedef enum {sunday, monday, tuesday, wednesday, thursday, friday, saturday}Days;
typedef enum {harddisk, monitor, keyboard, mouse}Products;
typedef enum {buy = 1, orders, prices, exit}Selections;
typedef enum {Harddisk = 2, Monitor = 5, Keyboard = 3, Mouse = 10}Prices;
typedef enum {dolar = 4, euro = 5, pound = 0, peso = 10}Currencies;


void print_days(int day)
{
    Days days;
    days = day;
    switch(days)
    {
        
        case sunday: printf("Sunday"); break;
        case monday: printf("Monday"); break;
        case tuesday: printf("Tuesday"); break;
        case wednesday: printf("Wednesday"); break;
        case thursday: printf("Thursday"); break;
        case friday: printf("Friday"); break;
        case saturday: printf("Saturday"); break;
    }
}

void readOrderFile(void (*f)(int))
{
    FILE *ptr;
    int a = 0;
    int b = 0;
    ptr = fopen("orders.txt","r");
    while(!feof(ptr))
    {   
        if(!feof(ptr))
            fscanf(ptr," %d",&a);
        else break;
        if(!feof(ptr))
        fscanf(ptr," %d",&b);
        else break;
        printf("Product ID: %d,Day: ",a);
        (*f)(b);
        printf("\n");
    }
    fclose(ptr);
}

int TL(int price, int curr)
{
    return price*curr;
}
int sum(int a, int b)
{
    return a+b;
}

void all(void (*a)(int), int (*b)(int,int), int (*c)(int,int))
{
    Products prod;
    Currencies cur;
    Prices pric;
    FILE *ptr;
    ptr = fopen("orders.txt","r");
    int summ, temp1, temp2;
    while(!feof(ptr))
    {
        printf("Product: ");
        if(!feof(ptr))
            fscanf(ptr," %d",&temp1);
        else break;
        pric = temp1;
        temp1 = (*b)(temp1,pric);
        summ = (*c)(summ,temp1);
        prod = temp1;
        if(prod == harddisk ) printf("Harddisk");
        else if(prod == monitor ) printf("Monitor");
        else if(prod == keyboard ) printf("Keyboard");
        else if(prod == mouse ) printf("Mouse");
        printf(",Day:");
        fscanf(ptr," %d",&temp1);
        (*a)(temp1);
        
        printf("\n");
    }
    printf("%d",summ);
    fclose(ptr);
}

int main()
{
    int i, j, k, l;
    int sum = 0;
    int temp = 0;
    void *point1 = &print_days;
    void *point2 = &TL;
    void *point3 = &sum;
    FILE *ptr;
    Selections menu;
    Products product;
    Days day;
    do
    {
        printf("Welcome to the TechMarket.\n 1. Buy Product\n 2. Orders\n 3. All Orders Prices\n 4. EXIT\n -------------------------------------------------\n");
        scanf("%d",&l);
        menu = l;
        if(menu == buy)
        {
            printf("Select your prodct:\n 0. Harddisk\n 1. Monitor\n 2. Keyboard\n 3. Mouse\n 4. GO TO MAIN MENU\n -------------------------------------------------\n");
            scanf("%d",&k);
            product = k;
            if(product == harddisk)
            {
                printf("Select your arrival day[0-6]:\n Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n -------------------------------------------------\n");
                scanf("%d",&j);
                day = j;
                ptr = fopen("orders.txt","a");
                fprintf(ptr,"%d %d\n",product,day);
                fclose(ptr);
            }
            else if(product == monitor)
            {
                printf("Select your arrival day[0-6]:\n Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n -------------------------------------------------\n");
                scanf("%d",&j);
                day = j;
                ptr = fopen("orders.txt","a");
                fprintf(ptr,"%d %d\n",product,day);
                fclose(ptr);
            }
            else if(product == keyboard)
            {
                printf("Select your arrival day[0-6]:\n Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n -------------------------------------------------\n");
                scanf("%d",&j);
                day = j;
                ptr = fopen("orders.txt","a");
                fprintf(ptr,"%d %d\n",product,day);
                fclose(ptr);
            }
            else if(product == mouse)
            {
                printf("Select your arrival day[0-6]:\n Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n -------------------------------------------------\n");
                scanf("%d",&j);
                day = j;
                ptr = fopen("orders.txt","a");
                fprintf(ptr,"%d %d\n",product,day);
                fclose(ptr);
            }
        }
        else if(menu == orders)
        {
            readOrderFile(point1);
        }
        else if(menu == prices)
        {
            all(point1, point2, point3);   
        }
    }while(menu != exit);
    return 0;
}