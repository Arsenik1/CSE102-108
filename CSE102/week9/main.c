#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_BLOCK_SIZE 10

typedef struct
{
	int *array;
	int currentsize;
	int maxsize;
} stack;

void push(stack *s, int d); /* the stack array will grow STACK_BLOCK_SIZE entries at
a time */

int pop(stack *s); /* the stack array will shrink STACK_BLOCK_SIZE entries at a
time */

stack *init_return(); /* initializes an empty stack */

int init(stack *s); /* returns 1 if initialization is successful */

stack *updateSmallest(int *smallest, stack *s1, stack *s2, stack *s3);

void clearAll(stack *s1, int diskAmount);

int giveLastElement(stack *s);

int main()
{
	stack *s1 = init_return(), *s2 = init_return(), *s3 = init_return(); /*declaring and initializing here*/
	stack *sTemp = s1;	/*holds the smallest disk's peg*/
	int smallest = 1;	/*smallest disk's peg index*/
	int i;
	stack *first = s2, *second = s3; /*holds the comparison stacks (stacks except the one that has the smallest)*/
	int peg = 1;	/*holds current peg*/
	int save, temp;		/*is used for temporarily saving things*/
	int diskAmount;
	
	printf("\033[1;37mHow many disks do you want?\n :");
	scanf("%d", &diskAmount);
	if(diskAmount >= 10)	/*if initialization is not enough, */
	{
		s2->array = (int *)realloc(s2->array, sizeof(int) * (diskAmount + 2));
		s3->array = (int *)realloc(s3->array, sizeof(int) * (diskAmount + 2));
	}
	clearAll(s1, diskAmount + 1);	/*fills all spaces with zeros, filling more than one space, used for safety and to create a boundary with zeros.*/
	clearAll(s2, diskAmount + 1);
	clearAll(s3, diskAmount + 1);
	while(getchar() != '\n');	/*fflush*/
	for(int i = 0; i < diskAmount; i++)	push(s1, diskAmount - i);

	peg = 1;	/*initializing the current peg, always has one of the three values: 1, 2, and 3.*/
	while(peg < 4)
	{
		printf("\nPeg1	Peg2	Peg3");
		for(i = diskAmount - 1; i >= 0; i--)	printf("\n %d\t %d\t %d",s1->array[i], s2->array[i],s3->array[i]);
		printf("\n");
		temp = pop(sTemp);								/*in my algorithm, smallest disk always moves in a certain route, which is; peg1-> peg2-> peg3 and then so on.*/
		sTemp = updateSmallest(&smallest, s1, s2, s3);	/*this part does that.*/
		push(sTemp, temp);
		save = smallest;	/*this line is used for comparing the two pegs other than the one containing the smallest.*/

		first = updateSmallest(&save, s1, s2, s3);	/*updateSmallest used for a different purpose in here. it is used for*/
		second = updateSmallest(&save, s1, s2, s3);	/*assigning first and second stacks with the stacks other than the one containing the smallest disk.*/
		if(giveLastElement(first) > giveLastElement(second))	/*in this if chain, the algorithm just makes the remaining legal move. there will always be*/
		{														/*one legal move remaining after I move the smallest one. there is only one legal move when we make operation with only two pegs.*/
			if(giveLastElement(second) > 0)	push(first,pop(second));
			else	push(second,pop(first));
		}
		else if(giveLastElement(first) < giveLastElement(second))
		{
			if(giveLastElement(first) > 0)	push(second,pop(first));
			else	push(first,pop(second));
		}
		/*-EXPLAINING ABOVE-  If neither of them are empty, then put the smaller disk to the other peg. if one is empty, then put the disk to the empty one.*/
		if((s3->array[diskAmount - 1] == 1 && s3->array[0] == diskAmount))	/*game end check. since I play only with legal moves, this condition only applies when they are placed back to back.*/
			{
				printf("\nPeg1	Peg2	Peg3");
				for(i = diskAmount; i >= 0; i--)	printf("\n%d\t%d\t%d",s1->array[i], s2->array[i],s3->array[i]);
				printf("\nThe game has ended.\n");
				break;
			}
		printf("\n\nPress ENTER\n");
		while(getchar() != '\n');
		peg++;
		if(peg == 4)
			peg = 1;
	}
	if(diskAmount <= 10)		/*this part gave error in my machine. It has something to do about my linux system. When i debugged it, it said "/sysdeps/unix/sysv/linux/raise.c: No such file or directory.", seems like a system error.*/
	{						/*if you want, you can delete this condition. It only gives an error message when the program ends so the program still finishes the came succesfully. the program does not free if more than 10 disks are entered. All modern operating systems automatically free it anyway.*/
		free(s1);
		free(s2);
		free(s3);
	}
	return 0;
}

int giveLastElement(stack *s)	/*gives the last element without changing the stack*/
{
	int temp = pop(s);
	push(s, temp);
	return temp;
}

void clearAll(stack *s1, int diskAmount)	/*fills stack with zero*/
{
	for(int i = 0; i < diskAmount; i++)	s1->array[i] = 0;
}

stack *updateSmallest(int *smallest, stack *s1, stack *s2, stack *s3)	/*moves the smallest disk's peg index by one and retruns it's corresponding peg stack.*/
{	
	(*smallest)++;
	if(*smallest == 4) *smallest = 1;
	
	switch (*smallest)
		{
		case 1: return s1;
		case 2: return s2;
		case 3:return s3;
		default:return NULL;;
		}
}

void push(stack *s, int d) /* the stack array will grow STACK_BLOCK_SIZE entries at a time*/
{
	if(s->currentsize + 2 == s->maxsize) /*resizes if it comes to the boundary*/
	{
		s->array = (int *)realloc(s->array, sizeof(int) * (s->maxsize + STACK_BLOCK_SIZE));
		s->maxsize += STACK_BLOCK_SIZE;
	}
	s->array[s->currentsize] = d;	/*assigning the last element and updating the last element index*/
	(s->currentsize)++;
}

int pop(stack *s)/*pops the last element only if the stack is not empty.*/
{
	if(s->currentsize >= 0)
	{
		int temp = s->array[s->currentsize - 1];
		s->array[s->currentsize - 1] = 0;
		(s->currentsize)--;
		return temp;
	}
	else return -2;
}

stack *init_return()	/*initializes the stack and returns it's pointer*/
{
	stack *s = NULL;
	while(!init(s))	/*while it is uninitialied, it tries again and again*/
	{
		s = (stack *)malloc(sizeof(stack) * 1);
		s->array = (int *)malloc(sizeof(int) * STACK_BLOCK_SIZE);
		s->currentsize = 0;
		s->maxsize = 0;
	}
	return s;
}

int init(stack *s)	/*returns the validity of a given stack*/
{
	if (s == NULL || s->array == NULL)
		return 0;
	else
		return 1;
}