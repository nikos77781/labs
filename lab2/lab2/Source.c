#include <stdio.h>
#include <math.h>
#include <Windows.h>

void main() {

	// lab2

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ex1
	/* 
	float g = 9.8; //��������� ���������� �������
	float height = 15; //������ � ������

	float time = sqrt(2 * height / g); //����� ������� � ��������

	printf("������ �� ������ ������ �������: %f ������.\n", height);
	printf("����� �������: %f ������.\n", time);
	*/
	// ex2
	/* 
	float g = 9.8; //��������� ���������� �������
	float height; //������ � ������

	printf("������� ��������� ������ � ������: ");
	scanf_s("%f", &height);

	float time = sqrt(2 * height / g); //����� ������� � ��������

	printf("������ �� ������ ������ �������: %f ������.\n", height);
	printf("����� �������: %f ������.\n", time);
	*/
	// ex3
	/* 
	float price_m; //���� �^2
	float square; //������� ��������

	printf("������� ����� ���������� ���� ��������? \n������� �������� � RUB: ");
	scanf_s("%f", &price_m);
	printf("������ ������� ��������? \n������� �������� � m^2: ");
	scanf_s("%f", &square);

	printf("��������� �������� �������� %f m^2 � ����� %f RUB �� m^2 ���������� %f RUB", square, price_m, price_m * square);
	*/
	// ex4
	/* 
	float price_m; // ���� �^2
	float square; // ������� ��������
	int salary; // ��������
	float n; // ������� ������� ����� �����������
	float price; // ��������� ��������

	printf("������� ����� ���������� ���� ��������? \n������� �������� � RUB: ");
	scanf_s("%f", &price_m);
	printf("������ ������� ��������? \n������� �������� � m^2: ");
	scanf_s("%f", &square);
	printf("������ ���� ��������?\n������� �������� � RUB: ");
	scanf_s("%d", &salary);

	price = square * price_m;
	n = price / (salary/2);

	if((int)n < n) n += 1;
	n = (int)n;

	printf("��������� �������� �������� %f m^2 � ����� %f RUB �� m^2 ���������� %f RUB\n", square, price_m, price);
	printf("�� �������� �������� ����� ����������� %f �������\n", n);
	*/
	//ex5
	/* 
	float r; // ������ ����
	float pi = 3.14; // ����� ��
	float vol; // ����� ����
	
	printf("������� ������ ����: ");
	scanf_s("%f", &r);

	vol = 4 * pi * r * r * r / 3;

	printf("����� ����: %f", vol);
	*/
	// ex6
	/* 
	float v; // ����� ����
	float p; // ��������� ����
	float m; // ����� ����

	printf("������� ����� ���� � �^3: ");
	scanf_s("%f", &v);
	printf("������� ��������� ���� � ��/�^3: ");
	scanf_s("%f", &p);

	m = v * p;

	printf("����� ���� ������� %f �^3 � ���������� %f ��/�^3 ����� %f ��.", v, p, m);	
	*/
	// ex7
	/* 
	float numbers_of_episodes; // ���������� �����
	float duration; // ������� ������������ ����� � �������
	int total_time; // ����� ����� �������
	float n; // ���������� ��������� ������� ����������� �� �
	
	printf("������� ���������� ����� ���������� �������: ");
	scanf_s("%f", &numbers_of_episodes);
	printf("������� ������� ����������������� ����� � �������: ");
	scanf_s("%f", &duration);

	total_time = duration * numbers_of_episodes / 60;
	n = total_time / (400 / 200 / 60.* 800);


	printf("�� �������� ���������� ������� �� ��������� %d �����. �� ��� ����� �� ����� ��������� ������ ���������� �� C %f ���.", total_time, n);
	*/

}