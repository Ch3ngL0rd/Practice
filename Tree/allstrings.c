#include <stdio.h>

int factorial(int n) {
	if (n == 1 || n == 0) return 1;
	return n * factorial(n-1);
}


char A[8];
void binary(int n) {
	if (n < 1) {
		printf("%s\n",A);
	} else {
		A[n-1] = '0';
		binary(n-1);
		A[n-1] = '1';
		binary(n-1);
	}
}

int main() {
	binary(8);
	return 0;
}
