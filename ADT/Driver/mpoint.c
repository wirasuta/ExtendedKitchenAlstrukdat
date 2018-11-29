// Driver untuk ADT Point
// Pandyaka A / 13517003

#include "../Impl/point.c"
#include <stdio.h>

int main ()
    {
        // Kamus Lokal
        POINT driverpoint;
        POINT pembanding;


        // Algoritma
        printf("point 1 : \n");
        BacaPOINT(&driverpoint);

        printf("Point anda ada di : \n");
        TulisPOINT(driverpoint);
        printf("\n");

        printf("Masukkan point untuk pembanding : \n");
        BacaPOINT(&pembanding);

        printf("Point pembanding anda ada di : \n");
        TulisPOINT(pembanding);
        printf("\n");
        if ( EQ(driverpoint,pembanding) )
            {
                printf("Point anda equal \n");
            };
        if ( NEQ(driverpoint,pembanding) )
            {
                printf("Point anda tidak equal \n");
            }
        if ( IsOrigin(driverpoint) )
            {
                printf("Point anda origin \n");
            }
        if ( IsOnSbX(driverpoint) )
            {
                printf("Point anda di sumbu x \n");
            }
        if ( IsOnSbY(driverpoint) )
            {
                printf("Point anda di sumbu y \n");
            }

        printf("Next X point anda ada di :");
        driverpoint = NextX(driverpoint);
        TulisPOINT(driverpoint);
        printf("\n");

        printf("Next Y point anda ada di :");
        driverpoint = NextY(driverpoint);
        TulisPOINT(driverpoint);
        printf("\n");

        printf("Geser 2,3 point anda, sehingga ada di :");
        Geser(&driverpoint,2,3);
        TulisPOINT(driverpoint);
        printf("\n");

    }
