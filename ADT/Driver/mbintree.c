#include "../Impl/bintree.c"
#include "../Header/tepokpramuka_type.h"
//#include "../Impl/mesinkata.c"
//#include "../Impl/mesinkar.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    BinTree Resep, Pohon;
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
    printf("cek alokasi Akar:%s\n", Akar(P));

    L = AlokNode(KL);
    printf("cek alokasi L:%s\n", Akar(L));

    R = AlokNode(KR);
    printf("cek alokasi R:%s\n", Akar(R));

    Resep = Tree(K1, L, R);
    printf("cek Akar(Resep):%s\n", Akar(Resep));
    printf("cek Left(Resep):%s\n", Left(Resep));
    printf("cek Right(Resep):%s\n", Right(Resep));

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
    printf("cek Delete Akar:%s\n", KDel);

    Pohon = Tree(K1, Nil, Nil);
    printf("cek Akar(Pohon):%s\n", Akar(Pohon));
    
    AddDaun(&Pohon , Akar(Pohon), KR, false);
    printf("cek Right(Pohon):%s\n", Right(Pohon));

    AddDaunTerkiri(&Pohon, KL);
    printf("cek Left(Pohon):%s\n", Left(Pohon));

    printf("Apakah ada KL? %d", SearchTree(Pohon, KL));

    DelDaunTerkiri(&Pohon, &KDel);
    printf("IsSKewLeft: %d\n", IsSkewLeft(Pohon));
    printf("IsSkewRight: %d\n", IsSkewRight(Pohon));

}
