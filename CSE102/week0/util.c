#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

int find_divisible(int x, int y, int z)
{
	x=x+1;
	if(x>y)
		return -1;	/*Reverse limits lead to error.*/

	while(x<y)
	{
		if(x%z==0)
			return x;	/*Sends the first divisible integer if there is one.*/
		x++;
	}
	return -1;	/*If the program gets out of the while loop above, it means that there is no divisible number between limits so it returns an error code.*/
}

int find_nth_divisible(int n, int f_I, int z)
{
	int i=0;
	int nb=0;
	if(n<0)
		return -999;	/*There cant be a negative nth number so error code returned.*/

	nb=f_I+z*n;	/*Here calculates the nth number but since we don't know the upper limit, this function can't control if it is out of bonds or not.*/
	return nb;
}

int validate_identity_number(char identity_number [])
{
	int i=0;
	int check=0;	/*There are a total of 5 conditions for validation. So if this variable is equal to 5 at the and, it means our number is valid.*/

	while(identity_number[i++]!='\0');	/*Checking the length*/
	
	i--;
	if(i==11)
		check++;
	i=0;

	while(identity_number[i]>='0' && identity_number[i]<='9' && i<11)
		i++;
	if(i==11)
		check++;	/*Checking if there is any number that is not numeric.*/
	
	if(identity_number[0]!=0 && identity_number[0]>='0' && identity_number[0]<='9')	/*Checking if the first element is zero or not.*/
			check++;

	if(((identity_number[0]+identity_number[2]+identity_number[4]+identity_number[6]+identity_number[8]-5*48)*7
			-(identity_number[1]+identity_number[3]+identity_number[5]+identity_number[7]-4*48))%10==identity_number[9]-'0')
		check++;	/*Checking the fourth rule on the pdf*/
	if((identity_number[0]+identity_number[1]+identity_number[2]+identity_number[3]+identity_number[4]+identity_number[5]
				+identity_number[6]+identity_number[7]+identity_number[8]+identity_number[9]-10*'0')%10==identity_number[10]-'0')
		check++;	/*Checking the fifth rule on the pdf. It is looking a little messy but it is just a mathematical formula after all.*/
	if(check==5)
		return 1;	/*Valid*/
	else
		return 0;	/*Invalid*/
}

int create_customer(char identity_number [ ], int password)
{
	FILE *fptr;
	char *arr;
	int i=0;

	fptr=fopen("customeraccount.txt","w");
	
	if(fptr==NULL || (password<1000 && password > 9999))	/*If the password is not 4 digits or file couldn't be opened, returns FALSE.*/
		return 0;
	
	arr=(char *)malloc(sizeof(char)*(11+3+4)+1); /*Opening static memory for 11 digit TC, space, comma, space, 4 digit password and 1 extra space for NULL termination.*/

	while(i<11)
	{
		arr[i]=identity_number[i];
		i++;
	}
	arr[i++]=' ';
	arr[i++]=',';
	arr[i++]=' ';
	i=i+3;
	while(i>13)
	{
		arr[i]=password%10+48;
		password=password/10;	/*Extracting int form of password to char array.*/
		i--;
	}
	i+=5;
	arr[i]='\0';
	

	fprintf(fptr,"%s",&arr[0]);

	fclose(fptr);

	return	1;
}

int check_login(char identity_number [ ], int password)
{
	FILE *fptr;
	char arr[255];
	char control[255];
	int i=0;
	int boo=0;

	fptr=fopen("customeraccount.txt","r");

	for(i=0;i<18;i++)
	fscanf(fptr,"%c",&control[i]);

        control[i]='\0';

	i=0;
	while(arr[i]==control[i])
		i++;

	while(i<11)
        {
                arr[i]=identity_number[i];
                i++;
        }
        arr[i++]=' ';
        arr[i++]=',';
        arr[i++]=' ';
        i=i+3;
        while(i>13)
        {
                arr[i]=password%10+48;
                password=password/10;
                i--;
        }
        i+=5;
        arr[i]='\0';

	i=0;

	while(arr[i]==control[i])
		i++;

	if(i==19)
	{
		return 1;
	}


	return 0;
}

int withdrawable_amount(float cash_amount)
{
	float num;

	num=cash_amount;

	if(num<0)
		return 0;
	num=num-((int)num%10);

	return num;
}
