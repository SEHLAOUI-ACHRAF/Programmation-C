#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Fonction pour afficher un tableau d'entiers
void affichage(int *T, int s) {
    for (int i = s - 1; i >= 0; i--) {
        printf("%d", T[i]);
    }
    printf("\n");
}

// Fonction pour ajouter la base si le nombre est négatif
int *ADDBASE(int *T, int s, int i) {
    for (int j = s - 1; j >= i; j--) {
        if (j == s - 1) {
            T[j] = 1;
        } else {
            T[j] = 0;
        }
    }
    return T;
}

// Fonction pour effectuer le complément à un (CM1)
int *CM1(int *T, int s) {
    for (int d = 0; d < s - 1; d++) {
        if (T[d] == 1) {
            T[d] = 0;
        } else {
            T[d] = 1;
        }
    }
    return T;
}

// Fonction pour effectuer le complément à un (Ca1), version alternative
int *CM1B(int *t, int s) {
    int i;
    for (i = 1; i < s - 1; i++) {
        if (t[i] == 1) {
            t[i] = 0;
        } else {
            t[i] = 1;
        }
    }
    return t;
}

// Fonction pour effectuer le complément à deux (Ca2)
int *CM2(int *T, int s) {
    for (int k = 0; k < s - 1; k++) {
        if (T[k] == 0) {
            T[k] = 1;
            break;
        } else {
            T[k] = 0;
        }
    }
    return T;
}

// Fonction pour convertir un tableau binaire en décimal
int BTOD(int *T2, int n) {
    int x = 0;
    for (int i = 0; i < n - 1; i++) {
        x += pow(2, i) * T2[n - i - 1];
    }
    return x;
}

int main() {
    int b, s, p, n;
    int i = 0;

    printf("Entrer la Base de saisir : ");
    scanf("%d", &b);

    if (b >= 2 && b <= 10) {
        getchar();

        if (b != 2) {
            printf("Donner le nombre de bits a coder : ");
            scanf("%d", &s);

            if (b > 10 && b <= 16) {
                printf("Donner le nombre a saisir : ");
                scanf("%X", &p);
            } else {
                printf("Donner le nombre a saisir : ");
                scanf("%d", &p);
            }

            int *T = (int *)malloc(s * sizeof(int));

            if (p < 0) {
                p = -p;

                while (p != 0) {
                    T[i] = p % 2;
                    p = p / 2;
                    i++;
                }
                n = i;
                T = ADDBASE(T, s, n);

                printf("\nLa valeur signe : ");
                affichage(T, s);
                T = CM1(T, s);

                printf("\nCa1 : ");
                affichage(T, s);

                printf("\nCa2 : ");
                T = CM2(T, s);

                affichage(T, s);
            } else {
                i = 0;
                int k = 0;
                while (p != 0) {
                    T[i] = p % 2;
                    p = p / 2;
                    i++;
                }

                for (int j = s - 1; j >= i; j--) {
                    T[j] = 0;
                }

                printf("\nLa valeur signe : ");
                affichage(T, s);

                printf("\nCa1 : ");
                affichage(T, s);

                printf("\nCa2 : ");
                affichage(T, s);
            }
        } else {
            char c;
            int *T2;
            int x = 0;

            T2 = (int *)malloc(sizeof(int));

            printf("Entrer le nombre binaire : ");
            while ((c = getchar()) != '\n') {
                T2[i] = c - '0';
                i++;
                T2 = (int *)realloc(T2, (i + 1) * sizeof(int));
            }
            n = i;

            if (T2[0] == 0) {
                x = BTOD(T2, n);
                printf("La valeur est %d", x);
            } else {
                int conversionChoice;
                printf("\nChoisissez le type de nombre binaire :\n");
                printf("1. CM2\n");
                printf("2. CM1\n");
                printf("3. Valeur Signee (VS)\n");
                printf("\nVotre choix : ");
                scanf("%d", &conversionChoice);

                switch (conversionChoice) {
                    case 1:
                        for (i = n - 1; i > 0; i--) {
                            if (T2[i] == 1) {
                                T2[i] = 0;
                                break;
                            } else {
                                T2[i] = 1;
                            }
                        }
                        printf("\nDe Ca2 a Ca1: ");
                        for (i = 0; i < n; i++) {
                            printf("%d", T2[i]);
                        }
                        printf("\n");

                        printf("De Ca1 a VS: ");
                        T2 = CM1B(T2, n + 1);
                        for (i = 0; i < n; i++) {
                            printf("%d", T2[i]);
                        }
                        printf("\n");

                        printf("De Valeur signee a un nombre decimal: ");
                        x = BTOD(T2, n);
                        printf("%d\n", -x);
                        break;
                    case 2:
                        printf("\nEn Valeur Signee (VS) : ");
                        T2 = CM1B(T2, n + 1);
                        for (i = 0; i < n; i++) {
                            printf("%d", T2[i]);
                        }
                        printf("\n");

                        printf("Valeur en decimal signee : ");
                        x = BTOD(T2, n);
                        printf("%d", -x);
                        printf("\n");
                        break;
                    case 3:
                        x = BTOD(T2, n);
                        printf("\nValeur en decimal signee : %d\n", -x);
                        break;
                    default:
                        printf("Choix invalide\n");
                        break;
                }
            }
        }
    } else {
        printf("Erreur de base");
    }

    return 0;
}
