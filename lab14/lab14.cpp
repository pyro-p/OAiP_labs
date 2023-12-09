// lab14.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab14.h"
#include "Images.h" 
#include "Pictures.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int image1_x = 30;
int image1_y = 30;
int image1_n = 1; // column
int image1_m = 1; // row
unsigned char image1_r = 0;
unsigned char image1_g = 0;
unsigned char image1_b = 0;

int images_count = 7;
int type = 0;

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
	LoadStringW(hInstance, IDC_LAB14, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB14));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB14));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB14);
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
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			image1_x -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			image1_x += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_UP:
			image1_y -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN:
			image1_y += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_SPACE:
			type++;
			if (type > images_count - 1) type = 0;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_SHIFT:
			type--;
			if (type < 0) type = images_count - 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x49: // key I
			image1_n += 1; // Increasing columns
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x4f: // key O
			if (image1_n > 1) image1_n -= 1; // Increasing columns
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x55: // key U
			image1_m += 1; // Decreasing rows
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x4e: // key N
			if (image1_m > 1) image1_m -= 1; // Decreasing rows
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x52: // key R
			image1_r += 50;
			if (image1_r > 255) image1_r = 0;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x47: // key G
			image1_g += 50;
			if (image1_g > 255) image1_g = 0;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x42: // key B
			image1_b += 50;
			if (image1_b > 255) image1_b = 0;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;
	case WM_LBUTTONDOWN:
	{
		WORD xPos, yPos;

		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		image1_x = xPos;
		image1_y = yPos;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Добавьте сюда любой код прорисовки, использующий HDC...

		switch (type) {
		case 0:
			Picture1(hdc, image1_x, image1_y, image1_n, image1_m, image1_r, image1_g, image1_b, Image0);
			break;
		case 1:
			Picture1(hdc, image1_x, image1_y, image1_n, image1_m, image1_r, image1_g, image1_b, Image1);
			break;
		case 2:
			Picture1(hdc, image1_x, image1_y, image1_n, image1_m, image1_r, image1_g, image1_b, Image2);
			break;
		case 3:
			Image8_4_5(hdc);
			break;
		case 4:
			Image8_7(hdc);
			break;
		case 5:
			Image9(hdc);
			break;
		case 6:
			Image9_2(hdc);
			break;
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
