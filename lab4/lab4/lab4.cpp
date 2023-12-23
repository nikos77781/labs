// lab4.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab4.h"

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
    LoadStringW(hInstance, IDC_LAB4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB4));

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

    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB4));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB4);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
        
        // Ёлочка 2
        
        hPen = CreatePen(PS_SOLID, 10, RGB(239, 24, 28));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 75, 525, NULL);
        LineTo(hdc, 75, 475);
        hPen = CreatePen(PS_SOLID, 10, RGB(255, 127, 39));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 10, 475, NULL);
        LineTo(hdc, 140, 475);
        hPen = CreatePen(PS_SOLID, 10, RGB(255, 242, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 20, 450, NULL);
        LineTo(hdc, 130, 450);
        hPen = CreatePen(PS_SOLID, 10, RGB(34, 177, 76));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 30, 425, NULL);
        LineTo(hdc, 120, 425);
        hPen = CreatePen(PS_SOLID, 10, RGB(153, 217, 234));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 40, 400, NULL);
        LineTo(hdc, 110, 400);
        hPen = CreatePen(PS_SOLID, 10, RGB(63, 72, 204));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 50, 375, NULL);
        LineTo(hdc, 100, 375);
        hPen = CreatePen(PS_SOLID, 10, RGB(163, 73, 164));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 50, 375, NULL);
        LineTo(hdc, 75, 312);
        LineTo(hdc, 100, 375);
        
        // Забор
        
        int x = 0, y = 0, z = 1;
        hPen = CreatePen(PS_SOLID, z, RGB(200, y, 150));
        SelectObject(hdc, hPen);
        while (x < 600) {
            MoveToEx(hdc, 10+x, 550, NULL);
            LineTo(hdc, 50 + x, 550);
            LineTo(hdc, 50 + x, 450);
            LineTo(hdc, 30 + x, 425);
            LineTo(hdc, 10 + x, 450);
            LineTo(hdc, 10 + x, 550);
            y += 10;
            z += 1;
            hPen = CreatePen(PS_SOLID, z, RGB(200, y, 150));
            SelectObject(hdc, hPen);
            x += 40;
        }
        
        // Солнышко
        
        hPen = CreatePen(PS_SOLID, 5, RGB(255, 240, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 40, 120, NULL);
        LineTo(hdc, 40, 60);
        LineTo(hdc, 80, 20);
        LineTo(hdc, 140, 20);
        LineTo(hdc, 180, 60);
        LineTo(hdc, 180, 120);
        LineTo(hdc, 140, 160);
        LineTo(hdc, 80, 160);
        LineTo(hdc, 40, 120);
        MoveToEx(hdc, 60, 180, NULL);
        LineTo(hdc, 40, 220);
        MoveToEx(hdc, 110, 180, NULL);
        LineTo(hdc, 110, 230);
        MoveToEx(hdc, 160, 180, NULL);
        LineTo(hdc, 185, 215);
        MoveToEx(hdc, 190, 150, NULL);
        LineTo(hdc, 235, 175);
        MoveToEx(hdc, 200, 90, NULL);
        LineTo(hdc, 250, 90);
        MoveToEx(hdc, 200, 40, NULL);
        LineTo(hdc, 250, 15);
        hPen = CreatePen(PS_SOLID, 7, RGB(255, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 80, 120, NULL);
        LineTo(hdc, 100, 140);
        LineTo(hdc, 120, 140);
        LineTo(hdc, 140, 120);
        hPen = CreatePen(PS_SOLID, 8, RGB(0, 0, 255));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 85, 50, NULL);
        LineTo(hdc, 85, 90);
        MoveToEx(hdc, 135, 50, NULL);
        LineTo(hdc, 135, 90);
        
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
