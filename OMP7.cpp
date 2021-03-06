// OMP7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <omp.h>

#define COUNT 12

int main() {

	int a[COUNT], b[COUNT], c[COUNT];
	omp_set_dynamic(0);

#pragma omp parallel num_threads(3)
	{
#pragma omp for schedule(static, 1)
		for (int i = 0; i < COUNT; i++) {
			a[i] = i * 2;
			b[i] = i * 3;
			printf("working %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		}
	}

	for (int i = 0; i < COUNT; i++) {
		printf("%d ", a[i]);
	} 
	printf("\n");

	for (int i = 0; i < COUNT; i++) {
		printf("%d ", b[i]);
	} 
	printf("\n");


#pragma omp parallel num_threads(4)
	{
#pragma omp for schedule(dynamic, 1)
		for (int i = 0; i < COUNT; i++) {
			c[i] = a[i] + b[i];
			printf("working %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		}
	}

	for (int i = 0; i < COUNT; i++) {
		printf("%d ", c[i]);
	} 
	printf("\n");



}
