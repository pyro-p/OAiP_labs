#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 

	printf("Ивлеев Данила\n");
	printf("ЛР23 Задача 1\n");

	int item = -1;

	while (item != 0) {
		printf("\n\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Текстовый файл text1.txt преобразовать в текстовый файл out1.txt заменив все табуляции символом ‘%’.\n");
		printf("2: Текстовый файл text2.txt преобразовать в текстовый файл out2.txt сделав все буквы БОЛЬШИМИ.\n");
		printf("3: Вывести в конце каждой строки символ #, если в строке встретилась хотя бы одна буква.\n");
		printf("4: Разобрать текст на слова и разделители.\n");
		printf("5: Сгенерировать HTML файл с тем же текстом.\n");
		printf("6: В конце каждой строки добавить число K – сколько в строке раз встретился символ ТОЧКА С ЗАПЯТОЙ.\n");
		printf("7: Все символы за исключением латинских букв,  заменить символом ‘_’ (подчеркивание).\n");
		printf("8: Текстовый файл превратить в HTML файл, выделив жирным те слова, которые есть в словаре.\n");
		printf("\n");

		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1: {
			FILE* fin = inputFile("src/text1.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out1.txt");

			task1(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		case 2: {
			FILE* fin = inputFile("src/text2.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out2.txt");

			task2(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		case 3: {
			FILE* fin = inputFile("src/text3.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out3.txt");

			task3(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		case 4: {
			FILE* fin = inputFile("src/text4.txt");
			if (!fin) break;

			task4(fin);

			fclose(fin);
		} break;
		case 5: {
			FILE* fin = inputFile("src/text5.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out5.html");

			task5(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		case 6: {
			FILE* fin = inputFile("src/text6.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out6.txt");

			task6(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		case 7: {
			FILE* fin = inputFile("src/text7.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out7.txt");

			task7(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		case 8: {
			FILE* fin = inputFile("src/text8.txt");
			if (!fin) break;
			FILE* fout = outputFile("src/out8.html");

			task8(fin, fout);

			fclose(fin);
			fclose(fout);
		} break;
		}
	}
}