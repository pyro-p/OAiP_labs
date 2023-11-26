#define _CRT_SECURE_NO_WARNINGS

#include "lab21.h"

void Save() {
    FILE* fout;
    fout = fopen("save1.txt", "wt");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    fprintf(fout, "%d ", N);
    fprintf(fout, "%d\n", M);

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fprintf(fout, "%d ", map[i][j]);
        }
        fprintf(fout, "\n");
    }

    fprintf(fout, "%d ", steps);
    fprintf(fout, "%d", gold);

    fclose(fout);
}

void Load() {
    FILE* fin;
    fin = fopen("save1.txt", "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }

    int n, m;
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fscanf(fin, "%d", &map[i][j]);
        }
    }

    fprintf(fin, "%d", &steps);
    fprintf(fin, "%d", &gold);

    fclose(fin);
}

void SaveBinary() {
    FILE* fout;
    fout = fopen("game_bin.bin", "wb");
    if (fout == NULL) {
        printf("Файл не создан");
        return;
    }

    int n = N;
    int m = M;

    fwrite(&n, sizeof(n), 1, fout);
    fwrite(&m, sizeof(m), 1, fout);
    fwrite(map, sizeof(map), 1, fout);
    fwrite(&steps, sizeof(steps), 1, fout);
    fwrite(&gold, sizeof(gold), 1, fout);

    fclose(fout);
}

void LoadBinary() {
    FILE* fin;
    fin = fopen("game_bin.bin", "rb");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }

    int n, m;

    fread(&n, sizeof(n), 1, fin);
    fread(&m, sizeof(m), 1, fin);
    fread(map, sizeof(map), 1, fin);
    fread(&steps, sizeof(steps), 1, fin);
    fread(&gold, sizeof(gold), 1, fin);

    fclose(fin);
}

void Reset() {
    FILE* fin;
    fin = fopen("start.txt", "rt");
    if (fin == NULL) {
        printf("Файл не найден");
        return;
    }

    int n, m;
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fscanf(fin, "%d", &map[i][j]);
        }
    }

    fprintf(fin, "%d", &steps);
    fprintf(fin, "%d", &gold);

    fclose(fin);
}