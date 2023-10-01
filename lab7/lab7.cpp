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

            // Первый куст
            {
                int x1 = 400, y1 = 150;
                int x2 = 500, y2 = 250;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 2;
                } while (x1 <= 600);
            }

            // Второй куст
            {
                int x1 = 0, y1 = 250;
                int x2 = 100, y2 = 250;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 2;
                    y1 -= 4;
                } while (x1 <= 100);

                x1 = 100;
                y1 = 50;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 2;
                    y1 += 4;
                } while (x1 <= 200);
            }

            // Забор
            {
                int x1 = 150, y1 = 0;
                int x2 = 150, y2 = 100;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 5;
                    x2 += 5;
                } while (x1 <= 450);
            }

            // Забор
            {
                HPEN hPen;

                int x1 = 50, y1 = 300;
                int x2 = 50, y2 = 380;
                int r = 164;
                do {
                    hPen = CreatePen(PS_SOLID, 8, RGB(r, 116, 73));
                    SelectObject(hdc, hPen);
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 19;
                    x2 += 20;
                    r -= 3;
                } while (x1 <= 350);

                hPen = CreatePen(PS_SOLID, 4, RGB(164, 116, 73));
                SelectObject(hdc, hPen);
                x1 = 40, y1 = 315;
                x2 = 360, y2 = 315;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    y1 += 20;
                    y2 += 20;
                } while (y1 <= 380);
            }

            // Рисунки
            {
                HPEN hPen;
                hPen = CreatePen(PS_SOLID, 1, RGB(117, 208, 154));
                SelectObject(hdc, hPen);

                // n1
                int x1 = 100, y1 = 400;
                int x2 = 100, y2 = 550;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 -= 12;
                    y1 += 10;

                    x2 += 12;
                    y2 -= 10;
                } while (y1 <= 520);

                // n2
                x1 = 300, y1 = 400;
                x2 = 300, y2 = 550;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    y1 += 10;
                    x2 += 10;
                } while (y1 <= 550);
                
                // n3
                x1 = 500, y1 = 400;
                x2 = 500, y2 = 550;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 -= 8;
                    y1 += 7;
                    y2 -= 6;
                } while (x1 >= 380);

                // n4
                x1 = 10, y1 = 650;
                x2 = 200, y2 = 550;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 11;
                    y2 += 7;
                } while (y2 <= 640);
                
                // n5
                x1 = 300, y1 = 560;
                x2 = 300, y2 = 680;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 7;
                    x2 -= 7;
                } while (x1 <= 410);

                // n6
                x1 = 420, y1 = 570;
                x2 = 420, y2 = 690;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 8;
                    y2 -= 6;
                } while (x1 <= 520);

                // n7
                x1 = 550, y1 = 400;
                x2 = 550, y2 = 490;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 7;
                    y1 -= 1;
                    x2 += 7;
                    y2 += 1;
                } while (x1 <= 640);

                // n8
                x1 = 650, y1 = 420;
                x2 = 650, y2 = 480;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 8;
                    y1 += 6;
                    x2 += 8;
                    y2 -= 6;
                } while (x1 <= 690);

                x1 = 690, y1 = 450;
                x2 = 690, y2 = 450;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 8;
                    y1 -= 6;
                    x2 += 8;
                    y2 += 6;
                } while (x1 <= 750);

                // n9
                x1 = 760, y1 = 380;
                x2 = 860, y2 = 520;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    x1 += 7;
                    y1 += 7;
                    y2 -= 8;
                } while (x1 <= 880);

                // n10
                x1 = 550, y1 = 570;
                x2 = 700, y2 = 570;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);

                    y1 -= 4;
                    y2 += 9;
                } while (y2 <= 650);
            }

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
