#include <stdio.h>
#include "command.h"
#include "../ADT/Header/mesinkata.h"

//commands
void InitKataCommand(){
  KataGU.TabKata[0] = 'G';
  KataGU.TabKata[1] = 'U';
  KataGU.Length = 2;

  KataGD.TabKata[0] = 'G';
  KataGD.TabKata[1] = 'D';
  KataGD.Length = 2;

  KataGL.TabKata[0] = 'G';
  KataGL.TabKata[1] = 'L';
  KataGL.Length = 2;

  KataGR.TabKata[0] = 'G';
  KataGR.TabKata[1] = 'R';
  KataGR.Length = 2;

  KataORDER.TabKata[0] = 'O';
  KataORDER.TabKata[1] = 'R';
  KataORDER.TabKata[2] = 'D';
  KataORDER.TabKata[3] = 'E';
  KataORDER.TabKata[4] = 'R';
  KataORDER.Length = 5;

  KataPUT.TabKata[0] = 'P';
  KataPUT.TabKata[1] = 'U';
  KataPUT.TabKata[2] = 'T';
  KataPUT.Length = 3;

  KataTAKE.TabKata[0] = 'T';
  KataTAKE.TabKata[1] = 'A';
  KataTAKE.TabKata[2] = 'K';
  KataTAKE.TabKata[3] = 'E';
  KataTAKE.Length = 4;

  KataCH.TabKata[0] = 'C';
  KataCH.TabKata[1] = 'H';
  KataCH.Length = 2;

  KataCT.TabKata[0] = 'C';
  KataCT.TabKata[1] = 'T';
  KataCT.Length = 2;

  KataPLACE.TabKata[0] = 'P';
  KataPLACE.TabKata[1] = 'L';
  KataPLACE.TabKata[2] = 'A';
  KataPLACE.TabKata[3] = 'C';
  KataPLACE.TabKata[4] = 'E';
  KataPLACE.Length = 5;

  KataGIVE.TabKata[0] = 'G';
  KataGIVE.TabKata[1] = 'I';
  KataGIVE.TabKata[2] = 'V';
  KataGIVE.TabKata[3] = 'E';
  KataGIVE.Length = 4;

  KataRECIPE.TabKata[0] = 'R';
  KataRECIPE.TabKata[1] = 'E';
  KataRECIPE.TabKata[2] = 'C';
  KataRECIPE.TabKata[3] = 'I';
  KataRECIPE.TabKata[4] = 'P';
  KataRECIPE.TabKata[5] = 'E';
  KataRECIPE.Length = 6;

  KataSAVE.TabKata[0] = 'S';
  KataSAVE.TabKata[1] = 'A';
  KataSAVE.TabKata[2] = 'V';
  KataSAVE.TabKata[3] = 'E';
  KataSAVE.Length = 4;

  KataLOAD.TabKata[0] = 'L';
  KataLOAD.TabKata[1] = 'O';
  KataLOAD.TabKata[2] = 'A';
  KataLOAD.TabKata[3] = 'D';
  KataLOAD.Length = 4;

  KataEXIT.TabKata[0] = 'E';
  KataEXIT.TabKata[1] = 'X';
  KataEXIT.TabKata[2] = 'I';
  KataEXIT.TabKata[3] = 'T';
  KataEXIT.Length = 4;
}
