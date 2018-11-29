#include <stdio.h>
#include <stdlib.h>
#include "ADT/Header/mesinkata.h"

void load()
{


    Kata data[20][50];

    int p,q;
    int a,b,c,d;
    int j =1;
    p = 1; q = 1;
    STARTKATA();
    while (!EndKata) {
        data[p][q] = CKata;
        ADVKATA();

        if(CKata.TabKata[1] == '|')
        {
            p++;
            q = 0;
            ADVKATA();
        }
        q++;
        }

//Ngeliat bentuk datanya kaya gimana
     for (a=1; a<=3; a++)
     {
         b = 1;
         while(data[a][b].TabKata[1]!='\x00')
         {
             for (c=1; c<=data[a][b].Length;c++)
             {
                 printf("%c",data[a][b].TabKata[c]);
             }
             printf("|");
             b++;
         }
         printf("\n");
     }
/*         for(k=1; k<=4; k++)
    {
            for (i=1;i<=data[k][1].Length;i++) {
                printf("%c", data[k][1].TabKata[i]);
                }
            printf("|");
    }*/
}

/*
int main()
{

pita = fopen("player_one.txt","r");
load();

}*/
