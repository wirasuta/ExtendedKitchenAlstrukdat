#include "draw.h"

void print_title()
{
    printf("\e[1;1H\e[2J");
    printf("%s                      :::::::::: ::::    :::  :::::::: ::::::::::: ::: ::::::::   \n", KGRN);
    printf("%s                      :+:        :+:+:   :+: :+:    :+:    :+:     :+ :+:    :+:  \n", KGRN);
    printf("%s                      +:+        :+:+:+  +:+ +:+           +:+        +:+         \n", KGRN);
    printf("%s                      +#++:++#   +#+ +:+ +#+ :#:           +#+        +#++:++#++  \n", KGRN);
    printf("%s                      +#+        +#+  +#+#+# +#+   +#+#    +#+               +#+  \n", KGRN);
    printf("%s                      #+#        #+#   #+#+# #+#    #+#    #+#        #+#    #+#  \n", KGRN);
    printf("%s                      ########## ###    ####  ######## ###########     ########   \n", KGRN);
    printf("\n");
    printf("%s:::    ::: ::::::::::: ::::::::::: ::::::::  :::    ::: :::::::::: ::::    :::       ::::::::       :::::::  \n",KYEL);
    printf("%s:+:   :+:      :+:         :+:    :+:    :+: :+:    :+: :+:        :+:+:   :+:      :+:    :+:     :+:   :+: \n",KYEL);
    printf("%s+:+  +:+       +:+         +:+    +:+        +:+    +:+ +:+        :+:+:+  +:+            +:+      +:+  :+:+ \n",KYEL);
    printf("%s+#++:++        +#+         +#+    +#+        +#++:++#++ +#++:++#   +#+ +:+ +#+          +#+        +#+ + +:+ \n",KYEL);
    printf("%s+#+  +#+       +#+         +#+    +#+        +#+    +#+ +#+        +#+  +#+#+#        +#+          +#+#  +#+ \n",KYEL);
    printf("%s#+#   #+#      #+#         #+#    #+#    #+# #+#    #+# #+#        #+#   #+#+#       #+#       #+# #+#   #+# \n",KYEL);
    printf("%s###    ### ###########     ###     ########  ###    ### ########## ###    ####      ########## ###  #######  %s\n",KYEL,KNRM);
}

void print_credits()
{
printf("                          %s ██████╗██████╗ ███████╗██████╗ ██╗████████╗███████╗\n",KBLU);
printf("                          %s██╔════╝██╔══██╗██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝\n",KBLU);
printf("                          %s██║     ██████╔╝█████╗  ██║  ██║██║   ██║   ███████╗\n",KBLU);
printf("                          %s██║     ██╔══██╗██╔══╝  ██║  ██║██║   ██║   ╚════██║\n",KBLU);
printf("                          %s╚██████╗██║  ██║███████╗██████╔╝██║   ██║   ███████║\n",KBLU);
printf("                          %s ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝ ╚═╝   ╚═╝   ╚══════╝\n",KBLU);
printf("                          -------------------------------------------------------\n");
printf("                          %s           Ainun Fitryh Vianiryzki\n",KRED);
printf("                          \n");
printf("                          %s            I Pute Gede Wirasuta\n",KRED);
printf("                          \n");
printf("                          %s             Kintan Sekar Adinda\n",KRED);
printf("                          \n");
printf("                          %s            M. Rifky I Bariansyah\n",KRED);
printf("                          \n");
printf("                          %s              Pandyaka Aptanagi\n",KRED);
printf("                          \n");
printf("                          %s                Raihan Asyraf%s\n",KRED,KNRM);

}

void print_menu()
{
  printf("                                            (1) New Game\n");
  printf("                                            (2) Start Game\n");
  printf("                                            (3) Load Game\n");
  printf("                                            (4) Exit\n\n");
  printf("                                      Please Input Your Choice : ");
}

void print_game(){
  printf("\e[1;1H\e[2J");
  printf("%s+------------------------------------------------------------------------------------------------------+\n%s",KBLU,KNRM);
  printf("\t%s\t\t\t UANG: %.1f\t\t\t NYAWA: %d\t\t TIME: %d\n", ElmtName(gameData).TabKata, Money(gameData), Life(gameData), PlayerTick(player));
  printf("%s+---------------------------------+--------------------------------------------------------------------+\n%s",KBLU,KNRM);
  TulisMATRIKS(Layout(Ruang(gameData, RoomID(player))));
  printf("\n");
  printf("%s+---------------------------------+--------------------------------------------------------------------+\n%s",KBLU,KNRM);
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	// Kamus
	int i,j;

	// Algoritma
	for ( i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) ; i++)
		{
      printf("%s|\t%s", KBLU,KNRM);
			for ( j = GetFirstIdxKol(M) ; j <= GetLastIdxKol(M) ; j++)
				{
					printf("%c",(M).Mem[i][j]);
					if ( j != GetLastIdxKol(M))
						{
							printf(" ");
						};
				};
      printf("\t  %s|\t%s", KBLU,KNRM);
      if (i==2) {
        printf("ANTRIAN PELANGGAN : ");
        PrintQueue(waitingList);
      }else if (i==4){
        printf("ORDERAN PELANGGAN : ");
        TulisIsiTab(OrderList(player));
      }else if (i==6){
        printf("ISI HAND : ");
        PrintStack(OnHand(player));
      }else if (i==8){
        printf("ISI TRAY : ");
        PrintStack(OnTray(player));
      }

			if ( i != GetLastIdxBrs(M))
				{
					printf("\n");
				};
		};

}
