#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

void Load();
void task2();
void task3();
void task4();
void task5();
int findMax();
void sortAsc();
void sortDesc();
void swap();

int *pa;
int n;

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int task;
    printf("Номер задачи - ");
    scanf_s("%d", &task);

    switch (task) {
    case 2: task2(); break;
    case 3: task3(); break;
    case 4: task4(); break;
    case 5: task5(); break;
    }

    free(pa);
}

void Load(char file[]) {
    FILE* fin = fopen(file, "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }

    fscanf(fin, "%d", &n);
    pa = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &pa[i]);
    }
    fclose(fin);
}

void task2() {
    Load("D:\\Temp\\in19-2.txt");

    float avg = 0;
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pa[i];
    }

    avg = sum / n;

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (pa[i] > avg) {
            m++;
        }
    }

    FILE* fout = fopen("D:\\Temp\\out19-2.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    fprintf(fout, "%d\n", m);
    for (int i = 0; i < n; i++) {
        if (pa[i] > avg) {
            fprintf(fout, "%d ", pa[i]);
        }
    }
    fclose(fout);
}

void task3() {
    Load("D:\\Temp\\in19-3.txt");

    float avg = 0;
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pa[i];
    }

    avg = sum / n;

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (pa[i] > avg) {
            m++;
        }
    }

    FILE* fout = fopen("D:\\Temp\\out19-3.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    fprintf(fout, "Среднее арифметическое - %f\n", avg);
    fprintf(fout, "%d\n", m);
    for (int i = 0; i < n; i++) {
        if (pa[i] < avg && pa[i] > 0) {
            fprintf(fout, "%d ", pa[i]);
        }
    }
    fclose(fout);
}

void task4() {
    Load("D:\\Temp\\in19-4.txt");

    int max = findMax();

    int m = 0;
    double high = max * (2.0 / 3.0);

    for (int i = 0; i < n; i++) {
        if (pa[i] > high) {
            m++;
        }
    }

    FILE* fout = fopen("D:\\Temp\\out19-4.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    fprintf(fout, "%d\n", m);
    for (int i = 0; i < n; i++) {
        if (pa[i] > high) {
            fprintf(fout, "%d ", pa[i]);
        }
    }
    fclose(fout);
}

void task5() {
    Load("D:\\Temp\\in19-5.txt");

    FILE* fout = fopen("D:\\Temp\\out19-5.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    sortAsc();

    fprintf(fout, "%d\n", n);
    for (int i = 0; i < n; i++) {
        if (pa[i] % 2 == 0) {
            fprintf(fout, "%d ", pa[i]);
        }
    }

    sortDesc();

    for (int i = 0; i < n; i++) {
        if (pa[i] % 2 == 1) {
            fprintf(fout, "%d ", pa[i]);
        }
    }
    fclose(fout);
}

int findMax() {
    int max = pa[0];
    for (int i = 1; i < n; i++) {
        if (pa[i] > max) {
            max = pa[i];
        }
    }
    return max;
}

void sortAsc() {
    int min_index;
    for (int i = 0; i < n; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (pa[j] < pa[min_index]) {
                min_index = j;
            }
        }
        swap(&pa[min_index], &pa[i]);
    }
}

void sortDesc() {
    int max_index;
    for (int i = 0; i < n; i++) {
        max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (pa[j] > pa[max_index]) {
                max_index = j;
            }
        }
        swap(&pa[max_index], &pa[i]);
    }
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}