/*!
    \file fonctions.c
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier avec tout les fonctions
    \remarks Aucune
    Description détaillée des fonctions et des procédures
*/

/* Inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "compresse.h"
#include "trisRapide.h"
#include <string.h>
#define nomFichier "lorem.txt" //emplacement où changer le nom du fichier à compresser



/* -------------------------------------------------------------*/
/*                 Fonctions de bases sur les listes            */
/* -------------------------------------------------------------*/

void AjouterTete(liste* l, int valeur, char c)
{
  maillon* m;

  m = malloc(sizeof(maillon));
  m -> valeur = valeur;
  m -> caract = c;
  m -> suivant = (*l);
  (*l) = m;
}

void AjouterTeteLArbre(listeArbre* l, arbre a)
{
  maillonA* m;

  m = malloc(sizeof(maillonA));
  m -> arbre = a;
  m -> suivant = (*l);
  (*l) = m;
}

void AffichageListe(liste l)
{
  liste temp;
  temp = l;

  if (temp == NULL)
  {
    printf("La liste est vide ! \n");
  }
  else
  {
    printf("-------------------------\n");
    while (temp != NULL)
    {
      printf("%c: %d occurences\n", temp -> caract, temp -> valeur);
      temp = temp -> suivant;
    }
    printf("-------------------------\n");
  }
}

void AffichageListeArbre(listeArbre l_a)
{
  listeArbre temp;
  temp = l_a;
  int i = 0;
  if (temp == NULL)
  {
    printf("La liste est vide ! \n");
  }
  else
  {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (temp != NULL)
    {
        printf("arbre n %d\n", i);
        parcoursPrefixe(temp -> arbre);
        temp = temp -> suivant;
        i++;
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  }
}

liste copieListe(liste l)
{
  liste temp = NULL;

  while (l != NULL)
  {
    AjouterTete(&temp, l->valeur, l->caract);
    l = l->suivant;
  }

  return temp;
}

int tailleListe(liste l)
{
  int i = 0;
  liste temp = l;
  while (temp != NULL)
  {
    temp = temp -> suivant;
    i++;
  }
  return i;
}

arbre suppDebutLstArbre(listeArbre* l)
{
  listeArbre temp = (*l);
  arbre eltSuppr = temp -> arbre;
  (*l) = temp -> suivant;
  return eltSuppr;
}



/* -------------------------------------------------------------*/
/*                 Fonctions de bases sur les arbres            */
/* -------------------------------------------------------------*/

arbre creeArbre(liste valeur, arbre filsGauche, arbre filsDroit)
{
  arbre a = NULL;
  a = malloc(sizeof(noeud));
  a -> valeur = valeur;
  a -> fGauche = filsGauche;
  a -> fDroite = filsDroit;
  return a;
}

arbre getFilsGauche(arbre a)
{
  return a -> fGauche;
}

arbre getFilsDroit(arbre a)
{
  return a -> fDroite;
}

liste getValeur(arbre a)
{
  return a -> valeur;
}

void parcoursPrefixe(arbre a)
{
  if (a == NULL)
  {
    printf("Arbre Vide \n");
  }
  else
  {
    return parcoursPrefixeAux(a);
  }
}

void parcoursPrefixeAux(arbre a)
{
  if (a != NULL)
  {
    printf("%d \n", getValeur(a)->valeur);
    parcoursPrefixeAux(getFilsGauche(a));
    parcoursPrefixeAux(getFilsDroit(a));
  }
}


/* -------------------------------------------------------------*/
/*               Fonctions qui calcule les occurences           */
/* -------------------------------------------------------------*/

liste occurence()
{
  liste ListeOCC = NULL;
  FILE* fichier = NULL;
  int caractereActuel = 0;
  int compteur[77] = {0}, i, y;
  char alphabet[77] = "abcdefghijklmnopqrstuwxyz (.)[,]/-?!:;'\"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n"; // reste les "" et certainement d'autres truc
  fichier = fopen(nomFichier, "r");
  int j;

  if (fichier != NULL)
  {
    while (caractereActuel != EOF)
    {
      caractereActuel = fgetc(fichier);
      y = 0;
      while(alphabet[y] != '\0')
      {
        if (alphabet[y] == caractereActuel)
        {
          compteur[y]++;
        }
      y++;
      }
    }
  }

    for(i = 0; i < 77; i++)
    {
      if(compteur[i] > 0)
      {
        AjouterTete(&ListeOCC, compteur[i], alphabet[i]);
        j++;
      }
    }
    fclose(fichier);
    return ListeOCC;
}
