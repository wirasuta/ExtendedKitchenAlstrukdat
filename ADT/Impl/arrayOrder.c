/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include "boolean.h"
#include "arrayOrder.h"
#include "stdio.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabOrder * T) {
	Neff(*T) = 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabOrder T) {
	return(Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabOrder T) {
	return (IdxMax);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabOrder T) {
	return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabOrder T) {
	return (Neff(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxOValid (TabOrder T, IdxType i) {
	return ((1 <= i) && (i <= 100));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxOEff (TabOrder T, IdxType i) {
	return ((IdxMin <= i) && (i <= Neff(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsOEmpty (TabOrder T) {
	return (Neff(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsOFull (TabOrder T) {
	return (Neff(T) == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTab (TabOrder T) {
	int i;
	
	printf("[");
	for (i=1; i<=Neff(T); i++) {
		printf("%s, %d", ElmtName(T,i), ElmtNomor(T,i));
		if ((i != Neff(T)) && (i != 1)) {
			printf("|");
		}
	}
	printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
//membandingkan yang 
boolean SearchBoolean(TabOrder T, int Meja, Kata Makanan){
	IdxType i;
    boolean checkMeja, checkMakanan;

    checkMeja = false;
	checkMakanan = false;

	if (!IsOEmpty){
		i = IdxMin;
		while (!checkMeja && (i <= Neff(T))){
			if (ElmtNomor(T,i) == Meja)
				checkMeja = true;
			else
				i += 1;
		}
		if (checkMeja){
			if (IsKataSama(ElmtNomor(T,i), Makanan))
				checkMakanan = true;
		}
	}

	return(checkMeja && checkMakanan);
}

//mengembalikan index array
IdxType SearchIndex (TabOrder T, int Meja, Kata Makanan) {
	IdxType i;
	boolean checkMeja, checkMakanan;

	checkMeja = false;
	checkMakanan = false;

	if (!IsOEmpty){
		i = IdxMin;

		while (!checkMeja && i <= Neff(T)){
			if (ElmtNomor(T,i) == Meja)
				checkMeja = true;
			else
				i += 1;
		}

		if (checkMeja){
			if (IsKataSama(ElmtName(T,i), Makanan))
				checkMakanan = true;
		}
	}

	if (checkMeja && checkMakanan){
		return i;
	}
	else{
		return IdxUndef;
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabOrder * T, ElType X) {
	if (IsOEmpty(*T)){
		int i;
		i = 1;

		Neff(*T) = 1;
		Elmt(*T,i) = X;
	}
	else if (!IsOEmpty(*T) && (!IsOFull(*T))){
		Neff(*T) += 1;
		Elmt(*T,Neff(*T)) = X;
	}
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelEli (TabOrder * T, IdxType i, ElType *X) {
	int j;
	
	*X = Elmt(*T,i);
	for (j=i; j<Neff(*T); j++) {
		Elmt(*T,j) = Elmt(*T,j+1);
	}
	Neff(*T) -= 1;
}
