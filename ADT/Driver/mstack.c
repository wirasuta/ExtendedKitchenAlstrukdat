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

    printf("%s\n", A);
    printf("%s\n", B);
    printf("\n");

    CreateEmptyStack(&S1);
    CreateEmptyStack(&S2);

    printf("cek isStackEmpty: %d\n", IsStackEmpty(S1));
    printf("cek isStackFull: %d\n", IsStackFull(S1));

    Push(&S2, A);
    printf("InfoTop: %s\n", InfoTop(S2));

    Push(&S2, B);
    printf("InfoTop: %s\n", InfoTop(S2));

    Pop(&S2, &C);
    printf("Pop: %s\n", C);
    printf("InfoTop: %s\n", InfoTop(S2));
    
    Pop(&S2, &C);
    printf("Pop: %s\n", C);
    printf("cek isStackEmpty: %d\n", IsStackEmpty(S2));
}