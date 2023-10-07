// lab9_2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab9_2.h"

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
void drawLogo(HDC hdc, int x, int y);

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
    LoadStringW(hInstance, IDC_LAB92, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB92));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB92));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB92);
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

            int n = 0;

            drawLogo(hdc, 0, 0);
            drawLogo(hdc, 150, 150);
            drawLogo(hdc, 0, 300);
            drawLogo(hdc, 300, 0);
            drawLogo(hdc, 300, 300);

            do {
                drawLogo(hdc, 0 + n, 600);
                n += 160;
            } while (n <= 900);
            n = 0;

            do {
                drawLogo(hdc, 610, 0 + n);
                n += 80;
            } while (n <= 500);
            n = 0;

            do {
                drawLogo(hdc, 780 + n, 0 + n);
                n += 100;
            } while (n <= 300);
            n = 0;

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

void drawLogo(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 75 + x, 4 + y, NULL);
    LineTo(hdc, 6 + x, 4 + y);
    LineTo(hdc, 14 + x, 15 + y);
    LineTo(hdc, 20 + x, 44 + y);
    LineTo(hdc, 75 + x, 55 + y);
    LineTo(hdc, 129 + x, 44 + y);
    LineTo(hdc, 135 + x, 15 + y);
    LineTo(hdc, 142 + x, 4 + y);
    LineTo(hdc, 75 + x, 4 + y);

    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 72 + x, 13 + y, NULL);
    LineTo(hdc, 72 + x, 9 + y);
    LineTo(hdc, 16 + x, 9 + y);
    LineTo(hdc, 19 + x, 13 + y);
    LineTo(hdc, 30 + x, 13 + y);
    LineTo(hdc, 28 + x, 9 + y);

    MoveToEx(hdc, 72 + x, 15 + y, NULL);
    LineTo(hdc, 20 + x, 15 + y);
    LineTo(hdc, 21 + x, 18 + y);
    LineTo(hdc, 72 + x, 18 + y);
    LineTo(hdc, 72 + x, 15 + y);

    MoveToEx(hdc, 72 + x, 25 + y, NULL);
    LineTo(hdc, 72 + x, 21 + y);
    LineTo(hdc, 21 + x, 21 + y);
    LineTo(hdc, 22 + x, 26 + y);
    LineTo(hdc, 33 + x, 26 + y);
    LineTo(hdc, 32 + x, 21 + y);

    MoveToEx(hdc, 51 + x, 28 + y, NULL);
    LineTo(hdc, 22 + x, 28 + y);
    LineTo(hdc, 23 + x, 35 + y);
    LineTo(hdc, 51 + x, 35 + y);
    LineTo(hdc, 51 + x, 28 + y);

    MoveToEx(hdc, 72 + x, 30 + y, NULL);
    LineTo(hdc, 54 + x, 30 + y);
    LineTo(hdc, 54 + x, 32 + y);
    LineTo(hdc, 72 + x, 32 + y);
    LineTo(hdc, 72 + x, 30 + y);

    MoveToEx(hdc, 51 + x, 40 + y, NULL);
    LineTo(hdc, 24 + x, 40 + y);
    LineTo(hdc, 25 + x, 41 + y);
    LineTo(hdc, 28 + x, 42 + y);
    LineTo(hdc, 30 + x, 43 + y);
    LineTo(hdc, 51 + x, 43 + y);
    LineTo(hdc, 51 + x, 40 + y);

    MoveToEx(hdc, 73 + x, 38 + y, NULL);
    LineTo(hdc, 54 + x, 38 + y);
    LineTo(hdc, 54 + x, 47 + y);
    LineTo(hdc, 73 + x, 50 + y);
    LineTo(hdc, 73 + x, 38 + y);

    MoveToEx(hdc, 125 + x, 40 + y, NULL);
    LineTo(hdc, 76 + x, 40 + y);
    LineTo(hdc, 76 + x, 50 + y);
    LineTo(hdc, 122 + x, 41 + y);
    LineTo(hdc, 125 + x, 40 + y);

    MoveToEx(hdc, 125 + x, 38 + y, NULL);
    LineTo(hdc, 126 + x, 35 + y);
    LineTo(hdc, 76 + x, 35 + y);
    LineTo(hdc, 76 + x, 38 + y);
    LineTo(hdc, 125 + x, 38 + y);

    MoveToEx(hdc, 76 + x, 32 + y, NULL);
    LineTo(hdc, 76 + x, 28 + y);
    LineTo(hdc, 127 + x, 28 + y);
    LineTo(hdc, 126 + x, 32 + y);
    LineTo(hdc, 115 + x, 32 + y);
    LineTo(hdc, 116 + x, 28 + y);

    MoveToEx(hdc, 128 + x, 18 + y, NULL);
    LineTo(hdc, 127 + x, 25 + y);
    LineTo(hdc, 97 + x, 25 + y);
    LineTo(hdc, 97 + x, 18 + y);
    LineTo(hdc, 128 + x, 18 + y);

    MoveToEx(hdc, 95 + x, 23 + y, NULL);
    LineTo(hdc, 75 + x, 23 + y);
    LineTo(hdc, 75 + x, 21 + y);
    LineTo(hdc, 95 + x, 21 + y);
    LineTo(hdc, 95 + x, 23 + y);

    MoveToEx(hdc, 95 + x, 16 + y, NULL);
    LineTo(hdc, 75 + x, 16 + y);
    LineTo(hdc, 75 + x, 8 + y);
    LineTo(hdc, 95 + x, 8 + y);
    LineTo(hdc, 95 + x, 16 + y);

    MoveToEx(hdc, 97 + x, 11 + y, NULL);
    LineTo(hdc, 132 + x, 11 + y);
    LineTo(hdc, 130 + x, 13 + y);
    LineTo(hdc, 97 + x, 13 + y);
    LineTo(hdc, 97 + x, 11 + y);
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
