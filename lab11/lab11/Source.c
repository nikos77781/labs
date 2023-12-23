#include <stdio.h>
#include <Windows.h>

void task1() {
	int i = 1, j = 1, n, m;

	printf("введите количество строк: ");
	scanf_s("%d", &m);
	printf("введите количество столбцов: ");
	scanf_s("%d", &n);

	while (i <= m && j <= n) {
		printf("%d ", i * 10 + j);
		j++;
		if (n < j) {
			printf("\n");
			i++;
			j = 1;
		}
	}
}

void task2() {
	int x = 1, n = 1;
	while (x<=10) {
		do {
			if(n/10==0) printf(" %d ", n);
			else printf("%d ", n);
			n += x;
		} while (n <= x*10);
		printf("\n");
		x++;
		n = x;
	}
}
void task3() {
	int x = 5, i = 1;
	while (i<=5) {
		do {
			printf("%d ", x);
			x--;
		} while (x>=i);
		printf("\n");
		x = 5;
		i++;
	}
}

void task4() {

}

void main() {

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int n = -1;

		do {

			printf("¬ведите номер задани€(1-4): \n");

			scanf_s("%d", &n);

			switch (n) {
			case 1:
				task1();
				break;
			case 2:
				task2();
				break;
			case 3:
				task3();
				break;
			case 4:
				task4();
				break;
			}


		} while (!n);

}
