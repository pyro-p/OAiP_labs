// lab15.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab15.h"
#include "Images.h" 

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
	LoadStringW(hInstance, IDC_LAB15, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB15));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB15);
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

struct Image {
	int x;
	int y;
	int vx;
	int vy;
};


struct Image im1 = { 670, 300, 10, 0 };

typedef struct Image IMAGE;

IMAGE im2 = { 800, 100, 0, 10 };
IMAGE im3 = { 100, 50, 0, 0 };

#define NUM_IM_A 9

IMAGE imA[NUM_IM_A] = {
	{700, 300, 10, 0},
	{700, 300, 9, 4},
	{700, 300, 7, 7},
	{700, 300, 4, 9},
	{700, 300, 0, 10},
	{700, 300, -4, 9},
	{700, 300, -7, 7},
	{700, 300, -9, 4},
	{700, 300, -10, 0}
};

//int fillArr(int** M, int m, int n) {
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int b[4] = { 700, 300, 0, 0 };
//
//	while (i < m) {
//		while (j < n) {
//			M[i][j] = b[k++];
//			j++;
//		}
//		i++;
//		j = 0;
//		k = 0;
//	}
//
//	return 0;
//}
//
//int createArr() {
//	int n = 4;
//	int m = 100;
//	int i = 0;
//
//	int **A;
//	A = new int* [m];
//	while (i < m) {
//		A[i] = new int[n];
//		i++;
//	}
//
//	fillArr(A, m, n);
//
//	return 0;
//}

#define NUM_IM_R 100

IMAGE imR[NUM_IM_R] = {
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 },
	{ 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }, { 700, 300, 0, 0 }
};

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
	case WM_CREATE:
	{
		SetTimer(hWnd, 1, 1, 0);
	}
	break;
	case WM_TIMER:
	{
		/*im1.x += im1.vx;
		im1.y += im1.vy;

		im2.x += im2.vx;
		im2.y += im2.vy;

		int dx3 = rand() % 10;
		int dy3 = rand() % 21 - 10;

		im3.x += dx3;
		im3.y += dy3;

		int i = 0;
		while (i < NUM_IM_A) {
			imA[i].x += imA[i].vx;
			imA[i].y += imA[i].vy;
			i++;
		}*/

		RECT rect;
		GetClientRect(hWnd, &rect);

		int i = 0;
		while (i < NUM_IM_R) {
			if (imR[i].x > rect.right) imR[i].x -= 10;
			if (imR[i].x < rect.left) imR[i].x += 10;
			if (imR[i].y > rect.bottom) imR[i].y -= 10;
			if (imR[i].y < rect.top) imR[i].y += 10;

			imR[i].x += rand() % 51 - 25;
			imR[i].y += rand() % 51 - 25;

			i++;
		}

		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
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

		//// ****************		tasks 1-6	 ****************
		//Image0(hdc, im1.x, im1.y, RGB(100, 100, 100));
		//Image1(hdc, im2.x, im2.y, RGB(100, 100, 100));
		//Image2(hdc, im3.x, im3.y, RGB(100, 100, 100));

		//int i = 0;
		//while (i < NUM_IM_A) {
		//	Image2(hdc, imA[i].x, imA[i].y, RGB(100, 100, 100));
		//	i++;
		//}
		//// *************************************************

		int i = 0;
		while (i < NUM_IM_R) {
			Image1(hdc, imR[i].x, imR[i].y, RGB(rand() % 255, rand() % 255, rand() % 255));
			i++;
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
