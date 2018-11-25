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
BinTree recipeTree;
LocTray locationTray;

//Variabel untuk coba2
Customer ujiCustomer;
Ingredients ujiIngredient;

void returnCustomer(Customer *C, int N);

void randomCustomer(Player P, CustQueue *Q);

int randomInteger();

boolean checkPlayerTick(Player P);


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
                }
                else if (IsKataSama(command, KataORDER)){

                    //fungsi ORDER
                    //TODO: Update fungsi dan cari indeks kosong
                    TakeOrder(&player, &ujiCustomer, Room1, &(OrderList(player)));
                    TulisIsiTab(OrderList(player));
                }
                else if (IsKataSama(command, KataPUT)){

                    //fungsi PUT
                    PutToTray(&player, &recipeTree, locationTray);
                }
                else if (IsKataSama(command, KataTAKE)){

                    //fungsi TAKE
                    TakeIngredient(&player, ujiIngredient);
                }
                else if (IsKataSama(command, KataCH)){

                    ClearStack(&(OnHand(player)));
                }
                else if (IsKataSama(command, KataCT)){

                    ClearStack(&(OnTray(player)));
                }
                else if (IsKataSama(command, KataPLACE)){

                    PlaceCustomer(player, &waitingList, &Room1);
                }
                else if (IsKataSama(command, KataGIVE)){

                    //fungsi GIVE
                    GiveFood(&player, ujiCustomer, &Room1, &gameData, recipeTree);
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
        random = randomInteger();
        returnCustomer(&C, random);
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

    return((PlayerTick(P) % 15) == random);
}
