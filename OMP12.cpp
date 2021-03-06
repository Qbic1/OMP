// OMP12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "omp.h"
#include "time.h"
#include "iostream"


#define COUNT 300
#define LIMIT 1000
#define NUM 7

int main() {

	srand(time(0));

	int a[COUNT];

	int base_max = -1;
	for (int i = 0; i < COUNT; i++) {
		a[i] = rand() % LIMIT;
		if (a[i] % NUM == 0 && base_max < a[i]) {
			base_max = a[i];
		}
	}

	int max = -1;
#pragma omp parallel for shared(max)
	for (int i = 0; i < COUNT; i++) {
		if (a[i] % NUM == 0 && max < a[i]) {
#pragma omp critical
			{
				max = a[i];
			}
		}
	}

	printf("%d\n", max);
	if (base_max == max) {
		printf("correct\n");
	}
}

