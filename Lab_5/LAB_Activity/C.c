#include<stdio.h>
int main() {
	int k = 35;
	printf("\n%d %d %d %d", k==35, k=35, k>40, k=50);
	// Order of execution is not defined when performing multiple comparisons, thus compiler will show some ambiguous behavior
	// Order of execution is not guarenteed by the compiler
	// Compiler pehly dependent statements(assigning something to a variable) ko compile krta hai phir independent(just comparisons) pr ata hai
}