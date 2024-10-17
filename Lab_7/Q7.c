// You are required to design a calculator utilizing an array. Take a string from the user i.e. 20+10-30 and store it in an array. 
// Traverse through the array, if there are values stored them in some variable and if an operation comes perform the necessary operation and if a null character comes display the result. 
// If the null character comes after the operator, the program should print an invalid expression. (Note: Only do this for + and - operator)

#include <stdio.h>

int main() {
    char str[100];
    int result = 0, num = 0;
    char operation = '+';
    printf("Enter an expression:\t");
    scanf("%s", str);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if((str[i] == '+' || str[i] == '-') && (str[i+1] == '\0')) {
            printf("Invalid expression.\n");
            return 0;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            num = (num * 10) + (str[i] - '0');
        }
        else if (str[i] == '+' || str[i] == '-') {
            if (operation == '+')
                result += num;
            else if (operation == '-')
                result -= num;
                
            operation = str[i];
            num = 0;
        }
        else {
            printf("Invalid expression.\n");
            return 0;
        }
    }
    
    if (operation == '+')
        result += num;
    else if (operation == '-')
        result -= num;
    printf("Answer: %d\n", result);
    return 0;
}
