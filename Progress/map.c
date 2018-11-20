// Header untuk map.c

#ifndef MAP_H
#define MAP_H

#include "../ADT/Header/boolean.h"
#include "../ADT/Header/matriks.h"

void InitMap(MATRIKS *M, POINT PlPoint){
  MakeMATRIKS(10, 10, M);
  int i,j;
  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
    for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
      if (i == Absis(PlPoint) && j == Ordinat(PlPoint)) {
        MatElmt(*M, i, j) = 'P';
      }else{
        MatElmt(*M, i, j) = '.';
      }
    }
  }

}

#endif
