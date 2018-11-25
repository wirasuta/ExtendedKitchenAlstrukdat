#include "process.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsNearTable (Player P, Table T){
    boolean check;
    int i;

    check = false;

    i = 0;
    while ((i<IdxMax) || (check == true)){
        if((Absis(PosPlayer(P)) == Absis(PosTable(T,i)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTable(T,i)) - 1) ||
           (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) - 1)){
            check = true;
        } else {
            i++;
        }
    }

    return(check);
}

boolean IsNearTray(Player P, LocTray T){
    return ((Absis(PosPlayer(P)) == Absis(PosTray(T)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTray(T)) - 1) ||
           (Ordinat(PosPlayer(P)) == Ordinat(PosTray(T)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTray(T)) - 1));
}

boolean IsAbleOrder(Player P, Customer C, Table T){
    boolean check;

    check = false;
    if (IsNearTable(P,T)){
        if(StatOrder(OrderC(C)) == '#'){
            check = true;
        }
    }

    return(check);
}
//mengembalikas true jika player bisa megambil orderan dari customer,
//yaitu jika player berada di samping customer

boolean IsAbleGive(Player P, Customer C, Table T){
    boolean check;

    check = false;
    if (IsNearTable(P,T)) {
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

boolean IsAblePlace(Player P, Customer C, Table T){
    boolean check;

    check = false;

    if(IsNearTable(P,T)){
        if(IsOccupied(T) == false) {
            if(CustomerCount(C) <= Capacity(T)) {
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

void TakeOrder(Player *P, Customer *C, Table T,IdxType i){

    if (IsAbleOrder(*P,*C,T)) {
        OrderList(*P,i) = OrderC(*C);
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

void PlaceCustomer (Player P, CustQueue *Q, Table *T) {
    Customer CustTemp;

    printf("PlaceCustomer called");

    if (!IsQueueEmpty(*Q)) {
        printf("Queue not empty");
        do {
            DelQueue(Q,&CustTemp);
            if(!IsAblePlace(P,InfoHead(*Q),*T)) {
                AddQueue(Q,CustTemp);
            } else {
                CustomerSeat(*T) = CustTemp;
                IsOccupied(*T) = true;
            }
            printf("Inside Loop\n");
        } while (CustomerCount(CustTemp) != CustomerCount(InfoTail(*Q)));
        printf("Made it here\n");
        if(IsAblePlace(P,InfoTail(*Q),*T)) {
            DelQueue(Q,&CustTemp);
            CustomerSeat(*T) = CustTemp;
            IsOccupied(*T) = true;
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

void GiveFood(Player *P, Customer C, Table *T, Game *G,BinTree RTree){
    Kata orinput;
    double Koef;

    if (IsAbleGive(*P,C,*T)){
        Pop(&OnTray(*P),&orinput);
        Koef = Level(RTree,orinput);
        Money(*G) += (NormalPrice * Koef);
        IsOccupied(*T) = false;
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

void TickOrder (Room R,Table T,Customer *C){
    int i;

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
