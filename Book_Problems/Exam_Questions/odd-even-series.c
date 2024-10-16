// 2024 mid B - section c, Q 3
// The program should prompt the user to enter the starting and ending numbers for the range, then generate the required sequence, and finally display the numbers stored in the array.
// 1 3 5 7 9 10 11 13 15 17 18 19
#include <stdio.h>

int main() {
    
    int start, end, count = 0, index = 0;
    printf("Enter the starting number of the range:\t");
    scanf("%d", &start);
    printf("Enter the ending number of the range:\t");
    scanf("%d", &end);
    
    int arr[500] = {0};
    
    for(int i = start; i <= end; i++) {
        if (i % 2 != 0) {
            arr[index] = i;
            index++;
            count++;
            if(count == 5) {
                arr[index] = i + 1;
                index++;
                count = 0;
            }
        }
    }
    
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
