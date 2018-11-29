#ifndef process_H
#define process_H

#include "../ADT/Header/tepokpramuka_type.h"
#include "../ADT/Header/queue.h"
#include "../ADT/Header/stackt.h"
#include "../ADT/Header/array.h"
#include "../ADT/Header/point.h"
#include "../ADT/Header/bintree.h"
#include "../ADT/Header/mesinkata.h"
#include "../ADT/Header/matriks.h"
#include "../ADT/Header/roomgraph.h"
#include "../ADT/Header/boolean.h"

//Counter for next customer arrival
int NextCustomerArr;

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

boolean pathFilled(MATRIKS M, int x , int Y);
// Menghasilkan true jika "kotak" sudah terisi

void newCoordinate(MATRIKS M, int *X, int *Y, Kata command, int *roomID);
// I.S : Sembarang
// F.S : Menghasilkan koordinat baru untuk move player

void move(MATRIKS *M, int *X, int *Y,Kata command, int *roomID);
// I.S : Sembarang
// F.S : Memindahkan player menuju koordinat baru sesuai perintah

boolean IsNearTable (Player P, Room R);
//mengembalikan true jika posisi pemain berada di dekat meja

int GetTableNumber (Player P, Room R);
//mendapatkan info table yang berada di sekitar player
//Syarat : Player di dekat table

boolean IsAbleOrder(Player P, Room R);
//untuk menentukan apakah player bisa megambil orderan dari customer

boolean IsNearTray(Player P, POINT T);
//mengembalikan true jika posisi player berada di samping kanan/kiri/atas/bawah tray

boolean IsAbleGive(Player P, Room R);
//untuk menentukan apakah player bisa memberikan makanan ke customer

boolean IsAbleTake(Player P, Room R);
//untuk menentukan apakah player bisa mengambil bahan makanan atau tidak

boolean IsAblePlace(Player P, Customer C, Room R);
//untuk menentukan apakah player bisa menempatkan customer ke meja kosong

void ClearStack(Stack *S);
//membuang seluruh bahan makanan yang ada di tangan maupun di tray
// digunakan untuk CH dan CT

void TakeOrder(Player *P, Room *R);
//I.S. sembarang
//F.S mengupdate status Player dan Customer
//Proses: mengambil order customer, cek terlebih dahulu apakah player
//        bersebelahan denga customer, cek status order, jika valid masukkan
//        ke array order

void PlaceCustomer (Player P, CustQueue *Q, Room *R);

void PutToTray(Player *P, BinTree C_Food, POINT T);
//I.S sembarang
//F.S Mengubah kondisi Tray, jika sesuai dengan Food tree, maka makanan
//    berhasil dibuat, makanan dimasukkan ke stack Tray

void TakeIngredient(Player *P, Room R);
//I.S sembarang
//F.S jika player bersebelahan dengan posisi bahan, maka mengambil bahan
//    dan menaruhnya dalam stack Hand

void GiveFood(Player *P, Room *R, Game *G,BinTree RTree);
//I.S sembarang
//F.S jika tumpukan paling atas sesuai dengan order customer yang bersebelahan
//    dengan player, maka makanan akan diberikan

void PrintRecipe(BinTree P,int H);
//Menampilkan Pohon Resep

void TickOrder (Room *R);
//Menguragi time waiting customer pada table sebanyak 1 tick apabila ordeeran belum diambil

void CheckTickOrder (Room *R, Game *G);

// RANDOM CUSTOMER MASUK KE QUEUE
void returnCustomer(Customer *C, int N);
void randomCustomer(Player P, CustQueue *Q);

void TickGame(Game *G, Player *P, CustQueue *waitingList);

#endif
