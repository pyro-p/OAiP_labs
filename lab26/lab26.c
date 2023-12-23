#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item = -1;

	while (item != 0) {
		printf("\n-------------------------------\n");
		printf("Список: ");
		printList();

		printf("Выберите нужную вам операцию:\n");
		printf("1: Создать заготовленный список\n");
		printf("2: Добавить элемент\n");
		printf("3: Удалить первый элемент\n");
		printf("4: Проверить наличие значения в списке\n");
		printf("5: Очистить список\n");
		printf("12: Подсчитать сумму всех элементов\n");
		printf("13: Подсчитать количество четных элементов\n");
		printf("14: Все нечетные увеличить в 10 раз\n");
		printf("15: i-ый элемент увеличить в 100 раз\n");
		printf("16: Все элементы левее i-го увеличить в 10 раз\n");
		printf("17: Все элементы правее i-го увеличить в 10 раз\n");
		printf("18: Удалить i-ый элемент\n");
		printf("19: Вывести односвязанный список в обратную сторону\n");
		printf("20: Проверить есть ли в списке повторяющиеся элементы\n");
		printf("21: Поменять местами два соседних элемента\n");
		printf("22: Поменять местами элементы с индексами i и j\n");
		printf("23: Отсортировать список по возрастанию\n");
		printf("\n");

		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1: {
			preset();
			break;
		}
		case 2: {
			int v;
			printf("Значение элемента: ");
			scanf("%d", &v);

			addToHead(v);
			break; 
		}
		case 3: {
			deleteFromHead();
			break; 
		}
		case 4: {
			int v;
			printf("Искомой значение: ");
			scanf("%d", &v);
			if (contains(v)) {
				printf("Есть");
			}
			else printf("Нет");
			break;
		}
		case 5: {
			clearList();
			break;
		}
		case 12: {
			printf("Сумма всех элементов: %d", sum());
			break;
		}
		case 13: {
			printf("Кол-во чётных: %d", countEven());
			break;
		}
		case 14: {
			oddsX10();
			break;
		}
		case 15: {
			int index;
			printf("Индекс: ");
			scanf("%d", &index);

			elIx100(index);
			break;
		}
		case 16: {
			int index;
			printf("Индекс: ");
			scanf("%d", &index);

			elLeftIx10(index);
			break;
		}
		case 17: {
			int index;
			printf("Индекс: ");
			scanf("%d", &index);

			elRightIx10(index);
			break;
		}
		case 18: {
			int index;
			printf("Индекс: ");
			scanf("%d", &index);

			deleteElI(index);
			break;
		}
		case 19: {
			task9();
			break;
		}
		case 20: {
			switch (checkDuplicate()) {
			case 0: 
				printf("Нет");
				break;
			case 1:
				printf("Есть");
				break;
			}
			break;
		}
		case 21: {
			swapAdjacent(3);
			break;
		}
		case 22: {
			int i, j;

			printf("Элемент i: ");
			scanf("%d", &i);
			printf("Элемент j: ");
			scanf("%d", &j);

			swap(i, j);
			break;
		}
		case 23: {
			bubbleSort();
			break;
		}
		}
	}
}