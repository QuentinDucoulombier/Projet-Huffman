/*!
    \file compresse.h
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier d'en-têtes pour compresse.c
    \remarks Aucune
    Prototypage des fonctions et procédures.
*/

#ifndef _COMPRESSE_H_
#define _COMPRESSE_H_

/* Inclusion des librairies */
#include <stdio.h>
#include "fonctions.h"

/* -------------------------------------------------------------*/
/*                  Structure du compresse.h                    */
/* -------------------------------------------------------------*/
/*!
    \struct maillonC
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param caract caractere de la liste de l'arbre
    \param code code de chaque caractere
    \param suivant element a la suite de la liste
    \brief struct pour saisir les differentes occurences de caractere d'un document
 */
typedef struct maillonC maillonC;
struct maillonC
{
  char caract;
  char* code;
  maillonC* suivant;
};
typedef maillonC* listeCode;

/* -------------------------------------------------------------*/
/*                           Fonctions                          */
/* -------------------------------------------------------------*/
/*!
    \fn void AjouterTeteCode(listeCode* l, char c, char* cd);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste qui va recevoir la nouvelle tete
    \param cd chaine de caractere du code
    \param c caractere de la nouvelle tete
    \brief permet de rajouter une tete a une liste
    \remarks Aucune
*/
void AjouterTeteCode(listeCode* l, char c, char* cd);

/*!
    \fn void AffichageListeCode(listeCode l_c);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l_c liste a afficher
    \brief affiche la liste
    \remarks Aucune
*/
void AffichageListeCode(listeCode l_c);

/*!
    \fn arbre creeArbreCompr(liste l, arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste de caractere et d'occurence
    \param a arbre
    \return l'arbre final de la compression
    \brief affiche la liste
    \remarks Aucune
*/
arbre creeArbreCompr(liste l);

/*!
    \fn void compression(arbre a, listeCode* lc);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param lc liste de caractere et de code
    \param a arbre
    \brief saisi un code selon l'emplacement dans l'arbre de chaque caractere
    \remarks Aucune
*/
void compression(arbre a, listeCode* lc);

/*!
    \fn void compressionAux(arbre a, char* code, listeCode* lc);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param lc liste de caractere et de code
    \param a arbre
    \param code chaine de caractere
    \brief fonction appeler dans compressionAux
    \remarks Aucune
*/
void compressionAux(arbre a, char* code, listeCode* lc);

/*!
    \fn arbre creeArbreCompr(liste l, arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param elt1 chaine de caractere
    \param elt2 chaine de caractere
    \return chaine de caractere
    \brief permet de fusionner de chaine de caractere
    \remarks Aucune
*/
char* rajoutChaine(char* elt1, char* elt2);

/*!
    \fn void en_tete(liste l, arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste de caractere et d'occurence
    \brief permet d'ecrire la liste dans le fichier compressé
    \remarks Aucune
*/
void en_tete(liste l);

/*!
    \fn char* caractCode(listeCode lc, int lettreEnCours);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param lc liste de caractere et de code
    \param lettreEnCours caractere en cours dans le texte
    \return chaine de caractere
    \brief permet de retourner le code de chaque caractere du texte
    \remarks Aucune
*/
char* caractCode(listeCode lc, int lettreEnCours);

/*!
    \fn void ouvrirFich(listeCode lc);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param lc liste de caractere et de code
    \brief permet d'ecriredans le documents tout les codes des caractere
    \remarks Aucune
*/
void ouvrirFich(listeCode lc);

#endif