#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "SortString.h"
#include <Windows.h>

char filename[] = "C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab28\\dict4b.txt";
void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// t0 - сколько прошло времени от старта программы до момента входа в функцию main()
	long t0 = clock();
	printf("t0 = %.15f sec \n", t0 / (float)CLOCKS_PER_SEC);

	LoadWords(filename);
	// сообщаем какие данные обрабатываются
	printf("Experiment with array lenth = %d, file = %s\n", n, filename);

	// t1 - сколько прошло времени от старта программы до окончания загрузки 	массива
	int t1 = clock();
	printf("t1 = %.15f sec \n", t1 / (float)CLOCKS_PER_SEC);
	for (int i = 0; i < 1; i++) {
		fillArrayStrings();

		//SelectionSortStrings();
		//BubbleSortStrings();
		QuickSortStrings();

		if (!isSortedStrings()) {
			printf("Array is not sorted!!!\n");
		}
	}

	// t2 - сколько прошло времени от старта программы до окончания сортировки
	long t2 = clock();
	printf("t2 = %.10f sec \n", t2 / (float)CLOCKS_PER_SEC);

	printf("t1 - t0 = %.10f sec (Run time of array loading)\n",
		(t1 - t0) / (float)CLOCKS_PER_SEC);
	printf("t2 - t1 = %.10f sec (Run time of sorting)\n",
		(t2 - t1) / (float)CLOCKS_PER_SEC);
}
