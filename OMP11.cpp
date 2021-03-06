// OMP11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "omp.h"
#include "time.h"
#include "iostream"


#define COUNT 30
#define LIMIT 100
#define NUM 9

int main() {

	srand(time(0));

	int a[COUNT];

	int basic_counter = 0;
	for (int i = 0; i < COUNT; i++) {
		a[i] = rand() % LIMIT;
		if (a[i] % NUM == 0) {
			basic_counter++;
		}
	}

	int counter = 0;
#pragma omp parallel for shared(counter)
	for (int i = 0; i < COUNT; i++) {
		if (a[i] % NUM == 0) {
#pragma omp atomic
			counter++;
		}
	}

	printf("counter is %d\n", counter);
	if (basic_counter == counter) {
		printf("the answer is correct\n");
	}

}
