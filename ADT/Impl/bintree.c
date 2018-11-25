/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotypeRek, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul ListRek rekursif. */

#include "../Header/bintree.h"
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
void PrintPreorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)) {
    printf("%s", Akar(P).TabKata);
    PrintPreorder(Left(P));
    PrintPreorder(Right(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)) {
    PrintInorder(Left(P));
    printf("%s", Akar(P).TabKata);
    PrintInorder(Right(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)) {
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%s", Akar(P).TabKata);
  }
  printf(")");
}
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

void AddDaunTerkanan(BinTree *P, infotypeRek X){
  if (IsTreeEmpty(*P)) {
    *P = AlokNode(X);
  }else{
    if (IsUnerLeft(*P)) {
      Right(*P) = AlokNode(X);
    } else {
      AddDaunTerkanan(&(Right(*P)), X);
    }
  }
}

/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotypeRek X, infotypeRek Y, boolean Kiri){
  if (IsTreeOneElmt(*P) && IsKataSama(Akar(*P), X)) {
    if (Kiri){
      Left(*P) = AlokNode(Y);
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

void buildRecipe(BinTree *P){
  BinTree Resep;
  Kata T[100];
  addrNode D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15, D16, D17, D18, D19, D20, D21, D22, D23, D24;


  T[0].TabKata[0]=' ';
  T[0].TabKata[1]='p';
  T[0].TabKata[2]='i';
  T[0].TabKata[3]='r';
  T[0].TabKata[4]='i';
  T[0].TabKata[5]='n';
  T[0].TabKata[6]='g';
  T[0].TabKata[7]='\0';
  T[0].Length=7;

  T[1].TabKata[0]=' ';
  T[1].TabKata[1]='s';
  T[1].TabKata[2]='e';
  T[1].TabKata[3]='n';
  T[1].TabKata[4]='d';
  T[1].TabKata[5]='o';
  T[1].TabKata[6]='k';
  T[1].TabKata[7]='\0';
  T[1].Length=7;

  T[2].TabKata[0]=' ';
  T[2].TabKata[1]='g';
  T[2].TabKata[2]='a';
  T[2].TabKata[3]='r';
  T[2].TabKata[4]='p';
  T[2].TabKata[5]='u';
  T[2].TabKata[6]='\0';
  T[2].Length=6;

  T[3].TabKata[0]=' ';
  T[3].TabKata[1]='e';
  T[3].TabKata[2]='s';
  T[3].TabKata[3]='k';
  T[3].TabKata[4]='r';
  T[3].TabKata[5]='i';
  T[3].TabKata[6]='m';
  T[3].TabKata[7]='\0';
  T[3].Length=7;

  T[4].TabKata[0]=' ';
  T[4].TabKata[1]='n';
  T[4].TabKata[2]='a';
  T[4].TabKata[3]='s';
  T[4].TabKata[4]='i';
  T[4].TabKata[5]='\0';
  T[4].Length=5;

  T[5].TabKata[0]=' ';
  T[5].TabKata[1]='r';
  T[5].TabKata[2]='o';
  T[5].TabKata[3]='t';
  T[5].TabKata[4]='i';
  T[5].TabKata[5]='\0';
  T[5].Length=5;

  T[6].TabKata[0]=' ';
  T[6].TabKata[1]='s';
  T[6].TabKata[2]='p';
  T[6].TabKata[3]='a';
  T[6].TabKata[4]='g';
  T[6].TabKata[5]='h';
  T[6].TabKata[6]='e';
  T[6].TabKata[7]='t';
  T[6].TabKata[8]='t';
  T[6].TabKata[9]='i';
  T[6].TabKata[10]='\0';
  T[6].Length=10;

  T[7].TabKata[0]=' ';
  T[7].TabKata[1]='p';
  T[7].TabKata[2]='i';
  T[7].TabKata[3]='s';
  T[7].TabKata[4]='a';
  T[7].TabKata[5]='n';
  T[7].TabKata[6]='g';
  T[7].TabKata[7]='\0';
  T[7].Length=7;

  T[8].TabKata[0]=' ';
  T[8].TabKata[1]='s';
  T[8].TabKata[2]='t';
  T[8].TabKata[3]='r';
  T[8].TabKata[4]='o';
  T[8].TabKata[5]='b';
  T[8].TabKata[6]='e';
  T[8].TabKata[7]='r';
  T[8].TabKata[8]='i';
  T[8].TabKata[9]='\0';
  T[8].Length=9;

  T[9].TabKata[0]=' ';
  T[9].TabKata[1]='t';
  T[9].TabKata[2]='e';
  T[9].TabKata[3]='l';
  T[9].TabKata[4]='u';
  T[9].TabKata[5]='r';
  T[9].TabKata[6]='\0';
  T[9].Length=6;

  T[10].TabKata[0]=' ';
  T[10].TabKata[1]='a';
  T[10].TabKata[2]='y';
  T[10].TabKata[3]='a';
  T[10].TabKata[4]='m';
  T[10].TabKata[5]='g';
  T[10].TabKata[6]='o';
  T[10].TabKata[7]='r';
  T[10].TabKata[8]='e';
  T[10].TabKata[9]='n';
  T[10].TabKata[10]='g';
  T[10].TabKata[11]='\0';
  T[10].Length=11;

  T[11].TabKata[0]=' ';
  T[11].TabKata[1]='p';
  T[11].TabKata[2]='a';
  T[11].TabKata[3]='t';
  T[11].TabKata[4]='t';
  T[11].TabKata[5]='y';
  T[11].TabKata[6]='\0';
  T[11].Length=6;

  T[12].TabKata[0]=' ';
  T[12].TabKata[1]='s';
  T[12].TabKata[2]='o';
  T[12].TabKata[3]='s';
  T[12].TabKata[4]='i';
  T[12].TabKata[5]='s';
  T[12].TabKata[6]='\0';
  T[12].Length=6;

  T[13].TabKata[0]=' ';
  T[13].TabKata[1]='b';
  T[13].TabKata[2]='o';
  T[13].TabKata[3]='l';
  T[13].TabKata[4]='o';
  T[13].TabKata[5]='g';
  T[13].TabKata[6]='n';
  T[13].TabKata[7]='e';
  T[13].TabKata[8]='s';
  T[13].TabKata[9]='e';
  T[13].TabKata[10]='\0';
  T[13].Length=10;

  T[14].TabKata[0]=' ';
  T[14].TabKata[1]='c';
  T[14].TabKata[2]='a';
  T[14].TabKata[3]='r';
  T[14].TabKata[4]='b';
  T[14].TabKata[5]='o';
  T[14].TabKata[6]='n';
  T[14].TabKata[7]='a';
  T[14].TabKata[8]='r';
  T[14].TabKata[9]='a';
  T[14].TabKata[10]='\0';
  T[14].Length=10;

  T[15].TabKata[0]=' ';
  T[15].TabKata[1]='b';
  T[15].TabKata[2]='a';
  T[15].TabKata[3]='n';
  T[15].TabKata[4]='a';
  T[15].TabKata[5]='n';
  T[15].TabKata[6]='a';
  T[15].TabKata[7]='s';
  T[15].TabKata[8]='p';
  T[15].TabKata[9]='l';
  T[15].TabKata[10]='i';
  T[15].TabKata[11]='t';
  T[15].TabKata[12]='\0';
  T[15].Length=12;

  T[16].TabKata[0]=' ';
  T[16].TabKata[1]='s';
  T[16].TabKata[2]='u';
  T[16].TabKata[3]='n';
  T[16].TabKata[4]='d';
  T[16].TabKata[5]='a';
  T[16].TabKata[6]='e';
  T[16].TabKata[7]='\0';
  T[16].Length=7;

  T[17].TabKata[0]=' ';
  T[17].TabKata[1]='n';
  T[17].TabKata[2]='a';
  T[17].TabKata[3]='s';
  T[17].TabKata[4]='i';
  T[17].TabKata[5]='t';
  T[17].TabKata[6]='e';
  T[17].TabKata[7]='l';
  T[17].TabKata[8]='u';
  T[17].TabKata[9]='r';
  T[17].TabKata[10]='d';
  T[17].TabKata[11]='a';
  T[17].TabKata[12]='d';
  T[17].TabKata[13]='a';
  T[17].TabKata[14]='r';
  T[17].TabKata[15]='\0';
  T[17].Length=15;

  T[18].TabKata[0]=' ';
  T[18].TabKata[1]='n';
  T[18].TabKata[2]='a';
  T[18].TabKata[3]='s';
  T[18].TabKata[4]='i';
  T[18].TabKata[5]='a';
  T[18].TabKata[6]='y';
  T[18].TabKata[7]='a';
  T[18].TabKata[8]='m';
  T[18].TabKata[9]='g';
  T[18].TabKata[10]='o';
  T[18].TabKata[11]='r';
  T[18].TabKata[12]='e';
  T[18].TabKata[13]='n';
  T[18].TabKata[14]='g';
  T[18].TabKata[15]='\0';
  T[18].Length=15;

  T[19].TabKata[0]=' ';
  T[19].TabKata[1]='b';
  T[19].TabKata[2]='u';
  T[19].TabKata[3]='r';
  T[19].TabKata[4]='g';
  T[19].TabKata[5]='e';
  T[19].TabKata[6]='r';
  T[19].TabKata[7]='\0';
  T[19].Length=7;

  T[20].TabKata[0]=' ';
  T[20].TabKata[1]='h';
  T[20].TabKata[2]='o';
  T[20].TabKata[3]='t';
  T[20].TabKata[4]='d';
  T[20].TabKata[5]='o';
  T[20].TabKata[6]='g';
  T[20].TabKata[7]='\0';
  T[20].Length=7;

  T[21].TabKata[0]=' ';
  T[21].TabKata[1]='k';
  T[21].TabKata[2]='e';
  T[21].TabKata[3]='j';
  T[21].TabKata[4]='u';
  T[21].TabKata[5]='\0';
  T[21].Length=5;

  T[22].TabKata[0]=' ';
  T[22].TabKata[1]='s';
  T[22].TabKata[2]='p';
  T[22].TabKata[3]='a';
  T[22].TabKata[4]='g';
  T[22].TabKata[5]='h';
  T[22].TabKata[6]='e';
  T[22].TabKata[7]='t';
  T[22].TabKata[8]='t';
  T[22].TabKata[9]='i';
  T[22].TabKata[10]='c';
  T[22].TabKata[11]='a';
  T[22].TabKata[12]='r';
  T[22].TabKata[13]='b';
  T[22].TabKata[14]='o';
  T[22].TabKata[15]='n';
  T[22].TabKata[16]='a';
  T[22].TabKata[17]='r';
  T[22].TabKata[18]='a';
  T[22].TabKata[19]='\0';
  T[22].Length=19;

  T[23].TabKata[0]=' ';
  T[23].TabKata[1]='s';
  T[23].TabKata[2]='p';
  T[23].TabKata[3]='a';
  T[23].TabKata[4]='g';
  T[23].TabKata[5]='h';
  T[23].TabKata[6]='e';
  T[23].TabKata[7]='t';
  T[23].TabKata[8]='t';
  T[23].TabKata[9]='i';
  T[23].TabKata[10]='b';
  T[23].TabKata[11]='o';
  T[23].TabKata[12]='l';
  T[23].TabKata[13]='o';
  T[23].TabKata[14]='g';
  T[23].TabKata[15]='n';
  T[23].TabKata[16]='e';
  T[23].TabKata[17]='s';
  T[23].TabKata[18]='e';
  T[23].TabKata[19]='\0';
  T[23].Length=19;

  /*D1 = AlokNode(T[0]);
  D2 = AlokNode(T[1]);
  D3 = AlokNode(T[2]);
  D4 = AlokNode(T[3]);
  D5 = AlokNode(T[4]);
  D6 = AlokNode(T[5]);
  D7 = AlokNode(T[6]);
  D8 = AlokNode(T[7]);
  D9 = AlokNode(T[8]);
  D10 = AlokNode(T[9]);
  D11 = AlokNode(T[10]);
  D12 = AlokNode(T[11]);
  D13 = AlokNode(T[12]);
  D14 = AlokNode(T[13]);
  D15 = AlokNode(T[14]);
  D16 = AlokNode(T[15]);
  D17 = AlokNode(T[16]);
  D18 = AlokNode(T[17]);
  D19 = AlokNode(T[18]);
  D20 = AlokNode(T[19]);
  D21 = AlokNode(T[20]);
  D22 = AlokNode(T[21]);
  D23 = AlokNode(T[22]);
  D24 = AlokNode(T[23]);*/

  Resep = Tree(T[0],Nil,Nil);
  //printf("cek %s", Akar(Resep));

  //AddDaun(&Resep, Akar(Resep), T[1], false);
  //printf("cek %s\n", Right(Resep));
  AddDaunTerkiri(&Resep, T[1]);
  //printf("cek %s\n", Left(Resep));
  AddDaunTerkanan(&Resep, T[2]);
  //printf("cek %s\n", Right(Resep));

  AddDaunTerkiri(&Left(Resep), T[3]);
  AddDaunTerkanan(&Left(Resep), T[4]);

  AddDaunTerkiri(&Right(Resep), T[5]);
  AddDaunTerkanan(&Right(Resep), T[6]);

  AddDaunTerkiri(&Left(Left(Resep)), T[7]);
  AddDaunTerkanan(&Left(Left(Resep)), T[8]);

  AddDaunTerkiri(&Right(Left(Resep)), T[9]);
  AddDaunTerkanan(&Right(Left(Resep)), T[10]);

  AddDaunTerkiri(&Left(Right(Resep)), T[11]);
  AddDaunTerkanan(&Left(Right(Resep)), T[12]);

  AddDaunTerkiri(&Right(Right(Resep)), T[13]);
  AddDaunTerkanan(&Right(Right(Resep)), T[14]);

  AddDaunTerkiri(&Left(Left(Left(Resep))), T[15]);

  AddDaunTerkiri(&Right(Left(Left(Resep))), T[16]);

  AddDaunTerkiri(&Left(Right(Left(Resep))), T[17]);

  AddDaunTerkanan(&Right(Right(Left(Resep))), T[18]);

  AddDaunTerkiri(&Left(Left(Right(Resep))), T[19]);

  AddDaunTerkiri(&Right(Left(Right(Resep))), T[20]);

  AddDaunTerkiri(&Left(Right(Right(Resep))), T[21]);

  AddDaunTerkiri(&Right(Right(Right(Resep))), T[22]);

  AddDaunTerkiri(&Left(Left(Right(Right(Resep)))), T[23]);


  //AddDaunTerkiri(&Resep, T[3]);
  //AddDaun(&Resep, T[1], T[4], false);
  //AddDaun(&Resep, T[1], T[3], true);
  //AddDaunTerkanan(&Resep, T[4]);

  //AddDaun(&Resep, T[1], T[3], false);
  //AddDaunTerkiri(&Resep, T[4]);
  //AddDaun(&Resep, T[1], T[4], true);

  *P = Resep;
  //PrintTree(Resep,2);
}
