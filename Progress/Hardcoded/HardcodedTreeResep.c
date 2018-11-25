#include <stdio.h>
#include <stdlib.h>
#include "tepokpramuka_type.h"

int main(){
    Kata T[100];

    T[0].TabKata[0]=' ';
    T[0].TabKata[1]='p';
    T[0].TabKata[2]='i';
    T[0].TabKata[3]='r';
    T[0].TabKata[4]='i';
    T[0].TabKata[5]='n';
    T[0].TabKata[6]='g';
    T[0].TabKata[7]='\0';
    T[0].Length=7;

    T[1].TabKata[0]=' ';
    T[1].TabKata[1]='s';
    T[1].TabKata[2]='e';
    T[1].TabKata[3]='n';
    T[1].TabKata[4]='d';
    T[1].TabKata[5]='o';
    T[1].TabKata[6]='k';
    T[1].TabKata[7]='\0';
    T[1].Length=7;

    T[2].TabKata[0]=' ';
    T[2].TabKata[1]='g';
    T[2].TabKata[2]='a';
    T[2].TabKata[3]='r';
    T[2].TabKata[4]='p';
    T[2].TabKata[5]='u';
    T[2].TabKata[6]='\0';
    T[2].Length=6;

    T[3].TabKata[0]=' ';
    T[3].TabKata[1]='e';
    T[3].TabKata[2]='s';
    T[3].TabKata[3]='k';
    T[3].TabKata[4]='r';
    T[3].TabKata[5]='i';
    T[3].TabKata[6]='m';
    T[3].TabKata[7]='\0';
    T[3].Length=7;

    T[4].TabKata[0]=' ';
    T[4].TabKata[1]='n';
    T[4].TabKata[2]='a';
    T[4].TabKata[3]='s';
    T[4].TabKata[4]='i';
    T[4].TabKata[5]='\0';
    T[4].Length=5;

    T[5].TabKata[0]=' ';
    T[5].TabKata[1]='r';
    T[5].TabKata[2]='o';
    T[5].TabKata[3]='t';
    T[5].TabKata[4]='i';
    T[5].TabKata[5]='\0';
    T[5].Length=5;

    T[6].TabKata[0]=' ';
    T[6].TabKata[1]='s';
    T[6].TabKata[2]='p';
    T[6].TabKata[3]='a';
    T[6].TabKata[4]='g';
    T[6].TabKata[5]='h';
    T[6].TabKata[6]='e';
    T[6].TabKata[7]='t';
    T[6].TabKata[8]='t';
    T[6].TabKata[9]='i';
    T[6].TabKata[10]='\0';
    T[6].Length=10;

    T[7].TabKata[0]=' ';
    T[7].TabKata[1]='p';
    T[7].TabKata[2]='i';
    T[7].TabKata[3]='s';
    T[7].TabKata[4]='a';
    T[7].TabKata[5]='n';
    T[7].TabKata[6]='g';
    T[7].TabKata[7]='\0';
    T[7].Length=7;

    T[8].TabKata[0]=' ';
    T[8].TabKata[1]='s';
    T[8].TabKata[2]='t';
    T[8].TabKata[3]='r';
    T[8].TabKata[4]='o';
    T[8].TabKata[5]='b';
    T[8].TabKata[6]='e';
    T[8].TabKata[7]='r';
    T[8].TabKata[8]='i';
    T[8].TabKata[9]='\0';
    T[8].Length=9;

    T[9].TabKata[0]=' ';
    T[9].TabKata[1]='t';
    T[9].TabKata[2]='e';
    T[9].TabKata[3]='l';
    T[9].TabKata[4]='u';
    T[9].TabKata[5]='r';
    T[9].TabKata[6]='\0';
    T[9].Length=6;

    T[10].TabKata[0]=' ';
    T[10].TabKata[1]='a';
    T[10].TabKata[2]='y';
    T[10].TabKata[3]='a';
    T[10].TabKata[4]='m';
    T[10].TabKata[5]='g';
    T[10].TabKata[6]='o';
    T[10].TabKata[7]='r';
    T[10].TabKata[8]='e';
    T[10].TabKata[9]='n';
    T[10].TabKata[10]='g';
    T[10].TabKata[11]='\0';
    T[10].Length=11;

    T[11].TabKata[0]=' ';
    T[11].TabKata[1]='p';
    T[11].TabKata[2]='a';
    T[11].TabKata[3]='t';
    T[11].TabKata[4]='t';
    T[11].TabKata[5]='y';
    T[11].TabKata[6]='\0';
    T[11].Length=6;

    T[12].TabKata[0]=' ';
    T[12].TabKata[1]='s';
    T[12].TabKata[2]='o';
    T[12].TabKata[3]='s';
    T[12].TabKata[4]='i';
    T[12].TabKata[5]='s';
    T[12].TabKata[6]='\0';
    T[12].Length=6;

    T[13].TabKata[0]=' ';
    T[13].TabKata[1]='b';
    T[13].TabKata[2]='o';
    T[13].TabKata[3]='l';
    T[13].TabKata[4]='o';
    T[13].TabKata[5]='g';
    T[13].TabKata[6]='n';
    T[13].TabKata[7]='e';
    T[13].TabKata[8]='s';
    T[13].TabKata[9]='e';
    T[13].TabKata[10]='\0';
    T[13].Length=10;

    T[14].TabKata[0]=' ';
    T[14].TabKata[1]='c';
    T[14].TabKata[2]='a';
    T[14].TabKata[3]='r';
    T[14].TabKata[4]='b';
    T[14].TabKata[5]='o';
    T[14].TabKata[6]='n';
    T[14].TabKata[7]='a';
    T[14].TabKata[8]='r';
    T[14].TabKata[9]='a';
    T[14].TabKata[10]='\0';
    T[14].Length=10;

    T[15].TabKata[0]=' ';
    T[15].TabKata[1]='b';
    T[15].TabKata[2]='a';
    T[15].TabKata[3]='n';
    T[15].TabKata[4]='a';
    T[15].TabKata[5]='n';
    T[15].TabKata[6]='a';
    T[15].TabKata[7]='s';
    T[15].TabKata[8]='p';
    T[15].TabKata[9]='l';
    T[15].TabKata[10]='i';
    T[15].TabKata[11]='t';
    T[15].TabKata[12]='\0';
    T[15].Length=12;

    T[16].TabKata[0]=' ';
    T[16].TabKata[1]='s';
    T[16].TabKata[2]='u';
    T[16].TabKata[3]='n';
    T[16].TabKata[4]='d';
    T[16].TabKata[5]='a';
    T[16].TabKata[6]='e';
    T[16].TabKata[7]='\0';
    T[16].Length=7;

    T[17].TabKata[0]=' ';
    T[17].TabKata[1]='n';
    T[17].TabKata[2]='a';
    T[17].TabKata[3]='s';
    T[17].TabKata[4]='i';
    T[17].TabKata[5]='t';
    T[17].TabKata[6]='e';
    T[17].TabKata[7]='l';
    T[17].TabKata[8]='u';
    T[17].TabKata[9]='r';
    T[17].TabKata[10]='d';
    T[17].TabKata[11]='a';
    T[17].TabKata[12]='d';
    T[17].TabKata[13]='a';
    T[17].TabKata[14]='r';
    T[17].TabKata[15]='\0';
    T[17].Length=15;

    T[18].TabKata[0]=' ';
    T[18].TabKata[1]='n';
    T[18].TabKata[2]='a';
    T[18].TabKata[3]='s';
    T[18].TabKata[4]='i';
    T[18].TabKata[5]='a';
    T[18].TabKata[6]='y';
    T[18].TabKata[7]='a';
    T[18].TabKata[8]='m';
    T[18].TabKata[9]='g';
    T[18].TabKata[10]='o';
    T[18].TabKata[11]='r';
    T[18].TabKata[12]='e';
    T[18].TabKata[13]='n';
    T[18].TabKata[14]='g';
    T[18].TabKata[15]='\0';
    T[18].Length=15;

    T[19].TabKata[0]=' ';
    T[19].TabKata[1]='b';
    T[19].TabKata[2]='u';
    T[19].TabKata[3]='r';
    T[19].TabKata[4]='g';
    T[19].TabKata[5]='e';
    T[19].TabKata[6]='r';
    T[19].TabKata[7]='\0';
    T[19].Length=7;

    T[20].TabKata[0]=' ';
    T[20].TabKata[1]='h';
    T[20].TabKata[2]='o';
    T[20].TabKata[3]='t';
    T[20].TabKata[4]='d';
    T[20].TabKata[5]='o';
    T[20].TabKata[6]='g';
    T[20].TabKata[7]='\0';
    T[20].Length=7;

    T[21].TabKata[0]=' ';
    T[21].TabKata[1]='k';
    T[21].TabKata[2]='e';
    T[21].TabKata[3]='j';
    T[21].TabKata[4]='u';
    T[21].TabKata[5]='\0';
    T[21].Length=5;

    T[22].TabKata[0]=' ';
    T[22].TabKata[1]='s';
    T[22].TabKata[2]='p';
    T[22].TabKata[3]='a';
    T[22].TabKata[4]='g';
    T[22].TabKata[5]='h';
    T[22].TabKata[6]='e';
    T[22].TabKata[7]='t';
    T[22].TabKata[8]='t';
    T[22].TabKata[9]='i';
    T[22].TabKata[10]='c';
    T[22].TabKata[11]='a';
    T[22].TabKata[12]='r';
    T[22].TabKata[13]='b';
    T[22].TabKata[14]='o';
    T[22].TabKata[15]='n';
    T[22].TabKata[16]='a';
    T[22].TabKata[17]='r';
    T[22].TabKata[18]='a';
    T[22].TabKata[19]='\0';
    T[22].Length=19;

    T[23].TabKata[0]=' ';
    T[23].TabKata[1]='s';
    T[23].TabKata[2]='p';
    T[23].TabKata[3]='a';
    T[23].TabKata[4]='g';
    T[23].TabKata[5]='h';
    T[23].TabKata[6]='e';
    T[23].TabKata[7]='t';
    T[23].TabKata[8]='t';
    T[23].TabKata[9]='i';
    T[23].TabKata[10]='b';
    T[23].TabKata[11]='o';
    T[23].TabKata[12]='l';
    T[23].TabKata[13]='o';
    T[23].TabKata[14]='g';
    T[23].TabKata[15]='n';
    T[23].TabKata[16]='e';
    T[23].TabKata[17]='s';
    T[23].TabKata[18]='e';
    T[23].TabKata[19]='\0';
    T[23].Length=19;


}
