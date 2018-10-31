#include <stdio.h>
#include <stdlib.h>
#include "tepokpramuka_type.h"
#include "boolean.h"
#include "stackt.c"

boolean isAbleOrder(Player P, Customer C, Table T){
    boolean check;
    int i;

    check = false;

    i = 0;
    for (i=0; i<20; i++){
        if((P.Position.X == T.Point[i].X + 1) || (P.Position.X == T.Point[i].X - 1) ||
           (P.Position.Y == T.Point[i].Y + 1) || (P.Position.Y == T.Point[i].Y -1)){
               if(C.Food.Status == '#'){
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
    for (i=0; i<20; i++){
        if((P.Position.X == T.Point[i].X + 1) || (P.Position.X == T.Point[i].X - 1) ||
           (P.Position.Y == T.Point[i].Y + 1) || (P.Position.Y == T.Point[i].Y -1)){
               if(C.Food.Status == '!'){
                   if(P.)
               }
        }
    }

    return(check);
}
//mengembalikas true jika player bisa memberikan makanan ke customer
//yaitu jika player berada di samping customer

boolean isAbleTake(Player P, Ingredients Bahan){
    boolean check;
}
//mengembalikas true jika player bisa mengambil bahan makanan atau tidak
//yaitu jika player berada di samping customer

boolean isAblePlace(Player P, Customer C){
    boolean check;
}
//mengembalikas true jika player bisa menempatkan customer ke meja kosong
//yaitu jika player berada di samping meja dan sesuai dengan kapasitas


Stack ClearStack(Stack *S){
    CreateEmpty(S);
}
//membuang seluruh bahan makanan yang ada di tangan maupun di tray
// digunakan untuk CH dan CT

void TakeOrder(Player *P, Customer *C){

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
