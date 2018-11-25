#include "initialize.h"
#include <stdio.h>

void InitGame(Game *G){
  //TODO: Load dari file external
  ElmtName(*G).Length = 0;
  Life(*G) = 5;
  Money(*G) = 0;
}

void InitPlayer(Player *P){
  CreateEmptyStack(&(OnHand(*P)));
  CreateEmptyStack(&(OnTray(*P)));
  PosPlayer(*P) =  MakePOINT(3, 4);
}

void InitMap(Room *R, POINT PlPoint){
  MakeMATRIKS(8, 8, &(Layout(*R)));
  int i,j,x;
  int tableCount = 4;
  for (i = GetFirstIdxBrs(Layout(*R)); i <= GetLastIdxBrs(Layout(*R)); i++) {
    for (j = GetFirstIdxKol(Layout(*R)); j <= GetLastIdxKol(Layout(*R)); j++) {
      if (i == 0 && j == 0){
        MatElmt(Layout(*R), i, j) = '#';
      }else if (EQ(PlPoint,MakePOINT(j, i))) {
        MatElmt(Layout(*R), i, j) = 'P';
      }else{
        MatElmt(Layout(*R), i, j) = '.';
      }
      for (x = 1; x <= tableCount; x++) {
        if (EQ(PosTable(TableNo(*R, x), 0),MakePOINT(j, i))){
          MatElmt(Layout(*R), i, j) = x + '0';
        }
        int xkursi;
        for (xkursi = 1; xkursi <= Capacity(TableNo(*R, x)); xkursi++) {
          if (EQ(PosTable(TableNo(*R, x), xkursi),MakePOINT(j, i))){
            if (IsOccupied(TableNo(*R, x))) {
              MatElmt(Layout(*R), i, j) = 'C';
            } else {
              MatElmt(Layout(*R), i, j) = 'X';
            }
          }
        }
      }
    }
  }
}

void InitRoom(Room *R){
  //TODO : Ganti jadi baca dari file external
  PosTable(TableNo(*R, 1), 0) = MakePOINT(2, 2);
  PosTable(TableNo(*R, 2), 0) = MakePOINT(7, 2);
  PosTable(TableNo(*R, 3), 0) = MakePOINT(2, 7);
  PosTable(TableNo(*R, 4), 0) = MakePOINT(7, 7);
  Capacity(TableNo(*R, 1)) = 4;
  Capacity(TableNo(*R, 2)) = 2;
  Capacity(TableNo(*R, 3)) = 4;
  Capacity(TableNo(*R, 4)) = 2;
  IsOccupied(TableNo(*R, 1)) = false;
  IsOccupied(TableNo(*R, 2)) = false;
  IsOccupied(TableNo(*R, 3)) = false;
  IsOccupied(TableNo(*R, 4)) = false;
  PosTable(TableNo(*R, 1), 1) = MakePOINT(1, 2);
  PosTable(TableNo(*R, 1), 2) = MakePOINT(3, 2);
  PosTable(TableNo(*R, 1), 3) = MakePOINT(2, 1);
  PosTable(TableNo(*R, 1), 4) = MakePOINT(2, 3);
  PosTable(TableNo(*R, 2), 1) = MakePOINT(6, 2);
  PosTable(TableNo(*R, 2), 2) = MakePOINT(8, 2);
  PosTable(TableNo(*R, 2), 3) = MakePOINT(7, 1);
  PosTable(TableNo(*R, 2), 4) = MakePOINT(7, 3);
  PosTable(TableNo(*R, 3), 1) = MakePOINT(1, 7);
  PosTable(TableNo(*R, 3), 2) = MakePOINT(3, 7);
  PosTable(TableNo(*R, 3), 3) = MakePOINT(2, 6);
  PosTable(TableNo(*R, 3), 4) = MakePOINT(2, 8);
  PosTable(TableNo(*R, 4), 1) = MakePOINT(6, 7);
  PosTable(TableNo(*R, 4), 2) = MakePOINT(8, 7);
  PosTable(TableNo(*R, 4), 3) = MakePOINT(7, 6);
  PosTable(TableNo(*R, 4), 4) = MakePOINT(7, 8);
}
