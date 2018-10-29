// Body untuk listrek.h
// Pandyaka Aptanagi / 13517003

#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Manajemen Memori *** */
addressRek AlokasiRek(infotypeRek X)
/* Mengirimkan addressRek hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressRek tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    {
        // Kamus Lokal
        addressRek P;

        // Algoritma
        P = (addressRek)malloc(1*sizeof(ElmtListRek));
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

void Dealokasi (addressRek P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressRek P */
    {
        // Kamus Lokal

        // Algoritma
        free(P);
    };

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListRek */
int IsEmpty(ListRek L)
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

int IsOneElmt(ListRek L)
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
infotypeRek FirstElmt (ListRek L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
    {
        // Kamus Lokal

        // Algoritma
        return Info(L);
    };

ListRek Tail(ListRek L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
    {
        // Kamus Lokal

        // Algoritma
        return(Next(L));
    };

/* *** Konstruktor *** */
ListRek Konso(infotypeRek e, ListRek L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
    {
        // Kamus Lokal
        addressRek P;

        // Algoritma
        P = AlokasiRek(e);
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

ListRek KonsB(ListRek L, infotypeRek e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
    {
        // Kamus Lokal
        addressRek P;

        // Algoritma
        P = AlokasiRek(e);
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
          } else {
            return Nil;
          }
    };

/* *** Operasi Lain *** */
ListRek Copy (ListRek L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
    {
        // Kamus Lokal
        ListRek newlist;

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

void MCopy (ListRek Lin, ListRek *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
    {
        // Kamus Lokal
        ListRek copylist;

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

ListRek Concat (ListRek L1, ListRek L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
    {
        // Kamus Lokal
        ListRek newlist;

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

void MConcat (ListRek L1, ListRek L2, ListRek *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
    {
        // Kamus Lokal
        ListRek newlist;

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

void PrintList (ListRek L)
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

int NbElmtList (ListRek L)
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

boolean Search (ListRek L, infotypeRek X)
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
        return false;
    };

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : ListRek tidak kosong */
infotypeRek MaxList (ListRek L)
/* Mengirimkan nilai info(P) yang maksimum */
    {
        // Kamus Lokal
        infotypeRek max;

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

infotypeRek MinList (ListRek L)
/* Mengirimkan nilai info(P) yang minimum */
    {
        // Kamus Lokal
        infotypeRek min;

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

infotypeRek SumList (ListRek L)
/* Mengirimkan total jumlah elemen ListRek L */
	{
		// Kamus Lokal
		infotypeRek sum;

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

float AverageList (ListRek L)
/* Mengirimkan nilai rata-rata elemen list L */
    {
        // Kamus Lokal
        float ratarata;

        // Algoritma
        ratarata = SumList(L) / NbElmtList(L);
        return ratarata;

    };

/*** Operasi-Operasi Lain ***/
ListRek InverseList (ListRek L)
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

void SplitPosNeg (ListRek L, ListRek *L1, ListRek *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
    {
        // Kamus Lokal
        ListRek newlist1, newlist2;

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

void SplitOnX (ListRek L, infotypeRek X, ListRek *L1, ListRek *L2)
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
    {
        // Kamus Lokal
        ListRek newlist1,newlist2;

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

int ListCompare (ListRek L1, ListRek L2)
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

boolean IsAllExist (ListRek L1, ListRek L2)
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
