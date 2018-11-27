#include "initialize.h"
#include <stdio.h>
#include <stdlib.h>

void InitGame(Game *G){
  ElmtName(*G).Length = 0;
  Life(*G) = 5;
  Money(*G) = 0;
  InitRoom(&(Ruang(*G,1)));
  InitRoom(&(Ruang(*G,2)));
  InitRoom(&(Ruang(*G,3)));
  InitDapur(&(Ruang(*G,4)));
  InitGraph(&(RoomGraph(*G)));
}

void InitPlayer(Player *P){
  CreateEmptyStack(&(OnHand(*P)));
  CreateEmptyStack(&(OnTray(*P)));
  PlayerTick(*P) = (rand() % (50 + 1 - 10)) + 10;
  PosPlayer(*P) =  MakePOINT(5, 5);
  RoomID(*P) = 1;
}

void InitMap(Room *R, POINT PlPoint){
  MakeMATRIKS(RestoSizeM, RestoSizeN, &(Layout(*R)));
  int i,j,x;
  int tableCount = 4;
  int ingCount = 16;
  for (i = GetFirstIdxBrs(Layout(*R)); i <= GetLastIdxBrs(Layout(*R)); i++) {
    for (j = GetFirstIdxKol(Layout(*R)); j <= GetLastIdxKol(Layout(*R)); j++) {
      if (i == 0 && j == 0){
        MatElmt(Layout(*R), i, j) = '#';
      }else if (EQ(PlPoint,MakePOINT(j, i))) {
        MatElmt(Layout(*R), i, j) = 'P';
      }else{
        MatElmt(Layout(*R), i, j) = '.';
      }
      if (RoomStructID(*R)!=4) { //Bukan Dapur
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
      } else {
        for (x = 0; x < ingCount; x++) {
          if (EQ(PosIngredients(Ingredient(*R, x)),MakePOINT(j, i))){
            MatElmt(Layout(*R), i, j) = 'M';
          }
        }
        if (EQ(PosTray(*R),MakePOINT(j, i))){
          MatElmt(Layout(*R), i, j) = 'T';
        }
      }
    }
  }
}

void InitGraph(GRAPH *G){
  adrNode R1 = AlokNodeGr(1);
  adrNode R2 = AlokNodeGr(2);
  adrNode R3 = AlokNodeGr(3);
  adrNode R4 = AlokNodeGr(4);

  *G = CreateGraph(R1);
  NextNode(R1) = R2;
  NextNode(R2) = R3;
  NextNode(R3) = R4;

  adrEdgeNode E12 = AlokEdgeNode(*G, MakePOINT(5, RestoSizeM), MakePOINT(2, 1), 2);
  adrEdgeNode E21 = AlokEdgeNode(*G, MakePOINT(2, 1), MakePOINT(5, RestoSizeM), 1);
  adrEdgeNode E23 = AlokEdgeNode(*G, MakePOINT(RestoSizeN, 5), MakePOINT(1, 5), 3);
  adrEdgeNode E32 = AlokEdgeNode(*G, MakePOINT(1, 5), MakePOINT(RestoSizeN, 5), 2);
  adrEdgeNode E34 = AlokEdgeNode(*G, MakePOINT(2, 1), MakePOINT(5, RestoSizeM), 4);
  adrEdgeNode E43 = AlokEdgeNode(*G, MakePOINT(5, RestoSizeM), MakePOINT(2, 1), 3);
  adrEdgeNode E14 = AlokEdgeNode(*G, MakePOINT(RestoSizeN, 5), MakePOINT(1, 5), 4);
  adrEdgeNode E41 = AlokEdgeNode(*G, MakePOINT(1, 5), MakePOINT(RestoSizeN, 5), 1);

  addEdgeNode(&R1, E12);
  addEdgeNode(&R1, E14);
  addEdgeNode(&R2, E21);
  addEdgeNode(&R2, E23);
  addEdgeNode(&R3, E32);
  addEdgeNode(&R3, E34);
  addEdgeNode(&R4, E41);
  addEdgeNode(&R4, E43);
}

void InitRoom(Room *R){
  PosTable(TableNo(*R, 1), 0) = MakePOINT(3, 3);
  PosTable(TableNo(*R, 2), 0) = MakePOINT(7, 4);
  PosTable(TableNo(*R, 3), 0) = MakePOINT(3, 8);
  PosTable(TableNo(*R, 4), 0) = MakePOINT(7, 7);
  Capacity(TableNo(*R, 1)) = 4;
  Capacity(TableNo(*R, 2)) = 2;
  Capacity(TableNo(*R, 3)) = 4;
  Capacity(TableNo(*R, 4)) = 2;
  IsOccupied(TableNo(*R, 1)) = false;
  IsOccupied(TableNo(*R, 2)) = false;
  IsOccupied(TableNo(*R, 3)) = false;
  IsOccupied(TableNo(*R, 4)) = false;
  PosTable(TableNo(*R, 1), 1) = MakePOINT(2, 3);
  PosTable(TableNo(*R, 1), 2) = MakePOINT(4, 3);
  PosTable(TableNo(*R, 1), 3) = MakePOINT(3, 2);
  PosTable(TableNo(*R, 1), 4) = MakePOINT(3, 4);
  PosTable(TableNo(*R, 2), 1) = MakePOINT(6, 4);
  PosTable(TableNo(*R, 2), 2) = MakePOINT(8, 4);
  PosTable(TableNo(*R, 2), 3) = MakePOINT(7, 3);
  PosTable(TableNo(*R, 2), 4) = MakePOINT(7, 5);
  PosTable(TableNo(*R, 3), 1) = MakePOINT(2, 8);
  PosTable(TableNo(*R, 3), 2) = MakePOINT(4, 8);
  PosTable(TableNo(*R, 3), 3) = MakePOINT(3, 7);
  PosTable(TableNo(*R, 3), 4) = MakePOINT(3, 9);
  PosTable(TableNo(*R, 4), 1) = MakePOINT(6, 7);
  PosTable(TableNo(*R, 4), 2) = MakePOINT(8, 7);
  PosTable(TableNo(*R, 4), 3) = MakePOINT(7, 6);
  PosTable(TableNo(*R, 4), 4) = MakePOINT(7, 8);
}

void InitDapur(Room *R){
  PosTray(*R) = MakePOINT(10, 1);
  IngName(Ingredient(*R, 0)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 0)).TabKata[1] = 'p';
  IngName(Ingredient(*R, 0)).TabKata[2] = 'i';
  IngName(Ingredient(*R, 0)).TabKata[3] = 'r';
  IngName(Ingredient(*R, 0)).TabKata[4] = 'i';
  IngName(Ingredient(*R, 0)).TabKata[5] = 'n';
  IngName(Ingredient(*R, 0)).TabKata[6] = 'g';
  IngName(Ingredient(*R, 0)).Length = 6;
  PosIngredients(Ingredient(*R, 0)) = MakePOINT(1, 1);

  IngName(Ingredient(*R, 1)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 1)).TabKata[1] = 's';
  IngName(Ingredient(*R, 1)).TabKata[2] = 'e';
  IngName(Ingredient(*R, 1)).TabKata[3] = 'n';
  IngName(Ingredient(*R, 1)).TabKata[4] = 'd';
  IngName(Ingredient(*R, 1)).TabKata[5] = 'o';
  IngName(Ingredient(*R, 1)).TabKata[6] = 'k';
  IngName(Ingredient(*R, 1)).Length = 6;
  PosIngredients(Ingredient(*R, 1)) = MakePOINT(1, 2);

  IngName(Ingredient(*R, 2)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 2)).TabKata[1] = 'g';
  IngName(Ingredient(*R, 2)).TabKata[2] = 'a';
  IngName(Ingredient(*R, 2)).TabKata[3] = 'r';
  IngName(Ingredient(*R, 2)).TabKata[4] = 'p';
  IngName(Ingredient(*R, 2)).TabKata[5] = 'u';
  IngName(Ingredient(*R, 2)).Length = 5;
  PosIngredients(Ingredient(*R, 2)) = MakePOINT(1, 3);

  IngName(Ingredient(*R, 3)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 3)).TabKata[1] = 'e';
  IngName(Ingredient(*R, 3)).TabKata[2] = 's';
  IngName(Ingredient(*R, 3)).TabKata[3] = 'k';
  IngName(Ingredient(*R, 3)).TabKata[4] = 'r';
  IngName(Ingredient(*R, 3)).TabKata[5] = 'i';
  IngName(Ingredient(*R, 3)).TabKata[6] = 'm';
  IngName(Ingredient(*R, 3)).Length = 6;
  PosIngredients(Ingredient(*R, 3)) = MakePOINT(1, 4);

  IngName(Ingredient(*R, 4)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 4)).TabKata[1] = 'n';
  IngName(Ingredient(*R, 4)).TabKata[2] = 'a';
  IngName(Ingredient(*R, 4)).TabKata[3] = 's';
  IngName(Ingredient(*R, 4)).TabKata[4] = 'i';
  IngName(Ingredient(*R, 4)).Length = 4;
  PosIngredients(Ingredient(*R, 4)) = MakePOINT(1, 5);

  IngName(Ingredient(*R, 5)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 5)).TabKata[1] = 'r';
  IngName(Ingredient(*R, 5)).TabKata[2] = 'o';
  IngName(Ingredient(*R, 5)).TabKata[3] = 't';
  IngName(Ingredient(*R, 5)).TabKata[4] = 'i';
  IngName(Ingredient(*R, 5)).Length = 4;
  PosIngredients(Ingredient(*R, 5)) = MakePOINT(1, 6);

  IngName(Ingredient(*R, 6)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 6)).TabKata[1] = 's';
  IngName(Ingredient(*R, 6)).TabKata[2] = 'p';
  IngName(Ingredient(*R, 6)).TabKata[3] = 'a';
  IngName(Ingredient(*R, 6)).TabKata[4] = 'g';
  IngName(Ingredient(*R, 6)).TabKata[5] = 'h';
  IngName(Ingredient(*R, 6)).TabKata[6] = 'e';
  IngName(Ingredient(*R, 6)).TabKata[7] = 't';
  IngName(Ingredient(*R, 6)).TabKata[8] = 't';
  IngName(Ingredient(*R, 6)).TabKata[9] = 'i';
  IngName(Ingredient(*R, 6)).Length = 9;
  PosIngredients(Ingredient(*R, 6)) = MakePOINT(1, 7);

  IngName(Ingredient(*R, 7)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 7)).TabKata[1] = 'p';
  IngName(Ingredient(*R, 7)).TabKata[2] = 'i';
  IngName(Ingredient(*R, 7)).TabKata[3] = 's';
  IngName(Ingredient(*R, 7)).TabKata[4] = 'a';
  IngName(Ingredient(*R, 7)).TabKata[5] = 'n';
  IngName(Ingredient(*R, 7)).TabKata[6] = 'g';
  IngName(Ingredient(*R, 7)).Length = 6;
  PosIngredients(Ingredient(*R, 7)) = MakePOINT(1, 8);

  IngName(Ingredient(*R, 8)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 8)).TabKata[1] = 's';
  IngName(Ingredient(*R, 8)).TabKata[2] = 't';
  IngName(Ingredient(*R, 8)).TabKata[3] = 'r';
  IngName(Ingredient(*R, 8)).TabKata[4] = 'o';
  IngName(Ingredient(*R, 8)).TabKata[5] = 'b';
  IngName(Ingredient(*R, 8)).TabKata[6] = 'e';
  IngName(Ingredient(*R, 8)).TabKata[7] = 'r';
  IngName(Ingredient(*R, 8)).TabKata[8] = 'i';
  IngName(Ingredient(*R, 8)).Length = 8;
  PosIngredients(Ingredient(*R, 8)) = MakePOINT(1, 9);

  IngName(Ingredient(*R, 9)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 9)).TabKata[1] = 't';
  IngName(Ingredient(*R, 9)).TabKata[2] = 'e';
  IngName(Ingredient(*R, 9)).TabKata[3] = 'l';
  IngName(Ingredient(*R, 9)).TabKata[4] = 'u';
  IngName(Ingredient(*R, 9)).TabKata[5] = 'r';
  IngName(Ingredient(*R, 9)).Length = 5;
  PosIngredients(Ingredient(*R, 9)) = MakePOINT(1, 10);

  IngName(Ingredient(*R, 10)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 10)).TabKata[1] = 'a';
  IngName(Ingredient(*R, 10)).TabKata[2] = 'y';
  IngName(Ingredient(*R, 10)).TabKata[3] = 'a';
  IngName(Ingredient(*R, 10)).TabKata[4] = 'm';
  IngName(Ingredient(*R, 10)).TabKata[5] = 'g';
  IngName(Ingredient(*R, 10)).TabKata[6] = 'o';
  IngName(Ingredient(*R, 10)).TabKata[7] = 'r';
  IngName(Ingredient(*R, 10)).TabKata[8] = 'e';
  IngName(Ingredient(*R, 10)).TabKata[9] = 'n';
  IngName(Ingredient(*R, 10)).TabKata[10] = 'g';
  IngName(Ingredient(*R, 10)).Length = 10;
  PosIngredients(Ingredient(*R, 10)) = MakePOINT(3, 3);

  IngName(Ingredient(*R, 11)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 11)).TabKata[1] = 'p';
  IngName(Ingredient(*R, 11)).TabKata[2] = 'a';
  IngName(Ingredient(*R, 11)).TabKata[3] = 't';
  IngName(Ingredient(*R, 11)).TabKata[4] = 't';
  IngName(Ingredient(*R, 11)).TabKata[5] = 'y';
  IngName(Ingredient(*R, 11)).Length = 5;
  PosIngredients(Ingredient(*R, 11)) = MakePOINT(4, 3);

  IngName(Ingredient(*R, 12)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 12)).TabKata[1] = 's';
  IngName(Ingredient(*R, 12)).TabKata[2] = 'o';
  IngName(Ingredient(*R, 12)).TabKata[3] = 's';
  IngName(Ingredient(*R, 12)).TabKata[4] = 'i';
  IngName(Ingredient(*R, 12)).TabKata[5] = 's';
  IngName(Ingredient(*R, 12)).Length = 5;
  PosIngredients(Ingredient(*R, 12)) = MakePOINT(5, 3);

  IngName(Ingredient(*R, 13)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 13)).TabKata[1] = 'b';
  IngName(Ingredient(*R, 13)).TabKata[2] = 'o';
  IngName(Ingredient(*R, 13)).TabKata[3] = 'l';
  IngName(Ingredient(*R, 13)).TabKata[4] = 'o';
  IngName(Ingredient(*R, 13)).TabKata[5] = 'g';
  IngName(Ingredient(*R, 13)).TabKata[6] = 'n';
  IngName(Ingredient(*R, 13)).TabKata[7] = 'e';
  IngName(Ingredient(*R, 13)).TabKata[8] = 's';
  IngName(Ingredient(*R, 13)).TabKata[9] = 'e';
  IngName(Ingredient(*R, 13)).Length = 9;
  PosIngredients(Ingredient(*R, 13)) = MakePOINT(3, 6);

  IngName(Ingredient(*R, 14)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 14)).TabKata[1] = 'c';
  IngName(Ingredient(*R, 14)).TabKata[2] = 'a';
  IngName(Ingredient(*R, 14)).TabKata[3] = 'r';
  IngName(Ingredient(*R, 14)).TabKata[4] = 'b';
  IngName(Ingredient(*R, 14)).TabKata[5] = 'o';
  IngName(Ingredient(*R, 14)).TabKata[6] = 'n';
  IngName(Ingredient(*R, 14)).TabKata[7] = 'a';
  IngName(Ingredient(*R, 14)).TabKata[8] = 'r';
  IngName(Ingredient(*R, 14)).TabKata[9] = 'a';
  IngName(Ingredient(*R, 14)).Length = 9;
  PosIngredients(Ingredient(*R, 14)) = MakePOINT(4, 6);

  IngName(Ingredient(*R, 15)).TabKata[0] = ' ';
  IngName(Ingredient(*R, 15)).TabKata[1] = 'k';
  IngName(Ingredient(*R, 15)).TabKata[2] = 'e';
  IngName(Ingredient(*R, 15)).TabKata[3] = 'j';
  IngName(Ingredient(*R, 15)).TabKata[4] = 'u';
  IngName(Ingredient(*R, 15)).Length = 4;
  PosIngredients(Ingredient(*R, 15)) = MakePOINT(5, 6);
}

void returnCustomer(Customer *C, int N){
    Customer arrC[20];

    arrC[0].Star = false;
    arrC[0].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[0].TimeWaiting = -999;
    arrC[0].SumOfCustomer = 2;
    arrC[0].Position.X = -999;
    arrC[0].Position.Y = -999;
    arrC[0].Food.Status = '#';
    arrC[0].Food.Name.TabKata[0]=' ';
    arrC[0].Food.Name.TabKata[1]='b';
    arrC[0].Food.Name.TabKata[2]='a';
    arrC[0].Food.Name.TabKata[3]='n';
    arrC[0].Food.Name.TabKata[4]='a';
    arrC[0].Food.Name.TabKata[5]='n';
    arrC[0].Food.Name.TabKata[6]='a';
    arrC[0].Food.Name.TabKata[7]='s';
    arrC[0].Food.Name.TabKata[8]='p';
    arrC[0].Food.Name.TabKata[9]='l';
    arrC[0].Food.Name.TabKata[10]='i';
    arrC[0].Food.Name.TabKata[11]='t';
    arrC[0].Food.Name.TabKata[12]='\0';
    arrC[0].Food.Name.Length=12;
    arrC[0].Food.Nomor = -999;

    arrC[1].Star = false;
    arrC[1].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[1].TimeWaiting = -999;
    arrC[1].SumOfCustomer = 4;
    arrC[1].Position.X = -999;
    arrC[1].Position.Y = -999;
    arrC[1].Food.Status = '#';
    arrC[1].Food.Name.TabKata[0]=' ';
    arrC[1].Food.Name.TabKata[1]='s';
    arrC[1].Food.Name.TabKata[2]='u';
    arrC[1].Food.Name.TabKata[3]='n';
    arrC[1].Food.Name.TabKata[4]='d';
    arrC[1].Food.Name.TabKata[5]='a';
    arrC[1].Food.Name.TabKata[6]='e';
    arrC[1].Food.Name.TabKata[7]='\0';
    arrC[1].Food.Name.Length=7;
    arrC[1].Food.Nomor = -999;

    arrC[2].Star = true;
    arrC[2].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[2].TimeWaiting = -999;
    arrC[2].SumOfCustomer = 4;
    arrC[2].Position.X = -999;
    arrC[2].Position.Y = -999;
    arrC[2].Food.Status = '#';
    arrC[2].Food.Name.TabKata[0]=' ';
    arrC[2].Food.Name.TabKata[1]='b';
    arrC[2].Food.Name.TabKata[2]='u';
    arrC[2].Food.Name.TabKata[3]='r';
    arrC[2].Food.Name.TabKata[4]='g';
    arrC[2].Food.Name.TabKata[5]='e';
    arrC[2].Food.Name.TabKata[6]='r';
    arrC[2].Food.Name.TabKata[7]='\0';
    arrC[2].Food.Name.Length=7;
    arrC[2].Food.Nomor = -999;

    arrC[3].Star = true;
    arrC[3].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[3].TimeWaiting = -999;
    arrC[3].SumOfCustomer = 3;
    arrC[3].Position.X = -999;
    arrC[3].Position.Y = -999;
    arrC[3].Food.Status = '#';
    arrC[3].Food.Name.TabKata[0]=' ';
    arrC[3].Food.Name.TabKata[1]='n';
    arrC[3].Food.Name.TabKata[2]='a';
    arrC[3].Food.Name.TabKata[3]='s';
    arrC[3].Food.Name.TabKata[4]='i';
    arrC[3].Food.Name.TabKata[5]='t';
    arrC[3].Food.Name.TabKata[6]='e';
    arrC[3].Food.Name.TabKata[7]='l';
    arrC[3].Food.Name.TabKata[8]='u';
    arrC[3].Food.Name.TabKata[9]='r';
    arrC[3].Food.Name.TabKata[10]='d';
    arrC[3].Food.Name.TabKata[11]='a';
    arrC[3].Food.Name.TabKata[12]='d';
    arrC[3].Food.Name.TabKata[13]='a';
    arrC[3].Food.Name.TabKata[14]='r';
    arrC[3].Food.Name.TabKata[15]='\0';
    arrC[3].Food.Name.Length=15;
    arrC[3].Food.Nomor = -999;

    arrC[4].Star = true;
    arrC[4].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[4].TimeWaiting = -999;
    arrC[4].SumOfCustomer = 1;
    arrC[4].Position.X = -999;
    arrC[4].Position.Y = -999;
    arrC[4].Food.Status = '#';
    arrC[4].Food.Name.TabKata[0]=' ';
    arrC[4].Food.Name.TabKata[1]='s';
    arrC[4].Food.Name.TabKata[2]='p';
    arrC[4].Food.Name.TabKata[3]='a';
    arrC[4].Food.Name.TabKata[4]='g';
    arrC[4].Food.Name.TabKata[5]='h';
    arrC[4].Food.Name.TabKata[6]='e';
    arrC[4].Food.Name.TabKata[7]='t';
    arrC[4].Food.Name.TabKata[8]='t';
    arrC[4].Food.Name.TabKata[9]='i';
    arrC[4].Food.Name.TabKata[10]='c';
    arrC[4].Food.Name.TabKata[11]='a';
    arrC[4].Food.Name.TabKata[12]='r';
    arrC[4].Food.Name.TabKata[13]='b';
    arrC[4].Food.Name.TabKata[14]='o';
    arrC[4].Food.Name.TabKata[15]='n';
    arrC[4].Food.Name.TabKata[16]='a';
    arrC[4].Food.Name.TabKata[17]='r';
    arrC[4].Food.Name.TabKata[18]='a';
    arrC[4].Food.Name.TabKata[19]='\0';
    arrC[4].Food.Name.Length=19;
    arrC[4].Food.Nomor = -999;

    arrC[5].Star = false;
    arrC[5].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[5].TimeWaiting = -999;
    arrC[5].SumOfCustomer = 1;
    arrC[5].Position.X = -999;
    arrC[5].Position.Y = -999;
    arrC[5].Food.Status = '#';
    arrC[5].Food.Name.TabKata[0]=' ';
    arrC[5].Food.Name.TabKata[1]='s';
    arrC[5].Food.Name.TabKata[2]='p';
    arrC[5].Food.Name.TabKata[3]='a';
    arrC[5].Food.Name.TabKata[4]='g';
    arrC[5].Food.Name.TabKata[5]='h';
    arrC[5].Food.Name.TabKata[6]='e';
    arrC[5].Food.Name.TabKata[7]='t';
    arrC[5].Food.Name.TabKata[8]='t';
    arrC[5].Food.Name.TabKata[9]='i';
    arrC[5].Food.Name.TabKata[10]='b';
    arrC[5].Food.Name.TabKata[11]='o';
    arrC[5].Food.Name.TabKata[12]='l';
    arrC[5].Food.Name.TabKata[13]='o';
    arrC[5].Food.Name.TabKata[14]='g';
    arrC[5].Food.Name.TabKata[15]='n';
    arrC[5].Food.Name.TabKata[16]='e';
    arrC[5].Food.Name.TabKata[17]='s';
    arrC[5].Food.Name.TabKata[18]='e';
    arrC[5].Food.Name.TabKata[19]='\0';
    arrC[5].Food.Name.Length=19;
    arrC[5].Food.Nomor = -999;

    arrC[6].Star = true;
    arrC[6].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[6].TimeWaiting = -999;
    arrC[6].SumOfCustomer = 4;
    arrC[6].Position.X = -999;
    arrC[6].Position.Y = -999;
    arrC[6].Food.Status = '#';
    arrC[6].Food.Name.TabKata[0]=' ';
    arrC[6].Food.Name.TabKata[1]='n';
    arrC[6].Food.Name.TabKata[2]='a';
    arrC[6].Food.Name.TabKata[3]='s';
    arrC[6].Food.Name.TabKata[4]='i';
    arrC[6].Food.Name.TabKata[5]='a';
    arrC[6].Food.Name.TabKata[6]='y';
    arrC[6].Food.Name.TabKata[7]='a';
    arrC[6].Food.Name.TabKata[8]='m';
    arrC[6].Food.Name.TabKata[9]='g';
    arrC[6].Food.Name.TabKata[10]='o';
    arrC[6].Food.Name.TabKata[11]='r';
    arrC[6].Food.Name.TabKata[12]='e';
    arrC[6].Food.Name.TabKata[13]='n';
    arrC[6].Food.Name.TabKata[14]='g';
    arrC[6].Food.Name.TabKata[15]='\0';
    arrC[6].Food.Name.Length=15;
    arrC[6].Food.Nomor = -999;

    arrC[7].Star = false;
    arrC[7].TimeQueue = (rand() % (25 + 1 -15)) + 15;
    arrC[7].TimeWaiting = -999;
    arrC[7].SumOfCustomer = 4;
    arrC[7].Position.X = -999;
    arrC[7].Position.Y = -999;
    arrC[7].Food.Status = '#';
    arrC[7].Food.Name.TabKata[0]=' ';
    arrC[7].Food.Name.TabKata[1]='h';
    arrC[7].Food.Name.TabKata[2]='o';
    arrC[7].Food.Name.TabKata[3]='t';
    arrC[7].Food.Name.TabKata[4]='d';
    arrC[7].Food.Name.TabKata[5]='o';
    arrC[7].Food.Name.TabKata[6]='g';
    arrC[7].Food.Name.TabKata[7]='\0';
    arrC[7].Food.Name.Length=7;
    arrC[7].Food.Nomor = -999;

    *C = arrC[N];
}

void randomCustomer(Player P, CustQueue *Q){
    int random;
    Customer C;
    //boolean tickCount;

    if (checkPlayerTick(P)){
        random = (rand() % 8);
        returnCustomer(&C, random);
        printf("Added customer %d to queue, status order is %c\n", random, StatOrder(OrderC(C)));
        AddQueue(Q, C);
    }
}

int randomInteger(){
    int random;

    random = (rand() % (15 + 1 - 8)) + 8;
    return random;
}

boolean checkPlayerTick(Player P){
    int random;

    random = randomInteger();

    printf("\n");
    printf("player %d, tick %d\n", PlayerTick(P) % 15, random);

    return((PlayerTick(P) % 15) == random);
}
