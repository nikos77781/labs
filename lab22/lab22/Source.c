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
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c == '�')
		new_c = '�';
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
	printf("������� ���� ���: ");
	fgets(name, 11, stdin);
	printf("����������� ����, %s\n", name);
	
}
void task2() {
	printf("������� ������: ");
	int ch = getchar();

	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}
void task3() {
	printf("������� ������: ");
	int ch = getchar();

	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}
void task4() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') cnt++;
	}
	printf("\n� ��� %d ��������\n", cnt);

}
void task5() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') s[i] = '#';
	}
	printf("\n�������� ������: %s\n", s);

}
void task6_1() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i])) s[i] = '$';
	}
	printf("\n�������� ������: %s\n", s);

}
void task6_2() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (isdigitMy(s[i])) s[i] = '$';
	}
	printf("\n�������� ������: %s\n", s);

}
void task7_1() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupper(s[i]);
	printf("\n�������� ������: %s\n", s);
}
void task7_2() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupperMy(s[i]);
	printf("\n�������� ������: %s\n", s);
}
void task8() {
	printf("�������� ������������ ������ �21\n");
}
void task9() {
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������: %s", s);

	printf("\n����� ������: %d", strlenMy(s));
}
void task10() {
	char s1[80];
	char s2[80];
	printf("������� ������: ");
	fgets(s1, 79, stdin);
	printf("\n�� ����� ������: %s", s1);
	printf("\n������� ������: ");
	fgets(s2, 79, stdin);
	printf("\n�� ����� ������: %s", s2);

	if (strcmpMy(s1, s2) < 0) printf("s1 < s2");
	else if (strcmpMy(s1, s2) == 0) printf("s1 = s2");
	else printf("s1 > s2");
}
void task11() {
	char s1[80];
	char s2[80];
	printf("������� ������: ");
	fgets(s1, 79, stdin);
	printf("\n�� ����� ������: %s", s1);
	printf("\n������� ������: ");
	fgets(s2, 79, stdin);
	printf("\n�� ����� ������: %s", s2);
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
	printf("��� ������� ������� ��������� ����� �������� �������� �$�.\n");
	printf("������� ������: ");
	fgets(s1, 79, stdin);
	var3_replace(s1);
	printf("�������� ������:\n%s", s1);
}

void menu() {

	printf("\n");
	printf("=======================================\n");
	printf("�������� ������ ��� ��������:\n");
	printf("1: Hello �� ������!\n");
	printf("2: ������� �� ����� 30 �������� � ������ �� CH �� CH+19\n");
	printf("3: ������� �� ����� 30 �������� � ������ �� CH �� CH-29\n");
	printf("4: ������ ������ s. ����������, ������� � ��� ��������\n");
	printf("5: ������ ������ s. ��� ������� � ��� �������� �������� �#�\n");
	printf("6: ������ ������ s. ��� ����� � ��� �������� �������� �$� (isdigit())\n");
	printf("7: ������ ������ s. ��� ����� � ��� �������� �������� �$� (isdigitMy())\n");
	printf("8: ������ ������ s (��� ������� ��������). ��� ��������� ��������� ����� ���������� � ������� (toupper())\n");
	printf("9: ������ ������ s � �������� � ���������� ���������. ��� ��������� ����� ���������� � ������� (toupperMy())\n");
	printf("10: � ����, ������������� � ������������ ������ �21, �������� ����� ������ ��������� ����\n");
	printf("11: ����������� ����������� ������ ������� int strlen(char *)\n");
	printf("12: ����������� ����������� ������ ������� int strcmp (char *, char *)\n");
	printf("13: ����������� ����������� ������ ������� void strcpy (char *, char *)\n");
	printf("14: ����������� ����������� ������ ������� void strcat (char *, char *)\n");
	printf("15: ��� ������� ������� ��������� ����� �������� ��������  �$�\n");
	printf("\n");
	printf("-1: ����� �� ���������\n");
	printf("��������� �������� >>>>>> ");

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