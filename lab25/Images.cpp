#include "lab25.h"

void Nabla(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 210, 190));

	SelectObject(hdc, hPen);
	MoveToEx(hdc, cx - size, cy - size, NULL);
	LineTo(hdc, cx + size, cy - size);
	LineTo(hdc, cx, cy + size);
	LineTo(hdc, cx - size, cy - size);

	DeleteObject(hPen);
}

void RecursiveNabla1(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla1(hdc, cx - size, cy - size, size / 2);
	RecursiveNabla1(hdc, cx + size, cy - size, size / 2);
}

void RecursiveNabla2(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla2(hdc, cx - size, cy - size, size / 2);
	RecursiveNabla2(hdc, cx, cy + size, size / 2);
}

void RecursiveNabla3(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla3(hdc, cx - size, cy - size, size / 2);
	RecursiveNabla3(hdc, cx, cy + size, size / 2);
	RecursiveNabla3(hdc, cx + size, cy - size, size / 2);
}

void RecursiveNabla4(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla4(hdc, cx, cy - size, size / 2);
}

void RecursiveNabla5(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla5(hdc, cx + size, cy, size / 2);
}

void RecursiveNabla6(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla6(hdc, cx - size, cy, size / 2);
}

void RecursiveNabla7(HDC hdc, int cx, int cy, int size) {
	Nabla(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveNabla7(hdc, cx, cy - size, size / 2);
	RecursiveNabla7(hdc, cx - size, cy, size / 2);
	RecursiveNabla7(hdc, cx + size, cy, size / 2);
}



void Hourglass(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(210, 180, 0));

	SelectObject(hdc, hPen);
	MoveToEx(hdc, cx - (size / 1.5), cy - size, NULL);
	LineTo(hdc, cx + (size / 1.5), cy - size);
	LineTo(hdc, cx - size, cy + size);
	LineTo(hdc, cx + size, cy + size);
	LineTo(hdc, cx - (size / 1.5), cy - size);

	DeleteObject(hPen);
}

void RecursiveHourglass1(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 5) {
		return;
	}
	RecursiveHourglass1(hdc, cx - size, cy - size, size / 2);
}

void RecursiveHourglass2(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 5) {
		return;
	}
	RecursiveHourglass2(hdc, cx - size, cy - size, size / 2);
	RecursiveHourglass2(hdc, cx + size, cy - size, size / 2);
}

void RecursiveHourglass3(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 5) {
		return;
	}
	RecursiveHourglass3(hdc, cx - size, cy + size, size / 2);
	RecursiveHourglass3(hdc, cx + size, cy + size, size / 2);
}

void RecursiveHourglass4(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveHourglass4(hdc, cx - (size / 1.5), cy - size, size / 2);
	RecursiveHourglass4(hdc, cx + (size / 1.5), cy - size, size / 2);
	RecursiveHourglass4(hdc, cx - size, cy + size, size / 2);
	RecursiveHourglass4(hdc, cx + size, cy + size, size / 2);
}

void RecursiveHourglass5(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveHourglass5(hdc, cx - size, cy, size / 2);
}

void RecursiveHourglass6(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveHourglass6(hdc, cx + size, cy, size / 2);
}

void RecursiveHourglass7(HDC hdc, int cx, int cy, int size) {
	Hourglass(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveHourglass7(hdc, cx + size, cy, size / 2);
	RecursiveHourglass7(hdc, cx - size, cy, size / 2);
}



void Rhombus(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 200));

	SelectObject(hdc, hPen);
	MoveToEx(hdc, cx, cy - size, NULL);
	LineTo(hdc, cx + size, cy);
	LineTo(hdc, cx, cy + size);
	LineTo(hdc, cx - size, cy);
	LineTo(hdc, cx, cy - size);

	DeleteObject(hPen);
}

void RecursiveRhombus1(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus1(hdc, cx + size, cy, size / 2);
	RecursiveRhombus1(hdc, cx - size, cy, size / 2);
}

void RecursiveRhombus2(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus2(hdc, cx + size, cy, size / 2);
	RecursiveRhombus2(hdc, cx - size, cy, size / 2);
	RecursiveRhombus2(hdc, cx, cy + size, size / 2);
}

void RecursiveRhombus3(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus3(hdc, cx + size, cy, size / 2);
	RecursiveRhombus3(hdc, cx - size, cy, size / 2);
	RecursiveRhombus3(hdc, cx, cy - size, size / 2);
}

void RecursiveRhombus4(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus4(hdc, cx + size, cy, size / 2);
	RecursiveRhombus4(hdc, cx - size, cy, size / 2);
	RecursiveRhombus4(hdc, cx, cy + size, size / 2);
	RecursiveRhombus4(hdc, cx, cy - size, size / 2);
}

void RecursiveRhombus5(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus5(hdc, cx - size, cy + size, size / 2);
	RecursiveRhombus5(hdc, cx + size, cy - size, size / 2);
}

void RecursiveRhombus6(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 5) {
		return;
	}
	RecursiveRhombus6(hdc, cx + size, cy, size / 2);
	RecursiveRhombus6(hdc, cx + size, cy + size, size / 2);
	RecursiveRhombus6(hdc, cx - size, cy + size, size / 2);
}

void RecursiveRhombus7(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus7(hdc, cx - size, cy - size, size / 2);
	RecursiveRhombus7(hdc, cx + size, cy + size, size / 2);
}

void RecursiveRhombus8(HDC hdc, int cx, int cy, int size) {
	Rhombus(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveRhombus8(hdc, cx - size, cy - size, size / 2);
	RecursiveRhombus8(hdc, cx + size, cy - size, size / 2);
	RecursiveRhombus8(hdc, cx + (size / 2), cy + (size / 2), size / 2);
}



void Star(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(210, 210, 255));

	SelectObject(hdc, hPen);
	MoveToEx(hdc, cx - size, cy, NULL);
	LineTo(hdc, cx - (size / 4), cy - (size / 4));
	LineTo(hdc, cx, cy - size);
	LineTo(hdc, cx + (size / 4), cy - (size / 4));
	LineTo(hdc, cx + size, cy);
	LineTo(hdc, cx + (size / 4), cy + (size / 4));
	LineTo(hdc, cx, cy + size);
	LineTo(hdc, cx - (size / 4), cy + (size / 4));
	LineTo(hdc, cx - size, cy);

	DeleteObject(hPen);
}

void RecursiveStar1(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveStar1(hdc, cx - size, cy, size / 2);
	RecursiveStar1(hdc, cx + size, cy, size / 2);
}

void RecursiveStar2(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveStar2(hdc, cx, cy - size, size / 2);
	RecursiveStar2(hdc, cx, cy + size, size / 2);
}

void RecursiveStar3(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveStar3(hdc, cx, cy - size, size / 2);
	RecursiveStar3(hdc, cx, cy + size, size / 2);
	RecursiveStar3(hdc, cx - size, cy, size / 2);
}

void RecursiveStar4(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveStar4(hdc, cx - (size / 1.5), cy, size / 2);
	RecursiveStar4(hdc, cx + (size / 1.5), cy, size / 2);
	RecursiveStar4(hdc, cx, cy - size, size / 2);
	RecursiveStar4(hdc, cx, cy + size, size / 2);
}

void RecursiveStar5(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveStar5(hdc, cx - (size / 2), cy, size / 2);
	RecursiveStar5(hdc, cx, cy + (size / 2), size / 2);
	RecursiveStar5(hdc, cx + size, cy - size, size / 2);
}

void RecursiveStar6(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveStar6(hdc, cx + (size / 2), cy, size / 2);
	RecursiveStar6(hdc, cx, cy + (size / 2), size / 2);
	RecursiveStar6(hdc, cx - size, cy - size, size / 2);
}

void RecursiveStar7(HDC hdc, int cx, int cy, int size) {
	Star(hdc, cx, cy, size);
	if (size < 30) {
		return;
	}
	RecursiveStar7(hdc, cx - size, cy, size / 2);
	RecursiveStar7(hdc, cx - (size / 1.5), cy - (size / 1.5), size / 2);
	RecursiveStar7(hdc, cx, cy - size, size / 2);
	RecursiveStar7(hdc, cx + (size / 1.5), cy - (size / 1.5), size / 2);
	RecursiveStar7(hdc, cx + size, cy, size / 2);
	RecursiveStar7(hdc, cx + (size / 1.5), cy + (size / 1.5), size / 2);
	RecursiveStar7(hdc, cx, cy + size, size / 2);
	RecursiveStar7(hdc, cx - (size / 1.5), cy + (size / 1.5), size / 2);
}



void Lightning(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(250, 210, 50));

	int x1 = cx - (size / 2);
	int y1 = cy - (size / 4);

	int x2 = cx + size;
	int y2 = cy - (size / 4);

	int x3 = cx;
	int y3 = cy - (size / 6);

	int x4 = cx + (size / 2);
	int y4 = cy + (size / 4);

	int x5 = cx - size;
	int y5 = cy + (size / 4);

	int x6 = cx;
	int y6 = cy + (size / 6);

	int x7 = cx - (size / 2);
	int y7 = cy - (size / 4);

	SelectObject(hdc, hPen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);
	LineTo(hdc, x6, y6);
	LineTo(hdc, x7, y7);

	DeleteObject(hPen);
}

void RecursiveLightning(HDC hdc, int cx, int cy, int size) {
	Lightning(hdc, cx, cy, size);
	if (size <  80) {
		return;
	}
	RecursiveLightning(hdc, cx - (size / 2), cy - (size / 4), size / 2);
	RecursiveLightning(hdc, cx + size, cy - (size / 4), size / 2);
	RecursiveLightning(hdc, cx - size, cy + (size / 4), size / 2);
	RecursiveLightning(hdc, cx + (size / 2), cy + (size / 4), size / 2);
}



void SmallArrow(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(150, 250, 150));

	SelectObject(hdc, hPen);
	MoveToEx(hdc, cx, cy, NULL);
	LineTo(hdc, cx - size, cy);
	LineTo(hdc, cx + (size / 1.5), cy - (size / 1.5));
	LineTo(hdc, cx, cy + size);
	LineTo(hdc, cx, cy);

	DeleteObject(hPen);
}

void RecursiveSmallArrow(HDC hdc, int cx, int cy, int size) {
	SmallArrow(hdc, cx, cy, size);
	if (size <  20) {
		return;
	}
	RecursiveSmallArrow(hdc, cx - (size / 4), cy + (size / 4), size / 2);
	RecursiveSmallArrow(hdc, cx + (size / 1.5), cy - (size / 1.5), size / 2);
}



void BigArrow(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(250, 50, 50));

	SelectObject(hdc, hPen);
	MoveToEx(hdc, cx, cy, NULL);
	LineTo(hdc, cx - (size / 2), cy - size);
	LineTo(hdc, cx + (size / 2), cy - size);
	LineTo(hdc, cx + size, cy);
	LineTo(hdc, cx + (size / 2), cy + size);
	LineTo(hdc, cx - (size / 2), cy + size);
	LineTo(hdc, cx, cy);

	DeleteObject(hPen);
}

void RecursiveBigArrow(HDC hdc, int cx, int cy, int size) {
	BigArrow(hdc, cx, cy, size);
	if (size <  20) {
		return;
	}
	RecursiveBigArrow(hdc, cx - (size / 2), cy, size / 2);
	RecursiveBigArrow(hdc, cx + size, cy, size / 2);
}



void Tribar(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(50, 200, 180));

	int x1 = cx - (size / 2.6);
	int y1 = cy + (size / 2);

	int x2 = cx + (size / 10);
	int y2 = cy - (size / 2);

	int x3 = cx + (size / 1.2);
	int y3 = cy + size;

	int x4 = cx - (size / 1.2);
	int y4 = cy + size;

	int x5 = cx - size;
	int y5 = cy + (size / 1.2);

	SelectObject(hdc, hPen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);

	x1 = cx + (size / 3);
	y1 = cy + (size / 2);

	x2 = cx - (size / 1.6);
	y2 = cy + (size / 2);

	x3 = cx + (size / 10);
	y3 = cy - size;

	x4 = cx + size;
	y4 = cy + (size / 1.2);

	x5 = cx + (size / 1.2);
	y5 = cy + size;

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);

	x1 = cx;
	y1 = cy - (size / 4);

	x2 = cx + (size / 2);
	y2 = cy + (size / 1.2);

	x3 = cx - size;
	y3 = cy + (size / 1.2);

	x4 = cx - (size / 10);
	y4 = cy - size;

	x5 = cx + (size / 10);
	y5 = cy - size;

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);

	DeleteObject(hPen);
}

void RecursiveTribar(HDC hdc, int cx, int cy, int size) {
	Tribar(hdc, cx, cy, (size / 1.8));
	if (size < 60) {
		return;
	}
	RecursiveTribar(hdc, cx + size, cy + size, size / 2);
	RecursiveTribar(hdc, cx - size, cy + size, size / 2);
	RecursiveTribar(hdc, cx, cy - size, size / 2);
}



void Figure(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(165, 115, 75));

	int x1 = cx - size;
	int y1 = cy;

	int x2 = cx - (size / 1.2);
	int y2 = cy - (size / 4);

	int x3 = cx - (size / 8);
	int y3 = cy - (size / 4);

	int x4 = cx + (size / 2.2);
	int y4 = cy - size;

	int x5 = cx + (size / 1.2);
	int y5 = cy - size;

	int x6 = cx + size;
	int y6 = cy - (size / 1.5);

	int x7 = cx + (size / 2);
	int y7 = cy;

	int x8 = cx + size;
	int y8 = cy + (size / 1.5);

	int x9 = cx + (size / 1.2);
	int y9 = cy + size;

	int x10 = cx + (size / 2.2);
	int y10 = cy + size;

	int x11 = cx - (size / 8);
	int y11 = cy + (size / 4);

	int x12 = cx - (size / 1.2);
	int y12 = cy + (size / 4);
	
	int x13 = cx - size;
	int y13 = cy;

	SelectObject(hdc, hPen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);
	LineTo(hdc, x6, y6);
	LineTo(hdc, x7, y7);
	LineTo(hdc, x8, y8);
	LineTo(hdc, x9, y9);
	LineTo(hdc, x10, y10);
	LineTo(hdc, x11, y11);
	LineTo(hdc, x12, y12);
	LineTo(hdc, x13, y13);

	MoveToEx(hdc, cx + (size / 8), cy, NULL);
	LineTo(hdc, cx - (size / 8), cy + (size / 4));
	MoveToEx(hdc, cx + (size / 8), cy, NULL);
	LineTo(hdc, cx - (size / 8), cy - (size / 4));
	MoveToEx(hdc, cx + (size / 8), cy, NULL);
	LineTo(hdc, cx + (size / 2), cy);

	DeleteObject(hPen);
}

void RecursiveFigure(HDC hdc, int cx, int cy, int size) {
	Figure(hdc, cx, cy, size);
	if (size < 60) {
		return;
	}
	RecursiveFigure(hdc, cx + size, cy + size, size / 2);
	RecursiveFigure(hdc, cx - size, cy + size, size / 2);
	RecursiveFigure(hdc, cx - (size * 2), cy, size / 2);
}