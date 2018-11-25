/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H

#include "boolean.h"
#include "tepokpramuka_type.h"

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

/* ********* Prototype ********* */
boolean IsQueueEmpty (CustQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsQueueFull (CustQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak QueueMaxEl */
int NBElmtQueue (CustQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQueue (CustQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg QueueMaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQueue(CustQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, QueueMaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void AddQueue (CustQueue * Q, Customer X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelQueue (CustQueue * Q, Customer * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void SearchFitQueue(CustQueue *Q, Customer *X, int N);

void addTick(CustQueue *Q);


#endif
