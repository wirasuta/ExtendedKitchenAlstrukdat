#ifndef tepokpramuka_type_H
#define tepokpramuka_type_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "Jam.c"
#include "Point.c"
#include "array.c"
#include "matriks.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include "queue.c"
#include "stackt.c"
#include "listlinier.c"
#include "listdp.c"
#include "bintree.c"
#include "listrek.c"

typedef struct {
    int Life;
    double Money;
    JAM Time;
    char Name[IdxMax]; //nama player
} Game;

/* SELEKTOR UNTUK TIPE DATA GAME */
#define life(G) (G).Life
#define money(G) (G).Money
#define tick(G) (G).Time
#define ElmtName(G,i) (G).Name[(i)]


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
#define PosCustomer(C) (C).Position
#define OrderC(C) (C).Food

typedef struct {
    MATRIKS Grid;
    Table Arr[IdxMax]; //array of meja di restoran. nyimpen lokasi lokasi meja
} Room;

/* SELEKTOR UNTUK TIPE DATA ROOM */
#define Layout(R) (R).Grid
#define TableLoc(R,i) (R).Arr[(i)]

typedef struct {
    char Status; //#: pesanan belom diambil, !: pesanan sudah diambil, $: pesanan sudah dikasi
    char Name[IdxMax]; //nama makanan
    int Nomor; //nomor meja
} Order;

/* SELEKTOR UNTUK TIPE DATA ORDER */
#define StatOrder(O) (O).Status
#define OrderName(O) (O).Name
#define NoTableOrder(O) (O).Nomor

typedef struct {
    POINT Point[10]; //posisi table dan kursi dalam (X,Y)
    int Kapasitas; //kapasitas table
    boolean Occupied;
    Customer Filled;
} Table;

/* SELEKTOR UNTUK TIPE DATA TABLE */
#define PosTable(T,i) (T).Point[(i)]
#define Capacity(T) (T).Kapasitas
#define IsOccupied(T) (T).Occupied
#define CustomerSeat(T) (T).Filled


typedef struct{
    char Name[IdxMax];
    POINT Position;
} Ingredients;

/* SELEKTOR UNTUK TIPE DATA INGREDIENTS */
#define IngName(I) (I).Name
#define PosIngredients(I) (I).Position

#endif
