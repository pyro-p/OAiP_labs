#define _CRT_SECURE_NO_WARNINGS
#include "Dict.h"
#include <string.h>
#include <stdio.h>


#define MAX_WORDS 10000

// Слова 
char words[MAX_WORDS][MAX_LEN_WORD + 1];
// Количество слов в словаре
int numWords = 0;

/*
CREATE - создает словарь.
Вызывается перед началом использования словаря.
*/
void Create() {
	numWords = 0;
}


/*
DESTROY - уничтожает словарь.
Вызывается после окончания использования словаря.
*/
void Destroy() {
	numWords = 0;
}



/*
INSERT – добавляет элемент в множество.
Множество – содержит только уникальные элементы.
При повторном добавлении элемента в множество, множество не изменяется.
*/
void Insert(char* word) {

	if (numWords >= MAX_WORDS) {
		return; // словарь переполнен!
	}

	// Начиная с конца массива ищется место куда нужно вставить слово
	// Вставка делается в отсортированный массив
	// Вставка делается так, чтобы после вставки массив был отсортирован
	int i = numWords;
	while ((i > 0) && (strcmp(word, words[i - 1]) < 0)) {
		strcpy(words[i], words[i - 1]);
		i--;
	}
	strcpy(words[i], word);
	++numWords;
}



/*
MEMBER – сообщает, является ли указанный элемент членом данного множества или нет.
Если является - возврашает 1, иначе - возвращает 0
*/
int  Member(char* word) {
	// Используется алгоритм бинарного поиска слова в отсортированном массиве
	int left = 0;
	int right = numWords - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		int dif = strcmp(words[middle], word);
		if (dif == 0) {
			return 1;
		}
		if (dif < 0) {
			left = middle + 1;
		}
		if (dif > 0) {
			right = middle - 1;
		}
	}
	return 0;
}
