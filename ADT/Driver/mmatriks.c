#include "../Impl/matriks.c"
#include "../Header/tepokpramuka_type.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    MATRIKS M1, M2, M3;

    MakeMATRIKS(3,3,&M1);
    printf("NBrsEff M1:%d, NKolEff M1: %d\n", NBrsEff(M1), NKolEff(M1));

    MakeMATRIKS(2,4,&M2);
    printf("NBrsEff M2:%d, NKolEff M2: %d\n", NBrsEff(M2), NKolEff(M2));

    printf("Is 3,4 valid for all matrix? %d\n", IsIdxValidMat(3,4));

    printf("Is 3,4 valid for M1(3x3)? %d\n", IsIdxEffMat(M1, 3,4));
    printf("Is 2,3 valid for M1(3x3)? %d\n", IsIdxEffMat(M1, 2,3));

    printf("Rentang indeks baris M2(2x4) adalah %d sampai %d\n", GetFirstIdxBrs(M2), GetLastIdxBrs(M2));
    printf("Rentang indeks kolom M2(2x4) adalah %d sampai %d\n", GetFirstIdxKol(M2), GetLastIdxKol(M2));

    printf("Banyak elemen M2(2x4): %d\n", NBElmt(M2));
    
    printf("\n");
    printf("Masukkan elemen matriks M3(3x3):\n");
    BacaMATRIKS(&M1,3,3);
    TulisMATRIKS(M1);

}