#include "../Impl/mesinkata.c"
#include "../Impl/mesinkar.c"

int main (){
    Kata K1,K2;
    boolean found;

    K1.TabKata[0]=' ';
    K1.TabKata[1]='a';
    K1.TabKata[2]='y';
    K1.TabKata[3]='a';
    K1.TabKata[4]='m';
    K1.TabKata[5]='\0';
    K1.Length=5;


    K2.TabKata[0]=' ';
    K2.TabKata[1]='a';
    K2.TabKata[2]='y';
    K2.TabKata[3]='a';
    K2.TabKata[4]='m';
    K2.TabKata[5]='\0';
    K2.Length=5;

    STARTKATA();
    int i =0;

    printf("length K1: %d", K1.Length);
    while(i < K1.Length+1){
        printf("cek isi CKata : %c\n",K1.TabKata[i]);
        i++;
    }
    printf("IsKataSama( K1, K2)= %d\n",IsKataSama( K1,  K2));

}
