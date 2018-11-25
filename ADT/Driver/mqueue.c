#include "../Impl/queue.c"
#include "../Header/tepokpramuka_type.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    CustQueue Q, Q1;
    Customer C1, C2,C3,C4;

    //INISIALISASI MASIH ANTRI
    //POSISI = UNDEFINED (-999,-999)
    //TIMEWAITING = 0
    //C.Food.Nomor = -999 (karena belom duduk di meja)
    C1.Star = false;
    C1.TimeQueue = 5;
    C1.TimeWaiting = 0;
    C1.SumOfCustomer = 2;
    C1.Position.X = -999;
    C1.Position.Y = -999;
    C1.Food.Status = '#';
    C1.Food.Name.TabKata[0] = 'a';
    C1.Food.Name.TabKata[1] = 'y';
    C1.Food.Name.TabKata[2] = 'a';
    C1.Food.Name.TabKata[3] = 'm';
    C1.Food.Name.TabKata[4] = '\0';
    C1.Food.Name.Length = 4;
    C1.Food.Nomor = -999;

    C2.Star = true;
    C2.TimeQueue = 7;
    C2.TimeWaiting = 0;
    C2.SumOfCustomer = 4;
    C2.Position.X = -999;
    C2.Position.Y = -999;
    C2.Food.Status = '#';
    C2.Food.Name.TabKata[0] = 't';
    C2.Food.Name.TabKata[1] = 'a';
    C2.Food.Name.TabKata[2] = 'h';
    C2.Food.Name.TabKata[3] = 'u';
    C2.Food.Name.TabKata[4] = '\0';
    C2.Food.Name.Length = 4;
    C2.Food.Nomor = -999;
    CreateEmptyQueue(&Q, 10);
    CreateEmptyQueue(&Q1, 5);
    printf("Max Elemen pada Queue: %d\n", QueueMaxEl(Q));
    printf("Max Elemen pada Queue1 setelah dialokasi : %d\n", QueueMaxEl(Q1));
    DeAlokasiQueue(&Q1);
    printf("Max Elemen pada Queue1 setelah didealokasi : %d\n", QueueMaxEl(Q1));

    printf("IsQueueEmpty: %d\n", IsQueueEmpty(Q));
    printf("IsQueueFull: %d\n", IsQueueFull(Q));

    AddQueue(&Q, C1);
    printf("cek star C1: %d\n", InfoHead(Q).Star);
    printf("cek time queue C1: %d\n", InfoHead(Q).TimeQueue);
    printf("cek time waiting C1: %d\n", InfoHead(Q).TimeWaiting);
    printf("cek jumlah customer C1: %d\n", InfoHead(Q).SumOfCustomer);
    printf("cek posisi (X,Y) C1: (%d,%d)\n", InfoHead(Q).Position.X, InfoHead(Q).Position.Y);
    printf("cek status order C1: %c\n", InfoHead(Q).Food.Status);
    printf("cek nama makanan C1: %s\n", InfoHead(Q).Food.Name);
    printf("cek nomor meja C1: %d\n", InfoHead(Q).Food.Nomor);
    printf("\n");

    AddQueue(&Q,C2);
    printf("cek star C2: %d\n", InfoTail(Q).Star);
    printf("cek time queue C2: %d\n", InfoTail(Q).TimeQueue);
    printf("cek time waiting C2: %d\n", InfoTail(Q).TimeWaiting);
    printf("cek jumlah customer C2: %d\n", InfoTail(Q).SumOfCustomer);
    printf("cek posisi (X,Y) C2: (%d,%d)\n", InfoTail(Q).Position.X, InfoTail(Q).Position.Y);
    printf("cek status order C2: %c\n", InfoTail(Q).Food.Status);
    printf("cek nama makanan C2: %s\n", InfoTail(Q).Food.Name);
    printf("cek nomor meja C2: %d\n", InfoTail(Q).Food.Nomor);
    printf("\n");

    DelQueue(&Q, &C3);
    printf("cek star C3: %d\n", C3.Star);
    printf("cek time queue C3: %d\n", C3.TimeQueue);
    printf("cek time waiting C3: %d\n",C3.TimeWaiting);
    printf("cek jumlah customer C3: %d\n", C3.SumOfCustomer);
    printf("cek posisi (X,Y) C3: (%d,%d)\n", C3.Position.X, C3.Position.Y);
    printf("cek status order C3: %c\n", C3.Food.Status);
    printf("cek nama makanan C3: %s\n", C3.Food.Name);
    printf("cek nomor meja C3: %d\n", C3.Food.Nomor);
    printf("\n");

    AddQueue(&Q, C3);
    printf("cek star C3: %d\n", InfoTail(Q).Star);
    printf("cek time queue C3: %d\n", InfoTail(Q).TimeQueue);
    printf("cek time waiting C3: %d\n", InfoTail(Q).TimeWaiting);
    printf("cek jumlah customer C3: %d\n", InfoTail(Q).SumOfCustomer);
    printf("cek posisi (X,Y) C3: (%d,%d)\n", InfoTail(Q).Position.X, InfoTail(Q).Position.Y);
    printf("cek status order C3: %c\n", InfoTail(Q).Food.Status);
    printf("cek nama makanan C3: %s\n", InfoTail(Q).Food.Name);
    printf("cek nomor meja C3: %d\n", InfoTail(Q).Food.Nomor);
    printf("\n");

    SearchFitQueue(&Q, &C4, 2);
    printf("cek star C4: %d\n", C4.Star);
    printf("cek time queue C4: %d\n", C4.TimeQueue);
    printf("cek time waiting C4: %d\n",C4.TimeWaiting);
    printf("cek jumlah customer C4: %d\n", C4.SumOfCustomer);
    printf("cek posisi (X,Y) C4: (%d,%d)\n", C4.Position.X, C4.Position.Y);
    printf("cek status order C4: %c\n", C4.Food.Status);
    printf("cek nama makanan C4: %s\n", C4.Food.Name);
    printf("cek nomor meja C4: %d\n", C4.Food.Nomor);
}
