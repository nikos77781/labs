#include <stdio.h>
#include <Windows.h>

void print1_10() {
	int a = 1;
	do {
		printf("%d ", a);
		a++;
	} while (a <= 10);
}

void print10_1() {
	int a = 10;
	do {
		printf("%d ", a);
		a--;
	} while (a >= 1);
}

void print5Odds() {
	printf("1 3 5 7 9");
}

void print100_10_while() {
	int a = 100;
	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
}

void print1000_100_goto() {
	int a = 1000;
	m1:
		printf("%d ", a);
		a -= 100;
		if (a >= 100) goto m1;
}

void print_acc_changes() {
	int s, n, i = 0;
	printf("s = ");
	scanf_s("%d", &s);
	printf("n = ");
	scanf_s("%d", &n);
	m2:
		printf("����� %d ���: %d\n", i, s);
		s += s * n / 100;
		i++;
		if (i <= 10) goto m2;
}

void print1000_n() {
	int n, s = 1000;
	printf("n = ");
	scanf_s("%d", &n);
	printf("%d\n", s);
	while (s >= 0) {
		s -= n;
		printf("%d\n", s);
	}
}

void printFac() {
	int n, i = 1, s = 1;
	printf("n = ");
	scanf_s("%d", &n);
	while (i <= n) {
		printf("%d\n", s);
		s *= i;
		i++;
	}
}

void printFib() {
	int i = 0, n, n1 = 1, n2 = 1, x;
	printf("n = ");
	scanf_s("%d", &n);
	if (n == 2) {
		printf("1 1\n");
	}
	else if (n == 1) {
		printf("1\n");
	}
	else {
		printf("1 1 ");
		while (i < n-2) {
			x = n2;
			n2 += n1;
			n1 = x;
			printf("%d ", n2);
			i++;
		}
	}
}

void simpleMul() {
	int n, i = 2, m;
	printf("n = ");
	scanf_s("%d", &n);
	if (n < 2) printf("Error!");
	else {
		while (i <= n) {
			if (n % i == 0) {
				printf("%d ", i);
				n /= i;
				i = 2;
			}
			i++;
		}
	}
}

void task1_9() {
	int n;
	do {
			printf("\n");
			printf("\n");
			printf("�������� ������ ��� ��������:\n");
			printf("1: ������� ����� �� 1 �� 10\n");
			printf("2: ������� ����� �� 10 �� 1\n");
			printf("3: ������� 5 ������ �������� ����� ������� � 1\n");
			printf("11: ������� ����� �� 100 �� 10 � ����� 10\n");
			printf("12: ������� ����� �� 1000 �� 100 � ����� 100\n");
			printf("13: ������� ��������� ����� �� 10 ���, �� ������� ���������� ���� S ������ ��� N %% �������\n");
			printf("20: ������� ����� �� 1000 �� 0 � ����� N\n");
			printf("21: ������� N ������ �����������\n");
			printf("40: ������� ������ N ����� ���������\n");
			printf("50: ������� ������� ��������� �����\n");
			printf("\n");
			printf("0: ����� �� ���������\n");
			scanf_s("%d", &n);
			switch (n) {
			case 1:
				print1_10();
				break;
			case 2:
				print10_1();
				break;
			case 3:
				print5Odds();
				break;
			case 11:
				print100_10_while();
				break;
			case 12:
				print1000_100_goto();
				break;
			case 13:
				print_acc_changes();
				break;
			case 20:
				print1000_n();
				break;
			case 21:
				printFac();
				break;
			case 40:
				printFib();
				break;
			case 50:
				simpleMul();
				break;
			}
		} while (n != 0);
}

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	task1_9();
}