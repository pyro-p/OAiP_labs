#include "Functions.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item = -1;

	while (item != 0) {
		printf("\n\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Рекурсивное вычисления факториала.\n");
		printf("2: Уменьшение на 2 на спуске и на подъёме.\n");
		printf("4: Задача из ЕГЭ 1.\n");
		printf("5: Задача из ЕГЭ 2.\n");
		printf("6: Задача из ЕГЭ 3.\n");
		printf("7: Задача из ЕГЭ 4.\n");
		printf("\n");

		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1: {
			task1();
		} break;
		case 2: {
			task2();
		} break;
		case 4: {
			task4(3);
		} break;
		case 5: {
			task5(10);
		} break;
		case 6: {
			task6(1);
		} break;
		case 7: {
			task7(11);
		} break;
		}
	}
}