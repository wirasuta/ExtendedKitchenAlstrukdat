/* File: Point.h */
/* Tanggal: 1 September 2018 */
/* *** Body untuk Point.h *** */

#include <stdio.h>
#include <math.h>
#include "../Header/point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
    {
        POINT P;
        Absis(P) = X;
        Ordinat(P) = Y;
        return P;
    }

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */

    {
        int X,Y;
        scanf("%d %d", &X, &Y);
        *P = MakePOINT(X,Y);
    }

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    {
        printf("(%d,%d)", Absis(P), Ordinat(P));
    }

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    {
        return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
    }
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    {
        return (!EQ(P1, P2));
    }

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
    {
        return ((Absis(P) == 0) && (Ordinat(P) == 0));
    }

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
    {
        return (Ordinat(P) == 0);
    }

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
    {
        return (Absis(P) == 0);
    }

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
    {
        Absis(P) += 1;
        return P;
    }

/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
    {
        Ordinat(P) += 1;
        return P;
    }

POINT PlusDelta (POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    {
        Absis(P) += deltaX;
        Ordinat(P) += deltaY;
        return P;
    }

void Geser (POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    {
        *P = PlusDelta( *P, deltaX, deltaY);
    }

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    {
        Ordinat(*P) = 0;
    }
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    {
        Absis(*P) = 0;
    }
