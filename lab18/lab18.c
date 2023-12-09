#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

#define NUM_ELEMENTS 10

void task2();
void task4(); 
void task5();
void task6();

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int task;
    printf("Номер задачи - ");
    scanf_s("%d", &task);

    switch (task) {
    case 2: task2(); break;
    case 4: task4(); break;
    case 5: task5(); break;
    case 6: task6(); break;
    }
}

void task2() {
    int a, b, c, p;

    FILE* fin = fopen("D:\\Temp\\in1.txt", "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }
    fscanf(fin, "%d%d%d", &a, &b, &c);
    fclose(fin);

    printf("A - %d\nB - %d\nC - %d\n", a, b, c);

    p = a * b * c;

    printf("Вывод - %d\n", p);

    FILE* fout = fopen("D:\\Temp\\out1.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }
    fprintf(fout, "%d", p);
    fclose(fout);
}

void task4() {
    int a, b, c, d, f, p;

    FILE* fin = fopen("D:\\Temp\\in2.txt", "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }
    fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &f);
    fclose(fin);

    printf("A - %d\nB - %d\nC - %d\nD - %d\nF - %d\n", a, b, c, d, f);

    p = a + b + c + d + f;

    printf("Вывод - %d\n", p);

    FILE* fout = fopen("D:\\Temp\\out2.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }
    fprintf(fout, "%d", p);
    fclose(fout);
}

void task5() {
    int a[NUM_ELEMENTS];
    int n;
    double avg = 0;

    FILE* fin = fopen("D:\\Temp\\in3.txt", "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }
    fscanf(fin, "%d\n", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &a[i]);
    }
    fclose(fin);

    printf("N - %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("A[%d] - %d\n", i, a[i]);
        avg += a[i];
    }

    avg /= (double)n;

    printf("Ср. арифметическое - %f\n\n", avg);

    for (int i = 0; i < n; i++) {
        if (a[i] > avg) {
            a[i] *= 10;
        }
    }
    
    printf("--------------\n\nN - %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("A[%d] - %d\n", i, a[i]);
        avg += a[i];
    }


    FILE* fout = fopen("D:\\Temp\\out3.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    fprintf(fout, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d ", a[i]);
    }

    fclose(fout);
}

void task6() {
    int a[NUM_ELEMENTS];
    int n;
    double avg = 0;

    FILE* fin = fopen("D:\\Temp\\in4.txt", "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }
    fscanf(fin, "%d\n", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &a[i]);
    }
    fclose(fin);

    printf("N - %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("A[%d] - %d\n", i, a[i]);
        avg += a[i];
    }

    avg /= (double)n;

    printf("Ср. арифметическое - %f\n\n", avg);

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (a[i] < n) {
                a[i] /= 2;
            }
        }
    }
    
    printf("--------------\n\nN - %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("A[%d] - %d\n", i, a[i]);
        avg += a[i];
    }


    FILE* fout = fopen("D:\\Temp\\out4.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    fprintf(fout, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d ", a[i]);
    }

    fclose(fout);
}