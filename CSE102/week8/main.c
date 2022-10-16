/*IMPORTANT NOTE: I HAD A HARD TIME UNDERSTANDING THIS HOMEWORK EVEN THOUGH MY FRIENDS HAVE ASKED ALL I HAD TO ASK.
  SO PLEASE JUDGE THIS CODE WITH A LITTLE BIT OF TOLERANCE SINCE I HAVE NOT BUILT THIS CODE'S STRUCTURE WITH A COMPLETE
  UNDERSTANDING. I HAVE NEVER MADE PERSONAL CHOICES WHILE CODING THIS PROGRAM, THIS CODE STRUCTURE IS WHAT I UNDERSTOOD.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Person
{
char name[50];
char address[50];
int phone;
};
union Loan
{
float amount;
float interestRate;
int period;
};
struct BankAccount
{
union Person Customer;
union Loan Loans[3];
};

typedef union Person Person;
typedef union Loan Loan;
typedef struct BankAccount BankAccount;

BankAccount account[50];

int gotoline(FILE *ptr, int line) /*goes to a spesific line pointed by line in ptr file.*/
{
	line--;
	rewind(ptr);
	int count = 0;
	char temp;
	while(count < line)
	{
		fscanf(ptr, "%c", &temp);
		if(feof(ptr))
			return -1;
		if(temp == '\n')
			count++;
	}
	return 1;
}

int placeIdToLastLine(FILE *ptr) /*adds new id to the data.*/
{
	int line = 0;
	while(gotoline(ptr, line) != -1)
		line++;
	gotoline(ptr, line - 1);
	fprintf(ptr, "%d,", line - 1);
	return line - 1;
}

int listCustomers(FILE *ptr, int index, int control)
{
	rewind(ptr);
	int phone;
	int temp;
	int enter;
	printf("1- Print all entries within this session\n2- Print all entriesin history in detail\nChoice: ");
	scanf("%d", &enter);
	if(enter == 1)
	{
		if(control == 0)
			{
				printf("\nNo account has been added in this session.");
				return 1;
			}
		index--;
		while(index != 0)
		{
			printf("\n--------------------------\nName: %s\n", account[index].Customer.name);	/*prints all customer names in current session*/
			index--;
		}
		return 1;
	}
	else if(enter == 2)
	{
	const char s[2] = ",";
	char *a = (char *)malloc(sizeof(char) * 200);	/*had to use malloc because strtok() only works with pointers, not arrays.*/
	char *parca = (char *)malloc(sizeof(char) * 52);
	fgets(a, 200, ptr);
	while(!feof(ptr))
	{
		printf("\n-----------------------------------------\n");	/*dividing each line using commas and printing the one by one using strtok()*/
		parca = strtok(a, s);
		printf("ID: %s\n", parca);
		parca = strtok(NULL, s);
		printf("Name: %s\n", parca);
		parca = strtok(NULL, s);
		printf("Address: %s\n", parca);
		parca = strtok(NULL, s);
		printf("Telephone number: %s\n", parca);
		fgets(a, 200, ptr);
	}
	free(a);
	free(parca);
	}
	return 1;
}
int addCustomer (FILE *ptr, int index,Person *customer)
{
	rewind(ptr);
	char name[51] = {};
	char address[51] = {};
	int phone = 0;
	int i;
	while(1)
	{
		printf("Please enter your name:");
		scanf(" %[^\n]%*c", name);				/*getting input until a newline is encountered*/
		if(name[50] == '\0' && name[49] != '\0')		/*error handling, you'll see this in so many places*/
				printf("\nThe entry is too long. Please enter a name which is less than 50 characters.\n");
		else break;
	}
	while(1)
	{
		printf("Please enter your adress:");
		scanf(" %[^\n]%*c", address);
		if(name[50] == '\0' && name[49] != '\0')
				printf("\nThe entry is too long. Please enter a address which is less than 50 characters.\n");
		else break;
	}
	while(1)
	{
		printf("Please enter your phone number:");
		scanf(" %d", &phone);
		if(phone < 0)
			printf("\nPlease enter a valid phone number.\n");	
		else break;
	}
	if(name[0] == 0 || address[0] == 0 || phone == 0)	/*this is an error handling too*/
	{
		printf("\n-ERROR- You have either entered an invalid input or caused a bug. Please try again.\n");
		printf("%s, %s, %d", name, address, phone);
		return -1;	/*-1 return value is used for error and 1 is used for succes throughout this program.*/
	}
	else
	{
		placeIdToLastLine(ptr);				/*this segment sends all values to the struct.*/
		strcpy(account[index].Customer.name, name);
		strcpy(customer->name, name);
		fprintf(ptr, "%s,", customer->name);
		strcpy(customer->address, address);
		fprintf(ptr, "%s,", customer->address);
		customer->phone = phone;
		fprintf(ptr, "%d\n", customer->phone);
		printf("\nThe user has succesfully been registered.");
		return 1;
	}
}
int newLoan (FILE *ptr, int index)
{
	rewind(ptr);
	int line = 0, period = 0, id = 0, temp = 0, counter = 0;
	float amount = 0, interestRate = 0;
	FILE *credit;
	credit = fopen("loans.txt", "r+");			/*error handling for file openings, if it is NULL it is an error.*/
	if(credit == NULL)
		credit = fopen("loans.txt", "w+");
	printf("\nPlease enter the ID you want to apply: ");
	scanf("%d", &id);
	line = id;
	if(line <= 50 && line > 0)	/*boundary check*/
		if(gotoline(ptr, line) == 1)
		{
			line = 1;
			rewind(credit);
			gotoline(credit, line);
			while(!feof(credit))
			{
				fscanf(credit, " %d", &temp);	/*getting id values*/
				if(temp == id)		/*if the corresponding id matches, we increase the counter*/
					counter++;
				line++;
				if(gotoline(credit, line + 1) == -1)	/*this is for the last line which includes only a \n that causes errors so we check the next line each time*/
					break;
				gotoline(credit, line);
			}
			if(counter >= 3)
			{
				printf("\nMaximum loan amount for this user has been maxed out.We're sorry :/ \n");
				fclose(credit);
				return -1;
			}
			printf("\nUser found in database. %d remaining loan for this user. Please enter the loan amount: ", 3 - counter);
			scanf("%f", &amount);
			if(amount <= 0)
			{
				printf("\nInvalid input. For this program to be stable you have to do it all over, we're sorry.\n\n");
				return -1;
			}
			printf("\nPlease enter the period:");
			scanf("%d", &period);
			if(period <= 0)
			{
				printf("\nInvalid input. For this program to be stable you have to do it all over, we're sorry.\n\n");
				return -1;
			}
			printf("\nPlease enter the interest rate:");
			scanf("%f", &interestRate);
			if(interestRate <= 0)
			{
				printf("\nInvalid input. For this program to be stable you have to do it all over, we're sorry.\n\n");
				return -1;
			}
			account[index].Loans[0].amount = amount;			/*filling the struct*/
			account[index].Loans[1].interestRate = interestRate;
			account[index].Loans[2].period = period;
			line = 1;

			rewind(credit);
			while(!feof(credit))
			{
				if(gotoline(credit, line) == -1)	/*getting to the end, instead of using fseek, i used my own function.*/
				{
					gotoline(credit, line - 1);
					fprintf(credit, "%d %.2f %.2f %d\n", id, account[index].Loans[0].amount, account[index].Loans[1].interestRate, account[index].Loans[2].period);
					printf("\nThe application has accepted.\n");
					fclose(credit);
					return 1;
				}
				line++;
			}
			
		}
		else printf("\nUser for this ID couldn't been found.");
	else printf("\nUser for this ID couldn't been found.");
	fclose(credit);
	return -1;
}
float calculateLoan(float amount, int period, float interestRate)
{
	if(period > 1)	/*we decrease the period each time and calculate the same equation again and again.*/
	{
		return (calculateLoan(amount, period - 1, interestRate) * (1 + interestRate));
	}
	else return (amount * (1 + interestRate));

}
void getReport()
{
	int reportmenu = 0;
	FILE *ptr;
	FILE *credit;
	int line = 0, temp = 0, period = 0, id, i = 0, counter = 0;
	float amount = 0, interestRate = 0, temp1 = 0;
	float loans[3] = {};
	credit = fopen("loans.txt", "r");
	ptr = fopen("customers.txt", "r");
	char *a = (char *)malloc(sizeof(char) * 200);
	char *parca = (char *)malloc(sizeof(char) * 52);
	const char s[2] = ",";
	if(ptr == NULL || credit == NULL)
		{
			printf("\nFile couldn't be opened.");
			// free(a);
			// free(parca);
			return ;
		}
	printf("\n1- List all customer details\n2- List a spesific user's loan details\nChoice: ");
	scanf("%d", &reportmenu);
	switch(reportmenu)
	{
		default: printf("\nInvalid Entry.\n");
		case 1:
		fgets(a, 200, ptr);
		while(!feof(ptr))
		{
			printf("\n-----------------------------------------\n");	/*value taking method is similar to the code in selection 1.*/
			parca = strtok(a, s);
			id = atoi(parca);
			printf("ID: %s\n", parca);
			parca = strtok(NULL, s);
			printf("Name: %s\n", parca);
			parca = strtok(NULL, s);
			printf("Address: %s\n", parca);
			parca = strtok(NULL, s);
			printf("Telephone number: %s\n", parca);
			fgets(a, 200, ptr);
			line = 1;
			i = 0;

			rewind(credit);
			while(!feof(credit))
			{
				fscanf(credit, " %d ", &temp);	/*taking values 4 by 4 meaning reading line by line.*/
				fscanf(credit, " %f ", &amount);
				fscanf(credit, " %f ", &interestRate);
				fscanf(credit, " %d ", &period);
				if(temp == id)	/*saving the loan value*/
				{
					loans[i] = calculateLoan(amount, period, interestRate);
					i++;
				}
			}
			if(i == 0) printf("\nLoan info couldn't found.");
			else if(i == 1) printf("\nLoan = [ %.2f ] => %.2f", loans[0], loans[0]);
			else if(i == 2) printf("\nLoan = [ %.2f + %.2f ] => %.2f", loans[0], loans[1], loans[0] + loans[1]);
			else if(i == 3) printf("\nLoan = [ %.2f + %.2f + %.2f ] => %.2f", loans[0], loans[1], loans[2], loans[0] + loans[1] + loans[2]);
		}
		break;
		case 2:
		printf("\nPlease enter the user ID: ");
		scanf("%d", &id);
		line = 1;
		rewind(credit);
		gotoline(credit, line);	/*this segment is used third time here. it finds maximum amount of corresponding id's in loans.txt so that user cannot see over the limits.*/
		while(!feof(credit))
		{
			fscanf(credit, " %d", &temp);
			if(temp == id)
				counter++;
			line++;
			if(gotoline(credit, line + 1) == -1)
				break;
			gotoline(credit, line);
		}
		rewind(credit);
		while(1)			/*error handling*/
		{
			printf("\nWhich loan do you want to show?\n: ");
			scanf("%d", &i);
			if(i <= counter)
				break;
			else
			{
				printf("\nMax loan count exceeded. %d", counter);
				return;
			}
		}
		line = 1;
		rewind(credit);
		gotoline(credit, line);
		counter = 0;
		while(!feof(credit))
		{
			fscanf(credit, " %d", &temp);
			if(temp == id)
				counter++;			/*reading until i'th number of loan. here we calculate and show loan details.*/
			if(counter == i)
			{
				fscanf(credit, " %f ", &amount);
				fscanf(credit, " %f ", &interestRate);
				fscanf(credit, " %d ", &period);
				temp1 = calculateLoan(amount, period, interestRate);
				printf("Total Credit Value: %.4f", temp1);
				temp = period;
				while(period > 0)
				{
					printf("\n%d. Month Installment = %.4f", temp - period + 1, temp1 / (float)temp);
					period--;
				}
				break;
			}
			line++;
			if(gotoline(credit, line + 1) == -1)
				break;
			gotoline(credit, line);
		}
		break;
	}
	// free(a);
	// free(parca);
	fclose(ptr);
	return;
}


int main()
{
	FILE *ptr;
	ptr = fopen("customers.txt", "r+");	/*nothing to explain in here, just normal menu layout.*/
	if(ptr == NULL)
		ptr = fopen("customers.txt", "w+");
	int control = 1;
	int b = 0;
	int enter = 0;
	int reportmenu = 0;
	int loanindex = 0;
	int customerindex = 0;
	do
	{
		printf("\n===========================================\nWelcome to the Bank Management System\n===========================================\n");
		printf("1. List All Customers\n2. Add New Customer\n3. New Loan Application\n4. Report Menu\n0. EXIT\nChoice: ");
		scanf("%d", &enter);
		switch(enter)
		{
			default: printf("\n\nInvalid entry.\n");
			case 1:
			listCustomers(ptr, customerindex, control);
			break;
			case 2:
			b = control;
			control += addCustomer(ptr, customerindex,&account[customerindex].Customer);
			if(control - b > 0)
			{
				customerindex++;
			}
			break;
			case 3:
			if(newLoan(ptr, loanindex) == 1)
				loanindex++;
			break;
			case 4:
			getReport();
			break;
			case 0: enter == 0;
		}

	}while(enter != 0);
	fclose(ptr);
	return 0;
}