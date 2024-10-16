// 2024 mid A - section b, Q 2
//  Create a C program for library managment. This library has only five books available for checkout. Each book can either he borrowed by a reader or returned to its spot on the shelf. But watch out-once a book is checked out, it goes missing until someone brings it back! 

#include <stdio.h>

int main() {
    int books[5] = {1,1,1,1,1}; // 1 for avaible and 0 for not available
    int index, option;
    
    while(1) {
        printf("\n\t\tLibrary Management System\n");
        printf("\t\t_________________________\n");
        printf("Menu:\n");
        printf("1. Check out a book\n2. Return a book\n3. Exit\n");
        printf("\nChoose a menu option:\t");
        scanf("%d", &option);
    
        switch(option) {
            case 1:
                printf("\nAvailable Books:\n");
                for (int i = 1; i <= 5; i++)
                    printf("%d. Book %d\n", i, i);
                
                printf("Enter the number of the book that you want to check out: \t");
                scanf("%d", &index);
                if (index < 1 || index > 5) {
                    printf("Wrong Book Number.\n");
                    break;
                } 
                else if(books[index-1] == 0) {
                   printf("Book is already checked out.\n");
                } 
                else {
                    books[index-1] = 0;
                    printf("You Successfully Checked out Book %d\n", index);
                }
                break;
            case 2:
                printf("Enter the number of the book that you want to return: \t");
                scanf("%d", &index);
                if (index < 1 || index > 5) {
                    printf("Wrong Book Number.\n");
                    break;
                }
                else if (books[index-1] != 0) {
                    printf("Book Already on the Shelf\n");
                }
                else {
                    books[index-1] = 1;
                    printf("You Have Successfully Returned the Book %d\n", index);
                }
                break;
            case 3:
               printf("Exiting the program...\n");
               return 0;
             break;
            default:
                printf("Invalid menu option.\n");
        }
    }
    return 0;
}
