// Body untuk bintree.h
// Pandyaka Aptanagi / 13517003

#include "../Header/bintree.h"
#include "../Header/boolean.h"
#include <stdlib.h>
#include <stdio.h>


/* *** Konstruktor *** */
BinTree Tree (infotypeRek Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    {
        // Kamus Lokal
        BinTree NewTree;

        // Algoritma
        NewTree = (BinTree)malloc(1*sizeof(BinTree));

        if ( NewTree != Nil )
            {
                Akar(NewTree) = Akar;
                Left(NewTree) = L;
                Right(NewTree) = R;

                return NewTree;
            }
        else
            {
                return Nil;
            };

    };

void MakeTree (infotypeRek Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
    {
        // Kamus Lokal

        // Algoritma
        *P = Tree(Akar,L,R);
    };

/* Manajemen Memory */
addrNode AlokNode (infotypeRek X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    {
        // Kamus Lokal
        addrNode NewNode;

        // ALgoritma
        NewNode = (addrNode)malloc(1*sizeof(addrNode));

        if ( NewNode != Nil )
            {
                Akar(NewNode) = X;
                Left(NewNode) = Nil;
                Right(NewNode) = Nil;

                return NewNode;
            }
        else
            {
                return Nil;
            };
    };

void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
    {
        // Kamus Lokal

        // Algoritma
        free(P);

    };

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
    {
        // Kamus Lokal

        // ALgoritma
        return ( P == Nil);
    };

boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
    {
        // Kamus Lokal

        // Algoritma
        if ( !IsTreeEmpty(P) )
            {
                return(Left(P) == Nil && Right(P) == Nil );
            }
        else
            {
                return false;
            };
    };

boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
    {
        // Kamus Lokal

        // Algoritma
        if ( !IsTreeEmpty(P) )
            {
                return ( Right(P) == Nil && Left(P) != Nil );
            }
        else
            {
                return false;
            };
    };

boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
    {
        // Kamus Lokal

        // Algoritma
        if ( !IsTreeEmpty(P) )
            {
                return ( Left(P) == Nil && Right(P) != Nil );
            }
        else
            {
                return false;
            };


    };

boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
    {
        // Kamus Lokal

        // Algoritma
        if ( !IsTreeEmpty(P) )
            {
                return ( ( Left(P) != Nil ) && ( Right(P) != Nil) );
            }
        else
            {
                return false;
            };

    };

/* *** Traversal *** */
void PrintPreorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
    {
        // Kamus Lokal

        // Algoritma
        printf("(");
        if ( !IsTreeEmpty(P) )
            {
                printf("%d",Akar(P) );
                PrintPreorder(Left(P));
                PrintPreorder(Right(P));
            };

        printf(")");

    };

void PrintInorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
    {
        // Kamus Lokal

        // Algoritma
        printf("(");
        if ( !IsTreeEmpty(P) )
            {
                PrintInorder(Left(P));
                printf("%d",Akar(P));
                PrintInorder(Right(P));
            };

        printf(")");

    };

void PrintPostorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
    {
        // Kamus Lokal

        // Algoritma
        printf("(");
        if ( !IsTreeEmpty(P) )
            {
                PrintPostorder(Left(P));
                PrintPostorder(Right(P));
                printf("%d",Akar(P));
            };

        printf(")");
    };

//TODO: void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
//    {
//        void PrintTree2(BinTree P, int h, int current_indent)
//            {
//                if (!IsTreeEmpty(P))
//                {
//                    printf("%*s%d\n", current_indent, "", Akar(P));
//                    PrintTree2(Left(P), h, current_indent + h);
//                    PrintTree2(Right(P), h, current_indent + h);
//                }
//            }
//
//        PrintTree2(P,h, 0);
//    }

/* *** Searching *** */
boolean SearchTree (BinTree P, infotypeRek X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
    {
        // Kamus Lokal

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return false;
            }
        else
            {
                if ( Akar(P) == X)
                    {
                        return true;
                    }
                else
                    {
                        return ( SearchTree(Left(P),X) || SearchTree(Right(P),X));
                    };
            };
    };

/* *** Fungsi-Fungsi Lain *** */
int NbElmtRek (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
    {
        // Kamus Lokal
        int count;

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return 0;
            }
        else
            {
                count = NbElmtRek( Right(P) ) + NbElmtRek( Left(P) ) + 1;
                return count;
            };
    };

int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
    {
        // Kamus Lokal
        int count;

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return 0;
            }
        else
        if ( IsTreeOneElmt(P) )
            {
                return 1;
            }
        else
            {
                count = NbDaun(Right(P)) + NbDaun(Left(P));
                return count;
            };
    };

boolean IsSkewLeft (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
    {
        // Kamus Lokal

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return true;
            }
        else
        if ( IsTreeOneElmt(P) )
            {
                return true;
            }
        else
            {
                return ( (IsSkewLeft( Left(P) ) ) && ( Right(P) == Nil ) );
            };
    };

boolean IsSkewRight (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
    {
        // Kamus Lokal

        // Algoritma
         if ( IsTreeEmpty(P) )
            {
                return true;
            }
        else
        if ( IsTreeOneElmt(P) )
            {
                return true;
            }
        else
            {
                return ( (IsSkewLeft( Right(P) ) ) && ( Left(P) == Nil ) );
            };

    };

int Level (BinTree P, infotypeRek X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
    {
        // Kamus Lokal

        // Algoritma
        if ( SearchTree(Left(P),X) )
            {
                return 1 + Level(Left(P) , X);
            }
        else
        if ( SearchTree(Right(P),X) )
            {
                return 1 + Level(Right(P), X);
            }
        else
            {
                return 1;
            };
    };

int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
    {
        // Kamus Lokal
        int kanan;
        int kiri;

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return 0;
            }
        else
            {
                kanan = Tinggi(Right(P));
                kiri = Tinggi(Left(P));

                if ( kanan > kiri )
                    {
                        return kanan + 1;
                    }
                else
                    {
                        return kiri + 1;
                    };
            };

    };

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotypeRek X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
    {
        // Kamus Lokal

        // Algoritma
        if ( IsTreeEmpty(*P) )
            {
                *P = Tree(X,Nil,Nil);
            }
        else
            {
                AddDaunTerkiri(&Left(*P),X);
            };
    };

void AddDaun (BinTree *P, infotypeRek X, infotypeRek Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
    {
        // Kamus Lokal

        // Algoritma
        if ( IsTreeOneElmt(*P) && Akar(*P) == X)
            {
                if ( Kiri )
                    {
                        Left(*P) = Tree(Y,Nil,Nil);
                    }
                else
                    {
                        Right(*P) = Tree(Y,Nil,Nil);
                    }
            }
        else
            {
                if (SearchTree( Left(*P) , X ) )
                    {
                        AddDaun(&Left(*P),X,Y,Kiri);
                    }
                else
                if (SearchTree( Right(*P),X ) )
                    {
                        AddDaun(&Right(*P),X,Y,Kiri);
                    };
            };
    };

void DelDaunTerkiri (BinTree *P, infotypeRek *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
    {
        // Kamus Lokal
        addrNode temp;

        // Algoritma
        if ( IsTreeOneElmt(*P) )
            {
                *X = Akar(*P);
                temp = *P;
                *P = Nil;
                DealokNode(temp);
            }
        else
            {
                if ( IsUnerRight(*P) )
                    {
                        DelDaunTerkiri(&Right(*P),X);
                    }
                else
                    {
                        DelDaunTerkiri(&Left(*P),X);
                    };
            };

    };

void DelDaun (BinTree *P, infotypeRek X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
    {
        // Kamus Lokal
        addrNode temp;

        // Algoritma
        if ( IsTreeOneElmt(*P) && Akar(*P) == X)
            {
                temp = *P;
                *P = Nil;
                DealokNode(temp);
            }
        else
            {
                DelDaun(&Left(*P),X);
                DelDaun(&Right(*P),X);
            }
    };

ListRek MakeListDaun (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
    {
        // Kamus Lokal
        ListRek Kanan;
        ListRek Kiri;

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return Nil;
            }
        else
        if ( IsTreeOneElmt(P) )
            {
                return AlokasiRek(Akar(P));
            }
        else
            {
                Kanan = MakeListDaun(Right(P));
                Kiri = MakeListDaun(Left(P));
                return Concat(Kiri,Kanan);
            }
    };

ListRek MakeListPreorder (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
    {
        // Kamus Lokal
        ListRek kanan;
        ListRek kiri;

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return Nil;
            }
        else
            {
                kiri = MakeListPreorder(Left(P));
                kanan = MakeListPreorder(Right(P));
                return Concat(Konso(Akar(P),kiri),kanan);
            }
    };

ListRek MakeListLevel (BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
    {
        // Kamus Lokal
        ListRek kanan;
        ListRek kiri;

        // Algoritma
        if ( IsTreeEmpty(P) )
            {
                return Nil;
            }
        else
        if ( N == 1)
            {
                return AlokasiRek(Akar(P));
            }
        else
            {
                kiri = MakeListLevel(Left(P),N-1);
                kanan = MakeListLevel(Right(P),N-1);

                return Concat(kiri,kanan);
            };
    };
