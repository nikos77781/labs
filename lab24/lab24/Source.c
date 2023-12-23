#include <stdio.h>
#include <Windows.h>

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}
void rec1(int n) {
	printf("%d ", n);
	if (n > 1) {
		 rec1(n - 2);
	}
}
void rec2(int n) {
	if (n > 1) {
		rec2(n - 2);
	}
	printf("%d ", n);
}
int rec3(int n) {
	printf("%d ", n);
	if (n > 1) {
		rec3(n - 2);
	}
	printf("%d ", n);
}
void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}
void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}
void F2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		printf("%d\n", n);
		F2(n + 1);
		F2(n + 3);
	}
}
void G3(int n);
void F3(int n) {
	if (n > 0);
		G3(n - 1);
}
void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}


void menu() {
	printf("------------------------------------------------------\n");
	printf("�������� �������:\n");
	printf("1: ��������� ����� n\n");
	printf("2: ������������������\n");
	printf("4: ������ �� ������� ���\n");
	printf("5: ������ �� ������� ��� 2\n");
	printf("6: ������ �� ������� ��� 3\n");
	printf("7: ������ �� ������� ��� 4\n");
	printf("\n������ 8 ���������!\n");
	printf("------------------------------------------------------\n");
	int point;
	scanf_s("%d", &point);
	switch (point) {
	case 1:
		printf("������� ����� n, ��� �������� ����� ����� ���������: ");
		int a;
		scanf_s("%d", &a);
		printf("��������� ����� %d ����� %d\n", a, factorial(a));
		break;
	case 2:
		printf("������� ����� n, ��� �������� ������ ����������� ������������������: ");
		{
			int a;
			scanf_s("%d", &a);
			rec1(a);
			printf("\n\n");
			rec2(a);
			printf("\n\n");
			rec3(a);
			printf("\n\n");
		}
		break;
	case 4:
		printf("������� ����� n: ");
		{
			int a;
			scanf_s("%d", &a);
			recEGE1(a);
		}
		break;
	case 5:
		printf("������� ����� n: ");
		{
			int a;
			scanf_s("%d", &a);
			F1(a);
		}
		break;
	case 6:
		printf("������� ����� n: ");
		{
			int a;
			scanf_s("%d", &a);
			F2(a);
		}
		break;
	case 7:
		printf("������� ����� n: ");
		{
			int a;
			scanf_s("%d", &a);
			F3(a);
		}
		break;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
}