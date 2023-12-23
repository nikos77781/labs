#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;
int x1;

void printElements() {
	for (int i = 0; i < n; i++) {
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}
void keyboardInput() {
	printf("������� ���������� ���������: ");
	scanf_s("%d", &n);

	printf("������� %d ���������: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) arr[i] *= 10;
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
int findMax() {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
int howMuchMore() {
	int x;
	int q = 0;

	printf("������� ��������: ");
	scanf_s("%d", &x);

	x1 = x;

	for (int i = 0; i < n; i++)
		if (arr[i] > x) q++;
	return q;
}
int findLastEven() {
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) last = i;
	}
	return last;
}
void lastElementX2() {
	if (findLastEven() != -1) arr[findLastEven()] *= 2;
}
void task4() {
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;

	int numberOfEvenElements = 0;
	for (int i = 0; i < minI; i++)
		if (arr[i] % 2 == 0)
			numberOfEvenElements++;
	printf("������ ������������ ��������: %d\n", minI);
	printf("���������� ������ ��������� ����� ������������: %d\n", numberOfEvenElements);
}
void task5() {
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;

	int numberOfEvenElements = 0;
	for (int i = minI + 1; i < n; i++)
		if (arr[i] % 2 == 1)
			arr[i] *= 10;
}void task6() {
	int maxI, tmp;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMax())
			maxI = i;
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;
	tmp = arr[minI];
	arr[minI] = arr[maxI];
	arr[maxI] = tmp;
}
void task7() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) arr[i] *= -1;
	}
}
void task8() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) arr[i] = 4;
	}
}
void task9() {
	int maxI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMax())
			maxI = i;
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;
	if (minI == maxI) printf("��� ��������� ��������� ��� ����� ������� = 1\n");
	else if (minI < maxI)
		for (int i = minI + 1; i < maxI; i++)
			arr[i] *= 10;
	else if (minI > maxI)
		for (int i = maxI + 1; i < minI; i++)
			arr[i] *= 10;

}
void task10() {
	int first, last;
	int x = 0;
	for (int i = 0; i < n; i++)
		if (x == 0 && arr[i] % 2 == 0) {
			x++;
			first = i;
		}
		else if (arr[i] % 2 == 0) last = i;
	for (int i = first + 1; i < last; i++) arr[i] *= 100;
}
void deleteElement() {
	int index;
	printf("������� ������ ���������� ��������: ");
	scanf_s("%d", &index);
	for (int i = index; i < n - 1; i++)
		arr[i] = arr[i + 1];
	n -= 1;
}
void insertElement() {
	n += 1;
	int index, x;
	printf("������� ������, ���� �������� �������: ");
	scanf_s("%d", &index);
	printf("������� ��������, ������� ����� ��������: ");
	scanf_s("%d", &x);
	for (int i = n - 1; i > index; i--)
		arr[i] = arr[i-1];
	arr[index] = x;
}
void deleteMinElement() {
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;
	for (int i = minI; i < n - 1; i++)
		arr[i] = arr[i + 1];
	n -= 1;
}
void insert0() {
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;
	n += 1;
	for (int i = n - 1; i > minI; i--)
		arr[i] = arr[i - 1];
	arr[minI] = 0;
}
void task17_5() {
	for (int j = 0; j < n; j++) 
		if (arr[j] % 2 == 0) {
			for (int i = j; i < n - 1; i++)
				arr[i] = arr[i + 1];
			n -= 1;
		}
}
void task17_6() {
	for (int j = 0; j < n; j++)
		if (arr[j] % 2 == 0) {
			n += 1;
			for (int i = n - 1; i > j; i--) 
				arr[i] = arr[i - 1];
			j++;
		}
}
void insertMin() {
	int min;
	int minI;
	for (int i = 0; i < n; i++)
		if (arr[i] == findMin())
			minI = i;
	min = arr[minI];
	n += 1;
	for (int i = n - 1; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = min;
}
void delete4() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			for (int j = i; j < n - 1; j++) {
				arr[j] = arr[j + 1];
			}
			n--;
			i--;
		}
	}
}
void save() {
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab16-17\\in123.txt", "wt");
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", arr[i]);
	}
	fclose(fout);
}
void load() {
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab16-17\\in123.txt", "rt");
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d ", &arr[i]);
	}
	fclose(fin);
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("���������� �������: ");
		printElements();
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������ � ���������� ������\n");
		printf("2: x10 ��� ���� �������� ���������\n");
		printf("3: ����� ����������� �������\n");
		printf("4: ������� �������� ������ ��������� ��������\n");
		printf("5: ��������� ��������� ������ ������� � 2 ����\n");
		printf("6: ������� ������ ��������� ����� ��������������\n");
		printf("7: ��������� ��� �������� ������ ������������ � 10 ���\n");
		printf("8: �������� ����������� � ������������ �������� �������\n");
		printf("9: ��� ������ �������� ������� �������� �� -1\n");
		printf("10: ��� �������� ������� ������� �������� ������ 4 �������� �� 4\n");
		printf("11: ��� �������� ������� ����� ������������ � ����������� ��������� � 10 ���\n");
		printf("12: ��� �������� ����� ������ � ��������� ������ ��������� � 100 ���\n");
		printf("13: ������� �������\n");
		printf("14: �������� ������� � �������� �����\n");
		printf("15: ������� ����������� �������\n");
		printf("16: ����� ����������� ��������� �������� 0\n");
		printf("17: ������� ��� ������ ��������\n");
		printf("18: �������������� ��� ������ ��������\n");
		printf("19: �������� � ������ �������, ������ ������������\n");
		printf("20: ������� �� ������� ��� ��������, �������� ������� ������ 4\n");
		printf("21: �������� ��������� ������� � ����\n");
		printf("22: ��������� ��������� ������� �� �����\n");

		printf("\n");
		printf("0: ����� �� ���������\n");
		printf("��������� �������� >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 0:
			break;
		case 1:
			keyboardInput();
			break;
		case 2:
			oddsX10();
			break;
		case 3:
			printf("����������� �������: %d\n", findMin());
			break;
		case 4:
			printf("%d ��������� ������ %d\n", howMuchMore(), x1);
			break;
		case 5:
			lastElementX2();
			break;
		case 6:
			task4();
			break;
		case 7:
			task5();
			break;
		case 8:
			task6();
			break;
		case 9:
			task7();
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
			deleteElement();
			break;
		case 14:
			insertElement();
			break;
		case 15:
			deleteMinElement();
			break;
		case 16:
			insert0();
			break;
		case 17:
			task17_5();
			break;
		case 18:
			task17_6();
			break;
		case 19:
			insertMin();
			break;
		case 20:
			delete4();
			break;
		case 21:
			save();
		case 22:
			load();
		}
	} while (!0);
}