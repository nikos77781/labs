#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void task1() {
	printf("������ ������\n");
	printf("������ 1\n");

	int a, b, c;
	int p;

	scanf_s("%d%d%d", &a, &b, &c);
	printf("�����: %d, %d, %d\n", a, b, c);

	p = a * b * c;
	printf("p = %d\n", p);
}
void task2() {
	printf("������ ������\n");
	printf("������ 2\n");

	int a, b, c;
	int p;

	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\in2.txt.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fin, "%d%d%d", &a, &b, &c);
	fclose(fin);

	printf("�����: %d %d %d\n", a, b, c);

	p = a * b * c;

	printf("p = %d\n", p);
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\out2.txt.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������");
		return;
	}
	fprintf(fout, "%d", p);
	fclose(fout);

}
void task3() {
	printf("������ ������\n");
	printf("������ 3\n");

	int a, b, c, d, e;
	int p;
	
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("�����: %d, %d, %d, %d, %d\n", a, b, c, d, e);

	p = a + b + c + d + e;
	printf("����� ����� ����� %d", p);
}
void task4() {
	printf("������ ������\n");
	printf("������ 4\n");

	int a, b, c, d, e;
	int p;

	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\in4.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	fclose(fin);

	printf("�����: %d %d %d %d %d\n", a, b, c, d, e);

	p = a + b + c + d + e;

	printf("p = %d\n", p);
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\out4.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������");
		return;
	}
	fprintf(fout, "%d", p);
	fclose(fout);
}
void task5() {
	printf("������ ������\n");
	printf("������ 5\n");

	int arr[5];
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\in4.txt", "rt");
	for (int i = 0; i < 5; i++) {
		fscanf(fin, "%d", &arr[i]);
	}
	fclose(fin);
	printf("arr[5] = { ");
	for (int i = 0; i < 5; i++) {
		printf("%d, ", arr[i]);
	}
	printf("}\n");
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	double sr;
	sr = sum / 5;
	for (int i = 0; i < 5; i++) {
		if (arr[i] < sr) arr[i] *= 10;
	}

	printf("�������� ������: arr[5] = { ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("}\n");

	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\out4.txt", "wt");
	for (int i = 0; i < 5; i++) {
		fprintf(fout, "%d ", arr[i]);
	}

}
void task6() {
	printf("������ ������\n");
	printf("������ 6\n");

	float arr[5];
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\in4.txt", "rt");
	for (int i = 0; i < 5; i++) {
		fscanf(fin, "%f", &arr[i]);
	}
	fclose(fin);
	printf("arr[5] = { ");
	for (int i = 0; i < 5; i++) {
		printf("%f, ", arr[i]);
	}
	printf("}\n");
	float sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	float sr;
	sr = sum / 5;
	for (int i = 0;  i < 5; i++) {
		if (arr[i] < sr && (int)(arr[i])%2==0) arr[i] /= 2;
	}

	printf("�������� ������: arr[5] = { ");
	for (int i = 0; i < 5; i++) {
		printf("%f ", arr[i]);
	}
	printf("}\n");

	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab18\\out4.txt", "wt");
	for (int i = 0; i < 5; i++) {
		fprintf(fout, "%f ", arr[i]);
	}
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

}