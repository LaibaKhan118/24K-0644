// 2022 mid A, Q. 1
//  Assign a category number to a product by barcode

#include <stdio.h>

int main() {
    int code, d1, d2, d4, d5;
    
    printf("Enter the Barcode:\t");
    scanf("%d", &code);
    if (code > 99999 || code <= 9999) {
        printf("Bar code must b 5 digit long\n");
        return 0;
    }
    
    d1 = code / 10000;
    d2 = (code / 1000) % 10;
    d4 = (code / 10) % 10;
    d5 = code % 10;
    
    if (((d1 % 2 == 0) && (d2 % 2 == 0)) || ((d1 % 4 == 0) && (d2 % 4 == 0)))
        printf("Category 1");
    else if (d5 % 3 == 0 && d4 % 2 != 0)
        printf("Category 2");
    else 
        printf("Category 3");
    return 0;
}
