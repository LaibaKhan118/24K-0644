/*Q: Write a program to read 10 integers into an array. Then, use loops to find the
frequency of each element in the array (how many times each number occurs).*/

#include <stdio.h>
int main() {
    int arr[10];
    for(int i = 0; i < 10; i++) {
        printf("Enter %d number:\t", i+1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 10; i++){
        int count = 0;
        for(int j = 0; j < 10; j++){
            if(arr[i] == arr[j]) {
                count++;
            }   
        }
        printf("%d is %d time\n", arr[i], count);
    }
    return 0;
}
