#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item = -1; 

	while (item != 0) {
		printf("\n\n");
		printf("Выберите нужную вам операцию:\n");
		printf("2: Вывести на экран 20 символов с кодами от CH до CH+19\n");
		printf("3: Вывести на экран 30 символов с кодами от CH до CH-29\n");
		printf("4: Подсчитать, сколько в строке пробелов\n");
		printf("5: Все пробелы в строке заменить символом ‘#’\n");
		printf("6: Все цифры в строке заменить символом ‘$’\n");
		printf("7: Все маленькие латинские буквы превратить в большие\n");
		printf("9: Собственная версия функции int strlen(char *)\n");
		printf("10: Собственная версия функции int strcmp(char *, char *)\n");
		printf("11: Собственная версия функции void strcpy(char *, char *)\n");
		printf("12: Собственная версия функции void strcat(char *, char *)\n");
		printf("80: Все символы за исключением латинских букв,  заменить символом ‘_’ (подчеркивание).\n");
		printf("\n");

		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 2: {
			getchar();
			next20Chars();
		} break;
		case 3: {
			getchar();
			previous30Chars();
		} break;
		case 4: {
			getchar();
			spaceCount();
		} break;
		case 5: {
			getchar();
			spaceSwitchHash();
		} break;
		case 6: {
			getchar();
			digitSwitchDollar();
		} break;
		case 7: {
			getchar();
			changeToUpper();
		} break;
		case 9: {
			getchar();
			//char str1[100];
			//printf("Введите строку str - ");
			//fgets(str1, 99, stdin);

			char str1[] = "int strlen";
			char str2[] = "123456789 987654321";

			int len1 = personalStrlen(str1);
			int len2 = personalStrlen(str2);
			printf("Длина str1 (%s) - %d\nДлина str2 (%s) - %d\n", str1, len1, str2, len2);
		} break;
		case 10: {
			getchar();
			//char str1[100];
			//char str2[100];
			//printf("Введите строку str1 - ");
			//fgets(str1, 99, stdin);
			//printf("Введите строку str2 - ");
			//fgets(str2, 99, stdin);

			char str1[] = "123";
			char str2[] = "124";
			char str3[] = "123";
			char str4[] = "123";

			int comp1 = personalStrcmp(str1, str2);
			switch (comp1) {
			case -1: printf("str1 < str2\n");
				break;
			case 0: printf("str1 == str2\n");
				break;
			case 1: printf("str1 > str2\n");
				break;
			}

			int comp2 = personalStrcmp(str3, str4);
			switch (comp2) {
			case -1: printf("str3 < str4\n");
				break;
			case 0: printf("str3 == str4\n");
				break;
			case 1: printf("str3 > str4\n");
				break;
			}
		} break;
		case 11: {
			getchar();
			//char str1[100];
			//char str2[100];
			//printf("Введите строку str1 - ");
			//fgets(str1, 99, stdin);
			//printf("Введите строку str2 - ");
			//fgets(str2, 99, stdin);

			char str1[10] = "123";
			char str2[10] = "1234";


			personalStrcpy(str1, str2);
			printf("%s", str1);

			printf("\n");

			char str3[30] = "Привет";
			char str4[30] = "Пока";

			personalStrcpy(str3, str4);
			printf("%s", str3);
		} break;
		case 12: {
			getchar();
			//char str1[100];
			//char str2[100];
			//printf("Введите строку str1 - ");
			//fgets(str1, 99, stdin);
			//printf("Введите строку str2 - ");
			//fgets(str2, 99, stdin);

			char str1[100] = "123";
			char str2[100] = "1234";

			personalStrcat(str1, str2);
			printf("%s", str1);

			printf("\n");

			char str3[100] = "Привет";
			char str4[100] = "Пока";

			strcat(str3, str4);
			printf("%s", str3);
		} break;
		case 80: {
			getchar();
			notDigitToUnderscore();
		} break;
		}
	}
}