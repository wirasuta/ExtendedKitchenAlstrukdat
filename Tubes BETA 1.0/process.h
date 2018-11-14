#ifndef process_H
#define process_H

#include "../ADT/Header/stackt.h"
#include "../ADT/Header/tepokpramuka_type.h"
/*
e. ORDER | Array
Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain
f. PUT | Stack
Command ini digunakan untuk menaruh makanan di hand ke nampan
g. TAKE | Stack
Command ini digunakan untuk mengambil bahan yang bersebelahan dengan
pemain
h. CH | STack
Command ini digunakan untuk membuang seluruh bahan makanan yang
terdapat di tangan pemain
i. CT | Stack
Command ini digunakan untuk membuang seluruh makanan yang berada di
dalam tray
j. PLACE | customer: Queue
Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue
k. GIVE | Stack
Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan
l. RECIPE | Graf
Command ini digunakan untuk menampilkan pohon makanan.
*/

boolean isAbleOrder(Player P, Customer C, Table T);
//untuk menentukan apakah player bisa megambil orderan dari customer

boolean isAbleGive(Player P, Customer C, Table T);
//untuk menentukan apakah player bisa memberikan makanan ke customer

boolean isAbleTake(Player P, Ingredients Bahan);
//untuk menentukan apakah player bisa mengambil bahan makanan atau tidak

boolean isAblePlace(Player P, Customer C, Table T);
//untuk menentukan apakah player bisa menempatkan customer ke meja kosong


Stack ClearStack(Stack S);
//membuang seluruh bahan makanan yang ada di tangan maupun di tray
// digunakan untuk CH dan CT

void TakeOrder(Player *P, Customer *C, Table T,IdxType i);
//I.S. sembarang
//F.S mengupdate status Player dan Customer
//Proses: mengambil order customer, cek terlebih dahulu apakah player
//        bersebelahan denga customer, cek status order, jika valid masukkan
//        ke array order

void PutToTray(Player *P);
//I.S sembarang
//F.S Mengubah kondisi Tray, jika sesuai dengan Food tree, maka makanan
//    berhasil dibuat, makanan dimasukkan ke stack Tray

void TakeIngredient(Player *P, Ingredients Bahan);
//I.S sembarang
//F.S jika player bersebelahan dengan posisi bahan, maka mengambil bahan
//    dan menaruhnya dalam stack Hand

void GiveFood(Player *P, Customer *C);
//I.S sembarang
//F.S jika tumpukan paling atas sesuai dengan order customer yang bersebelahan
//    dengan player, maka makanan akan diberikan


#endif
