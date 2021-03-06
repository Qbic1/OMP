// OMP8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <omp.h>
#include <time.h>

#define COUNT 16000

void printArray(double a[], int lenght) {
	for (int i = 0; i < lenght; i++) {
		printf("%.1f ", a[i]);
	}
	printf("\n");
}

void printArray(int a[], int lenght) {
	for (int i = 0; i < lenght; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[COUNT];
	double b[COUNT];

	for (int i = 0; i < COUNT; i++) {
		a[i] = i;
	}

	printArray(a, COUNT);

#pragma omp parallel for schedule(static) num_threads(8) shared(b)
	for (int i = 1; i < COUNT - 1; i++) {
		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
		printf("%.0f:%d ", b[i], omp_get_thread_num());
		if (i == COUNT - 2) printf("\n");
	}

#pragma omp parallel for schedule(dynamic) num_threads(8) shared(b)
	for (int i = 1; i < COUNT - 1; i++) {
		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
		printf("%.0f:%d ", b[i], omp_get_thread_num());
		if (i == COUNT - 2) printf("\n");
	}

#pragma omp parallel for schedule(guided) num_threads(8) shared(b)
	for (int i = 1; i < COUNT - 1; i++) {
		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
		printf("%.0f:%d ", b[i], omp_get_thread_num());
		if (i == COUNT - 2) printf("\n");
	}

#pragma omp parallel for schedule(runtime) num_threads(8) shared(b)
	for (int i = 1; i < COUNT - 1; i++) {
		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
		printf("%.0f:%d ", b[i], omp_get_thread_num());
		if (i == COUNT - 2) printf("\n");
	}

	printf("\nruntime = %d\n", clock());
}

