﻿#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "SortString.h"

// Максимальная длина слова в массиве
#define MAX_LEN_WORD 80
// Максимальное количество слов
#define MAX_WORDS 20000

// Слова, загруженные из файла 
char words[MAX_WORDS][MAX_LEN_WORD + 1];
// Количество слов в массиве
int n = 0;

// Массив для сортировки 
char a[MAX_WORDS][MAX_LEN_WORD + 1];

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[]);

int LoadWords(char* filename) {
	// открыть файл
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filename);
		return 0;
	}

	char token[MAX_LEN_WORD + 1];
	// пока не конец файла
	while (!feof(fin)) {
		// пока есть разделитель - берем его
		while (getNextDelim(fin, token)) {
		}
		// если есть слово - берем его
		if (getNextWord(fin, token)) {
			if (n < MAX_WORDS) {
				strcpy(words[n], token);
				n++;
			}
			else {
				printf("Words are more than elements in array!!\n", filename);
				fclose(fin);
				return 0;
			}
		}
	}
	// Закрываем файл с текстом
	fclose(fin);
	return 1;
}

// Возвращает 0 - если ch - не буква.
// Возвращает 1 - если ch - буква.
// Корректно работает для латинских букв (с кодами < 128)
// И для русских букв из кодировки ANSI
int isalpha_my(unsigned char ch) {

	if (isalpha(ch))
		return 1;

	// ANSI кодировка!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	return 0;
}

// Возвращает 1 - если  из файла прочитан разделитель.
// В этом случае в token возвращается строка, содержащая 
// этот разделитель.
// Если в файле был не разделитель - возвращает 0.
// В этом случае состояние token неопределено.
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}

// Возвращает 1 - если  из файла прочитано слово.
// В этом случае в token возвращается строка, содержащая 
// это слово. Гарантируется что слово не более MAX_LEN_WORD символов.
// Если в файле не было буквы - возвращает 0.
// В этом случае token содержит пустую строку.
int getNextWord(FILE* fp, char token[])
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < MAX_LEN_WORD)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;
}

void fillArrayStrings() {
	for (int i = 0; i < n; i++) {
		strcpy(a[i], words[i]);
	}
}

int isSortedStrings() {
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(a[i], a[i + 1]) > 0) {
			return 0;
		}
	}
	return 1;
}

void SelectionSortStrings() {
	for (int i = 0; i < n - 1; i++) {

		int iMin = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[j], a[iMin]) < 0) {
				iMin = j;
			}
		}

		if (i != iMin) {
			char tmp[MAX_LEN_WORD + 1];
			strcpy(tmp, a[i]);
			strcpy(a[i], a[iMin]);
			strcpy(a[iMin], tmp);
		}
	}
}

void QuickSortStrings() {
	qsort(a, n, sizeof(a[0]), strcmp);
}

void BubbleSortStrings() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = (n - 1); j > i; j--) {
			// если текущий элемент меньше предыдущего
			if (strcmp(a[j - 1], a[j]) > 0) {
				// меняем их местами
				char tmp[MAX_LEN_WORD + 1];
				strcpy(tmp, a[j - 1]);
				strcpy(a[j - 1], a[j]);
				strcpy(a[j], tmp);
			}
		}
	}
}

void InsertSortStrings() {
	for (int pos = 1; pos < n; pos++) {
		char value[MAX_LEN_WORD + 1];
		strcpy(value, a[pos]);
		int i = pos;
		while ((i > 0) && (strcmp(value, a[i - 1]) < 0)) {
			strcpy(a[i], a[i - 1]);
			i--;
		}
		strcpy(a[i], value);
	}
}

void GnomeSortStrings() {
	int i = 1;
	int j = 2;
	while (i < n)
		if (strcmp(a[i - 1], a[i]) < 0) { //для сортировки по возрастанию поменяйте знак сравнения на <
			i = j;
			j = j + 1;
		}
		else {
			char tmp[MAX_LEN_WORD + 1];
			strcpy(tmp, a[i - 1]);
			strcpy(a[i - 1], a[i]);
			strcpy(a[i], tmp);
			i = i - 1;

			if (i == 0) {
				i = j;
				j = j + 1;
			}
		}
}
