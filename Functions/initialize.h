// Header untuk map.c

#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "../ADT/Header/boolean.h"
#include "../ADT/Header/matriks.h"
#include "../ADT/Header/queue.h"
#include "../ADT/Header/tepokpramuka_type.h"
#include "../ADT/Header/mesinkata.h"
#include "../ADT/Header/stackt.h"
#include "../ADT/Header/point.h"
#include "../ADT/Header/roomgraph.h"

extern Kata KataGU, KataGD, KataGL, KataGR, KataORDER, KataPUT, KataTAKE, KataCH, KataCT;
extern Kata KataPLACE, KataGIVE, KataRECIPE, KataSAVE, KataLOAD, KataEXIT;

extern int NextCustomerArr;

void InitKataCommand();
void InitGame(Game *G);
void InitPlayer(Player *P);
void InitRoom(Room *R);
void InitDapur(Room *R);
void InitMap(Room *R, POINT PlPoint);
void InitGraph(GRAPH *Gr);

#endif
