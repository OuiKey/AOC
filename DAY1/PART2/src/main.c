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
    int total = 0;
    int tab[tabL][tabW] = {0};
    int tabSim[tabL][tabW] = {0};
    int iteration = 0;
    int nbValLues = 0;

    if (getInteger(tab, "data.csv", &nbValLues))
    {
        printf("ERREUR\n");
    }

    occurrenceCounter(tab, tabSim, nbValLues);

    printf("Entier1\tEntier2\tSim\tTotal\n");
    while (iteration < nbValLues)
    {
        i1 = tabSim [iteration][0];
        i2 = tabSim [iteration][1];

        buff = i1*i2;
        total += buff;

        printf("%d\t%d\t%d\t%d\n", i1, i2, buff, total);

        iteration += 1;
    }

    return 0;
}

