#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <math.h>

int isdigitMy(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}
int toupperMy(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'п')
		new_c = 'А' + (c - 'а');
	if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}
int strlenMy(char c[]) {
	int t = 0;
	for (int i = 0; c[i]; i++) t++;
	return t - 1;
}
int strcmpMy(char c1[], char c2[]) {
	for (int i = 0; i < min(strlen(c1), strlen(c2)); i++) {
		if (c1[i] < c2[i]) return -1;
		else if (c1[i] > c2[i]) return 1;
	}
	return 0;
}
void strcpyMy(char* c1, char* c2) {
	while (*c1++ = *c2++);
}
void strcatMy(char* c1, char* c2) {
	while (*c1) c1++;
	while (*c1++ = *c2++);
}
void var3_replace(char* str) {
	while (*str) {
		if ((int)*str >= 65 && (int)*str <= 90) *str = '$';
		str++;
	}
}
void task1() {
	char name[12];
	printf("Введите ваше имя: ");
	fgets(name, 11, stdin);
	printf("Приветствую тебя, %s\n", name);
	
}
void task2() {
	printf("Введите символ: ");
	int ch = getchar();

	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}
void task3() {
	printf("Введите символ: ");
	int ch = getchar();

	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}
void task4() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') cnt++;
	}
	printf("\nВ ней %d пробелов\n", cnt);

}
void task5() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') s[i] = '#';
	}
	printf("\nИтоговая строка: %s\n", s);

}
void task6_1() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i])) s[i] = '$';
	}
	printf("\nИтоговая строка: %s\n", s);

}
void task6_2() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (isdigitMy(s[i])) s[i] = '$';
	}
	printf("\nИтоговая строка: %s\n", s);

}
void task7_1() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupper(s[i]);
	printf("\nИтоговая строка: %s\n", s);
}
void task7_2() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupperMy(s[i]);
	printf("\nИтоговая строка: %s\n", s);
}
void task8() {
	printf("Смотреть Лабораторную работу №21\n");
}
void task9() {
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку: %s", s);

	printf("\nДлина строки: %d", strlenMy(s));
}
void task10() {
	char s1[80];
	char s2[80];
	printf("Введите строку: ");
	fgets(s1, 79, stdin);
	printf("\nВы ввели строку: %s", s1);
	printf("\nВведите строку: ");
	fgets(s2, 79, stdin);
	printf("\nВы ввели строку: %s", s2);

	if (strcmpMy(s1, s2) < 0) printf("s1 < s2");
	else if (strcmpMy(s1, s2) == 0) printf("s1 = s2");
	else printf("s1 > s2");
}
void task11() {
	char s1[80];
	char s2[80];
	printf("Введите строку: ");
	fgets(s1, 79, stdin);
	printf("\nВы ввели строку: %s", s1);
	printf("\nВведите строку: ");
	fgets(s2, 79, stdin);
	printf("\nВы ввели строку: %s", s2);
	strcpyMy(s1, s2);
	printf("\ns1 = %s", s1);

}
void task12() {
	char src[] = "World!";
	char dest[80] = "Hello ";
	printf("src = %s, dest = %s\n", src, dest);

	strcatMy(dest, src);
	printf("src = %s, dest = %s\n", src, dest);
}
void hw_var3() {
	char s1[80];
	printf("Все гласные большие латинские буквы заменить символом ‘$’.\n");
	printf("Введите строку: ");
	fgets(s1, 79, stdin);
	var3_replace(s1);
	printf("Итоговая строка:\n%s", s1);
}

void menu() {

	printf("\n");
	printf("=======================================\n");
	printf("Выберите нужную вам операцию:\n");
	printf("1: Hello по русски!\n");
	printf("2: Вывести на экран 30 символов с кодами от CH до CH+19\n");
	printf("3: Вывести на экран 30 символов с кодами от CH до CH-29\n");
	printf("4: Ввести строку s. Подсчитать, сколько в ней пробелов\n");
	printf("5: Ввести строку s. Все пробелы в ней заменить символом ‘#’\n");
	printf("6: Ввести строку s. Все цифры в ней заменить символом ‘$‘ (isdigit())\n");
	printf("7: Ввести строку s. Все цифры в ней заменить символом ‘$‘ (isdigitMy())\n");
	printf("8: Ввести строку s (без русских символов). Все маленькие латинские буквы превратить в большие (toupper())\n");
	printf("9: Ввести строку s с русскими и латинскими символами. Все маленькие буквы превратить в большие (toupperMy())\n");
	printf("10: В игру, реализованную в лабораторной работе №21, добавить вывод строки состояния игры\n");
	printf("11: Реализовать собственную версию функции int strlen(char *)\n");
	printf("12: Реализовать собственную версию функции int strcmp (char *, char *)\n");
	printf("13: Реализовать собственную версию функции void strcpy (char *, char *)\n");
	printf("14: Реализовать собственную версию функции void strcat (char *, char *)\n");
	printf("15: Все гласные большие латинские буквы заменить символом  ‘$’\n");
	printf("\n");
	printf("-1: выйти из программы\n");
	printf("Выбранная операция >>>>>> ");

	int task;
	scanf_s("%d", &task);
		switch (task) {
		case -1:
			break;
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
		case 5:
			task5();
			break;
		case 6:
			task6_1();
			break;
		case 7:
			task6_2();
			break;
		case 8:
			task7_1();
			break;
		case 9:
			task7_2();
			break;
		case 10:
			task8();
			break;
		case 11:
			task9();
			break;
		case 12:
			task10();
			break;
		case 13:
			task11();
			break;
		case 14:
			task12();
			break;
		case 15:
			hw_var3();
			break;
		}
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	menu();
	//task1();
	//task2();
	//task3();
	//task4();
	//task5();
	//task6_1();
	//task6_2();
	//task7_1();
	//task7_2();
	//task8();
	//task9();
	//task10();
	//task11();
	//task12();
	//hw_var3();
}