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
Room Room1;
Game gameData;
Player player;
CustQueue waitingList;

//Variabel untuk coba2
Customer UjiCustomer;

int main(int argc, char const *argv[]) {
  int input;
  Kata command;

  printf("(1)New Game\n");
  printf("(2)Start Game\n");
  printf("(3)Load Game\n");
  printf("(4)Exit\n");

  //Input Main Menu
  scanf("%d",&input);
  while ((input!=1)&&(input!=2)&&(input!=3)&&(input!=4)){
      printf("Inputan salah. Silahkan input angka yang valid.\n");
      scanf("%d",&input);
  }

  //Inisialisasi
  InitKataCommand();
  InitGame(&gameData);
  InitRoom(&Room1);
  InitPlayer(&player);
  InitMap(&Room1, PosPlayer(player));

  //Inisialisasi Ujicoba
  IsStar(UjiCustomer) = false;
  TimeQueue(UjiCustomer) = 30;
  TimeWaiting(UjiCustomer) = 30;
  CustomerCount(UjiCustomer) = 2;

  CreateEmptyQueue(&waitingList, 20);
  AddQueue(&waitingList, UjiCustomer);

  while (input!=4){
      switch (input){
        case 3:
            //TODO : Load file
            input = 2;
            break;
        case 1:
            printf("Masukkan username : ");
            scanf("%s",ElmtName(gameData).TabKata);
            SetKataLength(&(ElmtName(gameData)));
            input = 2;
            break;
        case 2:
            if (ElmtName(gameData).Length == 0) {
              printf("Anda belum memasukkan username! Masukkan username : ");
              scanf("%s",ElmtName(gameData).TabKata);
              SetKataLength(&(ElmtName(gameData)));
            }

            //Kondisi Awal, TODO: Bikin fungsi draw yang dipanggil setiap setelah pemanggilan fungsi
            TulisMATRIKS(Layout(Room1)); printf("\n");
            printf("Masukkan command: ");

            //Loop utama game
            scanf("%s", command.TabKata);
            while (!IsKataSama(command,KataEXIT)){
                if (IsKataSama(command, KataGU) || IsKataSama(command, KataGL) || IsKataSama(command, KataGD) || IsKataSama(command, KataGR)){
                    //fungsi GU/GL/GD/GR
                    move(&(Layout(Room1)), &(Absis(PosPlayer(player))), &(Ordinat(PosPlayer(player))), command);
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
                    ClearStack(&(OnHand(player)));
                }
                else if (IsKataSama(command, KataCT)){
                    ClearStack(&(OnTray(player)));
                }
                else if (IsKataSama(command, KataPLACE)){
                    printf("%d\n", CustomerCount(InfoHead(waitingList)));
                    printf("%d\n", TimeQueue(InfoHead(waitingList)));
                    printf("Placing customer\n");
                    PlaceCustomer(player, &waitingList, &(TableNo(Room1, 2)));
                    printf("Done\n");
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
                else if (IsKataSama(command, KataEXIT)){
                    //Ngapain ni pas exit
                }
                else {
                    printf("Command tidak valid. Silahkan input command lagi.\n");
                }
                InitMap(&Room1, PosPlayer(player));
                TulisMATRIKS(Layout(Room1));
                printf("\n");

                printf("Masukkan command: ");
                scanf("%s", command.TabKata);
            }
            input = 4;
            break;
      }
  }

  //Game over/Exit. Show Credit
  printf("Permainan berakhir! Sampai jumpa!\n");
  printf("    CREDITS:\n");
  printf("    Afviany Ryzki\n");
  printf("    I Pute Gede Wirasuta\n");
  printf("    Kintan Sekar Adinda\n");
  printf("    M. Rifky I Bariansyah\n");
  printf("    Pandyaka Aptanagi\n");
  printf("    Raihan Asyraf\n");

  return 0;
}
