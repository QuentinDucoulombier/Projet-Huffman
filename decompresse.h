/*!
    \file decompresse.h
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier d'en-têtes pour decompresse.c
    \remarks Aucune
    Prototypage des fonctions et procédures.
*/

#ifndef _DECOMPRESSE_H_
#define _DECOMPRESSE_H_

/*!
    \fn void decompression();
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief decompresse et ecrit dans un fichier
    \remarks Aucune
*/
void decompression();

/*!
    \fn char lectCode(arbre a, char temp, FILE* fichier);
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \param a l'arbre recuperer grace au fichier qui est compressé
    \param temp caractere
    \param fichier fichier compressé
    \brief fonction recursive qui doit permettre de trouver le caractere qui correspond au code
    \remarks Aucune
*/
char lectCode(arbre a, char temp, FILE* fichier);


#endif