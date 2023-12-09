#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

void next20Chars() {
	printf("Введите ch - ");
	int ch = getchar(); 

	for (int i = ch; i < ch + 19; i++) {
		printf("'%c' [%d]\n", i, i);
	}
}

void previous30Chars() {
	printf("Введите ch - ");
	int ch = getchar();

	for (int i = ch; i > ch - 29; i--) {
		printf("'%c' [%d]\n", i, i);
	}
}

void spaceCount() {
	char s[100];
	printf("Введите строку s - ");
	fgets(s, 99, stdin);
	printf("\nСтрока s: %s", s);

	int n = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') n++;
	}
	printf("Кол-во пробелов - %d", n);
}

void spaceSwitchHash() {
	char s[100];
	printf("Введите строку s - ");
	fgets(s, 99, stdin);
	printf("\nСтрока s: %s", s);

	int n = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') s[i] = '#';
	}
	printf("\nСтрока s с #: %s", s);
}

void digitSwitchDollar() {
	char s[100];
	printf("Введите строку s - ");
	fgets(s, 99, stdin);
	printf("\nСтрока s: %s", s);
	
	for (int i = 0; i < strlen(s); i++) {
		if (personalIsDigit(s[i])) s[i] = '$';
	}
	printf("\nСтрока s с $: %s", s);
}

int personalIsDigit(char ch) {
	if (ch >= '0' && ch <= '9') {
		return 1;
	}
	return 0;
}

void changeToUpper() {
	char s[100];
	printf("Введите строку s - ");
	fgets(s, 99, stdin);
	printf("\nСтрока s: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		s[i] = personalToUpper(s[i]);
	}
	printf("\nСтрока s с большыми буквами: %s", s);
}

int personalToUpper(char ch) {
	int out = ch;
	if (ch >= 'a' && ch <= 'z') out = 'A' + (ch - 'a');
	if (ch >= 224 && ch <= 255) out = 'А' + (ch - 'а');
	if (ch == 'ё') out = 'Ё';
	return out;
}

int personalStrlen(char str[]) {
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '\n') {
			cnt++;
		}
		else return cnt;
	}
	return cnt;
}

int personalStrcmp(char str1[], char str2[]) {
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] > str2[i]) return 1;
		if (str1[i] < str2[i]) return -1;
	}
	return 0;
}

void personalStrcpy(char dest[], char src[]) {
	int cnt = 0;
	for (int i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
		cnt++;
	}
	dest[cnt] = '\0';
}

void personalStrcat(char dest[], char src[]) {
	int cnt = 0;
	int dest_len = personalStrlen(dest);
	int src_len = personalStrlen(src);
	for (int i = dest_len, j = 0; i < (dest_len + src_len); i++, j++) {
		dest[i] = src[j];
	}
	dest[(dest_len + src_len)] = '\0';
}

void notDigitToUnderscore() {
	unsigned char s[100];
	printf("Введите строку s - ");
	fgets(s, 99, stdin);
	printf("\nСтрока s: %s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (!isalpha(s[i])) {
			s[i] = '_';
		}
	}
	printf("\nСтрока s с _: %s", s);
}