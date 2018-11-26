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

void InitGame(Game *G);
void InitPlayer(Player *P);
void InitRoom(Room *R);
void InitMap(Room *R, POINT PlPoint);
void InitGraph(GRAPH *Gr);

// RANDOM CUSTOMER MASUK KE QUEUE
void returnCustomer(Customer *C, int N);
void randomCustomer(Player P, CustQueue *Q);
int randomInteger();
boolean checkPlayerTick(Player P);

#endif
