/*!
    \file fonctions.h
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier d'en-têtes pour trisRapide.c
    \remarks Aucune
    Prototypage des fonctions et procédures.
*/


#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_

/* Inclusion de stdio.h */
#include <stdio.h>



/* -------------------------------------------------------------*/
/*               Differentes structures du fonctions.h          */
/* -------------------------------------------------------------*/
/*!
    \struct maillon
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param valeur entier qui represente le nombre d'occurence du caractere
    \param caract le caractere
    \param suivant element a la suite de la liste
    \brief struct pour saisir les differentes occurences de caractere d'un document
 */
typedef struct maillon maillon;
struct maillon
{
  int valeur;
  char caract;
  maillon* suivant;
};
typedef maillon* liste;

/*!
    \struct noeud
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param valeur liste d'occurence et de caractere
    \param fGauche fils gauche de l'arbre
    \param fDroite fils droite de l'arbre
    \brief struct pour l'arbre de la liste
 */
typedef struct noeud noeud;
struct noeud
{
  liste valeur;
  noeud* fGauche;
  noeud* fDroite;
};
typedef noeud* arbre;

/*!
    \struct maillonA
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param arbre est un arbre de liste
    \param suivant element a la suite de la liste
    \brief struct pour cree une liste d'arbre afin de cree un arbre general
 */
typedef struct maillonA maillonA;
struct maillonA
{
  arbre arbre;
  maillonA* suivant;
};
typedef maillonA* listeArbre;



/* -------------------------------------------------------------*/
/*                 Fonctions de bases sur les listes            */
/* -------------------------------------------------------------*/

/* Differentes fonctions qui ajoute une tete dans une listes */

/*!
    \fn void AjouterTete(liste* l, int valeur, char c);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste qui va recevoir la nouvelle tete
    \param valeur entier de la nouvelle tete
    \param c caractere de la nouvelle tete
    \brief permet de rajouter une tete a une liste
    \remarks Aucune
*/
void AjouterTete(liste* l, int valeur, char c);

/*!
    \fn void AjouterTeteLArbre(listeArbre* l, arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste qui va recevoir la nouvelle tete
    \param a arbre de la nouvelle tete
    \brief permet de rajouter une tete a une liste d'arbre
    \remarks Aucune
*/
void AjouterTeteLArbre(listeArbre* l, arbre a);


/* Differentes fonctions qui affiche la liste */

/*!
    \fn void AffichageListe(liste l);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste a afficher
    \brief permet d'afficher une liste
    \remarks Aucune
*/
void AffichageListe(liste l);

/*!
    \fn void AffichageListeArbre(listeArbre l_a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l_a liste d'arbre a afficher
    \brief permet d'afficher une liste d'arbre
    \remarks Aucune
*/
void AffichageListeArbre(listeArbre l_a);

/* Autre fonctions sur les listes */

/*!
    \fn liste copieListe(liste l);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste d'entier et de caractere
    \return une liste identique a la premiere
    \brief permet de copier une liste
    \remarks Aucune
*/
liste copieListe(liste l);

/*!
    \fn int tailleListe(liste l);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste d'entier et de caractere
    \return une liste identique a la premiere
    \brief permet de copier une liste
    \remarks Aucune
*/
int tailleListe(liste l);

/*!
    \fn arbre suppDebutLstArbre(listeArbre* l);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste d'arbre
    \return l'arbre en tete de la liste d'arbre
    \brief permet de supprimer la tete de la liste d'arbre et de la retourner
    \remarks Aucune
*/
arbre suppDebutLstArbre(listeArbre* l);



/* -------------------------------------------------------------*/
/*                 Fonctions de bases sur les arbres            */
/* -------------------------------------------------------------*/

/*!
    \fn arbre creeArbre(liste valeur, arbre filsGauche, arbre filsDroit);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param valeur une liste d'entier et de caractere
    \param filsGauche le fils gauche de l'arbre
    \param filsDroite le fils droite de l'arbre
    \return une arbre de liste
    \brief cree un arbre de liste
    \remarks Aucune
*/
arbre creeArbre(liste valeur, arbre filsGauche, arbre filsDroit);

/*!
    \fn arbre getFilsGauche(arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param arbre l'arbre parent
    \return l'arbre du fils Gauche de l'arbre parent
    \brief permet de retourner l'arbre gauche de l'abre pris en parametre
    \remarks Aucune
*/
arbre getFilsGauche(arbre a);

/*!
    \fn arbre getFilsDroit(arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param arbre l'arbre parent
    \return l'arbre du fils Droit de l'arbre parent
    \brief permet de retourner l'arbre Droit de l'abre pris en parametre
    \remarks Aucune
*/
arbre getFilsDroit(arbre a);

/*!
    \fn liste getValeur(arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param arbre un arbre
    \return retourne la liste du noeud de l'arbre
    \brief retourne la valeur de l'arbre
    \remarks Aucune
*/
liste getValeur(arbre a);

/*!
    \fn void parcoursPrefixe(arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param arbre un arbre
    \brief Affiche l'arbre de maniere prefixe
    \remarks Aucune
*/
void parcoursPrefixe(arbre a);

/*!
    \fn void parcoursPrefixeAux(arbre a);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param arbre un arbre
    \brief Fonction utiliser dans parcoursPrefixe il affiche l'arbre de maniere prefixe
    \remarks Aucune
*/
void parcoursPrefixeAux(arbre a);


/* -------------------------------------------------------------*/
/*               Fonctions qui calcule les occurences           */
/* -------------------------------------------------------------*/
/*!
    \fn liste occurence();
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \return une liste avec le caractere present dans le texte et le nombre d'occurence de ce caractere
    \brief fonction qui lit dans un fichier les differents caractere et compte le nombre d'occurence de ce meme caractere. Il rentre ces données dans une liste
    \remarks Aucune
*/
liste occurence();

#endif