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
		return ( (Q).HEAD == queueNil && (Q).TAIL == queueNil);
	};

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak QueueMaxEl */
	{
		// Kamus
		int count;

		// Algoritma
		count = ( ((Q).TAIL - (Q).HEAD + (Q).QueueMaxEl ) % (Q).QueueMaxEl + 1 ); // Menggunakan mod karena bisa saja (Q).TAIL > (Q).HEAD
		return ( count == (Q).QueueMaxEl );
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
				return ( ((Q).TAIL - (Q).HEAD + (Q).QueueMaxEl) % (Q).QueueMaxEl + 1); // Menggunakan mod karena bisa saja (Q).TAIL > (Q).HEAD
			};
	};

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg QueueMaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	{
		// Kamus

		// Algoritma
		(*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype)); // ALokasi memori dinamik
		if ( (*Q).T != NULL )
			{
				(*Q).HEAD = queueNil;
				(*Q).TAIL = queueNil;
				(*Q).QueueMaxEl = Max;
			}
		else
			{
				(*Q).QueueMaxEl = 0;
			};
	};

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, QueueMaxEl(Q) diset 0 */
	{
		// Kamus

		// Algoritma
		QueueMaxEl(*Q) = 0;
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
				QueueTail(*Q) = (QueueTail(*Q) % QueueMaxEl(*Q)) + 1;
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
        			Head(*Q) = (Head(*Q) % QueueMaxEl(*Q)) + 1;
				}
		};
