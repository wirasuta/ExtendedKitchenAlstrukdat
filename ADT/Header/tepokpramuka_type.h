#ifndef tepokpramuka_type_H
#define tepokpramuka_type_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "jam.h"
#include "point.h"
#include "array.h"
#include "matriks.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "queue.h"
#include "stackt.h"
#include "listdp.h"
#include "bintree.h"
#include "listrek.h"

typedef struct {
    int Life;
    double Money;
    JAM Time;
    Kata Name; //nama player
} Game;

/* SELEKTOR UNTUK TIPE DATA GAME */
#define life(G) (G).Life
#define money(G) (G).Money
#define tick(G) (G).Time
#define ElmtName(G) (G).Name

typedef struct {
  char Status; //#: pesanan belom diambil, !: pesanan sudah diambil, $: pesanan sudah dikasi
  Kata Name; //nama makanan
  int Nomor; //nomor meja
  double Price; // Harga Makanan yang diorder
} Order;

typedef struct {
    Stack Hand;
    Stack Tray;
    POINT Position; //posisi dalam koordinat
    Order PArr[IdxMax];
} Player;

/* SELEKTOR UNTUK TIPE DATA PLAYER */
#define OnHand(P) (P).Hand
#define OnTray(P) (P).Tray
#define PosPlayer(P) (P).position
#define OrderList(P,i) (P).PArr[(i)]

typedef struct {
    boolean Star; //priority customer
    int TimeQueue; //count waktu ketika mengantri
    int TimeWaiting; //count waktu ketika menunggu makanan
    int SumOfCustomer; //jumlah orang
    POINT Position; //posisi saat duduk
    Order Food; //customer mau pesan apa
} Customer;

/* SELEKTOR UNTUK TIPE DATA CUSTOMER */
#define IsStar(C) (C).Star
#define timeQueue(C) (C).TimeQueue
#define timeWaiting(C) (C).TimeWaiting
#define Customers(C) (C).SumOfCustomer
#define PosCustomer(C) (C).Position
#define OrderC(C) (C).Food

typedef struct {
    POINT Point[IdxMax]; //posisi table dan kursi dalam (X,Y)
    int Kapasitas; //kapasitas table
    boolean Occupied;
    Customer Filled;
} Table;

/* SELEKTOR UNTUK TIPE DATA TABLE */
#define PosTable(T,i) (T).Point[(i)]
#define Capacity(T) (T).Kapasitas
#define IsOccupied(T) (T).Occupied
#define CustomerSeat(T) (T).Filled

typedef struct {
    MATRIKS Grid;
    Table Arr[IdxMax]; //array of meja di restoran. nyimpen lokasi lokasi meja
} Room;

/* SELEKTOR UNTUK TIPE DATA ROOM */
#define Layout(R) (R).Grid
#define TableLoc(R,i) (R).Arr[(i)]

/* SELEKTOR UNTUK TIPE DATA ORDER */
#define StatOrder(O) (O).Status
#define OrderName(O) (O).Name
#define NoTableOrder(O) (O).Nomor
#define OrderPrice(O) (O).Price


typedef struct{
    Kata Name;
    POINT Position;
} Ingredients;

/* SELEKTOR UNTUK TIPE DATA INGREDIENTS */
#define IngName(I) (I).Name
#define PosIngredients(I) (I).Position

#endif
