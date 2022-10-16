#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    int id;
    char title[10];
    char author[10];
    char subject[20];
    int year;
};

typedef struct Book Book;

int main()
{
    int menu, submenu;
    int id = 0;
    int index = 0;
    int a, b;
    int arrlen = 0;
    char *string;
    Book *books;
    Book *temp;
    Book tempp;
    string = (char *)calloc(20, sizeof(char));
    books = (Book *)calloc(arrlen,sizeof(Book));
    do
    {
        printf("\n*************************************\nMenu\n\t1. Add New Book\n\t2. List Books\n\t3. EXIT\n\n\nChoose = ");
        scanf("%d", &menu);
        if(menu == 3)
            break;
        if(menu > 3 || menu < 1)
            {
                printf("\n TRY AGAIN");
                continue;
            }
        if(menu == 1)
        {
            if(id == arrlen)
            {
                arrlen += 2;
                temp = (Book *)calloc(arrlen,sizeof(Book));
                for(int i = 0; i < id; i++)
                    temp[i] = books[i];
                free(books);
                books = (Book *)calloc(arrlen,sizeof(Book));
                for(int i = 0; i < id; i++)
                    books[i] = temp[i];
                free(temp);
                // printf("\n\naaaaa\n\n");
            }
                printf("\nTitle: ");
                fflush(stdin);
                scanf(" %[^\n]%*c", books[id].title);
                printf("\nAuthor: ");
                fflush(stdin);
                scanf(" %[^\n]%*c", books[id].author);
                printf("\nSubject: ");
                fflush(stdin);
                scanf(" %[^\n]%*c", books[id].subject);
                printf("\nYear: ");
                fflush(stdin);
                scanf(" %d", &books[id].year);
                id++;
        }
        if(menu == 2)
            do{
                index = 0;
                printf("\nSUBMENU\n\n\t1. Get By Title\n\t2. Author\n\t3. Subject\n\t4. Sorted List By year (desc)\n\t5. List All books\n\t6. EXIT SUBMENU\n\n Choose : ");
                scanf("%d", &submenu);
                if(submenu == 6)
                    break;
                if(submenu > 6 || submenu < 1)
                    {
                        printf("\n********************\nTRY AGAIN\n***********************\n");
                        continue;
                    }
                switch(submenu)
                {
                    case 1:
                        printf("\n\n\tEnter a book title: ");
                        fflush(stdin);
                        scanf(" %[^\n]%*c", string);
                        for(a = 0; a < id; a++)
                        {
                            if(strcmp(books[a].title, string) == 0)
                            {
                                printf("\n****************************\n\n Book found\nTitle: %s\nAuthor: %s\nSubject: %s\nYear: %d\n******************************\n", books[a].title, books[a].author, books[a].subject, books[a].year);
                                break;
                            }
                        }
                        if(a == id)
                            printf("There is no such book for search '%s'.", string);
                        break;
                    case 2:
                        printf("\n\n\tEnter a book author: ");
                        fflush(stdin);
                        scanf(" %[^\n]%*c", string);
                        for(a = 0; a < id; a++)
                        {
                            if(strcmp(books[a].author, string) == 0)
                            {
                                printf("\n****************************\n\n Book found\nTitle: %s\nAuthor: %s\nSubject: %s\nYear: %d\n******************************\n", books[a].title, books[a].author, books[a].subject, books[a].year);
                                break;
                            }
                            if(a == id)
                            printf("There is no such book for search '%s'.", string);
                        }
                        break;
                    case 3:
                        printf("\n\n\tEnter a book subject: ");
                        fflush(stdin);
                        scanf(" %[^\n]%*c", string);
                        for(a = 0; a < id; a++)
                        {
                            if(strcmp(books[a].subject, string) == 0)
                            {
                                printf("\n****************************\n\n Book found\nTitle: %s\nAuthor: %s\nSubject: %s\nYear: %d\n******************************\n", books[a].title, books[a].author, books[a].subject, books[a].year);
                                break;
                            }
                            if(a == id)
                            printf("There is no such book for search '%s'.", string);
                        }
                        break;
                    case 4:
                        for(a = 0; a < id - 1; a++)
                        {
                            for(b = a + 1; b < id; b++)
                            {
                                if(books[b].year < books[a].year)
                                {
                                    tempp = books[a];
                                    books[a] = books[b];
                                    books[b] = tempp;
                                }
                            }
                        }
                        for(a = 0; a < id; a++)
                                printf("\n****************************\n\n%d. Book;\nTitle: %s\nAuthor: %s\nSubject: %s\nYear: %d\n******************************\n", a + 1, books[a].title, books[a].author, books[a].subject, books[a].year);
                        break;
                    case 5:
                        for(a = 0; a < id - 1; a++)
                        {
                            for(b = a + 1; b < id; b++)
                            {
                                if(books[b].id > books[a].id)
                                {
                                    tempp = books[a];
                                    books[a] = books[b];
                                    books[b] = tempp;
                                }
                            }
                        }
                        for(a = 0; a < id; a++)
                                printf("\n****************************\n\n%d. Book;\nTitle: %s\nAuthor: %s\nSubject: %s\nYear: %d\n******************************\n", a + 1, books[a].title, books[a].author, books[a].subject, books[a].year);
                        break;
                    case 6:
                        break;
                }
            }while(submenu != 6);
        }while(menu != 3);
    free(books);
    free(string);
    return 0;
}