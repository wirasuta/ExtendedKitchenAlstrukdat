/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotypeRek, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul ListRek rekursif. */

#include "../Header/bintree.h"
#include "../Impl/mesinkata.c"
#include "../Impl/mesinkar.c"
#include <stdlib.h>
#include <stdio.h>

/* *** Konstruktor *** */
BinTree Tree(infotypeRek Akar, BinTree L, BinTree R){
  addrNode A = AlokNode(Akar);
  if (A!=Nil){
    Left(A) = L;
    Right(A) = R;
  }
  return A;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika AlokasiRek berhasil */
/* Menghasilkan pohon kosong (Nil) jika AlokasiRek gagal */
void MakeTree(infotypeRek Akar, BinTree L, BinTree R, BinTree *P){
  *P = Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika AlokasiRek berhasil. P = Nil jika AlokasiRek gagal. */

/* Manajemen Memory */
addrNode AlokNode(infotypeRek X){
  addrNode P = (addrNode) malloc(sizeof(Node));
  if (P != Nil) {
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;
  }
  return P;
}
/* Mengirimkan addrNode hasil AlokasiRek sebuah elemen */
/* Jika AlokasiRek berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika AlokasiRek gagal, mengirimkan Nil */
void DealokNode(addrNode P){
  free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan deAlokasiRek/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
  return (P==Nil);
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
  if (P!=Nil) {
    return (Left(P)==Nil && Right(P)==Nil);
  } else {
    return false;
  }
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
  if (P!=Nil) {
    return (Left(P)!=Nil && Right(P)==Nil);
  } else {
    return false;
  }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
  if (P!=Nil) {
    return (Left(P)==Nil && Right(P)!=Nil);
  } else {
    return false;
  }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
  if (P!=Nil) {
    return (Left(P)!=Nil && Right(P)!=Nil);
  } else {
    return false;
  }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
/*void PrintPreorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)) {
    printf("%s", Akar(P).TabKata);
    PrintPreorder(Left(P));
    PrintPreorder(Right(P));
  }
  printf(")");
}*/
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
/*void PrintInorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)) {
    PrintInorder(Left(P));
    printf("%s", Akar(P).TabKata);
    PrintInorder(Right(P));
  }
  printf(")");
}*/
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
/*void PrintPostorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)) {
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%s", Akar(P).TabKata);
  }
  printf(")");
}*/
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTreeRek(BinTree P, int h, int curr_level){
  if (!IsTreeEmpty(P)) {
    int i,j;
    for (i = 1; i <= curr_level; i++) {
      for (j = 1; j <= h; j++) {
        printf(" ");
      }
    }
    printf("%s\n", Akar(P).TabKata);
    PrintTreeRek(Left(P), h, curr_level+1);
    PrintTreeRek(Right(P), h, curr_level+1);
  }
}

void PrintTree(BinTree P, int h){
  PrintTreeRek(P, h, 0);
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E

A
|
|-B
|-C
   |-D
   |-D
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotypeRek X){
  if (IsTreeEmpty(P)){
    return false;
  }else if (IsKataSama(Akar(P), X)){
    return true;
  }else{
    return (SearchTree(Right(P), X) || SearchTree(Left(P), X));
  }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
  if (IsTreeEmpty(P)) {
    return 0;
  }else{
    return 1+NbElmt(Right(P))+NbElmt(Left(P));
  }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
  if (IsTreeEmpty(P)) {
    return 0;
  }else if (IsTreeOneElmt(P)){
    return 1;
  }else if (IsUnerLeft(P)){
    return NbDaun(Left(P));
  }else if (IsUnerRight(P)){
    return NbDaun(Right(P));
  }else{
    return (NbDaun(Right(P)) + NbDaun(Left(P)));
  }
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
  if (IsTreeEmpty(P)) {
    return true;
  }else if (IsTreeOneElmt(P)){
    return true;
  }else if (IsUnerLeft(P)){
    return (true && IsSkewLeft(Left(P)));
  }else{
    return false;
  }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
  if (IsTreeEmpty(P)) {
    return true;
  }else if (IsTreeOneElmt(P)){
    return true;
  }else if (IsUnerRight(P)){
    return (true && IsSkewRight(Right(P)));
  }else{
    return false;
  }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
double Level(BinTree P, infotypeRek X){
  if (IsKataSama(Akar(P), X)) {
    return 1;
  } else {
    if (SearchTree(Left(P), X)) {
      return 1+Level(Left(P),X);
    }else{
      return 1+Level(Right(P),X);
    }
  }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
  if (IsTreeEmpty(P)) {
    return 0;
  }else{
    if (Tinggi(Right(P)) > Tinggi(Left(P))){
      return 1+Tinggi(Right(P));
    }else{
      return 1+Tinggi(Left(P));
    }
  }
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotypeRek X){
  if (IsTreeEmpty(*P)) {
    *P = AlokNode(X);
  }else{
    if (IsUnerRight(*P)) {
      Left(*P) = AlokNode(X);
    } else {
      AddDaunTerkiri(&(Left(*P)), X);
    }
  }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotypeRek X, infotypeRek Y, boolean Kiri){
  if (IsTreeOneElmt(*P) && IsKataSama(Akar(*P), X)) {
    //printf("sama kok %d\n", IsKataSama(Akar(*P), X));
    if (Kiri){
      Left(*P) = AlokNode(Y);
      //printf("cek masuk: %s", Left(*P));
    }else{
      Right(*P) = AlokNode(Y);
    }
  } else {
    if (SearchTree(Left(*P), X)) {
      AddDaun(&(Left(*P)), X, Y, Kiri);
    } else {
      AddDaun(&(Right(*P)), X, Y, Kiri);
    }
  }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotypeRek *X){
  if (IsTreeOneElmt(*P)) {
    BinTree Temp = *P;
    *X = Akar(*P);
    *P = Nil;
    DealokNode(Temp);
  }else{
    if (IsUnerRight(*P)) {
      DelDaunTerkiri(&(Right(*P)), X);
    } else {
      DelDaunTerkiri(&(Left(*P)), X);
    }
  }
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan dideAlokasiRek, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotypeRek X){
  if (IsTreeOneElmt(*P) && IsKataSama(Akar(*P), X)) {
    BinTree Temp = *P;
    *P = Nil;
    DealokNode(Temp);
  } else {
    if (SearchTree(Left(*P), X)) {
      DelDaun(&(Left(*P)), X);
    }
    if (SearchTree(Right(*P), X)) {
      DelDaun(&(Right(*P)), X);
    }
  }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
/*ListRek MakeListDaun(BinTree P){
  if (IsTreeEmpty(P)) {
    return Nil;
  }else if (IsTreeOneElmt(P)) {
    return AlokasiRek(Akar(P));
  } else {
    return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
  }
}*/
/* Jika P adalah pohon kosong, maka menghasilkan ListRek kosong. */
/* Jika P bukan pohon kosong: menghasilkan ListRek yang elemennya adalah semua daun pohon P,
   jika semua AlokasiRek ListRek berhasil.
   Daun terkiri menjadi elemen pertama dari ListRek  diikuti elemen kanannya, dst.
   Menghasilkan ListRek kosong jika ada AlokasiRek yang gagal. */
/*ListRek MakeListPreorder(BinTree P){
  if (IsTreeEmpty(P)) {
    return Nil;
  }else if (IsTreeOneElmt(P)) {
    return AlokasiRek(Akar(P));
  } else {
    return Concat(Konso(Akar(P),MakeListPreorder(Left(P))), MakeListPreorder(Right(P)));
  }
}*/
/* Jika P adalah pohon kosong, maka menghasilkan ListRek kosong. */
/* Jika P bukan pohon kosong: menghasilkan ListRek yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua AlokasiRek berhasil.
   Menghasilkan ListRek kosong jika ada AlokasiRek yang gagal. */
/*ListRek MakeListLevel(BinTree P, int N){
  if (IsTreeEmpty(P)){
    return Nil;
  } else {
    if (N==1) {
      return AlokasiRek(Akar(P));
    } else {
      return Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1));
    }
  }
}*/
/* Jika P adalah pohon kosong, maka menghasilkan ListRek kosong. */
/* Jika P bukan pohon kosong: menghasilkan ListRek yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua AlokasiRek berhasil.
   Elemen terkiri menjadi elemen pertama dari ListRek  diikuti elemen kanannya, dst.
   Menghasilkan ListRek kosong jika ada AlokasiRek yang gagal. */