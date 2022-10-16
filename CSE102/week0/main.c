#include <stdio.h>
#include "util.h"
#include <stdlib.h>

int find_divisible(int x, int y, int z);
int find_nth_divisible(int n, int f_I, int z);
int create_customer(char identity_number [ ], int password);
int validate_identity_number(char identity_number []);
int check_login(char identity_number [ ], int password);
int withdrawable_amount(float cash_amount);

int main()
{

	int menucounter=0; /*Using this, part 3 will only be available if part 2 is success.*/
	int x,y,z;
	int find=0;
	int nbr=0;
	int nth=0;
	int menu=0;
	int boo=0;
	char tc[15];

	while(1){
	printf("\n\n\nMAIN MENU\n\n1-Calculate nth number between two numbers\n2-Register account with TC and PIN\n");

	if(menucounter!=0)
		printf("3-Log in to the ATM system and withdraw");
	else
		printf("**Log in system will be enabled after you register**");

	printf("\n0-EXIT\n\nEnter a number:");
	scanf("%d",&menu);

	printf("\e[2J\e[H");
	if(menu==1){
	printf("Enter the first integer:");
	scanf("%d",&x);
	
	printf("\n\nEnter the second integer:");
	scanf("%d",&y);
	
	printf("\n\nEnter the divisor:");
	scanf("%d",&z);
	find=find_divisible(x,y,z);
	if((find==-999) || (find==-1))
		printf("\n\nOutput> There is not any integer between %d and %d can be divided by %d",x,y,z);	
	else
	{
		printf("\n\nOutput> The first integer between %d and %d divided by %d is %d\n\nEnter the number how many next:",x,y,z,find);
		scanf("%d",&nth);
		nbr=find_nth_divisible(nth,find,z);
		if(nbr>y)
			printf("\n\nOutput> There is not any integer between %d and %d can be divided by %d",x,y,z);	
		else
			printf("\n\nThe 3rd integer between %d and %d divided by %d is %d",x,y,z,nbr);
	}

	}

	else if(menu==2){

	printf("\e[2J\e[H");
	
	if(menucounter!=0)
		printf("You have registered before. Your old account will be removed.");

	printf("\n\nPlease enter the TC you want to sign:");
	scanf("%s",tc);

	boo=validate_identity_number(tc);
	if(boo==1){
		printf("\n\nTC is valid. Please enter the 4 digit password:");
		scanf("%d",&nbr);
		boo=create_customer(tc,nbr);
		if(boo==1)
		{
			printf("\n\nYour account has been registered succesfully.");
			menucounter++;	
		}
		else
		{
			printf("\n\nYour account couldn't been registered. \nYour password may not be 4 digits long. Make sure you entered a 4 digit password.");
			menucounter=0;
		}
	}
	else
		printf("Not a valid TC.");
	}
	else if(menu==3 && menucounter!=0){

	printf("\e[2J\e[H");

	int pass=0;
	float num=0;

	printf("Enter your identity number:");
	scanf("%s",&tc[0]);

	printf("\n\nEnter your password:");
	scanf("%d",&pass);

	boo=check_login(tc,pass);

	if(boo==1)
	{
		printf("\n\nOutput> “Login Successful”");
		printf("\n\nEnter your withdraw amount:");
		scanf("%f",&num);
		nbr=withdrawable_amount(num);
		if(nbr==0)
		{
			printf("You can't withdraw negative amount.\n\nExiting..");
		}
		else{
			printf("Output> Withdrawable amount is: %d",nbr);
		}
	}
	else
	{
		printf("\n\nOutput> “Invalid identity number or password”");
	}
	}
	else if(menu==0)
		break;
	else 
	{
		printf("\nInvalid input.");
	}
	}
	return (0);
}
