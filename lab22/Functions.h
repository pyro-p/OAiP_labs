#pragma once

#include <stdio.h>
#include <windows.h>

void next20Chars();
void previous30Chars();
void spaceCount();
void spaceSwitchHash();
void digitSwitchDollar();
int personalIsDigit(char ch);
void changeToUpper();
int personalToUpper(char ch);
int personalStrlen(char str[]);
int personalStrcmp(char str1[], char str2[]);
void personalStrcpy(char dest[], char src[]);
void personalStrcat(char dest[], char src[]);
void notDigitToUnderscore();