#include <stdio.h>
#include <math.h>
#include <Windows.h>

void main() {

	// lab2

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ex1
	/* 
	float g = 9.8; //ускорение свободного падения
	float height = 15; //высота в метрах

	float time = sqrt(2 * height / g); //время падения в секундах

	printf("Высота на момент начала падения: %f метров.\n", height);
	printf("Время падения: %f секунд.\n", time);
	*/
	// ex2
	/* 
	float g = 9.8; //ускорение свободного падения
	float height; //высота в метрах

	printf("Введите начальную высоту в метрах: ");
	scanf_s("%f", &height);

	float time = sqrt(2 * height / g); //время падения в секундах

	printf("Высота на момент начала падения: %f метров.\n", height);
	printf("Время падения: %f секунд.\n", time);
	*/
	// ex3
	/* 
	float price_m; //цена м^2
	float square; //площадь квартиры

	printf("Сколько стоит квадратный метр квартиры? \nВведите значение в RUB: ");
	scanf_s("%f", &price_m);
	printf("Какова площадь квартиры? \nВведите значение в m^2: ");
	scanf_s("%f", &square);

	printf("Стоимость квартиры площадью %f m^2 и ценой %f RUB за m^2 составляет %f RUB", square, price_m, price_m * square);
	*/
	// ex4
	/* 
	float price_m; // цена м^2
	float square; // площадь квартиры
	int salary; // зарплата
	float n; // сколько месяцев нужно откладывать
	float price; // стоимость квартиры

	printf("Сколько стоит квадратный метр квартиры? \nВведите значение в RUB: ");
	scanf_s("%f", &price_m);
	printf("Какова площадь квартиры? \nВведите значение в m^2: ");
	scanf_s("%f", &square);
	printf("Какова ваша зарплата?\nВведите значение в RUB: ");
	scanf_s("%d", &salary);

	price = square * price_m;
	n = price / (salary/2);

	if((int)n < n) n += 1;
	n = (int)n;

	printf("Стоимость квартиры площадью %f m^2 и ценой %f RUB за m^2 составляет %f RUB\n", square, price_m, price);
	printf("На желанную квартиру нужно откладывать %f месяцев\n", n);
	*/
	//ex5
	/* 
	float r; // Радиус шара
	float pi = 3.14; // Число Пи
	float vol; // Объём шара
	
	printf("Введите радиус шара: ");
	scanf_s("%f", &r);

	vol = 4 * pi * r * r * r / 3;

	printf("Объём шара: %f", vol);
	*/
	// ex6
	/* 
	float v; // объём тела
	float p; // плотность тела
	float m; // масса тела

	printf("Введите объём тела в м^3: ");
	scanf_s("%f", &v);
	printf("Введите плотность тела в кг/м^3: ");
	scanf_s("%f", &p);

	m = v * p;

	printf("Масса тела объёмом %f м^3 и плотностью %f кг/м^3 равна %f кг.", v, p, m);	
	*/
	// ex7
	/* 
	float numbers_of_episodes; // Количество серий
	float duration; // Средняя длительность серии в минутах
	int total_time; // Общее время сериала
	float n; // Количество прочтений Полного справочника по С
	
	printf("Введите количество серий выбранного сериала: ");
	scanf_s("%f", &numbers_of_episodes);
	printf("Введите среднюю продолжительность серии в минутах: ");
	scanf_s("%f", &duration);

	total_time = duration * numbers_of_episodes / 60;
	n = total_time / (400 / 200 / 60.* 800);


	printf("На просмотр выбранного сериала вы потратите %d часов. За это время вы могли прочитать Полный справочник по C %f раз.", total_time, n);
	*/

}