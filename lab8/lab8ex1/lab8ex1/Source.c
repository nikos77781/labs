#include <stdio.h>
#include <Windows.h>

void aboutMe() {
	printf("Фамилия: Клыков\n");
	printf("Имя: Никита\n");
	printf("Отчество: Вячеславович\n");
	printf("\n");
	printf("Группа: ПИбд-13\n");
	printf("Дата: 05.09.2023\n");
	printf("Предмет: Основы алгоритмизации и программирование\n");
	printf("Лабораторная работа №1\n");
	printf("\n");
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();

}