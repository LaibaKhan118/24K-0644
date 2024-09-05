// Because the added number was out of the range of the variable, we are getting a different value.

// Here is the correct code
#include <stdio.h>
int main() {
  long long int a = 3000000000;
  printf("%lld", a);
}
