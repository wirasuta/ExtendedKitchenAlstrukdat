#ifndef tepokpramuka_type_H
#define tepokpramuka_type_H

#include "boolean.h"

/**** Definisi type JAM <HH:MM:SS> ****/
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;
/**** Selektor type JAM ****/
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

/**** Definisi type POINT <X,Y> ****/
typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;
/**** Selektor type POINT ****/
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/**** Definisi type TabInt ****/
/*  Kamus Umum TabInt */
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999
/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct {
	ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
/**** Selektor type TabInt ****/
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/**** Definisi type MATRIKS ****/
/* Kamus Umum MATRIKS */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100
/* Definisi elemen dan koleksi objek */
typedef int indeks; /* indeks baris, kolom */
typedef char ElTypeMat;
typedef struct {
	ElTypeMat Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/**** Selektor type MATRIKS ****/
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MatElmt(M,i,j) (M).Mem[(i)][(j)]

/**** Definisi type Kata ****/
#define NMaxKata 50
typedef struct {
    char TabKata[NMaxKata+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/*TODO: Ganti infotype Stack menjadi Bahan/Makanan*/
/**** Definisi type Stack ****/
/* Kamus Umum Stack */
#define MaxElStack 10
typedef int stackAddress;   /* indeks tabel */
/* Stack Versi I : menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	Kata T[MaxElStack+1]; /* tabel penyimpan elemen */
	stackAddress TOP;  /* alamat TOP: elemen puncak */
} Stack;
/**** Selektor type Stack ****/
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/**** ADT Non-Olympia ****/

typedef struct {
    int Life;
    double Money;
    JAM Time;
    Kata Name; //nama player
} Game;

/* SELEKTOR UNTUK TIPE DATA GAME */
#define Life(G) (G).Life
#define Money(G) (G).Money
#define Tick(G) (G).Time
#define ElmtName(G) (G).Name

typedef struct {
  char Status; //#: pesanan belom diambil, !: pesanan sudah diambil, $: pesanan sudah dikasi
  Kata Name; //nama makanan
  int Nomor; //nomor meja
} Order;

/* SELEKTOR UNTUK TIPE DATA ORDER */
#define StatOrder(O) (O).Status
#define OrderName(O) (O).Name
#define NoTableOrder(O) (O).Nomor
#define NormalPrice


typedef struct {
    Stack Hand;
    Stack Tray;
    POINT Position; //posisi dalam koordinat
    Order PArr[IdxMax];
} Player;

/* SELEKTOR UNTUK TIPE DATA PLAYER */
#define OnHand(P) (P).Hand
#define OnTray(P) (P).Tray
#define PosPlayer(P) (P).Position
#define OrderList(P,i) (P).PArr[(i)]

typedef struct{
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

typedef struct{
    Kata Name;
    POINT Position;
} Ingredients;

/* SELEKTOR UNTUK TIPE DATA INGREDIENTS */
#define IngName(I) (I).Name
#define PosIngredients(I) (I).Position

typedef struct{
    POINT Point;
} LocTray;

/* SELEKTOR UNTUK TIPE DATA LOCTRAY */
#define PosTray(L) (L).Point

#endif
