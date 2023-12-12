#include <stdio.h>

int factorial(int n) {
	if (n == 1 || n == 0) return 1;
	return n * factorial(n-1);
}

int main() {
	int n = 5;
	printf("Factorial of %d is %d\n",5,factorial(5));
	return 0;
}
