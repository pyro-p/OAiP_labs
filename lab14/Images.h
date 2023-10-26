#pragma once

#include <Windows.h>

void Image0(HDC hdc, int cx, int cy, COLORREF color);
void Image1(HDC hdc, int cx, int cy, COLORREF color);
void Image2(HDC hdc, int cx, int cy, COLORREF color);
void Picture1(HDC hdc, int x, int y, int ej, int ei, unsigned char r, unsigned char g, unsigned char b, void (*pfImage)(HDC hdc, int cx, int cy, COLORREF color));