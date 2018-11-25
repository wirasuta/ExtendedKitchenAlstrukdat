#include "../Header/tepokpramuka_type.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Customer arrC[20];
    //int r1,r2,r2,r4;

    /*printf("random 1: %d", (rand() % (25 + 1 -15)) + 15);
    printf("random 2: %d", (rand() % (25 + 1 -15)) + 15);
    printf("random 3: %d", (rand() % (25 + 1 -15)) + 15);
    printf("random 4: %d", (rand() % (25 + 1 -15)) + 15);*/

    //printf("%d\n", random);

    arrC[0].Star = false;
    arrC[0].TimeQueue = (rand() % (25 + 1 -15)) + 15);
    arrC[0].TimeWaiting = -999;
    arrC[0].SumOfCustomer = 2;
    arrC[0].Position.X = -999;
    arrC[0].Position.Y = -999;
    arrC[0].Food.Status = '#';
    arrC[0].Food.Name.TabKata[0]=' ';
    arrC[0].Food.Name.TabKata[1]='b';
    arrC[0].Food.Name.TabKata[2]='a';
    arrC[0].Food.Name.TabKata[3]='n';
    arrC[0].Food.Name.TabKata[4]='a';
    arrC[0].Food.Name.TabKata[5]='n';
    arrC[0].Food.Name.TabKata[6]='a';
    arrC[0].Food.Name.TabKata[7]='s';
    arrC[0].Food.Name.TabKata[8]='p';
    arrC[0].Food.Name.TabKata[9]='l';
    arrC[0].Food.Name.TabKata[10]='i';
    arrC[0].Food.Name.TabKata[11]='t';
    arrC[0].Food.Name.TabKata[12]='\0';
    arrC[0].Food.Name.Length=12;
    arrC[0].Food.Nomor = -999;

    arrC[1].Star = true;
    arrC[1].TimeQueue = (rand() % (25 + 1 -15)) + 15);
    arrC[1].TimeWaiting = -999;
    arrC[1].SumOfCustomer = 4;
    arrC[1].Position.X = -999;
    arrC[1].Position.Y = -999;
    arrC[1].Food.Status = '#';
    arrC[1].Food.Name.TabKata[0]=' ';
    arrC[1].Food.Name.TabKata[1]='s';
    arrC[1].Food.Name.TabKata[2]='u';
    arrC[1].Food.Name.TabKata[3]='n';
    arrC[1].Food.Name.TabKata[4]='d';
    arrC[1].Food.Name.TabKata[5]='a';
    arrC[1].Food.Name.TabKata[6]='e';
    arrC[1].Food.Name.TabKata[7]='\0';
    arrC[1].Food.Name.Length=7;
    arrC[1].Food.Nomor = -999;

    arrC[2].Star = true;
    arrC[2].TimeQueue = (rand() % (25 + 1 -15)) + 15);
    arrC[2].TimeWaiting = -999;
    arrC[2].SumOfCustomer = 4;
    arrC[2].Position.X = -999;
    arrC[2].Position.Y = -999;
    arrC[2].Food.Status = '#';
    arrC[2].Food.Name.TabKata[0]=' ';
    arrC[2].Food.Name.TabKata[1]='b';
    arrC[2].Food.Name.TabKata[2]='u';
    arrC[2].Food.Name.TabKata[3]='r';
    arrC[2].Food.Name.TabKata[4]='g';
    arrC[2].Food.Name.TabKata[5]='r';
    arrC[2].Food.Name.TabKata[6]='r';
    arrC[2].Food.Name.TabKata[7]='\0';
    arrC[2].Food.Name.Length=7;
    arrC[2].Food.Nomor = -999;


}