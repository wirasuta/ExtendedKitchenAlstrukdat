#include "listlinier.c"
#include <stdio.h>

/* Driver list linear
   Kalo berantakan mohon dimaklumi wkwkkw
   Cuman untuk testing cepet
*/

void menuAdd(List *Lin){
  int in2;
  int in3;

  printf("1) first\n2) last\n");
  scanf("%d",&in2);
  printf("in = ");
  scanf("%d",&in3);

  if(in2 == 1){
    InsVFirst(Lin, in3);
  }else{
    InsVLast(Lin, in3);
  }
}

void menuDel(List *Lin){
  int in2;
  int in3;
  address pdel;
  int X;

  printf("1) first\n2) last\n3) delp(via search)\n");
  scanf("%d",&in2);

  if(in2 == 1){
    DelVFirst(Lin, &in3);
  }else if(in2==2){
    DelVLast(Lin, &in3);
  }else{
    scanf("%d",&X);
    DelP(Lin, X);
    in3 = 0;
  }

  printf("deleted  = %d\n",in3);

}
void menuOther(List *Lin){
  int in2;

  printf("1) max\n2) nbelmt\n3) isempty");
  scanf("%d",&in2);

  if(in2==1){
    printf("max = %d",Max(*Lin));
  }else if(in2==2){
    printf("nb elmt  = %d",NbElmt(*Lin));
  }else{
    printf("IsEmpty = %d",IsEmpty(*Lin));
  }

}

int main(){
  List L1;
  List L2;
  List L3;
  int input;
  address temp;

  CreateEmpty(&L1);
  CreateEmpty(&L2);

  InsVFirst(&L2, 12);
  InsVFirst(&L2, 38);
  InsVFirst(&L2, 56);

  while(true){
    printf("\n");
    PrintInfo(L1);

    printf("\n1) add\n2) delete\n3) search\n4) other\n5) konkat\n");
    scanf("%d",&input);
    switch(input){
      case 1:
        menuAdd(&L1);
        break;
      case 2:
        menuDel(&L1);
        break;
      case 3:
        printf("search = ");
        scanf("%d",&input);
        temp = Search(L1, input);
        if(temp==Nil){
          printf("Not found");
        }else{
          printf("%d",Info(temp));
        }
        break;
      case 4:
        menuOther(&L1);
        break;
      case 5:
        printf("list 1 = ");
        PrintInfo(L1);
        printf("list 2 = ");
        PrintInfo(L2);

        Konkat1(&L1, &L2, &L3);

        printf("list 3 = ");
        PrintInfo(L3);
        break;
    }

  }

  return 0;
}
