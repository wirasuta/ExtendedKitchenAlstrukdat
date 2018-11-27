#include "process.h"
#include <stdio.h>
#include <stdlib.h>

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
        StatOrder(OrderC(C)) = '!';
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

void PutToTray(Player *P, BinTree *Adr, POINT T){
    boolean check;
    Stack checkStack,Temp;
    Kata food;
    BinTree C_Food;

    if(IsNearTray(*P,T)) {
        check = true;
        C_Food = *Adr;

        //BUG : Infinite Loop, Fungsi IsNearTray sudah benar
        CreateEmptyStack(&checkStack);
        CreateEmptyStack(&Temp);
        while(!IsStackEmpty(OnHand(*P))) {
            Pop(&OnHand(*P),&food);
            Push(&checkStack,food);
            Push(&Temp,food);
            printf("%s\n", food.TabKata);
        }

        while((!check) || (!IsTreeEmpty(C_Food)) || (!IsStackEmpty(checkStack))) {
                if(IsKataSama(InfoTop(checkStack),Akar(C_Food))) {
                    Pop(&checkStack,&food);
                    if(IsKataSama(Akar(Left(C_Food)), food)) {
                        C_Food = Left(C_Food);
                    } else {
                        C_Food = Right(C_Food);
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
        printf("GAGAL MEMBUAT MAKANAN!!!\n");

    } else {
        if(!IsBiner(C_Food)) {
            Push(&OnTray(*P),Akar(Left(C_Food)));
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
    double Koef;
    int NoTable;

    if (IsAbleGive(*P,*R)){
        Pop(&OnTray(*P),&orinput);
        Koef = Level(RTree,orinput);
        Money(*G) += (NormalPrice * Koef);
        NoTable = GetTableNumber(*P,*R);
        IsOccupied(TableNo(*R,NoTable)) = false;
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
