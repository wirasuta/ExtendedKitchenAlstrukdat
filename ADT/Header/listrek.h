/* File: listrek.h */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#ifndef _LISTREK_H_
#define _LISTREK_H_

#include "boolean.h"
#include "tepokpramuka_type.h"
#include "mesinkata.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL

/* Definisi Type */
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

/* *** Manajemen Memori *** */
addressRek AlokasiRek(infotypeRek X);
/* Mengirimkan addressRek hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressRek tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiRek (addressRek P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan DealokasiRek/pengembalian addressRek P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListRek */
int IsEmptyRek(ListRek L);
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(ListRek L);
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotypeRek FirstElmt (ListRek L);
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
ListRek Tail(ListRek L);
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
ListRek Konso(infotypeRek e, ListRek L);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
ListRek KonsB(ListRek L, infotypeRek e);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */

/* *** Operasi Lain *** */
ListRek Copy (ListRek L);
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
void MCopy (ListRek Lin, ListRek *Lout);
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
ListRek Concat (ListRek L1, ListRek L2);
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcat (ListRek L1, ListRek L2, ListRek *LHsl);
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (ListRek L);
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList (ListRek L);
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean SearchRek (ListRek L, infotypeRek X);
/* Mengirim true jika X adalah anggota list, false jika tidak */




/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : ListRek tidak kosong
infotypeRek MaxList (ListRek L);
 Mengirimkan nilai info(P) yang maksimum

infotypeRek MinList (ListRek L);
 Mengirimkan nilai info(P) yang minimum

infotypeRek SumList (ListRek L);
 Mengirimkan total jumlah elemen ListRek L

float AverageList (ListRek L);
 Mengirimkan nilai rata-rata elemen list L */

/*** Operasi-Operasi Lain ***/
ListRek InverseList (ListRek L);
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
/*
void SplitPosNeg (ListRek L, ListRek *L1, ListRek *L2);
I.S. L mungkin kosong
F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2
L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L
L tidak berubah: Semua elemen L1 dan L2 harus dialokasi
Jika L kosong, maka L1 dan L2 kosong

void SplitOnX (ListRek L, infotypeRek X, ListRek *L1, ListRek *L2);
I.S. L dan X terdefinisi, L1 dan L2 sembarang.
F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama.

int ListCompare (ListRek L1, ListRek L2);
Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2
Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L:
L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i]
L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2|
Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4]
L1>L2: kebalikan dari L1<L2 */

boolean IsAllExist (ListRek L1, ListRek L2);
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
#endif
