#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements();
void keyboardInput();
void oddsX10();
int findMin();
int greaterThen10();
int findLastEven();
int findFirstEven();
int findAllEven(int array[]);
int findIndexMin();
void deleteElement(int deleteIndex);
void insertElement(int insertIndex, int value);
void deleteLess4();

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item = -1;

	while (item != 0) {
		printf("\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("���������� �������:");
		printElements();
		printf("\n");
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������ � ���������� ������\n");
		printf("2: x10 ��� ���� �������� ���������\n");
		printf("3: ����� ����������� �������\n");
		printf("4: ���-�� ��������� ������ ��� 10\n");
		printf("5: x2 ��������� ������\n");
		printf("6: ���-�� ������ ����� ������������\n");
		printf("7: x10 ��� �������� ������ ������������\n");
		printf("8: �������� ��� � ���� �������� �������\n");
		printf("9: ��� ������ �������� ������� �������� �� -1\n");
		printf("10: ��� �������� ������� ������� �������� ������ 4 �������� �� 4\n");
		printf("11: ��� �������� ������� ����� ������������ � ����������� ��������� � 10 ���\n");
		printf("12: ��� �������� ����� ������ � ��������� ������ ��������� � 100 ���\n\n");
		printf("21: �������� ��������� �������� �������\n");
		printf("22: ������� ������ �������� � �������� �����\n");
		printf("23: ������� ����������� �������\n");
		printf("24: ����� ����������� ��������� �������� 0\n");
		printf("25: ������� ��� ������ ��������\n");
		printf("26: �������������� ��� ������ ��������\n");
		printf("27: �������� � ������ �������, ������ ������������\n");
		printf("28: ������� �� ������� ��� ��������, �������� ������� ������ 4\n");
		printf("\n");
		printf("0: ����� �� ���������\n");
		printf("��������� �������� >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1: {
			keyboardInput();
		} break;
		case 2: {
			oddsX10();
		} break;
		case 3: {
			int min = findMin();
			printf("min = %d\n", min);
		} break;
		case 4: {
			int gr = greaterThen10();
			printf("������ 10 - %d ���������\n", gr);
		} break;
		case 5: {
			int le = findLastEven();
			if (le >= 0) {
				arr[le] *= 2;
			}
		}
		break;
		case 6: {
			int index_min = findIndexMin();
			int cnt = 0;
			for (int i = 0; i < index_min; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("����� ������������ �������� - %d ������", cnt);
		} break;
		case 7: {
			int index_min = findIndexMin();
			for (int i = index_min + 1; i < n; i++) {
				if (arr[i] % 2 == 1) {
					arr[i] = arr[i] * 10;
				}
			}
		} break;
		case 8: {
			int index_min = findIndexMin();
			int index_max = findIndexMax();

			int tmp = arr[index_max];
			arr[index_max] = arr[index_min];
			arr[index_min] = tmp;
		} break;
		case 9: {
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 == 0) {
					arr[i] *= -1;
				}
			}
		} break;
		case 10: {
			for (int i = 0; i < n; i++) {
				if (arr[i] < 4) {
					arr[i] = 4;
				}
			}
		} break;
		case 11: {
			int index_min = findIndexMin();
			int index_max = findIndexMax();

			if (index_max > index_min) {
				for (int i = index_min + 1; i < index_max; i++) {
					arr[i] = arr[i] * 10;
				}
			}
			else if (index_max < index_min) {
				for (int i = index_max + 1; i < index_min; i++) {
					arr[i] = arr[i] * 10;
				}
			}
		} break;
		case 12: {
			int index_first = findFirstEven();
			int index_last = findLastEven();

			if (index_first > index_last) {
				for (int i = index_last + 1; i < index_first; i++) {
					arr[i] = arr[i] * 100;
				}
			}
			else if (index_first < index_last) {
				for (int i = index_first + 1; i < index_last; i++) {
					arr[i] = arr[i] * 100;
				}
			}
		} break;
		case 21: {
			printf("������ ���������� �������� - ");
			int index;
			scanf_s("%d", &index);

			if (index >= n) {
				printf("������ ������� �������");
				break;
			}
			else deleteElement(index);
		} break;
		case 22: {
			printf("������ ������������ �������� - ");
			int index;
			scanf_s("%d", &index);

			if (index > n) {
				printf("������ ������� �������");
				break;
			}
			else {
				printf("�������� - ");
				int value;
				scanf_s("%d", &value);

				insertElement(index, value);
			}
		} break;
		case 23: {
			int index = findIndexMin();
			deleteElement(index);
		} break;
		case 24: {
			int index = findIndexMin();
			insertElement(index, 0);
		} break;
		case 25: {
			int index[NUM_ELEMENTS];

			int cnt = findAllEven(index);

			for (int i = cnt - 1; i >= 0; i--) {
				deleteElement(index[i]);
			}
		} break;
		case 26: {
			int index[NUM_ELEMENTS];

			int cnt = findAllEven(index);

			for (int i = cnt - 1; i >= 0; i--) {
				insertElement(index[i], arr[index[i]]);
			}
		} break;
		case 27: {
			int min = findMin();
			insertElement(0, min);
		} break;
		case 28: {
			deleteLess4();
		} break;
		}
	}
}

void printElements() {
	FILE* fout = fopen("D:\\Temp\\out-lab16_17.txt", "wt");
	if (fout == NULL) {
		for (int i = 0; i < n; i++) {
			printf(" %d", arr[i]);
			fprintf(fout, "%d ", arr[i]);
		}
		return;
	}

	fprintf(fout, "%d\n", n);
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
		fprintf(fout, "%d ", arr[i]);
	}

	fclose(fout);
}

void keyboardInput() {
	FILE* fin = fopen("D:\\Temp\\in-lab16_17.txt", "rt");
	if (fin == NULL) {
		printf("������ ������� - ");
		scanf_s("%d", &n);

		printf("������� %d ��������: ", n);
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &arr[i]);
		}
		return;
	}
	fscanf(fin, "%d\n", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &arr[i]);
	}
	fclose(fin);
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}

int findMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int greaterThen10() {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			index++;
		}
	}
	return index;
}

int findLastEven() {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			index = i;
		}
	}
	return index;
}

int findFirstEven() {
	int index;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			index = i;
			return index;
		}
	}
}

int findAllEven(int array[]) {
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			array[j] = i;
			j++;
		}
	}
	return j;
}

int findIndexMin() {
	int min = arr[0];
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

int findIndexMax() {
	int max = arr[0];
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	return index;
}

void deleteElement(int deleteIndex) {
	for (int i = deleteIndex; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void insertElement(int insertIndex, int value) {
	for (int i = n; i > insertIndex; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[insertIndex] = value;
}

void deleteLess4() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			deleteElement(i);
			deleteLess4();
		}
	}
}