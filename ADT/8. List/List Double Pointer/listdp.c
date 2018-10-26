// Body untuk listdp.h
// Pandyaka Aptanagi / 13517003

#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    {
        // Kamus Lokal

        // Algoritma
        return ( First(L) == Nil && Last(L) == Nil );
    };

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    {
        // Kamus Lokal

        // Algoritma
        First(*L) = Nil;
        Last(*L) = Nil;
    };

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    {
        // Kamus Lokal
        address P;

        // Algoritma
        P = (address)malloc(1*sizeof(ElmtList));

        if ( P != Nil)
            {
                Info(P) = X;
                Next(P) = Nil;
                Prev(P) = Nil;

                return P;
            }
        else
            {
                return Nil;
            }

    }
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    {
        // Kamus Lokal

        // Algoritma
        free(P);
    };

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
   	{
		// Kamus Lokal
		address P;

        // Algoritma
        P = First(L);

        while (P != Nil)
            {
                if ( Info(P) == X)
                    {
                        return P;
                    }
                P = Next(P);
            }
        
        return Nil;
    };

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    {
        // Kamus Lokal
        address P,P1;

        // Algoritma
        P = Alokasi(X);
        if ( P != Nil )
            {
                if ( !IsEmpty(*L) )
                    {
                        Prev(First(*L)) = P;
                        Next(P) = First(*L);
                    }
                First(*L) = P;

                P1 = First(*L);
                while ( Next(P1) != Nil )
                    {
                        P1 = Next(P1);
                    };
                Last(*L) = P1;
            }
    };

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    {
        // Kamus Lokal
        address P,P1;

        // Algoritma
        P = Alokasi(X);
        P1 = Last(*L);
        if ( P != Nil )
            {
                         if ( P1 != Nil )
                            {
                                Next(P1) = P;
                                Prev(P) = P1;
                                Last(*L) = P;
                            }
                        else
                            {
                                InsVFirst(L,X);
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
        if ( P == Last(*L) )
            {
                First(*L) = Nil;
                Last(*L) = Nil;
            }
        else
            {
                Prev(Next(P)) = Nil;
                First(*L) = Next(P);
            };

        Dealokasi(P);

    };

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    {
        // Kamus Lokal
        address P,P1;

        // Algoritma
        P = Last(*L);
        *X = Info(P);
        
        if ( First(*L) == Last(*L) )
            {
                First(*L) = Nil;
                Last(*L) = Nil;
            }
        else
            {
                P1 = Prev(P);
                Last(*L) = P1;
                Next(P1) = Nil;
            };
        
        Dealokasi(P);
    };

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    {
        // Kamus Lokal
        address P1;

        // Algoritma
        if ( !IsEmpty(*L) )
            {
                Next(P) = First(*L);
                Prev(First(*L)) = P;
            }
       First(*L) = P;

       P1 = First(*L);
       while ( Next(P1) != Nil)
        {
            P1 = Next(P1);
        };
        Last(*L) = P1;
    };

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    {
        // Kamus Lokal
        address P1;

        // Algoritma
        if ( !IsEmpty(*L) )
            {
                P1 = Last(*L);
                Next(P1) = P;
                Prev(P) = P1;
                Last(*L) = P;
            }
        else
            {
                First(*L) = P;
                Last(*L) = P;
                Prev(P) = Nil;
                Next(P) = Nil;
            };

    };

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    {
        // Kamus Lokal
        address P1;

        // Algoritma
        P1 = Last(*L);
        if ( Prec == P1 )
            {
                Last(*L) = P;
            }
        else
            {
                Prev(Next(Prec)) = P;
            };
        
        Next(P) = Next(Prec);
        Next(Prec) = P;
        Prev(P) = Prec;
    };

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    {
        // Kamus Lokal
        address P1;

        // Algoritma
        P1 = First(*L);
        if ( Succ ==    P1 )
            {
                First(*L) = P;
            }
        else
            {
                Next(Prev(Succ)) = P;
            };
        
        Next(P) = Succ;
        Prev(P) = Prev(Succ);
        Prev(Succ) = P;

        
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
       if ( First(*L) == Last(*L) )
            {
                First(*L) = Nil;
                Last(*L) = Nil;
            }
        else
            {
                Prev(Next(*P)) = Nil;
                First(*L) = Next(*P);
            }


    };

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    {
        // Kamus Lokal

        // Algoritma
        *P = Last(*L);
        if ( First(*L) == Last(*L) )
            {
                First(*L) = Nil;
                Last(*L) = Nil;
            }
        else
            {
                Next(Prev(*P)) = Nil;
                Last(*L) = Prev(*P);
            };

    };

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    {
        // Kamus Lokal
            address P,P1;

        // Algoritma 
            P = First(*L);
            P1 = Nil;
            if ( Info(P) == X)
                {
                    if ( First(*L) == Last(*L) )
                        {
                            First(*L) = Nil;
                            Last(*L) = Nil;
                        }
                    else
                        {
                            First(*L) = Next(P);
                            Prev(Next(P)) = Nil;
                        };
                }
            else
                {
                    while ( ( P != Nil ) && (Info(P) != X ) )
                        {
                            P1 = P;
                            P = Next(P);
                        };

                    if ( P != Nil )
                        {
                            if ( P == Last(*L) )
                                {
                                    Last(*L) = P1;
                                    Next(P1) = Nil;
                                }
                            else
                                {
                                    Prev(Next(P)) = P1;
                                    Next(P1) = Next(P);
                                }

                        } 
                }
            Dealokasi(P);
    };

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    {
        // Kamus Lokal

        // Algoritma
        *Pdel = Next(Prec);
    	if ( *Pdel == Last(*L) )
            {
                Last(*L) = Prec;
            }
        else
            {
                Prev(Next(*Pdel)) = Prec;
            }
        Next(Prec) = Next(*Pdel);
    };

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    {
        *Pdel = Prev(Succ);

        if (*Pdel == First(*L))
            {
                First(*L) = Succ;
            }
        else 
            {
                Next(Prev(*Pdel)) = Succ;
            }

       Prev(Succ) = Prev(*Pdel);
    };

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
     {
         // Kamus Lokal
        address PIterate;

        // Algoritma
        PIterate = First(L);
        printf("[");
        while (PIterate!=Nil)
        {
            printf("%d",Info(PIterate));
            if (Next(PIterate)!=Nil)
                {
                    printf(",");
                }
            PIterate = Next(PIterate);
        }
        printf("]");
    };
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
     {
         // Kamus Lokal
        address PIterate;
              
        // Algoritma
        PIterate = Last(L);
        printf("[");
        while (PIterate!=Nil) 
            {
                printf("%d",Info(PIterate));
                if (Prev(PIterate)!=Nil)
                    {
                        printf(",");
                    }
                PIterate = Prev(PIterate);
            }
        printf("]");
    };

