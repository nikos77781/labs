#include <stdio.h>
#include <Windows.h>

void main() {

	// lab3

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//ex1
	/* 
	int a, b;

	printf("Введите первое число: ");
	scanf_s("%d", &a);
	printf("Введите второе число: ");
	scanf_s("%d", &b);

	if (a > b) printf("Большее число = %d \nМеньшее число = %d", a, b);
	if (a < b) printf("Большее число = %d \nМеньшее число = %d", b, a);
	if (a == b) printf("Числа равны");
	*/
	//ex2
	/* 
	int a, b, c, d, e;
	int max_num;

	printf("Введите 5 чисел: ");
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);

	max_num = a;
	if (max_num < b) max_num = b;
	if (max_num < c) max_num = c;
	if (max_num < d) max_num = d;
	if (max_num < e) max_num = e;

	printf("%d", max_num);
	*/
	//ex3
	/* 
	float t;
	printf("Введите температуру: ");
	scanf_s("%f", &t);
	if (t < 18) printf("Холодно");
	if (t >= 18 && t<22) printf("Прохладно");
	if (t>=22 && t<26) printf("Тепло");
	if (t>=26) printf("Жарко");
	*/
	//ex4
	/* ex4
	float t; // Выбранная местность: Ульяновск; Сезон: ранняя осень
	printf("Введите температуру: ");
	scanf_s("%f", &t);
	if (t < 0) printf("Мороз");
	if (t >= 0 && t < 15) printf("Холодно");
	if (t >= 15 && t < 27) printf("Тепло");
	if (t >= 27) printf("Жарко");
	*/
	//ex5
	/* 
	float price; // Цены при выборе телефона
	printf("Введите цену в RUB: ");
	scanf_s("%f", &price);
	if (price < 10000) printf("Дешево");
	if (price >= 10000 && price < 30000) printf("Нормально");
	if (price >= 30000 && price < 45000) printf("Дорого");
	if (price >= 45000) printf("Ужас дорого");
	*/
	//ex6
	/*
	float speed; // Оценка скорости скачивания
	printf("Введите скорость скачивания в Мб/c: ");
	scanf_s("%f", &speed);
	if (speed < 1) printf("Очень медленно");
	if (speed >= 1 && speed < 5) printf("Медленно");
	if (speed >= 5 && speed < 10) printf("Нормально");
	if (speed >= 10 && speed <50) printf("Быстро");
	if (speed >= 50) printf("Очень быстро");
	*/

}