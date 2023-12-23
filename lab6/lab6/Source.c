#include <stdio.h>

void main() {
	// ex1
	/*
	int n, i = 1;

	printf("n = ");
	scanf_s("%d", &n);
	do {
		printf("%d ", i);
		i++;
	} while (i<=n);
	*/
	//ex2
	/*
	int n = 1, i = 0;
	do {
		printf("n^%d = %d\n", i, n);
		n = n * 2;
		i++;
	} while (i<=5);
	*/
	// ex3*
	/*
	float R, n, r, i = 1;
	printf("n = ");
	scanf_s("%f", &n);
	printf("r = ");
	scanf_s("%f", &r);
	R = (100 + r) / 100;
	do {
		n = n * R;
		printf("%f\n", n);
		i++;
	} while (i <= 10);
	*/
	// ex4
	/*
	int n, j = 1, i = 0;
	printf("n = ");
	scanf_s("%d", &n);
	do {
		printf("%d\n", i);
		i += 2;
		j++;
	} while (j <= n);
	*/
	// ex5
	/*
	int n, a, i = 1;
	printf("n = ");
	scanf_s("%d", &n);
	printf("a = ");
	scanf_s("%d", &a);
	do {
		printf("%d\n", a*i);
		i++;
	} while (i<=n);
	*/
	// ex6 Вывести n нечетных чисел
	/*
	int n, j = 1, i = 1;
	printf("n = ");
	scanf_s("%d", &n);
	do {
		printf("%d\n", i);
		i += 2;
		j++;
	} while (j <= n);
	*/
	// ex7
	// Никита откладывает каждую неделю по 500 рублей,
	// выведите его накоплния за первые 12 недель.
	/*
	int i = 1, n = 500;
	do {
		printf("%d\n", n * i);
		i++;
	} while (i <= 12);
	*/
}