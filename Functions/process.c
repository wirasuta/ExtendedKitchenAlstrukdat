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
                TimeWaiting(CustTemp) = (rand()%(35+1-30))+30;
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
               TimeWaiting(C) -= 1;
            }
        }
    }
}

void CheckTickOrder (Room *R){
    int i;
    Customer C;
    Table T;

    for(i=1;i<=NTable;i++){
        T = TableNo(*R,i);
        if(IsOccupied(T) == true){
            C = CustomerSeat(T);
            if(TimeWaiting(C) == 0 ){
               IsOccupied(T) = false;
            }
        }
    }
}
