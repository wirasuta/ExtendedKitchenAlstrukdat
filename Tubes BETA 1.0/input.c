#include <stdio.h>
#include "mesinkata.c"

boolean IsKataSama(Kata K1, Kata K2)
/*
Pengganti strcmp, Kata harus di-set per K1.TabKata[i]
contoh:
    K1.TabKata[0] = 'k';
    K1.TabKata[1] = 'e';
    K1.TabKata[2] = 'l';

*/
{
    //kamus
    int i, length1, length2;
    boolean sama;

    //algoritma

    length1 = 0;
    length2 = 0;

        while (K1.TabKata[length1] != '\x00')
        {
            length1++;
        }

        while (K2.TabKata[length2] != '\x00')
        {
            length2++;
        }


        i = 0;
        sama = true;

        if(length1 != length2)
        {
            sama = false;
        }
        else
        {
        while ((sama) && i <= length1)
               {
                 if (K1.TabKata[i] == K2.TabKata[i])
                 {
                 i++;
                 }
                 else
                 {
                     sama = false;
                 }
               }
        }
    return sama;

}


//contoh penggunaan

/*int main()
{
    Kata a;
    Kata b;
    int i;

    b.TabKata[0] = 'k';
    b.TabKata[1] = 'e';
    b.TabKata[2] = 'l';

    // input kata untukk dibandingkan dengan 'kel'
    scanf(" %s", a.TabKata);

    //print input
    for (i = 0; i <4; i++)
    {
        printf("%c", a.TabKata[i]);
    }

    printf("\n");

    //print hasil perbandingan dengan kata kel
    printf("IsKataKel: %d", IsKataSama(a, b));
}*/
