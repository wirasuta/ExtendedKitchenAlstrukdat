#include "ADT/Header/array.h"
#include "ADT/Header/jam.h"
#include "ADT/Header/listlinier.h"
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
BinTree recipeTree;
LocTray locationTray;

//Variabel untuk coba2
Customer ujiCustomer;
Ingredients ujiIngredient;


int main(int argc, char const *argv[]) {
  int input;
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
  InitRoom(&Room1);
  InitPlayer(&player);
  InitMap(&Room1, PosPlayer(player));

  //Inisialisasi Ujicoba
  IsStar(ujiCustomer) = false;
  TimeQueue(ujiCustomer) = 30;
  TimeWaiting(ujiCustomer) = 30;
  CustomerCount(ujiCustomer) = 2;
  PosCustomer(ujiCustomer) = MakePOINT(0, 0);
  StatOrder(OrderC(ujiCustomer)) = '#';
  OrderName(OrderC(ujiCustomer)).TabKata[0] = 'P';
  OrderName(OrderC(ujiCustomer)).TabKata[1] = 'I';
  OrderName(OrderC(ujiCustomer)).TabKata[2] = 'R';
  OrderName(OrderC(ujiCustomer)).TabKata[3] = 'I';
  OrderName(OrderC(ujiCustomer)).TabKata[4] = 'N';
  OrderName(OrderC(ujiCustomer)).TabKata[5] = 'G';
  NoTableOrder(OrderC(ujiCustomer)) = 0;

  CreateEmptyQueue(&waitingList, 20);
  AddQueue(&waitingList, ujiCustomer);

  buildRecipe(&recipeTree);

  PosTray(locationTray) = MakePOINT(8, 1);

  IngName(ujiIngredient).TabKata[0] = 'P';
  IngName(ujiIngredient).TabKata[1] = 'I';
  IngName(ujiIngredient).TabKata[2] = 'R';
  IngName(ujiIngredient).TabKata[3] = 'I';
  IngName(ujiIngredient).TabKata[4] = 'N';
  IngName(ujiIngredient).TabKata[5] = 'G';
  IngName(ujiIngredient).Length = 6;

  Push(&(OnHand(player)), ujiCustomer.Food.Name);

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
                    printf("\n");
                    randomCustomer(player, &waitingList);
                    printf("player tick: %d\n", PlayerTick(player));
                    printf("\n");
                    printf("N Queue: %d\n", NBElmtQueue(waitingList));
                    
                    PlayerTick(player)++;
                    
                    printf("%d\n", IsOccupied(TableNo(Room1, 1)));
                }
                else if (IsKataSama(command, KataORDER)){

                    //fungsi ORDER
                    //TODO: Update fungsi dan cari indeks kosong
                    TakeOrder(&player, &ujiCustomer, Room1, &(OrderList(player)));
                    TulisIsiTab(OrderList(player));
                    
                    PlayerTick(player)++;
                }
                else if (IsKataSama(command, KataPUT)){
                    //fungsi PUT
                    PutToTray(&player, &recipeTree, locationTray);
                    
                    PlayerTick(player)++;
                }
                else if (IsKataSama(command, KataTAKE)){
                    //fungsi TAKE
                    TakeIngredient(&player, ujiIngredient);
                    
                    PlayerTick(player)++;
                }
                else if (IsKataSama(command, KataCH)){
                    ClearStack(&(OnHand(player)));
                    PlayerTick(player)++;
                }
                else if (IsKataSama(command, KataCT)){
                    ClearStack(&(OnTray(player)));
                    PlayerTick(player)++;
                }
                else if (IsKataSama(command, KataPLACE)){
                    PlaceCustomer(player, &waitingList, &Room1);
                    PlayerTick(player)++;
                    
                    printf("%d\n", IsOccupied(TableNo(Room1, 1)));
                }
                else if (IsKataSama(command, KataGIVE)){
                    //fungsi GIVE
                    GiveFood(&player, ujiCustomer, &Room1, &gameData, recipeTree);
                    PlayerTick(player)++;                    
                }
                else if (IsKataSama(command, KataRECIPE)){
                    //fungsi RECIPE
                    PrintRecipe(recipeTree, 2);
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

  if (input==4){
      printf("Permainan berakhir! Sampai jumpa!\n");
      printf("    CREDITS:\n");
      printf("    Ainun Fitryh Vianiryzki\n");
      printf("    I Pute Gede Wirasuta\n");
      printf("    Kintan Sekar Adinda\n");
      printf("    M. Rifky I Bariansyah\n");
      printf("    Pandyaka Aptanagi\n");
      printf("    Raihan Asyraf\n");
  }
  return 0;
}

