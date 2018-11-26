#include "move.h"
#include "command.h"


boolean pathFilled(MATRIKS M ,int X, int Y)
{
    return ((MatElmt(M, X, Y) == 'X') || (MatElmt(M, X, Y) == 'M') || (MatElmt(M, X, Y) == 'C') || (MatElmt(M, X, Y) == '1') || (MatElmt(M, X, Y) == '2') || (MatElmt(M, X, Y) == '3') || (MatElmt(M, X, Y) == '4'));
    // tinggal tambah kalo X, Y < Btsmin Ruangan dan X, Y > Btsmax Ruangan
}

void newCoordinate(MATRIKS M, int *X, int *Y, Kata command, int *roomID)
{
    if (IsKataSama(command, KataGU))
    {
        if (pathFilled(M, *X-1, *Y))
        {
         printf("Path is Filled! \n");
        }
        else if ( (*X-1) < 1 )
        {
            int i=0;
            adrEdgeNode nextRoom = Nil;
            while (i<=4 && nextRoom==Nil) {
              i++;
              nextRoom = SearchEdgeNode(RoomGraph(gameData), MakePOINT(*X,*Y), *roomID, i);
            }
            if (nextRoom != Nil) {
              *roomID = i;
              *X = Absis(DestTile(nextRoom));
              *Y = Ordinat(DestTile(nextRoom));
            }else{
              printf("You can't move through a wall, duh");
            }
        }
        else
        {
        *X = *X - 1;
        }
    }
    else if (IsKataSama(command, KataGD))
    {
        if (pathFilled(M, *X+1, *Y))
        {
         printf("Path is Filled! \n");
        }
        else if ( (*X+1) > 8 )
        {
          int i=0;
          adrEdgeNode nextRoom = Nil;
          while (i<=4 && nextRoom==Nil) {
            i++;
            nextRoom = SearchEdgeNode(RoomGraph(gameData), MakePOINT(*X,*Y), *roomID, i);
          }
          if (nextRoom != Nil) {
            *roomID = i;
            *X = Absis(DestTile(nextRoom));
            *Y = Ordinat(DestTile(nextRoom));
          }else{
            printf("You can't move through a wall, duh");
          }
        }
        else
        {
        *X = *X + 1;
        }
    }
    else if (IsKataSama(command, KataGL))
    {
        if (pathFilled(M, *X, *Y-1))
        {
         printf("Path is Filled! \n");
        }
        else if ( (*Y-1) < 1 )
        {
          int i=0;
          adrEdgeNode nextRoom = Nil;
          while (i<=4 && nextRoom==Nil) {
            i++;
            nextRoom = SearchEdgeNode(RoomGraph(gameData), MakePOINT(*X,*Y), *roomID, i);
          }
          if (nextRoom != Nil) {
            *roomID = i;
            *X = Absis(DestTile(nextRoom));
            *Y = Ordinat(DestTile(nextRoom));
          }else{
            printf("You can't move through a wall, duh");
          }
        }
        else
        {
        *Y = *Y - 1;
        }
    }
    else if (IsKataSama(command, KataGR))
    {
        if (pathFilled(M, *X, *Y+1))
        {
         printf("Path is Filled! \n");
        }
        else if ( (*Y+1) > 8 )
        {
          int i=0;
          adrEdgeNode nextRoom = Nil;
          while (i<=4 && nextRoom==Nil) {
            i++;
            nextRoom = SearchEdgeNode(RoomGraph(gameData), MakePOINT(*X,*Y), *roomID, i);
          }
          if (nextRoom != Nil) {
            *roomID = i;
            *X = Absis(DestTile(nextRoom));
            *Y = Ordinat(DestTile(nextRoom));
          }else{
            printf("You can't move through a wall, duh");
          }
        }
        else
        {
        *Y = *Y + 1;
        }
    }
}

void move(MATRIKS *M, int *X, int *Y,Kata command, int *roomID)
{
        newCoordinate(*M, Y, X, command, roomID);
}



/* int main()
{
    MATRIKS Map;
    Kata command;
    int X, Y;
    Kata KataGU, KataGD, KataGL, KataGR, KataORDER, KataPUT, KataTAKE, KataCH;
Kata KataPLACE, KataGIVE, KataRECIPE, KataSAVE, KataLOAD, KataEXIT;

//commands

KataGU.TabKata[0] = 'G';
KataGU.TabKata[1] = 'U';

KataGD.TabKata[0] = 'G';
KataGD.TabKata[1] = 'D';

KataGL.TabKata[0] = 'G';
KataGL.TabKata[1] = 'L';

KataGR.TabKata[0] = 'G';
KataGR.TabKata[1] = 'D';

KataORDER.TabKata[0] = 'O';
KataORDER.TabKata[1] = 'R';
KataORDER.TabKata[2] = 'D';
KataORDER.TabKata[3] = 'E';
KataORDER.TabKata[4] = 'R';

KataPUT.TabKata[0] = 'P';
KataPUT.TabKata[1] = 'U';
KataPUT.TabKata[2] = 'T';

KataTAKE.TabKata[0] = 'T';
KataTAKE.TabKata[1] = 'A';
KataTAKE.TabKata[2] = 'K';
KataTAKE.TabKata[3] = 'E';

KataCH.TabKata[0] = 'C';
KataCH.TabKata[1] = 'H';

KataPLACE.TabKata[0] = 'P';
KataPLACE.TabKata[1] = 'L';
KataPLACE.TabKata[2] = 'A';
KataPLACE.TabKata[3] = 'C';
KataPLACE.TabKata[4] = 'E';

KataGIVE.TabKata[0] = 'G';
KataGIVE.TabKata[1] = 'I';
KataGIVE.TabKata[2] = 'V';
KataGIVE.TabKata[3] = 'E';

KataRECIPE.TabKata[0] = 'R';
KataRECIPE.TabKata[1] = 'E';
KataRECIPE.TabKata[2] = 'C';
KataRECIPE.TabKata[3] = 'I';
KataRECIPE.TabKata[4] = 'P';
KataRECIPE.TabKata[5] = 'E';

KataSAVE.TabKata[0] = 'S';
KataSAVE.TabKata[1] = 'A';
KataSAVE.TabKata[2] = 'V';
KataSAVE.TabKata[3] = 'E';

KataLOAD.TabKata[0] = 'L';
KataLOAD.TabKata[1] = 'O';
KataLOAD.TabKata[2] = 'A';
KataLOAD.TabKata[3] = 'D';

KataEXIT.TabKata[0] = 'E';
KataEXIT.TabKata[1] = 'X';
KataEXIT.TabKata[2] = 'I';
KataEXIT.TabKata[3] = 'T';

    MakeMATRIKS(10, 10, &Map);
    X = 4;
    Y = 4;

    //Current Position
    Elmt(Map, 4, 3) = 'X';

    Elmt(Map, X, Y) = 'P';
    printf("Initial Position : %d %d \n", X, Y);

    move(&Map, &X, &Y, KataGD);
    printf("Next Position: %d %d", X, Y);
} */
