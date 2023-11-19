#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item = -1;

	while (item != 0) {
		printf("\n\n");
		printf("Содержимое двумерного массива:\n");
		printArray();
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: i * 10 + j\n");
		printf("2: Заполнить 0\n");
		printf("3: Заполнить случайными числами\n");
		printf("4: Все нечётные увеличить в 10 раз\n");
		printf("5: Все кратные 10 уменьшить в 10 раз\n\n");

		printf("10: Ввести массив с клавиатуры\n");
		printf("11: Сохранить массив в файл\n");
		printf("12: Загрузить массив из файла\n");
		printf("13: Удалить строку\n");
		printf("14: Продублировать столбец\n");
		printf("15: Задание по варианту А8: Обнулить элементы в тех столбцах, в которых встречается хотя бы два одинаковых элемента\n");
		printf("16: Задание по варианту В8: Продублировать те строки, в которых встречается хотя бы два одинаковых элемента\n");

		printf("\n");

		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1: {
			fillIx10plusJ();
		} break;
		case 2: {
			fill0();
		} break;
		case 3: {
			fillRandom();
		} break;
		case 4: {
			evenX10();
		} break;
		case 5: {
			div10();
		} break;
		case 10: {
			keyboardInput();
		} break;
		case 11: {
			fileOutput();
		} break;
		case 12: {
			fileInput();
		} break;
		case 13: {
			int r;
			scanf_s("%d", &r);
			deleteRow(r);
		} break;
		case 14: {
			int c;
			printf("Индекс столбца - ");
			scanf_s("%d", &c);
			duplicateColumn(c);
		} break;
		case 15: {
			same0();
		} break;
		case 16: {
			sameDuplicate();
		} break;
		}
	}
}