// Driver untuk ADT Jam
// Pandyaka Aptanagi / 13517003

#include <stdio.h>
#include "../Header/jam.h"

int main ()
    {
        // Kamus Lokal
        JAM J1,J2;

        // Algoritma
        printf("Masukkan Jam 1 : \n");
        BacaJAM(&J1);
        TulisJAM(J1);
        printf("\n");

        printf("Masukkan Jam 2 : \n");
        BacaJAM(&J2);
        TulisJAM(J2);
        printf("\n");

        printf("J1 in detik : %d\n",JAMToDetik(J1));
        printf("J2 in detik: %d\n",JAMToDetik(J2));

        //konversi detik ke jam
        long detik;
        printf("Masukan detik: ");
        scanf("%ld",&detik);
        printf("Jamnya: ");
        TulisJAM(DetikToJAM(detik));
        printf("\n");

        (JEQ(J1,J2)) ? printf("JEQ bernilai true\n"):printf("JEQ bernilai false\n");
        (JNEQ(J1,J2)) ? printf("JNEQ bernilai true\n"):printf("JNEQ bernilai false\n");
        (JLT(J1,J2)) ? printf("JLT bernilai true\n"):printf("JLT bernilai false\n");
        (JGT(J1,J2)) ? printf("JGT bernilai true\n"):printf("JGT bernilai false\n");

        int n;
        printf("satu detik setelah "); TulisJAM(J1); printf(" adalah "); TulisJAM(NextDetik(J1));
        printf("\n");
        //NextNDetik
        printf("masukan nilai n:"); scanf("%d", &n);
        printf("%d detik setelah ",n); TulisJAM(J1); printf(" adalah "); TulisJAM(NextNDetik(J1,n));
        printf("\n");
        //PrevDetik
        printf("satu detik sebelum "); TulisJAM(J2); printf(" adalah "); TulisJAM(PrevDetik(J2));
        printf("\n");
        //PrevNDetik
        printf("%d detik sebelum ",n); TulisJAM(J2); printf(" adalah "); TulisJAM(PrevNDetik(J2,n));
        printf("\n");
        //fungsi Durasi
        printf("perbedaan antara jam "); TulisJAM(J1); printf(" dan jam "); TulisJAM(J2);
        printf(" adalah %ld detik atau ",Durasi(J1,J2)); TulisJAM(DetikToJAM(Durasi(J1,J2)));
        printf("\n");

        return 0;
    }
