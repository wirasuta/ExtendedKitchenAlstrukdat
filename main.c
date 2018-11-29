#include <time.h>
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

int main(int argc, char const *argv[]) {
  char input_raw;
  int input;
  Kata command;
  //Display Main Menu
  print_title();
  print_menu();

  //Input Main Menu
  scanf("%c", &input_raw);
  while ((input_raw!='1') && (input_raw!='2') && (input_raw!='3') && (input_raw!='4')){
      printf("Inputan salah. Silahkan input angka yang valid.\n");
      scanf("%c",&input_raw);
  }
  input = input_raw-'0';

  //Game Initialization
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
  srand(time(NULL));

  while (input!=4){
      switch (input){
        case 3:
            //TODO : Load file
            input = 2;
            break;
        case 1:
            printf("                                      Masukkan username : ");
            scanf("%s",ElmtName(gameData).TabKata);
            SetKataLength(&(ElmtName(gameData)));
        case 2:
            if (ElmtName(gameData).Length == 0) {
              printf("                    Anda belum memasukkan username! Masukkan username : ");
              scanf("%s",ElmtName(gameData).TabKata);
              SetKataLength(&(ElmtName(gameData)));
            }

            //Input pertama kali
            print_game();
            printf("Masukkan command: ");
            scanf("%s", command.TabKata);

            //Game Loop
            while (!IsKataSama(command,KataEXIT) && Life(gameData)!=0){
                if (IsKataSama(command, KataGU) || IsKataSama(command, KataGL) || IsKataSama(command, KataGD) || IsKataSama(command, KataGR)){

                    //fungsi GU/GL/GD/GR
                    move(&(Layout(Ruang(gameData, RoomID(player)))), &(Absis(PosPlayer(player))), &(Ordinat(PosPlayer(player))), command, &(RoomID(player)));
                    printf("\n");
                    TickGame(&gameData, &player, &waitingList);
                }
                else if (IsKataSama(command, KataORDER)){
                    //fungsi ORDER
                    TakeOrder(&player, &(Ruang(gameData, RoomID(player))));
                    TickGame(&gameData, &player, &waitingList);
                }
                else if (IsKataSama(command, KataPUT)){
                    //fungsi PUT
                    PutToTray(&player, recipeTree, PosTray(Ruang(gameData, RoomID(player))));
                    TickGame(&gameData, &player, &waitingList);
                }
                else if (IsKataSama(command, KataTAKE)){
                    //fungsi TAKE
                    TakeIngredient(&player, Ruang(gameData, RoomID(player)));
                    TickGame(&gameData, &player, &waitingList);
                }
                else if (IsKataSama(command, KataCH)){
                    ClearStack(&(OnHand(player)));
                }
                else if (IsKataSama(command, KataCT)){
                    ClearStack(&(OnTray(player)));
                }
                else if (IsKataSama(command, KataPLACE)){
                    PlaceCustomer(player, &waitingList, &(Ruang(gameData, RoomID(player))));
                    TickGame(&gameData, &player, &waitingList);
                }
                else if (IsKataSama(command, KataGIVE)){
                    //fungsi GIVE
                    GiveFood(&player, &(Ruang(gameData, RoomID(player))), &gameData, recipeTree);
                    TickGame(&gameData, &player, &waitingList);
                }
                else if (IsKataSama(command, KataRECIPE)){
                    //fungsi RECIPE
                    PrintRecipe(recipeTree, 2);
                }
                else if (IsKataSama(command, KataSAVE)){
                    //fungsi SAVE
                    printf("Command belum diimplementasikan. Silahkan input command lagi.\n");
                }
                else if (IsKataSama(command, KataLOAD)){
                    //fungsi LOAD
                    printf("Command belum diimplementasikan. Silahkan input command lagi.\n");
                }
                else if (IsKataSama(command, KataEXIT)){
                    printf("Gudbai.\n");
                }
                else {
                    printf("Command tidak valid. Silahkan input command lagi.\n");
                }
                if (!(IsKataSama(command, KataRECIPE))) {
                  //Update Room
                  for (roomCount = 1; roomCount <= 4; roomCount++) {
                    if (RoomID(player)==roomCount) {
                      InitMap(&(Ruang(gameData, roomCount)), PosPlayer(player));
                    } else {
                      InitMap(&(Ruang(gameData, roomCount)), MakePOINT(0, 0));
                    }
                  }
                  //Input Again
                  print_game();
                }
                printf("Masukkan command: ");
                scanf("%s", command.TabKata);
            }
            if (Life(gameData)==0) {
              printf("You Lose!\n");
            }
            input = 4;
            break;
      } //Switch Case Ends
  } //While Ends
  print_credits();
  return 0;
}
