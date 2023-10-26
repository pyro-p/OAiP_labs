#include <stdio.h>
#include <Windows.h>

void task2();
void task3();
void task4();

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = -1;
	while (n != 0) {
		printf("\n");
		printf("\n");
		printf("Выберите нужную операцию:\n");
		printf("2. Таблица Пифагора:\n");
		printf("3. Рисунок:\n");
		printf("4. Отраженный рисунок:\n");
		printf("\n");
		printf("0. Выйти из программы\n");

		scanf_s("%d", &n);
		printf("\n");

		switch (n) {
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		}
	}
}

void task2() {
	int i = 1, j = 1, n = 0, m = 1;

	while (i <= 10) {
		while (j <= 10) {
			n += m;
			printf("%2d ", n);
			j++;
		}
		printf("\n");

		n = 0;
		m++;

		i++;
		j = 1;
	}
}

void task3() {
	int i = 1, j = 1;

	while (i <= 5) {
		while (j <= i) {
			printf("5 ");
			j++;
		}
		printf("\n");

		i++;
		j = 1;
	}
}

void task4() {
	int i = 1, n = -4, j = n;

	while (i <= 5) {
		while (j < 0) {
			printf("  ");
			j++;
		}
		
		j++;

		while (j <= i) {
			printf("%d ", j);
			j++;
		}
		printf("\n");

		i++;
		n++;
		j = n;
	}

	i = 1, n = 2, j = n;
	int k = 1;
	while (i <= 4) {
		while (k < j) {
			printf("  ");
			k++;
		}

		while (j <= 5) {
			printf("%d ", j);
			j++;
		}
		printf("\n");

		k = 1;
		i++;
		n++;
		j = n;
	}
}