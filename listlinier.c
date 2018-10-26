// Body untuk listlinier.h
// Pandyaka Aptanagi / 13517003

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
	{
		// Kamus Lokal
		
		// Algoritma
		return ( First(L) == Nil);
	};

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	{
		// Kamus Lokal
		
		// Algoritrma
		First(*L) = Nil;
	};
	
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	{
		// Kamus Lokal
		
		// Algoritma
		ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
		
		if ( P != Nil)
			{
				Info(P) = X;
				Next(P) = Nil;
				return(P);
			}
		else
			{
				return(Nil);
			};
	};
	
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
 	{
 		// Kamus Lokal
		 
		 // Algoritma
		 free(*P);	
	};
 

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	{
		// Kamus Lokal
		boolean sama;
		address P;
		address cari;
		
		// Algoritma
		sama = false;
		P = First(L);
		cari = Nil;

		while  ( ( P != Nil) && (!sama) )
			{
				if ( Info(P) == X)
					{
						sama = true;
						cari = P;
					};
				P = Next(P);
			};
		
		return(cari);
		
	};

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	{
		// Kamus Lokal
		address P;
		
		// Algoritma
		P = Alokasi(X);

		if ( P != Nil)
			{
				Next(P) = First(*L);
				First(*L) = P;
			}
		
	};
	
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	{
		// Kamus Lokal
		address P;
		address P1;

		// Algoritma
		P = Alokasi(X);
		P1 = First(*L);
		if ( P != Nil)
			{
				if ( P1 != Nil)
					{
						while ( Next(P1) != Nil)
							{
								P1 = Next(P1);
							};
						Next(P1) = P;
					}
				else
					{
						Next(P) = First(*L);
						First(*L) = P;
					};		
			};
	};

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	{
		// Kamus Lokal
		address P;
	
		// Algoritma
		P = First(*L);
		*X = Info(P);
		First(*L) = Next(P);
		Dealokasi(&P);

	};
	
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
	{
		// Kamus Lokal
		address P;
		address P1;

		// Algoritma
		P = First(*L);
		P1 = Nil;

		while ( Next(P) != Nil )
			{
				P1 = P;
				P = Next(P);
			};
		
		*X = Info(P);

		if (P1 == Nil)
			{
				First(*L) = Nil;
			}
		else
			{
				Next(P1) = Nil;
			}

		Dealokasi(&P);
		
	};
	
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	{
		// Kamus Lokal
		
		// Algoritma
		Next(P) = First(*L);
		First(*L) = P;
	};

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	{
		// Kamus Lokal
		
		// Algoritma
		Next(P) = Next(Prec);
		Next(Prec) = P;
	};

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	{
		// Kamus Lokal
		address last;
		address P1;

		// Algoritma
		if ( IsEmpty(*L) )
			{
				Next(P) = First(*L);
				First(*L) = P;
			}
		else
			{
				P1 = First(*L);
				while( Next(P1) != Nil)
					{
						P1 = Next(P1);
					};
				Next(P1) = P;
			}
		

	};

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	{
		// Kamus Lokal

		// Algoritma
		 *P = First(*L);
 		 First(*L) = Next(*P);
	};

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	{
		// Kamus Lokal
		address P;
		address prec;

		// Algoritma
		P = First(*L);
		prec = Nil;
		if ( Info(P) == X)
			{
				First(*L) = Next(P);
				Dealokasi(&P);
			}
		else
			{
				while ( ( P != Nil) && ( Info(P) != X ) )
					{
						prec = P;
						P = Next(P);
					};
				
				if ( P != Nil )
					{
						Next(prec) = Next(Next(prec));
						Dealokasi(&P);
					};
			}
		
			

	};

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
	{
		// Kamus Lokal
		address prec;	
		address P1;

		// Algoritma
		P1 = First(*L);
		prec = Nil;
		
		if ( Next(P1) == Nil )
			{
				*P = First(*L);
				P1 = Nil;
				First(*L) = Nil;
			}
		else
			{
				while ( Next(P1) != Nil )
					{
						prec = P1;
						P1 = Next(P1);
					};
				*P = P1;
				
				if ( prec != Nil )
					{
						Next(prec) = Nil;
					};
				
				
			};
		

	};

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	{
		// Kamus Lokal

		// Algoritma
		*Pdel = Next(Prec);
    	if (*Pdel != Nil)
			{
				 Next(Prec) = Next(Next(Prec));
			};

	};

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	// Kamus Lokal
	address P1;
	

	// Algoritma
	P1 = First(L);
	printf("[");
	while (P1!=Nil) 
		{
			printf("%d",Info(P1));
			if ( Next(P1) != Nil )
				{
					printf(",");
				}
			P1 = Next(P1);
		}
	printf("]");
};


int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	{
		// Kamus Lokal
		int nb;
		address first;
		// Algoritma
			nb = 0;
			first = First(L);
			while ( first != Nil)
				{
					nb = nb + 1;
					first = Next(first);
				};
		
		return nb;
	};

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
	{
		// Kamus Lokal
		infotype max;
		address pmax;

		// Algoritma
		pmax = First(L);
		max = Info(pmax);
		
		while ( pmax != Nil)
			{
				if ( max < Info(pmax) ) 
					{
						max = Info(pmax);
					};
				pmax = Next(pmax);
			};
		
		return max;
	
	}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
	{
		// Kamus Lokal
		address P;

		// Algoritma
		P = First(*L1);
		if ( P != Nil)
			{
				First(*L3) = First(*L1);
				while( Next(P) != Nil)
					{
						P = Next(P);
					};
				Next(P) = First(*L2);
			}
		else
			{
				First(*L3) = First(*L2);
			};

			First(*L1) = Nil;
			First(*L2) = Nil;


	};

