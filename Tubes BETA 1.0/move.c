#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "move.h"

boolean pathFilled(MATRIKS M ,int X, int Y)
{
    return ((Elmt(M, X, Y) == 'X') || (Elmt(M, X, Y) == 'M') || (Elmt(M, X, Y) == 'C'));
    //tinggal tambah kalo X, Y < Btsmin Ruangan dan X, Y > Btsmax Ruangan
}

void newCoordinate(MATRIKS M, int *X, int *Y, char a[4])
{
    char string[4];

    strcpy(string, a);

    if (strcmp(string, "GU") == 0)
    {
        if (pathFilled(M, *X, *Y-1))
        {
         printf("Path is Filled! \n");
        }
        else
        {
        *Y = *Y - 1;
        }
    }
    else if (strcmp(string, "GD") == 0)
    {
        if (pathFilled(M, *X, *Y+1))
        {
         printf("Path is Filled! \n");
        }
        else
        {
        *Y = *Y + 1;
        }
    }
    else if (strcmp(string, "GL") == 0)
    {
        if (pathFilled(M, *X - 1, *Y))
        {
         printf("Path is Filled! \n");
        }
        else
        {
        *X = *X - 1;
        }
    }
    else if (strcmp(string, "GR") == 0)
    {
        if (pathFilled(M, *X+1, *Y))
        {
         printf("Path is Filled! \n");
        }
        else
        {
        *X = *X + 1;
        }
    }
}

void move(MATRIKS *M, int *X, int *Y,char a[4])
{

        Elmt(*M, *X, *Y) = NULL;
        newCoordinate(*M, X, Y, a);
        Elmt(*M, *X, *Y) = 'P';

}



int main()
{
    MATRIKS Map;
    char command[4];
    int X, Y;

    MakeMATRIKS(10, 10, &Map);
    X = 4;
    Y = 4;

    //Current Position
    Elmt(Map, 4, 3) = 'X';

    Elmt(Map, X, Y) = 'P';
    printf("Initial Position : %d %d \n", X, Y);
    printf("Move Command : ");
    scanf(" %s", command);
    move(&Map, &X, &Y, command);
    printf("Next Position: %d %d", X, Y);
}
