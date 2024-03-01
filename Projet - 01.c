#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int char_vers_int(char c){ // fonction pour convertir char en int, renvoie la valeur int du char 0 1 2 3 4 5 6 7 8 9 A B C D E F
    int c_int;
    switch (c) {
        case '0':
            c_int = 0;
            break;
        case '1':
            c_int = 1;
            break;
        case '2':
            c_int = 2;
            break;
        case '3':
            c_int = 3;
            break;
        case '4':
            c_int = 4;
            break;
        case '5':
            c_int = 5;
            break;
        case '6':
            c_int = 6;
            break;
        case '7':
            c_int = 7;
            break;
        case '8':
            c_int = 8;
            break;
        case '9':
            c_int = 9;
            break;
        case 'A':
            c_int = 10;
            break;
        case 'B':
            c_int = 11;
            break;
        case 'C':
            c_int = 12;
            break;
        case 'D':
            c_int = 13;
            break;
        case 'E':
            c_int = 14;
            break;
        case 'F':
            c_int = 15;
            break;
        case 'a':
            c_int = 10;
            break;
        case 'b':
            c_int = 11;
            break;
        case 'c':
            c_int = 12;
            break;
        case 'd':
            c_int = 13;
            break;
        case 'e':
            c_int = 14;
            break;
        case 'f':
            c_int = 15;
            break;
        default:
            printf("Chiffre saisi invalide : %c\n", c);
            exit(1);
    }
    return c_int;
}

int* tab_A(char num[1000], int num_size){ // fonction pour enregistrer le numéro dans le tableau (tab_A)
    int *tabA, i = 0;

    tabA = (int*)malloc(num_size * sizeof(int));
    while (i < num_size)
    {
        tabA[i] = char_vers_int(num[i]);
        i++;
    }
    return tabA;
}

int baseA_vers_decimal( int *tabA, int num_size, int BaseA){ // fonction pour convertir le num de la base A a la base décimale
    int num_10 = 0, i = 0;

    if( num_size == 1)
        return (tabA[i]);

    for( i=0; i< num_size; i++)
        num_10 += ( tabA[i] * pow(BaseA, (num_size-i-1) ));

    return num_10;
}

int* decimal_vers_baseB(int num_10, int BaseB, int *size){ // fonction pour convertir le num de la base décimale a la base B
    int *tabB = NULL;
    int i = 0, q, r;
    q = num_10;

    if (q == 0) {
        *size = 1;
        tabB = (int*)malloc(sizeof(int));
        tabB[i] = 0;
        return tabB;
    } else {
        while (q != 0) {
            r = q % BaseB;
            q = q / BaseB;
            if (i == 0) {
                tabB = (int*)malloc(sizeof(int));
            } else {
                tabB = (int*)realloc(tabB, (i + 1) * sizeof(int));
            }
            tabB[i] = r;
            i++;
        }
        *size = i;
    }

    int *tabB_V = (int*)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++) {
        tabB_V[j] = tabB[i - 1 - j];
    }

    free(tabB);
    return tabB_V;
}

int main() {
    int BaseA, BaseB;
    char num[1000];
    int *tabA, *tabB_V;
    int num_10, size;

    printf("cette programme permettant de convertir un nombre d'une base A vers une base B.\n(A et B compris entre 2 et 16)\n\n");

    printf("Enter la base A : ");
    scanf("%d", &BaseA);
    while (BaseA < 2 || BaseA > 16) {
        printf("Base source invalide.\n");
        printf("Enter la base A (A doit etre compris entre 2 et 16): ");
        scanf("%d", &BaseA);
    }

    printf("\n");
    printf("Enter la base B : ");
    scanf("%d", &BaseB);
    while (BaseB < 2 || BaseB > 16) {
        printf("Base source invalide.\n");
        printf("Enter la base B (B doit etre compris entre 2 et 16): ");
        scanf("%d", &BaseB);
    }

    printf("\n");
    printf("Enter the number in base %d: ", BaseA);
    scanf("%s", num);

    if (BaseA != 10)
    {
        int num_size = strlen(num);
        tabA = tab_A(num, num_size);
        num_10 = baseA_vers_decimal(tabA, num_size, BaseA);
    }
    else num_10 = atoi(num);


    if (BaseB != 10 && BaseA != 10)
        printf("\nle nombre en base decimal est : %d", num_10);

    tabB_V = decimal_vers_baseB(num_10, BaseB, &size);

    printf("\nle nombre en base %d est : ", BaseB);

    for (int i = 0 ; i < size; i++) {
        if (tabB_V[i] >= 10)
            printf("%c", 'A' + (tabB_V[i] - 10));
        else printf("%d", tabB_V[i]);
    }
    printf("\n ");

    return 0;
}
