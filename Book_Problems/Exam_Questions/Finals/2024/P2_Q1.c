/*Resursive function to concatenate two strings*/

#include <stdio.h>

// Recursive function to concatenate strings
char* recursiveConcat(char* dest, const char* src) {
    // Base case: If the source string is empty, return the destination
    if (*src == '\0') {
        return dest;
    }

    // Move to the end of the destination string
    if (*dest != '\0') {
        recursiveConcat(dest + 1, src);  // Move to the next character in 'dest'
    } else {
        // Append the current character from 'src' to 'dest'
        *dest = *src;
        *(dest + 1) = '\0'; // Null-terminate the string
        recursiveConcat(dest + 1, src + 1); // Move to the next character in 'src'
    }

    return dest;
}

int main() {
    char dest[100] = "Hello, "; // Ensure 'dest' has enough space for concatenation
    const char src[] = "World!";

    printf("Before Concatenation:\n");
    printf("dest: %s\n", dest);
    printf("src: %s\n\n", src);

    // Call the recursive function
    recursiveConcat(dest, src);

    printf("After Concatenation:\n");
    printf("dest: %s\n", dest);

    return 0;
}
