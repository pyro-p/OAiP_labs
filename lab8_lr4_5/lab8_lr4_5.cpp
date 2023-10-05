// lab8_lr4_5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab8_lr4_5.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
void drawHouse(HDC hdc);
void drawRightTree(HDC hdc);
void drawLeftTree(HDC hdc);
void drawBrige(HDC hdc);
void drawTrashBin(HDC hdc);
void drawCar(HDC hdc);
void drawSnowman(HDC hdc);
void drawSchoolBus(HDC hdc);
void drawMario(HDC hdc);

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
    LoadStringW(hInstance, IDC_LAB8LR45, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB8LR45));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB8LR45));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB8LR45);
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

            /************       TASK 1      ************/

            drawHouse(hdc);
            drawRightTree(hdc);
            drawLeftTree(hdc);
            drawBrige(hdc);
            drawTrashBin(hdc);

            /************       TASK 2      ************/

            drawCar(hdc);
            drawSnowman(hdc);
            drawSchoolBus(hdc);
            drawMario(hdc);

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

void drawHouse(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 6, RGB(100, 255, 180));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 225, 400);
    LineTo(hdc, 275, 400);
    LineTo(hdc, 275, 425);
    LineTo(hdc, 325, 425);
    LineTo(hdc, 275, 425);
    LineTo(hdc, 275, 475);
}

void drawRightTree(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 4, RGB(68, 175, 105));
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
}

void drawLeftTree(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 4, RGB(160, 82, 45));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 85, 415, NULL);
    LineTo(hdc, 75, 433);
    LineTo(hdc, 66, 422);
    LineTo(hdc, 75, 433);
    LineTo(hdc, 72, 452);
    LineTo(hdc, 42, 439);
    LineTo(hdc, 52, 443);
    LineTo(hdc, 52, 426);
    MoveToEx(hdc, 72, 452, NULL);
    LineTo(hdc, 74, 466);
    LineTo(hdc, 98, 459);
    LineTo(hdc, 98, 446);
    MoveToEx(hdc, 85, 461, NULL);
    LineTo(hdc, 88, 440);
    LineTo(hdc, 83, 430);
    MoveToEx(hdc, 74, 461, NULL);
    LineTo(hdc, 64, 496);
    LineTo(hdc, 53, 490);
    LineTo(hdc, 52, 466);
    LineTo(hdc, 53, 490);
    LineTo(hdc, 30, 474);
    LineTo(hdc, 26, 457);
    LineTo(hdc, 35, 446);
    MoveToEx(hdc, 30, 474, NULL);
    LineTo(hdc, 16, 483);
    MoveToEx(hdc, 64, 496, NULL);
    LineTo(hdc, 70, 516);
    LineTo(hdc, 85, 503);
    LineTo(hdc, 105, 480);
    MoveToEx(hdc, 85, 503, NULL);
    LineTo(hdc, 88, 480);
    MoveToEx(hdc, 70, 516, NULL);
    LineTo(hdc, 72, 544);
}

void drawBrige(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 18, RGB(112, 128, 144));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 75, 132, NULL);
    LineTo(hdc, 70, 60);
    MoveToEx(hdc, 118, 120, NULL);
    LineTo(hdc, 113, 51);
    MoveToEx(hdc, 155, 120, NULL);
    LineTo(hdc, 152, 52);
    MoveToEx(hdc, 183, 130, NULL);
    LineTo(hdc, 192, 60);
    MoveToEx(hdc, 208, 131, NULL);
    LineTo(hdc, 225, 73);

    hPen = CreatePen(PS_SOLID, 26, RGB(188, 143, 143));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 50, 62, NULL);
    LineTo(hdc, 106, 49);
    LineTo(hdc, 147, 44);
    LineTo(hdc, 197, 53);
    LineTo(hdc, 243, 76);
    MoveToEx(hdc, 50, 140, NULL);
    LineTo(hdc, 106, 127);
    LineTo(hdc, 147, 126);
    LineTo(hdc, 197, 136);
    LineTo(hdc, 243, 152);
}

void drawTrashBin(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(77, 80, 85));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 355, 192, NULL);
    LineTo(hdc, 429, 206);
    LineTo(hdc, 421, 219);
    LineTo(hdc, 353, 206);
    LineTo(hdc, 355, 192);

    MoveToEx(hdc, 356, 220, NULL);
    LineTo(hdc, 420, 220);
    LineTo(hdc, 414, 283);
    LineTo(hdc, 362, 283);
    LineTo(hdc, 356, 220);

    MoveToEx(hdc, 375, 235, NULL);
    LineTo(hdc, 375, 270);
    MoveToEx(hdc, 390, 235, NULL);
    LineTo(hdc, 390, 270);
    MoveToEx(hdc, 402, 235, NULL);
    LineTo(hdc, 402, 270);
}

void drawCar(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(252, 76, 2));
    SelectObject(hdc, hPen);

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 164, 0));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 650, 200, 900, 250);

    MoveToEx(hdc, 700, 200, NULL);
    LineTo(hdc, 750, 150);
    LineTo(hdc, 850, 150);
    LineTo(hdc, 900, 200);

    hPen = CreatePen(PS_SOLID, 5, RGB(28, 20, 228));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_CROSS, RGB(128, 0, 128));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 675, 225, 725, 275);

    hPen = CreatePen(PS_SOLID, 5, RGB(28, 200, 28));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 216, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 825, 225, 875, 275);
}

void drawSnowman(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);

    /* Base */
    RoundRect(hdc, 690, 440, 830, 545, 105, 100);
    RoundRect(hdc, 705, 385, 810, 470, 94, 91);
    RoundRect(hdc, 723, 337, 802, 408, 74, 65);

    /* Hands */
    Arc(hdc, 725, 402, 830, 466, 826, 462, 818, 392);
    Chord(hdc, 685, 400, 782, 480, 712, 404, 698, 476);

    hPen = CreatePen(PS_NULL, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 692, 430, 738, 472);

    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Arc(hdc, 692, 430, 738, 474, 698, 480, 698, 420);

    /* Face */
    hPen = CreatePen(PS_SOLID, 2, RGB(160, 105, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(160, 105, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 779, 355, 787, 363);
    Ellipse(hdc, 746, 361, 754, 369);

    hPen = CreatePen(PS_SOLID, 2, RGB(243, 98, 35));
    SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(243, 98, 35));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 766, 363, 786, 383);

    hPen = CreatePen(PS_SOLID, 10, RGB(243, 98, 35));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 778, 367, NULL);
    LineTo(hdc, 823, 366);
    LineTo(hdc, 776, 379);

    /* Bucket */
    hPen = CreatePen(PS_SOLID, 3, RGB(80, 80, 180));
    SelectObject(hdc, hPen);
    Arc(hdc, 737, 306, 818, 388, 795, 307, 738, 330);
    Arc(hdc, 770, 308, 802, 342, 802, 350, 802, 295);
    Arc(hdc, 757, 317, 796, 384, 802, 356, 792, 320);

    hPen = CreatePen(PS_SOLID, 9, RGB(80, 80, 180));
    SelectObject(hdc, hPen);
    Arc(hdc, 573, 325, 805, 420, 825, 358, 750, 315);
}

void drawSchoolBus(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 216, 0));
    SelectObject(hdc, hBrush);

    RoundRect(hdc, 1247, 113, 1302, 180, 12, 12);
    RoundRect(hdc, 960, 50, 1257, 180, 40, 40);
    Rectangle(hdc, 960, 77, 1257, 180);
    Rectangle(hdc, 1184, 84, 1230, 180);

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1000, 155, 1050, 205);
    Ellipse(hdc, 1230, 155, 1280, 205);

    hBrush = CreateSolidBrush(RGB(239, 239, 239));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1010, 165, 1040, 195);
    Ellipse(hdc, 1240, 165, 1270, 195);

    hBrush = CreateSolidBrush(RGB(215, 248, 255));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 977, 90, 1037, 140);
    Rectangle(hdc, 1047, 90, 1107, 140);
    Rectangle(hdc, 1117, 90, 1177, 140);
    Rectangle(hdc, 1190, 90, 1223, 140);
    Rectangle(hdc, 1237, 85, 1257, 113);
}

void drawMario(HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 210, 169));
    SelectObject(hdc, hBrush);

    /* Ears */
    Ellipse(hdc, 972, 480, 1066, 590);
    Ellipse(hdc, 996, 528, 1030, 560);

    Ellipse(hdc, 1220, 480, 1314, 590);
    Ellipse(hdc, 1260, 528, 1294, 560);

    /* Head */
    Ellipse(hdc, 1010, 380, 1280, 670);

    /* Eyes */
    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1164, 465, 1220, 540);
    Ellipse(hdc, 1066, 465, 1122, 540);

    hBrush = CreateSolidBrush(RGB(3, 160, 216));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1163, 470, 1205, 535);
    Ellipse(hdc, 1084, 470, 1122, 535);

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1166, 482, 1194, 524);
    Ellipse(hdc, 1090, 482, 1122, 524);

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1101, 488, 1111, 498);
    Ellipse(hdc, 1175, 488, 1185, 498);

    HPEN hPen = CreatePen(PS_SOLID, 20, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Arc(hdc, 1050, 430, 1127, 525, 1130, 401, 1044, 403);
    Arc(hdc, 1163, 429, 1240, 524, 1242, 402, 1157, 404);

    /* Mustache */
    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1059, 549, 1115, 605);
    Ellipse(hdc, 1097, 561, 1153, 617);
    Ellipse(hdc, 1134, 561, 1190, 617);
    Ellipse(hdc, 1171, 549, 1227, 605);

    hPen = CreatePen(PS_SOLID, 40, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Arc(hdc, 960, 193, 1330, 578, 1010, 655, 1280, 655);

    /* Nose */
    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(255, 210, 169));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1089, 505, 1199, 595);

    /* Mouth */
    Arc(hdc, 1062, 535, 1225, 635, 1111, 656, 1184, 660);
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Arc(hdc, 1062, 522, 1225, 622, 1074, 630, 1214, 630);

    /* Cap */
    hPen = CreatePen(PS_NULL, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(198, 46, 45));
    SelectObject(hdc, hBrush);
    Chord(hdc, 992, 293, 1292, 621, 1210, 280, 972, 512);
    Chord(hdc, 992, 293, 1292, 621, 1310, 410, 965, 410);
    Chord(hdc, 992, 293, 1292, 621, 1319, 505, 1081, 280);

    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Arc(hdc, 992, 293, 1292, 621, 1309, 502, 965, 514);

    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 1091, 313, 1197, 395);


    hBrush = CreateSolidBrush(RGB(254, 57, 56));
    SelectObject(hdc, hBrush);
    POINT poly[10];

    MoveToEx(hdc, 1100, 367, NULL);
    poly[0] = { 1124, 323 };
    poly[1] = { 1144, 339 };
    poly[2] = { 1163, 323 };
    poly[3] = { 1188, 367 };
    poly[4] = { 1174, 378 };
    poly[5] = { 1160, 343 };
    poly[6] = { 1144, 358 };
    poly[7] = { 1128, 343 };
    poly[8] = { 1115, 377 };
    poly[9] = { 1100, 367 };

    Polygon(hdc, poly, 10);

    hPen = CreatePen(PS_SOLID, 40, RGB(160, 30, 37));
    SelectObject(hdc, hPen);
    Arc(hdc, 966, 405, 1324, 751, 1318, 368, 967, 368);
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
