#include <stdio.h>  // Pour les fonctions d'entrée/sortie (printf, scanf).
#include <stdlib.h> // Pour les fonctions utilitaires (malloc, free, rand).
#include <limits.h>
#include "func.h"   // Fichier d'en-tête contenant les définitions des fonctions et structures du jeu.

int diff(int integer1, int integer2)
{
    int i1 = (integer1 > integer2) ? integer1 : integer2;
    int i2 = (integer1 > integer2) ? integer2 : integer1;

    return i1 - i2;
}

char getInteger(int tab[tabL][tabW], char fileName[], int *nbValLues)
{

    // Fichier
    FILE *fp;
    // variables pour le temps et la valeur
    int numA, numB;
    // nombre de champs lus à chaque ligne
    int nbChamp;

    // ouverture fichier
    fp = fopen(fileName, "r");
    // Si le fichier n'est pas ouvrable
    if (!fp)
    {
        printf("Impossible d'ouvrir le fichier!");
        return 1;
    }
    else
    {
        do
        {
            // On lit les deux champs année / valeur
            nbChamp = fscanf(fp, "%d,%d", &numA, &numB);
            if (nbChamp == 2)
            {
                printf("getInteger : valeurs lues : %d %d \n", numA, numB);
                tab[(*nbValLues)][0] = numA;
                tab[(*nbValLues)][1] = numB;
                (*nbValLues)++;
            }
        } while (!feof(fp));
        // Fermeture du fichier
        fclose(fp);
        printf("getInteger : Nb valeur = %d\n", *nbValLues);
    }

    return 0;
}

void sortTab(int tab[tabL][tabW], int nbValLues)
{
    int tabBuff[tabL][tabW] = {0};
    int buff = 0;
    int min = INT_MAX;
    int iBuff = 0;

    printf("\nsortTab : Tableau non trier\n");

    for (int i = 0; i < nbValLues; i++)
    {
        printf("\tsortTab : %d, %d\n", tab[i][0], tab[i][1]);
    }
    

    for (int b = 0; b < tabW; b++)
    {
        for (int j = 0; j < nbValLues; j++)
        {
            for (int i = 0; i < nbValLues; i++)
            {
                buff = tab[i][b];
                
                if (buff != 0)
                {
                    if (min > buff)
                    {
                        min = buff;
                        iBuff = i;
                    }
                }
            }

            tabBuff[j][b] = min;
            tab[iBuff][b] = 0;
            min = INT_MAX;
        }
    }
    printf("\nsortTab : Tableau trier\n");

    for (int i = 0; i < nbValLues; i++)
    {
        printf("\tsortTab : %d, %d\n", tabBuff[i][0], tabBuff[i][1]);
    } 

    for (int b = 0; b < tabW; b++)
    {
        for (int i = 0; i < nbValLues; i++)
        {
            tab[i][b] = tabBuff[i][b];
        }
    }
}

