#include <stdio.h>
#include <stdlib.h>

int decimal_vers_binaire(int nmu_ent, int*size){
    int *tabB, i = 0, q, r;
    q = nmu_ent;
    tabB = (int*)malloc(sizeof(int));
    if (q == 0) {
        *size = 1;
        tabB[i] = 0;
        return tabB;
    }
    while (q != 0)
    {
        r = q%2;
        q = q/2;
        tabB = (int*)realloc(tabB,(i+1)*sizeof(int));
        tabB[i] = r;
        i++;
    }
    int* tabB_V = (int*)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++) {
        tabB_V[j] = tabB[i - 1 - j];
    }
    *size = i;
    free(tabB);
    return tabB_V;
}

int main()
{
    float num, num_fra;
    int nmu_ent;
    int ent_bits, fra_bits;
    int *tab_ent, *tab_fra;

    printf("ce programme permettant de representer un nomber reel en binaire avec la methode de virgule fix\n\n");
    printf("donnee le nombre de bits pour la partie entière : ");
    scanf("%d", &ent_bits);
    printf("donnee le nombre de bits pour la partie fractionnaire  : ");
    scanf("%d", &fra_bits);

    tab_ent = (int*)malloc(ent_bits*sizeof(int));
    tab_fra = (int*)malloc(fra_bits*sizeof(int));

    for (int i = 0;i < ent_bits;i++)
        tab_ent[i] = 0;

    for (int j = 0;j < fra_bits;j++)
        tab_fra[j] = 0;

    printf("\nle nombre = ");
    scanf("%f", &num);

    if (num < 0)
    {
        tab_ent[0] = 1;
        num = -num;
    }

    nmu_ent = num;
    num_fra = num - nmu_ent;

    int *tabB_V, size;
    tabB_V = decimal_vers_binaire(nmu_ent, &size);

    int k = size-1;

    for (int i = ent_bits-1;i > 0;i--)
    {
            if (k>=0)
            tab_ent[i] = tabB_V[k];
            k--;
    }

    float q;
    int x;

    q = num_fra;
    int i = 0;

    while (q != 1.0 && i < fra_bits)
    {
        q = q*2;
        x = q;
        if (q > 1)
            q = q-1;
        tab_fra[i] = x;
        i++;
    }

    printf("\nle resultat est :\n");

    for (int j = 0;j < ent_bits;j++)
    {
        printf("%d",tab_ent[j]);
    }

    for (int j = 0;j < fra_bits;j++)
    {
        printf("%d",tab_fra[j]);
    }

    printf("\n");
}
