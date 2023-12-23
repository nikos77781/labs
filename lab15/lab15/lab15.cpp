// lab15.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab15.h"
#include "Images.h"

#define MAX_LOADSTRING 100
#define NUM_IM_A 16

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int dx, dy;
int i = 0, j = 0;
int dr, dg, db;
int type = 0;

struct Image {
    int x;
    int y;
    int vx;
    int vy;
};

typedef struct Image IMAGE;

IMAGE im1 = { 100, 300, 10, 0 };
IMAGE im2 = { 1200, 300, -10, 0 };
IMAGE im3 = { 650, 100, 0, 10 };
IMAGE im4 = { 650, 600, 0, -10 };
IMAGE im5 = { 650, 350, 0, 0 };
IMAGE imA[NUM_IM_A] = {
    { 700, 300, 10, 0},
    { 700, 300, 9, 4},
    { 700, 300, 7, 7},
    { 700, 300, 4, 9},
    { 700, 300, 0, 10},
    { 700, 300, -4, 9},
    { 700, 300, -7, 7},
    { 700, 300, -9, 4},
    { 700, 300, -10, 0},
    { 700, 300, -9, -4},
    { 700, 300, -7, -7},
    { 700, 300, -4, -9},
    { 700, 300, 0, - 10},
    { 700, 300, 4, -9},
    { 700, 300, 7, -7},
    { 700, 300, 9, -4}
};


// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB15, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB15));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB15));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB15);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_LBUTTONDOWN:
        WORD xPos, yPos;

        // Сохраняем координаты курсора мыши
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_SPACE:
            type++;
            if (type > 2) type = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_CREATE:
        SetTimer(hWnd, 1, 100, 0);
        break;

    case WM_TIMER:
    {
        dx = rand() % 10;
        dy = rand() % 21 - 10;
        im1.x += im1.vx;
        im1.y += im1.vy;

        im2.x += im2.vx;
        im2.y += im2.vy;

        im3.x += im3.vx;
        im3.y += im3.vy;

        im4.x += im4.vx;
        im4.y += im4.vy;

        im5.x += dx;
        im5.y += dy;

        while (i < NUM_IM_A) {
            imA[i].x += imA[i].vx;
            imA[i].y += imA[i].vy;
            if (imA[i].x <= 20 || imA[i].x >= 1405) imA[i] = { imA[i].x, imA[i].y, -imA[i].vx, imA[i].vy };
            if (imA[i].y <= 20 || imA[i].y >= 676) imA[i] = { imA[i].x, imA[i].y, imA[i].vx, -imA[i].vy };
            i++;
        }
        i = 0;


        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            int nx = 0;
            //Rectangle(hdc, 0, 0, 1425, 696);
            if (type == 0) {
                Image0(hdc, im1.x, im1.y, RGB(0, 0, 0));
                Image1(hdc, im2.x, im2.y, RGB(0, 0, 0));
                Image2(hdc, im3.x, im3.y, RGB(0, 0, 0));
                Image3(hdc, im4.x, im4.y, RGB(0, 0, 0));
                Image4(hdc, im5.x, im5.y, RGB(0, 0, 0));
            }
            if (type == 1) {
                while (j<NUM_IM_A) {
                    dr = rand() % 256;
                    dg = rand() % 256;
                    db = rand() % 256;
                    Image6(hdc, imA[j].x, imA[j].y, RGB(dr, dg, db));
                    j++;
                }
            }
            j = 0;
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
