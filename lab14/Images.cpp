#include "Images.h"

void Image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen); 

    POINT p[7] = {
        cx,         cy - 10,
        cx + 20,    cy - 20,
        cx - 20,    cy - 20,
        cx - 20,    cy + 20,
        cx - 20,    cy,
        cx + 20,    cy,
        cx,         cy - 10
    };

    Polyline(hdc, p, 7);
    DeleteObject(hPen);
}
void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[13] = {
        cx,         cy ,
        cx + 10,    cy - 10,
        cx + 10,    cy,
        cx,         cy + 10,
        cx - 10,    cy + 10,
        cx - 10,    cy,
        cx + 10,    cy - 20,
        cx + 20,    cy - 20,
        cx + 20,    cy,
        cx,         cy + 20,
        cx - 20,    cy + 20,
        cx - 20,    cy,
        cx,         cy - 20
    };

    Polyline(hdc, p, 13);
    DeleteObject(hPen);
}
void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    HBRUSH hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(128, 128, 178));
    SelectObject(hdc, hBrush);

    POINT p[8] = {
        cx,         cy - 20,
        cx + 10,    cy,
        cx + 20,    cy - 20,
        cx + 15,    cy + 20,
        cx - 15,    cy + 20,
        cx - 20,    cy - 20,
        cx - 10,    cy,
        cx,         cy - 20,
    };

    Polygon(hdc, p, 8);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void Picture1(HDC hdc, int x, int y, int ej, int ei, unsigned char r, unsigned char g, unsigned char b, void (*pfImage)(HDC hdc, int cx, int cy, COLORREF color)) {
    int cx, i, j;
    cx = x;
    i = 0;

    while (i < ei) {
        x = cx;
        j = 0;

        while (j < ej) {
            pfImage(hdc, x, y, RGB(r, g, b));
            x += 45;
            j++;
        }
        y += 45;
        i++;
    }
}