#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14
#define MAX_INT 1000000

struct Coordinates
{
    int x;
    int y;
};
struct Circle
{
    struct Coordinates points[2];   /*struct inside struct*/
    float radius;
    float perimeter;
    float area;
};

int is_prime(int a)     /*looks if it is prime*/
{
    for(int i = 2; i < a /2;i++)
        if(a%i == 0)
            return 0;
    return 1;
}

void factorization(int a)       /*finds prime factors*/
{
	for(int i = 2; i <= a && is_prime(i) == 1; i++)
		if(a%i==0)
			{printf("\n%d", a); factorization(a/i);}
}

void print_struct(struct Circle *circle, int noCircles, float max, int depth)
{
    int i = 0;
    int max_idx = 0;
    int temp;
    int flag = 0;
    if(depth > 0)
    {
        for(i = 0; i < noCircles; i++)
        {
            if(circle[i].radius < max && flag == 0)     /*finds the biggest number that is smaller than max value.*/
            {
                    max_idx = i;
                    flag = 1;       /*to initialize temp, a flag is used.*/
                    temp = circle[max_idx].radius;
            }
            else if(circle[max_idx].radius < circle[i].radius && circle[i].radius > temp&& circle[i].radius < max)
            {
                    max_idx = i;
                    temp = circle[max_idx].radius;
            }   
    }
    print_struct(circle, noCircles, circle[max_idx].radius, depth - 1);
    printf("\nCircle %d         Radius: %.2f      Perimeter: %.2f       Area: %.2f", max_idx + 1, circle[max_idx].radius, circle[max_idx].perimeter, circle[max_idx].area);
    }
}
int main()
{
    struct Circle circle[10];
    int noCircles = 0;
    int i = 0, j = 0;
    int sort[10];
    int temp;
    printf("Number of circles: ");
    scanf("%d", &noCircles);
    for(i = 0; i < noCircles; i++)
    {
        printf("Circle %d...\n\n", i + 1);
        printf("Coordinates of center(x,y): ");
        scanf("%d %d", &circle[i].points[0].x, &circle[i].points[0].y); 
        printf("Coordinates of point P: ");
        scanf("%d %d", &circle[i].points[1].x, &circle[i].points[1].y);
        circle[i].radius = sqrt((circle[i].points[0].y - circle[i].points[1].y) * (circle[i].points[0].y - circle[i].points[1].y) + (circle[i].points[0].x - circle[i].points[1].x) * (circle[i].points[0].x - circle[i].points[1].x));
        circle[i].perimeter = (circle[i].radius)*(2)*3.14;      /*calculations*/
        circle[i].area = circle[i].radius*circle[i].radius*3.14;
    }
    for(i = 0; i < noCircles; i++)
        sort[i] = i;

    printf("Printing circles in an ascending order...\n\n");
    // for(i = 0; i < noCircles; i++)
        // printf("\nCircle %d         Radius: %.2f      Perimeter: %.2f       Area: %.2f", i + 1, circle[i].radius, circle[i].perimeter, circle[i].area);

    print_struct(circle, noCircles, MAX_INT, noCircles);
    printf("\n\n\n");
    int prime = 0;
    scanf("%d", &prime);
    factorization(prime);
    return 0;
}