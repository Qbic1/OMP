	// OMP5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

#define LIMIT 30

int main()
{
	int d[6][8];
	srand(time(0));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			d[i][j] = rand() % LIMIT;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");

#pragma omp parallel sections
	{
#pragma omp section
		{
			int count = 0;
			int sum = 0;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					sum += d[i][j];
					count++;
				}
			}
			printf("average value of array d[6][8] elements is %.2f. thread is %d\n", sum * 1.0 / count, omp_get_thread_num());
		}

#pragma omp section
		{
			int min = LIMIT + 1;
			int max = -1;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					if (min > d[i][j]) {
						min = d[i][j];
					}
					if (max < d[i][j]) {
						max = d[i][j];
					}
				}
			}
			printf("min is %d and max is %d of array d[6][8] elements. thread is %d\n", min, max, omp_get_thread_num());
		}

#pragma omp section
		{
			int count = 0;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					if (d[i][j] != 0 && d[i][j] % 3 == 0) {
						count ++;
					}
				}
			}
			printf("count of array d[6][8] devided by 3 elements is %d. thread is %d\n", count, omp_get_thread_num());
		}
	}
}

