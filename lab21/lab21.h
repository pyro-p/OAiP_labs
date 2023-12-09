#pragma once 
#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Строки
#define N 10
// Столбцы
#define M 15

#define WIDTH 50
#define HEIGHT 60

extern int map[N][M];
extern int steps;
extern int gold;

void drawMap(HDC hdc);
void PlaceWallLeft();
void PlaceGoldRight();
void BreakRight();
void CollectGoldAbove();
void BreakAdjacentWalls();
void BreakTwoWalls();

void Left();
void Right();
void Up();
void Down();
void TeleportDown();

void Save();
void Load();
void SaveBinary();
void LoadBinary();
void Reset();
