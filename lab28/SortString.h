#pragma once

int LoadWords(char* filename);
void fillArrayStrings();

void SelectionSortStrings();
void BubbleSortStrings();
void InsertSortStrings();
void GnomeSortStrings();
void QuickSortStrings();

//int LinearSearchStrings(char* value);
//int BinarySearchStrings(char* value);
int isSortedStrings();

extern int n;