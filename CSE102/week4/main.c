#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef enum        
{
    Triangle = 1,
    Quadrilateral,
    Circle,
    Pyramid,
    Cylinder
} Shapes;
typedef enum
{
    Area = 1,
    Perimeter,
    Volume
} Calculators;

int select_shape();
int select_calc();
int calculate(int (*select_shape)(void), int (*select_calc)(void));
int calc_triangle(int);
int calc_quadrilateral(int);
int calc_circle(int);
int calc_pyramid(int);
int calc_cylinder(int);

int main()
{
    printf("\33[0;37m");    /*Just white color code for the text*/
    calculate(select_shape, select_calc);   /*Sending functions as arguments as requested*/
    return 0;
}

int select_shape()      /*Here, Shape selection is made. Only shape  menu number inputs are allowed.*/
{
    Shapes shape;
    Calculators calc;
    int a;
    while (1)
    {
        printf("\n\nSelect shape:\n"
               "-------------------------\n"
               "1. Triangle\n"
               "2. Quadrilateral\n"
               "3. Circle\n"
               "4. Pyramid\n"
               "5. Cylinder\n"
               "0. Exit\n"
               "-------------------------\n"
               "Input : "); 
        scanf("%d", &a);

        if (a == Triangle || a == Quadrilateral || a == Circle || a == Pyramid || a == Cylinder || a == 0)  /*Used enums for better understanding*/
            return a;
        else
        {
            printf("\n\n\nERROR ! Invalid entry.");
            while (getchar() != '\n');
        }
    }
}
int select_calc()       /*Here, Calculation selection is made. Only calculation menu number inputs are allowed.*/
{
    Shapes shape;
    Calculators calc;
    int a;
    while (1)
    {
            while (getchar() != '\n');
        printf("\n\nSelect calculator:\n"
               "-------------------------\n"
               "1. Area\n"
               "2. Perimeter\n"
               "3. Volume\n"
               "0. Exit\n"
               "-------------------------\n"
               "Input : "); 
        scanf("%d", &a);
        if (a == Area || a == Perimeter || a == Volume || a == 0)
            return a;
        else
            printf("\n\n\nERROR ! Invalid entry.");
    }
}
int calculate(int select_shape(), int select_calc())
{
    Shapes shape;
    Calculators calc;
    int menu1 = 0, menu2 = 0;
    int result;
    do                              /*A do while loop is used because the menu will show up at least once.*/
    {
        /*At every loop, user sends the shape value to the function and it is returned to a variable named menu1 int this loop.
        According to the value, program goes to the corresponding case and lats user select the calculation operation using select_calc() function.
        menu2 takes the calculation operation value and whis value is being sent to the corresponding calculation function. This loop goes forever until
        user enters 0.*/
        menu1 = select_shape();
        switch (menu1)
        {
        case Triangle:
            menu2 = select_calc();
            if(menu2 == 0)
                return 0;
            calc_triangle(menu2);
            break;
        case Quadrilateral:
            menu2 = select_calc(); 
            if(menu2 == 0)
                return 0;
            calc_quadrilateral(menu2);
            break;
        case Circle:
            menu2 = select_calc(); 
            if(menu2 == 0)
                return 0;
            calc_circle(menu2);
            break;
        case Pyramid:
            menu2 = select_calc(); 
            if(menu2 == 0)
                return 0;
            calc_pyramid(menu2);
            break;
        case Cylinder:
            menu2 = select_calc(); 
            if(menu2 == 0)
                return 0;
            calc_cylinder(menu2);
            break;
        case 0:
            return 0;
        default:
            printf("\n\n\nInvalid Entry.");
            break;
        }
    } while (menu1 != 0 || menu2 != 0);
}
int calc_triangle(int op)
{
    while (1)
    {
        Shapes shape;
        Calculators calc;
        float a = -999, b = -999, c = -999, s, r;       /*If scanf does not read any appropriate value, they stay as -999 and an error message is displayed.*/
        if (op == Volume)
        {
            printf("\n\nERROR ! You cannot calculate the volume of a triangle. Please try again.");
            return 0;
        }
        printf("\n\n\nPlease enter three sides of Triangle: ");  /*!!!!!!!!!!IMPORTANT NOTE!!!!!!!!!!!: When you enter the secund input wrong, you have to start over.*/
        scanf("%f", &a);
        if (a < 0)
        {
            while (getchar() != '\n');      /*Clears the buffer so that the program does not create any buffer complications.*/
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;                       /*Lets user input again.*/
        }
        scanf("%f", &b);
        if (b < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        scanf("%f", &c);
        if (c < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }

        if (a + b > c && b + c > a && a + c > b) /*Validity check*/
        {
            switch (op)
            {
            case Area:
                s = (a + b + c) / 2;
                r = sqrt(s * (s - a) * (s - b) * (s - c));
                printf("\n\nArea of TRIANGLE : %.2f", r);
                return 1;
            case Perimeter:
                r = a + b + c;
                printf("\n\nPerimeter of TRIANGLE : %.2f", r);
                return 1;
            case Volume:    /*The program can't even enter this case since this error is handled at the beginning of the function. */
                printf("\n\nERROR ! You cannot calculate the volume of a triangle. Please try again.");
                break;
            }
        }
        else
        {
            printf("\n\nERROR ! Please enter a valid triangle.");
        }
    }
}
int calc_quadrilateral(int op)      
/*Neccessary comments have been made in the calc_triangle() function so If you want explanation about the things that are similar, 
you can read the comment in that function's similar place.*/
{
    while (1)
    {
        Shapes shape;
        Calculators calc;
        float a = -999, b = -999, c = -999, d = -999, s, r;
        if (op == Volume)
        {
            printf("\n\nERROR ! You cannot calculate the volume of a quadrilateral. Please try again.");
            return 0;
        }
        printf("\n\n\nPlease enter four sides of Quadrilateral: ");
        scanf("%f", &a);
        if (a < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        scanf("%f", &b);
        if (b < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        scanf("%f", &c);
        if (c < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        scanf("%f", &d);
        if (d < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        if (a + b + d > c && d + b + c > a && d + a + c > b && a + b + c > d) /*Validity check*/
        {
        switch (op)
        {
        case Area:
            s = (a + b + c + d) / 2;
            r = sqrt((s - a) * (s - b) * (s - c) * (s - d));
            printf("\n\nArea of QUADRILATERAL : %.2f", r);
            return 1;
        case Perimeter:
            r = a + b + c + d;
            printf("\n\nPerimeter of QUADRILATERAL : %.2f", r);
            return 1;
        case Volume:
            printf("\n\nERROR ! You cannot calculate the volume of a quadrilateral. Please try again.");
            break;
        }
        }
        else
        {
            printf("\n\nERROR ! Please enter a valid quadrilateral.");
        }
    }
}
int calc_circle(int op)             
/*Neccessary comments have been made in the calc_triangle() function so If you want explanation about the things that are similar, 
you can read the comment in that function's similar place.*/
{
    while (1)
    {
        Shapes shape;
        Calculators calc;
        float a = -999, r;
        if (op == Volume)
        {
            printf("\n\nERROR ! You cannot calculate the volume of a Circle. Please try again.");
            return 0;
        }
        printf("\n\n\nPlease enter the radius of Circle: ");
        scanf("%f", &a);
        if (a < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }

        switch (op)
        {
        case Area:
            r = PI * a * a;
            printf("\n\nArea of CIRCLE : %.2f", r);
            return 1;
        case Perimeter:
            r = PI * 2 * r;
            printf("\n\nPerimeter of CIRCLE : %.2f", r);
            return 1;
        case Volume:
            printf("\n\nERROR ! You cannot calculate the volume of a Circle. Please try again.");
            break;
        }
    }
}
int calc_pyramid(int op)            
/*Neccessary comments have been made in the calc_triangle() function so If you want explanation about the things that are similar, 
you can read the comment in that function's similar place.*/
{
    while (1)
    {
        Shapes shape;
        Calculators calc;
        float h = -999, b = -999, r;
        printf("\n\n\nPlease enter the base side and the height of a Pyramid: ");
        scanf("%f", &b);
        if (b < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        scanf("%f", &h);
        if (h < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        switch (op)
        {
        case Area:
            r = b * b;
            printf("\n\nBase Surface Area of a PYRAMID : %.2f", r);
            r = b * 2 * h;
            printf("\n\nLateral Surface Area of a PYRAMID : %.2f", r);
            r = (b * b) + (b * 2 * h);
            printf("\n\nSurface Area of a PYRAMID : %.2f", r);
            return 1;
        case Perimeter:
            r = 4 * b;
            printf("\n\nPerimeter of PYRAMID : %.2f", r);
            return 1;
        case Volume:
            r = b * b * h / 3;
            printf("\n\nVolume of a PYRAMID : %.2f", r);
            return 1;
            break;
        }
    }
}
int calc_cylinder(int op)           
/*Neccessary comments have been made in the calc_triangle() function so If you want explanation about the things that are similar, 
you can read the comment in that function's similar place.*/
{
    while (1)
    {
        float h = -999, b = -999, r;
        printf("\n\n\nPlease enter the radius and the height of a Cylinder: ");
        scanf("%f", &b);
        if (b < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        scanf("%f", &h);
        if (h < 0)
        {
            while (getchar() != '\n');
            printf("\n\nERROR ! Please enter a valid entry.");
            continue;
        }
        switch (op)
        {
        case 1:
            r = PI * b * b;
            printf("\n\nBase Surface Area of a Cylinder : %.2f", r);
            r = 2 * PI * b * h;
            printf("\n\nLateral Surface Area of a Cylinder : %.2f", r);
            r = 2 * PI * b * (b + h);
            printf("\n\nSurface Area of a Cylinder : %.2f", r);
            return 1;
        case 2:
            r = 2 * PI * b;
            printf("\n\nBase Surface Perimeter of Cylinder : %.2f", r);
            return 1;
        case 3:
            r = PI * b * b * h;
            printf("\n\nVolume of a CYLINDER : %.2f", r);
            return 1;
            break;
        }
    }
}