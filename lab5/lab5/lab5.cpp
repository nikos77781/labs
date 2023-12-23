// lab5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab5.h"

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
    LoadStringW(hInstance, IDC_LAB5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB5));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB5);
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
            HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
            SelectObject(hdc, hPen);
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 128, 67));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 50, 200, 300, 250);
            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 150, 150);
            LineTo(hdc, 250, 150);
            LineTo(hdc, 300, 200);
            hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 75, 225, 125, 275);
            hPen = CreatePen(PS_SOLID, 7, RGB(0, 255, 0));
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0));
            SelectObject(hdc, hBrush);
            SelectObject(hdc, hPen);
            Ellipse(hdc, 225, 225, 275, 275);
            // Снеговик
            hPen = CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
            hBrush = CreateSolidBrush(RGB(240, 240, 240));
            SelectObject(hdc, hBrush);
            SelectObject(hdc, hPen);
            Ellipse(hdc, 375, 190, 475, 275);
            Ellipse(hdc, 388, 152, 462, 220);
            Ellipse(hdc, 400, 115, 450, 165);
            hPen = CreatePen(PS_SOLID, 2, RGB(200, 200, 200));
            hBrush = CreateSolidBrush(RGB(255, 100, 0));
            SelectObject(hdc, hBrush);
            POINT poly1[3];
            poly1[0].x = 425;
            poly1[0].y = 138;
            poly1[1].x = 425;
            poly1[1].y = 145;
            poly1[2].x = 390;
            poly1[2].y = 148;
            Polygon(hdc, poly1, 3);
            hBrush = CreateSolidBrush(RGB(178, 220, 255));
            SelectObject(hdc, hBrush);
            POINT poly2[4];
            poly2[0].x = 405;
            poly2[0].y = 127;
            poly2[1].x = 412;
            poly2[1].y = 77;
            poly2[2].x = 444;
            poly2[2].y = 77;
            poly2[3].x = 444;
            poly2[3].y = 123;
            Polygon(hdc, poly2, 4);
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(255, 255, 255));
            SelectObject(hdc, hBrush);
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 412, 133, 417, 138);
            Ellipse(hdc, 433, 133, 438, 138);
            Ellipse(hdc, 415, 170, 421, 176);
            Ellipse(hdc, 415, 186, 421, 192);
            Ellipse(hdc, 415, 202, 421, 208);
            hPen = CreatePen(PS_SOLID, 4, RGB(56, 10, 10));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 388, 186, NULL);
            LineTo(hdc, 368, 170);          
            LineTo(hdc, 363, 185);
            MoveToEx(hdc, 462, 186, NULL);
            LineTo(hdc, 482, 170);
            LineTo(hdc, 487, 185);
            // Грузовик

            POINT poly3[7];
            poly3[0].x = 500;
            poly3[0].y = 250;
            poly3[1].x = 500;
            poly3[1].y = 200;
            poly3[2].x = 525;
            poly3[2].y = 175;
            poly3[3].x = 550;
            poly3[3].y = 175;
            poly3[4].x = 575;
            poly3[4].y = 125;
            poly3[5].x = 650;
            poly3[5].y = 125;
            poly3[6].x = 650;
            poly3[6].y = 250;
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            hBrush = CreateSolidBrush(RGB(255, 0, 0));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Polygon(hdc, poly3, 7);
            MoveToEx(hdc, 600, 200, NULL);
            LineTo(hdc, 625, 200);
            hBrush = CreateSolidBrush(RGB(180, 200, 255));
            SelectObject(hdc, hBrush);
            POINT poly4[4];
            poly4[0].x = 575;
            poly4[0].y = 175;
            poly4[1].x = 590;
            poly4[1].y = 137;
            poly4[2].x = 625;
            poly4[2].y = 137;
            poly4[3].x = 625;
            poly4[3].y = 175;
            Polygon(hdc, poly4, 4);
            hBrush = CreateSolidBrush(RGB(200, 200, 200));
            SelectObject(hdc, hBrush);
            POINT poly5[4];
            poly5[0].x = 650;
            poly5[0].y = 250;
            poly5[1].x = 650;
            poly5[1].y = 175;
            poly5[2].x = 825;
            poly5[2].y = 175;
            poly5[3].x = 825;
            poly5[3].y = 250;
            Polygon(hdc, poly5, 4);
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            hBrush = CreateSolidBrush(RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 550, 225, 600, 275);
            Ellipse(hdc, 750, 225, 800, 275);
            hPen = CreatePen(PS_SOLID, 3, RGB(200, 200, 200));
            hBrush = CreateSolidBrush(RGB(100, 100, 100));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 562, 263, 588, 237);
            Ellipse(hdc, 762, 263, 788, 237);
            
            // ex4 Трава

            int x11 = 0, y11 = 300, x12 = 8, y12 = 225;
            int x21 = 8, y21 = 275, x22 = 16, y22 = 300;
            int x31 = 16, y31 = 300, x32 = 24, y32 = 250;
            
            while (x11 < 900) {
                hPen = CreatePen(PS_SOLID, 2, RGB(11, 156, 5));
                hBrush = CreateSolidBrush(RGB(86, 173, 79));
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);
                Rectangle(hdc, x11, y11, x12, y12);
                hPen = CreatePen(PS_SOLID, 1, RGB(38, 153, 105));
                hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(65, 212, 140));
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);
                Rectangle(hdc, x21, y21, x22, y22);
                hPen = CreatePen(PS_SOLID, 3, RGB(49, 156, 19));
                hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(63, 255, 42));
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);
                Rectangle(hdc, x31, y31, x32, y32);
                x11 += 24;
                x12 += 24;
                x21 += 24;
                x22 += 24;
                x31 += 24;
                x32 += 24;
            }
            // ex5 Облако

            hPen = CreatePen(PS_SOLID, 1, RGB(151, 255, 255));
            hBrush = CreateSolidBrush(RGB(151, 255, 255));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 25, 50, 125, 100);
            Ellipse(hdc, 75, 25, 200, 75);
            Ellipse(hdc, 75, 50, 175, 125);
            Ellipse(hdc, 100, 50, 250, 100);
            Ellipse(hdc, 125, 87, 225, 113);

            // ex6 

            hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            hBrush = CreateSolidBrush(RGB(255, 205, 54));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            POINT poly6[5];
            poly6[0].x = 108;
            poly6[0].y = 400;
            poly6[1].x = 100;
            poly6[1].y = 408;
            poly6[2].x = 388;
            poly6[2].y = 712;
            poly6[3].x = 450;
            poly6[3].y = 750;
            poly6[4].x = 412;
            poly6[4].y = 688;
            Polygon(hdc, poly6, 5);
            POINT poly7[5];
            poly7[0].x = 487;
            poly7[0].y = 400;
            poly7[1].x = 500;
            poly7[1].y = 408;
            poly7[2].x = 212;
            poly7[2].y = 712;
            poly7[3].x = 150;
            poly7[3].y = 750;
            poly7[4].x = 188;
            poly7[4].y = 688;
            Polygon(hdc, poly7, 5);
            hPen = CreatePen(PS_SOLID, 5, RGB(255, 205, 54));
            SelectObject(hdc, hPen);
            Arc(hdc, 173, 348, 427, 602, 402, 400, 198, 400);
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            Arc(hdc, 176, 351, 424, 599, 399, 400, 201, 400);
            Arc(hdc, 170, 345, 430, 605, 405, 400, 195, 400);
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            hBrush = CreateSolidBrush(RGB(230, 20, 20));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 150, 450, 450, 750);
            Chord(hdc, 100, 400, 275, 575, 250, 425, 125, 550);
            Chord(hdc, 325, 400, 500, 575, 475, 550, 350, 425);
            hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
            hBrush = CreateSolidBrush(RGB(255, 255, 255));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 175, 475, 425, 725);
            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
            hBrush = CreateSolidBrush(RGB(230, 20, 20));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            POINT poly8[5];
            poly8[0].x = 297;
            poly8[0].y = 600;
            poly8[1].x = 297;
            poly8[1].y = 550;
            poly8[2].x = 300;
            poly8[2].y = 537;
            poly8[3].x = 303;
            poly8[3].y = 550;
            poly8[4].x = 303;
            poly8[4].y = 600;
            Polygon(hdc, poly8, 5);
            POINT poly9[5];
            poly9[0].x = 297;
            poly9[0].y = 600;
            poly9[1].x = 308;
            poly9[1].y = 625;
            poly9[2].x = 314;
            poly9[2].y = 630;
            poly9[3].x = 312;
            poly9[3].y = 622;
            poly9[4].x = 303;
            poly9[4].y = 600;
            Polygon(hdc, poly9, 5);
            MoveToEx(hdc, 300, 600, NULL);
            LineTo(hdc, 250, 650);
            Ellipse(hdc, 297, 597, 303, 603);
            MoveToEx(hdc, 300, 500, NULL);
            LineTo(hdc, 300, 525);
            MoveToEx(hdc, 225, 600, NULL);
            LineTo(hdc, 200, 600);
            MoveToEx(hdc, 300, 675, NULL);
            LineTo(hdc, 300, 700);
            MoveToEx(hdc, 375, 600, NULL);
            LineTo(hdc, 400, 600);

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
