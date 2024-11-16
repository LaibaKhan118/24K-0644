/*Define a Book structure with fields like title, author, publication_year, and price. Create
an array of books and write functions to:
1. Display all books in the library
2. Search for a book by title
3. List books by a specific author*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char title[50];
    char author[50];
    int p_yr;
    float price;
} Book;

void lower(char *str);
void displayBooks(Book arr[], int size);
void searchBook(Book arr[], char title[], int size);
void searchAuthor(Book arr[], char author[], int size);

int main()
{
    Book library[100];
    int n, c;
    char title[50], author[50];
    printf("How many book are there:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the title of book %d:\t", i + 1);
        scanf(" %s", library[i].title);
        printf("Enter the author of book %d:\t", i + 1);
        scanf(" %s", library[i].author);
        printf("Enter the publication year of book %d:\t", i + 1);
        scanf("%d", &library[i].p_yr);
        printf("Enter the price of book %d:\t", i + 1);
        scanf("%f", &library[i].price);
    }

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. View all books\n2. Search a book by title\n3. View books by an author.\n4. Exit\n");
        printf("Choose an option:\t");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            displayBooks(library, n);
            break;
        case 2:
            printf("Enter the title of the book:\t");
            scanf("%s", title);
            searchBook(library, title, n);
            break;
        case 3:
            printf("Enter the author of the book:\t");
            scanf("%s", author);
            searchAuthor(library, author, n);
            break;
        case 4:
            printf("Exiting...");
            return 0;
            break;
        default:
            printf("Invalid Option Number\n");
        }
    }
    return 0;
}

void displayBooks(Book arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", arr[i].title);
        printf("Author: %s\n", arr[i].author);
        printf("Publication Year: %d\n", arr[i].title);
        printf("price: %.2f\n", arr[i].price);
    }
}
void searchBook(Book arr[], char title[], int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        char str[50];
        strcpy(str, arr[i].title);
        if (strcmp(strlwr(str), strlwr(title)) == 0)
        {
            printf("\n%s\n%s\n%d\n%.2f\n", arr[i].title, arr[i].author, arr[i].p_yr, arr[i].price);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Not Available\n");
    }
}
void searchAuthor(Book arr[], char author[], int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        char str[50];
        strcpy(str, arr[i].author);
        if (strcmp(strlwr(str), strlwr(author)) == 0)
        {
            printf("\n%s\n%s\n%d\n%.2f\n", arr[i].title, arr[i].author, arr[i].p_yr, arr[i].price);
            flag = 1;
        }
    }
    if(flag == 0) {
        printf("Not Available\n");
    }
}
