#include "stdio.h"
#include "Windows.h"

void sum_increase();
void print1000_0();
void factorial();
void fibonacci();
void prime_factor();

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = -1;
	while (n != 0) {
		printf("\n");
		printf("\n");
		printf("Выберите нужную операцию:\n");
		printf("13. Рост суммы на счёте:\n");
		printf("20. Числа от 1000 до 0:\n");
		printf("21. N факториалов:\n");
		printf("22. N фибоначчи:\n");
		printf("23. Разложение на простые множители:\n");
		printf("\n");
		printf("0. Выйти из программы\n");
		
		scanf_s("%d", &n);
		printf("\n");

		switch (n) {
		case 13:
			sum_increase();
			break;
		case 20:
			print1000_0();
			break;
		case 21:
			factorial();
			break;
		case 22:
			fibonacci();
			break;
		case 23:
			prime_factor();
			break;
		}
	}
}

void sum_increase() {
	int s, n;
	int i = 0;

	printf("s = ");
	scanf_s("%d", &s);
	printf("n = ");
	scanf_s("%d", &n);

	while (i <= 10) {
		printf("Через %d лет: %d\n", i, s);
		s += s * n / 100;
		i++;
	}
}

void print1000_0() {
	int n = 1000;

	while (n >= 0) {
		printf("%d ", n);
		n -= 8;
	}
}

void factorial() {
	int n, i = 1, j = 1;
	double num = 1;
	
	printf("n = ");
	scanf_s("%d", &n);

	while (n >= 1) {
		while (i <= j) {
			printf("%d | %.0lf\n", i - 1, num);
			num *= i;
			i++;
		}

		j++;
		n--;
	}
}

void fibonacci() {
	int n;
	int i = 1;
	int num = 0;
	int num2 = 1;
	int num3 = 0;

	printf("Кол-во чисел: ");
	scanf_s("%d", &n);

	if (num3 <= 0) {
		printf("%d ", num3);
		num3 = 1;
	}

	while (i <= n - 1) {
		printf("%d ", num3);
		num3 = num + num2;
		num = num2;
		num2 = num3;
		i += 1;
	}
}

void prime_factor() {
	int n, i = 2;

	printf("n = ");
	scanf_s("%d", &n);

	while (i <= n) {
		if (n % i == 0) {
			printf("%d ", i);
			n /= i;
		}
		else {
			i++;
		}
	}
}