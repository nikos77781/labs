#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h> 
#include <stdio.h>

#define MAX_N 10
#define MAX_M 10

int n = 4;
int m = 5;

int arr[MAX_N][MAX_M];

void printA() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %3d ", arr[i][j]);
		}
		printf("\n");
	}
}
void point1() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = i * 10 + j;
}
void point2() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 0;
}
void point3() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % 100;
}
void point4() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(arr[i][j] % 2 == 1) arr[i][j] *= 10;
}
void point5() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] % 10 == 0) arr[i][j] /= 10;
}
void point6() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%d", &arr[i][j]);
}
void input() {
	FILE* fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab20\\in1.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}

	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			fscanf(fin, "%d", &arr[i][j]);
	fclose(fin);
}
void output() {
	FILE* fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab20\\in1.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			fprintf(fout, "%d ", arr[i][j]);
		printf("\n");
	}
	fclose(fout);
}
void deleteString() {
	int str;
	printf("����� ������ ����� �������? ");
	scanf_s("%d", &str);
	for (int i = str; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}
void duplicateColumn() {
	int col;
	m++;
	printf("����� ������� ����� ��������������? ");
	scanf_s("%d", &col);
	for (int i = 0; i < n; i++) {
		for (int j = m; j > col; j--) {
			arr[i][j] = arr[i][j - 1];
		}
	}
}
void task9A1() {
	int minI, minJ, maxI, maxJ, tmp = 10000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < tmp) {
				minI = i;
				minJ = j;
				tmp = arr[i][j];
			}
		}
	}
	tmp = -10000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > tmp) {
				maxI = i;
				maxJ = j;
				tmp = arr[i][j];
			}
		}
	}
	int sa = (arr[minI][minJ] + arr[maxI][maxJ]) / 2;
	for (int i = 0; i < minI; i++) {
		for (int j = 0; j < minJ; j++) arr[i][j] = sa;
	}
}
void task10B5() {
	int flag = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] % 2 == 0) flag = 1;
		}
		if (flag == 0) {
			for (int x = 0; x < n; x++) {
				for (int y = j; y < m-1; y++) {
					arr[x][y] = arr[x][y+1];
				}
			}
			m--;
		}
		flag = 0;
	} 
	
}


void menu() {
	printf("\n");
	printf("������ ������ �������� ���:\n");
	printA();
	printf("=======================================\n");
	printf("�������� ������ ��� ��������:\n");
	printf("1: ��������� ���������� i + 10 + j\n");
	printf("2: ��������� ������\n");
	printf("3: ��������� ���������� ����������\n");
	printf("4: ��� �������� ��������� � 10 ���\n");
	printf("5: ��� ������� 10 ��������� � 10 ���\n");
	printf("6: ������ ������ � ����������\n");
	printf("7: ��������� ������ �� �����\n");
	printf("8: ��������� ������ � ����\n");
	printf("9: ������� �������� ������\n");
	printf("10: �������������� �������� �������\n");
	printf("11: �������� ���� � ����� ������������ �������� �� (max+min)/2\n");
	printf("12: ������� �� ������, � ������� ������� arr[i][i] - ������\n");
	printf("\n");
	printf("-1: ����� �� ���������\n");
	printf("��������� �������� >>>>>> ");

	int point;
	scanf_s("%d", &point);

	switch (point) {
	case -1:
		break;
	case 1:
		point1();
		break;
	case 2:
		point2();
		break;
	case 3:
		point3();
		break;
	case 4:
		point4();
		break;
	case 5:
		point5();
		break;
	case 6:
		point6();
		break;
	case 7:
		input();
		break;
	case 8:
		output();
		break;
	case 9:
		deleteString();
		break;
	case 10:
		duplicateColumn();
		break;
	case 11:
		task9A1();
		break;
	case 12:
		task10B5();
		break;
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	while(!0) menu();

}