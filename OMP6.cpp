// OMP6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "time.h"
#include <iostream>

#define LIMIT 100;

int main() {
	srand(time(0));
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = rand() % LIMIT;
	}

	int sum_a = 0;
#pragma omp parallel for
	for (int i = 0; i < 100; i++) {
		sum_a += a[i];
	}

	printf("%d without reduction\n", sum_a);
	
	int sum_a_red = 0;
#pragma omp parallel for reduction(+: sum_a_red)
	for (int i = 0; i < 100; i++) {
		sum_a_red += a[i];
	}

	printf("%d with reduction\n", sum_a_red);

	printf(sum_a == sum_a_red ? "Values equal\n" : "Values not equal\n");

}

