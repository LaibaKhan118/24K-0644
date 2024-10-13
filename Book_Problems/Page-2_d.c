// convert string to integer. string: "124" to integer: 124
#include <stdio.h>
int main()
{
    char str[1000000];
    printf("Enter a number as string:\t");
    scanf("%s", str);
    int num = 0, place = 1;
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    for(int i = size-1; i >= 0; i--){
        switch(str[i]) {
            case '0':
                num += (0*place);
                break;
            case '1':
                num += (1*place);
                break;
            case '2':
                num += (2*place);
                break;
            case '3':
                num += (3*place);
                break;
            case '4':
                num += (4*place);
                break;
            case '5':
                num += (5*place);
                break;
            case '6':
                num += (6*place);
                break;
            case '7':
                num += (7*place);
                break;
            case '8':
                num += (8*place);
                break;
            case '9':
                num += (9*place);
                break;
            default:
                printf("Invalid Input\n");
                return 0;
        }
        place *= 10;
    }
    printf("Integer: %d", num);
}
