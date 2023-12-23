#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void task1() {
	printf("Задание №1");

	int arr[1000];
	int n;

	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &arr[i]);
	}

	fclose(fin);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	double sa = sum / n;
	int m = 0; //кол-во элементов < sa
	for (int i = 0; i < n; i++) {
		if (arr[i] > sa) m++;
	}
	
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Вsходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (arr[i] > sa) fprintf(fout, "%d ", arr[i]);
	}

	fclose(fout);
}
void task2() {
	printf("Задание №2");

	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	int* pa;
	int n;

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pa[i];
	}
	double sa = sum / n;
	int m = 0; //кол-во элементов < sa
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) m++;
	}
	
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) fprintf(fout, "%d ", pa[i]);
	}

	fclose(fout);
}
void task3() {
	printf("Задание №3");

	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	int* pa;
	int n;

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pa[i];
	}
	double sa = sum / n;
	int m = 0; //кол-во элементов < sa
	for (int i = 0; i < n; i++) {
		if (pa[i] < sa && pa[i] > 0) m++;
	}
	
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] < sa && pa[i] > 0) fprintf(fout, "%d ", pa[i]);
	}

	fclose(fout);
}
void task4() {
	printf("Задание №4");

	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	int* pa;
	int n;

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if(max<pa[i]) max = pa[i];
	}
	double sa = max*(2./3);
	int m = 0; //кол-во элементов < sa
	for (int i = 0; i < n; i++) {
		if (pa[i] >= sa) m++;
	}

	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab19\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] >= sa) fprintf(fout, "%d ", pa[i]);
	}

	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//task1();
	//task2();
	//task3();
	task4();

}