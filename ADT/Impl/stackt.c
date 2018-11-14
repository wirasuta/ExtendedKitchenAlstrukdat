// Body untuk stackt.h
// Pandyaka Aptanagi / 13517003

#include <stdio.h>
#include "../Header/stackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai StackNil */
	{
		// Kamus

		// Algoritma
		(*S).TOP = StackNil;

	};

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	{
		// Kamus

		// Algoritma
		return ( (S).TOP == StackNil);

	};

boolean IsStackFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	{
		// Kamus

		// Algoritma
		return ((S).TOP == MaxEl);
	};

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Kata X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	{
		// Kamus
		int l,i;
		// Algoritma
		if ( IsStackEmpty(*S) )
			{
				(*S).TOP = 1;
			}
		else
			{
				(*S).TOP = (*S).TOP +1;
			}

		l = X.Length;

		for (i=0; i < l+1; i++)
			InfoTop(*S).TabKata[i] = X.TabKata[i];
	};

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Kata *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

	{
		// Kamus
		int l,i;

		// Algoritma
		l = InfoTop(*S).Length;
		for (i=0; i<l+1; i++)
			(*X).TabKata[i] = InfoTop(*S).TabKata[i];

		if ( (*S).TOP == 1)
			{
				CreateEmptyStack(S);
			}
		else
			{
				(*S).TOP = (*S).TOP - 1;
			};
	};
