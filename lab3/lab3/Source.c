#include <stdio.h>
#include <Windows.h>

void main() {

	// lab3

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//ex1
	/* 
	int a, b;

	printf("������� ������ �����: ");
	scanf_s("%d", &a);
	printf("������� ������ �����: ");
	scanf_s("%d", &b);

	if (a > b) printf("������� ����� = %d \n������� ����� = %d", a, b);
	if (a < b) printf("������� ����� = %d \n������� ����� = %d", b, a);
	if (a == b) printf("����� �����");
	*/
	//ex2
	/* 
	int a, b, c, d, e;
	int max_num;

	printf("������� 5 �����: ");
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
	printf("������� �����������: ");
	scanf_s("%f", &t);
	if (t < 18) printf("�������");
	if (t >= 18 && t<22) printf("���������");
	if (t>=22 && t<26) printf("�����");
	if (t>=26) printf("�����");
	*/
	//ex4
	/* ex4
	float t; // ��������� ���������: ���������; �����: ������ �����
	printf("������� �����������: ");
	scanf_s("%f", &t);
	if (t < 0) printf("�����");
	if (t >= 0 && t < 15) printf("�������");
	if (t >= 15 && t < 27) printf("�����");
	if (t >= 27) printf("�����");
	*/
	//ex5
	/* 
	float price; // ���� ��� ������ ��������
	printf("������� ���� � RUB: ");
	scanf_s("%f", &price);
	if (price < 10000) printf("������");
	if (price >= 10000 && price < 30000) printf("���������");
	if (price >= 30000 && price < 45000) printf("������");
	if (price >= 45000) printf("���� ������");
	*/
	//ex6
	/*
	float speed; // ������ �������� ����������
	printf("������� �������� ���������� � ��/c: ");
	scanf_s("%f", &speed);
	if (speed < 1) printf("����� ��������");
	if (speed >= 1 && speed < 5) printf("��������");
	if (speed >= 5 && speed < 10) printf("���������");
	if (speed >= 10 && speed <50) printf("������");
	if (speed >= 50) printf("����� ������");
	*/

}