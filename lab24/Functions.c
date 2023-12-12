#include "Functions.h"

void task1() {
	int n = 4;
	long f = fact(n);

	printf("%d! = %ld", n, f);
}

void task2() {
	int n = 11;
	f1(n);
	printf("\n");
	f2(n);
	printf("\n");
	f3(n);
}

void task4(int n) {
	if (n >= 1) {
		printf(" %d", n);
		task4(n - 1);
		task4(n - 1);
	}
}

void task5(int n) {
	if (n > 2) {
		printf("%d\n", n);
		task5(n - 3);
		task5(n - 4);
	}
}

void task6(int n) {
	printf("%d\n", n);
	if (n < 5) {
		task6(n + 1);
		task6(n + 3);
	}
}

void task7(int n) {
	if (n > 0) G3(n - 1);
}

long fact(int n) {
	if (n == 0) return 1;

	long res = fact(n - 1) * n;
	return res;
}

int f1(int n) {
	printf("%2d ", n);
	if (n > 1) f1(n - 2);
}

int f2(int n) {
	if (n > 1) f2(n - 2);
	printf("%2d ", n);
}

int f3(int n) {
	printf("%2d ", n);
	if (n > 1) f3(n - 2);
	printf("%2d ", n);
}

void G3(int n) {
	printf("*");
	if (n > 1) task7(n - 3);
}