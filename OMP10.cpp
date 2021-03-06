// OMP10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "time.h"
#include "omp.h"

#define WIDTH 6
#define HEIGHT 8
#define LIMIT 30

int main() {
	int d[WIDTH][HEIGHT];
	srand(time(0));

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			d[i][j] = rand() % LIMIT;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

	int max = -1;
	int min = LIMIT + 1;

	int counter = 0;
#pragma omp parallel num_threads(8) reduction(+: counter)
#pragma omp for
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			counter++;
			if (min > d[i][j]) {
#pragma omp critical
				min = d[i][j];
			}
			if (max < d[i][j]) {
#pragma omp critical
				max = d[i][j];
			}
		}
	}
	printf("counter is %d\n", counter);
	printf("min is %d, max is %d\n", min, max);

}

