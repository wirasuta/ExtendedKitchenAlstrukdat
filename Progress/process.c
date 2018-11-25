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
        j = 1;
        while((j<=4) && (check != true)){
            // Cek deket kursi atau tidak
            if((Absis(PosPlayer(P)) == Absis(PosTable(T,i)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTable(T,i)) - 1) ||
            (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) - 1)){
                check = true;
            } else {
                j++;
            }
        }
    }

    return(check);
}

int GetTableNumber(Player P, Room R){
    int i;
    Table T;
    boolean check = false;

    if(IsNearTable(P,R)){
        i = 1;
        while((i<=4) && (check != true)){
            T = TableNo(R,i);
            if(EQ(PosTable(T,i),PlusDelta(PosPlayer(P),-2,0)) || EQ(PosTable(T,i),PlusDelta(PosPlayer(P),2,0))
               || EQ(PosTable(T,i),PlusDelta(PosPlayer(P),0,-2)) || EQ(PosTable(T,i),PlusDelta(PosPlayer(P),0,2))){
                check = true;
            }else{
                i++;
            }
        }
    }

    return i;
}

boolean IsNearTray(Player P, LocTray T){
    return ((Absis(PosPlayer(P)) == Absis(PosTray(T)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTray(T)) - 1) ||
           (Ordinat(PosPlayer(P)) == Ordinat(PosTray(T)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTray(T)) - 1));
}

boolean IsAbleOrder(Player P, Customer C, Room R){
    boolean check;

    check = false;
    if (IsNearTable(P,R)){
        if(StatOrder(OrderC(C)) == '#'){
            check = true;
        }
    }

    return(check);
}
//mengembalikas true jika player bisa megambil orderan dari customer,
//yaitu jika player berada di samping customer

boolean IsAbleGive(Player P, Customer C, Room R){
    boolean check;

    check = false;
    if (IsNearTable(P,R)) {
        if(StatOrder(OrderC(C)) == '!' && IsKataSama(InfoTop(OnTray(P)),OrderName(OrderC(C)))) {
            check = true;
        }
    }

    return(check);
}
//mengembalikas true jika player bisa memberikan makanan ke customer
//yaitu jika player berada di samping customer

boolean IsAbleTake(Player P, Ingredients Bahan){
    boolean check;

    check = false;

    if ((Absis(PosPlayer(P)) == Absis(PosIngredients(Bahan)) + 1) || (Absis(PosPlayer(P)) == Absis(PosIngredients(Bahan)) - 1) ||
        (Ordinat(PosPlayer(P)) == Ordinat(PosIngredients(Bahan)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosIngredients(Bahan)) - 1)){
               check = true;
        }

    return(check);

}
//mengembalikas true jika player bisa mengambil bahan makanan atau tidak
//yaitu jika player berada di samping customer

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

void TakeOrder(Player *P, Customer *C, Room R, TabOrder *T){

    if (IsAbleOrder(*P,*C,R)) {
        AddAsLastEl(T,OrderC(*C));
        StatOrder(OrderC(*C)) = '!';
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
        do {
            DelQueue(Q,&CustTemp);
            if(!IsAblePlace(P,InfoHead(*Q),*R)) {
                AddQueue(Q,CustTemp);
            } else {
                NoTable = GetTableNumber(P,*R);
                CustomerSeat(TableNo(*R,NoTable)) = CustTemp;
                IsOccupied(TableNo(*R,NoTable)) = true;
            }
        } while (CustomerCount(CustTemp) != CustomerCount(InfoTail(*Q)));
        if(IsAblePlace(P,InfoTail(*Q),*R)) {
            DelQueue(Q,&CustTemp);
            CustomerSeat(TableNo(*R,NoTable)) = CustTemp;
            IsOccupied(TableNo(*R,NoTable)) = true;
        }
    }
}

void PutToTray(Player *P, BinTree *Adr, LocTray T){
    boolean check;
    Stack checkStack,Temp;
    Kata food;
    BinTree C_Food;

    if(IsNearTray(*P,T)) {
        check = true;
        C_Food = *Adr;

        CreateEmptyStack(&checkStack);
        CreateEmptyStack(&Temp);
        while(!IsStackEmpty(OnHand(*P))) {
            Pop(&OnHand(*P),&food);
            Push(&checkStack,food);
            Push(&Temp,food);
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

void TakeIngredient(Player *P, Ingredients Bahan){

    if (IsAbleTake(*P,Bahan)) {
        Push(&OnHand(*P),IngName(Bahan));
    } else {
        printf("GAGAL MENGAMBIL BAHAN MAKANAN !!!/n");
    }
}
//I.S sembarang
//F.S jika player bersebelahan dengan posisi bahan, maka mengambil bahan
//    dan menaruhnya dalam stack Hand

void GiveFood(Player *P, Customer C, Room *R, Game *G,BinTree RTree){
    Kata orinput;
    double Koef;
    int NoTable;

    if (IsAbleGive(*P,C,*R)){
        Pop(&OnTray(*P),&orinput);
        Koef = Level(RTree,orinput);
        Money(*G) += (NormalPrice * Koef);
        NoTable = GetTableNumber(*P,*R);
        IsOccupied(TableNo(*R,NoTable)) = false;
    } else {
        printf("GAGAL MEMBERIKAN ORDER MAKANAN !!!/n");
    }
}
//I.S sembarang
//F.S jika tumpukan paling atas sesuai dengan order customer yang bersebelahan
//    dengan player, maka makanan akan diberikan

void PrintRecipe(BinTree P,int H){
    PrintTree(P,H);
}

void TickOrder (Room R,Customer *C){
    int i;
    Table T;

    for(i=1;i<=NTable;i++){
        T = TableNo(R,i);
        if(IsOccupied(T) == true){
            *C = CustomerSeat(T);
            if(StatOrder(OrderC(*C)) == '#'){
               TimeWaiting(*C) -= 1;
            }
        }
    }
}
