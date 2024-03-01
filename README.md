# Programmation-C
Des programmes en langage C :

    1 - Conversion des nombres
    2 - Representation des entiers signes
    3 - Representation des nombres à virgule:
             A - nombre réel en binaire avec la méthode de virgule fixe
             B - un nomber en binaire et affaiche come nomber reel avec la methode de virgule fixe
             C - représenter un nombre réel en binaire avec la méthode de virgule flottante en Codage IEEE 754 avec simple précision et double précision
             
# Le 1er problème : Conversion des nombres :
    Un programme permettant de convertir un nombre d'des bases A vers une base B (A et B compris entre 2 et 16).

L’analyse de problème :

    Dans le programme pour convertir un nombre d'des bases A vers une base B en va utilise la base décimal (10) comme une base intermidier en va convertir le nombre (base A) en décimal après en va convertire se nombre décimal en base B.    
    Dans ce pragramme en va utiliser les tableaux pour sevgarde et faire des traitements mathématiques pour avoir le résultèrent et pour les nombres dans la base 16 en va utiliser la fonction switch() pour remplacer les chiffres (A, B, C, D, E, F) par les nombres (10, 11, 12, 13, 14, 15).

Les étapes de programme :

    1.	Lire le nombre dans la base A
    2.	Sevgarde le nombre dans un tableau (tabA[] )
    3.	Converter les valeurs de tableau (tabA[] ) de char vers int ( A>10 B>11 C>12 D>13 E>14 F>15 )
    4.	Converter le nombre en decimal
    5.	Converter se décimal en base B
    6.	affiché le nombre dans la base B

L’algorithme :

    Entrées :
        BaseA : un entier (entre 2 et 16) représentant la base source.
        BaseB : un entier (entre 2 et 16) représentant la base cible.
        num : une chaîne de caractères représentant le nombre en base BaseA.

    Sorties :
        num_10 : un entier représentant le nombre en décimal.
        num_B : une chaîne de caractères représentant le nombre en base BaseB.

    Début :

    Lire BaseA de l'utilisateur
    Tant que BaseA n'est pas compris entre 2 et 16 :
    	Afficher "Base source invalide. Base A doit être entre 2 et 16."
    	Lire BaseA de l'utilisateur
        
    Lire BaseB de l'utilisateur
    Tant que BaseB n'est pas compris entre 2 et 16 :
    	Afficher "Base cible invalide. Base B doit être entre 2 et 16."
    	Lire BaseB de l'utilisateur
        
    Lire num de l'utilisateur
    num  ConvertirCaractèreEnEntier(num) // ( A=10 B=11 C=12 D=13 E=14 F=15 )
    num_size  longueur de num
        
    num_10  0
    Pour i de 0 à num_size - 1 :
    	power  num_size - i - 1
    num_10  num_10 + tabA[i] ^ power
    
    Afficher "Le nombre en décimal est : num_10"
    
    num_B  [] // Initialiser une chaîne vide
    Tant que num_10 > 0 :
    	reste  num_10 % BaseB
    	chiffre  ConvertirEntierEnCaractère(reste) // ( 10=A 11=B 12=C 13=D 14=E 15=F )
    	num_B  chiffre
    	num_10  num_10 / BaseB
        
    Afficher "Le nombre en base BaseB est : num_B"

    Fin

# Le 2eme problème : Representation des entiers signes :
Un programme permettant de représenter les entiers signés en utilisant les 3 méthodes :
VS, Cà1, Cà2. 

L’analyse de problème :

    Dans ces pragrammes en va utiliser les tableaux pour sevgarde et faire les traitements nécessaires pour avoir le résultèrent
    dans ce problème il y a 2 parties :
        1-partie : représenter les entiers signés en VS et Ca1 et Ca2 (en bainire)
        2-partie : laire les entiers signés soit en VS ou Ca1 ou Ca2 (en bainire) et représente le en decimal
        	C'est la réciproque de la ( 1-partie )

    Le programme prend également en charge la conversion du binaire en décimal et affiche le résultat correspondant.
    
    Le programme utilise des structures de contrôle pour gérer l'entrée de l'utilisateur et effectuer les conversions appropriées.
    
Gestion des erreurs :

    Le programme gère les erreurs en vérifiant que la base est dans la plage spécifiée (entre 2 et 16) et affiche un message d'erreur en cas de base incorrecte.
    
    Le programme est structuré de manière à permettre à l'utilisateur de convertir entre plusieurs formats en fonction de la base initiale et des choix effectués. Il offre une grande flexibilité pour la conversion de valeurs en utilisant le complément à un (CM1), le complément à deux (CM2), ou la représentation en Valeur Signée (VS) pour les nombres binaires.

Les étapes de programme :

    1.	Saisie de la base : Demandez à l'utilisateur d'entrer la base b et Vérifiez si b est dans [2, 10]
    2.	Gestion des erreurs de base : Si la base b n'est pas dans la plage [2, 10], affichez "Erreur de base".
    3.	Gestion des bases autres que 2 : Si b n'est pas égal à 2, demandez le nombre de bits s, Demandez à l'utilisateur d'entrer la valeur p, Si b est dans la plage [11, 16], permettez à l'utilisateur d'entrer en hexadécimal.
    4.	Conversion de décimal en binaire (si p est négatif) : Si p est négatif, convertissez p en binaire en utilisant une boucle de division par 2 et ajoutez la base si nécessaire, Affichez la valeur signée, effectuez le CM1, puis le CM2, Affichez les résultats.
    5.	Conversion de décimal en binaire (si p est positif) : Si p est positif, remplissez le tableau avec les bits du nombre p et complétez avec des zéros à gauche si nécessaire, Affichez la valeur signée, le CM1 et le CM2.
    6.	Conversion de binaire en décimal (si b est égal à 2) : Si b est égal à 2, l'utilisateur entre un nombre binaire, Si le premier bit est 0, convertissez-le en décimal et affichez la valeur, Si le premier bit est 1, demandez à l'utilisateur de choisir une conversion (CM2, CM1, VS).
    7.	Conversion CM2, CM1 et VS (si b est égal à 2)
    
    Selon le choix de conversion de l'utilisateur (CM2, CM1, VS), effectuez la conversion appropriée et affichez le résultat.

    Le programme est structuré pour gérer la conversion entre décimal et binaire en prenant en charge différentes bases et les conversions CM1, CM2 et VS pour les nombres binaires.

L’algorithme :

    Début :

    Afficher "Entrer la Base = "
    Lire b

    Si b < 2 OU b > 10 Alors
        Afficher "Erreur de base"
        Arrêter le programme
    Fin Si
    
    Ignorer la ligne suivante (pour la saisie utilisateur)
    
    Si b ? 2 Alors
        Afficher "Donner le nombre de bits à coder : "
        Lire s
        
        Si b > 10 ET b <= 16 Alors
            Afficher "Donner le nombre à saisir en hexadécimal : "
            Lire p (en hexadécimal)
        Sinon
            Afficher "Donner le nombre à saisir : "
            Lire p
        Fin Si
        
        Si p < 0 Alors
            p <- -p
            i <- 0
            
            Tant que p ? 0 Faire
                T[i] <- p % 2
                p <- p / 2
                i <- i + 1
            Fin Tant que
            
            n <- i
            
            Pour j allant de 0 à s - 1 Faire
                Si j = n Alors
                    T[j] <- 1
                Sinon
                    T[j] <- 0
                Fin Si
            Fin Pour
            
            Afficher "La valeur signe : "
            Pour j allant de s - 1 à 0 (en décroissant) Faire
                Afficher T[j]
            Fin Pour
            Afficher une nouvelle ligne
            
            Pour j allant de 0 à s - 1 Faire
                Si T[j] = 1 Alors
                    T[j] <- 0
                Sinon
                    T[j] <- 1
                Fin Si
            Fin Pour
            
            Afficher "CM1"
            Pour j allant de s - 1 à 0 (en décroissant) Faire
                Afficher T[j]
            Fin Pour
            Afficher une nouvelle ligne
            
            Afficher "CM2"
            Pour j allant de 0 à s - 1 Faire
                Si T[j] = 0 Alors
                    T[j] <- 1
                    Sortir de la boucle
                Sinon
                    T[j] <- 0
                Fin Si
            Fin Pour
            
            Afficher "CM2"
            Pour j allant de s - 1 à 0 (en décroissant) Faire
                Afficher T[j]
            Fin Pour
            Afficher une nouvelle ligne
        Sinon
            i <- 0
            k <- 0
            
            Tant que p ? 0 Faire
                T[i] <- p % 2
                p <- p / 2
                i <- i + 1
            Fin Tant que
            
            Pour j allant de s - 1 à i (en décroissant) Faire
                T[j] <- 0
            Fin Pour
            
            Afficher "La valeur signe :"
            Pour j allant de s - 1 à 0 (en décroissant) Faire
                Afficher T[j]
            Fin Pour
            Afficher une nouvelle ligne
            
            Afficher "CM1:"
            Pour j allant de s - 1 à 0 (en décroissant) Faire
                Afficher T[j]
            Fin Pour
            Afficher une nouvelle ligne
            
            Afficher "CM2:"
            Pour j allant de s - 1 à 0 (en décroissant) Faire
                Afficher T[j]
            Fin Pour
            Afficher une nouvelle ligne
        Fin Si
    Sinon
        i <- 0
        
        Tant que c ? retour chariot Faire
            Lire c
            T[i] <- Entier(c)
            i <- i + 1
        Fin Tant que
        
        n <- i
        
        Si T[0] = 0 Alors
            x <- 0
            Pour j allant de 0 à n - 1 Faire
                x <- x + T[j] * 2^(n - j - 1)
            Fin Pour
            Afficher "La valeur est ", x
        Sinon
            Afficher "Choisissez une conversion :"
            Afficher "1. CM2"
            Afficher "2. CM1"
            Afficher "3. Valeur Signee (VS)"
            Afficher "Votre choix : "
            Lire choix
            
            Selon choix Faire
                Cas 1:
                    Pour j allant de n - 1 à 1 (en décroissant) Faire
                        Si T[j] = 1 Alors
                            T[j] <- 0
                            Sortir de la boucle
                        Sinon
                            T[j] <- 1
                        Fin Si
                    Fin Pour
                    
                    Afficher "De CM2 a CM1: "
                    Pour j allant de 0 à n - 1 Faire
                        Afficher T[j]
                    Fin Pour
                    Afficher une nouvelle ligne
                    
                    Afficher "De CM1 a VS: "
                    Pour j allant de 0 à n - 1 Faire
                        T[j] <- CM1B(T[j])
                    Fin Pour
                    Pour j allant de 0 à n - 1 Faire
                        Afficher T[j]
                    Fin Pour
                    Afficher une nouvelle ligne
                    
                    Afficher "De Valeur signee a un nombre decimal: "
                    x <- BTOD(T, n)
                    Afficher -x
                Fin Cas
                Cas 2:
                    Afficher "Conversion en CM1 : "
                    Pour j allant de 0 à n - 1 Faire
                        T[j] <- CM1B(T[j])
                    Fin Pour
                    Pour j allant de 0 à n - 1 Faire
                        Afficher T[j]
                    Fin Pour
                    Afficher une nouvelle ligne
                    
                    Afficher "Valeur en decimal signee "
                    x <- BTOD(T, n)
                    Afficher -x
                Fin Cas
                Cas 3:
                    x <- BTOD(T, n)
                    Afficher "Conversion en Valeur Signee (VS) : ", -x
                Fin Cas
                Cas par défaut:
                    Afficher "Choix invalide"
                Fin Cas
            Fin Selon
        Fin Si
    Fin Si

    Fin

le 3eme problème : Representation des nombres à virgule :

    Un programme permettant de représenter les nombres à virgule fixe et virgule flottante.
    Codage IEEE 754 (Simple précision : 32 bits)
    Codage IEEE 754 (Double précision : 64 bits)

l'analyse de problème :

    dans ce problème il y a 3 parties :
    1-partie : représenter un nombre réel en binaire avec la méthode de virgule fixe 
    2-partie : laire un nomber en binaire et affaiche come nomber reel avec la methode de virgule fixe
    3-parties : représenter un nombre réel en binaire avec la méthode de virgule flottante
    en Codage IEEE 754 avec simple précision et double précision

    Dans ces pragrammes en va utiliser les tableaux pour sevgarde et faire des traitements mathématiques pour avoir le résultèrent

# 1 - partie : représenter un nombre réel en binaire avec la méthode de virgule fixe :

les étapes de programme :

    8.	lire le nombre réel
    9.	Remplir le bit de signe 
    10.	convertir la partie entiere en binaire et sevgarde le dans un tableau
    11.	convertire la partie fractionnaire en binaire et sevgarde dans un auter tableau
    12.	print les résultats pour représenter le nombre réel en binaire

l'algorithm :

    Entrées :
    ent_bits: Nombre de bits pour la partie entière
    fra_bits: Nombre de bits pour la partie fractionnaire
    num: Nombre réel d'entrée
    
    Variables :
    nmu_ent: Partie entière du nombre
    num_fra: Partie fractionnaire du nombre
    tab_ent[ent_bits]: Tableau pour stocker la partie entière en binaire
    tab_fra[fra_bits]: Tableau pour stocker la partie fractionnaire en binaire
    tabB_V: Tableau pour stocker la conversion binaire de la partie entière
    size: Taille du tableau tabB_V
    q: Variable temporaire pour les calculs
    x: Variable temporaire pour les calculs
    
    Début :
    
    Afficher "Donnez le nombre de bits pour la partie entière : "
    Lire ent_bits
    Afficher "Donnez le nombre de bits pour la partie fractionnaire : "
    Lire fra_bits
    
    tab_ent[ent_bits]  {0, 0, 0, 0, 0, 0, 0, 0}  // Initialisation de la partie entière en binaire
    tab_fra[fra_bits]  {0, 0, 0, 0, 0, 0, 0, 0}  // Initialisation de la partie fractionnaire en binaire
    
    Afficher "Entrez le nombre réel : "
    Lire num
    
    Si num < 0 Alors:
    	tab_ent[0]  1  // Le bit de signe (le plus significatif) est mis à 1
    	num  - num  // Prend la valeur absolue du nombre
    
    nmu_ent  Partie entière de num  // Extraction de la partie entière
    num_fra  num - nmu_ent  // Extraction de la partie fractionnaire
    
    tabB_V, size  ConversionDecimalVersBinaire(nmu_ent)  // Conversion de la partie entière en binaire
    
    k  size - 1
    
    Pour i de ent_bits - 1 à 1 Faire:  // pour insere la partie entière en binaire dans le Tableau
    	Si k >= 0 Alors:
    		tab_ent[i] <- tabB_V[k]
    	k <- k - 1
    
    q  num_fra
    i  0
    
    Tant que q ≠ 1.0 ET i < fra_bits Faire
    q  q x 2
    x  Partie entière de q
    Si q > 1 Alors
    q  q - 1  // Soustraire 1 pour obtenir la nouvelle partie fractionnaire
    tab_fra[i]  x
    i  i + 1
    
    Afficher "Le résultat est :"
    
    Pour j de 0 à ent_bits - 1 Faire:
    	Afficher tab_ent[j]  // Affichage de la partie entière en binaire
    Pour j de 0 à fra_bits - 1 Faire:
    	Afficher tab_fra[j]  // Affichage de la partie fractionnaire en binaire
    
    Fin

# 2-partie : laire un nomber en binaire et affaiche come nomber reel avec la methode de virgule fixe :

les étapes de programme :

    1.	lire le nombre en binaire :
    a.	stocker la partie entière du nombre binaire dans le 1er Tableau
    b.	stocker la partie fractionnaire du nombre binaire dans le 2eme Tableau
    2.	convertir la partie entiere en decimal et sevgarde le dans un int
    3.	convertire la partie fractionnaire en decimal et sevgarde dans un float
    4.	print les résultats pour représenter le nombre binaire en decimal

l'algorithm :

    Entrées :
    
    tab_ent: Tableau pour stocker la partie entière du nombre binaire
    tab_fra: Tableau pour stocker la partie fractionnaire du nombre binaire
    
    Variables :
    size_ent: Taille de la partie entière du nombre binaire
    size_fra: Taille de la partie fractionnaire du nombre binaire
    sum_ent: Somme de la partie entière en décimal
    sum_fra: Somme de la partie fractionnaire en décimal
    sum: Nombre réel final
    
    
    Début :
    
    Afficher "Entrez la partie entière (chiffre par chiffre), Entrez le chiffre 2 pour terminer "
    tab_ent  Tableau vide
    i  0
    Afficher "Le 1er chiffre : "
    Lire tab_ent[i]
    
    Tant que tab_ent[i] ≠ 2 Faire :
    i  i + 1
    Redimensionner tab_ent à la taille (i + 1)
    Afficher "Le (i + 1) ème chiffre : "
    Lire tab_ent[i]
    
    size_ent  i
    
    Afficher "Entrez la partie fractionnaire (chiffre par chiffre), Entrez le chiffre 2 pour terminer"
    tab_fra <- Tableau vide
    j <- 0
    
    Afficher "Le 1er chiffre : "
    Lire tab_fra[j]
    
    Tant que tab_fra[j] ≠ 2 Faire :
    j  j + 1
    Redimensionner tab_fra à la taille (j + 1)
    Afficher "Le ( j + 1) ème chiffre : "
    Lire tab_fra[j]
    
    size_fra  j
    
    Afficher "Le résultat est : "
    
    k  size_ent - 1
    sum_ent  0
    Pour i de 0 à size_ent - 1 Faire :
    sum_ent  sum_ent + (tab_ent[i] * 2^k)
    k  k - 1
    
    k  -1
    sum_fra  0
    Pour j de 0 à size_fra - 1 Faire :
    sum_fra  sum_fra + (tab_fra[j] * 2^k)
    k  k - 1
    
    sum  sum_ent + sum_fra
    Afficher sum
    
    Fin

# 3-parties : représenter un nombre réel en binaire avec la méthode de virgule flottante :

les étapes de programme :
    
    1.	laire le nomber reel
    2.	sevgarde le bit de signe (1 ou 0)
    3.	convertir le nomber en binaire
    4.	remplire la partie de mantisse
    5.	calcule l'exposant remplire la partie d’exposant
    6.	affiche le resultat

l'algorithm :

    Entrées :
    precision: Choix de la précision (1 pour simple, 2 pour double)
    num: Nombre réel
    
    Variables :
    tab_exp: Tableau pour stocker la partie d'exposant
    tab_mn: Tableau pour stocker la partie de mantisse
    tab_sig: Tableau pour stocker le signe
    expo_bits: Nombre de bits pour la partie d'exposant
    mn_bits: Nombre de bits pour la partie de mantisse
    tabA: Tableau temporaire pour stocker la conversion décimale
    size_0: Taille de la partie entière du nombre binaire
    size_1: Taille totale du nombre binaire
    v: Position de la première "1" dans le tableau
    e: Exposant calculé / E: Exposant final pour la représentation
    tabB_V: Tableau pour stocker la conversion de l'exposant en binaire
    
    Début :
    Afficher "Pour choisir la précision :"
    Afficher "1 : pour Simple precision (32 bits)"
    Afficher "2 : pour Double precision (64 bits)"
    Afficher "La précision : "
    Lire precision
    Si precision = 1 Alors
    expo_bits  8
    mn_bits  23
    Sinon Si precision = 2 Alors
    expo_bits  11
    mn_bits  52
    Sinon
    Afficher "Précision non détectée."
    Sortir
    Fin Si
    
    tab_exp  Tableau de taille expo_bits initialisé à 0
    tab_mn  Tableau de taille mn_bits initialisé à 0
    tab_sig  Tableau de taille 1
    
    Pour i de 0 à expo_bits - 1 Faire
     tab_exp[i]  0
    
    Pour j de 0 à mn_bits - 1 Faire
    tab_mn[j]  0
    
    Afficher "Le nombre = "
    Lire num
    
    Si num < 0 Alors
    tab_sig[0]  1
    num  - num
    Sinon
            tab_sig[0]  0
    
    tabA  Appeler decimal_vers_binaire_float(num, &size_0, &size_1)
    v  0
    i  0
    
    Tant que v ≠ 1 Faire :
    Si tabA[i] = 1 Alors
    v  1
    Sinon
    i  i + 1
    Fin Tant Que
    
    v  i + 1
    e  size_0 - v
    E  e + 127
    tabB_V  Appeler decimal_vers_binaire_int(E, &size)
    
    j  expo_bits - 1
    
    Pour i de size - 1 à 0 Faire :
    tab_exp[j]  tabB_V[i]
    j  j - 1
    
        i  0
        j  v
    
    Pour i de 0 à size_1 - v Faire :
    tab_mn[i]  tabA[j]
    j  j + 1
    
    Afficher "Le résultat est : "
    Afficher "tab_sig[0] "
    
    Pour i de 0 à expo_bits - 1 Faire :
    Afficher tab_exp[i]
    
    Afficher " "
    Pour i de 0 à mn_bits - 1 Faire :
    Afficher tab_mn[i]
    
    Fin
