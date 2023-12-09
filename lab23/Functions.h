#pragma once

#include <stdio.h>
#include <windows.h>

FILE* inputFile(char file[]);
FILE* outputFile(char file[]);

int personalIsalpha(unsigned char ch);

void task1(FILE* fin, FILE* fout);
void task2(FILE* fin, FILE* fout);
void task3(FILE* fin, FILE* fout);
void task4(FILE* fin);
void task5(FILE* fin, FILE* fout);
void task6(FILE* fin, FILE* fout);
void task7(FILE* fin, FILE* fout);
void task8(FILE* fin, FILE* fout);

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);