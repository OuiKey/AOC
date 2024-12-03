#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include <ctype.h>
#include "func.h"
#include "main.h"

bool mul(char tab[], int *first, int *second);

bool isDo(char tab[]);

bool isDont(char tab[]);

int main(int argc, char **argv)
{
    char tabBuff[12] = {0};  // Tableau pour accumuler des caractères
    FILE *fp;
    char buff;
    int int1 = 0;
    int int2 = 0;
    int nbMul = 0;
    int somme = 0;
    bool isdo = true;
    // Ouverture du fichier
    fp = fopen("input.txt", "r");
    if (!fp)
    {
        printf("Impossible d'ouvrir le fichier!");
        return 1;
    }

    // Lecture du fichier et accumulation des caractères dans tabBuff
    while (fscanf(fp, "%c", &buff) != EOF) {
        // On déplace tous les caractères dans tabBuff d'un indice vers la gauche
        for (int j = 0; j < 11; j++) {
            tabBuff[j] = tabBuff[j + 1];
        }
        
        // On ajoute le nouveau caractère à la fin de tabBuff
        tabBuff[11] = buff;

        if (isDo(tabBuff))
        {
            isdo = true;
        }

        if (isDont(tabBuff))
        {
            isdo = false;
        }
        

        // Si la chaîne "mul(xxx,xxx)" est trouvée, on affiche OK et on sort de la boucle
        if (mul(tabBuff, &int1, &int2)) {
            nbMul++;
            if (isdo) somme = somme + (int1 * int2);
            if (isdo) printf(" isDo = 1\n"); else printf(" isDo = 0\n");
            printf("\n");
        }
    }
    printf("Somme : %d", somme);
    // Fermeture du fichier
    fclose(fp);

    return 0;
}




bool isDo(char tab[]){

    if (tab[0] == 'd' && tab[1] == 'o' && tab[2] == '(' && tab[3] == ')') return true;

    else return false ;
}

bool isDont(char tab[]){

    if (tab[0] == 'd' && tab[1] == 'o' && tab[2] == 'n' && tab[3] == 0x27 && tab[4] == 't' && tab[5] == '(' && tab[6] == ')') return true;

    else return false ;
}

bool mul(char tab[], int *first, int *second) {
    int i = 0;

    // Recherche du motif "mul("
    if (tab[i] == 'm' && tab[i + 1] == 'u' && tab[i + 2] == 'l' && tab[i + 3] == '(') {
        i += 4;  // On avance après "mul("

        // Extraction des chiffres avant la virgule
        *first = 0;
        while (isdigit(tab[i])) {
            *first = *first * 10 + (tab[i] - '0'); // Construction du nombre
            i++;  // On avance dans la chaîne
        }

        // Vérification de la virgule
        if (tab[i] == ',') {
            i++;  // On avance après la virgule

            // Extraction des chiffres après la virgule
            *second = 0;
            while (isdigit(tab[i])) {
                *second = *second * 10 + (tab[i] - '0'); // Construction du nombre
                i++;  // On avance dans la chaîne
            }

            // Vérification de la parenthèse fermante
            if (tab[i] == ')') {
                return true;  // Le motif "mul(xxx,xxx)" est trouvé
            }
        }
    }

    return false;  // Le motif n'a pas été trouvé
}