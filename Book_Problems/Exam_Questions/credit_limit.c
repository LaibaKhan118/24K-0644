//  Create a C program to check if the user has exceeded their credit limit. Input Account number, starting balance of the month, how many items did the user purchased and the cost of each of them (calulate the total), credits applied, and the credit limit. compute new balance = (starting balance+total charge) - total credits. check if the user exceeded limit. if yes, calculate how much it exceeded and display it.

#include <stdio.h>

int main() {
    int account_number, n_items;
    float s_balance, cost, sum = 0, t_credit, c_limit, new_balance, excess = 0.0;
    printf("Enter your Account Number: \t");
    scanf("%d", &account_number);
    printf("Enter your starting balance for the month: \t");
    scanf("%f", &s_balance);
    printf("Enter the number of items purchased this month:\t");
    scanf("%d", &n_items);
    for (int i = 1; i <= n_items; i++) {
        printf("Enter the cost of item %d:\t", i);
        scanf("%f", &cost);
        sum += cost;
    }
    printf("Enter the total credits applied to your account this month:\t");
    scanf("%f", &t_credit);
    printf("Enter your allowed credit limit:\t");
    scanf("%f", &c_limit);
    
    new_balance = (s_balance + sum) - t_credit;
    
    if (new_balance > c_limit) {
        excess = new_balance - c_limit;
    }
    
    printf("\n\nAccount Number: %d\nCredit Limit: %.2f\nNew Balance: %.2f\nCredit limit exceeded by %.2f\n", account_number, c_limit, new_balance, excess);
    return 0;
}
