// Body untuk matriks.h
// Pandyaka A / 13517003

#include <stdio.h>
#include <stdlib.h>
#include "../Header/matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	{
		// Kamus

		// Algoritma
		NBrsEff(*M)=NB;
		NKolEff(*M)=NK;
	};

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidMat (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	{
		// Kamus

		// ALgoritma
		return ((BrsMin<=i) && (i<=BrsMax)) && ((KolMin<=j) && (j<=KolMax));
	};

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
	{
		// Kamus

		// Algoritma
		return(BrsMin);
	};

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
	{
		// Kamus

		// Algoritma
		return(KolMin);
	};

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
	{
		// Kamus

		// Algoritma
		return(NBrsEff(M));
	};

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
	{
		// Kamus

		// Algoritma
		return NKolEff(M);
	};

boolean IsIdxEffMat (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	{
		// Kamus

		// Algoritma
			return ((BrsMin<=i) && (i<=NBrsEff(M)) && ((KolMin<=j) && (j<=NKolEff(M))));
	};

ElTypeMat GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
	{
		// Kamus

		// Algoritma
		return ( (M).Mem[(i)][(i)]);
	};

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
	{
		// Kamus
		MATRIKS M1;
		int a,b;
		int i,j;

		// Algoritma
		a = (MIn).NBrsEff;
		b = (MIn).NKolEff;
		MakeMATRIKS(a,b,&M1);

		for ( i = GetFirstIdxBrs(MIn) ; i<=GetLastIdxBrs(MIn) ; i++)
			{
				for ( j = GetFirstIdxKol(MIn) ; j<=GetLastIdxKol(MIn) ; j++)
					{
						(M1).Mem[i][j] = (MIn).Mem[i][j];
					};
			};

		*MHsl = M1;
	}


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
	{
		// Kamus
		int i,j;

		// Algoritma
		MakeMATRIKS(NB,NK,M);
		for ( i = GetFirstIdxBrs(*M) ; i <= GetLastIdxBrs(*M) ; i++)
			{
				for ( j = GetFirstIdxKol(*M) ; j <= GetLastIdxKol(*M) ; j++)
					{
						scanf("%c",&(MatElmt(*M,i,j)));
					};
			}

	};

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
	{
		// Kamus
		int i,j;
		MATRIKS M3;

		// Algoritma
		MakeMATRIKS( (M1).NBrsEff , (M1).NKolEff , &M3 );
		for ( i = GetFirstIdxBrs(M1) ; i <= GetLastIdxBrs(M1) ; i++)
			{
				for ( j = GetFirstIdxKol(M1) ; j<= GetLastIdxKol(M1) ; j++)
					{
						(M3).Mem[i][j] = (M1).Mem[i][j] + (M2).Mem[i][j];
					};
			};

		return (M3);

	};

/* Mengirim hasil penjumlahan matriks: M1 + M2 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 � M2 */
	{
		// Kamus
		int i,j;
		MATRIKS M3;

		// Algoritma
		MakeMATRIKS( (M1).NBrsEff , (M1).NKolEff , &M3 );
		for ( i = GetFirstIdxBrs(M1) ; i <= GetLastIdxBrs(M1) ; i++)
			{
				for ( j = GetFirstIdxKol(M1) ; j<= GetLastIdxKol(M1) ; j++)
					{
						(M3).Mem[i][j] = (M1).Mem[i][j] - (M2).Mem[i][j];
					};
			};

		return (M3);

	};

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
	{
		// Kamus
		MATRIKS M;
		int i,j,k;
		int total;

		// Algoritma
		MakeMATRIKS ( NBrsEff(M1) , NKolEff(M2) , &M );
		for ( i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) ; i++)
			{
				for( j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++)
					{
						total=0;
						for( k = GetFirstIdxKol(M1) ; k <= GetLastIdxKol(M1) ; k++)
							{
								total = total + ( (M1).Mem[i][k] * (M2).Mem[k][j] );
							};
						(M).Mem[i][j] = total;
					};
			};
		return(M);
	};

MATRIKS KaliKonsMat (MATRIKS M, ElTypeMat X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
	{
		// Kamus
		int i,j;
		MATRIKS M3;

		// Algoritma
		MakeMATRIKS( (M).NBrsEff , (M).NKolEff , &M3 );
		for ( i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) ; i++)
			{
				for ( j = GetFirstIdxKol(M) ; j<= GetLastIdxKol(M) ; j++)
					{
						(M3).Mem[i][j] = (M).Mem[i][j] * X;
					};
			};

		return (M3);

	};
void PKaliKons (MATRIKS * M, ElTypeMat K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
	{
		// Kamus
		int i,j;

		// Algoritma

		for ( i = GetFirstIdxBrs(*M) ; i <= GetLastIdxBrs(*M) ; i++)
			{
				for ( j = GetFirstIdxKol(*M) ; j<= GetLastIdxKol(*M) ; j++)
					{
						(*M).Mem[i][j] = (*M).Mem[i][j] * K;
					};
			};

	};

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQMat (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */

	{
		// Kamus
		indeks i,j;
		boolean sama;

		// Algoritma
		i=GetFirstIdxBrs(M1);
		j=GetFirstIdxKol(M1);
		sama = NBElmt(M1)==NBElmt(M2);

		while ( (sama) && (i<=GetLastIdxBrs(M1)))
		{
			while ( (sama) && (j<=GetLastIdxKol(M1)))
				{
					sama = (MatElmt(M1,i,j)==MatElmt(M2,i,j));
					j++;
				}
			i++;
			j =GetFirstIdxKol(M1);
		}
		return sama;
	}

boolean NEQMat (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	{
		// Kamus

		// Algoritma
		return(!EQMat(M1,M2));
	};

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	{
		// Kamus

		// Algoritma
		return ( (M1).NBrsEff == (M2).NBrsEff && (M1).NKolEff == (M2).NKolEff );
	};

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
	{
		// Kamus

		// Algoritma
		return ( NBrsEff(M) - GetFirstIdxBrs(M) + 1) * ( NKolEff(M) - GetFirstIdxKol(M) + 1);
	};

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	{
		// Kamus

		// Algoritma
		return ( NBrsEff(M) - GetFirstIdxBrs(M) + 1 ) == ( NKolEff(M) - GetFirstIdxKol(M) + 1);
	};

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
   {
   		// Kamus
   		int i,j;
   		boolean sama;

   		// Algoritma
   		sama = true;
   		if ( !(IsBujurSangkar(M)) )
		   {
		   		sama = false;
		   }
		else
			{
				i = GetFirstIdxBrs(M);
				while ( sama && i <= GetLastIdxBrs(M) )
					{
						j = i;
						while ( sama && j <= GetLastIdxKol(M) )
							{
								if ( (M).Mem[i][j] != (M).Mem[j][i] )
									{
										sama = false;
									};
								j++;
							};
						i++;
					};
			};
		return(sama);
   };

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   {
   		// Kamus
   		int i,j;
   		boolean satu;

   		// Algoritma
   		satu = true;
   		if ( !(IsBujurSangkar(M)) )
   			{
   				satu = false;
			}
		else
			{
				i = BrsMin;

				while ( satu && i <= GetLastIdxBrs(M) )
					{
						j = KolMin;
						while ( satu && j <= GetLastIdxKol(M) )
							{
								if ( i == j)
									{
										if ( (M).Mem[i][j] != 1)
											{
												satu = false;
											}

									}
								else
									{
										if ( (M).Mem[i][j] != 0)
											{
												satu = false;
											};
									};
								j++;
							};
						i++;
					};
			};
		return satu;
	};

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks �jarang� dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
	{
		// Kamus
		int MaxElmt;
		int count;
		boolean spars;
		indeks i,j;

		// Algoritma
		MaxElmt = (5 * NBElmt(M) / 100);
		count = 0;
		spars = true;

		i=GetFirstIdxBrs(M);
		j=GetFirstIdxKol(M);

		while ( (spars) && (i<=GetLastIdxBrs(M)))
		{
			while ((spars) && (j<=GetLastIdxKol(M)))
			{
				if (MatElmt(M,i,j)!=0)
				{
					count++;
					spars = ( count <= MaxElmt );
				}
				j++;
			}
			j=GetFirstIdxKol(M);
			i++;
		}

		return spars;
	}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	{
		// Kamus
		MATRIKS M1;
		int i,j;

		// Algoritma
		MakeMATRIKS( (M).NBrsEff , (M).NKolEff , &M1);
		for ( i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) ; i++ )
			{
				for ( j = GetFirstIdxKol(M) ; j <= GetLastIdxKol(M) ; j++)
					{
						(M1).Mem[i][j] = (M).Mem[i][j] * -1;
					};
			};
		return M1;
	};

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
	{
		// Kamus
		float det;
		int sign;
		indeks i,j,k,m;
		MATRIKS M1;

		// ALgoritma
		det = 0;
		sign = 1;

		if ( GetLastIdxBrs(M) == 1)
			{
				return ( GetElmtDiagonal(M,1));
			}
		else
			{
				for ( i = GetFirstIdxKol (M) ; i <= GetLastIdxKol(M) ; i++ )
					{
						m = GetFirstIdxKol(M1);
						MakeMATRIKS ( GetLastIdxBrs(M) - 1 , GetLastIdxKol(M) -1, &M1);
						for ( j = GetFirstIdxBrs(M) + 1 ; j <= GetLastIdxBrs(M) ; j++)
							{
								for ( k = GetFirstIdxKol(M) ; k <= GetLastIdxKol(M) ; k++)
									{
										if ( k != i )
											{
												MatElmt(M1,(j-1),m) = MatElmt(M,j,k);
												m++;
												if ( m > GetLastIdxKol(M) - 1)
													{
														m = GetFirstIdxKol(M1);
													}
											}
									}
							}
						det += sign*MatElmt(M,1,i)*Determinan(M1);
						sign *= -1;
					}
				return det;
			}
	}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	{
		// Kamus

		// ALgoritma
		(*M) = Inverse1(*M);
	};

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	{
		// Kamus
		int i,j;
		MATRIKS M1;

		// Algoritma
		MakeMATRIKS( (*M).NBrsEff , (*M).NKolEff , &M1);
		for ( i = GetFirstIdxBrs(*M) ; i <= GetLastIdxBrs(*M) ; i++)
			{
				for ( j = GetFirstIdxKol(*M) ; j <= GetLastIdxKol(*M) ; j++)
					{
						(M1).Mem[j][i] = (*M).Mem[i][j];
					};
			};
		*M = M1;
	};
