// lab7.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab7.h"

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
    LoadStringW(hInstance, IDC_LAB7, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB7));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB7);
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            HPEN hPen;
            hPen = CreatePen(PS_SOLID, 3, RGB(40, 120, 200));
            SelectObject(hdc, hPen);
            
            // Домик
            MoveToEx(hdc, 150, 350, NULL);
            LineTo(hdc, 275, 250);
            LineTo(hdc, 400, 350);
            LineTo(hdc, 150, 350);
            LineTo(hdc, 150, 525);
            LineTo(hdc, 400, 525);
            LineTo(hdc, 400, 350);
            MoveToEx(hdc, 225, 400, NULL);
            LineTo(hdc, 325, 400);
            LineTo(hdc, 325, 475);
            LineTo(hdc, 225, 475);
            LineTo(hdc, 225, 400);
            MoveToEx(hdc, 275, 400, NULL);
            LineTo(hdc, 275, 475);
            MoveToEx(hdc, 275, 425, NULL);
            LineTo(hdc, 325, 425);
            // Ёлочка
            hPen = CreatePen(PS_SOLID, 3, RGB(10, 200, 140));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 525, 375, NULL);
            LineTo(hdc, 550, 400);
            LineTo(hdc, 500, 400);
            LineTo(hdc, 525, 375);
            MoveToEx(hdc, 525, 400, NULL);
            LineTo(hdc, 575, 450);
            LineTo(hdc, 475, 450);
            LineTo(hdc, 525, 400);
            MoveToEx(hdc, 525, 450, NULL);
            LineTo(hdc, 600, 525);
            LineTo(hdc, 450, 525);
            LineTo(hdc, 525, 450);
            // Куст 1
            hPen = CreatePen(PS_SOLID, 2, RGB(100, 20, 140));
            SelectObject(hdc, hPen);
            int x1 = 400;
            do {
                MoveToEx(hdc, 500, 250, NULL);
                LineTo(hdc, x1, 150);
                x1 += 10;
            } while (x1<=600);
            // Куст 2
            hPen = CreatePen(PS_SOLID, 1, RGB(10, 200, 140));
            SelectObject(hdc, hPen);
            int x2 = 0, y2 = 250;
            do {
                MoveToEx(hdc, 100, 250, NULL);
                LineTo(hdc, x2, y2);
                x2 += 5;
                y2 -= 10;
            } while (x2 < 100);
            do {
                MoveToEx(hdc, 100, 250, NULL);
                LineTo(hdc, x2, y2);
                x2 += 5;
                y2 += 10;
            } while (x2 <= 200);
            // Забор

            int x3 = 150;
            hPen = CreatePen(PS_SOLID, 3, RGB(255, 10, 10));
            SelectObject(hdc, hPen);
            do {
                MoveToEx(hdc, x3, 0, NULL);
                LineTo(hdc, x3, 100);
                x3 += 10;
            } while (x3<=450);
            
            // Лестница
            
            int x4 = 0, y4 = 525, i = 1;
            hPen = CreatePen(PS_SOLID, 3, RGB(100, 250, 100));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, x4, y4, NULL);
            do {
                if (i % 2 == 1) x4 += 15;
                else y4 -= 7;
                LineTo(hdc, x4, y4);
                i++;
            } while (x4<150);

            // Забор
            int x5 = 0, y5 = 0, z5 = 1;
            hPen = CreatePen(PS_SOLID, z5, RGB(100, y5, 250));
            SelectObject(hdc, hPen);
            do {
                MoveToEx(hdc, 20 + x5, 550, NULL);
                LineTo(hdc, 50 + x5, 550);
                LineTo(hdc, 50 + x5, 450);
                LineTo(hdc, 35 + x5, 425);
                LineTo(hdc, 20 + x5, 450);
                LineTo(hdc, 20 + x5, 550);
                y5 += 10;
                z5 += 1;
                hPen = CreatePen(PS_SOLID, z5, RGB(100, y5, 250));
                SelectObject(hdc, hPen);
                x5 += 30;
            } while (x5 < 600);
            
            // Рисунок 1
            hPen = CreatePen(PS_SOLID, 1, RGB(100, 200, 250));
            SelectObject(hdc, hPen);
            int x6 = 0, x7 = 250, y6 = 725, y7 = 675; 
            do {
                MoveToEx(hdc, x6, y6, NULL);
                LineTo(hdc, x7, y7);
                x6 += 5;
                y6 -= 7;
                x7 -= 5;
                y7 += 7;
            
            } while (x6 <= 100);

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
