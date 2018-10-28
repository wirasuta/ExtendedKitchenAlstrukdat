// Body untuk listrek.h
// Pandyaka Aptanagi / 13517003

#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Manajemen Memori *** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    {
        // Kamus Lokal
        address P;

        // Algoritma
        P = (address)malloc(1*sizeof(ElmtList));
        if ( P != Nil )
            {
                Info(P) = X;
                Next(P) = Nil;
                return P;
            }
        else
            {
                return Nil;
            };
    };

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    {
        // Kamus Lokal

        // Algoritma    
        free(P);
    };

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
    {
        // Kamus Lokal

        // Algoritma
        if ( L == Nil )
            {
                return 1;
            }
        else
            {
                return 0;
            };
    };

int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
    {
        // Kamus Lokal

        // Algoritma
        if (!IsEmpty(L))
            {
                return IsEmpty(Next(L));
            }
        else
            {
                return 0;
            };
    };

/* *** Selektor *** */
infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
    {
        // Kamus Lokal

        // Algoritma
        return Info(L);
    };

List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
    {
        // Kamus Lokal

        // Algoritma
        return(Next(L));
    };

/* *** Konstruktor *** */
List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
    {
        // Kamus Lokal
        address P;

        // Algoritma
        P = Alokasi(e);
        if ( P != Nil )
            {
                Next(P) = L;
                return P;
            }
        else
            {
                return L;
            };
    };

List KonsB(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
    {
        // Kamus Lokal
        address P;

        // Algoritma
        P = Alokasi(e);
        if ( P != Nil )
            {
               if ( IsEmpty(L) )
                    {
                        return P;
                    }
                else
                    {
                        Next(L) = KonsB(Tail(L),e);
                        return L;
                    }
            };
    };

/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
    {
        // Kamus Lokal
        List newlist;

        // Algoritma
        if ( IsEmpty(L) )
            {
                return Nil;
            }
        else
            {
                newlist = Konso(FirstElmt(L),Copy(Tail(L)));
                return newlist;
            }
    };

void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
    {
        // Kamus Lokal
        List copylist;

        // Algoritma
        if (IsEmpty(Lin) )
            {
                *Lout = Nil;
            }
        else
            {
                MCopy(Tail(Lin),&copylist);
                *Lout = Konso(FirstElmt(Lin),copylist);
            };
    };

List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
    {
        // Kamus Lokal
        List newlist;

        // Algoritma
        if ( IsEmpty(L1) )
            {
                return Copy(L2);
            }
        else 
            {
                newlist = Konso(FirstElmt(L1),Concat(Tail(L1),L2));
                return newlist;
            };
    };

void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
    {
        // Kamus Lokal
        List newlist;

        // Algoritma
        if ( IsEmpty(L1) )
            {
               *LHsl = Copy(L2);
            }
        else
            {
                MConcat(Tail(L1),L2,&newlist);
                *LHsl = Konso(FirstElmt(L1),newlist);
            }
    };

void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
    {
        // Kamus Lokal

        // Algoritma
        if ( !IsEmpty(L) )
            {
                printf("%d", FirstElmt(L) );
                PrintList(Tail(L));
            };
    };  

int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
    {
        // Kamus Lokal

        // Algoritma
        if ( !IsEmpty(L) )
            {
                return NbElmtList(Tail(L)) + 1 ;
            }
        else
            {
                return 0;
            }
    };

boolean Search (List L, infotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
    {
        // Kamus Lokal

        // Algoritma
        if ( IsEmpty(L) )
            {
                return false;
            }
        else
            {
                if ( FirstElmt(L) == X)
                    {
                        return true;
                    }
                else
                    {
                        Search(Tail(L),X);
                    };
            };
    };

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L)
/* Mengirimkan nilai info(P) yang maksimum */
    {
        // Kamus Lokal
        infotype max;

        // Algoritma
        if ( !IsEmpty(L) )
            {
                max = MaxList(Tail(L));
                if ( FirstElmt(L) > max )
                    {
                        return FirstElmt(L);
                    }
                else
                    {
                        return max;
                    };
            }
        else
            {
                return -999;
            };
    };  

infotype MinList (List L)
/* Mengirimkan nilai info(P) yang minimum */
    {
        // Kamus Lokal
        infotype min;

        // Algoritma
        if ( IsEmpty(L) )
            {
                return 999;
            }
        else
            {
                min = MinList(Tail(L));
                if ( FirstElmt(L) < min )
                    {
                        return FirstElmt(L);
                    }
                else
                    {
                        return min;
                    };
            };
    };

infotype SumList (List L)
/* Mengirimkan total jumlah elemen List L */
	{
		// Kamus Lokal
		infotype sum;
		
		// Algoritma
		if ( IsEmpty(L) )
			{
				return 0;
			}
		else
			{
				sum = FirstElmt(L) + SumList(Tail(L)) ;
				return sum;
			};
	};
	
float AverageList (List L)
/* Mengirimkan nilai rata-rata elemen list L */
    {
        // Kamus Lokal
        float ratarata;

        // Algoritma
        ratarata = SumList(L) / NbElmtList(L);
        return ratarata;

    };

/*** Operasi-Operasi Lain ***/
List InverseList (List L)
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
    {
        // Kamus Lokal
        
        // Algoritma
        if ( IsEmpty(L) )
            {
                return Nil;
            }
        else
            {
                return KonsB(InverseList(Tail(L)),FirstElmt(L));
            };
    };

void SplitPosNeg (List L, List *L1, List *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
    {
        // Kamus Lokal
        List newlist1, newlist2;

        // Algoritma
        if (IsEmpty(L)) 
            {
                *L1 = Nil;
                *L2 = Nil;
            }
        else
            {
                SplitPosNeg(Tail(L),&newlist1,&newlist2);
                if ( FirstElmt(L) >= 0 )
                    {
                        *L1 = Konso(FirstElmt(L),newlist1);
                        *L2 = newlist2;
                    }
                else
                    {
                        *L1 = newlist1;
                        *L2 = Konso(FirstElmt(L),newlist2);
                    };
            };
    };

void SplitOnX (List L, infotype X, List *L1, List *L2)
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
    {
        // Kamus Lokal
        List newlist1,newlist2;

        // Algoritma
        if ( IsEmpty(L) )
            {
                *L1 = Nil;
                *L2 = Nil;
            }
        else
            {
                SplitOnX(Tail(L),X,&newlist1,&newlist2);

                if (FirstElmt(L) < X)
                    {
                        *L1 = Konso(FirstElmt(L),newlist1);
                        *L2 = newlist2;
                    }
                else
                    {
                        *L1 = newlist1;
                        *L2 = Konso(FirstElmt(L),newlist2);
                    };
            };

    };

int ListCompare (List L1, List L2)
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
    {
        // Kamus Lokal

        // Algoritma
        if ( IsEmpty(L1) && IsEmpty(L2) )
            {
                return 0;
            }
        else
        if ( IsEmpty(L1) && !IsEmpty(L2) )
            {
                return -1;
            }
        else
        if ( !IsEmpty(L1) && IsEmpty(L2) )
            {
                return 1;
            }
        else
            {
                if ( FirstElmt(L1) < FirstElmt(L2) )
                    {
                        return -1;
                    }
                else
                if ( FirstElmt(L1) > FirstElmt(L2) )
                    {
                        return 1;
                    }
                else
                    {
                        return ListCompare(Tail(L1),Tail(L2));
                    };
            };
    };

boolean IsAllExist (List L1, List L2)
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
    {
        // Kamus Lokal
        boolean exist;

        // Algoritma
        if ( IsEmpty(L1) )
            {
                return false;
            }
        else
        if ( IsOneElmt(L1) )
            {
                return Search(L2,FirstElmt(L1));
            }
        else
            {
                exist = IsAllExist(Tail(L1),L2);
                return ( Search(L2,FirstElmt(L1)) && exist );
            };
    };
