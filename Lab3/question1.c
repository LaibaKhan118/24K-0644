/* 
ANSWER:
Because the given number was out of the range of the variable, we are getting a different value than the input value.
If we increase the size of the variable then we'll be able to save and print this huge number. 
*/

// Here is the correct code
#include <stdio.h>
int main() {
  long long int a = 3000000000;
  printf("%lld", a);
}
