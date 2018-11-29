#include "../Impl/stackt.c"
#include "../Header/tepokpramuka_type.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Kata A,B,C,D;
    Stack S1, S2;

    A.TabKata[0] = 'h';
    A.TabKata[1] = 'a';
    A.TabKata[2] = 'l';
    A.TabKata[3] = 'o';
    A.TabKata[4] = '\0';
    A.Length = 4;

    B.TabKata[0] = 'p';
    B.TabKata[1] = 'a';
    B.TabKata[2] = 'g';
    B.TabKata[3] = 'i';
    B.TabKata[4] = '\0';
    B.Length = 4;

    printf("Isi Kata : \n");
    printf("%s\n", A.TabKata);
    printf("%s\n", B.TabKata);
    printf("\n");

    CreateEmptyStack(&S1);
    CreateEmptyStack(&S2);

    printf("===== Cek Fungsi isStackEmpty S2 =====\n ");
    printf("cek isStackEmpty: %d\n", IsStackEmpty(S2));
    printf("===== Cek Fungsi isStackFull S2 =====\n ");
    printf("cek isStackFull: %d\n", IsStackFull(S2));

    printf("===== Cek Fungsi Push Kata A ke Stack 2 =====\n ");
    Push(&S2, A);
    printf("InfoTop: %s [%d]\n", InfoTop(S2).TabKata,InfoTop(S2).Length);

    printf("===== Cek Fungsi Push Kata B ke Stack 2 =====\n ");
    Push(&S2, B);
    printf("InfoTop: %s [%d]\n", InfoTop(S2).TabKata,InfoTop(S2).Length);

    printf("===== Cek Fungsi Pop InfoTop Stack 2 =====\n ");
    Pop(&S2, &C);
    printf("Pop: %s [%d]\n", C.TabKata, C.Length);
    printf("InfoTop: %s [%d]\n", InfoTop(S2).TabKata,InfoTop(S2).Length);

    printf("===== Cek Fungsi Push Infotop S2 ke S1 =====\n ");
    Push(&S1, C);
    printf("Push: %s [%d]\n", C.TabKata, C.Length);
    printf("InfoTop: %s [%d]\n", InfoTop(S2).TabKata,InfoTop(S2).Length);

    printf("===== Cek Fungsi isStackEmpty S1 =====\n ");
    printf("cek isStackEmpty: %d\n", IsStackEmpty(S1));
}
