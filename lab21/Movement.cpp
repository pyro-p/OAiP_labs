#include "lab21.h"

void Left() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (map[i][j] == 1) {
                if (map[i][j - 1] == 0) {
                    map[i][j - 1] = 1;
                    map[i][j] = 0;

                    steps++;
                }
                else if (map[i][j - 1] == 3) {
                    map[i][j - 1] = 1;
                    map[i][j] = 0;

                    steps++;
                    gold++;
                }
            }
        }
    }
}

void Right() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = M - 2; j >= 0; j--) {
            if (map[i][j] == 1) {
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;

                    steps++;
                }
                else if (map[i][j + 1] == 3) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;

                    steps++;
                    gold++;
                }
            }
        }
    }
}

void Up() {
    int i, j;

    for (i = 1; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                if (map[i - 1][j] == 0) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;

                    steps++;
                }
                else if (map[i - 1][j] == 3) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;

                    steps++;
                    gold++;
                }
            }
        }
    }
}

void Down() {
    int i, j;

    for (i = N - 2; i >= 0; i--) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                if (map[i + 1][j] == 0) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;

                    steps++;
                }
                else if (map[i + 1][j] == 3) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;

                    steps++;
                    gold++;
                }
            }
        }
    }
}

void TeleportDown() {
    int i, j, k;

    for (i = N - 2; i >= 0; i--) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                if (map[N - 1][j] == 0) {
                    map[N - 1][j] = 1;
                    map[i][j] = 0;

                    steps++;
                }
                else if (map[N - 1][j] == 3) {
                    map[N - 1][j] = 1;
                    map[i][j] = 0;

                    steps++;
                    gold++;
                }
                else if (map[N - 1][j] == 2) {
                    for (k = N - 1; k > i; k--) {
                        if (map[k][j] == 0) {
                            map[k][j] = 1;
                            map[i][j] = 0;

                            steps++;
                            return;
                        }
                        else if (map[k][j] == 3) {
                            map[k][j] = 1;
                            map[i][j] = 0;

                            steps++;
                            gold++;
                            return;
                        }
                    }
                }
            }
        }
    }
}