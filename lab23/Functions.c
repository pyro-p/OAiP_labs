#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

#define MAX_LEN 80
char s[MAX_LEN];

FILE* inputFile(char file[]) {
	// Входной файл
	FILE* fin = fopen(file, "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return 0;
	}
	return fin;
}

FILE* outputFile(char file[]) {
	// Выходной файл
	FILE* fout;
	fout = fopen(file, "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	return fout;
}

int personalIsalpha(unsigned char ch) {
	if (ch >= 'A' && ch <= 'Z') return 1;
	if (ch >= 'a' && ch <= 'z') return 1;
	if (ch >= 'А' && ch <= 'Я') return 1;
	if (ch >= 'а' && ch <= 'я') return 1;
	if (ch >= 192 && ch <= 255) return 1;
	if (ch == 'Ё') return 1;
	if (ch == 'ё') return 1;
	return 0;
}

void task1(FILE* fin, FILE* fout) {
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t') {
					s[i] = '%';
				}
			}
			fprintf(fout, "%s", s);
		}
	}
}

void task2(FILE* fin, FILE* fout) {
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				int out = s[i];
				if (s[i] >= 'a' && s[i] <= 'z') out = 'A' + (s[i] - 'a');
				if (s[i] >= 'а' && s[i] <= 'я') out = 'А' + (s[i] - 'а');
				if (s[i] >= 224 && s[i] <= 255) out = 'А' + (s[i] - 'а');
				if (s[i] == 'ё') out = 'Ё';
				s[i] = out;
			}
			fprintf(fout, "%s", s);
		}
	}
}

void task3(FILE* fin, FILE* fout) {
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int have_alpha = 0;
			int b = 0;

			for (int i = 0; s[i] != '\0'; i++) {
				// Поиск буквы в строке
				if (personalIsalpha(s[i])) have_alpha = 1;

				if (s[i + 1] == '\0' && have_alpha == 1) {
					b = i;
				}
			}
			if (have_alpha) {
				s[b] = '#';
				s[b + 1] = '\n';
				s[b + 2] = '\0';
			}
			fprintf(fout, "%s", s);
		}
	}
}

void task4(FILE* fin) {
	char token[MAX_LEN];

	while (!feof(fin)) {
		while (getNextDelim(fin, token)) {
			printf("<DELIM>%s</DELIM>\n", token);
		}
		if (getNextWord(fin, token, MAX_LEN)) {
			printf("<WORD>%s</WORD>\n", token);
		}
	}
}

void task5(FILE* fin, FILE* fout) {
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html lang = \"en\">");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta charset = \"UTF-8\">");
	fprintf(fout, "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">");
	fprintf(fout, "<title>Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	int ch;
	while ((ch = getc(fin)) != EOF) {
		fprintf(fout, "%c", ch);
		if (ch == '\n') {
			fprintf(fout, "<br>");
		}
	}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");
}

void task6(FILE* fin, FILE* fout) {
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int k = 0;
			int i = 0;

			while (s[i] != '\0') {
				if (s[i] == ';') k += 1;
				i++;
			}
			if (k > 0) {
				s[i - 1] = (k + 48);
				s[i] = '\n';
				s[i + 1] = '\0';
			}

			fprintf(fout, "%s", s);
		}
	}
}

void task7(FILE* fin, FILE* fout) {
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int i = 0;
			
			while (s[i] != '\0') {
				if (!(s[i] >= 'A' && s[i] <= 'Z')
					&& !(s[i] >= 'a' && s[i] <= 'z')
					&& s[i] != '\n')
				{
					s[i] = '_';
				}
				i++;
			}

			fprintf(fout, "%s", s);
		}
	}
}

void task8(FILE* fin, FILE* fout, FILE* fdict) {
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html lang = \"en\">");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta charset = \"UTF-8\">");
	fprintf(fout, "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">");
	fprintf(fout, "<title>Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	char token[MAX_LEN];
	char dict[MAX_LEN]; 

	while (!feof(fin)) {
		while (getNextDelim(fin, token)) {
			fprintf(fout, "%s", token);
			if (token[0] == '\n') {
				fprintf(fout, "<br>");
			}
		}

		if (getNextWord(fin, token, MAX_LEN)) {
			int switcher = 0;
			FILE* fdict = inputFile("src/dictionary.txt");
			
			// Перебор слов в словаре
			while (!feof(fdict) && switcher == 0) {

				while (getNextDelim(fdict, dict)) {}

				if (getNextWord(fdict, dict, MAX_LEN)) {

					// Сравнение слова из исходного текста со словом в словаре
					if (strcmp(token, dict) == 0) {
						fprintf(fout, "<b>%s</b>", token);
						switcher++;
						break;
					}
				}
			}
			if (switcher == 0) {
				fprintf(fout, "%s", token);
			}
		}
	}

	//int ch;
	//while ((ch = getc(fin)) != EOF) {
	//	fprintf(fout, "%c", ch);
	//	if (ch == '\n') {
	//		fprintf(fout, "<br>");
	//	}
	//}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");
}

int getNextDelim(FILE* fp, char token[]) {
	int ch = getc(fp);
	if (ch == EOF) return 0;
	if (personalIsalpha((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen) {
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!personalIsalpha((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';

	if (i == 0) return 0;
	return 1;
}