#include <stdio.h>
#include <stdlib.h>

#define NUMOFITEMS 2
#define FILENAME "Lab11_data.bin"
int size = NUMOFITEMS - 1;

typedef struct
{
	int id;
	char name[20];
	int price;
}item_t;

typedef union
{
	int id;
	int phone;
	char mail[50];
}contactinfo_t;

typedef struct
{
	contactinfo_t contactinfo[3];
	item_t item;
}itemWithCont_t;

item_t *getItems(item_t *items, int size)
{
	printf("\nid => %d\nName => ", items[size - 1].id);	
	scanf("%s", items[size - 1].name);
	printf("\nPrice => ");
	scanf("%d", &items[size - 1].price);
}

void printItem(item_t item)
{
	printf("\n\nPrinting...\nID => %d\nName => %s\nPrice => %d", item.id, item.name, item.price);
}

int writeItems(char filename[], item_t *items, int size)
{
	FILE *ptr;
	ptr = fopen(FILENAME, "wb");
	fwrite(items, sizeof(item_t), size, ptr);
	printf("\nSuccesfully wrote data to file\n");
	fclose(ptr);
}

item_t readAnItem(FILE *file)
{
	item_t item;
	fread(&item, sizeof(item_t), 1, file);
	return item;
}

void contactInfoAdder(item_t *items, int size, itemWithCont_t contacts[])
{
	for(int i = 0; i < size; i++)
	{
		printf("\nPhone number for %s: ", items[i].name);
		scanf("%d", &contacts[i].contactinfo[0].phone);
		printf("\nMail for %s: ", items[i].name);
		scanf("%s", contacts[i].contactinfo[1].mail);
	}
}

void printItemWithContactInfo(itemWithCont_t contacts[])
{
	for(int i = 0; i < size; i++)
	{
		printf("\nId: %d\nName: %s\nPrice: %d\nPhone Number: %d\nMail: %s", contacts[i].item.id, contacts[i].item.name, contacts[i].item.price, contacts[i].contactinfo[0].phone, contacts[i].contactinfo[1].mail);
	}
}

void flushInputBuffer()
{
	char tmp;
	do
	{
		scanf("%c", &tmp);
	} while (tmp != '\n');
	
}

int main()
{
	item_t *item = NULL;
	contactinfo_t *contact = NULL;
	itemWithCont_t itemCont[50];

	item = (item_t *)malloc(sizeof(item_t) * 50);
	contact = (contactinfo_t *)malloc(sizeof(contactinfo_t) * 50);
	for(int i = 0; i < 50; i++)
	{
		item[i].id = i + 1;
		contact[i].id = i + 1;
		itemCont[i].item = item[i];
	}

	int menu = 0;
	
	getItems(item, size);
	size++;
	getItems(item, size);
	size++;
	printItem(item[0]);
	printItem(item[1]);
	writeItems(FILENAME, item, size) - 1;
	getItems(item, size);
	size++;
	getItems(item, size);
	size++;
	for(int i = 0; i < 5; i++)
		printItem(item[i]);
	contactInfoAdder(item, size, itemCont);
	printf("\n\nPrinting with contact info...\n\n");
	printItemWithContactInfo(itemCont);

	// while(1)
	// {
	// 	printf("\nGet Item\n");
	// 	scanf("%d", &menu);
	// 	switch(menu)
	// 	{
	// 		default: return 0;
	// 		case 1:
	// 		getItems(item, size);
	// 		size++;
	// 		break;
	// 		case 2:

	// 		break;
	// 		case 3:
	// 		break;
	// 		case 4:
	// 		break;
	// 		case 5:
	// 		break;
	// 	}
	// }
	return 0;
}