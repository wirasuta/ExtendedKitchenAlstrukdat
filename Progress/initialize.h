// Header untuk map.c

#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "../ADT/Header/boolean.h"
#include "../ADT/Header/matriks.h"
#include "../ADT/Header/tepokpramuka_type.h"
#include "../ADT/Header/mesinkata.h"
#include "../ADT/Header/stackt.h"
#include "../ADT/Header/point.h"

void InitGame(Game *G);
void InitPlayer(Player *P);
void InitRoom(Room *R);
void InitMap(Room *R, POINT PlPoint);

#endif
