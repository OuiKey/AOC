#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "func.h"
#include "main.h"

int main(int argc, char **argv)
{
    int i1 = 0;
    int i2 = 0;
    int buff = 0;
    int dist = 0;
    int tab[tabL][tabW] = {0};
    int iteration = 0;
    int nbValLues = 0;

    if (getInteger(tab, "data.csv", &nbValLues))
    {
        printf("ERREUR\n");
    }


    sortTab(tab, nbValLues);
    
    printf("Entier1\tEntier2\tDiff\tDistance\n");
    while (iteration < nbValLues)
    {
        i1 = tab[iteration][0];
        i2 = tab[iteration][1];

        buff = diff(i1, i2);
        dist += buff;

        printf("%d\t%d\t%d\t%d\n", i1, i2, buff, dist);

        iteration += 1;
    }

    return 0;
}

