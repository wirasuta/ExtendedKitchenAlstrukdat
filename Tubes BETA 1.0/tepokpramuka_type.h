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
    char Name[20]; //nama player
    int NWaitingList; //jumlah customer yang ngantri
} Game;

typedef struct {
    Stack Hand;
    Stack Tray;
    POINT Position; //posisi dalam koordinat
    Order POrder;
} Player;

typedef struct {
    boolean Star; //priority customer
    int TimeQueue; //count waktu ketika mengantri
    int TimeWaiting; //count waktu ketika menunggu makanan
    int N; 
    Order COrder; //customer mau pesan apa
} Customer;

typedef struct {
    MATRIKS Grid;
    Table Arr[20]; //array of meja di restoran. nyimpen lokasi lokasi meja
} Room;

typedef struct {
    char Status; //#: pesanan belom diambil, !: pesanan uda diambil, $: pesanan uda dikasi
    char Name[20]; //nama makanan
    int Sum; //jumlah makanan yang dipesanan
} Order;

typedef struct {
    POINT Point; //posisi table dan kursi dalam (X,Y)
    int Kapasitas; //kapasitas table
    boolean Occupied;
} Table;

#endif