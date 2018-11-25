// Driver untuk List Double Pointer
// Pandyaka A / 13517003

#include <stdio.h>
#include "../Header/listdp.h"

int main()
	{
		// Kamus Lokal
		List L;
		infotype x,y;
		address pt,pt2;
		int input;

		// Algoritma
		CreateEmpty(&L);

		while(1){
			printf("1. insertfirst\n2. insertlast\n3. delfirst\n4. dellast\n5. delp\n6. search\n7. insertafter\n8. insertbefore\n9. deleteafter\n10. deletebefore\n");
			scanf("%d",&input);
			switch(input){
				case 1:
					scanf("%d",&x);
					InsVFirst(&L,x);
					break;
				case 2:
					scanf("%d",&x);
					InsVLast(&L,x);
					break;
				case 3:
					DelVFirst(&L,&x);
					printf("deleted:%d\n",x);
					break;
				case 4:
					DelVLast(&L,&x);
					printf("deleted:%d\n",x);
					break;
				case 5:
					scanf("%d",&x);
					DelP(&L,x);
					break;
				case 6:
					scanf("%d",&x);
					pt=Search(L,x);
					if(pt==Nil){
						printf("not found\n");
					}else{
						printf("found in %d with value %d\n",pt,Info(pt));
					}
					break;
				case 7:
					printf("insert after element: ");scanf("%d",&x);
					printf("value to be inserted : ");scanf("%d",&y);
					pt2=Alokasi(y);
					pt=Search(L,x);
					InsertAfter(&L,pt2,pt);
					break;
				case 8:
					printf("insert before element: ");scanf("%d",&x);
					printf("value to be inserted : ");scanf("%d",&y);
					pt2=Alokasi(y);
					pt=Search(L,x);
					InsertBefore(&L,pt2,pt);
					break;
				case 9:
					printf("delete after element: ");scanf("%d",&x);
					pt=Search(L,x);
					DelAfter(&L,&pt2,pt);
					printf("deleted: %d\n",Info(pt2));
					break;
				case 10:
					printf("delete before element: ");scanf("%d",&x);
					pt=Search(L,x);
					DelBefore(&L,&pt2,pt);
					printf("deleted: %d\n",Info(pt2));
					break;

			}
			PrintForward(L);printf("\n");
			PrintBackward(L);
			printf("\n\n");
		}
		return 0;
	}
