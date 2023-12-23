#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];

void task1() {
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab23\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout;
	fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t')
					s[i] = '%';
			}
			fprintf(fout, "%s", s);
			printf("%s\n", s);
		}
	}
	fclose(fin);
	fclose(fout);
}
void task2() {
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab23\\in2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout;
	fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab23\\out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if ((int)s[i] >= 97 && (int)s[i] <= 122)
					s[i] = (int)s[i] - 32;
			}
			fprintf(fout, "%s", s);
			printf("%s\n", s);
		}
	}
	fclose(fin);
	fclose(fout);
}
void task3() {
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab23\\in3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\Рабочий стол\\Учеба\\1 курс\\Основы программирования\\Лабы\\lab23\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	int flag = 0;
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; i < strlen(s); i++) {
				if (isalpha(s[i])) {
					flag = 1;
				}
				if (flag == 1 && i==strlen(s)-1) {
					s[strlen(s)-1] = '#'; 
					fprintf(fout, "<%s>\n", s);
					printf("<%s>\n", s);
					flag = 0;
					break;
				}
				else if(i == strlen(s) - 1) {
					s[strlen(s) - 1] = '>';
					fprintf(fout, "<%s\n", s);
					printf("<%s\n", s);
					break;
				}
			}
		}
	}
	
	fclose(fin);
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//task1();
	task2();
	//task3();
}