// Body untuk mesinkata.h
// Pandyaka Aptanagi / 13517003

#include "../Header/mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ? BLANK atau CC = MARK */
{
	// Kamus

	// Algoritma
   while ((CC == BLANK) && (CC != MARK))
   {
       ADV();
   }
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	// Kamus

	// Algoritma
	START();
	IgnoreBlank();
	if ( CC == MARK)
		{
			EndKata = true;
		}
	else
		{
			EndKata = false;
			SalinKata();
		}

}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	// Kamus

	// Algoritma
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else
	{
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong"
*/
{
	// Kamus
    int i = 1;

    // Algoritma
    for (;;)
    	{
    		CKata.TabKata[i] = CC;
    		ADV();
    		if ( (CC== MARK) || ( CC == BLANK) )
    			{
    				break;
    			}
    		else
				{
					if ( i < 50 )
						{
							i++;
						}
					else
						{
							break;
						}
				}
		}
	CKata.Length = i;
}

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

        length2 = K2.Length;

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

void SetKataLength(Kata *K){
  int length;

  length = 0;
  while ((*K).TabKata[length] != '\x00')
  {
      length++;
  }
  K->Length = length;
}
