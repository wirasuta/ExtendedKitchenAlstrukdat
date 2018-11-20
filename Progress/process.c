#include <stdio.h>
#include <stdlib.h>
#include "process.h"

boolean isAbleOrder(Player P, Customer C, Table T){
    boolean check;
    int i;

    check = false;

    i = 0;
    for (i=0; i<IdxMax; i++){
        if((Absis(PosPlayer(P)) == Absis(PosTable(T,i)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTable(T,i)) - 1) ||
           (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) - 1)){
               if(StatOrder(OrderC(C)) == '#'){
                   check = true;
               }
        }
    }

    return(check);
}
//mengembalikas true jika player bisa megambil orderan dari customer,
//yaitu jika player berada di samping customer

boolean isAbleGive(Player P, Customer C, Table T){
    boolean check;
    int i;

    check = false;

    i = 0;
    for (i=0; i<IdxMax; i++){
        if((Absis(PosPlayer(P)) == Absis(PosTable(T,i)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTable(T,i)) - 1) ||
           (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) - 1)){
               if(StatOrder(OrderC(C)) == '!' && IsKataSama(InfoTop(OnTray(P)),OrderName(OrderC(C)))) {
                    check = true;
               }
        }
    }

    return(check);
}
//mengembalikas true jika player bisa memberikan makanan ke customer
//yaitu jika player berada di samping customer

boolean isAbleTake(Player P, Ingredients Bahan){
    boolean check;

    check = false;

    if ((Absis(PosPlayer(P)) == (Absis(PosIngredients(Bahan)) + 1)) || (Absis(PosPlayer(P)) == (Absis(PosIngredients(Bahan)) - 1)) ||
        (Ordinat(PosPlayer(P)) == (Ordinat(PosIngredients(Bahan)) + 1)) || (Ordinat(PosPlayer(P)) == (Ordinat(PosIngredients(Bahan)) - 1))){
               check = true;
        }
    return check;
}
//mengembalikas true jika player bisa mengambil bahan makanan atau tidak
//yaitu jika player berada di samping customer

boolean isAblePlace(Player P, Customer C, Table T){
    boolean check;
    int i;

    check = false;

    i = 0;
    for (i=0; i<IdxMax; i++){
        if((Absis(PosPlayer(P)) == Absis(PosTable(T,i)) + 1) || (Absis(PosPlayer(P)) == Absis(PosTable(T,i)) - 1) ||
           (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) + 1) || (Ordinat(PosPlayer(P)) == Ordinat(PosTable(T,i)) - 1)){
               if(IsOccupied(T) == false) {
                    if(Customers(C) <= Capacity(T)) {
                        check = true;
                    }
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

    if (isAbleOrder(*P,*C,T)) {
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

void PutToTray(Player *P){

}
//I.S sembarang
//F.S Mengubah kondisi Tray, jika sesuai dengan Food tree, maka makanan
//    berhasil dibuat, makanan dimasukkan ke stack Tray

void TakeIngredient(Player *P, Ingredients Bahan){

}
//I.S sembarang
//F.S jika player bersebelahan dengan posisi bahan, maka mengambil bahan
//    dan menaruhnya dalam stack Hand

void GiveFood(Player *P, Customer *C){

}
//I.S sembarang
//F.S jika tumpukan paling atas sesuai dengan order customer yang bersebelahan
//    dengan player, maka makanan akan diberikan
