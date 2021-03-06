// OMP9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "omp.h"
#include "time.h"

#define SIZE 700

int main()
{
	int **arr = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
		arr[i] = new int[SIZE];
	int *vector = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = j+i;
		}
		vector[i] = i;
	}

	unsigned int time = clock();
	int res[SIZE];
	for (int j = 0; j < SIZE; j++)
	{
		res[j] = 0;
		for (int i = 0; i < SIZE; i++)
			res[j] += arr[j][i] * vector[i];
	}
	time = clock() - time;

	printf("time for non parallel algo %dms\n", time);

	time = clock();
#pragma omp parallel for shared(arr, vector, res)
	for (int j = 0; j < SIZE; j++)
	{
		res[j] = 0;
		for (int i = 0; i < SIZE; i++)
			res[j] += arr[j][i] * vector[i];
	}
	time = clock() - time;

	printf("time for parallel algo %dms\n", time);
}

