#include <stdio.h>
#include <stdlib.h>

int main() {
	int sum = 0;
	int N = 10000;
	// Create a 2D of size N
	int* ptr = malloc((N*N) * sizeof(int));
	for (int i = 0; i < N * N; i++) {
		ptr[i] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += ptr[i * N + j];
		}
	}
	return 0;
}
