#include "process.h"
#include <stdio.h>
#include <stdlib.h>

boolean pathFilled(MATRIKS M ,int X, int Y)
{
    return ((MatElmt(M, X, Y) == 'X') || (MatElmt(M, X, Y) == 'M') || (MatElmt(M, X, Y) == 'T') || (MatElmt(M, X, Y) == 'C') || (MatElmt(M, X, Y) == '1') || (MatElmt(M, X, Y) == '2') || (MatElmt(M, X, Y) == '3') || (MatElmt(M, X, Y) == '4'));
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
              *roomID = RoomNumber(NextRoom(nextRoom));
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
        else if ( (*X+1) > RestoSizeM )
        {
          int i=0;
          adrEdgeNode nextRoom = Nil;
          while (i<=4 && nextRoom==Nil) {
            i++;
            nextRoom = SearchEdgeNode(RoomGraph(gameData), MakePOINT(*X,*Y), *roomID, i);
          }
          if (nextRoom != Nil) {
            *roomID = RoomNumber(NextRoom(nextRoom));
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
            *roomID = RoomNumber(NextRoom(nextRoom));
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
        else if ( (*Y+1) > RestoSizeN )
        {
          int i=0;
          adrEdgeNode nextRoom = Nil;
          while (i<=4 && nextRoom==Nil) {
            i++;
            nextRoom = SearchEdgeNode(RoomGraph(gameData), MakePOINT(*X,*Y), *roomID, i);
          }
          if (nextRoom != Nil) {
            *roomID = RoomNumber(NextRoom(nextRoom));
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

boolean IsNearTable (Player P, Room R){
    boolean check;
    int i,j;
    Table T;

    check = false;

    i = 1;
    while ((i<=4) && (check != true)){
        T = TableNo(R,i);
        j = 0;
        while((j<=Capacity(T)) && (check != true)){
            // Cek deket kursi/meja atau tidak
            if(EQ(PosTable(T,j),PlusDelta(PosPlayer(P),-1,0)) || EQ(PosTable(T,j),PlusDelta(PosPlayer(P),1,0))
               || EQ(PosTable(T,j),PlusDelta(PosPlayer(P),0,-1)) || EQ(PosTable(T,j),PlusDelta(PosPlayer(P),0,1))){
                check = true;
            } else {
                j++;
            }
        }
        i++;
    }
    return(check);
}

int GetTableNumber(Player P, Room R){
    int i,j;
    Table T;
    boolean check = false;
    i=0;
    while ((i<=4) && (check != true)){
        T = TableNo(R,i);
        j = 0;
        while((j<=Capacity(T)) && (check != true)){
            if(EQ(PosTable(T,j),PlusDelta(PosPlayer(P),-1,0)) || EQ(PosTable(T,j),PlusDelta(PosPlayer(P),1,0))
               || EQ(PosTable(T,j),PlusDelta(PosPlayer(P),0,-1)) || EQ(PosTable(T,j),PlusDelta(PosPlayer(P),0,1))){
                check = true;
            } else {
                j++;
            }
        }
        if (!check){
          i++;
        }
    }
    return i;
}

boolean IsNearTray(Player P, POINT T){
    return (EQ(PosPlayer(P),PlusDelta(T,-1,0)) || EQ(PosPlayer(P),PlusDelta(T,1,0))
               || EQ(PosPlayer(P),PlusDelta(T,0,-1)) || EQ(PosPlayer(P),PlusDelta(T,0,1)));
}

boolean IsAbleOrder(Player P, Room R){
    boolean check;
    Customer C;
    int NoTable;

    check = false;
    if (IsNearTable(P,R)){
        NoTable = GetTableNumber(P,R);
        C = CustomerSeat(TableNo(R,NoTable));
        if(StatOrder(OrderC(C)) == '#'){
            check = true;
        }
    }

    return(check);
}
//mengembalikas true jika player bisa megambil orderan dari customer,
//yaitu jika player berada di samping customer

boolean IsAbleGive(Player P, Room R){
    boolean check;
    Customer C;
    int NoTable;

    check = false;
    if (IsNearTable(P,R)) {
        NoTable = GetTableNumber(P,R);
        C = CustomerSeat(TableNo(R,NoTable));
        if(StatOrder(OrderC(C)) == '!' && IsKataSama(InfoTop(OnTray(P)),OrderName(OrderC(C)))) {
            check = true;
        }
    }

    return(check);
}
//mengembalikas true jika player bisa memberikan makanan ke customer
//yaitu jika player berada di samping customer

boolean IsAbleTake(Player P, Room R){
    boolean check=false;
    int i;

    i = 0;
    while ((i<NIngredient) && (!check)){
          if(EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),-1,0)) || EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),1,0))
             || EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),0,-1)) || EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),0,1))){
              check = true;
          } else {
              i++;
          }
    }
    return(check);
}
//mengembalikas true jika player bisa mengambil bahan makanan atau tidak
//yaitu jika player berada di samping customer

Ingredients GetIngrendient(Player P, Room R){
    boolean check=false;
    int i;

    i = 0;
    while ((i<NIngredient) && (!check)){
          if(EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),-1,0)) || EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),1,0))
             || EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),0,-1)) || EQ(PosIngredients(Ingredient(R, i)),PlusDelta(PosPlayer(P),0,1))){
              check = true;
          } else {
              i++;
          }
    }
    return(Ingredient(R, i));
}

boolean IsAblePlace(Player P, Customer C, Room R){
    boolean check;
    int NoTable;

    check = false;

    if(IsNearTable(P,R)){
        NoTable = GetTableNumber(P,R);
        if(IsOccupied(TableNo(R,NoTable)) == false) {
            if(CustomerCount(C) <= Capacity(TableNo(R,NoTable))) {
                check = true;
            }
        }
    }
    return(check);

}
//mengembalikas true jika player bisa menempatkan customer ke meja kosong
//yaitu jika player berada di samping meja dan sesuai dengan kapasitas


void ClearStack(Stack *S){
    CreateEmptyStack(S);
}
//membuang seluruh bahan makanan yang ada di tangan maupun di tray
// digunakan untuk CH dan CT

void TakeOrder(Player *P, Room *R){
    Customer C;
    int NoTable;

    if (IsAbleOrder(*P,*R)) {
        NoTable = GetTableNumber(*P,*R);
        C = CustomerSeat(TableNo(*R,NoTable));
        NoTableOrder(OrderC(C)) = NoTable;
        OrderName(OrderC(C)) = OrderCName(C);
        AddAsLastEl(&(OrderList(*P)),OrderC(C));
        OrderCStatus(CustomerSeat(TableNo(*R,NoTable))) = '!';
    } else {
        printf("GAGAL MENGAMBIL ORDER !!!\n");
    }
}
//I.S. sembarang
//F.S mengupdate status Player dan Customer
//Proses: mengambil order customer, cek terlebih dahulu apakah player
//        bersebelahan denga customer, cek status order, jika valid masukkan
//        ke array order

void PlaceCustomer (Player P, CustQueue *Q, Room *R) {
    Customer CustTemp;
    int NoTable;

    if (!IsQueueEmpty(*Q)) {
        int countermax = NBElmtQueue(*Q);
        int counter = 0;
        boolean placed = false;
        do {
            DelQueue(Q,&CustTemp);
            if(!IsAblePlace(P,CustTemp,*R) || placed) {
                AddQueue(Q,CustTemp);
                counter++;
            } else {
                NoTable = GetTableNumber(P,*R);
                TimeWaiting(CustTemp) = (rand() % (30 + 1 -20)) + 20;
                CustomerSeat(TableNo(*R,NoTable)) = CustTemp;
                IsOccupied(TableNo(*R,NoTable)) = true;
                placed = true;
                countermax--;
            }
        } while (counter != countermax);
    }else{
      printf("Tidak ada yang sedang mengantri, Ferguso\n");
    }
}

void PutToTray(Player *P, BinTree C_Food, POINT T){
    boolean check;
    Stack checkStack,Temp;
    Kata food;

    if(IsNearTray(*P,T)) {
        check = true;

        CreateEmptyStack(&checkStack);
        CreateEmptyStack(&Temp);
        while(!IsStackEmpty(OnHand(*P))) {
            Pop(&OnHand(*P),&food);
            Push(&checkStack,food);
            Push(&Temp,food);
        }

        while( check && !IsTreeEmpty(C_Food) && !IsStackEmpty(checkStack) ) {
            if(IsKataSama(InfoTop(checkStack),Akar(C_Food))) {
                Pop(&checkStack,&food);
                if (!IsStackEmpty(checkStack)) {
                  if(IsKataSama(Akar(Left(C_Food)), InfoTop(checkStack))) {
                    C_Food = Left(C_Food);
                  } else if(IsKataSama(Akar(Right(C_Food)), InfoTop(checkStack))){
                    C_Food = Right(C_Food);
                  }
                }
            } else {
                check = false;
            }
        }
    }
    if(check == false) {
        while(!IsStackEmpty(Temp)) {
            Pop(&Temp,&food);
            Push(&OnHand(*P),food);
        }
        printf("TIDAK SESUAI RESEP. GAGAL MEMBUAT MAKANAN!!!\n");

    } else {
        if(IsUnerLeft(C_Food)) {
            Push(&(OnTray(*P)),Akar(Left(C_Food)));
            CreateEmptyStack(&(OnHand(*P)));
        } else {
            printf("BAHAN MAKANAN KURANG LENGKAP!\n");
        }
    }
}
//I.S sembarang
//F.S Mengubah kondisi Tray, jika sesuai dengan Food tree, maka makanan
//    berhasil dibuat, makanan dimasukkan ke stack Tray

void TakeIngredient(Player *P, Room R){
    Ingredients Ig;

    if (IsAbleTake(*P,R)) {
        Ig = GetIngrendient(*P, R);
        Push(&(OnHand(*P)),IngName(Ig));
    } else {
        printf("GAGAL MENGAMBIL BAHAN MAKANAN !!!\n");
    }
}
//I.S sembarang
//F.S jika player bersebelahan dengan posisi bahan, maka mengambil bahan
//    dan menaruhnya dalam stack Hand

void GiveFood(Player *P, Room *R, Game *G,BinTree RTree){
    Kata orinput;
    Order Temp;
    double Koef;
    int NoTable;

    if (IsAbleGive(*P,*R)){
        Pop(&OnTray(*P),&orinput);
        Koef = Level(RTree,orinput);
        Money(*G) += (NormalPrice * Koef);
        NoTable = GetTableNumber(*P,*R);
        IsOccupied(TableNo(*R,NoTable)) = false;
        DelEli(&OrderList(*P), SearchIndex(OrderList(*P), NoTable, orinput), &Temp);
    } else {
        printf("GAGAL MEMBERIKAN ORDER MAKANAN !!!\n");
    }
}
//I.S sembarang
//F.S jika tumpukan paling atas sesuai dengan order customer yang bersebelahan
//    dengan player, maka makanan akan diberikan

void PrintRecipe(BinTree P,int H){
    PrintTree(P,H);
}

void TickOrder (Room *R){
    int i;
    Customer C;
    Table T;

    for(i=1;i<=NTable;i++){
        T = TableNo(*R,i);
        if(IsOccupied(T) == true){
            C = CustomerSeat(T);
            if(StatOrder(OrderC(C)) == '#'){
               TimeWaiting(CustomerSeat(TableNo(*R,i))) -= 1;
            }
        }
    }
}

void CheckTickOrder (Room *R, Game *G){
    int i;
    Customer C;
    Table T;

    for(i=1;i<=NTable;i++){
        T = TableNo(*R,i);
        if(IsOccupied(T) == true){
            C = CustomerSeat(T);
            if(TimeWaiting(C) == 0 ){
              Life(*G) -=1;
              IsOccupied(TableNo(*R,i)) = false;
              OrderCStatus(CustomerSeat(TableNo(*R, i))) = '$';
            }
        }
    }
}

void TickGame(Game *G, Player *P, CustQueue *waitingList){
  PlayerTick(*P)++;
  //counter customer ngantri
  addTick(waitingList);
  del0Tick(waitingList);
  int i;
  for (i = 1; i <=4 ; i++) {
    TickOrder(&Ruang(*G, i));
    CheckTickOrder(&(Ruang(*G, i)), G);
  }
  randomCustomer(*P, waitingList);
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
    Customer C;
    //boolean tickCount;
    if (PlayerTick(P) == NextCustomerArr){
        NextCustomerArr = PlayerTick(P) + (rand() % 10);
        returnCustomer(&C, rand() % 8);
        AddQueue(Q, C);
    }
}
