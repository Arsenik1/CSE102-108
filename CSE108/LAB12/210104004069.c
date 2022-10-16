#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *array;
	int currentsize;
}dynamic_array;

int *resize_array(int *array, int currentsize)		/*creates a temporary array and assigns current array's currentsize + 1 to it and then*/
{													/*opens our original array as currentsize + 1 then assigns the temp back to it.*/
	int *temp;
	temp = (int *)calloc(currentsize + 1, sizeof(int));
	for(int i = 0; i < currentsize; i++)
		temp[i] = array[i];
	array = (int *)calloc(currentsize + 1, sizeof(int)), sizeof(int);
	for(int i = 0; i < currentsize; i++)
		array[i] = temp[i];
	free(temp);
	currentsize++;
	return array;
}

dynamic_array read_from_file(char *filename, dynamic_array arr)
{
	int i = 0;
	int arrIndex = 0;
	FILE *ptr;
	ptr = fopen(filename, "r+");
	if(ptr == NULL)		/*if file couldn't be opened.*/
		{
			printf("\nERROR\n");
			return arr;
		}
	arr.currentsize = 0;		/*initializing the array length*/
	arr.array = (int *)calloc(arr.currentsize, sizeof(int)); /*initializing the array, this can also be used to reset the data read from the file.*/
	while(!feof(ptr))
	{
		arr.array = resize_array(arr.array, arr.currentsize);	/*increases capacity by one and assigns the array one line by line from the file.*/
		arr.currentsize++;
		fscanf(ptr ," %d", &arr.array[arrIndex]);
		arrIndex++;
	}
	fclose(ptr);
	return arr;
}
dynamic_array removeData(dynamic_array arr, int number)
{
	int i = 0;
	int arrIndex = 0;
	for(i = 0; i < arr.currentsize; i++)	/*looks for the value*/
	{
		if(arr.array[i] == number)
			break;
	}
	if(i == arr.currentsize)		/*if the value couldn't been found, array has been returned with no operations made.*/
		{
			printf("\nThe value couldn't been found.");
			return arr;
		}
	for(;i < arr.currentsize - 1; i++)		/*drags the array's remaining parts*/
		{
			arr.array[i] = arr.array[i + 1];
		}
	int *temp;
	temp = (int *)calloc(arr.currentsize - 1, sizeof(int));		/*does the same thing as in the resize_array() but instead of increasing the size,*/
	for(i = 0; i < arr.currentsize - 1; i++)					/*this place decreases it.*/
		temp[i] = arr.array[i];
	free(arr.array);
	arr.array = (int *)calloc(arr.currentsize - 1, sizeof(int));
	for(i = 0; i < arr.currentsize - 1; i++)
		arr.array[i] = temp[i];
	free(temp);
	arr.currentsize--;
	return arr;
}

int main()
{
	int input, delete;
	dynamic_array data;
	char *filename = "data.txt";
	do
	{
		printf("\n\nMENU\n1- Read data from source file\n2- Configure read data\n0- EXIT\n:");		/*convential menu screen,*/
		scanf("%d", &input);																		/*nothing to explain in here.*/
		if(input == 1)
		{
			printf("\n\nData in source file\n***************************");
			data = read_from_file(filename, data);
			for(int i = 0; i < data.currentsize; i++)
				printf("\n%d", data.array[i]);
		}
		else if(input == 2)
		{
			printf("\n\nEnter the number you want to be deleted: \n");
			scanf("%d", &delete);
			data = removeData(data, delete);
			printf("\nArray after deletion\n***************************");
			for(int i = 0; i < data.currentsize; i++)
				printf("\n%d", data.array[i]);
		}
	}while(input == 1 || input == 2);

	return 0;
}