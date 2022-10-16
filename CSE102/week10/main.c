#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct table {
	char *name;
	char **field;
	char **type;
	int *isNull;
	int *isKey;
} table;

typedef struct tables tables;

struct tables {
	tables *next; 
	table * t;
};

typedef struct database {
	tables * tList; /* to be implemented as a 
	linked list */
	int n; /* num of entries */
	char * name; /* table name */
} database;

database *create_database(char *name);
int show_table(database *d);
int desc_table(database *d, char *name);
void insert_table(database *d, table *t);
void remove_table(database *d, char *name);
void insert_key(database *d, table *t, char *key_value);

int main()
{
	
	return 0;
}

database *create_database(char *name)
{
	FILE *ptr;
	ptr = fopen(name, "r");
	if(ptr == NULL)
	{
		ptr = fopen(name, "w+");
		printf("\nDatabase has successfully been created.\n");
		database *d = (database *)malloc(sizeof(database));
		return d;
	}
	else
	{
		printf("\nDatabase already exists.\n");
		return NULL;
	}
}

int show_table(database *d)
{
	if(d != NULL)
	{
		for(int i = 0; i < d->n; i++)
		{
			printf("%s. Table Name: ", d->tList[i].t->name);
		}
		return 1;
	}
	else
	{
		printf("\nDatabase does not exist.\n");
		return 0;
	}
}

int desc_table(database *d, char *name)	/*removed "table *t" parameter because the database already consists of the table, i changed the parameter to "char *name" since the user enters the table name*/
{
	while(d->tList->next != NULL && strcmp(d->tList->t->name, name));
	if(d->tList->next == NULL)
	{
		printf("\nNo table exists for this table name.\n");
		return 0;
	}
	else
	{
		int i = 0;
		tables *n;
		n = d->tList;
		printf("-----------------------------------------\n");
		printf("	Field		Type		Null		Key\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
	}
}
void insert_table(database *d, table *t);
void remove_table(database *d, char *name);
void insert_key(database *d, table *t, char *key_value);