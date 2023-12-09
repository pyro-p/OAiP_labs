#include "Pictures.h"

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

void Image8_4_5(HDC hdc) {
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
}

void drawFirstBush(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    int x1 = 400, y1 = 150;
    int x2 = 500, y2 = 250;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);

        x1 += 2;
    } while (x1 <= 600);
}
void drawSecondBush(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

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
void drawFence(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(252, 76, 2));

    int x1 = 150, y1 = 0;
    int x2 = 150, y2 = 100;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);

        x1 += 5;
        x2 += 5;
    } while (x1 <= 450);
}
void drawFenceRGB(HDC hdc) {
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
void drawDrawings(HDC hdc) {
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

void Image8_7(HDC hdc) {
    // Первый куст
    drawFirstBush(hdc);
    // Второй куст
    drawSecondBush(hdc);
    // Забор
    drawFence(hdc);
    // Забор
    drawFenceRGB(hdc);
    // Рисунки
    drawDrawings(hdc);
}

void drawSnowWoman1(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 17 + x, 25 + y, NULL);
    LineTo(hdc, 0 + x, 40 + y);
    MoveToEx(hdc, 43 + x, 25 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);

    MoveToEx(hdc, 70 + x, 0 + y, NULL);
    LineTo(hdc, 40 + x, 120 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 65 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);
}
void drawSnowWoman2(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 17 + x, 25 + y, NULL);
    LineTo(hdc, 0 + x, 40 + y);
    MoveToEx(hdc, 43 + x, 25 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);

    MoveToEx(hdc, 70 + x, 0 + y, NULL);
    LineTo(hdc, 40 + x, 120 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 65 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);
}
void drawSnowWoman3(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 17 + x, 25 + y, NULL);
    LineTo(hdc, 0 + x, 40 + y);
    MoveToEx(hdc, 43 + x, 25 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);

    MoveToEx(hdc, 70 + x, 0 + y, NULL);
    LineTo(hdc, 40 + x, 120 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 65 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);
}
void drawSnowWoman4(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 17 + x, 25 + y, NULL);
    LineTo(hdc, 0 + x, 40 + y);
    MoveToEx(hdc, 43 + x, 25 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);

    MoveToEx(hdc, 70 + x, 0 + y, NULL);
    LineTo(hdc, 40 + x, 120 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 65 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);
}

void Image9(HDC hdc) {
    int n = 0;

    drawSnowWoman1(hdc, 0, 0);
    drawSnowWoman1(hdc, 150, 150);
    drawSnowWoman1(hdc, 0, 300);
    drawSnowWoman1(hdc, 300, 0);
    drawSnowWoman1(hdc, 300, 300);

    do {
        drawSnowWoman2(hdc, 0 + n, 450);
        n += 100;
    } while (n <= 500);
    n = 0;

    do {
        drawSnowWoman3(hdc, 610, 0 + n);
        n += 130;
    } while (n <= 500);
    n = 0;

    do {
        drawSnowWoman4(hdc, 750 + n, 0 + n);
        n += 100;
    } while (n <= 300);
    n = 0;
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

void Image9_2(HDC hdc) {
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
}