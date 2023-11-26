#include "lab21.h"

void PlaceWallLeft() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (map[i][j] == 1) {
                if (map[i][j - 1] == 0) {
                    map[i][j - 1] = 2;
                }
            }
        }
    }
}

void PlaceGoldRight() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = M - 2; j >= 0; j--) {
            if (map[i][j] == 1) {
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 3;
                }
            }
        }
    }
}

void BreakRight() {
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = M - 2; j >= 0; j--) {
            if (map[i][j] == 1) {
                for (k = j + 1; k < M; k++) {
                    if (map[i][k] == 2) {
                        map[i][k] = 0;
                    }
                }
            }
        }
    }
}

void CollectGoldAbove() {
    int i, j;

    for (i = 1; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                if (map[i - 1][j] == 3) {
                    map[i - 1][j] = 0;

                    gold++;
                }
            }
        }
    }
}

void BreakAdjacentWalls() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                if (i > 0 && map[i - 1][j] == 2) map[i - 1][j] = 0;
                if (i < N - 1 && map[i + 1][j] == 2) map[i + 1][j] = 0;
                if (j > 0 && map[i][j - 1] == 2) map[i][j - 1] = 0;
                if (j < M - 1 && map[i][j + 1] == 2) map[i][j + 1] = 0;
            }
        }
    }
}

void BreakTwoWalls() {
    int i, j, i1, j1;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                for (i1 = i - 2; i1 <= i + 2; i1++) {
                    for (j1 = j - 2; j1 <= j + 2; j1++) {
                        if (map[i1][j1] == 2) map[i1][j1] = 0;
                    }
                }
            }
        }
    }
}