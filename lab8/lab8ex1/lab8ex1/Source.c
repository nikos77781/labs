#include <stdio.h>
#include <Windows.h>

void aboutMe() {
	printf("�������: ������\n");
	printf("���: ������\n");
	printf("��������: ������������\n");
	printf("\n");
	printf("������: ����-13\n");
	printf("����: 05.09.2023\n");
	printf("�������: ������ �������������� � ����������������\n");
	printf("������������ ������ �1\n");
	printf("\n");
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();

}