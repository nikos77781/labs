// lab25.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab25.h"

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
    LoadStringW(hInstance, IDC_LAB25, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB25));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB25));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB25);
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

void rectangle(HDC hdc, int cx, int cy, int csize) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx - csize, cy - csize, NULL);
    LineTo(hdc, cx + csize, cy - csize);
    LineTo(hdc, cx, cy + csize);
    LineTo(hdc, cx - csize, cy - csize);
    DeleteObject(hPen);

}
void double_rectangle(HDC hdc, int cx, int cy, int csize) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx + csize, cy + csize, NULL);
    LineTo(hdc, cx - csize, cy + csize);
    LineTo(hdc, cx + csize / 2, cy - csize / 2 - csize);
    LineTo(hdc, cx - csize / 2, cy - csize / 2 - csize);
    LineTo(hdc, cx + csize, cy + csize);
    DeleteObject(hPen);
}
void rhomb(HDC hdc, int cx, int cy, int csize) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx, cy - csize, NULL);
    LineTo(hdc, cx + csize, cy);
    LineTo(hdc, cx, cy + csize);
    LineTo(hdc, cx - csize, cy);
    LineTo(hdc, cx, cy - csize);
}
void star(HDC hdc, int cx, int cy, int csize) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx, cy - csize, NULL);
    LineTo(hdc, cx + csize/4, cy - csize/4);
    LineTo(hdc, cx + csize, cy);
    LineTo(hdc, cx + csize/4, cy + csize/4);
    LineTo(hdc, cx, cy + csize);
    LineTo(hdc, cx - csize/4, cy + csize/4);
    LineTo(hdc, cx - csize, cy);
    LineTo(hdc, cx - csize/4, cy - csize/4);
    LineTo(hdc, cx, cy - csize);
}

void task1_1(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_1(hdc, cx - csize, cy - csize, csize / 2);
    task1_1(hdc, cx + csize, cy - csize, csize / 2);
}
void task1_2(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_2(hdc, cx, cy + csize, csize / 2);
    task1_2(hdc, cx - csize, cy - csize, csize / 2);
}
void task1_3(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_3(hdc, cx, cy + csize, csize / 2);
    task1_3(hdc, cx - csize, cy - csize, csize / 2);
    task1_3(hdc, cx + csize, cy - csize, csize / 2);
}
void task1_4(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_4(hdc, cx, cy - csize, csize / 2);
}
void task1_5(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_5(hdc, cx - csize, cy, csize / 2);
}
void task1_6(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_6(hdc, cx + csize, cy, csize / 2);
}
void task1_7(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rectangle(hdc, cx, cy, csize);
    task1_7(hdc, cx, cy - csize, csize / 2);
    task1_7(hdc, cx + csize, cy, csize / 2);
    task1_7(hdc, cx - csize, cy, csize / 2);
}
void task2_1(HDC hdc, int cx, int cy, int csize) {
    if (csize < 5) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_1(hdc, cx - csize/2, cy - csize - csize/2, csize / 2);
}
void task2_2(HDC hdc, int cx, int cy, int csize) {
    if (csize < 5) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_2(hdc, cx + csize / 2, cy - csize - csize / 2, csize / 2);
    task2_2(hdc, cx - csize / 2, cy - csize - csize / 2, csize / 2);
}
void task2_3(HDC hdc, int cx, int cy, int csize) {
    if (csize < 5) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_3(hdc, cx + csize, cy + csize, csize / 2);
    task2_3(hdc, cx - csize, cy + csize, csize / 2);
}
void task2_4(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_4(hdc, cx + csize, cy + csize, csize / 2);
    task2_4(hdc, cx - csize, cy + csize, csize / 2);
    task2_4(hdc, cx - csize, cy + csize, csize / 2);
    task2_4(hdc, cx + csize / 2, cy - csize - csize / 2, csize / 2);
    task2_4(hdc, cx - csize / 2, cy - csize - csize / 2, csize / 2);
}
void task2_5(HDC hdc, int cx, int cy, int csize) {
    if (csize < 5) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_5(hdc, cx - csize, cy, csize / 2);
}
void task2_6(HDC hdc, int cx, int cy, int csize) {
    if (csize < 5) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_6(hdc, cx + csize, cy, csize / 2);
}
void task2_7(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    double_rectangle(hdc, cx, cy, csize);
    task2_7(hdc, cx + csize, cy, csize / 2);
    task2_7(hdc, cx - csize, cy, csize / 2);
}
void task3_1(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    task3_1(hdc, cx - csize, cy, csize / 2);
    task3_1(hdc, cx + csize, cy, csize / 2);
}
void task3_2(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    task3_2(hdc, cx - csize, cy, csize / 2);
    task3_2(hdc, cx + csize, cy, csize / 2);
    task3_2(hdc, cx, cy + csize, csize / 2);
}
void task3_3(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    task3_3(hdc, cx - csize, cy, csize / 2);
    task3_3(hdc, cx + csize, cy, csize / 2);
    task3_3(hdc, cx, cy - csize, csize / 2);
}
void task3_4(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    task3_4(hdc, cx - csize, cy, csize / 2);
    task3_4(hdc, cx + csize, cy, csize / 2);
    task3_4(hdc, cx, cy - csize, csize / 2);
    task3_4(hdc, cx, cy + csize, csize / 2);
}
void task3_5(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    task3_5(hdc, cx - csize, cy, csize / 2);
    //task3_5(hdc, cx + csize, cy, csize / 2);
    task3_5(hdc, cx, cy - csize, csize / 2);
    task3_5(hdc, cx, cy + csize, csize / 2);
}
void task3_6(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    //task3_6(hdc, cx - csize, cy, csize / 2);
    task3_6(hdc, cx + csize, cy, csize / 2);
    task3_6(hdc, cx, cy - csize, csize / 2);
    task3_6(hdc, cx, cy + csize, csize / 2);
}
void task3_7(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    task3_7(hdc, cx - csize, cy, csize / 2);
    //task3_7(hdc, cx + csize, cy, csize / 2);
    task3_7(hdc, cx, cy - csize, csize / 2);
    //task3_7(hdc, cx, cy + csize, csize / 2);
}
void task3_8(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    rhomb(hdc, cx, cy, csize);
    //task3_8(hdc, cx - csize, cy, csize / 2);
    task3_8(hdc, cx + csize, cy, csize / 2);
    //task3_8(hdc, cx, cy - csize, csize / 2);
    task3_8(hdc, cx, cy + csize, csize / 2);
}
void task4_1(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    task4_1(hdc, cx - csize, cy, csize / 2);
    task4_1(hdc, cx + csize, cy, csize / 2);
}
void task4_2(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    task4_2(hdc, cx, cy + csize, csize / 2);
    task4_2(hdc, cx, cy - csize, csize / 2);
}
void task4_3(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    task4_3(hdc, cx - csize, cy, csize / 2);
    task4_3(hdc, cx, cy + csize, csize / 2);
    task4_3(hdc, cx, cy - csize, csize / 2);
}
void task4_4(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    task4_4(hdc, cx - csize, cy, csize / 2);
    task4_4(hdc, cx + csize, cy, csize / 2);
    task4_4(hdc, cx, cy - csize, csize / 2);
    task4_4(hdc, cx, cy + csize, csize / 2);
}
void task4_5(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    task4_5(hdc, cx + csize, cy, csize / 2);
    //task4_5(hdc, cx + csize, cy, csize / 2);
    task4_5(hdc, cx, cy - csize, csize / 2);
    task4_5(hdc, cx, cy + csize, csize / 2);
}
void task4_6(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    //task4_6(hdc, cx - csize, cy, csize / 2);
    task4_6(hdc, cx + csize/2, cy, csize / 2);
    task4_6(hdc, cx + csize, cy - csize, csize / 2);
    task4_6(hdc, cx, cy + csize, csize / 2);
    task4_6(hdc, cx - csize, cy - csize, csize / 2);
    task4_6(hdc, cx - csize / 2, cy, csize / 2);
}
void task4_7(HDC hdc, int cx, int cy, int csize) {
    if (csize < 10) return;
    star(hdc, cx, cy, csize);
    task4_7(hdc, cx - csize, cy, csize / 2);
    //task4_7(hdc, cx + csize, cy, csize / 2);
    task4_7(hdc, cx, cy - csize, csize / 2);
    //task4_7(hdc, cx, cy + csize, csize / 2);
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
            //task1(hdc, 300, 300, 150);
            //task1_1(hdc, 300, 300, 150);
            //task1_2(hdc, 300, 300, 150);
            //task1_3(hdc, 300, 300, 150);
            //task1_4(hdc, 300, 300, 150);
            //task1_5(hdc, 300, 300, 150);
            //task1_6(hdc, 300, 300, 150);
            //task1_7(hdc, 300, 300, 150);
            //task2_1(hdc, 300, 300, 100);
            //task2_2(hdc, 300, 300, 100);
            //task2_3(hdc, 300, 300, 100);
            //task2_4(hdc, 300, 300, 100);
            //task2_5(hdc, 300, 300, 100);
            //task2_6(hdc, 300, 300, 100);
            //task2_7(hdc, 300, 300, 100);
            //task3_1(hdc, 300, 300, 100);
            //task3_2(hdc, 300, 300, 100);
            //task3_3(hdc, 300, 300, 100);
            //task3_4(hdc, 300, 300, 100);
            //task3_5(hdc, 300, 300, 100);
            //task3_6(hdc, 300, 300, 100);
            //task3_7(hdc, 300, 300, 100);
            //task3_8(hdc, 300, 300, 100);
            //task4_1(hdc, 300, 300, 100);
            //task4_2(hdc, 300, 300, 100);
            //task4_3(hdc, 300, 300, 100);
            //task4_4(hdc, 300, 300, 100);
            //task4_5(hdc, 300, 300, 100);
            //task4_6(hdc, 300, 300, 100);
            //task4_7(hdc, 300, 300, 100);
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
