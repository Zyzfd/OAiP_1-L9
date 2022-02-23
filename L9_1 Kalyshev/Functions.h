#pragma once

#include "framework.h"
#include <time.h>

#define N 10
#define M 15

void moveToLeft();
void moveToRight();
void moveUp();
void moveDown();
void DrawField(HDC hdc);
void newWallLeft();
void newWallRight();
void newWallUp();
void newWallDown();
void destroyWallRight();
void destroyWallLeft();
void destroyWallAround();
void MoveMonsters();
void MoveMonstersChoose();
void MoveMonstersRage();
void generateLevel();
void generateLevelWithMonsters();
void insertGold();
int saveLevel();
int loadLevel();