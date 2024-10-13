#include<stdio.h>
#include<string.h>
int main()
{
    char arr[30];
    int a=0,e=0,i=0,o=0,u=0;
    printf("Enter a string:\t");
    scanf("%[^\n]s", arr);
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int j = 0; j < size; j++) {
    	char c = arr[j];
    	switch(c) {
    		case 'a':
    		case 'A':
    			a++;
    			break;
    		case 'e':
    		case 'E':
    			e++;
    			break;
			case 'i':
    		case 'I':
    			i++;
    			break;
			case 'o':
    		case 'O':
    			o++;
    			break;
			case 'u':
    		case 'U':
    			u++;
    			break;		
    }
    }
    printf("Number of a: %d\nNumber of e: %d\nNumber of i: %d\nNumber of o: %d\nNumber of u: %d\n", a,e,i,o,u);
}
