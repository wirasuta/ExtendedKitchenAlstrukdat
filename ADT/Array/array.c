/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include "boolean.h"
#include "array.h"
#include "stdio.h"

/*  Kamus Umum */
// #define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
// #define IdxMin 1
/* Indeks minimum array */
// #define IdxUndef -999 
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
//typedef int IdxType;  /* type indeks */
//typedef int ElType;   /* type elemen tabel */
//typedef struct { 
	//ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	//int Neff; /* >=0, banyaknya elemen efektif */
//} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
//#define Neff(T)   (T).Neff
//#define TI(T)     (T).TI
//#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T) {
	Neff(*T) = 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
	return(Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T) {
	return (100);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T) {
	return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T) {
	return (Neff(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
	return ((1 <= i) && (i <= 100));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i) {
	return ((IdxMin <= i) && (i <= Neff(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
	return (Neff(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T) {
	return (Neff(T) == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T) {
	int i,N;
	
	do {
		scanf("%d", &N);
	} while((N < 0) || (N > IdxMax));
	
	Neff(*T) = N;
	for (i=1; i<=N; i++) {
		scanf("%d", &Elmt(*T,i));
	}
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void BacaIsiTab (TabInt * T) {
	int x,i;
	
	i = 1;
	scanf("%d", &x);
	while ((x != -9999) && (i<=100)) {
		Elmt(*T,i) = x;
		scanf("%d", &x);
		i++;
	}
	Neff(*T) = i-1;
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
void TulisIsi (TabInt T) {
	int i;
	
	if (T.Neff == 0) {
		printf("Tabel kosong\n");
	}
	for (i=1; i<=T.Neff; i++) {
		printf("["); printf("%d",i); printf("]"); printf("%d\n", Elmt(T,i));
	}
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
void TulisIsiTab (TabInt T) {
	int i;
	
	printf("[");
	for (i=1; i<=T.Neff; i++) {
		printf("%d", Elmt(T,i));
		if (i != T.Neff) {
			printf(",");
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

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2) {
	TabInt T3;
	int i;
	
	T3.Neff = T1.Neff;
	for (i=1; i<= T3.Neff; i++) {
		T3.TI[i] = T1.TI[i] + T2.TI[i];
	}
	
	return(T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
TabInt MinusTab (TabInt T1, TabInt T2) {
	TabInt T3;
	int i;
	
	T3.Neff = T1.Neff;
	for (i=1; i<= T3.Neff; i++) {
		T3.TI[i] = T1.TI[i] - T2.TI[i];
	}
	
	return(T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2) {
	TabInt T3;
	int i;
	
	T3.Neff = T1.Neff;
	for (i=1; i<= T3.Neff; i++) {
		T3.TI[i] = T1.TI[i] * T2.TI[i];
	}
	
	return(T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c) {
	TabInt T3;
	int i;
	
	T3.Neff = Tin.Neff;
	for (i=1; i<= T3.Neff; i++) {
		T3.TI[i] = Tin.TI[i] * c;
	}
	
	return(T3);
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2) {
	int i,ls;
 /*algoritma*/
   i = 1;
   if((T1.Neff) == (T2.Neff)) {
    	while((Elmt(T1,i) == Elmt(T2,i)) && (i < NbElmt(T1))) {
       		i++;
       	}
      	ls = GetLastIdx(T1); 
      	if((i==ls)&&(Elmt(T1,ls) == Elmt(T2,ls))) {
        	return true;	
        } else {
      		return false;
      	}		
    } else {
   		return false;
	}
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2) {
	int i,j,ls;
 /*algoritma*/
   	i = 1;
   	j = 0;
   	if(NbElmt(T1) == NbElmt(T2)) {
      	while ((i<= T1.Neff) && (j == 0)) {
      		if (T1.TI[i] < T2.TI[i]) {
      			j = 1;
			} else if (T1.TI[i] > T2.TI[i]) {
				j = 2;
			}
			i++;
		}
		if (j == 1) {
			return (true);
		} else {
			return (false);
		}
	} else if (T1.Neff < T2.Neff) {
		return (true);
    } else 
	return false;
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X) {
	IdxType i;
/*algoritma*/
	if(!IsEmpty(T)) {
    i = IdxMin;
    while(X != Elmt(T,i) && i < GetLastIdx(T)) i++;
    if(X == Elmt(T,i))
      return i;
  }
	return IdxUndef;

}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X) {
	IdxType i;
	boolean Found;
	
	if(!IsEmpty(T)) {
    Found = false;
    i = GetFirstIdx(T);
	  while((!Found) && (i<=NbElmt(T))) {
      if(X == Elmt(T,i))
      Found = true;
      i++;
    }
	  	if(Found) {
			return(i-1);
		}
  	}
	return(IdxUndef);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X) {
	int i;
	boolean Found;
	
	Found = false;
	i = 1;
	while (!Found && (i<=T.Neff)) {
		if (T.TI[i] == X) {
			Found = true;
		}
		i += 1;
	}
	return (Found);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X) {
	int i;
	
	T.TI[0] = 0;
	for (i=1; i<=T.Neff; i++) {
		if (T.TI[i] == X) {
			T.TI[0] = X;
		}
	}
	return (T.TI[0] == X);
	
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T) {
	int i,m;
	
	m = T.TI[1];
	for (i=2; i<=T.Neff; i++) {
		if (m < T.TI[i]) {
			m = T.TI[i];
		}
	}
	return (m);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T) {
	int i,m;
	
	m = T.TI[1];
	for (i=2; i<=T.Neff; i++) {
		if (m > T.TI[i]) {
			m = T.TI[i];
		}
	}
	return (m);
} 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T) {
	int i,x,y;
	
	x = ValMax(T);
	for (i=T.Neff; i>=1; i--) {
		if (T.TI[i] == x) {
			y = i;
		}
	}
	
	return (y);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T) {
	int i,x,y;
	
	x = ValMin(T);
	for (i=T.Neff; i>=1; i--) {
		if (T.TI[i] == x) {
			y = i;
		}
	}
	
	return (y);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout) {
	int i;
	
	Neff(*Tout) = Tin.Neff;
	for (i = 1; i<=Tin.Neff; i++) {
		Elmt(*Tout,i) = Tin.TI[i];
	}
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T) {
	int i,j;
	TabInt T1;
	
	T1.Neff = T.Neff;
	j=1;
	for (i=T.Neff; i>=1; i--) {
		T1.TI[j] = T.TI[i];
		j++;
	}
	return (T1);
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T) {
	int i,j;
	
	i=1;
	j=T.Neff;
	while ((T.TI[i] == T.TI[j]) && (i<=T.Neff)) {
		i++;
		j--;
	}
	
	return (i == (T.Neff+1));
}
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T) {
	int h,i,j,k,temp;
	
	j = 1;
	for (i = 1;i<Neff(*T); i++) {
		k = Elmt(*T,i);
		h = i;
		for (j=i+1; j<=Neff(*T); j++) {
			if (Elmt(*T,j) > k) {
				k = Elmt (*T,j);
				h = j;
			}
		}
		temp = Elmt (*T,i);
		Elmt(*T,i) = k;
		Elmt(*T,h) = temp;
	}
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
void InsSortAsc (TabInt * T) {
	int i,j,k,h,temp;
	
	for (i=2; i<=Neff(*T); i++) {
		temp = Elmt(*T,i);
		j = i-1;
		while (temp < Elmt(*T,j) && j>1) {
			Elmt(*T,j+1) = Elmt(*T,j);
			j--;
		}
		if (temp >= Elmt(*T,j)) {
			Elmt(*T,j+1) = temp;
		} else {
			Elmt(*T,j+1) = Elmt(*T,j);
			Elmt(*T,j) = temp;
		}
	}
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X) {
	Neff(*T) += 1;
	Elmt(*T,Neff(*T)) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabInt * T, ElType X, IdxType i) {
	int j;
	
	Neff(*T) += 1;
	if (i < Neff(*T)) {
		for (j = Neff(*T); j > i; j--) {
			Elmt(*T,j) = Elmt(*T,j-1);
		}
		Elmt(*T,i) = X;
	} else {
		Elmt(*T,i) = X;
	}
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) {
	*X = Elmt(*T,Neff(*T));
	Neff(*T) -= 1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, ElType * X) {
	int j;
	
	*X = Elmt(*T,i);
	for (j=i; j<Neff(*T); j++) {
		Elmt(*T,j) = Elmt(*T,j+1);
	}
	Neff(*T) -= 1;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X) {
	int i,j;
	
	if (Neff(*T) != 0) {
		j=0;
		for (i=1; i<=Neff(*T); i++) {
			if (Elmt(*T,i) == X) {
				j=1;
			}
		}
		if (j==1) {
			printf("nilai sudah ada\n");
		} else {
			Neff(*T) += 1;
			Elmt(*T,Neff(*T)) = X;
		}
	} else {
		Neff(*T) += 1;
		Elmt (*T,1) = X;
	}
}
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X) {
	int i;
	boolean Found;
	
	if (T.Neff != 0) {
		Found = false;
		i = 1;
		while ((!Found) && (i<=T.Neff)) {
			if (X == T.TI[i]) {
				Found = true;
			}
			i++;
		}
		if (Found) {
			return (i-1);
		} else {
			return (IdxUndef);
		}
	} else {
		return (IdxUndef);
	}
}
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
ElType MaxUrut (TabInt T) {
	int i,j;
	
	j = T.TI[1];
	for (i=2; i<=T.Neff; i++) {
		if (j < T.TI[i]) {
			j = T.TI[i];
		}
	}
	return (j);
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
ElType MinUrut (TabInt T) {
	int i,j;
	
	j = T.TI[1];
	for (i=2; i<= T.Neff; i++) {
		if (j > T.TI[i]) {
			j = T.TI[i];
		}
	}
	return (j);
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min) {
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
void Add1Urut (TabInt * T, ElType X){
	int i,j,k;

	j=0;
	if (Neff(*T) != 100) {
		Neff(*T) += 1;
		i = 1;
		while ((i<Neff(*T)) && (j==0)) {
			if (Elmt(*T,i) > X) {
				j = 1;
			}
			i++;
		}
		if (j == 1) {
			for (k=Neff(*T); k>=i; k--) {
				Elmt(*T,k) = Elmt(*T,k-1);
			}
			Elmt(*T,i-1) = X;
		} else {
			Elmt(*T,Neff(*T)) = X;
		}
	}
}
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
void Del1Urut (TabInt * T, ElType X) {
	int j,i;
	
	i = IdxUndef;
	for (j=Neff(*T); j>=1; j--) {
		if (Elmt(*T,j) == X) {
			i = j;
		}
	}
	if (i != IdxUndef) {
		for (j=i; j<Neff(*T); j++) {
			Elmt(*T,j) = Elmt(*T,j+1);
		}
		Neff(*T) -= 1;
	}
}
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
