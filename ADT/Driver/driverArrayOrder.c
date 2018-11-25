#include <stdio.h>
#include "boolean.h"
#include "arrayOrder.c"
#include "mesinkata.c"
#include "mesinkar.c"

int main(){
    IdxType idx;
    TabOrder T;
    Kata Makanan;
    boolean cek;
    ElTypeInfoOrder X;

    MakeEmpty(&T);

    T.TI[1].Name.TabKata[0]=' ';
    T.TI[1].Name.TabKata[1]='s';
    T.TI[1].Name.TabKata[2]='p';
    T.TI[1].Name.TabKata[3]='a';
    T.TI[1].Name.TabKata[4]='g';
    T.TI[1].Name.TabKata[5]='e';
    T.TI[1].Name.TabKata[6]='t';
    T.TI[1].Name.TabKata[7]='i';
    T.TI[1].Name.TabKata[8]='\0';
    T.TI[1].Name.Length=7;
    T.TI[1].Nomor=2;
    T.TI[2].Name.TabKata[0]=' ';
    T.TI[2].Name.TabKata[1]='a';
    T.TI[2].Name.TabKata[2]='y';
    T.TI[2].Name.TabKata[3]='a';
    T.TI[2].Name.TabKata[4]='m';
    T.TI[2].Name.TabKata[5]='\0';
    T.TI[2].Name.Length=4;
    T.TI[2].Nomor=3;
    T.TI[3].Name.TabKata[0]=' ';
    T.TI[3].Name.TabKata[1]='b';
    T.TI[3].Name.TabKata[2]='u';
    T.TI[3].Name.TabKata[3]='r';
    T.TI[3].Name.TabKata[4]='g';
    T.TI[3].Name.TabKata[5]='e';
    T.TI[3].Name.TabKata[6]='r';
    T.TI[3].Name.TabKata[7]='\0';
    T.TI[3].Name.Length=6;
    T.TI[3].Nomor=1;
    T.Neff=3;

    printf("\n");
    printf("Banyaknya elemen efektif tabel: %d\n",NbElmtArr(T));
    printf("Maksimum elemen yang dapat ditampung oleh tabel: %d\n",MaxNbEl(T));
    printf("Indeks elemen T pertama: %d\n",GetFirstIdx(T));
    printf("Indeks elemen T terakhir: %d\n",GetLastIdx(T));

    printf("Indeks yang ingin dicek: 2\n");
    idx=2;
    printf("\n");
    printf("IsIdxOValid(T,idx)= %d\n",IsIdxOValid(T,idx));
    printf("IsIdxOEff(T,idx)= %d\n",IsIdxOEff(T,idx));

    printf("IsOEmpty(T)= %d\n",IsOEmpty(T));
    printf("IsOFull(T)= %d\n", IsOFull(T));

    printf("Output: \n");
    TulisIsiTab(T);
    printf("\n");

    Makanan.TabKata[0]=' ';
    Makanan.TabKata[1]='a';
    Makanan.TabKata[2]='y';
    Makanan.TabKata[3]='a';
    Makanan.TabKata[4]='m';
    Makanan.TabKata[5]='\0';
    Makanan.Length=4;
    printf("SearchBoolean(TabOrder T, int Meja=3, Kata Makanan=ayam)= %d\n",SearchBoolean(T,3,Makanan));
    printf("SearchIndex (TabOrder T, int Meja=3, Kata Makanan=ayam)= %d\n",SearchIndex (T, 3, Makanan));
    printf("Setelah ditambahkan ayam sebagai elemen terakhir:\n");
    AddAsLastEl ( &T, T.TI[2]);
    TulisIsiTab(T);
    printf("Setelah elemen ke-2 didelete: \n");
    DelEli (&T, 2, &X);
    TulisIsiTab(T);
    printf("Isi X:\n%s\nnomor %d\n",X.Name.TabKata,X.Nomor);
}
