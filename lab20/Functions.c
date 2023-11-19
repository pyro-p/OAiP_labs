#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS][NUM_ELEMENTS];
int n = 3;
int m = 4;

void printArray() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

void fillIx10plusJ() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}

void fill0() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

void fillRandom() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = (rand() % 8);
		}
	}
}

void evenX10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 1) {
				arr[i][j] *= 10;
			}
		}
	}
}

void div10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}

void keyboardInput() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d:%d - ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
		printf("\n");
	}
}

void fileInput() {
	char file[0x100];

	printf("Путь к файлу - ");
	fscanf(stdin, " "); // Чтение строки с консоли

	if (fgets(file, 0x100, stdin)) { // Удаление последнего элемента \n
		char len = strlen(file) - 1;

		if (file[len] == '\n')
			file[len] = '\0';
	}

	FILE* fin = fopen(file, "rt");
	if (fin == NULL) {
		printf("Файл не найден");
		return;
	}

	fscanf(fin, "%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
		fscanf(fin, "\n");
	}
	fclose(fin);
}

void fileOutput() {
	char file[0x100];

	printf("Путь к файлу - ");
	fscanf(stdin, " "); // Чтение строки с консоли

	if (fgets(file, 0x100, stdin)) { // Удаление последнего элемента \n
		char len = strlen(file) - 1;

		if (file[len] == '\n')
			file[len] = '\0';
	}

	FILE* fout = fopen(file, "wt");
	if (fout == NULL) {
		printf("Файл не создан");
		return;
	}

	fprintf(fout, "%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);

}

void deleteRow(int row_index) {
	row_index -= 1;
	for (int i = row_index; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
		printf("\n");
	}
	n--;
}

void duplicateColumn(int column_index) {
	for (int i = 0; i < n; i++) {
		for (int j = m; j > column_index; j--) {
			arr[i][j] = arr[i][j - 1];
		}
		printf("\n");
	}
	m++;
}

void same0() {
	int cnt = 0;
	int tmp[NUM_ELEMENTS];
	for (int i = 0; i < n; i++) { // Массив элементов подходящих под условие
		for (int j = 0; j < m; j++) {
			for (int k = i + 1; k < n; k++) {
				if (arr[i][j] == arr[k][j]) {
					tmp[cnt] = j;
					cnt++;
				}
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		fillColumn0(tmp[i]);
	}
}

void fillColumn0(int column_index) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == column_index) arr[i][j] = 0;
		}
	}
}

void sameDuplicate() {
	int cnt = 0;
	int tmp[30];
	for (int i = 0; i < n; i++) { // Массив элементов подходящих под условие
		for (int j = 0; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				if (arr[i][j] == arr[i][k]) {
					tmp[cnt] = i;
					cnt++;
				}
			}
		}
	}

	// Удаление дубликатов в массиве индексов
	int c = cnt - 1;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (tmp[i] == tmp[j]) {
				for (int k = j; k < c; k++) {
					tmp[k] = tmp[k + 1];
				}
				cnt--;
			}
		}
	}

	for (int i = cnt - 1; i >= 0; i--) {
		duplicateRow(tmp[i]);
	}
}

void duplicateRow(int row_index) {
	for (int i = n; i > row_index; i--) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
	n++;
}