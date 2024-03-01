#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int *tab_ent, *tab_fra;
    int size_ent, size_fra;
    int i = 0, j = 0, k = 0;
    int sum_ent = 0;
    float sum_fra = 0.0;
    float sum = 0.0;

    printf("Ce programme permettant de lire un nombre en binaire (avec virgule) et afficher comme nombre reel\navec la methode de virgule fixe.\n");

    printf("\n>>> Entrez la partie entiere (chiffre par chiffre)\n[Entrez le chiffre 2 pour terminer]\n");
    tab_ent = (int*)malloc(sizeof(int));
    printf("\nLe 1 er chiffre : ");
    scanf("%d", &tab_ent[i]);
    while (tab_ent[i] != 2) {
        i++;
        tab_ent = (int*)realloc(tab_ent, (i + 1) * sizeof(int));
        printf("Le %deme chiffre : ", i + 1);
        scanf("%d", &tab_ent[i]);
    }
    size_ent = i;

    printf("\n>>> Entrez la partie fractionnaire (chiffre par chiffre)\n[Entrez le chiffre 2 pour terminer]\n");
    tab_fra = (int*)malloc(sizeof(int));
    printf("\nLe 1 er chiffre : ");
    scanf("%d", &tab_fra[j]);
    while (tab_fra[j] != 2) {
        j++;
        tab_fra = (int*)realloc(tab_fra, (j + 1) * sizeof(int));
        printf("Le %deme chiffre : ", j + 1);
        scanf("%d", &tab_fra[j]);
    }
    size_fra = j;

    printf("\nle resultat est : ");

    k = size_ent - 1;
    for (i = 0; i < size_ent; i++)
    {
        sum_ent += (tab_ent[i] * pow(2, k));
        k--;
    }


    k = -1;
    for (j = 0; j < size_fra; j++)
    {
        sum_fra += (tab_fra[j] * pow(2, k));
        k--;
    }

    sum = sum_ent + sum_fra;
    printf("%f", sum);

    return 0;
}
