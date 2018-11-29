#include "../Impl/bintree.c"
#include "../Impl/mesinkata.c"
#include "../Impl/mesinkar.c"
#include "../Header/tepokpramuka_type.h"
//#include "../Impl/mesinkata.c"
//#include "../Impl/mesinkar.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    BinTree Resep, Pohon, Recipe;
    addrNode P, PL, PR;
    BinTree L, R;
    infotypeRek K, K1, K2, K3, KL, KR, KDel;

    K.TabKata[0] = ' ';
    K.TabKata[1] = 'a';
    K.TabKata[2] = 'y';
    K.TabKata[3] = 'a';
    K.TabKata[4] = 'm';
    K.TabKata[5] = '\0';
    K.Length = 5;

    K1.TabKata[0] = ' ';
    K1.TabKata[1] = 'a';
    K1.TabKata[2] = 'y';
    K1.TabKata[3] = 'a';
    K1.TabKata[4] = 'm';
    K1.TabKata[5] = '\0';
    K1.Length = 5;

    K2.TabKata[0] = ' ';
    K2.TabKata[1] = 'a';
    K2.TabKata[2] = 'y';
    K2.TabKata[3] = 'a';
    K2.TabKata[4] = 'm';
    K2.TabKata[5] = '\0';
    K2.Length = 5;

    KL.TabKata[0] = ' ';
    KL.TabKata[1] = 't';
    KL.TabKata[2] = 'a';
    KL.TabKata[3] = 'h';
    KL.TabKata[4] = 'u';
    KL.TabKata[5] = '\0';
    KL.Length = 5;

    KR.TabKata[0] = ' ';
    KR.TabKata[1] = 'i';
    KR.TabKata[2] = 'k';
    KR.TabKata[3] = 'a';
    KR.TabKata[4] = 'n';
    KR.TabKata[5] = '\0';
    KR.Length = 5;

    //printf("sama gak? %d\n", IsKataSama(K1,K2));
    P = AlokNode(K);
    printf("cek alokasi Akar: %s [%d]\n ", Akar(P).TabKata, Akar(P).Length);

    L = AlokNode(KL);
    printf("cek alokasi L: %s [%d]\n ", Akar(L).TabKata, Akar(P).Length);

    R = AlokNode(KR);
    printf("cek alokasi R: %s [%d]\n", Akar(R).TabKata, Akar(P).Length);

    Resep = Tree(K1, L, R);
    printf("cek Akar(Resep): %s [%d]\n ", Akar(Resep).TabKata, Akar(Resep).Length);

    PrintTree(Resep,2);

    printf("Tinggi pohon biner: %d\n", Tinggi(Resep));

    printf("Level tahu: %.2f\n", Level(Resep, Akar(Left(Resep))));
    printf("Level ikan: %.2f\n", Level(Resep, Akar(Right(Resep))));

    printf("Jumlah element Resep: %d\n", NbElmt(Resep));
    printf("Jumlah element daun Resep: %d\n", NbDaun(Resep));
    printf("IsBiner: %d\n", IsBiner(Resep));
    printf("IsUnerLeft: %d\n", IsUnerLeft(Resep));
    printf("IsUnerRight: %d\n", IsUnerRight(Resep));
    printf("IsTreeOneElmt: %d\n", IsTreeOneElmt(Resep));

    DelDaun(&Resep, KL); //del daun kiri
    DelDaun(&Resep, KR); //del daun kanan
    printf("IsTreeOneElmt: %d\n", IsTreeOneElmt(Resep));

    DelDaunTerkiri(&Resep, &KDel);
    printf("cek Delete Akar: %s [%d]\n", KDel.TabKata, KDel.Length);

    Pohon = Tree(K1, Nil, Nil);
    printf("cek Akar(Pohon): %s [%d]\n", Akar(Pohon).TabKata, Akar(Pohon).Length);

    AddDaun(&Pohon , Akar(Pohon), KR, false);
    printf("cek Right(Pohon): %s [%d]\n", Akar(Right(Pohon)).TabKata, Akar(Right(Pohon)).Length);

    AddDaunTerkiri(&Pohon, KL);
    printf("cek Left(Pohon): %s [%d]\n", Akar(Left(Pohon)).TabKata, Akar(Left(Pohon)).Length);


    printf("Apakah ada KL? %d", SearchTree(Pohon, KL));

    DelDaunTerkiri(&Pohon, &KDel);
    printf("IsSKewLeft: %d\n", IsSkewLeft(Pohon));
    printf("IsSkewRight: %d\n", IsSkewRight(Pohon));

    buildRecipe(&Recipe);
    PrintTree(Recipe,2);
}
