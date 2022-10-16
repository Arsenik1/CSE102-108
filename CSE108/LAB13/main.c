#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char bookname[30];
	char author[30];
	int year;
	struct Node *next;
};

typedef struct Node Node;


Node *read_file(Node *root, char arr[50][50])
{

	return root;
}

Node *insert_node(Node *root, char *bookname, char *author, int year)
{
	if(root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		strcpy(root->author,author);
		strcpy(root->bookname,bookname);
		root->year = year;
		return root;
	}
	else if(root->next == NULL)
	{
		Node *newnode = (Node *)malloc(sizeof(Node));
		if(root->year > year)
		{

		}
		else
		{
			newnode->year = year;
			strcpy(newnode->author,author);
			strcpy(newnode->bookname,bookname);
		}
		strcpy(root->author,author);
		strcpy(root->bookname,bookname);
		root->year = year;
		return root;
	}
	else
	{
	Node *newnode = (Node *)malloc(sizeof(Node));
	Node *temp;
	temp = root;
	Node *tempp;
	while(!(year > temp->year && year < temp->next->year))
		temp = temp->next;
	if(temp == root)
	{
		newnode->year = year;
		strcpy(newnode->author,author);
		strcpy(newnode->bookname,bookname);
		newnode->next = temp->next;	
		temp->next = newnode;
		root = temp;
	}
	else
	{
		newnode->year = year;
		strcpy(newnode->author,author);
		strcpy(newnode->bookname,bookname);
		newnode->next = temp->next;	
		temp->next = newnode;
	}
		return root;
	}
}

Node *delete_node(Node *root, char *bookname)
{

}

void print_nodes(Node *root)	/*printfs nodes'datas*/
{
	Node *temp;
	temp = root;
	while (temp != NULL)
	{
		printf("%s %s %d\n", temp->bookname, temp->author, temp->year);
		temp = temp->next;
	}
	printf("NULL");
}

int main()
{
	char arr[50][50] = {"test1 d1 123", "test2 d2 234", "test3 d3 123", "test4 d4 345", "test5 d5 456"};
	int i,j,k;
	Node *root = NULL;
	char temp1[50], temp2[50];
	for(i = 0; i < 5; i++)
		{
			sscanf(arr[i], "%s %s %d", temp1, temp2, &j);
			root = insert_node(root, temp1, temp2, j);
		}
	print_nodes(root);
	
	return 0;
}