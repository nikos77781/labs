#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include "objects.h"
#include <tchar.h>

#define N 10
#define M 15

#define WIDTH 30
#define HEIGHT 20

// 0 - �����
// 1 - �����
// 2 - �����
// 3 - ������

/*
����������

S - ���������
L - ���������
Q - ����� �� ������ �������� �����
W - �������� ������ ������
E - ��������� ����� ������ 
R - �������� ����� �����
Z - ��������� ��� ����� ������
A - ��������� ����� �� ���� ������
X - ��������� ��� ����� ������ �� ���������� 2

*/
int map[N][M] = {
	{0, 0, 0, 0, 0,     0, 0, 0, 0, 0,     0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0,     0, 0, 0, 0, 3,     0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0,     0, 0, 0, 0, 3,     0, 0, 0, 0, 0},
	{0, 0, 0, 3, 3,     3, 3, 0, 0, 0,     3, 3, 0, 0, 0},
	{0, 0, 0, 0, 0,     0, 3, 0, 0, 0,     3, 3, 0, 0, 0},

	{0, 0, 0, 0, 0,     0, 3, 3, 3, 0,     0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0,     0, 0, 0, 3, 0,     2, 0, 0, 2, 0},
	{0, 0, 0, 0, 0,     0, 0, 2, 0, 0,     2, 0, 0, 2, 0},
	{0, 0, 0, 0, 0,     0, 2, 2, 2, 2,     2, 2, 2, 2, 0},
	{0, 0, 0, 0, 0,     0, 0, 0, 0, 0,     0, 0, 0, 0, 0},
};

int steps = 0;
int gold = 0;

void drawMap(HDC hdc) {
	// ����� ��� ������� ����
	HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // �����
	// ����� ��� ���� � �������
	HBRUSH hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // ������
	// ����� ��� �����
	HBRUSH hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // ������
	// ����� ��� ������
	HBRUSH hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // �����

	// ���� �����:
	// 0 - ��������
	// 1 - �����
	// 2 - �����������
	// 3 - ������

	HBRUSH brush[4] = { hBrushEmptyCell, hBrushMan, hBrushWall, hBrushGold };

	int i, j;
	for (i = 0; i < N; i++) 
		for (j = 0; j < M; j++) {
			int x1 = j * WIDTH;
			int x2 = (j + 1) * WIDTH;
			int y1 = i * HEIGHT;
			int y2 = (i + 1) * HEIGHT;

			RECT r = { x1, y1, x2, y2 };
			FillRect(hdc, &r, brush[map[i][j]]);
		}
	for (i = 0; i < 4; i++) DeleteObject(brush[i]);

	char strC[80];
	sprintf(strC, "steps=%d  gold=%d", steps, gold);

	TCHAR  strWin[80];
	OemToChar(strC, strWin);

	HFONT hFont = CreateFont(HEIGHT, 0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
	SelectObject(hdc, hFont);
	SetTextColor(hdc, RGB(0, 0, 128));

	TextOut(hdc, 10, HEIGHT * N, (LPCWSTR)strWin, _tcslen(strWin));

	DeleteObject(hFont);

}

void Left() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (map[i][j] == 1) { // ���� � map[i][j]  �����
				if (map[i][j - 1] == 0) { // ���� ����� �� ������ - ������ ������
					map[i][j - 1] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i][j - 1] == 3) {// ���� ����� �� ������ - ������
					map[i][j - 1] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}

void Right() {
	int i, j;

	for (i = 0; i < N; i++) {

		for (j = M - 2; j >= 0; j--) {

			if (map[i][j] == 1) { // ���� � map[i][j]  �����
				if (map[i][j + 1] == 0) {
					map[i][j + 1] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i][j + 1] == 3) {
					map[i][j + 1] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}

void Up() {
	int i, j;

	for (i = 1; i < N; i++) {

		for (j = 0; j < M; j++) {

			if (map[i][j] == 1) { // ���� � map[i][j]  �����
				if (map[i - 1][j] == 0) {
					map[i - 1][j] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i - 1][j] == 3) {
					map[i - 1][j] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}

void Down() {
	int i, j;

	for (i = N - 2; i >= 0; i--) {

		for (j = 0; j < M; j++) {

			if (map[i][j] == 1) { // ���� � map[i][j]  �����
				if (map[i + 1][j] == 0) {
					map[i + 1][j] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i + 1][j] == 3) {
					map[i + 1][j] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}
void save() {
	FILE* fout;
	fout = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab21\\lab21\\game.txt", "wt");
	//if (fout == NULL) {
	//	printf("Cannot open file.\n");
	//	return;
	//}

	fprintf(fout, "%d ", N);
	fprintf(fout, "%d\n", M);
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			fprintf(fout, "%d ", map[i][j]);
		}
		fprintf(fout, "\n");
	}

	fprintf(fout, "%d ", steps);
	fprintf(fout, "%d", gold);

	fclose(fout);
}

void load() {
	FILE* fin;
	fin = fopen("C:\\Users\\klyko\\OneDrive\\������� ����\\�����\\1 ����\\������ ����������������\\����\\lab21\\lab21\\game.txt", "rt");
	//if (fin == NULL) {
	//	printf("Cannot open file.\n");
	//	return;
	//}

	int n, m;
	fscanf(fin, "%d ", &n);
	fscanf(fin, "%d\n", &m);
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(fin, "%d ", &map[i][j]);
		}
	}

	fscanf(fin, "%d ", &steps);
	fscanf(fin, "%d", &gold);

	fclose(fin);
}
void task3() {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (map[i][j] == 1) map[i][j - 1] = 2;
		}
	}

}
void task4() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (map[i][j] == 1) map[i][j + 1] = 3;
		}
	}
}
void task5() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && map[i - 1][j] == 2) map[i - 1][j] = 0;
		}
	}
}
void task6() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && map[i + 1][j]) map[i + 1][j] = 2;
		}
	}
}
void task7() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (map[i][j] == 1) {
				for (int k = j + 1; k < M - 1; k++) {
					if (map[i][k] == 2) map[i][k] = 0;
				}
			}
		}
	}
}
void task8() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (j > 0 && map[i][j - 1] == 2) map[i][j - 1] = 0;
				if (j < M && map[i][j + 1] == 2) map[i][j + 1] = 0;
				if (i > 0 && map[i - 1][j] == 2) map[i - 1][j] = 0;
				if (i < N && map[i + 1][j] == 2) map[i + 1][j] = 0;
			} 
		}
	}
}
void task9() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (j > 0 && map[i][j - 1] == 2) map[i][j - 1] = 0;
				if (j < M && map[i][j + 1] == 2) map[i][j + 1] = 0;
				if (i > 0 && map[i - 1][j] == 2) map[i - 1][j] = 0;
				if (i < N && map[i + 1][j] == 2) map[i + 1][j] = 0;
				if (j-1 > 0 && map[i][j - 2] == 2) map[i][j - 2] = 0;
				if (j+1 < M && map[i][j + 2] == 2) map[i][j + 2] = 0;
				if (i-1 > 0 && map[i - 2][j] == 2) map[i - 2][j] = 0;
				if (i+1 < N && map[i + 2][j] == 2) map[i + 2][j] = 0;
			}
		}
	}
}
void doMidasHand(int i, int j) {
	if (map[i][j] == 2) {
		map[i][j] = 3;
		if (i > 0) doMidasHand(i - 1, j);
		if (i < N - 1) doMidasHand(i + 1, j);
		if (i > 0) doMidasHand(i - 1, j);
		if (i < M - 1) doMidasHand(i, j + 1);
	}
}
void midasHandToRight() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M - 1; ++j)
			if (map[i][j] == 1 && map[i][j + 1] == 2)
				doMidasHand(i, j + 1);
}
