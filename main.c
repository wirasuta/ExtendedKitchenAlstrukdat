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
#include "Tubes BETA 1.0/move.h"
#include "Tubes BETA 1.0/process.h"
#include "Tubes BETA 1.0/command.h"

int main(int argc, char const *argv[]) {
  int input;
  char username[100];
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
                  if (IsKataSama(command, KataGU)){
                    //fungsi GU
                    printf("Berhasil Go Up\n");
                  }
                  else if (IsKataSama(command, KataGD)){
                      //fungsi GD
                      printf("Berhasil Go Down\n");
                  }
                  else if (IsKataSama(command, KataGL)){
                      //fungsi GL
                      printf("Berhasil Go Left\n");
                  }
                  else if (IsKataSama(command, KataGR)){
                      //fungsi GR
                      printf("Berhasil Go Right\n");
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
                      printf("%s\n", command.TabKata);
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
