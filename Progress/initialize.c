#include "initialize.h"

void InitGame(Game *G){
  //TODO: Load dari file external
  ElmtName(*G).TabKata[1] = ' ';
  Life(*G) = 5;
  Money(*G) = 0;
}

void InitPlayer(Player *P){
  CreateEmptyStack(&(OnHand(*P)));
  CreateEmptyStack(&(OnTray(*P)));
  PosPlayer(*P) =  MakePOINT(3, 4);
}

void InitMap(MATRIKS *M, POINT PlPoint){
  MakeMATRIKS(10, 10, M);
  int i,j;
  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
    for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
      if (i == Ordinat(PlPoint) && j == Absis(PlPoint)) {
        MatElmt(*M, i, j) = 'P';
      }else{
        MatElmt(*M, i, j) = '.';
      }
    }
  }
}
