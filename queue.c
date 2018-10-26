// Body untuk queue.h
// Pandyaka Aptanagi / 13517003

#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
	{
		// Kamus
		
		// Algoritma
		return ( (Q).HEAD == Nil && (Q).TAIL == Nil);
	};
	
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	{
		// Kamus
		int count;
		
		// Algoritma
		count = ( ((Q).TAIL - (Q).HEAD + (Q).MaxEl ) % (Q).MaxEl + 1 ); // Menggunakan mod karena bisa saja (Q).TAIL > (Q).HEAD
		return ( count == (Q).MaxEl );
	}
	
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	{
		// Kamus
		
		// Algoritma
		if ( IsEmpty(Q) )
			{
				return(0);
			}
		else
			{
				return ( ((Q).TAIL - (Q).HEAD + (Q).MaxEl) % (Q).MaxEl + 1); // Menggunakan mod karena bisa saja (Q).TAIL > (Q).HEAD
			};
	};

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	{
		// Kamus
		
		// Algoritma
		(*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype)); // ALokasi memori dinamik
		if ( (*Q).T != NULL )
			{
				(*Q).HEAD = Nil;
				(*Q).TAIL = Nil;
				(*Q).MaxEl = Max;
			}
		else
			{
				(*Q).MaxEl = 0;
			};
	};

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	{
		// Kamus
		
		// Algoritma
		MaxEl(*Q) = 0;
 		free((*Q).T);
	}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
	{
		// Kamus
		
		// Algoritma
		if ( IsEmpty(*Q) )
			{
				(*Q).HEAD = 1;
				(*Q).TAIL = 1;
				InfoTail(*Q) = X;
			}
		else
			{
				Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
				InfoTail(*Q) = X;
			}
	}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
        {
        	// Kamus
        	
        	// Algoritma
        	if ( NBElmt(*Q) == 1)
        		{
        			*X = InfoHead(*Q);
        			(*Q).HEAD = 0;
        			(*Q).TAIL = 0;
				}
			else
				{
					*X = InfoHead(*Q);
        			Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
				}
		};


