// Header untuk pergerakan player

#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "matriks.c"


boolean pathFilled(MATRIKS M ,int X, int Y);
// Menghasilkan true jika "kotak" sudah terisi 

void newCoordinate(MATRIKS M, int *X, int *Y, char a[4]);
// I.S. Koordinat player sembarang
// F.S. Koordinat player berubah sesuai dengan X dan Y

void move(MATRIKS *M, int *X, int *Y,char a[4]);
// I.S. Posisi player sembarang
// F.S. Posisi player ada di X dan Y yang ditunjuk

#endif
