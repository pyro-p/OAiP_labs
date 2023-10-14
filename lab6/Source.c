п»ї#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int task;
	printf("Р’РІРµРґРёС‚Рµ РЅРѕРјРµСЂ Р·Р°РґР°С‡Рё: ");
	scanf_s("%d", &task);
	if (task == 4) {
		return task4();
	}
	if (task == 5) {
		return task5();
	}
	if (task == 6) {
		return task6();
	}
	if (task == 7) {
		return task7();
	}
}

int task4() {
	int N;
	int i = 1;
	int num = 0;

	printf("РљРѕР»-РІРѕ С‡РёСЃРµР»: ");
	scanf_s("%d", &N);

	do {
		num += 2;
		i += 1;
		printf("%d ", num);
	} while (i <= N);
}

int task5() {
	int N, A;
	int i = 1;
	int num = 0;

	printf("РљРѕР»-РІРѕ С‡РёСЃРµР»: ");
	scanf_s("%d", &N);
	printf("РљСЂР°С‚РЅС‹Рµ С‡РёСЃР»Сѓ: ");
	scanf_s("%d", &A);

	do {
		num += A;
		i += 1;
		printf("%d ", num);
	} while (i <= N);
}

// Р§РёСЃР»Р° С„РёР±РѕРЅРЅР°С‡Рё
int task6() {
	int N;
	int i = 1;
	int num = 0;
	int num2 = 1;
	int num3 = 0;

	printf("РљРѕР»-РІРѕ С‡РёСЃРµР»: ");
	scanf_s("%d", &N);

	if (num3 <= 0) {
		printf("%d ", num3);
		num3 = 1;
	}

	do {
		printf("%d ", num3);
		num3 = num + num2;
		num = num2;
		num2 = num3;
		i += 1;
	} while (i <= N);
}

// РљР°РїРёС‚Р°Р»РёР·Р°С†РёСЏ РїРѕ РІРєР»Р°РґСѓ
int task7() {
	int invest;
	int i = 0;
	float percent, period;

	float temp = 0;

	printf("Р’РІРµРґРёС‚Рµ СЃСѓРјРјСѓ РІРєР»Р°РґР° РІ СЂСѓР±Р»СЏС…: ");
	scanf_s("%d", &invest);
	printf("Р’РІРµРґРёС‚Рµ СЃСЂРѕРє РІРєР»Р°РґР° РІ РјРµСЃСЏС†Р°С…: ");
	scanf_s("%f", &period);
	printf("Р’РІРµРґРёС‚Рµ РіРѕРґРѕРІСѓСЋ СЃС‚Р°РІРєСѓ: ");
	scanf_s("%f", &percent);

	float received = invest;

	do {
		printf("%10.2f ", received);
		temp = received * pow(1 + (percent / 100) / 365, 30) - received;
		printf("%10.2f \n", temp);
		received += received * pow(1 + (percent/100) / 365, 30) - received;
		i += 1;
	} while (i <= period); 
}