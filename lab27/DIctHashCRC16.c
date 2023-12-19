//
// Реализация словаря на хэше
// 
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "Dict.h"



#define MAX_HASH 0xC003
#define CRC16 0x8005
//#define MAX_HASH 13
//#define MAX_HASH 1

struct Node {
	char* word;
	struct Node* next;
};

// Массив списков
struct Node* first[MAX_HASH];


//// Вычисление хэша для строки word
//int hash(char* word) {
//	unsigned long hash_value = 0;
//	int i = 0;
//	while (word[i] != '\0') {
//		hash_value = ((unsigned)(word[i]));
//		break;
//		//hash_value = 31 * hash_value + ((unsigned)(word[i]));
//		//i++;
//	}
//	return hash_value % MAX_HASH;
//}


// Хэш-функция CRC-16-IBM
uint16_t gen_crc16(const uint8_t* data, uint16_t size)
{
    uint16_t out = 0;
    int bits_read = 0, bit_flag;

    /* Sanity check: */
    if (data == NULL)
        return 0;

    while (size > 0)
    {
        bit_flag = out >> 15;

        /* Get next bit: */
        out <<= 1;
        out |= (*data >> bits_read) & 1; // item a) work from the least significant bits

        /* Increment bit counter: */
        bits_read++;
        if (bits_read > 7)
        {
            bits_read = 0;
            data++;
            size--;
        }

        /* Cycle check: */
        if (bit_flag)
            out ^= CRC16;

    }

    // item b) "push out" the last 16 bits
    int i;
    for (i = 0; i < 16; ++i) {
        bit_flag = out >> 15;
        out <<= 1;
        if (bit_flag)
            out ^= CRC16;
    }

    // item c) reverse the bits
    uint16_t crc = 0;
    i = 0x8000;
    int j = 0x0001;
    for (; i != 0; i >>= 1, j <<= 1) {
        if (i & out) crc |= j;
    }

    return crc;
}



/* INSERT – добавляет элемент в множество.
Множество – содержит только уникальные элементы.
При повторном добавлении элемента в множество, множество не изменяется. */
void Insert(char* word) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	int hash_value = gen_crc16(word, strlen(word));

	newNode->next = first[hash_value];
	newNode->word = (char*)calloc(strlen(word) + 1, sizeof(char));
	strcpy(newNode->word, word);
	first[hash_value] = newNode;

}


/* MEMBER – сообщает, является ли указанный элемент членом данного множества или нет. */
int  Member(char* word) {
	int hash_value = gen_crc16(word, strlen(word));

	struct Node* ptr = first[hash_value];
	while (ptr != NULL) {
		if (strcmp(ptr->word, word) == 0) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}


/* CREATE - создает словарь.
Вызывается перед началом использования словаря. */
void Create() {
	for (int i = 0; i < MAX_HASH; i++)
		first[i] = NULL;
}


/* DESTROY - уничтожает словарь.
Вызывается после окончания использования словаря. */
void Destroy() {
	for (int i = 0; i < MAX_HASH; i++) {

		while (first[i] != NULL) {
			struct Node* delNode = first[i];
			first[i] = first[i]->next;

			free(delNode->word);
			free(delNode);
		}
	}
}