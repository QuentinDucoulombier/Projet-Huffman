/*!
    \file trisRapide.h
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier d'en-têtes pour trisRapide.c
    \remarks Aucune
    Prototypage des fonctions et procédures.
*/


#ifndef __TRISRAPIDE_H_
#define __TRISRAPIDE_H_

/* Incusion de fonction.h necessaire pour importer les structures */
#include "fonctions.h"

/* Prototypes de fonctions */

/* -------------------------------------------------------------*/
/*     Tri Fusion pour une liste de caractere et d'entier       */
/* -------------------------------------------------------------*/

/*!
    \fn void TriFusion(liste* l);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste de la struct liste qui contient des entiers et des caractere
    \return une liste triée selon les valeurs d'entier
    \brief permet de triée toute la liste selon les entiers
    \remarks Aucune
*/
void TriFusion(liste* l);

/*!
    \fn liste listeTrie(liste a, liste b);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param a 
    \param b
    \return une liste
    \brief fonction utiliser dans TriFusion, permet de trié
    \remarks Aucune
*/
liste listeTrie(liste a, liste b);

/*!
    \fn liste listeTrie(liste a, liste b);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param premiereMoitie pointeur de liste, premiere partie de la liste
    \param deuxiemeMoitie pointeur de liste , deuxieme partie de la liste
    \brief fonction utiliser dans TriFusion, permet de fusionner les deux listes selon deux curseur
    \remarks Aucune
*/
void Fusionner(liste l,	liste* premiereMoitie, liste* deuxiemeMoitie);

/* -------------------------------------------------------------*/
/*               Tri Fusion pour une liste d'arbre              */
/* -------------------------------------------------------------*/
/*!
    \fn void TriFusionArbre(listeArbre* l);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param l liste de la struct listeArbre qui contient des arbre qui sont eu meme une struct de liste et de noeud
    \return une liste triée selon les entiers de la liste de l'arbre
    \brief permet de triée toute la liste selon lles entiers de la liste de l'arbre
    \remarks Aucune
*/
void TriFusionArbre(listeArbre* l);

/*!
    \fn listeArbre listeTrieArbre(listeArbre a, listeArbre b);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param a
    \param b
    \brief fonction utiliser dans TriFusionArbre trie la liste
    \return une liste
    \remarks Aucune
*/
listeArbre listeTrieArbre(listeArbre a, listeArbre b);

/*!
    \fn liste listeTrie(liste a, liste b);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param premiereMoitie pointeur de liste, premiere partie de la liste
    \param deuxiemeMoitie pointeur de liste , deuxieme partie de la liste
    \brief fonction utiliser dans TriFusion Arbre permet de fusionner les deux listes selon deux curseur
    \remarks Aucune
*/
void FusionnerArbre(listeArbre l, listeArbre* premiereMoitie, listeArbre* deuxiemeMoitie);

#endif