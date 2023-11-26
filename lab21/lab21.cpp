// lab21.cpp : Определяет точку входа для приложения.
//

#include "lab21.h"

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
    LoadStringW(hInstance, IDC_LAB21, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB21));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB21));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB21);
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

// 0 - пусто
// 1 - игрок
// 2 - стена
// 3 - золото
int map[N][M] = {
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 2, 2, 2, 2,  0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0,  0, 0, 0, 0, 2,  0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 2,  0, 0, 0, 0, 0},
    {0, 0, 3, 3, 3,  0, 0, 0, 0, 2,  0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0,  0, 0, 0, 0, 2,  0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 2,  0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 0, 0, 2,  0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,  0, 0, 2, 2, 2,  0, 0, 0, 0, 0},
};

int steps = 0;
int gold = 0;

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
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            Left();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            Right();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            Up();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            Down();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x53: // S
            // Save();
            SaveBinary();
            break;
        case 0x57: // W
            // Load();
            LoadBinary();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x51: // Q
            Reset();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4C: // L
            PlaceWallLeft();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x52: // R
            PlaceGoldRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x55: // U
            CollectGoldAbove();
            InvalidateRect(hWnd, NULL, true);
            break;
        case 0x44: // D
            TeleportDown();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x5A: // Z
            BreakRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x41: // A
            BreakAdjacentWalls();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4F: // O
            BreakTwoWalls();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

            drawMap(hdc);

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

void drawMap(HDC hdc) {
    // Кисть для пустой ячейки
    HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(230, 230, 230));
    // Кисть для игрока
    HBRUSH hBrushPlayer = CreateSolidBrush(RGB(20, 20, 240));
    // Кисть для стены
    HBRUSH hBrushWall = CreateSolidBrush(RGB(20, 20, 20));
    // Кисть для золота
    HBRUSH hBrushGold = CreateSolidBrush(RGB(250, 250, 20));

    HBRUSH brush[4] = { hBrushEmptyCell, hBrushPlayer, hBrushWall, hBrushGold };

    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int x1 = j * WIDTH;
            int x2 = (j + 1) * WIDTH;
            int y1 = i * HEIGHT;
            int y2 = (i + 1) * HEIGHT;

            RECT r = { x1, y1, x2, y2 };
            FillRect(hdc, &r, brush[map[i][j]]);
        }
    }

    for (i = 0; i < 4; i++) {
        DeleteObject(brush[i]);
    }
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
