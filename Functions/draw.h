#include <stdio.h>
#include "../ADT/Header/tepokpramuka_type.h"
#include "../ADT/Header/queue.h"
#include "../ADT/Header/array.h"
#include "../ADT/Header/matriks.h"
#include "../ADT/Header/stackt.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

extern Game gameData;
extern Player player;
extern CustQueue waitingList;
extern BinTree recipeTree;

void print_title();
void print_credits();
void print_menu();
void print_game();
void TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
