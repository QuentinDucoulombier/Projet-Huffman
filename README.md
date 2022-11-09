# Projet Huffman

## Présentation

Le codage de Huffman est un algorithme de compression de données sans perte. Le codage de Huffman utilise un code à longueur variable pour représenter un symbole de la source (par exemple un caractère dans un fichier). Le code est déterminé à partir d'une estimation des probabilités d'apparition des symboles de source, un code court étant associé aux symboles de source les plus fréquents.

Un code de Huffman est optimal au sens de la plus courte longueur pour un codage par symbole, et une distribution de probabilité connue. Des méthodes plus complexes réalisant une modélisation probabiliste de la source permettent d'obtenir de meilleurs ratios de compression.

Cette algorithme permet de compresse en binaire puis de decompresse des fichiers texte grace au codage de Huffman, ainsi il utilise des arbres binaire, des tri rapide et des listes chainées.

## Installation 

Le programme "Huffman" doit être exécuté de la manière suivante:

- Se placer dans le répertoire du projet.
- Ouvrir les fichiers "[fonctions.c](./fonctions.c)" et "[compresse.c](./compresse.c)" si vous    souhaitez compresser un fichier. Remplacer le nom du fichier entre les "" du #define nomFichier (situé tout en haut du fichier l.5) par le nom du fichier que vous souhaitez compresser.
- Ouvrir le fichier "[decompresse.c](./decompresse.c)" si vous souhaitez décompresser un fichier. Remplacer le nom du fichier entre les "" du #define fichierCompresse (situé tout en haut du fichier l.6) par le nom du fichier que vous souhaitez décompresser.
- Enregistrer et fermer les fichiers précédemment ouverts.
- Entrer la commande ```make``` dans un terminal.
- Entrer la commande ```./exe```.
- Un menu apparaît, choisissez parmi la compression (1) et la décompression (2). Si vous sélectionnez la compression un fichier « compression.txt » est créer. Si vous sélectionnez la décompression un fichier « décompression.txt » se créer.
- Entrer la commande "make clear" lorsque vous avez terminé d'utiliser le programme.

## Demarche
Afin de mieux appréhender le projet nous avons tout d’abord effectué une lecture approfondie du sujet afin d’en comprendre tous les aspects. Ensuite nous avons effectué de longues sessions de brainstorming afin d’entamer ce projet de la meilleure manière possible. 

En premier lieu nous avons crée l’ensemble des fonctions/procédures et structures utiles à évaluer le nombre d’occurrences de chaque caractère apparaissant dans le texte. On s’est ensuite penché sur la création de l’arbre qui classe les caractères. On a poursuivi notre avancé en attribuant un nouveaux code à chaque caractère qu’on a soigneusement placé en en-tête du nouveau fichier de compression.

Quant à la décompression, nous avons réutilisé nos travaux précédent afin de recréer un arbre qu’on utilise pour décompresser le fichier. Cette partie du projet marche quasiment cependant nous avons rencontré de nombreuses péripéties qui ont entraîné le dysfonctionnement de la décompression. En effet, on a une certaine décompression du fichier mais une mauvaise restitution du texte (inversion de caractères notamment lorsqu’elles ont le même nombre d’occurrences).
