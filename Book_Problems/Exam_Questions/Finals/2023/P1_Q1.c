#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addCategory();
void addProduct();
void final();
void menu();

int main()
{
    while (1)
    {
        int op;
        menu();
        printf("Select an option: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 0:
            printf("Exiting...\n");
            return 0;
            break;
        case 1:
            addCategory();
            break;
        case 2:
            addProduct();
            break;
        case 3:
            final();
            break;
        default:
            printf("Wrong option.\n");
        }
    }
    return 0;
}

void menu()
{
    printf("\n==== Menu ====\n");
    printf("1. Add Category\n");
    printf("2. Add Product\n");
    printf("3. Generate a final report\n");
    printf("0. Exit\n");
}

void addCategory()
{
    FILE *ptr = fopen("categories.txt", "a+");
    if (ptr == NULL)
    {
        printf("Cannot open file\n");
        return;
    }
    char existing_name[50];
    int existing_id;
    char name[50];
    int id, dup = 0;
    printf("Enter the name of the category: ");
    scanf("%[^\n]s", name);
    printf("Enter the id of the category: ");
    scanf("%d", &id);
    getchar();
    while (fscanf(ptr, "%s %d", existing_name, &existing_id) == 2)
    {
        if (id == existing_id)
        {
            dup = 1;
            break;
        }
    }
    if (dup == 1)
    {
        printf("ID already exists. Please enter a different ID.\n");
    }
    else
    {
        fprintf(ptr, "%s %d\n", name, id);
        printf("Category Added successfully.\n");
    }
    fclose(ptr);
}
void addProduct()
{
    FILE *ptr = fopen("products.txt", "a");
    if (ptr == NULL)
    {
        printf("Cannot open file\n");
        return;
    }
    char name[50];
    float price;
    int category_id;
    printf("Enter the name of the product: ");
    scanf("%[^\n]s", name);
    printf("Enter the price of the product: ");
    scanf("%f", &price);
    printf("Enter the id of the category it belongs to: ");
    scanf("%d", &category_id);
    getchar();
    fprintf(ptr, "%s %.2f %d\n", name, price, category_id);
    fclose(ptr);
    printf("Product Added successfully.\n");
}

void final()
{
    FILE *cptr = fopen("categories.txt", "r");
    FILE *pptr = fopen("products.txt", "r");
    FILE *ptr = fopen("final.txt", "w");
    if (cptr == NULL || pptr == NULL || ptr == NULL)
    {
        printf("Cannot open one or more files\n");
        if (cptr != NULL)
        {
            fclose(cptr);
        }
        if (pptr != NULL)
        {
            fclose(pptr);
        }
        if (ptr != NULL)
        {
            fclose(ptr);
        }
        return;
    }

    char category_name[100][50];
    int cat_id[100];
    int cCount = 0;

    while (fscanf(cptr, "%s %d", category_name[cCount], &cat_id[cCount]) == 2)
    {
        cCount++;
    }

    char product_name[50];
    int pro_id;
    float price;

    while (fscanf(pptr, "%s %f %d", product_name, &price, &pro_id) == 3)
    {
        for (int i = 0; i < cCount; i++)
        {
            if (cat_id[i] == pro_id)
            {
                fprintf(ptr, "%s %s %.2f\n", category_name[i], product_name, price);
                break;
            }
        }
    }

    fclose(cptr);
    fclose(pptr);
    fclose(ptr);
    printf("\nGenerated final file successfully.\n");
}
