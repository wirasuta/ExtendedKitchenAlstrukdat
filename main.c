#include "ADT/Header/array.h"
#include "ADT/Header/jam.h"
#include "ADT/Header/roomgraph.h"
#include "ADT/Header/matriks.h"
#include "ADT/Header/mesinkar.h"
#include "ADT/Header/mesinkata.h"
#include "ADT/Header/point.h"
#include "ADT/Header/queue.h"
#include "ADT/Header/stackt.h"
#include "ADT/Header/bintree.h"
#include "ADT/Header/tepokpramuka_type.h"
#include "Functions/process.h"
#include "Functions/initialize.h"
#include "Functions/draw.h"

Kata KataGU, KataGD, KataGL, KataGR, KataORDER, KataPUT, KataTAKE, KataCH, KataCT;
Kata KataPLACE, KataGIVE, KataRECIPE, KataSAVE, KataLOAD, KataEXIT;
Game gameData;
Player player;
CustQueue waitingList;
BinTree recipeTree;

//Variabel untuk coba2
Customer ujiCustomer;
Ingredients ujiIngredient;


int main(int argc, char const *argv[]) {
  int input;
  Kata command;

  print_title();
  print_menu();

  scanf("%d",&input);
  while ((input!=1)&&(input!=2)&&(input!=3)&&(input!=4)){
      printf("Inputan salah. Silahkan input angka yang valid.\n");
      scanf("%d",&input);
  }
  InitKataCommand();
  InitGame(&gameData);
  InitPlayer(&player);
  int roomCount;
  for (roomCount = 1; roomCount <= 4; roomCount++) {
    if (RoomID(player)==roomCount) {
      InitMap(&(Ruang(gameData, roomCount)), PosPlayer(player));
    } else {
      InitMap(&(Ruang(gameData, roomCount)), MakePOINT(0, 0));
    }
    RoomStructID(Ruang(gameData, roomCount)) = roomCount;
  }

  CreateEmptyQueue(&waitingList, 20);

  buildRecipe(&recipeTree);

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
            TulisMATRIKS(Layout(Ruang(gameData, RoomID(player)))); printf("\n");
            printf("Masukkan command: ");

            //Loop utama game
            scanf("%s", command.TabKata);
            while (!IsKataSama(command,KataEXIT)){
                if (IsKataSama(command, KataGU) || IsKataSama(command, KataGL) || IsKataSama(command, KataGD) || IsKataSama(command, KataGR)){

                    //fungsi GU/GL/GD/GR
                    move(&(Layout(Ruang(gameData, RoomID(player)))), &(Absis(PosPlayer(player))), &(Ordinat(PosPlayer(player))), command, &(RoomID(player)));
                    printf("\n");
                    randomCustomer(player, &waitingList);
                    printf("player tick: %d\n", PlayerTick(player));
                    printf("\n");
                    printf("N Queue: %d\n", NBElmtQueue(waitingList));

                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                }
                else if (IsKataSama(command, KataORDER)){

                    //fungsi ORDER
                    TakeOrder(&player, &(Ruang(gameData, RoomID(player))));

                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
                }
                else if (IsKataSama(command, KataPUT)){
                    //fungsi PUT
                    PutToTray(&player, recipeTree, PosTray(Ruang(gameData, RoomID(player))));

                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
                }
                else if (IsKataSama(command, KataTAKE)){
                    //fungsi TAKE
                    TakeIngredient(&player, Ruang(gameData, RoomID(player)));

                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
                }
                else if (IsKataSama(command, KataCH)){
                    ClearStack(&(OnHand(player)));
                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
                }
                else if (IsKataSama(command, KataCT)){
                    ClearStack(&(OnTray(player)));
                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
                }
                else if (IsKataSama(command, KataPLACE)){
                    PlaceCustomer(player, &waitingList, &(Ruang(gameData, RoomID(player))));
                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
                }
                else if (IsKataSama(command, KataGIVE)){
                    //fungsi GIVE
                    GiveFood(&player, &(Ruang(gameData, RoomID(player))), &gameData, recipeTree);
                    PlayerTick(player)++;
                    //counter customer ngantri
                    addTick(&waitingList);
                    del0Tick(&waitingList);
                    CheckTickOrder(&(Ruang(gameData, RoomID(player))));
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
                    //keluar windows
                }
                else {
                    printf("Command tidak valid. Silahkan input command lagi.\n");
                }
                for (roomCount = 1; roomCount <= 4; roomCount++) {
                  if (RoomID(player)==roomCount) {
                    InitMap(&(Ruang(gameData, roomCount)), PosPlayer(player));
                  } else {
                    InitMap(&(Ruang(gameData, roomCount)), MakePOINT(0, 0));
                  }
                }
                printf("Chef Engi berada di ruang %d\n", RoomID(player));
                TulisMATRIKS(Layout(Ruang(gameData, RoomID(player))));
                printf("\n");

                printf("DUIT : %.1f",Money(gameData)); printf("\n");

                printf("ANTRIAN PELANGGAN : ");
                PrintQueue(waitingList); printf("\n");

                printf("ORDERAN PELANGGAN : ");
                TulisIsiTab(OrderList(player));
                printf("\n");

                printf("ISI HAND : ");
                PrintStack(OnHand(player)); printf("\n");

                printf("ISI TRAY : ");
                PrintStack(OnTray(player)); printf("\n");

                printf("Masukkan command: ");
                scanf("%s", command.TabKata);
            }
            input = 4;
            break;
      }
  }
  print_credits();
  return 0;
}
