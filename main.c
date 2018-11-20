#include "ADT/Header/array.h"
#include "ADT/Header/jam.h"
#include "ADT/Header/listdp.h"
#include "ADT/Header/matriks.h"
#include "ADT/Header/mesinkar.h"
#include "ADT/Header/mesinkata.h"
#include "ADT/Header/point.h"
#include "ADT/Header/queue.h"
#include "ADT/Header/stackt.h"
#include "ADT/Header/bintree.h"
#include "ADT/Header/tepokpramuka_type.h"
#include "Progress/move.h"
#include "Progress/process.h"
#include "Progress/command.h"
#include "Progress/initialize.h"

Kata KataGU, KataGD, KataGL, KataGR, KataORDER, KataPUT, KataTAKE, KataCH, KataCT;
Kata KataPLACE, KataGIVE, KataRECIPE, KataSAVE, KataLOAD, KataEXIT;
MATRIKS map;
Game gameData;
Player player;

int main(int argc, char const *argv[]) {
  int input;
  char username;
  Kata command;

  printf("(1)New Game\n");
  printf("(2)Start Game\n");
  printf("(3)Load Game\n");
  printf("(4)Exit\n");

  scanf("%d",&input);
  while ((input!=1)&&(input!=2)&&(input!=3)&&(input!=4)){
      printf("Inputan salah. Silahkan input angka yang valid.\n");
      scanf("%d",&input);
  }
  InitKataCommand();
  InitGame(&gameData);
  InitMap(&map, PosPlayer(player));
  while (input!=4){
      switch (input){
          case 1:
              scanf("%s",&username);
              break;
          case 2:
              //boolean CekUsername(char username[30],*gatau mau nyimpen nama2 user dimana*)
              printf("Masukkan command\n");
              scanf("%s", command.TabKata);
              while (!IsKataSama(command,KataEXIT)){
                  if (IsKataSama(command, KataGU) || IsKataSama(command, KataGL) || IsKataSama(command, KataGD) || IsKataSama(command, KataGR)){
                      //fungsi GU/GL/GD/GR
                      move(&map, &(Absis(PosPlayer(player))), &(Ordinat(PosPlayer(player))), command);
                      TulisMATRIKS(map);
                      printf("\n");
                  }
                  else if (IsKataSama(command, KataORDER)){
                      //fungsi ORDER
                  }
                  else if (IsKataSama(command, KataPUT)){
                      //fungsi PUT
                  }
                  else if (IsKataSama(command, KataTAKE)){
                      //fungsi TAKE
                  }
                  else if (IsKataSama(command, KataCH)){
                      //fungsi CH
                  }
                  else if (IsKataSama(command, KataCT)){
                      //fungsi CT
                  }
                  else if (IsKataSama(command, KataPLACE)){
                      //fungsi PLACE
                  }
                  else if (IsKataSama(command, KataGIVE)){
                      //fungsi GIVE
                  }
                  else if (IsKataSama(command, KataRECIPE)){
                      //fungsi RECIPE
                  }
                  else if (IsKataSama(command, KataSAVE)){
                      //fungsi SAVE
                  }
                  else if (IsKataSama(command, KataLOAD)){
                      //fungsi LOAD
                  }
                  else {
                      printf("Command tidak valid. Silahkan input command lagi.\n");
                  }
                  scanf("%s", command.TabKata);
              }
              if (IsKataSama(command,KataEXIT)){
                  input=4;
              }
              break;
          case 3:
              break;
      }
  }

  if (input==4){
      printf("Permainan berakhir! Sampai jumpa!\n");
      printf("    CREDITS:\n");
      printf("    Afviany Ryzki\n");
      printf("    I Pute Gede Wirasuta\n");
      printf("    Kintan Sekar Adinda\n");
      printf("    M. Rifky I Bariansyah\n");
      printf("    Pandyaka Aptanagi\n");
      printf("    Raihan Asyraf\n");
  }
  return 0;
}
