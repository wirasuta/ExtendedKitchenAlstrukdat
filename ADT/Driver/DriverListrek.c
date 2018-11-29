#include "../Impl/listrek.c"
#include "../Impl/mesinkata.c"
#include "../Impl/mesinkar.c"

int main(){
    ListRek L,M,Lin,Lout,N,InvN,Llain;
    infotypeRek e,f;

    L=Nil;
    printf("IsEmptyRek(ListRek L)= %d\n",IsEmptyRek(L));
    printf("Konso(infotypeRek e, ListRek L)=");
    e.TabKata[0]=' ';
    e.TabKata[1]='t';
    e.TabKata[2]='e';
    e.TabKata[3]='p';
    e.TabKata[4]='o';
    e.TabKata[5]='k';
    e.TabKata[6]='\0';
    e.Length=6;

    f.TabKata[0]=' ';
    f.TabKata[1]='t';
    f.TabKata[2]='e';
    f.TabKata[3]='l';
    f.TabKata[4]='o';
    f.TabKata[5]='r';
    f.TabKata[6]='\0';
    f.Length=6;
    //printf("%s",e.TabKata);
    L=Konso(e,L);
    //printf("cek konso1: %s\n", Info(L).TabKata);

    //printf("cek konso2: %s\n", Info(L).TabKata);
    PrintList(L);
    printf("\n");

    L=KonsB(L,f);
    printf("KonsB(ListRek L, infotypeRek f)=");
    PrintList(L);
    printf("\n");

    M=Copy(L);
    printf("Copy (ListRek L)=");
    PrintList(M);
    printf("\n");

    printf("Concat (ListRek L1=L, ListRek L2=Copy(L))=");
    N=Concat(L,M);
    PrintList(N);
    printf("\n");

    printf("NbElmtList (ListRek L=setelah Concat)=%d\n",NbElmtList ( N));

    printf("SearchRek (ListRek L=setelah Concat, infotypeRek X=tepok)=%d",SearchRek(N,e));

    printf("InverseList (ListRek L=setelah Concat)=");
    InvN=InverseList(N);
    PrintList(InvN);
    printf("\n");

    //printf("IsAllExist (ListRek L1=L, ListRek L2=Inverse setelah Concat)=%d\n",IsAllExist(N,InvN));
    //PrintList(N);printf("\n");
    //PrintList(InvN);printf("\n");
    Llain=Nil;
    e.TabKata[0]=' ';
    e.TabKata[1]='t';
    e.TabKata[2]='e';
    e.TabKata[3]='p';
    e.TabKata[4]='o';
    e.TabKata[5]='k';
    e.TabKata[6]='\0';
    e.Length=6;
    Llain=Konso(e,Llain);
    printf("IsAllExist (ListRek L1=List berelemen 1 yaitu tepok, ListRek L2=L)=%d\n",IsAllExist(Llain,L));

}
