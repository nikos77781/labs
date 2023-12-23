// lab9.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab9.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

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
    LoadStringW(hInstance, IDC_LAB9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB9);
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
//task1
void StClausAuto(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 200, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}
//task2
void drawTruck(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);
}
void drawTrucks1(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 160, 160);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 310);
}
void drawTrucks2(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 115, 10);
    drawTruck(hdc, 220, 10);
    drawTruck(hdc, 325, 10);
    drawTruck(hdc, 430, 10);
}
void drawTrucks3(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 80);
    drawTruck(hdc, 10, 150);
    drawTruck(hdc, 10, 220);
    drawTruck(hdc, 10, 290);
}
void drawTrucks4(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 80, 80);
    drawTruck(hdc, 150, 150);
    drawTruck(hdc, 220, 220);
    drawTruck(hdc, 290, 290);
}
//task3
void drawSnowWoman(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, x + 60, 120 + y);
    MoveToEx(hdc, 14 + x, 28 + y, NULL);
    LineTo(hdc, 0 + x, 40 + y);
    MoveToEx(hdc, 46 + x, 28 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);
    MoveToEx(hdc, 40 + x, 120 + y, NULL);
    LineTo(hdc, 70 + x, 0 + y);
    MoveToEx(hdc, 66 + x, 20 + y, NULL);
    LineTo(hdc, 65 + x, y + 0);
    MoveToEx(hdc, 66 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, y + 0);
}
void drawSnowWomans1(HDC hdc) {
    drawSnowWoman(hdc, 10, 10);
    drawSnowWoman(hdc, 250, 10);
    drawSnowWoman(hdc, 130, 140);
    drawSnowWoman(hdc, 10, 270);
    drawSnowWoman(hdc, 250, 270);
}
void drawSnowWomans2(HDC hdc) {
    drawSnowWoman(hdc, 10, 10);
    drawSnowWoman(hdc, 100, 10);
    drawSnowWoman(hdc, 190, 10);
    drawSnowWoman(hdc, 280, 10);
    drawSnowWoman(hdc, 370, 10);
}
void drawSnowWomans3(HDC hdc) {
    drawSnowWoman(hdc, 10, 10);
    drawSnowWoman(hdc, 10, 150);
    drawSnowWoman(hdc, 10, 290);
    drawSnowWoman(hdc, 10, 430);
    drawSnowWoman(hdc, 10, 570);
}
void drawSnowWomans4(HDC hdc) {
    drawSnowWoman(hdc, 10, 10);
    drawSnowWoman(hdc, 100, 150);
    drawSnowWoman(hdc, 190, 290);
    drawSnowWoman(hdc, 280, 430);
    drawSnowWoman(hdc, 370, 570);
}
//ex4
void drawCarLogo(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 10 + y, 130 + x, 130 + y);
    hPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 0 + x, 60 + y, NULL);
    LineTo(hdc, 90 + x, 60 + y);
    LineTo(hdc, 50 + x, 80 + y);
    LineTo(hdc, 140 + x, 80 + y);
}
//ex5
void drawCarLogos1(HDC hdc) {
    drawCarLogo(hdc, 0, 0);
    drawCarLogo(hdc, 250, 0);
    drawCarLogo(hdc, 125, 125);
    drawCarLogo(hdc, 0, 250);
    drawCarLogo(hdc, 250, 250);
}
void drawCarLogos2(HDC hdc) {
    drawCarLogo(hdc, 10, 0);
    drawCarLogo(hdc, 160, 0);
    drawCarLogo(hdc, 310, 0);
    drawCarLogo(hdc, 460, 0);
    drawCarLogo(hdc, 610, 0);
    drawCarLogo(hdc, 760, 0);
}
void drawCarLogos3(HDC hdc) {
    drawCarLogo(hdc, 10, 10);
    drawCarLogo(hdc, 10, 150);
    drawCarLogo(hdc, 10, 290);
    drawCarLogo(hdc, 10, 430);
}
void drawCarLogos4(HDC hdc) {
    drawCarLogo(hdc, 10, 10);
    drawCarLogo(hdc, 150, 150);
    drawCarLogo(hdc, 290, 290);
    drawCarLogo(hdc, 430, 430);
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            //ex1.1
            /*
            StClausAuto(hdc, 0, 0);
            StClausAuto(hdc, 100, 0);
            StClausAuto(hdc, 50, 50);
            StClausAuto(hdc, 0, 100);
            StClausAuto(hdc, 100, 100);
            */
            // ex1.2
            /*
            int x = 0, i = 0;
            do {
                StClausAuto(hdc, x, 0);
                i++;
                x += 45;
            } while (i < 8);
            
            //ex1.3
            
            int y = 0;
            i = 0;
            do {
                StClausAuto(hdc, 0, y);
                i++;
                y += 85;
            } while (i < 4);
            
            //ex1.4
            
            x = 0, y = 0, i = 0;
            do {
                StClausAuto(hdc, x, y);
                i++;
                x += 45;
                y += 85;
            } while (i < 4);
            */
            
            //ex2
            //drawTrucks1(hdc);
            //drawTrucks2(hdc);
            //drawTrucks3(hdc);
            //drawTrucks4(hdc);

            //ex3
            //drawSnowWoman(hdc, 0, 0);
            //drawSnowWomans1(hdc);
            //drawSnowWomans2(hdc);
            //drawSnowWomans3(hdc);
            //drawSnowWomans4(hdc);

            //ex4
            //drawCarLogo(hdc, 10, 0);
            //ex5
            //drawCarLogos1(hdc);
            //drawCarLogos2(hdc);
            //drawCarLogos3(hdc);
            //drawCarLogos4(hdc);
            
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
