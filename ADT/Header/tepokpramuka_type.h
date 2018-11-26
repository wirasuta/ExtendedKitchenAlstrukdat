#ifndef tepokpramuka_type_H
#define tepokpramuka_type_H

#include "boolean.h"

#define Nil NULL

/**** Definisi type Kata ****/
#define NMaxKata 50
typedef struct {
    char TabKata[NMaxKata+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;


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

typedef struct {
  char Status; //#: pesanan belom diambil, !: pesanan sudah diambil, $: pesanan sudah dikasi
  Kata Name; //nama makanan
  int Nomor; //nomor meja
} Order;

/* SELEKTOR UNTUK TIPE DATA ORDER */
#define StatOrder(O) (O).Status
#define OrderName(O) (O).Name
#define NoTableOrder(O) (O).Nomor
#define NormalPrice 100

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
#define TimeQueue(C) (C).TimeQueue
#define TimeWaiting(C) (C).TimeWaiting
#define CustomerCount(C) (C).SumOfCustomer
#define PosCustomer(C) (C).Position
#define OrderC(C) (C).Food
#define OrderCName(C) (C).Food.Name
#define OrderCNomor(C) (C).Food.Nomor

/* Definisi elemen dan koleksi objek */
/*typedef struct {
    Kata Name; //nama makanan
    int Nomor; //nomor meja
} InfoOrder;*/

typedef Order ElTypeInfoOrder;

typedef int IdxType;  /* type indeks */
// typedef int ElTypeInfoOrder;   /* type elemen tabel */
typedef struct {
	ElTypeInfoOrder TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabOrder;
/**** Selektor type TabOrder ****/
#define Neff(T)         (T).Neff
#define TI(T)           (T).TI
#define Elmt(T,i)       (T).TI[(i)]
#define ElmtOrderName(T,i)   (T).TI[(i)].Name
#define ElmtNomor(T,i)  (T).TI[(i)].Nomor

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

/**** Definisi type Queue ****/
#define queueNil 0
/* Konstanta untuk mendefinisikan queueAddress tak terdefinisi */

/* Definisi elemen dan queueAddress */
typedef int queueAddress;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan QueueTail eksplisit, ukuran disimpan */
typedef struct { Customer *T;   /* tabel penyimpan elemen */
                 queueAddress HEAD;  /* alamat penghapusan */
                 queueAddress TAIL;  /* alamat penambahan */
                 int QueueMaxEl;     /* Max elemen queue */
               } CustQueue;
/* Definisi Queue kosong: HEAD=queueNil;  TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define QueueTail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define QueueMaxEl(Q) (Q).QueueMaxEl

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

/**** Definisi type ListRek ****/
typedef Kata infotypeRek;
typedef struct tElmtlistrek *addressRek;
typedef struct tElmtlistrek {
	infotypeRek info;
	addressRek next;
} ElmtListRek;

/* Definisi list : */
/* ListRek kosong : L = Nil */
typedef addressRek ListRek;

/* Deklarasi  nama untuk variabel kerja */
/*  	L : ListRek */
/*  	P : addressRek 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next

/**** Definisi type Pohon Biner ****/
/* typedef int infotypeRek; */ /* type infotypeRek sesuai pada modul listrek */
typedef struct tNode *addrNode;
typedef struct tNode {
	infotypeRek info;
	addrNode left;
	addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/**** ADT Graph/Variasi MultiList ****/
typedef struct tRoomNode *adrNode;
typedef struct tEdgeNode *adrEdgeNode;
typedef struct tRoomNode {
  int Id;
  adrEdgeNode Trail;
  adrNode Next;
} RoomNode;

typedef struct tEdgeNode {
  POINT TransitTile;
  POINT DestTile;
  adrNode NextRoom;
  adrEdgeNode Next;
} EdgeNode;

typedef struct{
  adrNode First;
}GRAPH;

#define FirstNodeGraph(G) (G).First
#define RoomNumber(Node) (Node)->Id
#define Trail(Node) (Node)->Trail
#define TransitTile(EdgeNode) (EdgeNode)->TransitTile
#define DestTile(EdgeNode) (EdgeNode)->DestTile
#define NextNode(Node) (Node)->Next
#define NextTile(EdgeNode) (EdgeNode)->Next
#define NextRoom(EdgeNode) (EdgeNode)->NextRoom

/**** ADT Non-Olympia ****/

typedef struct {
    Stack Hand;
    Stack Tray;
    int Tick;
    POINT Position; //posisi dalam koordinat
    int RoomID;
    TabOrder PArr;
} Player;

/* SELEKTOR UNTUK TIPE DATA PLAYER */
#define OnHand(P) (P).Hand
#define OnTray(P) (P).Tray
#define PlayerTick(P) (P).Tick
#define PosPlayer(P) (P).Position
#define OrderList(P) (P).PArr
#define RoomID(P) (P).RoomID

typedef struct {
    POINT Point[IdxMax]; //posisi table dan kursi dalam (X,Y)
		//Point[0] : Posisi Meja
		//Point[1] : Posisi Kursi kiri
		//Point[2] : Posisi Kursi kanan
		//Point[3] : Posisi Kursi atas
		//Point[4] : Posisi Kursi bawah
    int Kapasitas; //kapasitas table
    boolean Occupied;
    Customer Filled;
} Table;

/* SELEKTOR UNTUK TIPE DATA TABLE */
#define PosTable(T,i) (T).Point[(i)]
#define Capacity(T) (T).Kapasitas
#define IsOccupied(T) (T).Occupied
#define CustomerSeat(T) (T).Filled

#define NTable 4

typedef struct {
    MATRIKS Grid;
    Table Arr[NTable]; //array of meja di restoran. nyimpen lokasi lokasi meja
} Room;

/* SELEKTOR UNTUK TIPE DATA ROOM */
#define Layout(R) (R).Grid
#define TableNo(R,i) (R).Arr[(i)]

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

typedef struct {
    int Life;
    double Money;
    JAM Time;
    Kata Name; //nama player
    Room Ruang[5];
    GRAPH RuangConnection;
} Game;

/* SELEKTOR UNTUK TIPE DATA GAME */
#define Life(G) (G).Life
#define Money(G) (G).Money
#define Tick(G) (G).Time
#define ElmtName(G) (G).Name
#define RoomGraph(G) (G).RuangConnection
#define Ruang(G,i) (G).Ruang[i]

/**** Variabel Global ****/
extern Kata KataGU, KataGD, KataGL, KataGR, KataORDER, KataPUT, KataTAKE, KataCH, KataCT;
extern Kata KataPLACE, KataGIVE, KataRECIPE, KataSAVE, KataLOAD, KataEXIT;
extern Game gameData;
extern Player player;
extern CustQueue waitingList;
extern BinTree recipeTree;
extern LocTray locationTray;

#endif
