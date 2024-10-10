#include<stdio.h>
int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int temp;
    
    for(int i = 0; i < 6; i++) {
    	temp = arr[i];
    	arr[i] = arr[6 - 1];
    	arr[6 - 1] = temp;
    
		printf("%d", arr[i]);
	}
}
