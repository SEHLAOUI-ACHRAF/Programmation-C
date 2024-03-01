#include <stdio.h>
#include <stdlib.h>

int decimal_vers_binaire_int(int nmu, int *size){
    int *tabB, i = 0, q, r;
    q = nmu;
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

int decimal_vers_binaire_float(float num, int *size_0, int *size_1) {
    float num_fra;
    int size=0;
    int nmu_ent;
    int *tab_fra, *tabA, *tabB;
    int i = 0,j = 0,k = 0;

    tab_fra = (int*)malloc(sizeof(int));

    nmu_ent = num;
    num_fra = num - nmu_ent;

    tabB = decimal_vers_binaire_int(nmu_ent, &size);

    float q;
    int x;

    q = num_fra;

    while (q != 1.0)
    {
        q = q*2;
        x = q;
        if (q > 1)
            q = q-1;
        tab_fra[i] = x;
        i++;
        tab_fra = (int*)realloc(tab_fra, (i + 1) * sizeof(int));
    }
    k = i;
    tabA = (int*)malloc((k + size)*sizeof(int));

    for (j = 0; j < size; j++)
        tabA[j] = tabB[j];

    for (i = 0; i < k; i++)
    {
        tabA[j] = tab_fra[i];
        j++;
    }

    *size_0 = size;
    *size_1 = k + size;

    return tabA;
}

int main()
{
    float num;
    int *tab_exp, *tab_mn, *tab_sig;
    int precision, expo_bits, mn_bits;
    int *tabA, *tabB_V, size=0, size_0=0, size_1=0;
    int i, j;

    printf("ce programme permettant de representer un nomber reel en binaire avec la methode de virgule flottante\n\n");
    printf("pour choisir la precision :\n");
    printf("1 : pour Simple precision (32 bits)\n2 : pour Double precision (64 bits)\n\nla precision : ");
    scanf("%d", &precision);

    if (precision == 1)
    {
        expo_bits = 8;
        mn_bits = 23;
    }
    else if (precision == 2)
    {
        expo_bits = 11;
        mn_bits = 52;
    }
    else
    {
        printf("precision no detecter");
        exit(1);
    }

    tab_exp = (int*)malloc(expo_bits*sizeof(int)); // pour la partie d�exposant
    tab_mn = (int*)malloc(mn_bits*sizeof(int)); // pour la partie de mantisse
    tab_sig = (int*)malloc(sizeof(int)); // pour le signe

    for (int i = 0;i < expo_bits;i++)
        tab_exp[i] = 0;

    for (int j = 0;j < mn_bits;j++)
        tab_mn[j] = 0;

    printf("\nle nombre = ");
    scanf("%f", &num);

    if (num < 0)
    {
        tab_sig[0] = 1;
        num = -num;
    } else tab_sig[0] = 0;

    tabA = decimal_vers_binaire_float(num, &size_0, &size_1);
    int v = 0;
    i = 0;
    while (v != 1)
    {
        if (tabA[i] == 1)
            v = 1;
        else
            i++;
    }
    v = i+1; // v est la position de la 1er [1] dans le tableau pour remplire la partie d�exposant
    int e = size_0 - v;
    int E = e + 127;
    tabB_V = decimal_vers_binaire_int(E, &size);

    j = expo_bits - 1;
    for (i = (size - 1); i >= 0; i--)
    {
        tab_exp[j] = tabB_V[i];
        j--;
    }

    i = 0,j = v;
    for (i = 0; i < (size_1 - v); i++)
    {
        tab_mn[i] = tabA[j];
        j++;
    }

    printf("\nle resultat est :\n");
    printf("%d ",tab_sig[0]);
    for (i = 0; i < expo_bits; i++)
        printf("%d",tab_exp[i]);
    printf(" ");
    for (i = 0; i < mn_bits; i++)
        printf("%d",tab_mn[i]);
    printf("\n");
}
