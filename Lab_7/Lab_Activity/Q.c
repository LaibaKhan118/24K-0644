/*Array is immutable: a fixed data structure, it cannot be changed are declaration.
Since computers operate in binary, it's memory starts with 0. Thus, Array's index also starts with zero.

*/
#include<stdio.h>
int main()
{
 char str[100];

 // Scanset example: accepts only alphabetic characters (A-Z, a-z)
 printf("Enter a string: ");
 scanf("%[A-Za-z]", str);

 printf("You entered: %s\n", str);
 return 0;

}
